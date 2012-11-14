eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
     & eval 'exec perl -S $0 $argv:q'
     if 0;

# $Id$
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::TestTarget;

$status = 0;
$debug_level = 0;

foreach $i (@ARGV) {
    if ($i eq '-debug') {
        $debug_level = '10';
    }
}

my $name_manager = PerlACE::TestTarget::create_target (1) || die "Create target 1 failed\n";
my $client      = PerlACE::TestTarget::create_target (2) || die "Create target 2 failed\n";

## The LoadManager needs to register signals with the ORB's reactor (on
## Windows only) and thus can not use the TP Reactor since it doesn't
## support that kind of thing.  So, we swith to the Select MT Reactor.
$NM_conf = $name_manager->LocalFile ("windows" . $PerlACE::svcconf_ext);

my $name_mgr_iorbase = "lm.ior";
my $name_iorbase = "nm.ior";

my $name_manager_iorfile = $name_manager->LocalFile ($name_mgr_iorbase);
my $name_server_iorfile = $name_manager->LocalFile ($name_iorbase);

my $naming_mgr_client_iorfile = $client->LocalFile ($name_mgr_iorbase);
my $name_client_iorfile = $client->LocalFile ($name_iorbase);

$name_manager->DeleteFile($name_mgr_iorbase);
$name_manager->DeleteFile($name_iorbase);
$client->DeleteFile($name_mgr_iorbase);
$client->DeleteFile($name_iorbase);


$NM = $name_manager->CreateProcess ("../../orbsvcs/Naming_Service/tao_ft_naming",
        "-f persist.dat -g $name_manager_iorfile -o $name_server_iorfile " .
        "-ORBDebugLevel $debug_level " .
        "-ORBDottedDecimalAddresses 1" .
        ($^O eq 'MSWin32' ? " -ORBSvcConf $NM_conf" : ''));


#$NS = $name_server->CreateProcess ("../../orbsvcs/Naming_Service/tao_cosnaming",
#        "-o $name_server_iorfile " .
#        ($^O eq 'MSWin32' ? " -ORBSvcConf $NS_conf" : ''));

$NM_REF       = "-ORBInitRef NameService=file://$name_client_iorfile";
$RM_REF       = "-ORBInitRef NamingManager=file://$naming_mgr_client_iorfile";
$DEBUG_LEVEL  = "-ORBDebugLevel $debug_level";
$LOAD_ARG     = "$NM_REF $RM_REF $DEBUG_LEVEL";

$CL   = $client->CreateProcess ("$ENV{ACE_ROOT}/bin/tao_nsgroup");

sub run_client ($)
{
    my $args = shift;

    my $arglist = "$LOAD_ARG $args";

    print STDERR "\n\n======== Running Test================\n";
    print STDERR "$args\n";

    $CL->Arguments ($arglist);

    my $client_status = $CL->SpawnWaitKill ($client->ProcessStartWaitInterval());

    if ($client_status != 0) {
        my $time = localtime;
        print STDERR "ERROR: client returned $client_status at $time\n";
        $status = 1;
    }
}

sub run_clients ()
{
    run_client ("group_list");
    run_client ("group_create -group GiasGateway -policy round -type_id IDL:omg.org/FT/NamingManager:1.0");
    run_client ("group_list");
    run_client ("group_bind -group GiasGateway -n GiasGateway");
    run_client ("group_modify -group GiasGateway -policy rand");
    run_client ("member_list -group GiasGateway");
    run_client ("member_add -group GiasGateway -location 10.201.200.64 -ior file://$naming_mgr_client_iorfile");
    run_client ("member_list -group GiasGateway");
    run_client ("member_show -group GiasGateway -location 10.201.200.64");
    run_client ("member_remove -group GiasGateway -location 10.201.200.64");
    run_client ("member_list -group GiasGateway");
    run_client ("group_remove -group GiasGateway");
    run_client ("group_list");
    run_client ("--help");
}

print STDERR "\n\n======== Running tao_nsgroup Test================\n";
print STDERR "\n";

print STDERR "This test will check the methods of the tao_nsgroup\n";
print STDERR "\n";

################################################################################
## Start LoadBalancer Service
################################################################################
$name_manager_status = $NM->Spawn ();

if ($name_manager_status != 0) {
    print STDERR "ERROR: server returned $name_manager_status\n";
    exit 1;
}
if ($name_manager->WaitForFileTimed ($name_mgr_iorbase,
        $name_manager->ProcessStartWaitInterval()) == -1) {
    print STDERR "ERROR: cannot find file <$name_manager_iorfile>\n";
    $NM->Kill (); $NM->TimedWait (1);
    exit 1;
}

if ($name_manager->GetFile ($name_mgr_iorbase) == -1) {
    print STDERR "ERROR: cannot retrieve file <$name_manager_iorfile>\n";
    $NM->Kill (); $NM->TimedWait (1);
    exit 1;
}
if ($client->PutFile ($name_mgr_iorbase) == -1) {
    print STDERR "ERROR: cannot set file <$naming_mgr_client_iorfile>\n";
    $NM->Kill (); $NM->TimedWait (1);
    exit 1;
}

run_clients();


print STDERR "\n\n====================================================\n";
print STDERR "\n";
$name_manager_status = $NM->TerminateWaitKill ($name_manager->ProcessStopWaitInterval());

if ($name_manager_status != 0) {
    print STDERR "ERROR: server returned $name_manager_status\n";
    $status = 1;
}

$name_manager->DeleteFile($name_mgr_iorbase);
$name_manager->DeleteFile($name_iorbase);
$client->DeleteFile($name_mgr_iorbase);
$client->DeleteFile($name_iorbase);

exit $status;
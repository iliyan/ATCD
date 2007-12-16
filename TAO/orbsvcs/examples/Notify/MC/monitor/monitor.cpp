// $Id$

#include "orbsvcs/Notify/MonitorControl/NotificationServiceMCC.h"
#include "ace/Get_Opt.h"
#include "ace/OS_NS_ctype.h"

const ACE_TCHAR* monitor_ior = 0;

static int
parse_args (int argc, ACE_TCHAR *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, ACE_TEXT ("k:"));
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'k':
        monitor_ior = get_opts.opt_arg ();
        break;
      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage: %s "
                           "-k <ior> "
                           "\n",
                           argv [0]),
                          -1);
      }
  return 0;
}

extern "C" int
sorter (const void* a, const void* b)
{
  const char* left = *(reinterpret_cast<const char* const*> (a));
  const char* right = *(reinterpret_cast<const char* const*> (b));
  return ACE_OS::strcmp (left, right);
}

int
ACE_TMAIN (int argc, ACE_TCHAR* argv[])
{
  static const char* shutdown = "shutdown";
  int status = 0;
  try
    {
      CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);

      if (parse_args (argc, argv) != 0)
        return 1;

      CORBA::Object_var obj = orb->string_to_object (
        ACE_TEXT_ALWAYS_CHAR (monitor_ior));
      CosNotification::NotificationServiceMonitorControl_var nsm =
        CosNotification::NotificationServiceMonitorControl::_narrow (obj.in ());

      if (CORBA::is_nil (nsm.in ()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Unable to locate the "
                             "Notification Service Monitor\n"),
                            1);
        }

      bool done = false;
      static const size_t lsize = 1024;
      char prev[lsize];
      while(!done)
        {
          ACE_OS::printf ("NotifyService> ");
          ACE_OS::fflush (stdout);

          char line[lsize] = "";
          char* rl = ACE_OS::fgets (line, lsize, stdin);
          if (rl != 0)
            {
              int len = static_cast<int> (ACE_OS::strlen (line));
              for(int i = 0; i < len && ACE_OS::ace_isspace (rl[0]); i++)
                {
                  rl++;
                }

              for(int i = len - 1; i >= 0 && ACE_OS::ace_isspace (line[i]); i--)
                {
                  line[i] = '\0';
                }

              if (ACE_OS::strlen (rl) == 0 || ACE_OS::strcmp (rl, "!!") == 0)
                {
                  ACE_OS::strcpy (line, prev);
                  rl = line;
                }
              ACE_OS::strcpy (prev, line);
            }


          if (rl == 0)
            {
              done = true;
              ACE_DEBUG ((LM_DEBUG, "\n"));
            }
          else if (ACE_OS::strlen (rl) == 0)
            {
            }
          else if (ACE_OS::strcmp (rl, "quit") == 0)
            {
              done = true;
            }
          else if (ACE_OS::strcmp (rl, "help") == 0)
            {
              ACE_DEBUG ((LM_DEBUG, "names    - Get a list of currently "
                                    "available statistic names.\n"
                                    "quit     - Exit the monitor.\n"
                                    "shutdown - Shut down an event "
                                    "channel with the given name.\n"
                                    "<statistic name> - Return the "
                                    "information for the specified "
                                    "statistic.\n"));
            }
          else if (ACE_OS::strcmp (rl, "names") == 0)
            {
              try
                {
                  CosNotification::NotificationServiceMonitorControl::NameList_var names =
                    nsm->get_statistic_names ();
                  CORBA::ULong length = names->length ();
                  ACE_DEBUG ((LM_DEBUG, "Statistic names\n"));

                  // It's much easier to read once it's sorted
                  const char** narray = 0;
                  ACE_NEW_THROW_EX (narray,
                                    const char* [length],
                                    CORBA::NO_MEMORY ());
                  for(CORBA::ULong i = 0; i < length; i++)
                    narray[i] = names[i].in ();
                  ACE_OS::qsort (narray, length,
                                 sizeof (const char*), sorter);

                  for(CORBA::ULong i = 0; i < length; i++)
                    {
                      ACE_DEBUG ((LM_DEBUG, "  %s\n", narray[i]));
                    }
                  delete [] narray;
                }
              catch (const CORBA::Exception& ex)
                {
                  ex._tao_print_exception ("names: ");
                }
            }
          else
            {
              if (ACE_OS::strstr(rl, shutdown) == rl)
                {
                  const char* name = rl + ACE_OS::strlen (shutdown);
                  bool space = false;
                  size_t i = 0;
                  while (ACE_OS::ace_isspace (name[i]))
                    {
                      space = true;
                      i++;
                    }
                  if (space)
                    {
                      try
                        {
                          nsm->shutdown_event_channel (name + i);
                        }
                      catch (const CORBA::Exception& ex)
                        {
                          ACE_OS::strcat (rl, ": ");
                          ex._tao_print_exception (rl);
                        }
                      continue;
                    }
                }
              try
                {
                  CosNotification::NotificationServiceMonitorControl::Data_var data =
                    nsm->get_statistic (rl);
                  ACE_DEBUG ((LM_DEBUG, "%s => ", rl));
                  if (data->_d () == CosNotification::NotificationServiceMonitorControl::DATA_NUMERIC)
                    {
                      CosNotification::NotificationServiceMonitorControl::Numeric_var
                        num = data->num ();
                      ACE_DEBUG ((LM_DEBUG, "%g\n", num->last));
                    }
                  else
                    {
                      CosNotification::NotificationServiceMonitorControl::NameList
                        list = data->list ();
                      CORBA::ULong length = list.length ();
                      for(CORBA::ULong i = 0; i < length; i++)
                        {
                          ACE_DEBUG ((LM_DEBUG, "%s ", list[i].in ()));
                        }
                      ACE_DEBUG ((LM_DEBUG, "\n"));
                    }
                }
              catch (const CORBA::Exception& ex)
                {
                  ACE_OS::strcat (rl, ": ");
                  ex._tao_print_exception (rl);
                }
            }
        }

      orb->destroy ();
    }
  catch (const CORBA::UserException& ex)
    {
      ex._tao_print_exception ("Notification Service Monitor: ");
      status++;
    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("Notification Service Monitor: ");
      status++;
    }
  catch (...)
    {
      ACE_ERROR ((LM_ERROR, "Notification Service Monitor: "
                            "unexpected exception type\n"));
      status++;
    }

  return status;
}

// $Id$

#include "Config_Backing_Store.h"
#include "Server_Info.h"
#include "Activator_Info.h"
#include "utils.h"
#include "ace/OS_NS_unistd.h"

static const ACE_TCHAR* STARTUP_COMMAND = ACE_TEXT("StartupCommand");
static const ACE_TCHAR* WORKING_DIR = ACE_TEXT("WorkingDir");
static const ACE_TCHAR* ENVIRONMENT = ACE_TEXT("Environment");
static const ACE_TCHAR* ACTIVATION = ACE_TEXT("Activation");
static const ACE_TCHAR* PARTIAL_IOR = ACE_TEXT("Location");
static const ACE_TCHAR* IOR = ACE_TEXT("IOR");
static const ACE_TCHAR* START_LIMIT = ACE_TEXT("StartLimit");
static const ACE_TCHAR* ACTIVATOR = ACE_TEXT("Activator");
static const ACE_TCHAR* SERVERS_ROOT_KEY = ACE_TEXT("Servers");
static const ACE_TCHAR* ACTIVATORS_ROOT_KEY = ACE_TEXT("Activators");
static const ACE_TCHAR* TOKEN = ACE_TEXT("Token");
static const ACE_TCHAR* SERVER_ID = ACE_TEXT("ServerId");

#if defined (ACE_WIN32) && !defined (ACE_LACKS_WIN32_REGISTRY)
static const char* WIN32_REG_KEY = "Software\\TAO\\ImplementationRepository";
#endif

Config_Backing_Store::Config_Backing_Store(ACE_Configuration& config)
: config_(config),
  status_(-1)
{
}

Config_Backing_Store::~Config_Backing_Store()
{
}

void Config_Backing_Store::loadActivators ()
{
  ACE_Configuration_Section_Key root;
  int err = config_.open_section (config_.root_section (), ACTIVATORS_ROOT_KEY, 0, root);
  if (err == 0)
    {
      int index = 0;
      ACE_TString name;
      while (config_.enumerate_sections (root, index, name) == 0)
        {
          ACE_CString ior;
          u_int token;

          ACE_Configuration_Section_Key key;

          // Can't fail, because we're enumerating
          config_.open_section (root, name.c_str(), 0, key);

          config_.get_string_value (key, IOR, ior);
          config_.get_integer_value (key, TOKEN, token);

          Activator_Info_Ptr info (new Activator_Info (name, token, ior));
          activators().bind (lcase (name), info);
          index++;
        }
    }
}

void
Config_Backing_Store::loadServers ()
{
  ACE_Configuration_Section_Key root;
  int err = config_.open_section (config_.root_section (), SERVERS_ROOT_KEY, 0, root);
  if (err == 0)
    {
      int index = 0;
      ACE_TString name;
      while (config_.enumerate_sections (root, index, name) == 0)
        {
          ACE_CString server_id, cmdline, dir, envstr, partial_ior, ior, aname;
          u_int amodeint = ImplementationRepository::MANUAL;
          u_int start_limit;

          ACE_Configuration_Section_Key key;

          // Can't fail, because we're enumerating
          config_.open_section (root, name.c_str (), 0, key);

          // Ignore any missing values. Server name is enough on its own.
          config_.get_string_value (key, SERVER_ID, server_id);
          config_.get_string_value (key, ACTIVATOR, aname);
          config_.get_string_value (key, STARTUP_COMMAND, cmdline);
          config_.get_string_value (key, WORKING_DIR, dir);
          config_.get_string_value (key, ENVIRONMENT, envstr);
          config_.get_integer_value(key, ACTIVATION, amodeint);
          config_.get_string_value (key, PARTIAL_IOR, partial_ior);
          config_.get_string_value (key, IOR, ior);
          config_.get_integer_value(key, START_LIMIT, start_limit);

          ImplementationRepository::ActivationMode amode =
            static_cast <ImplementationRepository::ActivationMode> (amodeint);

          ImplementationRepository::EnvironmentList env_vars =
            ImR_Utils::parseEnvList (envstr);

          Server_Info_Ptr info (new Server_Info(server_id, name, aname, cmdline,
            env_vars, dir, amode, start_limit, partial_ior, ior));
          servers().bind (name, info);
          index++;
        }
    }
}

int
Config_Backing_Store::persistent_remove (const ACE_CString& name, bool activator)
{
  const ACE_TCHAR* const key = (activator ? ACTIVATORS_ROOT_KEY : SERVERS_ROOT_KEY);
  if (activator)
    {
    }
  else
    {
    }
  return remove (name, key);
}

int
Config_Backing_Store::remove (const ACE_CString& name, const ACE_TCHAR* key)
{
  ACE_Configuration_Section_Key root;
  int err = config_.open_section (config_.root_section (), key, 0, root);
  if (err != 0)
    {
      return 0; // Already gone.
    }
  return config_.remove_section (root, name.c_str (), 1);
}

static int get_key (ACE_Configuration& cfg, const ACE_CString& name,
                    const ACE_TCHAR* const sub_section, ACE_Configuration_Section_Key& key)
{
  ACE_Configuration_Section_Key root;
  int err = cfg.open_section (cfg.root_section(), sub_section, 1, root);
  if (err != 0)
    {
      ACE_ERROR ((LM_ERROR, "Unable to open config section:%s\n", sub_section));
      return err;
    }
  err = cfg.open_section (root, name.c_str (), 1, key);
  if (err != 0)
    {
      ACE_ERROR((LM_ERROR, "Unable to open config section:%s\n", name.c_str()));
    }
  return err;
}

int
Config_Backing_Store::persistent_update(const Server_Info_Ptr& info)
{
  ACE_Configuration_Section_Key key;
  int err = get_key(this->config_, info->name, SERVERS_ROOT_KEY, key);
  if (err != 0)
    {
      return err;
    }

  ACE_CString envstr = ImR_Utils::envListToString(info->env_vars);

  this->config_.set_string_value (key, SERVER_ID, info->server_id.c_str ());
  this->config_.set_string_value (key, ACTIVATOR, info->activator.c_str ());
  this->config_.set_string_value (key, STARTUP_COMMAND, info->cmdline.c_str ());
  this->config_.set_string_value (key, WORKING_DIR, info->dir.c_str ());
  this->config_.set_string_value (key, ENVIRONMENT, envstr);
  this->config_.set_integer_value (key, ACTIVATION, info->activation_mode);
  this->config_.set_integer_value (key, START_LIMIT, info->start_limit);
  this->config_.set_string_value (key, PARTIAL_IOR, info->partial_ior.c_str ());
  this->config_.set_string_value (key, IOR, info->ior.c_str());

  return 0;
}

int
Config_Backing_Store::persistent_update(const Activator_Info_Ptr& info)
{
  ACE_Configuration_Section_Key key;
  int err = get_key(this->config_, info->name, ACTIVATORS_ROOT_KEY, key);
  if (err != 0)
    {
      return err;
    }

  this->config_.set_integer_value (key, TOKEN, info->token);
  this->config_.set_string_value (key, IOR, info->ior.c_str ());

  return 0;
}

int
Config_Backing_Store::persistent_load ()
{
  if (status_ != 0)
    {
      return status_;
    }

  loadActivators();
  loadServers();

  return 0;
}

Heap_Backing_Store::Heap_Backing_Store(const ACE_CString& filename, bool start_clean)
: Config_Backing_Store(heap_),
  filename_(filename)
{
  if (start_clean)
    {
      if (this->debug_ > 9)
        {
          ACE_DEBUG((LM_INFO, "Heap start clean\n"));
        }
      ACE_OS::unlink ( this->filename_.c_str () );
    }

  status_ = heap_.open (this->filename_.c_str ());
}

Heap_Backing_Store::~Heap_Backing_Store()
{
}

const char*
Heap_Backing_Store::repo_mode() const
{
  return this->filename_.c_str();
}

#if defined (ACE_WIN32) && !defined (ACE_LACKS_WIN32_REGISTRY)
static HKEY setup_registry(const bool start_clean)
{
  if (start_clean)
    {
      ACE_Configuration_Win32Registry config ( HKEY_LOCAL_MACHINE );
      ACE_Configuration_Section_Key root;
      config.open_section (config.root_section(), "Software\\TAO", 0, root);
      config.remove_section (root, "ImplementationRepository", 1);
    }

  return ACE_Configuration_Win32Registry::
    resolve_key (HKEY_LOCAL_MACHINE, WIN32_REG_KEY);
}
#endif

Registry_Backing_Store::Registry_Backing_Store(const ACE_CString& filename, bool start_clean)
#if defined (ACE_WIN32) && !defined (ACE_LACKS_WIN32_REGISTRY)
: Config_Backing_Store(win32registry_),
  win32registry_(setup_registry(start_clean))
#else
: Config_Backing_Store(invalid_config_)
#endif
{
#if !defined (ACE_WIN32) || defined (ACE_LACKS_WIN32_REGISTRY)
  ACE_ERROR ((LM_ERROR, "Registry persistence is only "
                        "supported on Windows\n"));
  status_ = -1;
#endif
}

Registry_Backing_Store::~Registry_Backing_Store()
{
}

const char*
Registry_Backing_Store::repo_mode() const
{
  return "Registry";
}
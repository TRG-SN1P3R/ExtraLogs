class ExtraLogsConfig{

    static const string CONFIG_VERSION = "2";

    // Config location
	private const static string ModFolder = "$profile:\\ExtraLogs\\";
	private const static string ModConfigFile = "ExtraLogsConfig.json";

    // CONFIG REF
	string ConfigVersion = "";
	ref LogConfig ServerConfig; //Config for gating logic for logs	
	ref MapConfig LiveMap; //Config for gating logic live map.
	ref LogCustomItems CustomConfig; // Config for logging items tagged by user.
	ref Testing TestItem; //TESTING
    void Load()
	{
		if (GetGame().IsDedicatedServer())
		{
			if (FileExist(ModFolder + ModConfigFile))
			{ // If config exists, load file
				JsonFileLoader<ExtraLogsConfig>.JsonLoadFile(ModFolder + ModConfigFile, this);

				// If version mismatch, backup old version of json before replacing it
				if (ConfigVersion != CONFIG_VERSION)
				{
					JsonFileLoader<ExtraLogsConfig>.JsonSaveFile(ModFolder + ModConfigFile + "_old", this);
				}
				else
				{
					// Config exists and version matches, stop here.
					return;
				}
			}
        // Set new config version
	    ConfigVersion = CONFIG_VERSION;
        // Set default config
	    ServerConfig = new LogConfig;
		Save();
		}
    }

    void Save()
	{
		if (!FileExist(ModFolder))
		{	// If config folder doesn't exist, create it.
			MakeDirectory(ModFolder);
		}

		// Save JSON config
		JsonFileLoader<ExtraLogsConfig>.JsonSaveFile(ModFolder + ModConfigFile, this);
	}

}


class LogConfig //LOGGING CONFIG
{
	bool ShowBaseDamage = true; //Show basebuilding object destroyed (Buggy!)
    bool ShowFenceOpen = true; //Show opening of gates
	bool ShowLockAttach = true; //Show attaching of locks
    bool ShowCarActions = true; //Show Start/Stop actions
    bool ShowBarrelActions = true; //Show OPEN/CLOSE Actions
    bool ShowTakeStorage = true; //Show taking of items with animations or the {F} key
    bool ShowDropStorage = true; //Show dropping of items with {G}
	bool ShowNVGActions = true; //Show NVG toggle
	bool ShowShock = true; //Show Uncon/Con	
	bool ShowBuryStash = true; //Show buring of stashs
	bool ShowBrokenLegs = true; //Show Broken legs after 3 minutes of character life
	bool ShowSplintAction = true; //Show splints duh
	bool ShowInjectorActions = true; //Show EPI and otherstuff soon
    bool ShowGasPoison = true; //Show POX
	bool ShowLockCode = false; //DANGEROUS! Shows applied lock combo!
	bool ShowConnectionInfo = true; //Shows Connecting/Disconnecting/disconnected
	bool SimpleLogs = true; //Does not show the Entity ID which is unique only per server restart! (Car/Fences)
	bool SimpleLogsStorage = false; //Does not show the Entity ID which is unique only per server restart!
	

};
class MapConfig //LIVE MAP CONFIG
{
	bool ShowStashs = false; //Shows buried stashes on the live map
	//bool ShowTents = false; //Shows tents on map
	//bool ShowShelters = false; //Show Shelters

};

class LogCustomItems //LOG ITEM INPUT BY USER 
{
	bool EnableCustomItems = false; //Allow logic to check for Custom entries. 
	string CustomItem1="";
	string CustomItem2="";
	string CustomItem3="";
	string CustomItem4="";

};

class Testing {
	string CustomItems [] = {"",""};
};




// Save config data
ref ExtraLogsConfig m_LogConfig;
// Helper function to return Config data storage object
static ExtraLogsConfig GetLogConfig()
{
	if (!m_LogConfig)
	{
		Print("[ExtraLogs] Init! Loading config.");
		m_LogConfig = new ExtraLogsConfig;

		// Only load JSON config on the server
		if (GetGame().IsServer())
		{
			m_LogConfig.Load();
		}
	}

	return m_LogConfig;
};

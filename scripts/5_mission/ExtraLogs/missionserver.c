modded class MissionServer {
    override void OnInit() {
		super.OnInit();
        if (GetGameLabs().IsServer()) {
			GetGameLabs().AddMonitoredAction("ActionLockDoors");       
            GetGameLabs().AddMonitoredAction("ActionUnlockDoors");
			GetGameLabs().AddMonitoredAction("ActionTriggerRemotely");
			GetGameLabs().AddMonitoredAction("ActionAttachExplosivesTrigger");
            
            Print("[ExtraLogs] Init Logging!");

            #ifdef EXTRALOGSMMG
                Print("[ExtraLogs] MMG Storage found! Logs are Active.");
            #endif

            #ifdef EXTRALOGSCROCO
                Print("[ExtraLogs] Croco Storage found! Logs are Active.");
            #endif

            #ifdef Trader
                Print("[ExtraLogs] Trader found! Logs are Active.");
            #endif

            #ifdef MuchCarKey
                Print("[ExtraLogs] MuchCarKey found! Logs are Active.");
            #endif

            #ifdef CodeLock
                Print("[ExtraLogs] CodeLock found! Logs are Active.");
            #endif

            #ifdef RAG_BASEITEMS
                Print("[ExtraLogs] Rag Base Items found! Logs are Active.");
            #endif

            #ifdef EXTRALOGSPARAGON
                Print("[ExtraLogs] Paragon Storage found! Logs are Active.");
            #endif

            #ifdef EXTRALOGSRAGBB
                Print("[ExtraLogs] RaG Base Building found! Logs are Active.");
            #endif

        
                

            GetLogConfig();
        }
    }

    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity) {
        super.InvokeOnConnect(player, identity);
        if(m_LogConfig.ServerConfig.ShowConnectionInfo==0) return;
        SendToCFTools(player, "", "", "has connected");
	}

	override void OnClientDisconnectedEvent(PlayerIdentity identity, PlayerBase player, int logoutTime, bool authFailed) {
        super.OnClientDisconnectedEvent(identity, player, logoutTime, authFailed);
        if(m_LogConfig.ServerConfig.ShowConnectionInfo==0) return;
		SendToCFTools(player, "", "", "is disconnecting");
    }

	override void InvokeOnDisconnect(PlayerBase player) {
        super.InvokeOnDisconnect(player);
        if(m_LogConfig.ServerConfig.ShowConnectionInfo==0) return;
        SendToCFTools(player, "", "", "has disconnected");
    }		


}

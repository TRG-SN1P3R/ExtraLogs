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

	override void HandleBody(PlayerBase player){
		super.HandleBody(player);
		bool ShowLog;
		if(player){
			if (player.IsUnconscious() || player.IsRestrained()){

				switch (player.GetKickOffReason()){
				case EClientKicked.SERVER_EXIT:
					ShowLog=false;
					break;
				case EClientKicked.KICK_ALL_ADMIN:
					ShowLog=false;
					break;
				case EClientKicked.KICK_ALL_SERVER:
					ShowLog=false;
					break;
				case EClientKicked.SERVER_SHUTDOWN:
					ShowLog=false;
					break;
				default:
					ShowLog=true;
					break;
				}
			}
		if(ShowLog==true){
			if(player.IsRestrained){
				SendToCFTools(player,"",""," was killed after logging out while Restrained");
			}
			if(player.IsUnconscious){
				SendToCFTools(player,"",""," was killed after logging out while Unconscious");
			}
		}

		
		}
	}


}

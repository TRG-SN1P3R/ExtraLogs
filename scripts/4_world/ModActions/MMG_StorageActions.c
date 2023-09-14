#if (m_LogConfig.MMGStorageActions.MMGStorageInstalled==1) //Is this enabled?

modded class ActionOpenCloseCrate_noLock: ActionInteractBase{
    override void OnStartServer( ActionData action_data ){
        super.OnStartServer(action_data);
        if(m_LogConfig.ModdedActions.ShowMMGStorageCrateAction==0) return;
        if(!action_data.m_Player || !ction_data.m_Target) return;
        if(m_LogConfig.ServerConfig.SimpleLogsStorage==0){
            SendToCFTools(action_data.m_Player,"","",string.Format("%1",action_data.m_Target.GetObject()));
        }else{
            SendToCFTools(action_data.m_Player,"","",action_data.m_Target.GetObject().GetType());
        }
    }
}
#endif
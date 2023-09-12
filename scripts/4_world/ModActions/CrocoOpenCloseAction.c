#ifdef CrocoStorageCrates
modded class ActionOpenOpenableCroco: ActionInteractBase{
    override void OnStartServer( ActionData action_data ){
        super.OnStartServer(action_data);

        if(m_LogConfig.ModdedActions.ShowCrocoStorageActions==0) return;
        if(!action_data.m_Player || !action_data.m_Target) return;
        if(m_LogConfig.ServerConfig.SimpleLogsStorage==0){
            SendToCFTools(action_data.m_Player, "", string.Format("%1", action_data.m_Target.GetObject()), "Opened");
            return;
        }else{
         SendToCFTools(action_data.m_Player, "", string.Format("%1", action_data.m_Target.GetObject().GetType()), "Opened");
        }
    }
}
modded class ActionCloseOpenableCroco: ActionInteractBase{
    override void OnStartServer( ActionData action_data ){
        super.OnStartServer(action_data);

        if(m_LogConfig.ModdedActions.ShowCrocoStorageActions==0) return;
        if(!action_data.m_Player || !action_data.m_Target) return;
        if(m_LogConfig.ServerConfig.SimpleLogsStorage==0){
            SendToCFTools(action_data.m_Player, "", string.Format("%1", action_data.m_Target.GetObject()), "Closed");
            return;
        }else{
         SendToCFTools(action_data.m_Player, "", string.Format("%1", action_data.m_Target.GetObject().GetType()), "Closed");
        }
    }
}
#endif
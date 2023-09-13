#ifdef MMG_storage 
modded class ActionOpenCloseCrate_noLock: ActionInteractBase{
    override void OnStartServer( ActionData action_data ){
        super.OnStartServer(action_data);
        if(m_LogConfig.ModdedActions.ShowMMGStorageCrateAction==0) return;
        
    }
}
#endif
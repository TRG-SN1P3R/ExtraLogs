modded class ActionPackTent : ActionContinuousBase{
    override void OnFinishProgressServer( ActionData action_data ){
        super.OnFinishProgressServer(action_data); //returns to class
        if(m_LogConfig.ServerConfig.ShowTentPack==0) return; //checks if we want to see this
        if(!action_data.m_Player || !action_data.m_Target) return; //checks for vaild data
        SendToCFTools(action_data.m_Player,"","","packed "+string.Format("%1",action_data.m_Target.GetParent()));
    }
}
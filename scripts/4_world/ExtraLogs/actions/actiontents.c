modded class ActionToggleTentOpen
{
    override void OnExecuteServer( ActionData action_data )
	{
        super.OnExecuteServer(action_data);
        if(!action_data.m_Player || !action_data.m_Target) return; //do we have a player and target
        if(m_LogConfig.ServerConfig.ShowTentActions==0) return;//do we want to see this
        Object TentParent = action_data.m_Target.GetParent();
        if(!TentParent) return;
        TentBase tent = TentBase.Cast(TentParent);
        if(tent.DidDoorStateChange()) //did we toggle a door?
        {
            if(tent.GetDoorState()) //is it opened or closed?
            {
                SendToCFTools(action_data.m_Player, "", string.Format("%1",tent), "Opened Entrance on");
                tent.ResetDoorStateChange();//Reset the doorstate bool
            }
            else
            {
                SendToCFTools(action_data.m_Player, "", string.Format("%1",tent), "Closed Entrance on");
                tent.ResetDoorStateChange();//Reset the doorstate bool
            }
        }
    }
};
 
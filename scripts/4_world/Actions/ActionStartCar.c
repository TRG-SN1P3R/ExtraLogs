modded class ActionStartEngine : ActionContinuousBase {
	override void OnFinishProgressServer(ActionData action_data) {
		super.OnFinishProgressServer(action_data);
        if (!action_data.m_Player || !action_data.m_Target) return;
		if (m_LogConfig.ServerConfig.ShowCarActions==0) return; //Do we want to see this?
		if (m_LogConfig.ServerConfig.SimpleLogs==1){//Show only name
        SendToCFTools(action_data.m_Player, "",action_data.m_Target.GetObject().GetType(), "Started Engine ");
		return;
		}
		
		SendToCFTools(action_data.m_Player, "",string.Format("%1",action_data.m_Target.GetObject()), "Started Engine ");

	}
}
modded class ActionStopEngine: ActionSingleUseBase{
	override void OnExecuteServer(ActionData action_data){
		super.OnExecuteServer(action_data);
		if (!action_data.m_Player || !action_data.m_Target) return;
		if (m_LogConfig.ServerConfig.ShowCarActions==0) return; //Do we want to see this?
		if (m_LogConfig.ServerConfig.SimpleLogs==1){//Show only name
        SendToCFTools(action_data.m_Player, "",action_data.m_Target.GetObject().GetType(), "Stopped Engine ");
		return;
		}		
		SendToCFTools(action_data.m_Player, "",string.Format("%1",action_data.m_Target.GetObject()), "Stopped Engine ");

		
	}
}

modded class ActionStartEngine : ActionContinuousBase {
	override void OnFinishProgressServer(ActionData action_data) {
		super.OnFinishProgressServer(action_data);
        if (!action_data.m_Player || !action_data.m_Target) return;
		if (m_LogConfig.ServerConfig.ShowCarActions==0) return; //Do we want to see this?
		SendToCFTools(action_data.m_Player, "",string.Format("%1",action_data.m_Target.GetObject()), "Started Engine ");
	}
}
modded class ActionStopEngine: ActionSingleUseBase{
	override void OnExecuteServer(ActionData action_data){
		super.OnExecuteServer(action_data);
		if (!action_data.m_Player || !action_data.m_Target) return;
		if (m_LogConfig.ServerConfig.ShowCarActions==0) return; //Do we want to see this?
		SendToCFTools(action_data.m_Player, "",string.Format("%1",action_data.m_Target.GetObject()), "Stopped Engine ");
	}
}
modded class ActionPushCar : ActionContinuousBase{
	override void OnStartServer(ActionData action_data)
	{
		super.OnStartServer(action_data);
		if (!action_data.m_Player || !action_data.m_Target) return;
		if (m_LogConfig.ServerConfig.ShowPushingCars==0) return; //Do we want to see this?
		SendToCFTools(action_data.m_Player, "",string.Format("%1",action_data.m_Target.GetObject()), "Pushed ");
		
	}
}

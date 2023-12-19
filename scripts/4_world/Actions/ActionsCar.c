modded class ActionStartEngine : ActionContinuousBase {
	override void OnFinishProgressServer(ActionData action_data) {
		super.OnFinishProgressServer(action_data);
        if (!action_data.m_Player || !action_data.m_Target) return;
		if (m_LogConfig.ServerConfig.ShowCarActions==0) return; //Do we want to see this?
		
		CarScript CarObject = CarScript.Cast(action_data.m_Target.GetObject());
		if (!CarObject) CarObject = CarScript.Cast(action_data.m_Target.GetParent());
		EntityAI CarEntity;
		Class.CastTo(CarEntity, CarObject);
        if (!CarEntity) return;
		if (m_LogConfig.ServerConfig.SimpleLogs==1){//Show only name
        SendToCFTools(action_data.m_Player, "",string.Format("%1",CarEntity.GetType()), "Started Engine ");
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
        SendToCFTools(action_data.m_Player, "",string.Format("%1",ConvTargetCar(action_data)), "Stopped Engine ");
		return;
		}		
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
	private CarScript ConvTargetCar(ActionData action_data)
	{
		if (action_data.m_Target.IsProxy())
			return CarScript.Cast(action_data.m_Target.GetParent());
		
		return CarScript.Cast(action_data.m_Target.GetObject());
	}
modded class ActionStartEngine : ActionContinuousBase {
	override void OnFinishProgressServer(ActionData action_data) {
		super.OnFinishProgressServer(action_data);
        if (!action_data.m_Player || !action_data.m_Target) return;
		if (m_LogConfig.ServerConfig.ShowCarActions==0) return;
		if (m_LogConfig.ServerConfig.SimpleLogs==1){//Show only name
		CarScript CarObject = CarScript.Cast(action_data.m_Target.GetObject());
		if (!CarObject) CarObject = CarScript.Cast(action_data.m_Target.GetParent());
		EntityAI CarEntity;
		Class.CastTo(CarEntity, CarObject);
        if (!CarEntity) return;
        SendToCFTools(action_data.m_Player, "",CarEntity.GetType(), "Started Engine ");
		return;
		}
		
		SendToCFTools(action_data.m_Player, "",string.Format("%1",action_data.m_Target.GetObject()), "Stopped Engine ");

	}
}
modded class ActionStopEngine: ActionSingleUseBase{
	override void OnExecuteServer(ActionData action_data){
		super.OnExecuteServer(action_data);
		if (!action_data.m_Player || !action_data.m_Target) return;
		if (m_LogConfig.ServerConfig.ShowCarActions==0) return;
		if (m_LogConfig.ServerConfig.SimpleLogs==1){//Show only name
		CarScript CarObject = CarScript.Cast(action_data.m_Target.GetObject());
		if (!CarObject) CarObject = CarScript.Cast(action_data.m_Target.GetParent());
		EntityAI CarEntity;
		Class.CastTo(CarEntity, CarObject);
        if (!CarEntity) return;
        SendToCFTools(action_data.m_Player, "",CarEntity.GetType(), "Stopped Engine ");
		return;
		}
		
		SendToCFTools(action_data.m_Player, "",string.Format("%1",action_data.m_Target.GetObject()), "Stopped Engine ");

		
	}
}

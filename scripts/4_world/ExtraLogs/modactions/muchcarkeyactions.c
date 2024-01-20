#ifdef MuchCarKey

modded class ActionPickLockOnCar: ActionLockUnlockCar {
	override void OnFinishProgressServer(ActionData action_data) {
        super.OnFinishProgressServer(action_data);
		if (!action_data.m_Player || !action_data.m_Target) return;
        if (m_LogConfig.MuchCarKey.ShowLockActions==0) return;
        CarScript carScript = CarScript.Cast(action_data.m_Target.GetObject());
		if(!carScript) carScript = CarScript.Cast(action_data.m_Target.GetParent());
        if(!carScript) return;
        if (!carScript.m_IsCKLocked && !carScript.m_HasCKAssigned) {
            SendToCFTools(action_data.m_Player, action_data.m_MainItem.GetType(), carScript.GetType(), "has successful picked");
        } else {
            SendToCFTools(action_data.m_Player, action_data.m_MainItem.GetType(), carScript.GetType(), "has failed to pick");
        }
    }
}

modded class ActionLockCar: ActionLockUnlockCar {
	override void OnFinishProgressServer(ActionData action_data) {
        super.OnFinishProgressServer(action_data);

		if (!action_data.m_Player || !action_data.m_Target || !action_data.m_MainItem) return;
        if (m_LogConfig.MuchCarKey.ShowLockActions==0) return; //Do we want to see this?
        CarScript carScript = CarScript.Cast(action_data.m_Target.GetParent());
         if(!carScript){
            SendToCFTools(action_data.m_Player, action_data.m_MainItem.GetType(), string.Format("%1",action_data.m_Target.GetObject().GetType()), "locked");
            return;
        }
        SendToCFTools(action_data.m_Player, action_data.m_MainItem.GetType(), carScript.GetType(), "locked");
    }
}

modded class ActionUnlockCar: ActionLockUnlockCar {
	override void OnFinishProgressServer(ActionData action_data) {	
        super.OnFinishProgressServer(action_data);

		if (!action_data.m_Player || !action_data.m_Target || !action_data.m_MainItem) return;
        if (m_LogConfig.MuchCarKey.ShowLockActions==0) return; //Do we want to see this?
        CarScript carScript = CarScript.Cast(action_data.m_Target.GetParent());
        if(!carScript){
            SendToCFTools(action_data.m_Player, action_data.m_MainItem.GetType(), string.Format("%1",action_data.m_Target.GetObject().GetType()), "unlocked");
            return;
        }
        SendToCFTools(action_data.m_Player, action_data.m_MainItem.GetType(), carScript.GetType(), "unlocked");
        }
    }
#endif
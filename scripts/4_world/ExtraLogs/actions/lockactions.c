modded class ActionAttachToConstruction: ActionSingleUseBase {
	
	override void OnStartServer(ActionData action_data) {
		super.OnStartServer(action_data);
		if(!action_data.m_Player || !action_data.m_Target) return;
		if(m_LogConfig.ServerConfig.ShowLockAttach==0) return; //checks to see if we want to see this
		CombinationLock lock = CombinationLock.Cast(action_data.m_MainItem);//Take Item to clas CombinationLock to get COMBO
		
		if(m_LogConfig.ServerConfig.ShowLockCode==1 && lock){
			if(m_LogConfig.ServerConfig.SimpleLockLogs==1){
				SendToCFTools(action_data.m_Player,"",string.Format("%1 to %2 CODE:%3", action_data.m_MainItem.GetType(), action_data.m_Target.GetObject().GetType(), lock.GetCombination()),"attached "); 
				return;
			}
			else
			{
				SendToCFTools(action_data.m_Player,"",string.Format("%1 to %2 CODE:%3", lock, action_data.m_Target.GetObject(), lock.GetCombination()),"attached ");//simple logs
				return;
			}
		}

		if(m_LogConfig.ServerConfig.SimpleLockLogs==1)
		{
			SendToCFTools(action_data.m_Player,"",string.Format("%1 to %2", action_data.m_MainItem.GetType(), action_data.m_Target.GetObject().GetType()),"attached "); //shows lock id and fence id
			return;
		}
		SendToCFTools(action_data.m_Player,"",string.Format("%1 to %2", lock, action_data.m_Target.GetObject()),"attached "); //show simple logs
	}
}

modded class ActionDialCombinationLockOnTarget {
	
	override void OnFinishProgressServer(ActionData action_data)
	{	
		//set dialed number
		ConstructionActionData constructionActionData = action_data.m_Player.GetConstructionActionData();
		CombinationLock combination_lock = constructionActionData.GetCombinationLock();
		if (combination_lock)
		{
			combination_lock.DialNextNumber();
	
			//check for unlock state
			if (!combination_lock.IsLockedOnGate())
			{
				if(m_LogConfig.ServerConfig.ShowLockUnlock==1){
					if(!action_data.m_Player || !action_data.m_Target) return; //checks to see if we want to see this
					if(m_LogConfig.ServerConfig.SimpleLockLogs==1){
						SendToCFTools(action_data.m_Player,"",combination_lock.GetType(),"unlocked ");
					}else
						SendToCFTools(action_data.m_Player,"",string.Format("%1", combination_lock,),"unlocked ");
				}


				EntityAI target_entity = EntityAI.Cast(action_data.m_Target.GetObject());
				combination_lock.UnlockServer(action_data.m_Player, target_entity.GetHierarchyParent());

			}
		}
	}
}

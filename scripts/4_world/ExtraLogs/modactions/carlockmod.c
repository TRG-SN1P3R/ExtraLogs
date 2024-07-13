#ifdef EXTRALOGCARLOCKMOD

modded class ActionDetachCarLockPick: ActionContinuousBase //LOCKPICK
{

   override void OnStartAnimationLoopServer(ActionData action_data)
   {
	super.OnStartAnimationLoopServer(action_data);
	if(!action_data.m_Player) return;
    if(m_LogConfig.CarLockMod.ShowCarLockLogs==0 || m_LogConfig.CarLockMod.ShowLockActions==0 ) return;
	CarScript car = CarScript.Cast(action_data.m_Target.GetObject());
	if(!car)return;
	SendToCFTools(action_data.m_Player,"",string.Format("%1",car.ToString()),"started lockpicking ");
   }

   override void OnFinishProgressServer(ActionData action_data)
	{
	  super.OnFinishProgressServer(action_data);
	  if(!action_data.m_Player) return;
      if(m_LogConfig.CarLockMod.ShowCarLockLogs==0 || m_LogConfig.CarLockMod.ShowLockActions==0 ) return;
	  CarScript car = CarScript.Cast(action_data.m_Target.GetObject());
	  if(!car)return;
	  SendToCFTools(action_data.m_Player,"",string.Format("%1",car.ToString()),"lockpicked ");
	}
}

modded class ActionCarUnLock: ActionContinuousBase //UNLOCK
{
	override void OnEndServer( ActionData action_data )
	{
		if(m_LogConfig.CarLockMod.ShowUnlockActions==0 || m_LogConfig.CarLockMod.ShowCarLockLogs==0 || !action_data.m_Player || !action_data.m_Target) return;
		CarScript car = CarScript.Cast(action_data.m_Target.GetObject());
		if(!car) return;
		SendToCFTools(action_data.m_Player,"",string.Format("%1",car.ToString()),"unlocked ");//send to CF
	}
}

modded class ActionCarLock: ActionContinuousBase //LOCK
{
	override void OnEndServer( ActionData action_data )
	{
		if(m_LogConfig.CarLockMod.ShowLockActions==0 || m_LogConfig.CarLockMod.ShowCarLockLogs==0 || !action_data.m_Player || !action_data.m_Target) return;
		CarScript car = CarScript.Cast(action_data.m_Target.GetObject());
		if(!car) return;
		SendToCFTools(action_data.m_Player,"",string.Format("%1",car.ToString()),"locked ");//send to CF
	}
}

modded class ActionAttachCarLock: ActionContinuousBase //ATTACH
{
	override void OnFinishProgressServer( ActionData action_data )
	{
		super.OnFinishProgressServer(action_data);
		if(m_LogConfig.CarLockMod.ShowMiscActions==0 || m_LogConfig.CarLockMod.ShowCarLockLogs==0 || !action_data.m_Player || !action_data.m_Target) return;
		CarScript car = CarScript.Cast(action_data.m_Target.GetObject());
		if(!car)return;
		SendToCFTools(action_data.m_Player,"",string.Format("%1",car.ToString()),"attached lock to");//send to CF
	}
}

modded class  ActionDetachCarLock: ActionContinuousBase //DETACH
{
	override void OnFinishProgressServer( ActionData action_data )
	{
		super.OnFinishProgressServer(action_data);
		if(m_LogConfig.CarLockMod.ShowMiscActions==0 || m_LogConfig.CarLockMod.ShowCarLockLogs==0 || !action_data.m_Player || !action_data.m_Target) return;
		CarScript car = CarScript.Cast(action_data.m_Target.GetObject());
		if(!car)return;
		SendToCFTools(action_data.m_Player,"",string.Format("%1",car.ToString()),"removed lock from ");//send to CF
	}
}
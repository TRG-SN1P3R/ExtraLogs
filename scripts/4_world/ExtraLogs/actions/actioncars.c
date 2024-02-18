modded class ActionStartEngine : ActionContinuousBase {
	override void OnFinishProgressServer(ActionData action_data) {
		super.OnFinishProgressServer(action_data);
        if (!action_data.m_Player || !action_data.m_Target) return;
		if (m_LogConfig.ServerConfig.ShowCarActions==0) return; //Do we want to see this?

		CarScript m_car = CarScript.Cast(action_data.m_Player.GetDrivingVehicle());
		if(!m_car) return; 
		if (m_LogConfig.ServerConfig.SimpleLogs==0){//Show Full info
			SendToCFTools(action_data.m_Player, "",string.Format("%1",m_car.ToString()), "Started Engine ");
			return;
		}
			SendToCFTools(action_data.m_Player, "",string.Format("%1",m_car.GetType()), "Started Engine ");
	}
}


modded class ActionStopEngine: ActionSingleUseBase{
	override void OnExecuteServer(ActionData action_data){
		super.OnExecuteServer(action_data);
		if (!action_data.m_Player || !action_data.m_Target) return;
		if (m_LogConfig.ServerConfig.ShowCarActions==0) return; //Do we want to see this?
		
		CarScript m_car = CarScript.Cast(action_data.m_Player.GetDrivingVehicle());
		if(!m_car) return;
		Print(m_car);
		if (m_LogConfig.ServerConfig.SimpleLogs==0){//Show Full info
			SendToCFTools(action_data.m_Player, "",string.Format("%1",m_car.ToString()), "Stopped Engine ");
			return;
		}
			SendToCFTools(action_data.m_Player, "",string.Format("%1",m_car.GetType()), "Stopped Engine ");
		
	}
}


modded class ActionPushCar : ActionContinuousBase{
	override void OnStartServer(ActionData action_data)
	{
		super.OnStartServer(action_data);
		if (!action_data.m_Player || !action_data.m_Target) return;
		if (m_LogConfig.ServerConfig.ShowPushingCars==0 || m_LogConfig.ServerConfig.ShowCarActions==0) return; //Do we want to see this?
		
		ActionPushCarData data = ActionPushCarData.Cast(action_data);
		if (m_LogConfig.ServerConfig.SimpleLogs==0){//Show Full info
			SendToCFTools(action_data.m_Player, "",string.Format("%1",data.m_Car.ToString()), "Pushed ");
			return;
		}
			SendToCFTools(action_data.m_Player, "",string.Format("%1",data.m_Car.GetType()), "Pushed ");
		
	}
}

modded class ActionGetInTransport: ActionBase{
	override void OnEndServer(ActionData action_data)
	{
		super.OnEndServer(action_data);
		if(m_LogConfig.ServerConfig.ShowCarActions==0) return; //Do we want to see this?
		if(!action_data.m_Player) return;
		
		CarScript car = CarScript.Cast(action_data.m_Target.GetObject());
		if(!car) return;
		if(m_LogConfig.ServerConfig.SimpleLogs==0){//Show Full info
			SendToCFTools(action_data.m_Player,"",string.Format("%1",car.ToString()),"got into ");
			return;
		}
			SendToCFTools(action_data.m_Player,"",string.Format("%1",car.GetType()),"got into ");
		
	}
}

modded class ActionGetOutTransport : ActionBase{
	override void OnEndServer(ActionData action_data){
		super.OnEndServer(action_data);
		if(m_LogConfig.ServerConfig.ShowCarActions==0) return; //Do we want to see this?
		if(!action_data.m_Player) return;
		GetOutTransportActionData gotActionData = GetOutTransportActionData.Cast(action_data);
		if(!gotActionData) return;
		
		if(m_LogConfig.ServerConfig.SimpleLogs==0){//Show Full info
			SendToCFTools(action_data.m_Player,"",string.Format("%1",gotActionData.m_Car.ToString()),"got out of ");
			return;
		}
		SendToCFTools(action_data.m_Player,"",string.Format("%1",gotActionData.m_Car.GetType()),"got out of ");
	}
}

modded class ActionCloseCarDoorsOutside: ActionCarDoorsOutside{
	/*override void OnEndServer(ActionData action_data){
		super.OnEndServer(action_data);
		if(m_LogConfig.ServerConfig.ShowCarActions==0 || m_LogConfig.ServerConfig.ShowDoorActions==0 ) return; //Do we want to see this?
		if(!action_data.m_Player) return;
		CarScript car = CarScript.Cast(action_data.m_Target.GetObject());
		if(!car) return;
		Print(car);
		
	}*/
		override void OnStartServer( ActionData action_data ){
			super.OnStartServer(action_data);
			if(m_LogConfig.ServerConfig.ShowCarActions==0 || m_LogConfig.ServerConfig.ShowDoorActions==0 ) return; //Do we want to see this?
			if(!action_data.m_Player) return; 
			
			CarScript car = CarScript.Cast(action_data.m_Target.GetParent());
			if (car)
			{	
				CarDoor carDoor = CarDoor.Cast(action_data.m_Target.GetObject());
				SendToCFTools(action_data.m_Player,"",string.Format("%1",carDoor.GetType()),"closed ");
			}
			else return;

		}
}

modded class ActionOpenCarDoorsOutside: ActionCarDoorsOutside{
	override void OnStartServer( ActionData action_data ){
		super.OnStartServer(action_data);
		if(m_LogConfig.ServerConfig.ShowCarActions==0 || m_LogConfig.ServerConfig.ShowDoorActions==0 ) return; //Do we want to see this?
		if(!action_data.m_Player) return; 
			
		CarScript car = CarScript.Cast(action_data.m_Target.GetParent());
		if (car)
		{	
			CarDoor carDoor = CarDoor.Cast(action_data.m_Target.GetObject());
			SendToCFTools(action_data.m_Player,"",string.Format("%1",carDoor.GetType()),"opened ");
		}
		else return;
	}
}

modded class CarScript{

	protected PlayerBase lastHitPlayer; //Store last player to hit this object
	protected bool carDestroyed = false; //Prevent double logs
	
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult,damageType,source,component,dmgZone,ammo,modelPos,speedCoef);
		
		if(m_LogConfig.ServerConfig.ShowCarActions==0 || m_LogConfig.ServerConfig.ShowCarDestruction==0) return; //Do we want to see this?
		if(!source) return;
		PlayerBase m_Player = PlayerBase.Cast(source.GetHierarchyRootPlayer());
		if(!m_Player) return;
		if(m_Player==lastHitPlayer) return; //Is stored player the same? IF yes no need to save again.
		lastHitPlayer=m_Player; //Save last player based on last hit.
	}

	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone)
	{
    	super.EEHealthLevelChanged(oldLevel,newLevel,zone);
		if(m_LogConfig.ServerConfig.ShowCarActions==0 || m_LogConfig.ServerConfig.ShowCarDestruction==0) return;//Do we want to see this?
		if(!lastHitPlayer) return;
		if(zone == "Engine" || zone == "Chassis"){ //Only show engine or chassis going to ruined state
			if(newLevel == GameConstants.STATE_RUINED && lastHitPlayer && carDestroyed == false){ //Pull last playerbase on this object from EEHitBy call.
				SendToCFTools(lastHitPlayer,"","",string.Format("ruined %1",this.ToString()));
				carDestroyed = true;
			}
		}
    }
}


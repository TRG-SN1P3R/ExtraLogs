modded class ActionPushBoat
{
    override void OnStartServer(ActionData action_data)
	{
		super.OnStartServer(action_data);

        if(!action_data.m_Player || !action_data.m_Target) return;
		if(m_LogConfig.ServerConfig.ShowPushingBoats==0) return; //checks to see if we want to see this

        if (m_LogConfig.ServerConfig.SimpleLogs==0){//Show Full info
			SendToCFTools(action_data.m_Player, "",string.Format("%1",action_data.m_Target.GetObject()), "Pushed ");
			return;
		}
			SendToCFTools(action_data.m_Player, "",string.Format("%1",action_data.m_Target.GetObject().GetType()), "Pushed ");
    }
}

modded class ActionStartEngineBoat
{
	override void OnExecuteServer(ActionData action_data) 
	{
		super.OnExecuteServer(action_data);
		if (m_LogConfig.ServerConfig.ShowBoatActions==0 || !action_data.m_Player || !action_data.m_Target) return; //Do we want to see this, do we meet all conditions?
		BoatScript boat = BoatScript.Cast(action_data.m_Player.GetDrivingVehicle());
		if(!boat) return; 
		if (m_LogConfig.ServerConfig.SimpleLogs==0){//Show Full info
			SendToCFTools(action_data.m_Player, "",string.Format("%1",boat), "Started Engine ");
			return;
		}
			SendToCFTools(action_data.m_Player, "",string.Format("%1",boat.GetType()), "Started Engine ");
	}

}

modded class ActionStopEngineBoat
{
	override void OnExecute(ActionData action_data)
	{
		if (m_LogConfig.ServerConfig.ShowCarActions==0 || !action_data.m_Player || !action_data.m_Target) return; //Do we want to see this, do we meet all conditions?
		BoatScript boat = BoatScript.Cast(action_data.m_Player.GetDrivingVehicle());
		if(!boat) return;
		if (m_LogConfig.ServerConfig.SimpleLogs==0){//Show Full info
			SendToCFTools(action_data.m_Player, "",string.Format("%1",boat), "Stopped Engine ");
			return;
		}
			SendToCFTools(action_data.m_Player, "",string.Format("%1",boat.GetType()), "Stopped Engine ");
	}
}


/*modded class BoatScript{

	protected PlayerBase lastHitPlayer; //Store last player to hit this object
	protected bool boatDestroyed = false; //Prevent double logs
	
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult,damageType,source,component,dmgZone,ammo,modelPos,speedCoef);
		
		if(m_LogConfig.ServerConfig.ShowCarDestruction==0) return; //Do we want to see this?
		if(!source) return;
		PlayerBase m_Player = PlayerBase.Cast(source.GetHierarchyRootPlayer());
		if(!m_Player) return;
		if(m_Player==lastHitPlayer) return; //Is stored player the same? IF yes no need to save again.
		lastHitPlayer=m_Player; //Save last player based on last hit.
	}

	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone)
	{
    	super.EEHealthLevelChanged(oldLevel,newLevel,zone);
		if(m_LogConfig.ServerConfig.ShowCarDestruction==0) return;//Do we want to see this?
		if(!lastHitPlayer) return;
		Print(zone);
		if(zone == "Engine" || zone == "Chassis"){ //Only show engine or chassis going to ruined state
			if(newLevel == GameConstants.STATE_RUINED && lastHitPlayer && boatDestroyed == false){ //Pull last playerbase on this object from EEHitBy call.
				SendToCFTools(lastHitPlayer,"","",string.Format("ruined %1",this.ToString()));
				boatDestroyed = true;
			}
		}
    }
}*/

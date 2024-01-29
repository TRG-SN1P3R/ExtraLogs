modded class CarScript{
	/*
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		
		PlayerBase m_Player = PlayerBase.Cast(source.GetHierarchyRootPlayer());
		if(!m_Player) return;
		CarScript carTemp = this;
		Print(carTemp);
		bool objectRunied =  IsDamageDestroyed();
		Print(objectRunied);
		if(objectRunied){
		SendToCFTools(m_Player,"",string.Format("%1",carTemp.ToString()),"destroyed ");
		}
	}
	*/
}

modded class BaseBuildingBase{
	
	protected PlayerBase lastHitPlayer;
	protected string lastHitAmmo;
	
	override void OnPartDestroyedServer(Man player, string part_name, int action_id, bool destroyed_by_connected_part = false ){
	super.OnPartDestroyedServer(player, part_name, action_id, destroyed_by_connected_part);
		if(m_LogConfig.ServerConfig.ShowBaseDamage==0)return;
		string AdminLog=""; //Allow us to modify our item name to more normal lingo.
		string message = "Destroyed Base Object "; //preface of the message.
		if(!lastHitPlayer){
			Print("[ExtraLogs] DEBUG: BaseBuildingBase.OnPartDestroyedServer: NO Playerbase found!");
			message = "(IGNORE PLAYER) Destroyed Base Object ";

		}
		switch(part_name){
			
			case "wall_metal_up":
				AdminLog="Lower Metal Wall";
				break;
			case "wall_metal_down":
				AdminLog="Lower Metal Wall";
				break;
			case "wall_wood_down":
				AdminLog = "Lower Wooden Wall";
				break;
			case "wall_wood_up":
				AdminLog = "Upper Wooden Wall";
				break;
			case "wall_base_up":
				AdminLog = "Upper Frame";
				break;
			case "wall_base_down":
				AdminLog = "Lower Frame";
				break;
			default:
				AdminLog=part_name;
				break;
			}
		if(AdminLog=="wall_gate") return;
		message = message+AdminLog;
		SendToCFTools(lastHitPlayer,"","",message);			
	}

	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		if(m_LogConfig.ServerConfig.ShowBaseDamage==0)return;
		PlayerBase m_Player = PlayerBase.Cast(source.GetHierarchyRootPlayer());
		
		if(!m_Player) return;

		float objectHealth = GetHealth(dmgZone, "Health");
		if(objectHealth<=0){
		lastHitPlayer = m_Player;
		}
	}
}
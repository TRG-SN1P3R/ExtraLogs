modded class Barrel_ColorBase{

    protected PlayerBase lastHitPlayer; 

	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult,damageType,source,component,dmgZone,ammo,modelPos,speedCoef);
		if(m_LogConfig.ServerConfig.ShowItemDestruction==0) return;//Do we want to see this
		
		PlayerBase m_Player = PlayerBase.Cast(source.GetHierarchyRootPlayer());

		if(!m_Player) return;
		if(m_Player==lastHitPlayer) return; //Is stored player the same? IF yes no need to save again.
		
		lastHitPlayer=m_Player; //Save last player based on last hit.
	}


  		override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone)
	{
        super.EEHealthLevelChanged(oldLevel,newLevel,zone);
		if(m_LogConfig.ServerConfig.ShowItemDestruction==0) return;
        if(newLevel == GameConstants.STATE_RUINED && lastHitPlayer){
            SendToCFTools(lastHitPlayer,"","",string.Format("destoryed %1",this.ToString()));
        }
    }
}

modded class SeaChest{

    protected PlayerBase lastHitPlayer; 

	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult,damageType,source,component,dmgZone,ammo,modelPos,speedCoef);
		if(m_LogConfig.ServerConfig.ShowItemDestruction==0) return;//Do we want to see this
		
		PlayerBase m_Player = PlayerBase.Cast(source.GetHierarchyRootPlayer());

		if(!m_Player) return;
		if(m_Player==lastHitPlayer) return; //Is stored player the same? IF yes no need to save again.
		
		lastHitPlayer=m_Player; //Save last player based on last hit.
	}


    	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone)
	{
        super.EEHealthLevelChanged(oldLevel,newLevel,zone);
		if(m_LogConfig.ServerConfig.ShowItemDestruction==0) return;
        if(newLevel == GameConstants.STATE_RUINED && lastHitPlayer){
            SendToCFTools(lastHitPlayer,"","",string.Format("destoryed %1",this.ToString()));
        }
    }
}

modded class WoodenCrate{

    protected PlayerBase lastHitPlayer; 

	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult,damageType,source,component,dmgZone,ammo,modelPos,speedCoef);
		if(m_LogConfig.ServerConfig.ShowItemDestruction==0) return;//Do we want to see this
		
		PlayerBase m_Player = PlayerBase.Cast(source.GetHierarchyRootPlayer());
		
		if(!m_Player) return;
		if(m_Player==lastHitPlayer) return; //Is stored player the same? IF yes no need to save again.
		
		lastHitPlayer=m_Player; //Save last player based on last hit.
	}


		override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone)
	{
        super.EEHealthLevelChanged(oldLevel,newLevel,zone);
		if(m_LogConfig.ServerConfig.ShowItemDestruction==0) return;
        if(newLevel == GameConstants.STATE_RUINED && lastHitPlayer){
            SendToCFTools(lastHitPlayer,"","",string.Format("destoryed %1",this.ToString()));
        }
    }

}

/*modded class TentBase {
	protected PlayerBase lastHitPlayer;

	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult,damageType,source,component,dmgZone,ammo,modelPos,speedCoef);
		if(m_LogConfig.ServerConfig.ShowItemDestruction==0) return;//Do we want to see this
		
		PlayerBase m_Player = PlayerBase.Cast(source.GetHierarchyRootPlayer());
		
		if(!m_Player) return;
		if(m_Player==lastHitPlayer) return; //Is stored player the same? IF yes no need to save again.
		
		lastHitPlayer=m_Player; //Save last player based on last hit.
	}


	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone)
	{
    	super.EEHealthLevelChanged(oldLevel,newLevel,zone);
		if(m_LogConfig.ServerConfig.ShowItemDestruction==0) return;
		Print(zone);
		Print(lastHitPlayer);
        if(newLevel == GameConstants.STATE_RUINED && zone == "body" && lastHitPlayer){
            SendToCFTools(lastHitPlayer,"","",string.Format("destoryed %1",this.ToString()));
        }
    }

}*/


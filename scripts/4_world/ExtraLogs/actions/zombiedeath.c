/*modded class ZombieBase : DayZInfected
{
	bool ELHasDied;
    //OVERRIDE AND OVERWRITE EEHITBY
    override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);

		if(!IsAlive()&& !ELHasDied)
	}

}
*/
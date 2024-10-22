modded class ActionLockDoors: ActionContinuousBase
{
    override void OnFinishProgressServer( ActionData action_data )
	{
        super.OnFinishProgressServer(action_data);
        if(!action_data.m_Player || !action_data.m_Target) return;//Check for NULL
        Building building;

		if (Class.CastTo(building, action_data.m_Target.GetObject()) )
		{
			int doorIndex = building.GetDoorIndex(action_data.m_Target.GetComponentIndex());
			if ( doorIndex != -1 )
			{
				SendToCFTools(action_data.m_Player,"","",string.Format("Locked %1",action_data.m_Target.GetObject()));
			}		
		}
    }
}

modded class ActionUnlockDoors: ActionContinuousBase
{
     override void OnFinishProgressServer( ActionData action_data )
	{
        super.OnFinishProgressServer(action_data);
        if(!action_data.m_Player || !action_data.m_Target) return;//Check for NULL
        Building building;

		if (Class.CastTo(building, action_data.m_Target.GetObject()) )
		{
			int doorIndex = building.GetDoorIndex(action_data.m_Target.GetComponentIndex());
			if ( doorIndex != -1 )
			{
				SendToCFTools(action_data.m_Player,"","",string.Format("Unlocked %1",action_data.m_Target.GetObject()));
			}		
		}
    }

}
#ifdef EXTRALOGSMUCHSTUFF
modded class ActionCustomClose
{
    override void OnStartServer( ActionData action_data )
	{
        super.OnStartServer(action_data);
        if(!action_data.m_Player || !action_data.m_Target) return; //do we have a player and target
        if(m_LogConfig.MuchStuff.ShowStorageActions==0) return;//do we want to see this
        SendToCFTools(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject().GetDisplayName()+GetEnitiyIDFromObject(action_data)),"closed ")
    }
}

modded class ActionCustomOpen
{
    override void OnStartServer( ActionData action_data )
	{
        super.OnStartServer(action_data);
        if(!action_data.m_Player || !action_data.m_Target) return; //do we have a player and target
        if(m_LogConfig.MuchStuff.ShowStorageActions==0) return;//do we want to see this
        SendToCFTools(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject().GetDisplayName()+GetEnitiyIDFromObject(action_data)),"opened ")
    }
}

modded class ActionAttachCodeLockToMSP
{
    override void OnExecuteServer(ActionData action_data)
    {
        super.OnExecuteServer(action_data);
        if(!action_data.m_Player || !action_data.m_Target) return; //do we have a player and target
        if(m_LogConfig.MuchStuff.ShowLockActions==0) return;//do we want to see this
        SendToCFTools(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject().GetDisplayName()+GetEnitiyIDFromObject(action_data)),"attached CodeLock to ")
    }
}

modded class ActionRaidCodelockOnMSP
{
    override void OnFinishProgressServer(ActionData action_data)
    {
        super.OnFinishProgressServer(action_data);
        if(!GetMuchCodelockConfig())
        {
            return;
        }
        if (!GetMuchCodelockConfig().CanRaid())
        {
            return;
        }

        if(!action_data.m_Player || !action_data.m_Target) return; //do we have a player and target
        if(m_LogConfig.MuchStuff.ShowLockActions==0 || m_LogConfig.MuchStuff.ShowLockRaid==0) return;//do we want to see this

        ItemBase itemBase = ItemBase.Cast(action_data.m_Target.GetObject());
        if (itemBase)
        {
            CodeLock codelock = itemBase.GetCodeLock();

            if (codelock) 
            {
                float _maxHealth = codelock.GetMaxHealth("", "Health");
                float raidIncrementAmount = _maxHealth / GetDayZGame().GetCodeLockConfig().GetIncrementAmount();
                float tempHealth =  codelock.GetHealth()-raidIncrementAmount;
                int healthPercentage = (tempHealth / m_MaxHealth) * 100;

                if (tempHealth > 0) 
                {
                    SendToCFTools(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject().GetDisplayName()+GetEnitiyIDFromObject(action_data)),"Raiding CodeLock HP: " + healthPercentage + "%");

                } 
                else
                {
                    if (GetMuchCodelockConfig().ShouldDeleteLockOnRaid())//DELETING CODELOCK
                    {
                        SendToCFTools(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject().GetDisplayName()+GetEnitiyIDFromObject(action_data)),"Destoryed CodeLock ");
                        return;
                    }
                    //DROPING CODELOCK
                    SendToCFTools(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject().GetDisplayName()+GetEnitiyIDFromObject(action_data)),"Dropped CodeLock ");

                }
            }
        }
    }
}
#endif
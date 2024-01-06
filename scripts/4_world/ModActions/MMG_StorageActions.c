#ifdef EXTRALOGSMMG

modded class ActionOpenCloseCrate_noLock: ActionInteractBase{
     override void OnStartServer( ActionData action_data ){
        super.OnStartServer(action_data);
        if(m_LogConfig.MMGStorage.ShowMMGStorageActions==0) return;
        if(!action_data.m_Player || !action_data.m_Target) return;
        ItemBase building = ItemBase.Cast(action_data.m_Target.GetObject());
        bool State = building.IsOpen();
        string StateAction;
        if(State==true){
            StateAction="Opened ";
        }else{
             StateAction="Closed ";
        }
        if(m_LogConfig.ServerConfig.SimpleLogsStorage==0){
            SendToCFTools(action_data.m_Player,"",action_data.m_Target.GetObject().GetDisplayName()+GetEnitiyIDFromObject(action_data),StateAction);
        }else{
            SendToCFTools(action_data.m_Player,"",action_data.m_Target.GetObject().GetDisplayName(),StateAction);
        }
    }
}

modded class ActionOpenCloseCrate: ActionInteractBase{
    override void OnStartServer( ActionData action_data ){
        super.OnStartServer(action_data);
        if(m_LogConfig.MMGStorage.ShowMMGStorageActions==0) return;
        if(!action_data.m_Player || !action_data.m_Target) return;
        ItemBase building = ItemBase.Cast(action_data.m_Target.GetObject());
        bool State = building.IsOpen();
        string StateAction;
        if(State==true){
            StateAction="Opened ";
        }else{
             StateAction="Closed ";
        }
        if(m_LogConfig.ServerConfig.SimpleLogsStorage==0){
            SendToCFTools(action_data.m_Player,"",action_data.m_Target.GetObject().GetDisplayName()+GetEnitiyIDFromObject(action_data),StateAction);
        }else{
            SendToCFTools(action_data.m_Player,"",action_data.m_Target.GetObject().GetDisplayName(),StateAction);
        }
    }
}

modded class ActionMMGOpen : ActionInteractBase{
    override void OnStartServer( ActionData action_data ){
        super.OnStartServer(action_data);
        if(m_LogConfig.MMGStorage.ShowMMGStorageActions==0) return;
        if(!action_data.m_Player || !action_data.m_Target) return;
        if(m_LogConfig.ServerConfig.SimpleLogsStorage==0){
            SendToCFTools(action_data.m_Player,"",action_data.m_Target.GetObject().GetDisplayName()+GetEnitiyIDFromObject(action_data),"Opened ");
        }else{
            SendToCFTools(action_data.m_Player,"",action_data.m_Target.GetObject().GetDisplayName(),"Opened ");
        }
    }
}

modded class ActionMMGClose: ActionInteractBase{
     override void OnStartServer( ActionData action_data ){
        super.OnStartServer(action_data);
        if(m_LogConfig.MMGStorage.ShowMMGStorageActions==0) return;
        if(!action_data.m_Player || !action_data.m_Target) return;
        if(m_LogConfig.ServerConfig.SimpleLogsStorage==0){
            SendToCFTools(action_data.m_Player,"",action_data.m_Target.GetObject().GetDisplayName()+GetEnitiyIDFromObject(action_data),"Closed ");
        }else{
            SendToCFTools(action_data.m_Player,"",action_data.m_Target.GetObject().GetDisplayName(),"Closed ");
        }
    }
}
modded class ActionDestroyCodeLock_MMG{

     override void OnFinishProgressServer(ActionData action_data)
    {
        super.OnFinishProgressServer(action_data);
        //Gate Log via config
        if(m_LogConfig.MMGStorage.ShowMMGStorageActions==0) return; //do we want to see this?
        if(m_LogConfig.MMGStorage.ShowRaid==0) return; //do we want to see this?
        if(!action_data.m_Player || !action_data.m_Target) return; //Are our inputs valid?


        if (!GetMMGConfigManagerPlugin().GetConfig().EnableRaid()) return;
        ItemBase itemBase = ItemBase.Cast(action_data.m_Target.GetObject());

        if (!itemBase) return;
        CodeLock codelock = itemBase.GetCodeLock();

        if (!codelock) return;
        float _maxHealth = codelock.GetMaxHealth("", "Health");
        float raidIncrementAmount = _maxHealth / GetDayZGame().GetCodeLockConfig().GetIncrementAmount();
        float tempHealth = codelock.GetHealth()-raidIncrementAmount;
        float _Health = codelock.GetHealth();

        if (_Health > 0) 
		{
            if(m_LogConfig.ServerConfig.SimpleLogsStorage==0){
                SendToCFTools(action_data.m_Player,"",action_data.m_Target.GetObject().GetDisplayName()+GetEnitiyIDFromObject(action_data),"Destoryed CodeLock ");
            }else{
                SendToCFTools(action_data.m_Player,"",action_data.m_Target.GetObject().GetDisplayName(),"Destoryed CodeLock ");
            }
        } 
		else 
		{
            if(m_LogConfig.ServerConfig.SimpleLogsStorage==0){
                SendToCFTools(action_data.m_Player,"",action_data.m_Target.GetObject().GetDisplayName()+GetEnitiyIDFromObject(action_data),"Raiding CodeLock:"+tempHealth+"/"+_Health+" ");
            }else{
                SendToCFTools(action_data.m_Player,"",action_data.m_Target.GetObject().GetDisplayName(),"Raiding CodeLock:"+tempHealth+"/"+_Health+" ");
            }
        }
    }

}
#endif
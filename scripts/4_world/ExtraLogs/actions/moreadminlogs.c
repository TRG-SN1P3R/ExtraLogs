modded class PluginAdminLog extends PluginBase{

override void UnconStart( PlayerBase player){
        super.UnconStart(player);
        if(m_LogConfig.ServerConfig.ShowShock==0) return;
        SendToCFTools(player,"","","is unconscious");
    }

override void UnconStop( PlayerBase player ){	
        super.UnconStop(player);
        if(m_LogConfig.ServerConfig.ShowShock==0) return;
		if ( player.IsAlive() ) 	// Do not log uncon stop for dead players
		{   
            if(m_LogConfig.ServerConfig.LifeTimeFilter>0){
                float life = player.StatGet("playtime");//get lifetime of character
                if(!life) return;
                if(life>=m_LogConfig.ServerConfig.LifeTimeFilter){ //Gates life time at based on value in logs
		            SendToCFTools(player,"","","regained consciousness" );
                }
                return;
            }
            SendToCFTools(player,"","","regained consciousness" );
		}
	}
}

//Log NVGs
modded class ActionToggleNVG: ActionBase{
    override void Start( ActionData action_data ){
		super.Start( action_data ); 

        if (!action_data.m_Player) return;
        if (m_LogConfig.ServerConfig.ShowNVGActions==0) return;
        NVGoggles gogglesTemp;
		Clothing NVmountTemp;
		NVmountTemp = Clothing.Cast(action_data.m_Target.GetObject());
		gogglesTemp = NVGoggles.Cast(NVmountTemp.FindAttachmentBySlotName("NVG"));
        
        if (gogglesTemp.m_IsLowered==false){
            SendToCFTools(action_data.m_Player,"","","turned off NVGs");
        }
        if (gogglesTemp.m_IsLowered==true){
            SendToCFTools(action_data.m_Player,"","","turned on NVGs");
        }
        
    }
}

//log injectors
modded class ActionInjectSelf: ActionSingleUseBase{
    override void OnExecuteServer( ActionData action_data ){
        super.OnExecuteServer(action_data);
        if(!action_data.m_Player) return;
        if(m_LogConfig.ServerConfig.ShowInjectorActions==0) return;
         SendToCFTools(action_data.m_Player,"","","used an "+action_data.m_MainItem.GetType()+" injector");
    }	
}

//log breaking legs
modded class BrokenLegsMdfr: ModifierBase{
    override void OnActivate(PlayerBase player){
        super.OnActivate(player);
        if(!player) return;
        if(m_LogConfig.ServerConfig.ShowBrokenLegs==0) return;
        if(m_LogConfig.ServerConfig.LifeTimeFilter>0){
        float life = player.StatGet("playtime");//get lifetime of character
        if(!life) return;
        if(life>=m_LogConfig.ServerConfig.LifeTimeFilter){  //Gates life time at based on value in logs
        SendToCFTools(player,"","","has broken legs");
            }
            return;
        }
        SendToCFTools(player,"","","has broken legs");
    }
}

//log splints to yourself
modded class ActionSplintSelf: ActionContinuousBase{
    override void OnFinishProgressServer(ActionData action_data){
        super.OnFinishProgressServer(action_data);
        if(!action_data.m_Player) return;
        if(m_LogConfig.ServerConfig.ShowSplintAction==0) return;
        SendToCFTools(action_data.m_Player,"","","applied a Splint");
    }
}
//log splints to others
/*modded class ActionSplintTarget: ActionContinuousBase{
    override void OnFinishProgressServer(ActionData action_data){
        super.OnFinishProgressServer(action_data);
        PlayerBase ntarget = PlayerBase.Cast( action_data.m_Target.GetObject());
        if(!action_data.m_Player || !ntarget)  return;
        SendToCFTools(action_data.m_Player,string.Format("%1",action_data.m_Target.GetObject()),"","applied a Splint to");
    }
}*/

//log stage 1
modded class ContaminationStage1Mdfr: ModifierBase{
    override protected void OnActivate(PlayerBase player){
        super.OnActivate(player);
         if(m_LogConfig.ServerConfig.ShowGasPoison==0) return; //do we want to see this?
        if(!player) return;
        SendToCFTools(player,"","","has Stage 1 Gas Poisoning");
    }
}

//log stage 2
modded class ContaminationStage2Mdfr: ModifierBase{
    override protected void OnActivate(PlayerBase player){
        super.OnActivate(player);
         if(m_LogConfig.ServerConfig.ShowGasPoison==0) return; //do we want to see this?
        if(!player) return;
        SendToCFTools(player,"","","has Stage 2 Gas Poisoning");
    }
}

//log stage 3
modded class ContaminationStage3Mdfr: ModifierBase{
     override protected void OnActivate(PlayerBase player){
        super.OnActivate(player);
         if(m_LogConfig.ServerConfig.ShowGasPoison==0) return; //do we want to see this?
        if(!player) return;
        SendToCFTools(player,"","","has Stage 3 Gas Poisoning");
    }
}

//logs nade actions
modded class ActionPin: ActionSingleUseBase {
	override void OnStartServer(ActionData action_data) {
		super.OnStartServer(action_data);
        if(m_LogConfig.ServerConfig.ShowGrenadeActions==0) return;//do we want to see this?
        SendToCFTools(action_data.m_Player, "hands", action_data.m_MainItem.GetType(), "pinned");
	}
}

//logs nade actions
modded class ActionUnpin: ActionSingleUseBase {
	override void OnStartServer(ActionData action_data) {
		super.OnStartServer(action_data);
        if(m_LogConfig.ServerConfig.ShowGrenadeActions==0) return;//do we want to see this?
        SendToCFTools(action_data.m_Player, "hands", action_data.m_MainItem.GetType(), "unpinned");
	}
}

modded class ActionGiveBloodSelf: ActionContinuousBase{
     override void OnEndServer(ActionData action_data){
        super.OnEndServer(action_data);
        if(m_LogConfig.ServerConfig.ShowUseBloodBag==0) return;
        if(!action_data.m_Player) return;

        SendToCFTools(action_data.m_Player,"","","used a blood bag");
     }
}

modded class ActionGiveBloodTarget: ActionContinuousBase{
     override void OnEndServer(ActionData action_data){
        super.OnEndServer(action_data);
        if(m_LogConfig.ServerConfig.ShowUseBloodBag==0) return;
        if(!action_data.m_Player) return;
        PlayerBase player_target = PlayerBase.Cast(action_data.m_Target.GetObject());
        if(!player_target) return;

        SendToCFTools(action_data.m_Player,"","","gave a blood transfusion");
        SendToCFTools(player_target,"","","had received a blood transfusion");
     }
}

modded class ActionCollectBloodTarget: ActionContinuousBase{
    override void OnEndServer(ActionData action_data){
        super.OnEndServer(action_data);
        if(m_LogConfig.ServerConfig.ShowTakeBloodBag==0) return;
        if(!action_data.m_Player) return;
        PlayerBase player_target = PlayerBase.Cast(action_data.m_Target.GetObject());
        if(!player_target) return;
        SendToCFTools(action_data.m_Player,"","","collected blood");
        SendToCFTools(player_target,"","","had blood taken");
     }
}

modded class ActionCollectBloodSelf: ActionContinuousBase{
    override void OnEndServer(ActionData action_data){
        super.OnEndServer(action_data);
        if(m_LogConfig.ServerConfig.ShowTakeBloodBag==0) return;
        if(!action_data.m_Player) return;
        SendToCFTools(action_data.m_Player,"","","collected their blood");
     }
}

modded class ActionTurnValveUndergroundReservoir{
	
	override void OnFinishProgressServer(ActionData action_data)
	{
		super.OnFinishProgressServer(action_data);
		if(!action_data.m_Player) return;
		SendToCFTools(action_data.m_Player,"","","has interacted with Valve");

	}
}

modded class ActionUseUndergroundPanel: ActionSingleUseBase{
	override void OnStartServer( ActionData action_data )
	{
		//Because the game hates me 
		Land_Underground_Panel target =  Land_Underground_Panel.Cast(action_data.m_Target.GetObject());
		
		if (!target)
			return;
		
		target.Interact();
		PunchedCard.Cast(action_data.m_MainItem).OnUse();
		//WHY!
		
		if(!action_data.m_Player) return;
		SendToCFTools(action_data.m_Player,"","","used Punchcard ");
	}
}

modded class ActionUseUndergroundLever: ActionInteractBase{
	override void OnStartServer( ActionData action_data )
	{
		super.OnStartServer(action_data);
		if(!action_data.m_Player) return;
		SendToCFTools(action_data.m_Player,"","","opened bunker door ");
		
	}
}


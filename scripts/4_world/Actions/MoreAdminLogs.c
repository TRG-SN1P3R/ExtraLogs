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
//Log Epipen usage
modded class EpinephrineMdfr: ModifierBase{
	override void OnActivate(PlayerBase player){
		super.OnActivate(player);
        if(!player) return;
        if(m_LogConfig.ServerConfig.ShowInjectorActions==0) return;
        SendToCFTools(player,"","","used an Epipen");
	}
}
//log breaking legs
modded class BrokenLegsMdfr: ModifierBase{
    override void OnActivate(PlayerBase player){
        super.OnActivate(player);
        if(!player) return;
        if(m_LogConfig.ServerConfig.ShowBrokenLegs==0) return;
        float life = player.StatGet("playtime");//get lifetime of character
        if(!life) return;
        if(life>=180.0){ //Gates life time at 3 minutes so we don't see freshie shit.
        SendToCFTools(player,"","","has broken legs");
        }
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


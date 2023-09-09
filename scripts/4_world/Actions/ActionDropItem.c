modded class ActionDropItem : ActionSingleUseBase{
	
	override void OnExecuteServer(ActionData action_data) {
		super.OnExecuteServer(action_data);
		if(!action_data.m_Player || !action_data.m_Target) return;
		if(m_LogConfig.ServerConfig.ShowDropStorage==0) return;
		string item = action_data.m_MainItem.GetType();

		//Shows only items we care about
		if(item.Contains("SeaChest")){
			SendToCFTools(action_data.m_Player, "","","Dropped "+item);
			return;
		}
		if(item.Contains("WoodenCrate")){
			SendToCFTools(action_data.m_Player, "","","Dropped "+item);
			return;
		}
		if(item.Contains("Barrel_")){
			SendToCFTools(action_data.m_Player, "","","Dropped "+item);
			return;
		}
		if(item.Contains("BarrelHoles_")){
			SendToCFTools(action_data.m_Player, "","","Dropped "+item);
			return;
		}
		if(m_LogConfig.CustomConfig.EnableCustomItems==1){ //Checks for custom items to be logged
            if(LogCustomItems.CustomConfig.CustomItem1!=""&&item.Contains(m_LogConfig.CustomConfig.CustomItem1)){
                 SendToCFTools(action_data.m_Player,"","","Dropped "+item);
                return;
            }
			if(LogCustomItems.CustomConfig.CustomItem2!=""&&item.Contains(m_LogConfig.CustomConfig.CustomItem2)){
                 SendToCFTools(action_data.m_Player,"","","Dropped "+item);
                return;
            }
			if(LogCustomItems.CustomConfig.CustomItem3!=""&&item.Contains(m_LogConfig.CustomConfig.CustomItem3)){
                 SendToCFTools(action_data.m_Player,"","","Dropped "+item);
                return;
            }
			if(LogCustomItems.CustomConfig.CustomItem4!=""&&item.Contains(m_LogConfig.CustomConfig.CustomItem4)){
                 SendToCFTools(action_data.m_Player,"","","Dropped "+item);
                return;
            }
		}
	}
}

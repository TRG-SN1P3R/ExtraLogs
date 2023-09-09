modded class ActionTakeItemToHands: ActionInteractBase{
    override void OnExecuteServer( ActionData action_data ){
        super.OnExecuteServer(action_data);
        if(!action_data.m_Player) return;
        if(m_LogConfig.ServerConfig.ShowTakeStorage==0) return; //Checks if we want to show this
        string item=string.ToString(action_data.m_Target.GetObject()); //Gets Item name

        if(m_LogConfig.ServerConfig.SimpleLogsStorage==0){ //If we want full item details
            if(item.Contains("WoodenCrate")){
                SendToCFTools(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject()),"Grabbed");
                return;
            }
            if(item.Contains("SeaChest")){
                SendToCFTools(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject()),"Grabbed");
                return;
            }
            if(item.Contains("Barrel_")){//Reg. Barrels
                SendToCFTools(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject()),"Grabbed");
                return;
            }
            if(item.Contains("BarrelHoles_")){ //Fire barrels
                SendToCFTools(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject()),"Grabbed");
                return;
            }


            if(m_LogConfig.CustomConfig.EnableCustomItems==1){ //Checks for custom items to be logged
                if(LogCustomItems.CustomConfig.CustomItem1!=""&&item.Contains(m_LogConfig.CustomConfig.CustomItem1)){
                    SendToCFTools(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject()),"Grabbed");
                    return;
                }
                 if(LogCustomItems.CustomConfig.CustomItem2!=""&&item.Contains(m_LogConfig.CustomConfig.CustomItem2)){
                    SendToCFTools(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject()),"Grabbed");
                    return;
                }
                 if(LogCustomItems.CustomConfig.CustomItem3!=""&&item.Contains(m_LogConfig.CustomConfig.CustomItem3)){
                    SendToCFTools(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject()),"Grabbed");
                    return;
                }
                 if(LogCustomItems.CustomConfig.CustomItem4!=""&&item.Contains(m_LogConfig.CustomConfig.CustomItem4)){
                    SendToCFTools(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject()),"Grabbed");
                    return;
                }
            }


        }
        else{ //if we want basic info
            if(item.Contains("WoodenCrate")){
                SendToCFTools(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject().GetType()),"Grabbed");
                return;
            }
            if(item.Contains("SeaChest")){
                SendToCFTools(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject().GetType()),"Grabbed");
                return;
            }
            if(item.Contains("Barrel_Red")){
                SendToCFTools(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject().GetType()),"Grabbed");
                return;
            if(item.Contains("BarrelHoles_Green")){
                SendToCFTools(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject().GetType()),"Grabbed");
                return;
            }


            if(m_LogConfig.CustomConfig.EnableCustomItems==1){ //Checks for custom items to be logged
                if(LogCustomItems.CustomConfig.CustomItem1!=""&&item.Contains(m_LogConfig.CustomConfig.CustomItem1)){
                    SendToCFTools(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject().GetType()),"Grabbed");
                    return;
                }
                 if(LogCustomItems.CustomConfig.CustomItem2!=""&&item.Contains(m_LogConfig.CustomConfig.CustomItem2)){
                    SendToCFTools(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject().GetType()),"Grabbed");
                    return;
                }
                 if(LogCustomItems.CustomConfig.CustomItem3!=""&&item.Contains(m_LogConfig.CustomConfig.CustomItem3)){
                    SendToCFTools(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject().GetType()),"Grabbed");
                    return;
                }
                 if(LogCustomItems.CustomConfig.CustomItem4!=""&&item.Contains(m_LogConfig.CustomConfig.CustomItem4)){
                    SendToCFTools(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject().GetType()),"Grabbed");
                    return;
                }
            }


        }
    }
}
#ifdef EXTRALOGSPARAGON

    modded class ActionOpenCloseSC{
        override void OnStartServer( ActionData action_data )
	    {   
            super.OnStartServer(action_data);
            if(m_LogConfig.Paragon.ShowPargonStorageLogs==0) return;
            if(!action_data.m_Player || !action_data.m_Target) return;
            string State;
            ItemBase building = ItemBase.Cast(action_data.m_Target.GetObject());
            if(building.IsOpen())
                State = "closed ";
            else
                State = "opened ";

            if(m_LogConfig.Paragon.SimpleLogs==1){ //Show only name
                SendToCFTools(action_data.m_Player, "", action_data.m_Target.GetObject().GetType(), State);
            else
                SendToCFTools(action_data.m_Player, "", string.Format("%1", action_data.m_Target.GetObject()), State);
	        }
        }
    }

    modded class ActionFurnitureClose{

        override void OnStartServer( ActionData action_data )
	    {
            super.OnStartServer(action_data);
            if(m_LogConfig.Paragon.ShowPargonStorageLogs==0) return;
            if(!action_data.m_Player || !action_data.m_Target) return;
            ItemBase building = ItemBase.Cast(action_data.m_Target.GetObject());
            if(building){
                if(m_LogConfig.Paragon.SimpleLogs==1){ //Show only name
                    SendToCFTools(action_data.m_Player, "", action_data.m_Target.GetObject().GetType(), "closed ");
                else
                    SendToCFTools(action_data.m_Player, "", string.Format("%1", action_data.m_Target.GetObject()), "closed ");   
                }  
            }
	    }
    }

    modded class ActionFurnitureOpen{
        override void OnStartServer( ActionData action_data )
	    {
            super.OnStartServer(action_data);
            if(m_LogConfig.Paragon.ShowPargonStorageLogs==0) return;
            if(!action_data.m_Player || !action_data.m_Target) return;
            ItemBase building = ItemBase.Cast(action_data.m_Target.GetObject());
            if(building){
                if(m_LogConfig.Paragon.SimpleLogs==1){ //Show only name
                    SendToCFTools(action_data.m_Player, "", action_data.m_Target.GetObject().GetType(), "opened ");
                else
                    SendToCFTools(action_data.m_Player, "", string.Format("%1", action_data.m_Target.GetObject()), "opened ");   
                }  
            }
	    }
    }



#endif
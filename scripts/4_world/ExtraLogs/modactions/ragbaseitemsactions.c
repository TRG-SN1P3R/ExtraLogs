#ifdef RAG_BASEITEMS

    modded class ActionOpenCloseRaGBaseItem
    {
        override void OnEndServer( ActionData action_data )
        {
            super.OnEndServer(action_data);
            if(m_LogConfig.RagMod.ShowRagBaseItemLogs==0) return; //Skip we don't want logs of this
            if(!action_data.m_Player || !action_data.m_Target) return; // Check for player and item
            ItemBase RagObject = ItemBase.Cast(action_data.m_Target.GetObject());
            if(!RagObject) return; // Skip if we didn't cast
            string tempState="";
            if(RagObject.IsOpen()){ //Decode state of object
                tempState = "closed";
            }else{
                tempState = "opened";
            }
            if(m_LogConfig.ServerConfig.SimpleLogsStorage==0){
                SendToCFTools(action_data.m_Player, "hands", action_data.m_Target.GetObject().GetType()+GetEnitiyIDFromObject(action_data), tempState);
            }else{
                SendToCFTools(action_data.m_Player, "hands", action_data.m_Target.GetObject().GetType(), tempState);
            }
        }
    }

    modded class ActionOpenRaGBaseItem
    {
        override void OnEndServer( ActionData action_data )
        {
            super.OnEndServer(action_data);
            if(m_LogConfig.RagMod.ShowRagBaseItemLogs==0) return; //Skip we don't want logs of this
            if(!action_data.m_Player || !action_data.m_Target) return; // Check for player and item
            if(m_LogConfig.ServerConfig.SimpleLogsStorage==0){
                SendToCFTools(action_data.m_Player, "hands", action_data.m_Target.GetObject().GetType()+GetEnitiyIDFromObject(action_data), "opened");
            }else{
                SendToCFTools(action_data.m_Player, "hands", action_data.m_Target.GetObject().GetType(), "opened");
            }
        }
    }

    modded class ActionCloseRaGBaseItem
    {
        override void OnEndServer( ActionData action_data )
        {
            super.OnEndServer(action_data);
            if(m_LogConfig.RagMod.ShowRagBaseItemLogs==0) return; //Skip we don't want logs of this
            if(!action_data.m_Player || !action_data.m_Target) return; // Check for player and item
            if(m_LogConfig.ServerConfig.SimpleLogsStorage==0){
                SendToCFTools(action_data.m_Player, "hands", action_data.m_Target.GetObject().GetType()+GetEnitiyIDFromObject(action_data), "closed");
            }else{
                SendToCFTools(action_data.m_Player, "hands", action_data.m_Target.GetObject().GetType(), "closed");
            }
        }

    }




#endif
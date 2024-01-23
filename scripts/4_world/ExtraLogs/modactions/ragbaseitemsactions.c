#ifdef RAG_BASEITEMS

    modded class ActionOpenCloseRaGBaseItem
    {
        override void OnEndServer( ActionData action_data )
        {
            super.OnEndServer(action_data);
            if(m_LogConfig.RagMod.ShowRagBaseItemLogs==0) return; //Skip we don't want logs of this
            if(!action_data.m_Player || !action_data.m_Target) return; // Check for player and item
            ItemBase RagObject = ItemBase.Cast(target.GetObject());
            if(!RagObject) return; // Skip if we didn't cast
            string objectState;
            if(RagObject.IsOpen()){ //Decode state of object
                objectState = "closed"
            }else{
                objectState = "opened"
            }
            if(m_LogConfig.RagMod.SimpleLogs==0){
                SendToGameLabs(action_data.m_Player, "hands", action_data.m_Target.GetObject(), objectState);
            }else{
                SendToGameLabs(action_data.m_Player, "hands", action_data.m_Target.GetObject().GetType(), objectState);
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
            if(m_LogConfig.RagMod.SimpleLogs==0){
                SendToGameLabs(action_data.m_Player, "hands", action_data.m_Target.GetObject(), "opened");
            }else{
                SendToGameLabs(action_data.m_Player, "hands", action_data.m_Target.GetObject().GetType(), "opened");
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
            if(m_LogConfig.RagMod.SimpleLogs==0){
                SendToGameLabs(action_data.m_Player, "hands", action_data.m_Target.GetObject(), "closed");
            }else{
                SendToGameLabs(action_data.m_Player, "hands", action_data.m_Target.GetObject().GetType(), "closed");
            }
        }

    }




#endif
#ifdef EXTRALOGSRAGBB
modded class ActionDeployObject
{
    override void OnFinishProgressServer( ActionData action_data )
	{
        super.OnFinishProgressServer(action_data);
        Print("Super!");
        Print(action_data.m_MainItem);
        Print(action_data.m_MainItem.IsKindOf("RaG_BB_BaseKit"));
        if (action_data.m_MainItem && action_data.m_MainItem.IsKindOf("RaG_BB_BaseKit") )
        Print("Check item type");
        {
            Print("Item is base kit");
            if (!action_data.m_Player) return;
            Print("player found");
            SendToCFTools(action_data.m_Player, "", action_data.m_MainItem.GetType(), "placed ");
        }
        Print("Item isnt a base kit");
    }
}

#endif
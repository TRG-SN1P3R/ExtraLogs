static string GetEnitiyIDFromObject(ActionData action_data){
    if(!action_data.m_Target) return "";
        string temp = string.Format("%1",action_data.m_Target.GetObject());
        int pos1 = temp.IndexOf("<");
        string ID = temp.Substring(pos1,10);
    return ID;
}

static string GetPersistentIDFromObject(ActionData action_data) {
    if(!action_data.m_Target) return ""; //Return if we have no target
    int b1,b2,b3,b4;
	EntityAI entity = EntityAI.Cast(action_data.m_Target.GetObject());
	if(!entity) return ""; //return if we didn't cast
    entity.GetPersistentID(b1,b2,b3,b4);
    if(!b1||!b2||!b3||!b4) return ""; //return if not set
    string temp1,temp2,temp3,temp4;
    temp1=string.Format("%x%1",temp1);
    string ID = string.Format("<%1%2%3%4>",temp1,b2,b3,b4);
    return ID;
}
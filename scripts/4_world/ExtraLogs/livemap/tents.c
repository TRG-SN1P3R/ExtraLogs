modded class TentBase
{
    protected bool m_DoorOpen;
    protected bool m_DoorStateChange;

    ref _Event _registeredInstance;
    
    private void _InitGameLabs() { //create the map icon and track this item

            foreach(string CheckItem: m_LogConfig.LiveMap.TentEnableList){ //Run through String Array to compare to tent object type to array entries. 
                if(this.GetType()==CheckItem)
                {
                    switch(this.GetType())
                    {
                        case "PartyTent":
                        {
                        if(m_LogConfig.LiveMap.ShowTents==0) return;
                        this._registeredInstance = new _Event(string.Format("%1",this.GetType()), "warehouse", this);
                        GetGameLabs().RegisterEvent(this._registeredInstance);
                        }
                        break;
                        
                        case "MediumTent":
                        {
                        if(m_LogConfig.LiveMap.ShowTents==0) return;
                        this._registeredInstance = new _Event(string.Format("%1",this.GetType()), "warehouse", this);
                        GetGameLabs().RegisterEvent(this._registeredInstance);
                        }
                        break;

                        case "LargeTent":
                        {
                        if(m_LogConfig.LiveMap.ShowTents==0) return;
                        this._registeredInstance = new _Event(string.Format("%1",this.GetType()), "warehouse", this);
                        GetGameLabs().RegisterEvent(this._registeredInstance);
                        }
                        break;

                        case "CarTent":
                        {
                        if(m_LogConfig.LiveMap.ShowTents==0) return;
                        this._registeredInstance = new _Event(string.Format("%1",this.GetType()), "garage-car", this);
                        GetGameLabs().RegisterEvent(this._registeredInstance);
                        }
                        break;

                        case "ShelterStick":
                        {
                        if(m_LogConfig.LiveMap.ShowTents==0) return;
                        this._registeredInstance = new _Event(string.Format("%1",this.GetType()), "campground", this);
                        GetGameLabs().RegisterEvent(this._registeredInstance);
                        }
                        break;

                        case "ShelterFabric":
                        {
                        if(m_LogConfig.LiveMap.ShowTents==0) return;
                        this._registeredInstance = new _Event(string.Format("%1",this.GetType()), "campground", this);
                        GetGameLabs().RegisterEvent(this._registeredInstance);
                        }
                        break;

                        case "ShelterLeather":
                        {
                        if(m_LogConfig.LiveMap.ShowTents==0) return;
                        this._registeredInstance = new _Event(string.Format("%1",this.GetType()), "campground", this);
                        GetGameLabs().RegisterEvent(this._registeredInstance);
                        }
                        break;

                        default:
                        {
                        if(m_LogConfig.LiveMap.ShowTents==0) return;
                        this._registeredInstance = new _Event(string.Format("%1",this.GetType()), "warehouse", this);
                        GetGameLabs().RegisterEvent(this._registeredInstance);
                        }
                        break;
                    }
                    break; //WE FOUND A MATCH! 
                }
            }
        }

    void ~TentBase() { //remove icon when removed
        if(GetGameLabs().IsServer()) {
                if(this._registeredInstance) GetGameLabs().RemoveEvent(this._registeredInstance);
        }
    }

    override void Pitch(bool update_navmesh, bool init = false)
	{
        super.Pitch(update_navmesh,init);
        if(m_LogConfig.LiveMap.ShowTents==1 && GetGameLabs().IsServer()){ //Checks to see if we want to see this and its pitched
                GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(this._InitGameLabs);
        }

    }

    override void Pack(bool update_navmesh, bool init = false)
	{
        super.Pack(update_navmesh,init);
        if(m_LogConfig.LiveMap.ShowTents==1 && GetGameLabs().IsServer()) { //removes icon on packing
            if(this._registeredInstance) {
                GetGameLabs().RemoveEvent(this._registeredInstance);
            }
            
        }
    }

    bool GetDoorState()
    {
        return m_DoorOpen;
    }
    bool DidDoorStateChange() 
    {
        return m_DoorStateChange;
    }
    void ResetDoorStateChange()
    {
        m_DoorStateChange=false;
    }

    override void ToggleAnimation(string selection)
	{
		if (m_State == PACKED)
		{
			return;
		}
		
		bool is_closed;
		
		for (int i = 0; i < m_ToggleAnimations.Count(); i++)
		{
			ToggleAnimations toggle = m_ToggleAnimations.GetKey(i);
			
			string toggle_off = toggle.GetToggleOff();
			toggle_off.ToLower();
			string toggle_on = toggle.GetToggleOn();
			toggle_on.ToLower();
			
			if (toggle_off == selection || toggle_on == selection)
			{
				is_closed = m_OpeningMask & toggle.GetOpeningBit();
				if (is_closed)
				{
					if (selection.Contains("entrance") || selection.Contains("door"))
					{
                        m_DoorOpen = true;
                        m_DoorStateChange=true;
					}
				}
				else
				{
					if (selection.Contains("entrance") || selection.Contains("door"))
					{
                        m_DoorOpen = false;
                        m_DoorStateChange=true;
					}
				}
			}
		}
        super.ToggleAnimation(selection);
	}
    


     // Public API
    _Event _GetEventInstance() {
        return this._registeredInstance;
    }

    void _SetEventInstance(_Event _registeredInstance) {
        this._registeredInstance = _registeredInstance;
    }

};

modded class ShelterBase
{
    void Deconstruct()
	{
        super.Deconstruct();
        if(m_LogConfig.LiveMap.ShowTents==1 && GetGameLabs().IsServer()) { //removes icon on packing
            if(this._registeredInstance) {
                GetGameLabs().RemoveEvent(this._registeredInstance);
            }
        }

    }
};
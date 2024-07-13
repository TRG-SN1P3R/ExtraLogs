modded class TentBase
{
    protected bool m_DoorOpen;
    protected bool m_DoorStateChange;

    void TentBase() { //when the tent is created
            if(m_State == PITCHED){ //Checks to see if we want to see this and its pitched
                GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(this._InitGameLabs);
            }
        }
    
    
    ref _Event _registeredInstance;
    
    private void _InitGameLabs() { //create the map icon and track this item
            switch(string.Format("%1",this.GetType()))
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
                if(m_LogConfig.LiveMap.ShowShelters==0) return;
                this._registeredInstance = new _Event(string.Format("%1",this.GetType()), "campground", this);
                GetGameLabs().RegisterEvent(this._registeredInstance);
                }
                break;

                case "ShelterLeather":
                {
                if(m_LogConfig.LiveMap.ShowShelters==0) return;
                this._registeredInstance = new _Event(string.Format("%1",this.GetType()), "campground", this);
                GetGameLabs().RegisterEvent(this._registeredInstance);
                }
                break;

                default:
                {
                if(m_LogConfig.LiveMap.ShowShelters==0) return;
                this._registeredInstance = new _Event(string.Format("%1",this.GetType()), "warehouse", this);
                GetGameLabs().RegisterEvent(this._registeredInstance);
                }
                break;

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
		ResetToggle();
		
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
					SetAnimationPhase(toggle.GetToggleOff(), 0);
					AddProxyPhysics(toggle.GetToggleOff());
					SetAnimationPhase(toggle.GetToggleOn(), 1);
					RemoveProxyPhysics(toggle.GetToggleOn());
					m_ToggleAnimations.Set(toggle, false);
					m_IsToggle = true;
					m_OpeningMask &= ~toggle.GetOpeningBit();
					
					if (selection.Contains("window"))
					{
						ManipulateWindow();
					}
					
					if (selection.Contains("entrance") || selection.Contains("door"))
					{
						ManipulateEntrance();
                        m_DoorOpen = true;
                        m_DoorStateChange=true;
					}
					
					AnimateCamonetToggle(toggle);
				}
				else
				{
					SetAnimationPhase(toggle.GetToggleOff(), 1);
					RemoveProxyPhysics(toggle.GetToggleOff());
					SetAnimationPhase(toggle.GetToggleOn(), 0);
					AddProxyPhysics(toggle.GetToggleOn());
					m_ToggleAnimations.Set(toggle, true);
					m_IsToggle = false;
					m_OpeningMask |= toggle.GetOpeningBit();
					
					if (selection.Contains("window"))
					{
						ManipulateWindow();
					}
					
					if (selection.Contains("entrance") || selection.Contains("door"))
					{
						ManipulateEntrance();
                        m_DoorOpen = false;
                        m_DoorStateChange=true;
					}
					
					AnimateCamonetToggle(toggle);
				}
			}
		}
		SetSynchDirty();
		SoundSynchRemote();
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
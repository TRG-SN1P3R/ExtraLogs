/*modded class ShelterStick extends ShelterBase {
      ref _Event _registeredInstance;
    void ShelterStick() {
         GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(this._InitGameLabs);
    }
    
    private void _InitGameLabs() {
        this._registeredInstance = new _Event("Stash", "treasure-chest", this);

        if(GetGameLabs()) {
            if(GetGameLabs().IsServer()) {
                GetGameLabs().RegisterEvent(this._registeredInstance);
            }
        }
    }

    void ~ShelterStick() {
        if(GetGameLabs()) {
            if(GetGameLabs().IsServer()) {
                if(this._registeredInstance) GetGameLabs().RemoveEvent(this._registeredInstance);
            }
        }
    }

    // Public API
    _Event _GetEventInstance() {
        return this._registeredInstance;
    }

    void _SetEventInstance(_Event _registeredInstance) {
        this._registeredInstance = _registeredInstance;
    }
};
*/
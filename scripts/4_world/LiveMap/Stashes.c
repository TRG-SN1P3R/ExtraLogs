modded class UndergroundStash extends ItemBase {

    if(m_LogConfig.MapConfig.ShowStashs==1){ //Checks to see if we want to see this
        void UndergroundStash() { //when the stash is created
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(this._InitGameLabs);
        }
        ref _Event _registeredInstance;
        private void _InitGameLabs() { //create the map icon and track this item
            this._registeredInstance = new _Event("Stash", "treasure-chest", this);

            if(GetGameLabs()) {
                if(GetGameLabs().IsServer()) {
                    GetGameLabs().RegisterEvent(this._registeredInstance);
                }
            }
        }

        void ~UndergroundStash() {
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
    }
}
/*modded class Tweaks_Crystal_Skull_Red {
        private ref _Vehicle _registeredInstance = new _Vehicle(this);
        void Tweaks_Crystal_Skull_Red() { //when the stash is created
              GetGameLabs().RegisterVehicle(this._registeredInstance);   
        }
        
        void ~Tweaks_Crystal_Skull_Red() {
            if(GetGameLabs().IsServer()) {
            if(this._registeredInstance) GetGameLabs().RemoveVehicle(this._registeredInstance);
            }
        }
}*/


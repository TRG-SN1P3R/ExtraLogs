class CfgPatches
{
	class ExtraLogs
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={
			"DZ_Data",
			"GameLabs_Scripts"
		};
	};
};

class CfgMods
{
	class HH_CFTools
	{
		dir="ExtraLogs";
		name="ExtraLogs";
		author="@TRG_SN1P3R";
		version="0.9;
		extra=0;
		type="mod";
		dependencies[]={"Game", "World", "Mission"};
		class defs {
			class gameScriptModule {
				value="";
				files[]={"ExtraLogs/Scripts/3_Game"};
			};
			class worldScriptModule {
				value="";
				files[]={"ExtraLogs/Scripts/4_World"};
			};
			class missionScriptModule {
				value="";
				files[]={"ExtraLogs/Scripts/5_Mission"};
			};
		};
	};
};
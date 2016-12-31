class CfgPatches
{
	class DSR_Code
	{
		requiredVersion = 1;
		requiredAddons[] = {"A3_Data_F"};
		units[] = {};
		weapons[] = {};
		magazines[] = {};
		ammo[] = {};
		version = 1;
	};
};
class CfgFunctions
{
	class DS 
	{
		class FSMs 
		{
			file = "\DSR_Code\fsm";
			class initStatusSys 
			{
				ext = ".fsm";
			};
		};
	};
};
class CfgDifficultyPresets {
	class Recruit {
		class Options {
			weaponCrosshair = 0;
			reducedDamage = 0;
			visionAid  = 0;
			groupIndicators = 0;
			friendlyTags = 0;
			deathMessages = 0;
		};
	};
	class Regular {
		class Options {
			weaponCrosshair = 0;
			reducedDamage = 0;
			visionAid  = 0;
			groupIndicators = 0;
			friendlyTags = 0;
			deathMessages = 0;
		};
	};
	class Veteran {
		class Options {
			weaponCrosshair = 0;
			visionAid  = 0;
			reducedDamage = 0;
			groupIndicators = 0;
			friendlyTags = 0;
			deathMessages = 0;
		};
	};
	class DesoHardcore {
		displayName = "Desolation Redux: Hardcore Mode";
		levelAI = "AILevelHigh";
		description = "Desolation `haaaard` coore!";
		optionDescription = "The hardest difficulty there is.";
		optionPicture = "\A3\Ui_f\data\Logos\arma3_white_ca.paa";
		class Options {
			reducedDamage = 0;
			groupIndicators = 0; 
			friendlyTags = 0;
			enemyTags = 0;
			detectedMines = 0;
			commands = 0;
			waypoints = 0;
			weaponInfo = 0;
			stanceIndicator = 0;
			staminaBar = 0;
			weaponCrosshair = 0;
			visionAid = 0;
			thirdPersonView = 0;
			cameraShake = 1;
			scoreTable = 0;
			deathMessages = 0;
			vonID = 1;
			mapContent = 0;
			autoReport = 0;
			multipleSaves = 0;
		};
	};
};
//--- end todo

class CfgMusic {
	class MAD {
		duration = 198;
	};
	class Defcon {
		duration = 193;
	};
	class SkyNet {
		duration = 234;
	};
	class Wasteland {
		duration = 195;
	};
	class track1
	{
		name = "";
		sound[] = {"\dsr_ui\Sounds\track1.ogg", 1, 1.0};
	};
	class track2
	{
		name = "";
		sound[] = {"\dsr_ui\Sounds\track2.ogg", 1, 1.0};
	};
	class track2_redefined
	{
		name = "";
		sound[] = {"\dsr_ui\Sounds\track2_redefined.ogg", 1, 1.0};
	};
};

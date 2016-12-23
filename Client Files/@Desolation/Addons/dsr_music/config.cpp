class CfgPatches
{
	class dsr_music
	{
		fileName = "dsr_music.pbo";
		requiredAddons[] = {};
		requiredVersion = 0.1;
		units[] = {};
		weapons[] = {};
		vehicles[] = {};
		author[]= {"Desolation Redux Dev Team"};
	};
};
class CfgMusic
{
	tracks[]={};

	class DropTheLoad
	{
		name = "";
		sound[] = {"\dsr_music\Airdrop\Drop_The_Load.ogg", db+0, 1.0};
	};
};
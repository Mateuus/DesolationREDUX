class CfgPatches
{
	class EasyMode {};
};

class Plugins
{
	class EasyMode
	{
		name = "Spooky Weather";
		desc = "Increases server fog & creates a spooky environment";
		tag = "Em";
	};
};

class CfgFunctions
{
	class EM
	{
		class Client 
		{
			file = "EasyMode\Client";
			isclient = 1;
			class initClient {};
		};
	};
};
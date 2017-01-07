class CfgPatches
{
	class TanoaMapDesign {};
};
class Plugins
{
	class TanoaMapDesign
	{
		name = "Tanoa Map Design";
		desc = "Makes the tanoa map look survival-like";
		tag = "TMD";
	};
}
class CfgFunctions
{
	class TMD
	{
		class Server 
		{
			file = "TanoaMapDesign\Server";
			isserver = 1;
			class initServer {};
		};
	};
};
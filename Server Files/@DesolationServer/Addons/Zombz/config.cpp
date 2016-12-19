class CfgPatches
{
	class Zombz {};
};
class Plugins
{
	class Zombz
	{
		name = "SM Zombz";
		desc = "Desolation Zombie Plugin";
		tag = "SM";
	};
};
class CfgFunctions
{
	class SM
	{
		class Client {
			file = "Zombz\Client";
			isclient = 1;
			class initClient {};
		};
		class Server {
			file = "Zombz\Server";
			isserver = 1;
			class initServer {};
		};
	};
};
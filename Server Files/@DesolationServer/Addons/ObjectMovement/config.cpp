class CfgPatches
{
	class ObjectMovement {};
};

class Plugins
{
	class ObjectMovement
	{
		name = "Object Movement";
		desc = "JMaster's Object Movement System - Recoded By Lysdick";
		tag = "OM";
	};
};
class CfgFunctions
{
	class OM
	{
		class Client 
		{
			file = "ObjectMovement\Client";
			isclient = 1;
			class initClient {};
		};
		class Client_Movement
		{
			file = "ObjectMovement\Client\Movement";
			isclient = 1;
			class canLift {};
			class dropObject {};
			class liftObject {};
		};
		class Server
		{
			file = "ObjectMovement\Server";
			isserver = 1;
			class serverLift {};
			class serverDrop {};
		};
	};
};

class CfgPatches
{
	class ObjectMovement {};
};

class Plugins
{
	class ObjectMovement
	{
		name = "Object Movement";
		desc = "IDK WOoooooooOooOoOOOo";
		tag = "OM";
	};
};

class CfgPluginKeybinds {
	class ObjectMovement {
		displayName = "Lift Object";
		tooltip = "Lifts the object you are looking at.";
		tag = "OM";
		variable = "LiftObject";
		defaultKeys[] = {{0x16,0}};
		code = "systemchat 'yeet';";
	};
};

class CfgFunctions
{
	class OM
	{
		class Client 
		{
			file = "ObjectMovement\Client";
			
			class initClient {};
			class boundingBoxCheck {};
			class lockObject {};
			class moveObject {};
			class objectLoading {};
			class objectLocking {};
			class objectMovement {};
			class unlockObject {};
			
		};
		class Server
		{
			file = "ObjectMovement\Server";
			isserver = 1;
			class initServer {};
			class requestMove {};
			class stopMove {};
		};
	};
};

class CfgObjectMovement {
	class CfgVehicleBlacklist {
		class EXAMPLE_CLASSNAME {};
		
	};
	class CfgObjectBlacklist {
		class EXAMPLE_CLASSNAME {};
		
	};
};

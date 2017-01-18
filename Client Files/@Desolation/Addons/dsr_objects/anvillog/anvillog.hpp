 class dsr_objects_anvil_log: DSR_objects_base {
	editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
	displayName = "Anvil & Log";
	model = "dsr_objects\anvillog\dsr_anvil_log.p3d";
	icon = "iconObject";
	faction = "Empty";
	editorSubcategory = "DSR_Objects";
	scope = 2;
	scopeCurator = 2;
	mass = 150;
 };
 class dsr_objects_anvil_log_preview: DSR_Crate_Base
{
	editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
	scope = 2;
	scopeCurator = 2;
	displayName = "Anvil and Log Preview";
	model = "\dsr_objects\anvillog\dsr_anvil_log_preview.p3d";
	icon = "iconObject_4x1";
	editorSubcategory = "DSR_Objects";
	maximumLoad = 5000;
	hiddenSelections[] = {"camo1"}; ///we want to allow changing the color of this selection
	hiddenSelectionsTextures[]=
	{
		"#(argb,2,2,1)color(0.7,0.93,0,0.6)"
	};
};
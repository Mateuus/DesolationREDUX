class DSR_objects_Workbench_crate: DSR_Crate_Base
{
	scope = 2;
	scopeCurator = 2;
	displayName = "Workbench";
	maximumLoad = 600;
	model = "\dsr_objects\workbench\dsr_workbench.p3d";
	editorSubcategory = "DSR_Objects";
};
class dsr_objects_workbench_preview: DSR_Crate_Base
{
	editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
	scope = 2;
	scopeCurator = 2;
	displayName = "Workbench Preview";
	model = "\dsr_objects\workbench\dsr_workbench_preview.p3d";
	icon = "iconObject_4x1";
	editorSubcategory = "DSR_Objects";
	maximumLoad = 5000;
	hiddenSelections[] = {"camo1"}; ///we want to allow changing the color of this selection
	hiddenSelectionsTextures[]=
	{
		"#(argb,2,2,1)color(0.7,0.93,0,0.6)"
	};
};
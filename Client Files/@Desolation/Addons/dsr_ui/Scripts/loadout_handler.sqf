

_type = _this;

switch(_type) do {
	case 0: {
		//--- hat switch
		_hats = ["H_StrawHat","H_Hat_blue","H_Hat_checker","H_Cap_tan","H_Cap_blk","H_Cap_blk_CMMG","H_Cap_brn_SPECOPS","H_Cap_tan_specops_US","H_Cap_khaki_specops_UK","H_Cap_grn","H_Cap_grn_BI","H_Cap_blk_Raven","H_Cap_oli_hs","H_Cap_press","H_Bandanna_khk","H_Bandanna_khk_hs"];
		_u = headgear player;
		_index = _hats find _u;
		_index = _index + 1;
		if(_index == count(_hats)) then {
			_index = 0;
		};
		removeHeadgear player;
		_newUNI = (_hats select _index);
		player addHeadgear _newUNI;
		profileNamespace setVariable ["DS_Default_Headgear",_newUNI];
	};
	case 1: {
		//--- goggles switch
		_goggles = ["G_Aviator","G_Shades_Black","G_Shades_Blue","G_Sport_Blackred","G_Tactical_Clear","G_Spectacles","G_Spectacles_Tinted","G_Shades_Green","G_Shades_Red","G_Squares","G_Squares_Tinted","G_Sport_BlackWhite","G_Sport_Blackyellow","G_Sport_Greenblack","G_Sport_Checkered","G_Sport_Red"];
		_u = goggles player;
		_index = _goggles find _u;
		_index = _index + 1;
		if(_index == count(_goggles)) then {
			_index = 0;
		};
		removeGoggles player;
		_newUNI = (_goggles select _index);
		player addGoggles _newUNI;
		profileNamespace setVariable ["DS_Default_Goggles",_newUNI];
	};
	case 2: {
		//--- uniform switch
		_uniforms = ["U_C_DSR_Tester","U_C_Poor_2","U_C_Poloshirt_blue","U_C_Poloshirt_burgundy","U_C_Poloshirt_stripped","U_C_Poloshirt_tricolour","U_C_Poloshirt_salmon","U_C_Poloshirt_redwhite","U_C_Commoner1_1","U_NikosBody","U_OrestesBody"];
		
		_u = uniform player;
		_index = _uniforms find _u;
		_index = _index + 1;
		if(_index == count(_uniforms)) then {
			_index = 0;
		};
		removeUniform player;
		_newUNI = (_uniforms select _index);
		player addUniform _newUNI;
		profileNamespace setVariable ["DS_Default_Uniform",_newUNI];
	};
	saveProfileNamespace;
	uiNamespace setVariable ["DS_LOADOUTDATA",[uniform player,headgear player,goggles player]];
};
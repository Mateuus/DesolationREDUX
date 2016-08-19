if (isnil "Ryanzombiesattackspeed") then {Ryanzombiesattackspeed = 0.8};
if (isnil "Ryanzombiesattackdistance") then {Ryanzombiesattackdistance = 2.35};
if (isnil "Ryanzombiesattackstrenth") then {Ryanzombiesattackstrenth = 1.5};
if (isnil "Ryanzombiesdamage") then {Ryanzombiesdamage = 0.15};
if (isnil "Ryanzombiesdamagecar") then {Ryanzombiesdamagecar = 0.02};
if (isnil "Ryanzombiesdamageair") then {Ryanzombiesdamageair = 0.01};
if (isnil "Ryanzombiesdamagetank") then {Ryanzombiesdamagetank = 0.002};
if (isnil "Ryanzombiesdamagecarstrenth") then {Ryanzombiesdamagecarstrenth = 1.5};
if (isnil "Ryanzombiesdamageairstrenth") then {Ryanzombiesdamageairstrenth = 1};
if (isnil "Ryanzombiesdamagetankstrenth") then {Ryanzombiesdamagetankstrenth = 0.4};
if (isnil "Ryanzombiesdamagecaliberneeded") then {Ryanzombiesdamagecaliberneeded = 2.3;};

if (isnil "Ryanzombiesfncs") then
{
	Ryanzombiesfncs = 1;

	fnc_RyanZombies_SwitchMove = compileFinal "_this select 0 switchmove (_this select 1)";
	fnc_RyanZombies_PlayMoveNow = compileFinal "_this select 0 playmovenow (_this select 1)";
	fnc_RyanZombies_DoMoveLocalized = compileFinal "_this select 0 domove (_this select 1)";
	fnc_RyanZombies_Bleeding = compileFinal "_this select 0 setBleedingRemaining (_this select 1)";
	fnc_RyanZombies_Velocity = compileFinal "if(local (_this select 0)) then {_this select 0 setvelocity (_this select 1)}";
	fnc_RyanZombies_SetHitIndex = compileFinal "if(local (_this select 0)) then {_this select 0 setHitIndex (_this select 1)}";
	fnc_RyanZombies_execVM = compileFinal "(_this select 0) execVM (_this select 1)";
	fnc_RyanZombies_AddCamShake = compileFinal "if(local (_this select 1)) then {AddCamShake (_this select 0)};";
	fnc_RyanZombies_RemoveGroups = compileFinal "{if (count units _x == 0) then {deletegroup _x}} foreach allgroups;";

	
	RZ_ServerSided_AttackScriptsInfantry =
	{
		private _target = _this select 0;
		private _group = _this select 1;
		
		if (isClass(configFile >> "CfgPatches" >> "ace_medical")) then {[_target,'manNormal'] execVM "\ryanzombies\acedamage.sqf"} else {_target setdamage (damage _target + Ryanzombiesdamageplayer)};
		if (!(alive _target) && !(isnil "Ryanzombiesinfection")) then {[_target, side _group] execVM "\ryanzombies\infection.sqf"};
		if ((alive _target) && !(isnil "ryanzombiesinfectedchance") && (_target getvariable ["ryanzombiesinfected",0] == 0)) then {[_target, side _group] execVM "\ryanzombies\infected.sqf"};
	};		
	
	RZ_ServerSided_AttackScriptsVehicle =
	{
		private _crew = _this select 0;
		private _group = _this select 1;
		
		{
			_target = _x;
			if (isClass(configFile >> "CfgPatches" >> "ace_medical")) then {[_target,'vehNormal'] execVM "\ryanzombies\acedamage.sqf"} else {_target setdamage (damage _target + Ryanzombiesdamageplayer)};
			if (!(alive _target) && !(isnil "Ryanzombiesinfection")) then {[_target, side _group] execVM "\ryanzombies\infection.sqf"};
			if ((alive _target) && !(isnil "ryanzombiesinfectedchance") && (_target getvariable ["ryanzombiesinfected",0] == 0)) then {[_target, side _group] execVM "\ryanzombies\infected.sqf"};
		} foreach _crew;
		
	};	
	
	RZ_fnc_ZombieKilled = 
	{
		params ["_victim","_sel","_damage","_shooter","_projectile"];

		if(_sel == "head" && _damage >= 1) then 
		{
			if(face _victim != "RyanZombieNoFace") then 
			{
				_caliber = getNumber (configFile >> "CfgAmmo" >> _projectile >> "caliber");
				if(_caliber >= Ryanzombiesdamagecaliberneeded) then 
				{
					_victim setFace "RyanZombieNoFace";
					_victim remoteExecCall ["RZ_fnc_HeadParticles"];
					[_victim, "RyanZombieNoFace"] remoteExecCall ["setFace"];
					
					removeHeadgear _victim;
					removeGoggles _victim;
					
					_hmd = (hmd _victim);
					_victim unassignItem _hmd;
					_victim removeItem _hmd;
					
					_HeadExplodeArray = ["ryanzombies\sounds\HeadExplode1.ogg", "ryanzombies\sounds\HeadExplode2.ogg", "ryanzombies\sounds\HeadExplode3.ogg"];
					_HeadExplode = selectRandom _HeadExplodeArray;
					playsound3d [format ["%1",_HeadExplode], _victim,false, getPosASL _victim, 10, 1, 30];
				};
			};
		};	
	};	
		
	RZ_fnc_HeadParticles =
	{
		_object = _this;

		_pArray = [];

		for "_i" from 0 to 2 do
		{

			_meat = "#particlesource" createVehicleLocal (getposATL _object); 
			_meat setParticleClass "HeadMeat1"; 
			_meat setParticleParams
			[
				["\A3\data_f\ParticleEffects\Universal\Meat_ca", 1, 0, 1], //shape name
				"", //animation name
				"SpaceObject", //type
				1, 5, //timer period & life time
			   [0, 0, 0], //position
			   [0.2,0.2,2], //moveVelocity
			   2, 22, 1, 0.2, //rotation velocity, weight, volume, rubbing
			   [4], //size
			   [[0.9,0.01,0.01,1]], //color
			   [0.1], //animationPhase (animation speed in config)
			   0.00, //randomdirection period
			   0.0, //random direction intensity
				"", //onTimer
				"", //before destroy
				"", //object
				0, //angle
				false, //on surface
				0.0 //bounce on surface
			];

			_meat setParticleRandom [0, [0.1, 0.1, 0.0], [1.35, 1.35, 1.0], 0, 0.1, [0, 0, 0, 0], 0, 0];
			_meat setDropInterval 60;
			_meat attachTo [_object,[0,0,0.2],"head"]; 

			_pArray pushBack _meat;

		};

		_blood = "#particlesource" createVehicleLocal (getposATL _object); 
		_blood setParticleClass "HeadBlood1"; 

		_blood setParticleParams
		[
			["\A3\data_f\ParticleEffects\Universal\Universal_02", 8, 4, 1], //shape name
			"", //animation name
			"Billboard", //type
			1, 0.3, //timer period & life time
		   [0, 0, 0], //position
		   [0.00,0.0,2], //moveVelocity
		   1, 0.127, 0.1, 0.4, //rotation velocity, weight, volume, rubbing
		   [0.5,1], //size
		   [[1,0,0,0.9],[1,0,0,0.45]],
		   [0.1], //animationPhase (animation speed in config)
		   0.0, //randomdirection period
		   0.0, //random direction intensity
			"", //onTimer
			"", //before destroy
			"", //object
			0, //angle
			false, //on surface
			0.0 //bounce on surface
		];

		_blood setDropInterval 60;
		_blood attachTo [_object,[0,0,0.],"head"]; 

		_pArray pushback _blood;

		_pArray spawn 
		{
			_pArray = _this;
			sleep 5;
			{ deleteVehicle _x } foreach _pArray;
		};
	};
		

    RZ_inventory_DblClick = 
	{
		// Unscheduled environment, executed by eventhandler
    	_idc = ctrlIDC (_this select 0);

    	_selectedIndex = _this select 1;
		_itemName = lbText [_idc, _selectedIndex];

		switch (_itemName) do 
		{
			case "Antivirus Injector": 
			{
			
				playsound3d ["ryanzombies\sounds\antivirus_inject.ogg", player]; 
				player spawn 
				{
					player removeItem "RyanZombiesAntiVirusCure_Item";
					sleep 0.75; 
					player setVariable ["ryanzombiesinfected",0,true];
				};
			};	
			case "Antivirus Pills": 
			{
				playsound3d ["ryanzombies\sounds\antivirus_pills.ogg", player];
				player spawn
				{
					player removeItem "RyanZombiesAntiVirusTemporary_Item";
					sleep 0.75;
					waituntil {!(player getvariable ["ryanzombiesimmunity",false])};
					player setVariable ["ryanzombiesimmunity",true,true];
					sleep ryanzombiesantivirusduration;
					player setVariable ["ryanzombiesimmunity",false,true];
				};
			
			};
		};	
		
    	false

    };	
	
};
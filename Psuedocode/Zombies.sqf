/*
NOTES: 
	CONTROLLER == Server OR HC 
	CONTROLLER spawns zombies & handles their virtualized unagroed movement
> Player checks near zombies (100m) for possible agro 
> If Player triggers an agro on one of the zombies near him
	> player requests CONTROLLER transfers ownership to player
	> CONTROLLER triggers that zombie agro brain on player
		> When player agro brain says DEAGRO
			> Player sends ownership back to CONTROLLER
			
			
			
	If you are bleeding and a cover yourself in blood you get sick (with gloves and other protective clothing you can mitigate / avoid this)
	If you are bleeding and run over a dead zombie you have a % chance of becoming sick (with gloves and other protective clothing you can mitigate / avoid this)
	
*/			
//Server
DS_FSM_MasterBrain = { //--- this will eventually be an FSM
	//TODO handle zombie movement
	
	// get all locations
	// split 500 / locations throw extra zombie on random one
	// seperate groups per locations
	// ai for traveling around locations
	// Horde? 
	
};
DS_FSM_MasterVirtualizer = { //--- this will eventually be an FSM
	params["_zombieClass"];

	while{true} do {
		_toLock = [];
		_toLockNIDS = [];
		_toUnlock = [];
		_toUnlockNIDS = [];
		
		{
			_inLockRange = (getposatl _x) nearEntities [_zombieClass,800];
			_inUnlockRange = (getposatl _x) nearEntities [_zombieClass,500];
			_inAgroRange = (getposatl _x) nearEntities [_zombieClass,100];
			
			_x setVariable ["POSSIBLE_AGRO",_inAgroRange,true]; //--- store what zombies can agro the player
			
			_inLockRange = _inLockRange - _inUnlockRange;
			
			{
				_nid = netid _x;
				_i = _toLockNIDS find _nid;
				if(_i != -1) then {
					_toLock deleteAt _i;
					_toLockNIDS deleteAt _i;
				};
				if !(_nid in _toUnlockNIDS) then {
					_toUnlockNIDS pushBack _nid;
					_toUnlock pushBack _x;
				};
			} forEach _inUnlockRange;
			{
				_nid = netid _x;
				if !(_nid in _toUnlockNIDS) then {
					_toLock pushBack _x;
					_toLockNIDS pushBack _nid;
				};
			} forEach _inLockRange;
		} forEach allPlayers;
		
		{
			if (simulationEnabled _x && local _x) then {
				_x hideObjectGlobal true;
				_x disableAI "ALL";
				_x enableAI "MOVE";	
				_x enableAI "PATH";	
			};
		} forEach _tolock;
		{
			if !(simulationEnabled _x && local _x) then {
				_x hideObjectGlobal false;
				_x enableAI "ALL";
			};
		} forEach _tounlock;
		uiSleep 1;
	};
};
DS_fnc_TransferRequest = {
	params["_zombies","_player"];
	{
		_x setOwner (owner _player);
	} forEach _zombies;
	[_zombies] remoteExec["DS_fnc_TransferBrain",_player];
};
DS_fnc_ReturnRequest = {
	params["_zombie"];
	_zombie setOwner 0;
};

//--- CLIENT	
DS_fnc_CheckAgro = {
	params["_agroDistance"];
	_nearzombies = player getVariable ["POSSIBLE_AGRO",[]];
	_agros = [];
	{
		_distance = player distance _x;
		if(_distance <= _agroDistance) then {
			_agros pushBack _x;
		};
	} forEach _nearzombies;
	[_agros,player] remoteExec ["DS_fnc_TransferRequest",CONTROLLER];
};
DS_fnc_TransferBrain = {
	params["_zombies"];
	{
		_x spawn DS_FSM_StartZombieBrain;
	} forEach _zombies;
};
DS_FSM_StartZombieBrain = { //--- This will eventually be an fsm
	params["_zombie"];
	
	_group = createGroup civilian;
	[_zombie] joinSilent _group;
	
	_lastKnown = getPosATL player;
	while{true} do {
		
		
		_position = _lastKnown;
		_distance = _zombie distance player;
		_zombie move _position;
		
		_tDist = _distance / 1.5;
		
		waitUntil { ||  ||  || };
		
		if(_zombie distance player > 100) exitWith {}; //--- out of max Agro distance
		if(!alive player) exitWith {}; //--- player died
		
		if((player distance _zombie) < 2) then {
			
		};
		
		//--- Checks for deagro
		
		uiSleep 0.5;
	};
	
};
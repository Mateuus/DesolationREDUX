 
if (isnil "Ryanzombiesjumpplayer") exitwith {};

if((time - (player getVariable ["ryanlastzombiepounce",0])) > 0.05) then 
{	
	if(stance player == "STAND" || stance player == "CROUCH") then 
	{
		player spawn 
		{
			_debug = false;
			if(_debug) then 
			{
				systemchat "execute";
			};

			if(isTouchingGround player) then 
			{
				if ((isnil "ryanzombiesdisablejumping") && ((time - (player getVariable ["ryanlastzombiepouncesound",0])) > 1.0)) then
				{
					_JumpArray = ["ryanzombies\sounds\jump1.ogg", "ryanzombies\sounds\jump2.ogg", "ryanzombies\sounds\jump3.ogg", "ryanzombies\sounds\jump4.ogg", "ryanzombies\sounds\jump5.ogg", "ryanzombies\sounds\jump6.ogg"];
					_Jump = selectRandom _JumpArray;
					playsound3d [format ["%1",_Jump], player];
					player setVariable ["ryanlastzombiepouncesound",time];
				};

				_basespeed = 7.5;  
				_runspeed = ((speed player) min 25) * 0.20;  
				_baseheight = 10;

				if(_debug) then 
				{
					systemchat "ground touching";
					systemchat format ["run speed: %1",_runspeed];
				};
			
			
				_pos1 = positionCameraToWorld [0,0,0];
				_pos2 = positionCameraToWorld [0,0,1];
				_x1 = _pos1 distance2d _pos2;
				_y1 = (_pos2 select 2)-(_pos1 select 2);
				_angle = _y1 atan2 _x1;


				_heightmultiplier = linearConversion [-75, 62, _angle, 0, 2, true] max 0.5;
				_speedmultiplier = 1 / _heightmultiplier;

				if(_debug) then 
				{
					systemchat format ["height multiplier: %1, angle: %2",_heightmultiplier, _angle];
					systemchat format ["combined speed: %1, speed multiplier: %2",((_basespeed + _runspeed) * _speedmultiplier), _speedmultiplier];
				};

				_dir = getdir player;
				if (isnil "Ryanzombiesjumpstrengthplayer") then
				{
					player setvelocity [((_basespeed + _runspeed) * _speedmultiplier) * (sin _dir), ((_basespeed + _runspeed) * _speedmultiplier) * (cos _dir), (_baseheight * _heightmultiplier)];
				} else
				{
					if (Ryanzombiesjumpstrengthplayer == 1) exitwith {player setvelocity [(((_basespeed + _runspeed) * _speedmultiplier) * (sin _dir))/1.33, (((_basespeed + _runspeed) * _speedmultiplier) * (cos _dir))/1.33, (_baseheight * _heightmultiplier)/1.33];};
					if (Ryanzombiesjumpstrengthplayer == 2) exitwith {player setvelocity [(((_basespeed + _runspeed) * _speedmultiplier) * (sin _dir))/1.66, (((_basespeed + _runspeed) * _speedmultiplier) * (cos _dir))/1.66, (_baseheight * _heightmultiplier)/1.66];};
					if (Ryanzombiesjumpstrengthplayer == 3) exitwith {player setvelocity [(((_basespeed + _runspeed) * _speedmultiplier) * (sin _dir))/2, (((_basespeed + _runspeed) * _speedmultiplier) * (cos _dir))/2, (_baseheight * _heightmultiplier)/2];};
					if (Ryanzombiesjumpstrengthplayer == 4) exitwith {player setvelocity [(((_basespeed + _runspeed) * _speedmultiplier) * (sin _dir))*4, (((_basespeed + _runspeed) * _speedmultiplier) * (cos _dir))*4, (_baseheight * _heightmultiplier)*4];};
				};
				sleep 0.5; 
				waituntil {isTouchingGround player}; 
				sleep 0.1;
				if(_debug) then 
				{
					systemchat format ["disable:%1",time];
				};

			} else {

				if(!(player getVariable ["WallHanging",false])) then 
				{

					if(_debug) then 
					{
						systemchat "jumping";
					};
					_surfaceArray = (lineIntersectsSurfaces  [eyePos player, ATLtoASL screenToWorld [0.5,0.5], player, objNull, true]) select 0;


					if(!isNil "_surfaceArray") then 
					{
						_surfaceObj = _surfaceArray select 2;
						if(!isNull _surfaceObj) then 
						{
							_surface = _surfaceArray select 0;
							
							if(_debug) then 
							{
								if(isNil "yoursphere") then 
								{
									yoursphere = "Sign_Sphere10cm_F" createVehicle [0,0,0];
								};
								yoursphere setposASL _surface;
							};

							_distance = (getposasl player) distance _surface;

							if(_distance < 1.8) then 
							{

								if(isNil "yourblock") then 
								{
									yourblock = "invisibleblock1m" createVehicleLocal [getPosATL player select 0, getPosATL player select 1,((getposATL player select 2) - 0.45)];  //invisibleblock1m Land_VR_Shape_01_cube_1m_F
									yourblock setdamage 0;
									yourblock allowdamage false;
								};
								
								yourblock setdamage 0;
								yourblock allowdamage false;
								yourblock setposATL [getPosATL player select 0, getPosATL player select 1,((getposATL player select 2) - 0.45)];
								
								if(_debug) then 
								{
									systemChat "block created";
								};

								player setVariable ["WallHanging",true];


								waituntil {(getposasl player) distance _surface > 1.8};
								player setVariable ["WallHanging",false];



								if(_debug) then {
									yoursphere setposatl [0,0,0];
									systemchat "block deleted";
								};
								yourblock setposatl [0,0,0];
							};

						};
					};
				};
			};
			player setVariable ["ryanlastzombiepounce",time];				
		};
	};
};	
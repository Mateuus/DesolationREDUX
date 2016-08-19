_sleepingObject = cursorObject;
_player = player;
[_player] remoteExec ["DS_fnc_dbSendStatsUpdate", 2];
_player attachTo [_sleepingObject,[0,0,0]];
_runLoop = true;
while{_runLoop}do{
	//health increase while it loops every 10 seconds
	//rested stat for players?
	for "_i" from 0 to 30 do{
		_count = _i * 10;
		if(_count isEqualTo 300)then{
			_runLoop=false;
		};
	};
	sleep 10;
};
{
	detach _x;
}forEach attachedObjects _player;
[_player] remoteExec ["DS_fnc_dbSendStatsUpdate", 2];
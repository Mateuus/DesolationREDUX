/*
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/
params["_unit","_selection"];
private["_bleedsourcedata","_sources","_bsourcesinfo","_i","_GLOBAL_BLEEDDATA","_select"];

_bleedsourcedata = _unit getVariable ["DS_var_BleedSourceData",[]];
_sources = _unit getVariable ["DS_var_BleedSources",[]];
_bsourcesinfo = _unit getVariable["DS_var_BleedSourcesInfo",[]];

_i = _sources find _selection;
if(_i != -1) then {
	deleteVehicle ((_bleedSourceData select _i) select 0);
	deleteVehicle ((_bleedSourceData select _i) select 1);
	
	if(_unit == player) then {
		//--- remove my global bleed data (for new connected clients to use on JIP)
		_GLOBAL_BLEEDDATA = player getVariable ["BLEED_SOURCES",[]];
		{
			_select = _x select 0;
			if(_select == _selection) exitWith {
				_GLOBAL_BLEEDDATA deleteAt _forEachIndex;
				player setVariable ["BLEED_SOURCES",_GLOBAL_BLEEDDATA,true];
			};
		} foreach _GLOBAL_BLEEDDATA;
	};
	
	//--- remove everything from our lists that relates to this bleedsource
	_bleedsourcedata deleteAt _i;
	_sources deleteAt _i;
	_bsourcesinfo deleteAt _i;
	
	_unit setVariable ["DS_var_BleedSourceData",_bleedsourcedata];
	_unit setVariable ["DS_var_BleedSources",_sources];
	_unit setVariable ["DS_var_BleedSourcesInfo",_bsourcesinfo];
};
private["_params","_response"];

_params = [1];
{
	_params pushback _x;
} forEach _this;

_response = _params call DB_fnc_buildRequest;
_response;
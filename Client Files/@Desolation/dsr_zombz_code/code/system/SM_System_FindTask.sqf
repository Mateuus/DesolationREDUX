/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

// Not me.
private["_haystack","_needle","_result","_i","_q"];
_haystack = _this select 0;
_needle = _this select 1;
_result = -1;
try
{
	for "_i" from 0 to ((count _haystack) -1) do 
	{
		_q = (_haystack select _i) find _needle;
		if (_q != -1) then
		{
			throw _i;
		};
	};
}
catch 
{
	_result = _exception;
};

_result

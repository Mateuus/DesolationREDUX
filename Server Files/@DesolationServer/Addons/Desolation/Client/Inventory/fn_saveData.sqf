/*
	fn_setupInvEvents

	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/
DS_var_NextSave = diag_tickTime + 60*5;
systemchat "Saving data...";
[player] remoteExec ["DS_fnc_requestSave",2];
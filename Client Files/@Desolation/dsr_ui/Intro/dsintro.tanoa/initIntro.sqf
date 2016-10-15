diag_log "Starting intro";
0 fadeMusic 0;

_music = ["MAD","SkyNet","Wasteland","Track01_Proteus","Defcon"];
addMusicEventHandler ["MusicStop",'0 fadeMusic 0;playMusic (' + str(_music) + ' select floor(random(5))); 5 fadeMusic 1;'];
playMusic (_music select floor(random(5)));
5 fadeMusic 1;
cutText ["", "BLACK IN", 5]; 
setViewDistance 200;
showCinemaBorder false;
_newCam = "camera" camCreate [0,0,0];
_newCam setPosATL [11073.2,8471.56,1.62917];	
_newCam camSetDir ([11073.5,8471.18,1.62917] vectorFromTo [11072.1,8474.48,1.62917]);
_newCam cameraEffect ["INTERNAL", "BACK"];
_newCam camCommit 0;


removeHeadgear player;
removeUniform player;
removeGoggles player;

//--- get their custom set loadout, if none is set then load the default one (strawhat,aviators,begger uniform)
player addHeadgear (profileNamespace getVariable ["DS_Default_Headgear","H_StrawHat"]);
player addUniform (profileNamespace getVariable ["DS_Default_Uniform","U_C_Poor_2"]);
player addGoggles (profileNamespace getVariable ["DS_Default_Goggles","G_Aviator"]);

uiNamespace setVariable ["DS_LOADOUTDATA",[uniform player,headgear player,goggles player]];

diag_log "intro started";
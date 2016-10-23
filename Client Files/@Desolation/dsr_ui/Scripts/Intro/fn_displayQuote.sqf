scriptName "fn_displayQuote";
/*--------------------------------------------------------------------
	Author: Maverick (ofpectag: MAV)
    File: fn_displayQuote.sqf

	<Maverick Applications>
    Written by Maverick Applications (www.maverick-apps.de)
    You're not allowed to use this file without permission from the author!
--------------------------------------------------------------------*/
#define __filename "fn_displayQuote.sqf"

disableSerialization;

_quotes = [
	["Temper us in fire, and we grow stronger. When we suffer, we survive.", "Cassandra Clare, City of Heavenly Fire"],
	["Sometimes even to live is an act of courage.", "Seneca"],
	["If you don't hunt it down and kill it, it will hunt you down and kill you.", "Flannery O'Connor"],
	["The strong survive, but the courageous triumph.", "Michael Scott, The Warlock"],
	["Tough times don't last, tough people do, remember?", "Gregory Peck"],
	["The thing about hearts is that they always want to keep beating.", "Elizabeth Scott, Living Dead Girl"],
	["A scar does not form on the dying. A scar means, I survived.", "Chris Cleave"],
	["To wander is to be alive.", "Roman Payne"],
	["Don't play his game. Play yours.", "Rachel Caine, Fall of Night "]
];

_quoteData = selectRandom _quotes;

5001 cutRsc ["quoteTemplate","PLAIN"];
_quoteDisplay = uiNamespace getVariable ["quoteTemplate", displayNull];

(_quoteDisplay displayCtrl 0) ctrlSetStructuredText parseText format ["<t size='2.7' align='center' shadow='2'>%1%2%1</t>", '"', _quoteData select 0];
(_quoteDisplay displayCtrl 1) ctrlSetStructuredText parseText format ["<t size='2' align='center' shadow='2'>– %1</t>", _quoteData select 1];
/*
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

params["_objectID","_objectName","_messages"];
_object = objectFromNetID _objectID;
_object setName _objectName;
{
	_object commandChat _x;
} forEach _messages;
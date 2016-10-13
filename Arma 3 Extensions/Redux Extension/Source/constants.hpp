/* constants.hpp
 *
 * Copyright 2016-2017 Desolation Redux
 *
 * Author: Legodev <legodevgit@mailbox.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef SOURCE_CONSTANTS_HPP_
#define SOURCE_CONSTANTS_HPP_

/*
 * Magic Numbers
 */
#define MAXCHARS_FOR_PROTOCOL_OVERHEAD 128
#define STATIC_MULTIPART_MESSAGE_PROTOCOL_OVERHEAD 49
#define DEFAULT_THREAD_COUNT boost::thread::hardware_concurrency()
#define ASYNC_MAGIC 0
#define SYNC_MAGIC 1
#define HANDLELESS_MAGIC 2

/*
 * Magic Strings for the Arma 3 Call Extension API
 */
// Libary Datatypes
#define PROTOCOL_IDENTIFIER_NAME "msguuid"
#define PROTOCOL_IDENTIFIER_DATATYPE std::string
#define PROTOCOL_IDENTIFIER_GENERATOR orderedUUID()

// Libary Functions
#define PROTOCOL_LIBARY_FUNCTION_EXECUTE_INIT_DB "initdb"
#define PROTOCOL_LIBARY_FUNCTION_EXECUTE_DB_CALL "dbcall"
#define PROTOCOL_LIBARY_FUNCTION_RECEIVE_MESSAGE "rcvmsg"
#define PROTOCOL_LIBARY_FUNCTION_CHECK_MESSAGE_STATE "chkmsg"

// Database Call Functions
#define PROTOCOL_DBCALL_FUNCTION_RETURN_UUID "getUUID"
#define PROTOCOL_DBCALL_FUNCTION_RETURN_ECHO_STRING "echo"
#define PROTOCOL_DBCALL_FUNCTION_RETURN_DB_VERSION "dbVersion"
#define PROTOCOL_DBCALL_FUNCTION_DEBUG_CALL "dbgCall"
#define PROTOCOL_DBCALL_FUNCTION_RETURN_ASYNC_MSG "rcvasmsg"
#define PROTOCOL_DBCALL_FUNCTION_RETURN_ASYNC_SATE "chkasmsg"

#define PROTOCOL_DBCALL_FUNCTION_LOAD_PLAYER "loadPlayer"
#define PROTOCOL_DBCALL_FUNCTION_AV_CHARS "loadAvChars"
#define PROTOCOL_DBCALL_FUNCTION_LINK_CHARS "linkChars"
#define PROTOCOL_DBCALL_FUNCTION_LOAD_CHAR "loadChar"
#define PROTOCOL_DBCALL_FUNCTION_CREATE_CHAR "createChar"
#define PROTOCOL_DBCALL_FUNCTION_UPDATE_CHAR "updateChar"
#define PROTOCOL_DBCALL_FUNCTION_LOCATIONUPDATE_CHAR "locupdateChar"

#define PROTOCOL_DBCALL_FUNCTION_LOAD_OBJECT "loadObject"
#define PROTOCOL_DBCALL_FUNCTION_CREATE_OBJECT "createObject"
#define PROTOCOL_DBCALL_FUNCTION_UPDATE_OBJECT "updateObject"
#define PROTOCOL_DBCALL_FUNCTION_DUMP_OBJECTS "dumpObjects"

// Database Call Arguments
#define PROTOCOL_DBCALL_ARGUMENT_ACCESSCODE "accesscode"
#define PROTOCOL_DBCALL_ARGUMENT_ANIMATIONSTATE "animationstate"
#define PROTOCOL_DBCALL_ARGUMENT_BACKPACK "backpack"
#define PROTOCOL_DBCALL_ARGUMENT_BACKPACKS "backpacks"
#define PROTOCOL_DBCALL_ARGUMENT_CHARUUID "charuuid"
#define PROTOCOL_DBCALL_ARGUMENT_CLASSNAME "classname"
#define PROTOCOL_DBCALL_ARGUMENT_CURRENTWEAPON "currentweapon"
#define PROTOCOL_DBCALL_ARGUMENT_DAMAGE "damage"
#define PROTOCOL_DBCALL_ARGUMENT_DIRECTION "direction"
#define PROTOCOL_DBCALL_ARGUMENT_FUELCARGO "fuelcargo"
#define PROTOCOL_DBCALL_ARGUMENT_FUEL "fuel"
#define PROTOCOL_DBCALL_ARGUMENT_GOOGLES "googles"
#define PROTOCOL_DBCALL_ARGUMENT_HANDGUN "handgun"
#define PROTOCOL_DBCALL_ARGUMENT_HEADGEAR "headgear"
#define PROTOCOL_DBCALL_ARGUMENT_HITPOINTS "hitpoints"
#define PROTOCOL_DBCALL_ARGUMENT_INVENTORYBACKPACK "inventorybackpack"
#define PROTOCOL_DBCALL_ARGUMENT_INVENTORYUNIFORM "inventoryuniform"
#define PROTOCOL_DBCALL_ARGUMENT_INVENTORYVEST "inventoryvest"
#define PROTOCOL_DBCALL_ARGUMENT_ITEMS "items"
#define PROTOCOL_DBCALL_ARGUMENT_LOCKED "locked"
#define PROTOCOL_DBCALL_ARGUMENT_MAGAZINES "magazines"
#define PROTOCOL_DBCALL_ARGUMENT_MAGAZINESTURRET "magazinesturret"
#define PROTOCOL_DBCALL_ARGUMENT_NICKNAME "nickname"
#define PROTOCOL_DBCALL_ARGUMENT_OBJECTUUID "objectuuid"
#define PROTOCOL_DBCALL_ARGUMENT_PERSISTENTVARIABLES "persistentvariables"
#define PROTOCOL_DBCALL_ARGUMENT_PLAYER_UUID "playeruuid"
#define PROTOCOL_DBCALL_ARGUMENT_POSITIONTYPE "positiontype"
#define PROTOCOL_DBCALL_ARGUMENT_POSITIONX "positionx"
#define PROTOCOL_DBCALL_ARGUMENT_POSITIONY "positiony"
#define PROTOCOL_DBCALL_ARGUMENT_POSITIONZ "positionz"
#define PROTOCOL_DBCALL_ARGUMENT_PRIMARYWEAPON "primaryweapon"
#define PROTOCOL_DBCALL_ARGUMENT_PRIORITY "priority"
#define PROTOCOL_DBCALL_ARGUMENT_REPAIRCARGO "repaircargo"
#define PROTOCOL_DBCALL_ARGUMENT_SECONDARYWEAPON "secondaryweapon"
#define PROTOCOL_DBCALL_ARGUMENT_STEAMID "steamid"
#define PROTOCOL_DBCALL_ARGUMENT_TEXTURES "textures"
#define PROTOCOL_DBCALL_ARGUMENT_TOOLS "tools"
#define PROTOCOL_DBCALL_ARGUMENT_UNIFORM "uniform"
#define PROTOCOL_DBCALL_ARGUMENT_VARIABLES "variables"
#define PROTOCOL_DBCALL_ARGUMENT_VARIABUUID "variabuuid"
#define PROTOCOL_DBCALL_ARGUMENT_VEST "vest"
#define PROTOCOL_DBCALL_ARGUMENT_VISIBLE "visible"
#define PROTOCOL_DBCALL_ARGUMENT_WEAPONS "weapons"
#define PROTOCOL_DBCALL_ARGUMENT_WORLDUUID "worlduuid"

// Message Types
#define PROTOCOL_MESSAGE_TYPE_ERROR "ERROR"
#define PROTOCOL_MESSAGE_TYPE_MESSAGE "MSG"
#define PROTOCOL_MESSAGE_TYPE_MULTIPART "MPMSG"
#define PROTOCOL_MESSAGE_TYPE_NOT_READY "RSN"
#define PROTOCOL_MESSAGE_TYPE_ASYNC "ASYNC"

// Complete Messages
#define PROTOCOL_MESSAGE_EXISTING "MESSAGE DOES EXIST"
#define PROTOCOL_MESSAGE_NOT_EXISTING "MESSAGE DOES NOT EXIST"
#define PROTOCOL_MESSAGE_EMPTY "EMPTY MESSAGE DOES EXIST"
#define PROTOCOL_MESSAGE_TRANSMIT_FINISHED_MSG "DONE GETTING CONTENT"

#endif /* SOURCE_CONSTANTS_HPP_ */

#ifndef SOURCE_CONSTANTS_HPP_
#define SOURCE_CONSTANTS_HPP_

/*
 * Magic Numbers
 */
#define MAXCHARS_FOR_PROTOCOL_OVERHEAD 128
#define STATIC_MULTIPART_MESSAGE_PROTOCOL_OVERHEAD 49
#define DEFAULT_THREAD_COUNT boost::thread::hardware_concurrency()

/*
 * Magic Strings for the Arma 3 Call Extension API
 */
// Libary Datatypes
#define PROTOCOL_IDENTIFIER_DATATYPE std::string
#define PROTOCOL_IDENTIFIER_GENERATOR orderedUUID()

// Libary Functions
#define PROTOCOL_LIBARY_FUNCTION_EXECUTE_DB_CALL "dbcall"
#define PROTOCOL_LIBARY_FUNCTION_RECEIVE_MESSAGE "rcvmsg"
#define PROTOCOL_LIBARY_FUNCTION_CHECK_MESSAGE_STATE "chkmsg"

// Database Call Functions
#define PROTOCOL_DBCALL_FUNCTION_RETURN_UUID "getUUID"
#define PROTOCOL_DBCALL_FUNCTION_RETURN_ECHO_STRING "echo"

// Message Types
#define PROTOCOL_MESSAGE_TYPE_ERROR std::string("ERROR")
#define PROTOCOL_MESSAGE_TYPE_MESSAGE std::string("MSG")
#define PROTOCOL_MESSAGE_TYPE_MULTIPART std::string("MPMSG")
#define PROTOCOL_MESSAGE_TYPE_NOT_READY std::string("RSN")

// Complete Messages
#define PROTOCOL_MESSAGE_EXISTING "MESSAGE DOES EXIST"
#define PROTOCOL_MESSAGE_NOT_EXISTING "MESSAGE DOES NOT EXIST"
#define PROTOCOL_MESSAGE_EMPTY "EMPTY MESSAGE DOES EXIST"
#define PROTOCOL_MESSAGE_TRANSMIT_FINISHED_MSG "DONE GETTING CONTENT"



#endif /* SOURCE_CONSTANTS_HPP_ */

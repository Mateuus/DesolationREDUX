#include "uuid.hpp"

#ifdef __linux__
#include <uuid/uuid.h>

std::string generateUUID() {
	uuid_t id;
	uuid_generate_time(id);

	char uuidstring[37];
	uuid_unparse(id, uuidstring);

	return uuidstring;
}
#else
#include <Rpc.h>
#pragma comment(lib, "Rpcrt4.lib")

std::string generateUUID() {
	UUID uuid;
	UuidCreateSequential( &uuid );

	WCHAR* wszUuid = NULL;

	UuidToStringW(&uuid, &wszUuid);

	std::string uuidstring = wszUuid;

	RpcStringFree(&wszUuid);
	wszUuid = NULL;

	return uuidstring;
}

#endif

std::string orderedUUID() {
	std::stringstream orderedUUID;
	std::string UUID = generateUUID();
	orderedUUID << UUID.substr(14, 4) << UUID.substr(9, 4) << UUID.substr(0, 8)
			<< UUID.substr(19, 4) << UUID.substr(24);
	return orderedUUID.str();
}

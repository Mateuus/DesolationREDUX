#include <exception>
#include <stdexcept>
#include <boost/format.hpp>
#include "database/mysql.hpp"

db_handler::db_handler() {
	this->hostname = "";
	this->user = "";
	this->password = "";
	this->database = "";
	this->port = 0;
	this->socket = "";
	this->flag = 0;
	this->worlduuid = "";

	connection = mysql_init(NULL);

	if (connection == NULL) {
		throw std::runtime_error("problem while initializing db_handler: " + std::string(mysql_error(connection)));
	}
}

db_handler::~db_handler() {
	mysql_close(connection);
	return;
}

void db_handler::connect(std::string hostname, std::string user,
		std::string password, std::string database, unsigned int port, std::string worlduuid) {
	this->hostname = hostname;
	this->user = user;
	this->password = password;
	this->database = database;
	this->port = port;
//	this->socket = NULL;
//	this->flag = 0;
	this->worlduuid = worlduuid;

	if (mysql_real_connect(connection, this->hostname.c_str(),
			this->user.c_str(), this->password.c_str(), this->database.c_str(),
			this->port, this->socket.c_str(), this->flag) == NULL) {
		throw std::runtime_error(
				"connection problem while initializing db_handler: "
						+ std::string(mysql_error(connection)));
		mysql_close(connection);
	} else {
		printf("created connection \n");
	}

	return;
}

void db_handler::rawquery(std::string query, MYSQL_RES **result) {
	if (mysql_real_query(connection, query.c_str(), query.size())) {
		throw std::runtime_error(
				"error while executing query: "
						+ std::string(mysql_error(connection)));
	}

	*result = mysql_store_result(connection);

	if (*result == NULL) {
		throw std::runtime_error(
				"error while getting the result: "
						+ std::string(mysql_error(connection)));
	}

	return;
}

std::string db_handler::querydbversion() {
	MYSQL_RES *result;
	MYSQL_ROW row;
	std::string version;

	this->rawquery("SELECT VERSION()", &result);

	row = mysql_fetch_row(result);
	//fieldcount = mysql_num_fields(*result);
	version = row[0];

	mysql_free_result(result);

	return version;
}

std::vector< std::vector<std::string> > db_handler::verbosetest(std::string query) {
	MYSQL_RES *result;
	MYSQL_ROW row;
	MYSQL_FIELD *field;
	unsigned int fieldcount;
	unsigned long long int rowcount;
	std::string version;

	//this->rawquery("SELECT HEX(uuid) FROM `world` WHERE uuid = CAST(0x11e66ac83e75277882c510bf48883ace AS BINARY)", &result);
	this->rawquery(query, &result);

	fieldcount = mysql_num_fields(result);
	rowcount = mysql_num_rows(result);

	printf("fieldcount = %d\n", fieldcount);
	printf("rowcount = %d\n", rowcount);

	std::vector< std::vector<std::string> > resultmatrix (rowcount, std::vector<std::string>(fieldcount));

	while(field = mysql_fetch_field(result))
	{
		printf("%s; ", field->name);
	}
	printf("\n");

	for (int rowpos = 0; rowpos < rowcount; rowpos++) {
		row = mysql_fetch_row(result);
		for (int fieldpos = 0; fieldpos < fieldcount; fieldpos++) {
			if (row[fieldpos] != NULL) {
			  resultmatrix[rowpos][fieldpos] = row[fieldpos];
			} else {
				resultmatrix[rowpos][fieldpos] = "";
			}

			printf("%s; ", row[fieldpos]);
		}
		printf("\n");
	}

	mysql_free_result(result);

	return resultmatrix;
}

std::vector< std::vector<std::string> > db_handler::dumpObjects() {
	MYSQL_RES *result;
	MYSQL_ROW row;
	unsigned int fieldcount;
	unsigned long long int rowcount;
	std::string query =
	str(boost::format{"SELECT HEX(`object`.`uuid`), HEX(`world_has_objects`.`parentobject_uuid`), \
		       `object`.`classname`, `object`.`priority`, \
		       `object`.`visible`, `object`.`accesscode`, `object`.`locked`, \
		       HEX(`object`.`player_uuid`), `object`.`hitpoints`, `object`.`damage`, \
		       `object`.`fuel`, `object`.`fuelcargo`, `object`.`repaircargo`, \
		       `object`.`items`, `object`.`magazines`, `object`.`weapons`, \
		       `object`.`backpacks`, `object`.`magazinesturret`, `object`.`variables`, \
		       `object`.`animationstate`, `object`.`textures`, `object`.`direction`, \
		       `object`.`positiontype`, `object`.`positionx`, `object`.`positiony`, \
		       `object`.`positionz`, GROUP_CONCAT(`player`.`steamid` SEPARATOR '\", \"') AS friendlist \
		  FROM `world_has_objects` \
		  INNER JOIN `object` \
		    ON `world_has_objects`.`object_uuid` = `object`.`uuid` \
		  LEFT JOIN `player_is_friend_with_player` \
		    ON `object`.`player_uuid` = `player_is_friend_with_player`.`player1_uuid` \
		  LEFT JOIN `player` \
		    ON `player_is_friend_with_player`.`player2_uuid` = `player`.`uuid` \
		  WHERE `world_has_objects`.`world_uuid` = CAST(0x%s AS BINARY) \
		  GROUP BY `object`.`uuid` \
		  ORDER BY `object`.priority ASC, `world_has_objects`.`parentobject_uuid` ASC"} % worlduuid);

	char typearray[] = {
			1, // HEX(`object`.`uuid`)
			1, // HEX(`world_has_objects`.`parentobject_uuid`)
			1, // `object`.`classname`
			0, // `object`.`priority`
			0, // `object`.`visible`
			1, // `object`.`accesscode`
			0, // `object`.`locked`
			1, // HEX(`object`.`player_uuid`)
			0, // `object`.`hitpoints`
			0, // `object`.`damage`
			0, // `object`.`fuel`
			0, // `object`.`fuelcargo`
			0, // `object`.`repaircargo`
			0, // `object`.`items`
			0, // `object`.`magazines`
			0, // `object`.`weapons`
			0, // `object`.`backpacks`
			0, // `object`.`magazinesturret`
			0, // `object`.`variables`
			0, // `object`.`animationstate`
			0, // `object`.`textures`
			0, // `object`.`direction`
			0, // `object`.`positiontype`
			0, // `object`.`positionx`
			0, // `object`.`positiony`
			0, // `object`.`positionz`
			2, // GROUP_CONCAT(`player`.`steamid` SEPARATOR '\", \"') AS friendlist
	};

	printf("%s\n", query.c_str());
	printf("%s\n", this->worlduuid.c_str());
	printf("%s\n", this->hostname.c_str());

	//this->rawquery("SELECT HEX(uuid) FROM `world` WHERE uuid = CAST(0x11e66ac83e75277882c510bf48883ace AS BINARY)", &result);
	this->rawquery(query, &result);

	fieldcount = mysql_num_fields(result);
	rowcount = mysql_num_rows(result);

	printf("fieldcount = %d\n", fieldcount);
	printf("rowcount = %d\n", rowcount);

	std::vector< std::vector<std::string> > resultmatrix (rowcount, std::vector<std::string>(fieldcount));

	for (int rowpos = 0; rowpos < rowcount; rowpos++) {
		row = mysql_fetch_row(result);
		for (int fieldpos = 0; fieldpos < fieldcount; fieldpos++) {
			switch (typearray[fieldpos]) {
			case 1:
				resultmatrix[rowpos][fieldpos] = "\"";
				break;
			case 2:
				resultmatrix[rowpos][fieldpos] = "[";
				if (row[fieldpos] != NULL)
					resultmatrix[rowpos][fieldpos] += "\"";
				break;
			default:
				resultmatrix[rowpos][fieldpos] = "";
			}

			if (row[fieldpos] != NULL) {
				resultmatrix[rowpos][fieldpos] += row[fieldpos];
			} else {
				resultmatrix[rowpos][fieldpos] += "";
			}

			switch (typearray[fieldpos]) {
			case 1:
				resultmatrix[rowpos][fieldpos] += "\"";
				break;
			case 2:
				if (row[fieldpos] != NULL)
					resultmatrix[rowpos][fieldpos] += "\"";
				resultmatrix[rowpos][fieldpos] += "]";
				break;
			}
			printf("%s, ", resultmatrix[rowpos][fieldpos].c_str());
		}
		printf("\n");
	}

	mysql_free_result(result);

	return resultmatrix;
}

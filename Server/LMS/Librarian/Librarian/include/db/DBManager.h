


#pragma once


#include "sqlite3.h"
class DBManager
{
public:
	DBManager();

	~DBManager();
	int Init();
	int AddMasterBookCatalog();
private:
	sqlite3* db;

};


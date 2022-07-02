
#include "DBManager.h"
#include "sqlite3.h"
#include<iostream>

#define LMS_DB_PATH "C:\\LMS\\Server\\LMS\\LMS_DB\\"
#define LMS_DB_NAME "LMS.db"
constexpr const char* db_file = LMS_DB_PATH LMS_DB_NAME;

constexpr const char* sql_create =
"BEGIN;"
"CREATE TABLE IF NOT EXISTS MasterBooksCatalog (Bookname TEXT, Author TEXT, Publisher TEXT, Price TEXT, MasterBookID TEXT, genre TEXT);"
"CREATE TABLE IF NOT EXISTS BookDatabase ( UniqueBookID TEXT, MasterBookID TEXT, UserID TEXT, AvailablityStatus BOOL );"
"CREATE TABLE IF NOT EXISTS UserTable ( UserName TEXT, useremail TEXT, userphone TEXT, UserID TEXT );"
"COMMIT;"
;

DBManager::DBManager()
{
	db = nullptr;
}

DBManager::~DBManager()
{
}

int DBManager::Init()
{
    int rc = sqlite3_open(db_file, &db);
    if (rc == SQLITE_OK) {
        std::cout<<"database open"<<std::endl;
    }
    else {
        printf("sqlite3_open returned an error (%d)\n", rc);
        return 1;
    }

    // create the table source
    puts("create the table source");
    rc = sqlite3_exec(db, sql_create, nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK) {
        puts(sqlite3_errmsg(db));
        return 1;
    }
    return 0;
}

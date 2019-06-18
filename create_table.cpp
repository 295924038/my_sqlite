#include <iostream>
#include <sqlite3.h>

using namespace std;


int main(int argc, char* argv[])
{
    sqlite3 *db;
    int rc = sqlite3_open("first.db",&db);
    if(rc)
    {
        cout<<"open failed "<<sqlite3_errmsg(db)<<endl;
    }else{
        cout<<"open success."<<endl;
    }

    char* sql;
    char *zErrMsg = 0;
    sql = "CREATE TABLE COMPANY("  \
          "ID INT PRIMARY KEY     NOT NULL," \
          "NAME           TEXT    NOT NULL," \
          "AGE            INT     NOT NULL," \
          "ADDRESS        CHAR(50)," \
          "SALARY         REAL );";

    rc = sqlite3_exec(db, sql, NULL, NULL, &zErrMsg);
    if( rc != SQLITE_OK )
    {
        cout<<"SQL error: "<<zErrMsg<<endl;
        sqlite3_free(zErrMsg);
    }else{
        cout<< "Table created successfully\n"<<endl;
    }

    sqlite3_close(db);

    return 0;
}

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

    char *zErrMsg = 0;

    char *sql[] = {
        "insert into COMPANY values(1,'小明', 20,'home',1000)",
        "insert into COMPANY values(2,'小强', 22,'home',1100)",
        "insert into COMPANY values(3,'小红', 24,'home',1200)",
        "insert into COMPANY values(4,'小庄', 26,'home',1300)",
        "insert into COMPANY values(5,'小丘', 28,'home',1400)",
        "insert into COMPANY values(6,'小胡', 30,'home',1500)"
    };

    for(int i = 0; i < sizeof(sql)/sizeof(sql[0]); i++)
    {
        rc = sqlite3_exec(db, sql[i], NULL, NULL, &zErrMsg);
        if( rc != SQLITE_OK )
        {
            cout<<"SQL error: "<<zErrMsg<<endl;
            sqlite3_free(zErrMsg);
        }else{
            cout<< "Table created successfully\n"<<endl;
        }
    }


    sqlite3_close(db);

    return 0;
}




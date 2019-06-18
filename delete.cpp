#include <iostream>
#include <sqlite3.h>

using namespace std;

int my_callback(void* pare,int col_num,char**col_values,char**col_names)
{
    cout<<""<<endl;
    for(int i = 0; i <col_num; i++)
    {
        cout<<col_names[i]<<" "<<col_values[i]<<endl;
    }
    return 0;
}


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

    char *sql = "delete from COMPANY where ID=1; "\
            "SELECT * from COMPANY;";


    rc = sqlite3_exec(db, sql, my_callback, 0, &zErrMsg);
    if( rc != SQLITE_OK )
    {
        cout<<"SQL error: "<<zErrMsg<<endl;
        sqlite3_free(zErrMsg);
    }else{
        cout<< "select successfully\n"<<endl;
    }



    sqlite3_close(db);

    return 0;
}




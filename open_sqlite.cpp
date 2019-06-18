#include <iostream>
#include <sqlite3.h>

using namespace std;

int main()
{
    sqlite3 *db;
    int rc = sqlite3_open("first.db",&db);
    if(rc)
    {
        cout<<"open failed "<<sqlite3_errmsg(db)<<endl;
    }else{
        cout<<"open success."<<endl;
    }
    sqlite3_close(db);


    return 0;
}


#include <iostream>
#include <mysql.h>

using namespace std;



int main() {

   

    insert into Universities(Name, Foundation)
        values('ONU I.I.Mechnikov', 1865);
    insert into Universities(Name, Foundation)
        values('ONPU', 1918);
    insert into Universities(Name, Foundation)
        values('SUNPU K.D.Ushynsky', 1817);

    unsigned int i = 0;
    if (!mysql_init(&mysql)) return 0;
    if (!(mysql_real_connect(&mysql, "localhost", "root", "123", "test_base", 3306, NULL, 0))) return 0;
    if (mysql_select_db(&mysql, "test_base")) return 0;
    if (mysql_query(&mysql, "SELECT * FROM Students")) return 0;
    if (!(res = mysql_store_result(&mysql))) return 0;
    while ((row = mysql_fetch_row(res))) {
        for (i = 0; i < mysql_num_fields(res); i++) {
            cout << row[i] << "\t";
        }

        cout << endl;
    }
    if (!mysql_eof(res)) return 0;
    mysql_free_result(res);
    mysql_close(&mysql);

}
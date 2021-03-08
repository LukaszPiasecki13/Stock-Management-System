#include "Data_Base.h"
#include "Global_Function.h"


Data_Base::Data_Base(string adress, string base_name)
{
    const char* adr = adress.c_str();
    c_adress = adr;
    const char* bn = base_name.c_str();
    c_base_name = bn;
   
}

void Data_Base::Initialization() //initialization and login
{
    string login{};
    string password{};
    Global_Function::Clean();
    while (true)
    {
        cout << "Login : " << endl;
        cin >> login;
        cout << "Password : " << endl;
        cin >> password;
        if (login == c_login & password == c_password)
       {
            cout << "Password correct " << endl;
            system("pause");
            break;
        }
        Global_Function::Clean();
        cout << "Wrong login or password " << endl;
    }
    mysql_init(&mysql); // initialization
    if (mysql_real_connect(&mysql, c_adress, c_login, c_password, "stock management system", 0, NULL, 0))
    {
        printf("Connection to the MySQL database has been established successfully!\n");
        system("pause");
    }
    else
    {
        printf("Connection error MySQL: %d, %s\n", mysql_errno(&mysql), mysql_error(&mysql));
        system("pause");
    }
}

void Data_Base::Add(string id_or_name, string quantity)
{
    MYSQL_RES* queryID;
    MYSQL_ROW  row;
    int id{ NULL };
    string str_id = to_string(id);
    string column{};
    if (!Global_Function::is_number(quantity))
    {
        cout << endl << "Entered text is not a number" << endl;
        system("pause");
        return;
    }
    if (!Global_Function::is_number(id_or_name))                 // If has been selected name
    {
        id_or_name = "'" + id_or_name + "'";
        column = "name";
    }
    else                                        //If has been selected id
        column = "id";

    if (is_exist(id_or_name) >= 1)
    {
        string query{ "SELECT quantity FROM " + c_table_name + " WHERE " +column+ "=" + id_or_name };
        mysql_query(&mysql, query.c_str()); // database query
        queryID = mysql_store_result(&mysql);
        row = mysql_fetch_row(queryID);
        
        quantity = Global_Function::IntToString(Global_Function::StringToInt(row[0]) + Global_Function::StringToInt(quantity));

        Edit(id_or_name, quantity);
        cout << "Item added" << endl;
        system("pause");
    }
    else
    {   
        if (Global_Function::is_number(id_or_name))
        {
            cout << "There is no item with this ID number" << endl;
            system("pause");
        }
        else
        {   string expiration_date;
            cout << "Expiration year: ";
            cin >> expiration_date;
            if (!Global_Function::is_number(expiration_date))
            {
                cout << endl << "Entered text is not a number" << endl;
                system("pause");
                return;
            }
            string query{ "INSERT INTO " + c_table_name + " (id, name, quantity, expiration_year) VALUES(" + str_id + " , " + id_or_name + " , " + quantity + " , " + expiration_date + ") " }; // NULL bo jest autoinkrementacja
            mysql_query(&mysql, query.c_str()); // add elements
            cout << "Item added" << endl;
            system("pause");
        }
    }
}
void Data_Base::Subtract(string column,string id_or_name, int quantity)
{
    MYSQL_RES* queryID;
    MYSQL_ROW  row;
    
    string query{ "SELECT COUNT(*) FROM " + c_table_name + " WHERE " + column + " = " + id_or_name };
    mysql_query(&mysql, query.c_str());
    queryID = mysql_store_result(&mysql);
    row = mysql_fetch_row(queryID); //query result is in new row, so only need to read this new row
    if (Global_Function::StringToInt(row[0]) == 0)
    {
        cout << "There is no such element" << endl;
        system("pause");
        return;
    }
    else
    {
        string query{ "SELECT quantity FROM " + c_table_name + " WHERE " + column + " = " + id_or_name };
        mysql_query(&mysql, query.c_str()); // zapytanie do bazy danych
        queryID = mysql_store_result(&mysql);
        row = mysql_fetch_row(queryID);
        int result = (Global_Function::StringToInt(row[0]) - quantity);
        if (result > 0)
        {
            Edit(id_or_name, Global_Function::IntToString(result));
            cout << "Item subtracted" << endl;
            system("pause");
        }
        else
        {

            cout << "In stock are only " << row[0] << " elements" << endl;
           // id_or_name = "'" + id_or_name + "'";
            Delete(column, id_or_name);
            cout << "Item completly removed" << endl;
            system("pause");
        }
        return;
    }
}

void Data_Base::Edit(string id_or_name, string value)
{
    string column{};
    if (!Global_Function::is_number(id_or_name))                 // If has been selected name
        column = "name";                        // In this case id_or_name is in ' '
    else                                        //If has been selected id
        column = "id";
    string query{ "UPDATE " + c_table_name + " SET quantity = " + value + " WHERE " + column + " = " + id_or_name };
    mysql_query(&mysql, query.c_str()); // editing
}

void Data_Base::Delete(string column,string id_or_name)
{
    if (is_exist(id_or_name) == 0)
    {
        cout << "There is no such element" << endl;
        system("pause");
        return;
    }
    string query{ "DELETE FROM " + c_table_name + " WHERE " + column + " = " + id_or_name };
    mysql_query(&mysql, query.c_str());  //deleting 
    cout << id_or_name <<" has been removed " << endl;
    system("pause");
}

void Data_Base::PrintOneRow(int i)
{
    if (i == 0)
    {
        string query{ "SELECT * FROM " + c_table_name };
        mysql_query(&mysql, query.c_str()); // zapytanie do bazy danych
                                                        //Select * FROM... - wybierz wszystko
        queryID = mysql_store_result(&mysql);
        row = mysql_fetch_row(queryID);
    }
    for (unsigned int i = 0; i < mysql_num_fields(queryID); i++)
    {
        cout << row[i] << " ";
    }
    cout << endl;
    row = mysql_fetch_row(queryID);

}

int Data_Base::is_exist(string id_or_name)
{ //model musi byæ w '' ''

    MYSQL_RES* queryID;
    MYSQL_ROW  row;
    string column{};
    if (!Global_Function::is_number(id_or_name))                 // If has been slected name
        column = "name";
    else                                       //If has been slected id   
    {
        column = "id";
    }
    string query{ "SELECT COUNT(*) FROM " + c_table_name + " WHERE " + column + " = " + id_or_name };
    mysql_query(&mysql, query.c_str());
    queryID = mysql_store_result(&mysql);
    row = mysql_fetch_row(queryID); //query result is in new row, so only need to read this new row
    
    if (Global_Function::StringToInt(row[0]) == 0)
    {
        return 0;
    }
    else
    {
        string query{ "SELECT quantity FROM " + c_table_name + " WHERE " + column + " = " + id_or_name };
        mysql_query(&mysql, query.c_str());
        queryID = mysql_store_result(&mysql);
        row = mysql_fetch_row(queryID); //query result is in new row, so only need to read this new row
        return Global_Function::StringToInt(row[0]);// string to int  
    }
}

int Data_Base::count_row()
{
    MYSQL_RES* queryID;
    MYSQL_ROW  row;
    string query{ "SELECT COUNT(*) FROM " + c_table_name };
    mysql_query(&mysql, query.c_str());
    queryID = mysql_store_result(&mysql);
    row = mysql_fetch_row(queryID); //query result is in new row, so only need to read this new row
    return Global_Function::StringToInt(row[0]);
}

vector<string> Data_Base::show_all_id(string column)
{
    MYSQL_RES* queryID;
    MYSQL_ROW  row;
    vector<string> id{};

    string query{ "SELECT " + column + " FROM " + c_table_name };
    mysql_query(&mysql, query.c_str()); // zapytanie do bazy danych
    queryID = mysql_store_result(&mysql);
    while ((row = mysql_fetch_row(queryID)) != NULL)
    {
        for (unsigned int i{}; i < mysql_num_fields(queryID); i++)
            id.push_back(row[i]);
    }
    return id;
}
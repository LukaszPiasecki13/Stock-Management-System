#pragma once
#include <iostream>
#include <mysql.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
class Data_Base
{
private:
    const char* c_adress{};
    const char* c_base_name{};
    const char* c_password{"admin"};
    string c_table_name{ "magazine1" };
    const char* c_login{ "admin" };

    MYSQL mysql;   //we create a variable MYSQL
    MYSQL_RES* queryID;
    MYSQL_ROW  row;


public:
    Data_Base(string adress, string base_name);
    void Initialization();

    void Add(string name, string quantity);
    void Subtract(string column, string id_or_name, int quantity);  
    void Edit(string column, string value);  
    void Delete(string column, string id_or_name);
    void PrintOneRow(int i); 
    int is_exist(string model);
    int count_row();  
    vector<string> show_all_id(string column);
    
};




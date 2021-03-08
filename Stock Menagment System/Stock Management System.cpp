// Stock Menagment System.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <mysql.h>
#include <string>
#include <sstream>
#include "Data_Base.h"
#include "Menu.h"
#include "Global_Function.h"
#include <fstream>
#include <cstdlib>


using namespace std;

int SetSettings(int choice, int firstnumber, int secondnumber, int thirdnumber)
{
    int start_place{ 22 };  //Start row
    int actual_place{ start_place };
    while (true) // move the arrow
    {
        int getch = _getch();
        Global_Function::GoToxy(actual_place, choice );
        switch (getch)
        {
        case 48:
        {
            cout << 0;
            if (actual_place == 22)
            {
                firstnumber = 0;
            }
            else if (actual_place == 23)
            {
                secondnumber = 0;
            }
            else if (actual_place == 24)
            {
                thirdnumber = 0;
            }
            Global_Function::GoToxy(actual_place, choice );
            break;
        }
        case 49:
        {
            cout << 1;
            if (actual_place == 22)
            {
                firstnumber = 1;
            }
            else if (actual_place == 23)
            {
                secondnumber = 1;
            }
            else if (actual_place == 24)
            {
                thirdnumber = 1;
            }
        }
        Global_Function::GoToxy(actual_place, choice );
        break;
        case 50:
        {
            cout << 2;
            if (actual_place == 22)
            {
                firstnumber = 2;
            }
            else if (actual_place == 23)
            {
                secondnumber = 2;
            }
            else if (actual_place == 24)
            {
                thirdnumber = 2;
            }
            Global_Function::GoToxy(actual_place, choice );
            break;
        }
        case 51:
        {
            cout << 3;
            if (actual_place == 22)
            {
                firstnumber = 3;
            }
            else if (actual_place == 23)
            {
                secondnumber = 3;
            }
            else if (actual_place == 24)
            {
                thirdnumber = 3;
            }
            Global_Function::GoToxy(actual_place, choice );
            break;
        }
        case 52:
        {
            cout << 4;
            if (actual_place == 22)
            {
                firstnumber = 4;
            }
            else if (actual_place == 23)
            {
                secondnumber = 4;
            }
            else if (actual_place == 24)
            {
                thirdnumber = 4;
            }
            Global_Function::GoToxy(actual_place, choice );
            break;
        }
        case 53:
        {
            cout << 5;
            if (actual_place == 22)
            {
                firstnumber = 5;
            }
            else if (actual_place == 23)
            {
                secondnumber = 5;
            }
            else if (actual_place == 24)
            {
                thirdnumber = 5;
            }
            Global_Function::GoToxy(actual_place, choice );
            break;
        }
        case 54:
        {
            cout << 6;
            if (actual_place == 22)
            {
                firstnumber = 6;
            }
            else if (actual_place == 23)
            {
                secondnumber = 6;
            }
            else if (actual_place == 24)
            {
                thirdnumber = 6;
            }
            Global_Function::GoToxy(actual_place, choice );
            break;
        }
        case 55:
        {
            cout << 7;
            if (actual_place == 22)
            {
                firstnumber = 7;
            }
            else if (actual_place == 23)
            {
                secondnumber = 7;
            }
            else if (actual_place == 24)
            {
                thirdnumber = 7;
            }
            Global_Function::GoToxy(actual_place, choice );
            break;
        }
        case 56:
        {
            cout << 8;
            if (actual_place == 22)
            {
                firstnumber = 8;
            }
            else if (actual_place == 23)
            {
                secondnumber = 8;
            }
            else if (actual_place == 24)
            {
                thirdnumber = 8;
            }
            Global_Function::GoToxy(actual_place, choice );
            break;
        }
        case 57:
        {
            cout << 9;
            if (actual_place == 22)
            {
                firstnumber = 9;
            }
            else if (actual_place == 23)
            {
                secondnumber = 9;
            }
            else if (actual_place == 24)
            {
                thirdnumber = 9;
            }
            Global_Function::GoToxy(actual_place, choice );
            break;
        }
        case 77: //right arrow                     
        {
            actual_place++;
            if (actual_place < 25)
            {
                Global_Function::GoToxy(actual_place, choice );
            }
            else if (actual_place >= 25)
            {
                actual_place = actual_place - 3;
                Global_Function::GoToxy(actual_place, choice );
            }break;
        }
        case 75: //left arrow
        { actual_place--;
        if (actual_place > 21)
        {
            Global_Function::GoToxy(actual_place, choice );
        }
        else if (actual_place <= 21)
        {
            actual_place = actual_place + 3;
            Global_Function::GoToxy(actual_place, choice );
        }break;
        }
        case 27: // ESCAPE
            return -1;

        case 13: // ENTER
        {
            int stock{ firstnumber * 100 + secondnumber * 10 + thirdnumber };
            return stock;
        }
        }
    }
}
void ChosenOption(Data_Base base,Menu menu ,int current_pos)
{
    switch (current_pos)
    {
    case 0: // Add
    {
        Global_Function::Clean();
        string name{};
        string quantity{};
        string expiration_date{};
        cout << "If you want exit enter 'exit' \n" << endl;
        cout << "Enter item name or id : ";

        cin >> name;
        if (name == "exit") { break; }
        cout << "Quantity: ";
        cin >> quantity;
        cout << endl;
        if (quantity == "exit") { break; }
        
        cout << endl;

        base.Add(name, quantity);
        break;
    }
    case 1: // Subtract
    {
        Global_Function::Clean();

        string id_or_name{};
        string column{};
        string quantity;
        cout << "If you want exit enter 'exit' \n" << endl;
        cout << "Enter item name or id " << endl;

        cin >> id_or_name;
        if (id_or_name == "exit") { break; }
        if (!Global_Function::is_number(id_or_name))                 // If has been slected name
        {
            id_or_name = "'" + id_or_name + "'";
            column = "name";
        }
        else                                       //If has been slected id
        {
            column = "id";
        }
        cout << "Enter quantity : ";
        while (true)
        {
            cin >> quantity;
            if (!Global_Function::is_number(quantity))
            {
                cout << "Entered word isn't a number. Enter corret number\n";
            }
            else break;
        }
        int int_quantity{ Global_Function::StringToInt(quantity) };

        base.Subtract(column, id_or_name, int_quantity); // Subtract funcjon
        break;
    }
    case 2:  // Find
    {
        string enter{};
        string id_or_name{};
        Global_Function::Clean();
        cout << "If you want exit enter 'exit' \n" << endl;
        cout << "Enter item name or id " << endl;
        cin >> id_or_name;

        if (id_or_name == "exit") { break; }
        enter = id_or_name;
        if (!Global_Function::is_number(id_or_name))                 // If has been slected name
        {
            id_or_name = "'" + id_or_name + "'";
        }
        if (base.is_exist(id_or_name) == 0)
        {
            cout << "There is no such element" << endl;
            system("pause");
            break;
        }
        else
        {
            cout << enter << " = " << base.is_exist(id_or_name) << endl;
            system("pause");
            break;
        }
    }
    case 3: // Delete
    {
        string id_or_name{};
        string column{}; 
        Global_Function::Clean();
        cout << "If you want exit enter 'exit' \n" << endl;
        cout << "Enter item name or id witch you want delate: " << endl;      
        cin >> id_or_name;
        if (id_or_name == "exit") { break; }
        if (!Global_Function::is_number(id_or_name))                 // If has been slected name
        {
            id_or_name = "'" + id_or_name + "'";
            column = "name";
        }
        else                                       //If has been slected id
        {
            column = "id";
        }
        base.Delete(column, id_or_name);
        break;
    }
    case 4: // Statistic
     {
        while (true)
        {
            Global_Function::Clean();
            int number_row{ base.count_row() }; // download number of row from base
            if (menu.StatisticsMenu(number_row, base) == -1) // Show StatisticsMenu if press esc return -1
            {
                // HERE will be statistic function code
                return;
            }
            system("pause");
        }
        break;
    }
    case 5: // Settings
    {
        while (true)
        {
            Global_Function::Clean();
            int number_row{2};  // number of options
            int choice{ menu.SettingsMenu(number_row, base )};   
            int start_place{22};
            switch (choice) // Show StatisticsMenu if press esc return -1
            {
            case -1:
                {return; }
            case 10:         
            {
                string line1{};
                string line2{};
                int actual_place{ start_place };
                Global_Function::GoToxy(actual_place, choice + 1);
                ifstream file("Settings.txt");
                if (file.good() == false)
                {
                    Global_Function::Clean();
                    cout << "Something was wrong. Sorry.";
                    exit(0);
                }
                getline(file, line1);
                getline(file, line2);  // reading
                ofstream save("Settings.txt");

                string s{ Global_Function::IntToString(menu.GetStock_min()) };
                
                int first{};
                int second{};
                int third{};
                if (menu.GetStock_min() < 10)
                {
                    first= 0 ;
                    second = 0 ;
                    third = int(s[0]) - 48;
                }
                else if(menu.GetStock_min()>9 & menu.GetStock_min()<100)
                {
                    first = 0;
                    second = int(s[0]) - 48;
                    third = int(s[1]) - 48;
                }
                else if (menu.GetStock_min()>99)
                {
                    first = int(s[0]) - 48;
                    second = int(s[1]) - 48;
                    third = int(s[2]) - 48;
                }

                int new_min{ SetSettings(choice +1, first, second, third) };
                if (new_min == (-1))
                {
                    break;
                }
                save << new_min << "\n"; // saving 
                save << line2 << "\n";
                menu.SetStock(new_min, Global_Function::StringToInt(line2));
                file.close();
                Global_Function::Clean();
                cout << "       You have to restart the program to save the changes."<< endl;
                system("pause");
                break;

            }
            case 11:
            {
                string line1{};
                string line2{};
                int actual_place{ start_place };
                Global_Function::GoToxy(actual_place, choice + 1);
                ifstream file("Settings.txt");
                if (file.good() == false)
                {
                    Global_Function::Clean();
                    cout << "Something was wrong. Sorry.";
                    exit(0);
                }
                getline(file, line1);
                getline(file, line2);
                ofstream save("Settings.txt");
                string s{ Global_Function::IntToString(menu.GetStock_max()) };
                int first{};
                int second{};
                int third{};
                if (menu.GetStock_max() < 10)
                {
                    first = 0;
                    second = 0;
                    third = int(s[0]) - 48;
                }
                else if (menu.GetStock_max() > 9 & menu.GetStock_max() < 100)
                {
                    first = 0;
                    second = int(s[0]) - 48;
                    third = int (s[1]) - 48;
                }
                else if (menu.GetStock_max() > 99)
                {
                    first = int(s[0]) - 48;
                    second = int(s[1]) - 48;
                    third = int(s[2]) - 48;
                }
                int new_max{ SetSettings(choice+1,first, second, third) };
                if (new_max == (-1))
                {
                    break;
                }
                save << line1 << "\n";
                save << new_max << "\n";
                menu.SetStock(Global_Function::StringToInt(line1), new_max);
                file.close();
                Global_Function::Clean();
                cout << "       You have to restart the program to save the changes." << endl;
                system("pause");
                break;

            }
                
            }
        }



        break;
    }
    case 6: // Exit
    {
        Global_Function::Clean();
        cout << endl;
        cout << "                                      Thank you for using the Stock Management System." << endl;
        cout << "                         The program was created as a final project of the Jezyki Programowania course" << endl;  
        cout << "                                                                               Lukasz Piasecki " << endl;
        cout << "                                                                                   AGH 2020" << endl;
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

        exit(0);
    }
    }
}


int main()
{
    string line1{};
    string line2{};
    Data_Base base("localhost", "stock management system");
    base.Initialization();
    ifstream file("Settings.txt");
    if (file.good() == false)
    {
        Global_Function::Clean();
        cout << "Something was wrong. Sorry.";
        return 0;
    }
    getline(file, line1);
    getline(file, line2);
    Menu menu(Global_Function::StringToInt(line1), Global_Function::StringToInt(line2));
    while (true)
    {
       int current_pos{ menu.MainMenu(base) };
       ChosenOption(base, menu, current_pos);
    }
    file.close();
    return 0;
}

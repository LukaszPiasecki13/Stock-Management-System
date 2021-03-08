#include "Menu.h"
#include "Data_Base.h"
#include "Global_Function.h"


Menu::Menu(int stock_min, int stock_max)
{
    c_stock_min = stock_min;
    c_stock_max = stock_max;
}

void Menu::SetStock(int stock_min, int stock_max)
{
    c_stock_min = stock_min;
    c_stock_max = stock_max;
}

int Menu::GetStock_min()
{
    return c_stock_min;
}
int Menu::GetStock_max()
{
    return c_stock_max;
}

int Menu::MainMenu(Data_Base base)
{

    while (true) //pêtla g³ówna programu
    {
        current_pos = start_pos;
        previous_pos = current_pos;
        PaintMainMenu(base); //rysowanie menu
        while (true) //przesuwanie strza³ki
        {
            PaintMainMenu(base);
         
            switch (_getch())
            {
            case 72: //strza³ka w górê
                if (start_pos < current_pos) current_pos--;
                else if (current_pos == start_pos)
                {
                    current_pos = last_pos;
                }
                break;

            case 80: //strza³ka w dó³
                if (current_pos != last_pos) current_pos++;
                else current_pos = start_pos;
                break;

            case 13: //strza³ka w prawo
                //je¿eli wciœniêto Enter, sprawdŸ wybran¹ opcjê i wykonaj odpowiedni¹ akcjê
                return current_pos - start_pos;
            }         
            Global_Function::GoToxy(1, previous_pos + 1);  //czyszczenie strza³ki wyboru
            cout << " ";
        }
    }
}
int Menu::StatisticsMenu(int number_row, Data_Base base)
{    
    while (true) //pêtla g³ówna programu
    {
        last_pos = number_row-1 + start_pos;
        current_pos = start_pos;
        previous_pos = current_pos;
        PaintStatisticsMenu( number_row, base); //rysowanie menu
        while (true) //przesuwanie strza³ki
        {
            PaintStatisticsMenu(number_row, base);          

            switch (_getch())
            {
            case 72: //strza³ka w górê
                if (start_pos < current_pos) current_pos--;
                else if (current_pos == start_pos)
                {
                    current_pos = last_pos;
                }
                break;

            case 80: //strza³ka w dó³
                if (current_pos != last_pos) current_pos++;
                else current_pos = start_pos;
                break;

            case 13: //strza³ka w prawo
                //je¿eli wciœniêto strza³kê w prawo, sprawdŸ wybran¹ opcjê i wykonaj odpowiedni¹ akcjê
                return current_pos;
            case 27: // ESCAPE
                return -1;
            }
            Global_Function::GoToxy(1, previous_pos + 1);  //czyszczenie strza³ki wyboru
            cout << " ";
           
        }
    }
}
int Menu::SettingsMenu(int number_row, Data_Base base)
{
    while (true) //pêtla g³ówna programu
    {
        last_pos = number_row - 1 + start_pos;
        current_pos = start_pos;
        previous_pos = current_pos;
        PaintSettingsMenu(number_row); //rysowanie menu
        while (true) //przesuwanie strza³ki
        {
            PaintSettingsMenu(number_row);

            switch (_getch())
            {
            case 72: //strza³ka w górê
                if (start_pos < current_pos) current_pos--;
                else if (current_pos == start_pos)
                {
                    current_pos = last_pos;
                }
                break;

            case 80: //strza³ka w dó³
                if (current_pos != last_pos) current_pos++;
                else current_pos = start_pos;
                break;

            case 13: //strza³ka w prawo
                //je¿eli wciœniêto strza³kê w prawo, sprawdŸ wybran¹ opcjê i wykonaj odpowiedni¹ akcjê
                return current_pos ;
            case 27: // ESCAPE
                return -1;
            }
            Global_Function::GoToxy(1, previous_pos + 1);  //czyszczenie strza³ki wyboru
            cout << " ";

        }
    }
}

void Menu::PaintMainMenu(Data_Base base)
{
    Global_Function::Clean(); // odœwierzanie wszystkiego
    Global_Function::GoToxy(3, 11);
    cout << "Add";
    Global_Function::GoToxy(3, 12);
    cout << "Subtract";
    Global_Function::GoToxy(3, 13);
    cout << "Find";
    Global_Function::GoToxy(3, 14);
    cout << "Delete";
    Global_Function::GoToxy(3, 15);
    cout << "Statistics";
    Global_Function::GoToxy(3, 16);
    cout << "Settings";
    Global_Function::GoToxy(3, 17);
    cout << "Exit";
    Global_Function::GoToxy(0, 20);
    cout << "-----------------------------------------------------------------------------------" << endl;
    Global_Function::GoToxy(35, 21);
    cout << "ALERTS" << endl;
    Alerts(base);
    Global_Function::GoToxy(1, current_pos + 1);  //rysowanie strza³ki wyboru
    cout << static_cast <char>(16);

    previous_pos = current_pos; //obs³uga klawiatury
}
void Menu::PaintStatisticsMenu(int number_row, Data_Base base)
{ 
    for (int i{ 0 }; i < number_row; i++)
    {
        Global_Function::GoToxy(3, i+1+start_pos);
        base.PrintOneRow(i);
    }   
    Global_Function::GoToxy(1, current_pos + 1);      //rysowanie strza³ki wyboru
    cout << static_cast <char>(16);   
    previous_pos = current_pos;      //obs³uga klawiatury
}
void Menu::PaintSettingsMenu(int number_row)
{
    Global_Function::Clean(); // odœwierzanie wszystkiego
    Global_Function::GoToxy(3, 11);
    cout << "Minimum Allert    [00";
    if(c_stock_min<99 & c_stock_min > 9)
    {
        Global_Function::GoToxy(23, 11);
        cout << c_stock_min << "]";
    }
    else if (c_stock_min < 9)
    {
        Global_Function::GoToxy(24, 11);
        cout << c_stock_min << "]";
    }
    else if (c_stock_min > 99)
    { 
        Global_Function::GoToxy(22, 11);
        cout << c_stock_min << "]";
    }
    Global_Function::GoToxy(3, 12);
    cout << "Maximum Allert    [00";
    if (c_stock_max < 99 & c_stock_max > 9)
    {
        Global_Function::GoToxy(23, 12);
        cout << c_stock_max << "]";
    }
    else if (c_stock_max < 9)
    {
        Global_Function::GoToxy(24, 12);
        cout << c_stock_max << "]";
    }
    else if (c_stock_max > 99)
    {
        Global_Function::GoToxy(22, 12);
        cout << c_stock_max << "]";
    }
    Global_Function::GoToxy(0, 20);
    Global_Function::GoToxy(1, current_pos + 1);      //rysowanie strza³ki wyboru
    cout << static_cast <char>(16);
    previous_pos = current_pos;      //obs³uga klawiatury
}

void Menu::Alerts(Data_Base base)
{
    vector<string> id_vector = base.show_all_id("id");
    for (int i{}; i < id_vector.size(); i++)
    {  
        if (base.is_exist(id_vector[i])< c_stock_min)
        {  
            cout << "ID: "<< id_vector[i] << "  --   Stocks below " << c_stock_min<< endl;
        }
        if (base.is_exist(id_vector[i]) > c_stock_max)
        {
            cout << "ID: " << id_vector[i] << "  --   Stocks above " << c_stock_max << endl;
        }
    }
}
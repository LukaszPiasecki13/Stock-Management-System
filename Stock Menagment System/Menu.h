#pragma once
#include <windows.h>
#include <conio.h>
#include <iostream>
#include "Data_Base.h"


//Przy tworzeniu bazy danych w xamppie pamietaj o daniu auto inkrementacji

using namespace std;

class Menu
{
private:
    const int start_pos{10};
    int current_pos;
    int previous_pos;
    int last_pos{ start_pos + 6 };
    int c_stock_min{};
    int c_stock_max{};

    void PaintMainMenu(Data_Base base);
    void PaintStatisticsMenu(int number_row, Data_Base base);
    void PaintSettingsMenu(int number_row);
    void Alerts(Data_Base base);

public:
    Menu(int stock_min, int stock_max);
    void SetStock(int stock_min, int stock_max);
    int GetStock_min();
    int GetStock_max();
    int MainMenu(Data_Base base);
    int StatisticsMenu(int number_row, Data_Base base);
    int SettingsMenu(int number_row, Data_Base base);
};


#include "Global_Function.h"

int Global_Function::StringToInt(string s1)
{
    istringstream iss(s1); // string to int
    int int_;
    iss >> int_;
    return int_;
}

string Global_Function::IntToString(int i1)
{
    ostringstream ss;
    ss << i1;
    return ss.str();
}

bool Global_Function::is_number(string text)
{
    for (unsigned int i = 0; i < text.length(); i++)
    {
        if (text[i] > '9' || text[i] < '0')
        {
            return false;
        }
    }
    return true;
}

void Global_Function::Clean()
{
    system("cls");
    cout << " _____ _             _     ___  ___                                                  _     _____           _                 " << endl;
    cout << "/  ___| |           | |    |  \\/  |                                                 | |   /  ___|         | |                " << endl;
    cout << "\\ `--.| |_ ___   ___| | __ | .  . | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_  \\ `--. _   _ ___| |_ ___ _ __ ___ " << endl;
    cout << " `--. \\ __/ _ \\ / __| |/ / | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|  `--. \\ | | / __| __/ _ \\ '_ ` _ \\ " << endl;
    cout << "/\\__/ / || (_) | (__|   <  | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_  /\\__/ / |_| \\__ \\ ||  __/ | | | | |" << endl;
    cout << "\\____/ \\__\\___/ \\___|_|\\_\\ \\_|  |_/\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__| \\____/ \\__, |___/\\__\\___|_| |_| |_|" << endl;
    cout << "                                                      __/ |                                       __/ |                      " << endl;
    cout << "                                                     |___/                                       |___/                       " << endl;
    cout << "                                                                             By Lukasz Piasecki    " << endl;
    cout << "                                                                             WIEiT Elektronika 2020    " << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;

}

void Global_Function::GoToxy(const int x, const int y) //a function that places the cursor anywhere
{
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
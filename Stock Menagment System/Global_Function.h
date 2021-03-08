#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>

using namespace std;
static class Global_Function
{
public:
	static int StringToInt(string s1);
	static string IntToString(int i1);
	static bool is_number(string text);
	static void Clean();
	static void GoToxy(const int x, const int y);  //a function that places the cursor anywhere
};


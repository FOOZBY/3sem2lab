#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

void getlength(int& length);
void gettext(char*& text, int length);
int getnum();
void changetext(char *& text, char* prim_text);
bool cmp(int first, int second);
void savetext(char* prim_text, char* text);
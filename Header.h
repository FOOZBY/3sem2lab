#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int getnum();

void getlength(int& length);
void gettext(char*& text, int length);

bool cmp(int first, int second);
void sort_text(char* text, int length);

void show(char* text, int lenght, string message);

void open_save_file(ofstream& out);
void savetext(ofstream& out, char* text, int length, string message);

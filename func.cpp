#include "Header.h"

int getnum() // �������� �����
{
	int value;
	while (!(cin >> value))
	{ //Since value is a int, (cin >> value) will be true only if the user enters a valid value that can be put inside a int
		cout << "Please enter a valid value:" << endl;
		cin.clear();
		cin.ignore(32767, '\n');
	}
	cin.ignore(32767, '\n');
	return value;
}


void getlength(int& length) 
{
	cout << "������� 0, ���� ������ ������ ����������� ������� ����������� � �����, ����� �������: ";
	int menu = getnum();
	if (menu) // manual
	{
		cout << "������� ����������� �������: ";
		length = getnum();
	}
	else // file
	{
		cout << "������� �������� �����, ���� �� � ���������� ���������, ����� ������� ���� � �����: ";
		string prim_file, line;
		while (true)
		{
			getline(cin, prim_file);
			ifstream in;
			in.open(prim_file); // �������� ���� ��� ������
			if (in.is_open())
			{
				getline(in, line, '\n');
				length = stoi(line);
				cout << "����� �������: " << length << endl;
				break;
			}
			else
			{
				cout << "���� �� ���������� � ��������� �����." << endl;
				cout << "������� ���/���� ����� ���������" << endl;
				cin.clear();
				cin.ignore(32767, '\n');
			}
			cin.seekg(0, ios::end);
			cin.clear();
			in.close(); // ��������� ����
		}   
	}
}

void gettext(char *&text, int length)
{
	cout << "������� 0, ���� ������ ��������� ������ ����������� � �����, ����� �������: ";
	int menu = 1;
	menu = getnum();
	if (menu) //1  manual
	{
		cout << "��������� ������: ";
		for (int i = 0; i < length; i++)
		{
			cin >> text[i];
		}
		// text[length] = '\0';
		cin.clear(); // ���� ����� ������ length, �� �� ������ ���������
		cin.ignore(32767, '\n');
	}
	else // 0 file
	{
		cout << "������� �������� �����, ���� �� � ���������� ���������, ����� ������� ���� � �����: ";
		string prim_file;
		while (true)
		{
			getline(cin, prim_file);
			ifstream in;
			in.open(prim_file); // �������� ���� ��� ������
			if (in.is_open())
			{
				string tmp;
				getline(in, tmp, '\n');//��������� ������ ������ � �����, � ������� �������� ������ �������
              //getline(in, text, length + 1);//��������� ���� ������, � ������� �������� ��� ������, ��� ���� ������� ���������� ������
				for (int i = 0; i < length; i++)
				{
					in >> text[i];
				}
				//text[length] = '\0';
				break;
			}
			else
			{
				cout << "���� �� ���������� � ��������� �����." << endl;
				cout << "������� ���/���� ����� ���������" << endl;
				cin.clear();
				cin.ignore(32767, '\n');
			}
			cin.seekg(0, ios::end);
			cin.clear();
			in.close(); // ��������� ����
		}    
	}
}

bool cmp(int first, int second) 
{
	return first < second;
}

void sort_text(char* text, int length)
{
	char temp;
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (cmp(text[i], text[j]))
			{
				temp = text[i];
				text[i] = text[j];
				text[j] = temp;
			}
		}
	}
}

void show(char * text, int length, string message)
{
	cout << message << endl;
	for (int i = 0; i < length; i++)
	{
		cout << text[i] << " ";
	}
	cout << endl;
}

void open_save_file(ofstream& out)
{
	cout << endl << "������� �������� ��� ���� � �����, � ������� ������ ��������� ���������: ";
	string final_file;
	while (true)
	{
		getline(cin, final_file);
		cin.clear();
		out.open(final_file); // �������� ���� ��� ������
		if (out.is_open())
		{
			break;
		}
		else
		{
			cout << "�� ����������� ������� ���� � ����� ���/� �� ������� ��� �����. ������� ���� � ��� ����� ������" << endl;
			cin.clear();
			cin.ignore(32767, '\n');

		}
		cin.seekg(0, ios::end);
		cin.clear();
	}
}

void savetext(ofstream &out, char* text, int length, string message)
{
	out << message << endl;
	for (int i = 0; i < length; i++)
	{
		out << text[i] << " ";
	}
	out << endl;
}

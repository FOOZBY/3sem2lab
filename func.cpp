#include "Header.h"

void getlength(int& length) 
{
	cout << "������� 0, ���� ������ ������ ����������� ������� ����������� � �����, ����� �������: ";
	int menu = getnum();
	if (menu)//manual
	{
		cout << "������� ����������� �������: ";
		length = getnum();
	}
	else//file
	{
		cout << "������� �������� �����, ���� �� � ���������� ���������, ����� ������� ���� � �����: ";
		string prim_file,line;
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
			in.close();
		}    // ��������� ����
	}
}

void gettext(char *&text, int length)
{
	cout << "������� 0, ���� ������ ��������� ������ ����������� � �����, ����� �������: ";
	int menu = 1;
	menu = getnum();
	if (menu)//1 manual
	{
		cout << "��������� ������: ";
		cin.getline(text, length + 1);
		cin.clear();//���� ����� ������ length, �� �� ������ ���������
		cin.ignore(32767, '\n');
	}
	else//0 file
	{
		cout << "\n������� �������� �����, ���� �� � ���������� ���������, ����� ������� ���� � �����: ";
		string prim_file;
		while (true)
		{
			getline(cin, prim_file);
			ifstream in;
			in.open(prim_file); // �������� ���� ��� ������
			if (in.is_open())
			{
				in.getline(text, length + 1);
				in.getline(text, length + 1);
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
			in.close();
		}    // ��������� ����
	}
}

int getnum()//�������� �����
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

bool cmp(int first, int second) 
{
	return first > second;
}

void changetext(char*& text, char* prim_text)
{
	cout << endl;
	for (int i = 0; i < strlen(text); i++)
	{
		sort(text, text+strlen(text), cmp);
	}
}

void savetext(char* prim_text, char* text)
{
	cout << endl << "������� �������� ��� ���� � �����, � ������� ������ ��������� ���������: ";
	string final_file;
	while (true)
	{
		getline(cin, final_file);
		ofstream out;
		out.open(final_file); // �������� ���� ��� ������
		if (out.is_open())
		{
			out << prim_text << " � ����������� ������" << '\n' << text << " � ��������� ������";
			cout << "\n��������� �������" << endl << endl;
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
		out.close();// ��������� ����
	}
}
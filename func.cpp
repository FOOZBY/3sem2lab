#include "Header.h"

void getlength(int& length) 
{
	cout << "¬ведите 0, если хотите ввести размерность массива считаванием с файла, иначе вручную: ";
	int menu = getnum();
	if (menu)//manual
	{
		cout << "¬ведите размерность массива: ";
		length = getnum();
	}
	else//file
	{
		cout << "¬ведите название файла, если он в директории программы, иначе введите путь к файлу: ";
		string prim_file,line;
		while (true)
		{
			getline(cin, prim_file);
			ifstream in;
			in.open(prim_file); // окрываем файл дл€ чтени€
			if (in.is_open())
			{
				getline(in, line, '\n');
				length = stoi(line);
				cout << "ƒлина массива: " << length << endl;
				break;
			}
			else
			{
				cout << "‘айл не существует в указанном месте." << endl;
				cout << "”кажите им€/путь файла корректно" << endl;
				cin.clear();
				cin.ignore(32767, '\n');
			}
			cin.seekg(0, ios::end);
			cin.clear();
			in.close();
		}    // закрываем файл
	}
}

void gettext(char *&text, int length)
{
	cout << "¬ведите 0, если хотите заполнить массив считаванием с файла, иначе вручную: ";
	int menu = 1;
	menu = getnum();
	if (menu)//1 manual
	{
		cout << "«аполните массив: ";
		cin.getline(text, length + 1);
		cin.clear();//если ввели больше length, то всЄ лишнее стираетс€
		cin.ignore(32767, '\n');
	}
	else//0 file
	{
		cout << "\n¬ведите название файла, если он в директории программы, иначе введите путь к файлу: ";
		string prim_file;
		while (true)
		{
			getline(cin, prim_file);
			ifstream in;
			in.open(prim_file); // окрываем файл дл€ чтени€
			if (in.is_open())
			{
				in.getline(text, length + 1);
				in.getline(text, length + 1);
				break;
			}
			else
			{
				cout << "‘айл не существует в указанном месте." << endl;
				cout << "”кажите им€/путь файла корректно" << endl;
				cin.clear();
				cin.ignore(32767, '\n');
			}
			cin.seekg(0, ios::end);
			cin.clear();
			in.close();
		}    // закрываем файл
	}
}

int getnum()//проверка ввода
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
	cout << endl << "¬ведите название или путь к файлу, в котором хотите сохранить результат: ";
	string final_file;
	while (true)
	{
		getline(cin, final_file);
		ofstream out;
		out.open(final_file); // окрываем файл дл€ записи
		if (out.is_open())
		{
			out << prim_text << " Ч изначальный массив" << '\n' << text << " Ч изменЄнный массив";
			cout << "\n–езультат сохранЄн" << endl << endl;
			break;
		}
		else
		{
			cout << "¬ы неправильно указали путь к файлу или/и не указали им€ файла. ”кажите путь и им€ файла заново" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		cin.seekg(0, ios::end);
		cin.clear();
		out.close();// закрываем файл
	}
}
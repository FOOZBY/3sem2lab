#include "Header.h"

int getnum() // проверка ввода
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
	cout << "¬ведите 0, если хотите ввести –ј«ћ≈–Ќќ—“№ массива считаванием с файла, иначе вручную: ";
	int menu = getnum();
	if (menu) // manual
	{
		cout << "¬ведите размерность массива: ";
		length = getnum();
	}
	else // file
	{
		cout << "¬ведите название файла, если он в директории программы, иначе введите путь к файлу: ";
		string prim_file, line;
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
			in.close(); // закрываем файл
		}   
	}
}

void gettext(char *&text, int length)
{
	cout << "¬ведите 0, если хотите «јѕќЋЌ»“№ массив считаванием с файла, иначе вручную: ";
	int menu = 1;
	menu = getnum();
	if (menu) //1  manual
	{
		cout << "«аполните массив: ";
		for (int i = 0; i < length; i++)
		{
			cin >> text[i];
		}
		// text[length] = '\0';
		cin.clear(); // если ввели больше length, то всЄ лишнее стираетс€
		cin.ignore(32767, '\n');
	}
	else // 0 file
	{
		cout << "¬ведите название файла, если он в директории программы, иначе введите путь к файлу: ";
		string prim_file;
		while (true)
		{
			getline(cin, prim_file);
			ifstream in;
			in.open(prim_file); // окрываем файл дл€ чтени€
			if (in.is_open())
			{
				string tmp;
				getline(in, tmp, '\n');//считываем первую строку в файле, в которой хранитс€ размер массива
              //getline(in, text, length + 1);//считываем след строку, в которой хранитс€ сам массив, при этом забыва€ предыдущую строку
				for (int i = 0; i < length; i++)
				{
					in >> text[i];
				}
				//text[length] = '\0';
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
			in.close(); // закрываем файл
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
	cout << endl << "¬ведите название или путь к файлу, в котором хотите сохранить результат: ";
	string final_file;
	while (true)
	{
		getline(cin, final_file);
		cin.clear();
		out.open(final_file); // окрываем файл дл€ записи
		if (out.is_open())
		{
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

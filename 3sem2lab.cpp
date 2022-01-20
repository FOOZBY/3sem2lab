#include "Header.h"

int main()
{
	setlocale(0, "");

	char* text = nullptr;
	int length = 0;

	ofstream out;

	getlength(length);
	if (!length)
	{
		cout << "Длина массива 0. Завершение работы\n";
		return 0;
	}
	cout << endl;

	text = new char[length] {'\0'}; // изменённый массив
	gettext(text, length);

	open_save_file(out);
	cout << endl;
	show(text, length, "Изначальный массив: ");
	savetext(out, text, length, "Изначальный массив: ");

  //sort(text, text + strlen(text), cmp);
	sort_text(text, length);
	cout << endl;
	out << endl;

	show(text, length, "Изменённый массив: ");
	savetext(out, text, length, "Изменённый массив: ");
	cout << endl;

	out.close();

	delete[] text; 

	system("pause");
}

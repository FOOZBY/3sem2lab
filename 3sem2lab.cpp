#include "Header.h"

int main()
{
	setlocale(0, "");

	int length = 0;
	getlength(length);
	if (!length)
	{
		cout << "Длина массива 0. Завершение работы\n";
		return 0;
	}
	
	char* prim_text = new char[length];//изначальный массив
	char* text = new char[length+1] {'\0'};//изменённый массив
	gettext(prim_text, length);

	for (int i = 0; i < length; i++)
		text[i] = prim_text[i];

	changetext(text, prim_text);

	for (int i = 0; i < strlen(prim_text); i++)
		cout << prim_text[i];
	cout << " — изначальный массив\n";
	for (int i = 0; i < strlen(text); i++)
		cout << text[i];
	cout << " — изменённый массив\n";
	savetext(prim_text, text);

	prim_text = NULL;//костыль
	delete[] prim_text;
	delete[] text; 

	system("pause");
}
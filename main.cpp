#include <iostream>
#include <locale.h>
#include "work.h"

using namespace std;

int main(void)
{
	setlocale(LC_ALL, "Russian");
	int n;
	char* a = new char[9];
	cout << "Введите число:" << ' ';
	cin.getline(a, 9);

	Chisla* arr = new Chisla[7];
	Zap(arr);//Создание массива с "устойчивыми" переменными

	if ('0' <= *a && *a <= '9')
	{
		n = Size(a);
		arabRim(n, arr);
	}
	else
		rimArab(a, arr);
	delete[] arr;
	system("pause");
	return 0;
}

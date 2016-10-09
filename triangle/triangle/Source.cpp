#include <iostream>
#include <cmath>
#include <clocale>
#include "windows.h"
using namespace std;

/*
* Трикутник
*/

int main() {
	//Для кривого cmd
	setlocale(LC_ALL, "Ukr");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Ввід даних
	double a, b, c;
	cout << "A: ";
	cin >> a;
	cout << "B: ";
	cin >> b;
	cout << "C: ";
	cin >> c;

	//Перевіка існування трикутника
	if (a + b>c && a + c>b && b + c>a)
	{
		cout << "Трикутник існує";
		//Первірка рівносторонності
		if (a == b && b == c)
			cout << ", рівносторонній";
		//Перевірна прямокутності
		if (pow(a, 2) + pow(b, 2) == pow(c, 2) ||
			pow(a, 2) + pow(c, 2) == pow(b, 2) ||
			pow(b, 2) + pow(c, 2) == pow(a, 2))
			cout << ", прямокутний";
		//Перевірка рівнобудренності
		if (a == b || a == c || b == c)
			cout << ", рівнобедренний";
	}
	else
		cout << "Трикутник не існує";

	cout << endl;
	system("pause");
}
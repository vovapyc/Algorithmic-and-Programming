#include <iostream>
#include <cmath>
#include <clocale>
#include "windows.h"
using namespace std;

/*
* ���������
*/

int main() {
	//��� ������� cmd
	setlocale(LC_ALL, "Ukr");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//��� �����
	double a, b, c;
	cout << "A: ";
	cin >> a;
	cout << "B: ";
	cin >> b;
	cout << "C: ";
	cin >> c;

	//������� ��������� ����������
	if (a + b>c && a + c>b && b + c>a)
	{
		cout << "��������� ����";
		//������� ��������������
		if (a == b && b == c)
			cout << ", ������������";
		//�������� ������������
		if (pow(a, 2) + pow(b, 2) == pow(c, 2) ||
			pow(a, 2) + pow(c, 2) == pow(b, 2) ||
			pow(b, 2) + pow(c, 2) == pow(a, 2))
			cout << ", �����������";
		//�������� ��������������
		if (a == b || a == c || b == c)
			cout << ", �������������";
	}
	else
		cout << "��������� �� ����";

	cout << endl;
	system("pause");
}
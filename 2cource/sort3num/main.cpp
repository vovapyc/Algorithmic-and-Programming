#include <iostream>
//#include "windows.h"
using namespace std;

/*
 * Сортує 3 числа від найменшого до найбільшого без використання масивів
 */

int main() {
    /*
    //Фікс кодиковки в cmd
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    */

    //Ввід даних
    double a, b, c;
    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;
    cout << "C: ";
    cin >> c;

    //Вираховування
    double x, y, z;
    if (a <= b && b <= c)
        x = a, y = b, z = c;
    else if (a <= c && c <= b)
        x = a, y = c, z = b;
    else if (b <= a && a <= c)
        x = b, y = a, z = c;
    else if (a <= b && c <= b)
        x = c, y = a, z = b;
    else if (b <= a && b <= c)
        x = b, y = c, z = a;
    else if (b <= a && c <= b)
        x = c, y = b, z = a;

    //Вивід
    cout << x << ", " << y << ", " << z << endl;
    //system("pause");
}
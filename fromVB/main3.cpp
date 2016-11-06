#include <iostream>
#include <cmath>
using namespace std;

int main() {
    //Об'явлення змінних
    float a, e, x, p;
    short n;
    cout << "Введіть значення" << endl
         << "x = ";
    cin >> x;
    cout << "n = ";
    cin >> n;

    e = 0.001;
    a = (x- n) / pow(x, n);
    p = 1;

    while (a > e)
    {
        p *= a;
        n++;
        a = (x - n) / pow(x, n);
    }

    cout << "Добуток членів ряду: " << p << endl;
}
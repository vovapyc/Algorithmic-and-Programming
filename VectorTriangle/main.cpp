#include <iostream>
#include <cmath>
using namespace std;

// Структура вектор
struct vector
{
    double x;
    double y;
};

// Повертає модуль вектора
double vectorModule(vector i)
{
    return (double) sqrt(pow(i.x, 2) + pow(i.y, 2));
}

// Повертає кут з cos
double cosToDeg(double cos)
{
    return cos * (180 / 3.14);
}

// Виводить ознаку кута (гострий, прямий)
void angleDefinition(double angle)
{
    if (angle <  90)
        cout << "Гострокутній";
    else if (angle > 90)
        cout << "Тупокутній";
    else
        cout << "Прямокутній";
    cout << endl;
}

int main()
{
    // Ввід даних
    vector a, b, c;

    cout << "Vector A (two numbers): ";
    cin >> a.x;
    cin >> a.y;

    cout << "Vector B (two numbers): ";
    cin >> b.x;
    cin >> b.y;

    cout << "Vector C (two numbers): ";
    cin >> c.x;
    cin >> c.y;

    //Довжина сторін
    double sideA, sideB, sideC;

    sideA = vectorModule(a);
    sideB = vectorModule(b);
    sideC = vectorModule(c);

    cout << "Side A: " << sideA << endl;
    cout << "Side B: " << sideB << endl;
    cout << "Side C: " << sideC << endl;
    cout << endl;

    // Синус кута між сторонами
    double cosSideA = (double) ((pow(sideB, 2) + pow(sideC, 2) - pow(sideA, 2)) / (2 * sideB * sideC));
    double cosSideB = (double) ((pow(sideA, 2) + pow(sideB, 2) - pow(sideC, 2)) / (2 * sideB * sideC));
    double cosSideC = (double) ((pow(sideA, 2) + pow(sideC, 2) - pow(sideB, 2)) / (2 * sideB * sideC));

    cout << "Cos side A: " << cosSideA << endl;
    cout << "Cos side B: " << cosSideB << endl;
    cout << "Cos side C: " << cosSideC << endl;
    cout << endl;

    // Градуси кутів
    double degrSideA = cosToDeg(cosSideA);
    double degrSideB = cosToDeg(cosSideB);
    double degrSideC = cosToDeg(cosSideC);

    cout << "A: " << degrSideA << " "; angleDefinition(degrSideA);
    cout << "B: " << degrSideB << " "; angleDefinition(degrSideB);
    cout << "C: " << degrSideC << " "; angleDefinition(degrSideC);
}
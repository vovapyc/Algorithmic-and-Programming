#include <iostream>
#include <string.h>

using namespace std;

long get_gcd(long a, long b) {
    // Найбільший спільний дільник
    if (b == 0)
        return a;

    return get_gcd(b, a % b);
}

class Fraction {
private:
    long numerator;
    long denominator;
public:
    Fraction(): numerator(1), denominator(1) {}
    Fraction(long n, long d): numerator(n), denominator(d) {}
    void set(long numerator, long denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    long getNumerator() {
        return numerator;
    }
    long getDenominator() {
        return denominator;
    }
    void input() {
        long numerator;
        long denominator;
        cout << "Enter numerator: ";
        cin >> this->numerator;
        cout << "Enter denominator: ";
        cin >> this->denominator;
    }
    void print() {
        cout << numerator << "/" << denominator << endl;
    }
    void shortly() {
        // Скоротити
        long gcd = get_gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }
    double getRealNumber() {
        // Повертає дійсне число
        return numerator/ denominator;
    }
    Fraction operator+(Fraction num) {
        return Fraction((num.getNumerator() * this->denominator + num.getDenominator() * this->numerator),
                        num.getDenominator() * this->denominator);
    }
    Fraction operator-(Fraction num) {
        return Fraction((num.getNumerator() * this->denominator - num.getDenominator() * this->numerator),
                        num.getDenominator() * this->denominator);
    }
    Fraction operator!() {
        return Fraction(denominator, numerator);
    }
    bool operator<(Fraction num) {
        return getRealNumber() < num.getRealNumber();
    }
    bool operator>(Fraction num) {
        return getRealNumber() > num.getRealNumber();
    }
    bool operator<=(Fraction num) {
        return getRealNumber() <= num.getRealNumber();
    }
    bool operator>=(Fraction num) {
        return getRealNumber() >= num.getRealNumber();
    }
};

int main()
{
    Fraction a(1, 3);
    Fraction b(3, 2);

    Fraction c = a + b;
    c.shortly();
    c.print();

    c = a - b;
    c.shortly();
    c.print();

    c = !c;
    c.print();

    if (a > b) {
        cout << "a > b" << endl;
    } else {
        cout << "a <= b" << endl;
    }

    // system("pause");  Для vs
}

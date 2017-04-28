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
    void intput() {
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
};

Fraction add(Fraction num1, Fraction num2) {
    Fraction result;
    result.set((num1.getNumerator() * num2.getDenominator() + num1.getDenominator() * num2.getNumerator()),
               num1.getDenominator() * num2.getDenominator());
    return result;
}

Fraction min(Fraction num1, Fraction num2) {
    Fraction result;
    result.set((num1.getNumerator() * num2.getDenominator() - num1.getDenominator() * num2.getNumerator()),
               num1.getDenominator() * num2.getDenominator());
    return result;
}

int main()
{
    Fraction a, b;
    a.set(1, 2);
    b.set(1, 4);

    Fraction result = add(a, b);
    result.shortly();
    result.print();

    result = min(a, b);
    result.shortly();
    result.print();

    // system("pause");  Для vs
}

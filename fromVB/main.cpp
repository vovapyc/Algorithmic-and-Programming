#include <iostream>
using namespace std;

int main() {
    //Об'явлення змінних
    double S = 10000;
    int n = 0;

    while (S < 20000)
    {
        S = S + 0.03 * S;
        n++;
    }
    cout << "Збереження збiльшаться в 2 рази через: " << n << " років" << endl;
}
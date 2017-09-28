#include <iostream>
using namespace std;

int main() {
    //Об'явлення змінних
    float p, k;
    int t, v;
    t = 0;
    v = 100;
    p = 5;

    while (t <= 10)
    {
        v += 6;
        k = p / v;
        p = p - 5 * k;
        v -= 5;
        t++;
    }

    cout << "Через 10хв кiлькiсть цукру складе: " << p << endl;
}
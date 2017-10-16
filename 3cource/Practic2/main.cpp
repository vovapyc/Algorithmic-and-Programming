#include <iostream>
#include <string>

using namespace std;

void func(int** arr, int n)
{
    short line = n/6;
    bool invert = 0;
    for (int i = 0;  i < n; i++) {
        if (i % line == 0) {
            invert = !invert;
        }
        for (int x = 0; x < n; x++) {
            if (invert) {
                arr[i][x] = 0;
            }
        }
    }
}

int main()
{
    const short size = 12; // Має ділитись на 6
    int** array = new int*[size];
    for(int i = 0; i < size; ++i) {
        array[i] = new int[size];
        fill_n(array[i], size, 1);  // Put 1 in each element
    }

    func(array, size);

    for (int i = 0; i < size; i++) {
        for (int x = 0; x < size; x++) {
            cout << array[i][x];
        }
        cout << endl;
    }
}

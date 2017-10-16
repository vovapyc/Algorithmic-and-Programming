#include <iostream>

using namespace std;

class Matrix {
private:
    int matrix[10][10];
public:
    Matrix(int m[10][10]) {
        for (int i = 0; i < 10; i++) {
            for (int x = 0; x < 10; x++){
                matrix[i][x] = m[i][x];
            }
        }
    }

    Matrix(int value) {
        for (int i = 0; i < 10; i++) {
            for (int x = 0; x < 10; x++){
                matrix[i][x] = value;
            }
        }
    }

    int getElement(int i, int x) {
        return matrix[i][x];
    }

    void operator -= (Matrix m) {
        for (int i = 0; i < 10; i++) {
            for (int x = 0; x < 10; x++){
                matrix[i][x] -= m.getElement(i, x);
            }
        }
    }

    void operator *= (Matrix m) {
        for (int i = 0; i < 10; i++) {
            for (int x = 0; x < 10; x++){
                matrix[i][x] *= m.getElement(i, x);
            }
        }
    }

    void print() {
        for (int i = 0; i < 10; i++) {
            for (int x = 0; x < 10; x++) {
                cout << matrix[i][x] << ' ';
            }
            cout << endl;
        }
    }
};

int main()
{
    Matrix a = Matrix(10);
    Matrix b = Matrix(2);
    a.print();
    cout << endl;
    b.print();
    cout << endl;

    a -= b;
    a.print();
}

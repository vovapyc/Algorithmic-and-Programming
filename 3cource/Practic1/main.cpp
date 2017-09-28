#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class Person{
private:
    string name;
    short dayOfBirth;
    short monthOfBirth;
public:
    void input() {
        cin.ignore();  // Без цеї хуйні getline не працює
        cout << "Enter name: "; getline(cin, name);
        cout << "Day of birthday: "; cin >> dayOfBirth;
        cout << "Month of birthday: "; cin >> monthOfBirth;
    }
    void appendToFile(string filename) {
        ofstream file(filename, fstream::app);
        if (file){
            file << name << setw(25 - name.length()) << dayOfBirth << '/' << monthOfBirth << endl;
            file.close();
        }
        else {
            exit(-1);
        }
    }
};

int main()
{
    Person p;
    while (true) {
        char check; cout << "Read(r), input(i) or quit(q): "; cin >> check;
        string temp;
        if (check == 'r') {
            ifstream f("../database.txt");
            if (f) {
                cout << "Name" << setw(22) << "d/m" << endl << string(22, '-') << ' ' << string(4, '-') << endl;
                while (!f.eof()) {
                    getline(f, temp);
                    cout << temp << endl;
                }
            }
            else {
                exit(-1);
            }
            f.close();
        }
        else if (check == 'i') {
            p.input();
            p.appendToFile("../database.txt");
        }
        else if (check == 'q') {
            return 0;
        }
    }
}

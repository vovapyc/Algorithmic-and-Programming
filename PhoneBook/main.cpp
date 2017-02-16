#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct phoneContact {
    unsigned long number;
    string firstName;
    string lastName;
    string address;
};

int main() {
    phoneContact *contactBook = new phoneContact[100];

    // Ввід
    unsigned index = 0;
    char check = 'n';
    do {
        // Записує контакт
        cout << "Номер: ";
        cin >> contactBook[index].number;
        cout << "Ім'я: ";
        cin >> contactBook[index].firstName;
        cout << "Прізвище: ";
        cin >> contactBook[index].lastName;
        cout << "Адреса: ";
        cin >> contactBook[index].address;
        index++;
        cout << endl;

        cout << "Продовжити?(y/n): ";
        cin >> check;
        cout << endl;
    } while (check == 'y' || check == 'Y');

    unsigned size = index;

    // Сортування
    for (int i = index - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (contactBook[j].number > contactBook[j+1].number)
            {
                auto tmp = contactBook[j].number;
                contactBook[j].number = contactBook[j+1].number;
                contactBook[j+1].number = tmp;
            }
        }
    }

    // Вивід
    for (unsigned i = 0; i < index; i++) {
        // Виводить контакт
        cout << left << i << '\t';
        cout << left << setw(15) << contactBook[i].number << '\t';
        cout << left << setw(30) << contactBook[i].firstName + ' ' + contactBook[i].lastName << '\t';
        cout << left << setw(30) << contactBook[i].address;
        cout << endl;
    }

    // Пошук
    check = 'n';
    cout << "Виконати пошук по контактах за номерами?(y/n): ";
    cin >> check;
    if (check == 'y' || check == 'Y') {
        unsigned long number;
        cout << "Введіть номер: ";
        cin >> number;
        for (unsigned i = 0; i < size; i++) {
            if (contactBook[i].number == number) {
                cout << "Знайдено" << endl;
                cout << left << setw(15) << contactBook[i].number << '\t';
                cout << left << setw(30) << contactBook[i].firstName + ' ' + contactBook[i].lastName << '\t';
                cout << left << setw(30) << contactBook[i].address;
                cout << endl;
            } else {
                cout << "Нічого не знайдено" << endl;
            }
        }
    }

    // system("pause"); // для vs
}

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct date {
    short year;
    short mouth;
    short day;
    short hour;
    short minute;
};

struct train {
    unsigned long number;
    string to;
    string from;
    date time;  // TODO: час прибуття і ...
};

int main() {
    train *trains = new train[100];

    // Ввід
    unsigned index = 0;
    char check = 'n';
    do {
        // Записує  поїзд
        cout << "Номер: ";
        cin >> trains[index].number;
        cout << "Звідки: ";
        cin >> trains[index].from;
        cout << "Куда: ";
        cin >> trains[index].to;
        cout << "Час відправлення (у форматі рік/місяць/день/година/хвилини): ";
        cin >> trains[index].time;  // TODO:  написати перевід у unix time

        index++;
        cout << endl;

        cout << "Продовжити?(y/n): ";
        cin >> check;
        cout << endl;
    } while (check == 'y' || check == 'Y');

    unsigned size = index;

    // Сортування за часом відправлення
    for (int i = index - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (trains[j].time > trains[j + 1].time)
            {
                auto tmp = trains[j].time;
                trains[j].time = trains[j + 1].time;
                trains[j + 1].time = tmp;
            }
        }
    }

    // Вивід
    for (unsigned i = 0; i < index; i++) {
        cout << left << i << '\t';
        cout << left << setw(15) << trains[i].number << '\t';
        cout << left << setw(30) << trains[i].from + " - " + trains[i].to << '\t';
        cout << left << setw(30) << trains[i].time;  // TODO: Написати перевід у unix time
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
            if (trains[i].number == number) {
                cout << left << i << '\t';
                cout << left << setw(15) << trains[i].number << '\t';
                cout << left << setw(30) << trains[i].from + " - " + trains[i].to << '\t';
                cout << left << setw(30) << trains[i].time;  // TODO: Написати перевід у unix time
                cout << endl;
            }
            else {
                cout << "Нічого не знайдено" << endl;
            }
        }
    }

    // system("pause"); // для vs
}
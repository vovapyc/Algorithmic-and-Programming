#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct train {
    unsigned long number;
    string to;
    string from;
    string arrivalTime;  // прибуття
    string departureTime;  // відправлення
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
        cout << "Час прибуття (у форматі рік/місяць/день/година/хвилини): ";
        cin >> trains[index].arrivalTime;
        cout << "Час відправлення (у форматі рік/місяць/день/година/хвилини): ";
        cin >> trains[index].departureTime;

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
            if (trains[j].departureTime > trains[j + 1].departureTime)
            {
                auto tmp = trains[j].departureTime;
                trains[j].departureTime = trains[j + 1].departureTime;
                trains[j + 1].departureTime = tmp;
            }
        }
    }

    // Вивід
    for (unsigned i = 0; i < index; i++) {
        cout << left << i << '\t';
        cout << left << setw(15) << trains[i].number << '\t';
        cout << left << setw(30) << trains[i].from + " - " + trains[i].to << '\t';
        cout << left << setw(30) << trains[i].arrivalTime;
        cout << " : ";
        cout << left << setw(30) << trains[i].departureTime;
        cout << endl;
    }

    // Пошук
    check = 'n';
    cout << "Виконати пошук по рейсах за номером?(y/n): ";
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
                cout << left << trains[i].arrivalTime << " : " << trains[i].departureTime;
                cout << endl;
            }
            else {
                cout << "Нічого не знайдено" << endl;
            }
        }
    }

    // system("pause"); // для vs
}
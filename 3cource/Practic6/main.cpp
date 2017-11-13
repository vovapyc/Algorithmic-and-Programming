# include <iostream>
# include <string>

using namespace std;


class Animal {
protected:
    string name;
    int weight;
public:
    Animal() {}
    virtual void call() = 0;
    virtual void feed(int feedWeight=1) {
        weight += feedWeight;
    }
    virtual void doAnimalStuff() {
        weight--;
        call();
    }
};

class Dog : public Animal {
public:
    Dog(string name, int weight) {
        this->name = name;
        this->weight = weight;
    }
    void call() {
        cout << "Woof" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string name, int weight) {
        this->name = name;
        this->weight = weight;
    }
    void call() {
        cout << "Meow" << endl;
    }
};

class Petuh : public Animal {
public:
    Petuh(string name, int weight) {
        this->name = name;
        this->weight = weight;
    }
    void call() {
        cout << "Ko-ko-ko-ko" << endl;
    }
};


int main()
{
    Petuh vanya = Petuh("Ваня", 50);
    vanya.call();
    vanya.doAnimalStuff();
}

//
// Created by hrist on 4/19/2024.
//
// vashiot kod ovde
#include <iostream>
#include <cstring>

using namespace std;

class Ucesnik {
private:
    char *name;
    bool gender;
    int age;

    void copy(const Ucesnik &other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->gender = other.gender;
        this->age = other.age;
    }

public:
    //Constructor
    Ucesnik(char *name = (char *) "", bool gender = false, int age = 10) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->gender = gender;
        this->age = age;
    }

    //Copy constructor
    Ucesnik(const Ucesnik &other) {
        copy(other);
    }

    //operator=
    Ucesnik &operator=(const Ucesnik &other) {
        if (this != &other) {
            delete[] name;
            copy(other);
        }
        return *this;
    }

    //Destructor
    ~Ucesnik() {
        delete[] name;
    }

    //Operator >
    bool operator>(Ucesnik &other) {
        return this->age > other.age;
    }

    int getAge() {
        return age;
    }

    friend ostream &operator<<(ostream &os, const Ucesnik &ucesnik) {
        os << ucesnik.name << endl;
        if (ucesnik.gender)
            os << "mashki" << endl;
        else
            os << "zhenski" << endl;
        os << ucesnik.age << endl;
        return os;
    }

};

class Maraton {
private:
    char location[100];
    Ucesnik *particapants;
    int numParticipants;

    void copy(const Maraton &other) {
        strcpy(this->location, other.location);
        this->numParticipants = other.numParticipants;
        this->particapants = new Ucesnik[other.numParticipants];
        for (int i = 0; i < numParticipants; i++) {
            this->particapants[i] = other.particapants[i];
        }
    }

public:
    //Constructor
    Maraton(char *location = (char *) "") {
        strcpy(this->location, location);
        this->numParticipants = 0;
        this->particapants = new Ucesnik[0];
    }

    //Copy construcotr
    Maraton(const Maraton &other) {
        copy(other);
    }

    //Operator =
    Maraton &operator=(const Maraton &other) {
        if (this != &other) {
            delete[] particapants;
            copy(other);
        }
        return *this;
    }

    Maraton operator+=(Ucesnik &other) {
        Ucesnik *temp = new Ucesnik[numParticipants + 1];
        for (int i = 0; i < numParticipants; i++) {
            temp[i] = particapants[i];
        }
        temp[numParticipants++] = other;
        delete[] particapants;
        particapants = temp;
        return *this;
    }


    double prosecnoVozrast() {
        int sum = 0;
        for (int i = 0; i < numParticipants; i++) {
            sum += particapants[i].getAge();
        }
        return (double) sum / numParticipants;
    }

    void pecatiPomladi(Ucesnik &ucesnik) {
        for (int i = 0; i < numParticipants; i++) {
            if (ucesnik > particapants[i]) {
                cout << particapants[i];
            }
        }
    }
};

int main() {
    char ime[100];
    bool maski;
    int vozrast, n;
    cin >> n;
    char lokacija[100];
    cin >> lokacija;
    Maraton m(lokacija);
    Ucesnik **u = new Ucesnik *[n];
    for (int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
        u[i] = new Ucesnik(ime, maski, vozrast);
        m += *u[i];
    }
    m.pecatiPomladi(*u[n - 1]);
    cout << m.prosecnoVozrast() << endl;
    for (int i = 0; i < n; ++i) {
        delete u[i];
    }
    delete[] u;
    return 0;
}
//
// Created by hrist on 4/19/2024.
//
//Zadaca 4 od tia za vezbanje

#include<iostream>
#include<cstring>

using namespace std;

#include<iostream>
#include<cstring>

using namespace std;

class Patnik {

private:
    char NamePassenger[100];
    int Wagon;
    bool Bicycle;

public:

    Patnik() {
        strcpy(this->NamePassenger, "");
        this->Wagon = 0;
        this->Bicycle = 0;
    }

    Patnik(char *NamePassenger, int Wagon, int Bicycle) {
        strcpy(this->NamePassenger, NamePassenger);
        this->Wagon = Wagon;
        this->Bicycle = Bicycle;
    }

    friend ostream &operator<<(ostream &out, Patnik &p) {
        out << p.NamePassenger << endl;
        out << p.Wagon << endl;
        out << p.Bicycle;
        out << endl;
    }

    friend class Voz;

};

class Voz {

private:
    char FinalDestinationn[100];
    Patnik *Passengers;
    int NumPassengers;
    int NumAvailableBicycles;

public:

    Voz() {
        strcpy(FinalDestinationn, "");
        Passengers = new Patnik[0];
        NumPassengers = 0;
        NumAvailableBicycles = 0;
    }

    Voz(char *FinalDestinationn, int NumAvailableBicycles) {
        strcpy(this->FinalDestinationn, FinalDestinationn);
        this->NumAvailableBicycles = NumAvailableBicycles;
        Passengers = new Patnik[0];
        NumPassengers = 0;
    }

    Voz(const Voz &v) {
        strcpy(this->FinalDestinationn, v.FinalDestinationn);
        this->NumAvailableBicycles = v.NumAvailableBicycles;
        this->NumPassengers = v.NumPassengers;
        this->Passengers = new Patnik[v.NumPassengers];
        for (int i = 0; i < v.NumPassengers; ++i) {
            Passengers[i] = v.Passengers[i];
        }
    }

    Voz &operator=(const Voz &v) {
        if (this != &v) {
            delete[] Passengers;
            strcpy(this->FinalDestinationn, v.FinalDestinationn);
            this->NumAvailableBicycles = v.NumAvailableBicycles;
            this->NumPassengers = v.NumPassengers;
            this->Passengers = new Patnik[v.NumPassengers];
            for (int i = 0; i < v.NumPassengers; ++i) {
                Passengers[i] = v.Passengers[i];
            }
        }
        return *this;
    }

    ~Voz() {
        delete[] Passengers;
    }

    Voz &operator+=(const Patnik &v) {
        int counter = 0;
        Patnik *NewPassengers = new Patnik[NumPassengers + 1];
        for (int i = 0; i < NumPassengers; i++) {
            NewPassengers[i] = Passengers[i];
        }
        if (NumAvailableBicycles > counter && v.Bicycle == 1) {
            NewPassengers[NumPassengers++] = v;
            counter++;
        } else if (v.Bicycle == 0)
            NewPassengers[NumPassengers++] = v;

        delete[] Passengers;
        Passengers = NewPassengers;
        //NumPassengers=counter;
    }

    friend ostream &operator<<(ostream &out, const Voz &v) {
        out << v.FinalDestinationn << endl;
        for (int i = 0; i < v.NumPassengers; i++) {
            out << v.Passengers[i] << endl;
//            out<<endl;
        }
    }

//    void patniciNemaMesto(){
    void patniciNemaMesto() {
        int i = 0, counter = 0, counter2 = 0, first = 0, second = 0, counterNo = 0;
        for (int i = 0; i < NumPassengers; i++) {
            if (Passengers[i].Wagon == 1) {
                if (NumAvailableBicycles != 0 && Passengers[i].Bicycle) {
                    NumAvailableBicycles--;
                    counter++;
                } else if (Passengers[i].Bicycle == 0)
                    counterNo++;
                first++;
            }
        }
        //cout<<"Kolku ima mesto za tocaci "<<NumAvailableBicycles<<endl;
        //cout<<"broj  na 1 klasa "<<first<<" Broj na tie so se kacile "<<counter<<endl;
        first -= (counter + counterNo);
        //cout<<"Kolku ostanale da ne se kacat od 1 klasa "<<first<<endl;
        //NumAvailableBicycles-=counter;
        //cout<<"Kolku ima mesto za tocaci "<<NumAvailableBicycles<<endl;
        counterNo = 0;
        for (int i = 0; i < NumPassengers; i++) {
            if (Passengers[i].Wagon == 2) {
                if (NumAvailableBicycles != 0 && Passengers[i].Bicycle) {
                    NumAvailableBicycles--;
                    counter2++;
                } else if (Passengers[i].Bicycle == 0)
                    counterNo++;
                second++;
            }
        }
        //cout<<"broj  na 2 klasa "<<second<<" Broj na tie so se kacile "<<counter2<<endl;
        second -= (counter2 + counterNo);
        //cout<<"Kolku ostanle da ne se kacat od 2 klasa "<<second<<endl;
        cout << "Brojot na patnici od 1-va klasa koi ostanale bez mesto e: " << first << endl;
        cout << "Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: " << second << endl;
    }
};


int main() {
    Patnik p;
    char ime[100], destinacija[100];
    int n;
    bool velosiped;
    int klasa;
    int maxv;
    cin >> destinacija >> maxv;
    cin >> n;
    Voz v(destinacija, maxv);
    //cout<<v<<endl;
    for (int i = 0; i < n; i++) {
        cin >> ime >> klasa >> velosiped;
        Patnik p(ime, klasa, velosiped);
        //cout<<p<<endl;
        v += p;
    }
    cout << v;
    v.patniciNemaMesto();

    return 0;
}

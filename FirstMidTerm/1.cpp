//
// Created by hrist on 4/19/2024.
//
#include <iostream>>
#include <cstring>>

using namespace std;

enum tip {
    pop,//0
    rap,//1
    rok//2
};


class Pesna {
private:
    char *SongName;
    int Duration;
    tip Type;
public:
    //Default
    Pesna() {
        SongName = new char[0];
        Duration = 0;
        Type = pop;
    }

    //argumetn
    Pesna(char *SongName, int Duration, tip Type) {
        this->SongName = new char[strlen(SongName) + 1];
        strcpy(this->SongName, SongName);
        this->Duration = Duration;
        this->Type = Type;
    }

    //Copy
    Pesna(const Pesna &p) {
        this->SongName = new char[strlen(p.SongName) + 1];
        strcpy(this->SongName, p.SongName);
        this->Duration = p.Duration;
        this->Type = p.Type;
    }

    //Operator =
    Pesna operator=(const Pesna &p) {
        if (this != &p) {
            delete[] SongName;
            this->SongName = new char[strlen(p.SongName) + 1];
            strcpy(this->SongName, p.SongName);
            this->Duration = p.Duration;
            this->Type = p.Type;
        }
        return *this;
    }

    //destruotr
    ~Pesna() {
        delete[] SongName;
    }

    //pecati
    void pecati() {
        cout << "\"" << SongName << "\"-" << Duration << "min" << endl;
    }

    friend class CD;
};


class CD {
private:
    Pesna Songs[10];
    int Recordedsongs;
    int MaxDuration;
public:
    //default
    CD() {
        //[0]=0;
        Recordedsongs = 0;
        MaxDuration = 0;
    }

    //argumets
    CD(int MaxDuration) {
        //Songs=nullptr;
        Recordedsongs = 0;
        this->MaxDuration = MaxDuration;
        //this->Songs=new Pesna[reco]
    }

    //copy
    CD(const CD &c) {
        this->MaxDuration = c.MaxDuration;
        this->Recordedsongs = c.Recordedsongs;
        //this->Songs=new Pesna[c.Recordedsongs];
        for (int i = 0; i < c.Recordedsongs; i++) {
            this->Songs[i] = c.Songs[i];
        }
    }

    //operator =
    CD &operator=(const CD &c) {
        if (this != &c) {
            delete[] Songs;
            this->MaxDuration = c.MaxDuration;
            this->Recordedsongs = c.Recordedsongs;
            //this->Songs=new Pesna[c.Recordedsongs];
            for (int i = 0; i < c.Recordedsongs; i++) {
                this->Songs[i] = c.Songs[i];
            }
        }
        return *this;
    }

    //destrucot
    ~CD() {
        //delete [] Songs;
    }

    //dodedipensa
    void dodadiPesna(Pesna p) {
        if (Recordedsongs < 10) {
            if (p.Duration < MaxDuration) {
                Songs[Recordedsongs++] = p;
                MaxDuration -= p.Duration;
            }
        }
    }

    //getPesna
    Pesna getPesna(int i) {
        return Songs[i];
    }

    //print
    void pecatiPesniPoTip(tip t) {
        int i;
        for (i = 0; i < Recordedsongs; i++) {
            if (Songs[i].Type == t) {
                Songs[i].pecati();
            }
        }
    }

    //getbroj
    int getBroj() {
        return Recordedsongs;
    }


};

int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, minuti, kojtip;
    char ime[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime, minuti, (tip) kojtip);
        p.pecati();
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i = 0; i < n; i++)
            (omileno.getPesna(i)).pecati();
    } else if (testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i = 0; i < omileno.getBroj(); i++)
            (omileno.getPesna(i)).pecati();
    } else if (testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        cin >> kojtip;
        omileno.pecatiPesniPoTip((tip) kojtip);

    } else if (testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        cin >> kojtip;
        omileno.pecatiPesniPoTip((tip) kojtip);

    }

    return 0;
}

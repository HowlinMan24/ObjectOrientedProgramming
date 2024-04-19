//
// Created by hrist on 4/19/2024.
//
#include <iostream>
#include <cstring>

using namespace std;

enum Tip {
    LINUX,
    UNIX,
    WINDOWS
};

class OperativenSistem {
private:
    char *OperativenName;
    float Version;
    Tip Type;
    float Size;
public:
    //Defaullt constructor
    OperativenSistem() {
        OperativenName = nullptr;
        Version = 0.0;
        Type = LINUX;
        Size = 0.0;
    }

    //Constructor with arguments
    OperativenSistem(char *OperativenName, float Version, Tip Type, float Size) {
        this->OperativenName = new char[strlen(OperativenName) + 1];
        strcpy(this->OperativenName, OperativenName);
        this->Version = Version;
        this->Type = Type;
        this->Size = Size;
    }

    //copy-constructor
    OperativenSistem(const OperativenSistem &p) {
        this->OperativenName = new char[strlen(p.OperativenName) + 1];
        strcpy(this->OperativenName, p.OperativenName);
        this->Version = p.Version;
        this->Type = p.Type;
        this->Size = p.Size;
    }

    //operator =
    OperativenSistem &operator=(const OperativenSistem &p) {
        if (this != &p) {
            delete[] OperativenName;
            this->OperativenName = new char[strlen(p.OperativenName) + 1];
            strcpy(this->OperativenName, p.OperativenName);
            this->Version = p.Version;
            this->Type = p.Type;
            this->Size = p.Size;
        }
        return *this;
    }

    //Destrucot
    ~OperativenSistem() {
        delete[] OperativenName;
    }

    //void pecati()
    void pecati() {
        cout << "Ime: " << OperativenName;
        cout << " Verzija: " << Version;
        cout << " Tip: " << Type;
        cout << " Golemina:" << Size << "GB";
        cout << endl;
    }

    //bool ednakviSe(const OperativenSistem &os)
    bool ednakviSe(const OperativenSistem &os) {
        return (strcmp(this->OperativenName, os.OperativenName) == 0 && (this->Version == os.Version) &&
                (this->Type == os.Type) && (this->Size, os.Size));
    }

    //int sporediVerzija(const OperativenSistem &os)
    int sporediVerzija(const OperativenSistem &os) {
        if (this->Version == os.Version)
            return 0;
        else if (this->Version < os.Version)
            return -1;
        else
            return 1;
    }

    //bool istaFamilija(const OperativenSistem &sporedba)
    bool istaFamilija(const OperativenSistem &sporedba) {
        return (strcmp(this->OperativenName, sporedba.OperativenName) == 0 && (this->Type == sporedba.Type));
    }

    friend class Repozitorium;
};

class Repozitorium {
private:
    char Name[20];
    OperativenSistem *Systems;
    int NumSystems;
public:
    //default constructor
    Repozitorium() {
        Name[0] = '\0';
        Systems = nullptr;
        NumSystems = 0;
    }

    //Cpnstructor with arguments
    Repozitorium(char *Name) {
        strcpy(this->Name, Name);
        NumSystems = 0;
        Systems = nullptr;
    }

    //copy-construcot
    Repozitorium(const Repozitorium &r) {
        strcpy(this->Name, r.Name);
        this->NumSystems = r.NumSystems;
        this->Systems = new OperativenSistem[r.NumSystems];
        for (int i = 0; i < NumSystems; i++) {
            this->Systems[i] = r.Systems[i];
        }
    }

    //operator =
    Repozitorium &operator=(const Repozitorium &r) {
        if (this != &r) {
            delete[] Systems;
            strcpy(this->Name, r.Name);
            this->NumSystems = r.NumSystems;
            this->Systems = new OperativenSistem[r.NumSystems];
            for (int i = 0; i < NumSystems; i++) {
                this->Systems[i] = r.Systems[i];
            }
        }
        return *this;
    }

    //destructor
    ~Repozitorium() {
        delete[] Systems;
    }

    //void pecatiOperativniSistemi()
    void pecatiOperativniSistemi() {
        cout << "Repozitorium: " << Name;
        cout << endl;
        for (int i = 0; i < NumSystems; i++) {
            Systems[i].pecati();
        }
    }

    //void izbrishi(const OperativenSistem &operativenSistem)
    void izbrishi(const OperativenSistem &operativenSistem) {
        int counter = 0;
        OperativenSistem *RemoveSystem = new OperativenSistem[NumSystems];
        for (int i = 0; i < NumSystems; i++) {
            if (Systems[i].ednakviSe(operativenSistem) == 0) {
                RemoveSystem[counter++] = Systems[i];
            }
        }
        delete[] Systems;
        Systems = RemoveSystem;
        NumSystems = counter;
    }

    //(void dodadi(const OperativenSistem &nov)
    void dodadi(const OperativenSistem &nov) {
        int counter = 0;
        OperativenSistem *NewSystem = new OperativenSistem[NumSystems + 1];
        for (int i = 0; i < NumSystems; i++) {
            if (Systems[i].istaFamilija(nov) && Systems[i].Version < nov.Version) {
                NewSystem[i] = nov;
            } else
                NewSystem[counter++] = Systems[i];
        }
        NewSystem[counter++] = nov;
        delete[] Systems;
        Systems = NewSystem;
        NumSystems = counter;
    }

};


int main() {
    char repoName[20];
    cin >> repoName;
    Repozitorium repozitorium = Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin >> brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i < brojOperativniSistemi; i++) {
        cin >> ime;
        cin >> verzija;
        cin >> tip;
        cin >> golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip) tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();
    cin >> ime;
    cin >> verzija;
    cin >> tip;
    cin >> golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip) tip, golemina);
    cout << "=====Brishenje na operativen sistem=====" << endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}

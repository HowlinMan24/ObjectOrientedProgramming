//
// Created by hrist on 4/19/2024.
//
#include <iostream>>
#include <cstring>>

using namespace std;

class Gitara {
private:
    char SerialNumber[25];
    float StockPrice;
    int ManufactureYear;
    char Type[40];
public:
    //default+arguments
    Gitara() {
        SerialNumber[0] = '\0';
        StockPrice = 0.0;
        ManufactureYear = 0;
        Type[0] = '\0';
    }

    Gitara(char *Type, char *SerialNumber, int ManufactureYear, float StockPrice) {
        strcpy(this->SerialNumber, SerialNumber);
        this->StockPrice = StockPrice;
        this->ManufactureYear = ManufactureYear;
        strcpy(this->Type, Type);
    }

    //copy
    Gitara(const Gitara &g) {
        strcpy(this->SerialNumber, g.SerialNumber);
        strcpy(this->Type, g.Type);
        this->StockPrice = g.StockPrice;
        this->ManufactureYear = g.ManufactureYear;
    }

    //operator=
    Gitara &operator=(const Gitara &g) {
        if (this != &g) {
            strcpy(this->SerialNumber, g.SerialNumber);
            strcpy(this->Type, g.Type);
            this->StockPrice = g.StockPrice;
            this->ManufactureYear = g.ManufactureYear;
        }
        return *this;
    }

    //destrucot
    ~Gitara() {}

    //geteri
    char *getTip() {
        return Type;
    }

    char *getSeriski() {
        return SerialNumber;
    }

    int getGodina() {
        return ManufactureYear;
    }

    float getNabavna() {
        return StockPrice;
    }

    //daliisti
    bool daliIsti(Gitara &g) {
        return strcmp(this->SerialNumber, g.SerialNumber) == 0;
    }

    void pecati() {
        cout << SerialNumber << " " << Type << " " << StockPrice << endl;
    }

    friend class Magacin;
};

class Magacin {
private:
    char Name[30];
    char Location[30];
    Gitara *Guitars;
    int NumGuitars;
    int YearOpened;
public:
    //2 in 1 construcot
    Magacin(char *Name = "", char *Location = "", int YearOpened = 0) {
        strcpy(this->Name, Name);
        strcpy(this->Location, Location);
        this->YearOpened = YearOpened;
        NumGuitars = 0;
        Guitars = nullptr;
    }

    //copy
    Magacin(const Magacin &m) {
        strcpy(this->Name, m.Name);
        strcpy(this->Location, m.Location);
        this->YearOpened = m.YearOpened;
        this->NumGuitars = m.NumGuitars;
        this->Guitars = new Gitara[m.NumGuitars];
        for (int i = 0; i < m.NumGuitars; i++) {
            Guitars[i] = m.Guitars[i];
        }
    }

    //opetaor=
    Magacin &operator=(const Magacin &m) {
        if (this != &m) {
            delete[] Guitars;
            strcpy(this->Name, m.Name);
            strcpy(this->Location, m.Location);
            this->YearOpened = m.YearOpened;
            this->NumGuitars = m.NumGuitars;
            this->Guitars = new Gitara[m.NumGuitars];
            for (int i = 0; i < m.NumGuitars; i++) {
                Guitars[i] = m.Guitars[i];
            }
        }
        return *this;
    }

    //destrucot
    ~Magacin() {
        delete[] Guitars;
    }

    //vrednot
    double vrednost() {
        double sum = 0;
        for (int i = 0; i < NumGuitars; i++) {
            sum += Guitars[i].StockPrice;
        }
        return sum;
    }

    //dodadi
    void dodadi(Gitara g) {
        Gitara *NewGuitars = new Gitara[NumGuitars + 1];
        for (int i = 0; i < NumGuitars; i++) {
            NewGuitars[i] = Guitars[i];
        }
        NewGuitars[NumGuitars++] = g;
        delete[] Guitars;
        Guitars = NewGuitars;
    }

    //prodadi
    void prodadi(Gitara g) {
        int counter = 0;
        Gitara *RemoveGuitars = new Gitara[NumGuitars];
        for (int i = 0; i < NumGuitars; i++) {
            if (Guitars[i].daliIsti(g) == 0) {
                RemoveGuitars[counter++] = Guitars[i];
            }
        }
        delete[] Guitars;
        Guitars = RemoveGuitars;
        NumGuitars = counter;
    }

    //void pecati
    void pecati(bool daliNovi) {
        cout << Name << " " << Location << endl;
        if (daliNovi == true) {
            for (int i = 0; i < NumGuitars; i++) {
                if (Guitars[i].getGodina() > YearOpened) {
                    Guitars[i].pecati();
                    //cout<<endl;
                }
            }
        } else {
            for (int i = 0; i < NumGuitars; i++) {
                Guitars[i].pecati();
                // cout<<endl;
            }
        }
    }

};

int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, godina;
    float cena;
    char seriski[50], tip[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Gitara ======" << endl;
        cin >> tip;
        cin >> seriski;
        cin >> godina;
        cin >> cena;
        Gitara g(tip, seriski, godina, cena);
        cout << g.getTip() << endl;
        cout << g.getSeriski() << endl;
        cout << g.getGodina() << endl;
        cout << g.getNabavna() << endl;
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata Magacin so metodot print() ======" << endl;
        Magacin kb("Magacin1", "Lokacija1");
        kb.pecati(false);
    } else if (testCase == 3) {
        cout << "===== Testiranje na klasata Magacin so metodot dodadi() ======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2005);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;
            Gitara g(tip, seriski, godina, cena);
            cout << "gitara dodadi" << endl;
            kb.dodadi(g);
        }
        kb.pecati(true);
    } else if (testCase == 4) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() ======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2012);
        cin >> n;
        Gitara brisi;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip, seriski, godina, cena);
            if (i == 2)
                brisi = g;
            cout << "gitara dodadi" << endl;
            kb.dodadi(g);
        }
        kb.pecati(false);
        kb.prodadi(brisi);
        kb.pecati(false);
    } else if (testCase == 5) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() i pecati(true) ======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2011);
        cin >> n;
        Gitara brisi;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip, seriski, godina, cena);
            if (i == 2)
                brisi = g;
            cout << "gitara dodadi" << endl;
            kb.dodadi(g);
        }
        kb.pecati(true);
        kb.prodadi(brisi);
        cout << "Po brisenje:" << endl;
        Magacin kb3;
        kb3 = kb;
        kb3.pecati(true);
    } else if (testCase == 6) {
        cout << "===== Testiranje na klasata Magacin so metodot vrednost()======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2011);
        cin >> n;
        Gitara brisi;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip, seriski, godina, cena);
            if (i == 2)
                brisi = g;
            kb.dodadi(g);
        }
        cout << kb.vrednost() << endl;
        kb.prodadi(brisi);
        cout << "Po brisenje:" << endl;
        cout << kb.vrednost();
        Magacin kb3;
        kb3 = kb;
    }
    return 0;
}

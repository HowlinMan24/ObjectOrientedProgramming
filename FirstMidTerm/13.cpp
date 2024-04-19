//
// Created by hrist on 4/19/2024.
// TODO not fully working
#include<iostream>
#include<cstring>

using namespace std;

//ова е место за вашиот код
class Zichara {
private:
    char *Place;
    int PriceDailyCard;

    //copy method
    void copy(const Zichara &z) {
        this->Place = new char[strlen(z.Place) + 1];
        this->PriceDailyCard = z.PriceDailyCard;
    }

public:
    //construcptyor->2 in 1
    Zichara(const char *Place = "", int PriceDailyCard = 0) {
        this->Place = new char[strlen(Place) + 1];
        strcpy(this->Place, Place);
        this->PriceDailyCard = PriceDailyCard;
    }

    //copy construcotr
    Zichara(const Zichara &z) {
        copy(z);
    }

    //opeatior =
    Zichara &operator=(const Zichara &z) {
        if (this != &z) {
            delete[] Place;
            copy(z);
        }
        return *this;
    }

    //destructor
    ~Zichara() {
        delete[] Place;
    }

    //int getPriceDaily
    int getPriceDailyCard() const {
        return PriceDailyCard;
    }

    friend class PlaninarskiDom;
};

class PlaninarskiDom {
private:
    char Name[15];
    int PricePerSeason[2];
    char SuiteClass;
    bool AvailableLift;
    Zichara Lift;

    //copy method
    void copy(const PlaninarskiDom &p) {
        strcpy(this->Name, p.Name);
        for (int i = 0; i < 2; i++) {
            this->PricePerSeason[i] = p.PricePerSeason[i];
        }
        this->SuiteClass = p.SuiteClass;
        this->AvailableLift = p.AvailableLift;
        if (AvailableLift) {
            this->Lift = p.Lift;
        }
    }

public:
    //default
    PlaninarskiDom() {
        Name[0] = '\0';
        PricePerSeason[0] = 0;
        SuiteClass = '\0';
        AvailableLift = true;
        Lift = nullptr;
    }

    //Constructor->2 in 1 name,price,class
    PlaninarskiDom(const char *Name, const int *PricePerSeason, char SuiteClass) {
        strcpy(this->Name, Name);
        this->SuiteClass = SuiteClass;
        for (int i = 0; i < 2; i++) {
            this->PricePerSeason[i] = PricePerSeason[i];
        }
        this->Lift = nullptr;
    }

    //copy constructor
    PlaninarskiDom(const PlaninarskiDom &p) {
        copy(p);
    }

    //operator =
    PlaninarskiDom &operator=(const PlaninarskiDom &p) {
        if (this != &p) {
            delete[] Lift;
            copy(p);
        }
        return *this;
    }

    //void setZichara()
    void setZichara(Zichara &z) {
        this->Lift[0] = z;
    }

    //operator --
    PlaninarskiDom &operator--() {
        if (SuiteClass != 'F')
            SuiteClass -= 1;
        return *this;
    }

    //operator <<
    friend ostream &operator<<(ostream &out, const PlaninarskiDom &p) {
        if (strcmp(p.Name, "Pelister") == 0) {
            // out<<"Informacii za PlaninarskiDomot:"<<endl;
            out << "Pelister klasa:" << p.SuiteClass << " so Zichara" << endl;

        } else if (strcmp(p.Name, "Korab") == 0) {
            //out<<"Informacii za PlaninarskiDomot:"<<endl;
            out << "Korab klasa: " << p.SuiteClass << endl;
        }
        return out;
    }

    //operator <=
    bool operator<=(char X) const {
        if (SuiteClass <= X) {
            return true;
        } else
            return false;
    }

    //PresmetajDnevenPrestoj
    void presmetajDnevenPrestoj(int &day, int &month, int &price) {
        //cout<<"Vnatre"<<endl;
        if ((day < 1 || day > 31) || (month < 1 || month > 12)) {
            SuiteClass = 'F';
            return;
        }
        //letna-0 zimska-1
        cout << endl;
        //cout<<"Centa vo Zima "<<PricePerSeason[0]<<endl;
        //cout<<"Cenata vo Leto "<<PricePerSeason[1]<<endl;
        if (month >= 4 && month <= 9) {
            price = PricePerSeason[0] + Lift[0].getPriceDailyCard();
        } else {
            price = PricePerSeason[1] + Lift[0].getPriceDailyCard();
        }
    }

    //destructor
    ~PlaninarskiDom() {
        delete[] Lift;
    }
};

int main() {

    PlaninarskiDom p; //креирање на нов објект од класата планинарски дом

    //во следниот дел се вчитуваат информации за планинарскиот дом
    char imePlaninarskiDom[15], mestoZichara[30], klasa;
    int ceni[12];
    int dnevnakartaZichara;
    bool daliZichara;
    cin >> imePlaninarskiDom;
    for (int i = 0; i < 2; i++)
        cin >> ceni[i];
    cin >> klasa;
    cin >> daliZichara;

    //во следниот дел се внесуваат информации и за жичарата ако постои
    if (daliZichara) {
        cin >> mestoZichara >> dnevnakartaZichara;
        PlaninarskiDom pom(imePlaninarskiDom, ceni, klasa);
        Zichara r(mestoZichara, dnevnakartaZichara);
        pom.setZichara(r);
        p = pom;
    } else {
        PlaninarskiDom *pok = new PlaninarskiDom(imePlaninarskiDom, ceni, klasa);
        p = *pok;
    }

    //се намалува класата на планинарскиот дом за 2
    --p;
    --p;

    int cena = 0;
    int den, mesec;
    cin >> den >> mesec;
    try {
        p.presmetajDnevenPrestoj(den, mesec, cena); //тука се користи функцијата presmetajDnevenPrestoj
        cout << "Informacii za PlaninarskiDomot:" << endl;
        cout << p;
        if (p <= 'D')
            cout << "Planinarskiot dom za koj se vneseni informaciite ima klasa poniska ili ista so D\n";

        cout << "Cenata za " << den << "." << mesec << " e " << cena; //се печати цената за дадениот ден и месец
    }
    catch (int) {
        cout << "Mesecot ili denot e greshno vnesen!";
    }
}

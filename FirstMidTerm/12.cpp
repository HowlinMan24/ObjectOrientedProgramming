//
// Created by hrist on 4/19/2024.
//
#include <iostream>
#include <cstring>

using namespace std;

class Pica {
private:
    char PizzaName[15];
    int Price;
    char *Ingridients;
    int Discount;

    //void copy
    void copy(const Pica &other) {
        strcpy(this->PizzaName, other.PizzaName);
        this->Price = other.Price;
        this->Ingridients = new char[strlen(other.Ingridients) + 1];
        strcpy(this->Ingridients, other.Ingridients);
        this->Discount = other.Discount;
    }

public:
    //2 in 1 consgructor
    Pica(char *PizzaName = (char *) "", int Price = 0, char *Ingridients = (char *) "", int Discount = 0) {
        strcpy(this->PizzaName, PizzaName);
        this->Price = Price;
        this->Ingridients = new char[strlen(Ingridients) + 1];
        strcpy(this->Ingridients, Ingridients);
        this->Discount = Discount;
    }

    //copy constrcutor
    Pica(const Pica &other) {
        copy(other);
    }

    //operator =
    Pica &operator=(const Pica &other) {
        if (this != &other) {
            delete[] Ingridients;
            copy(other);
        }
        return *this;
    }

    //destructor
    ~Pica() {
        delete[] Ingridients;
    }

    //void pecati
    friend ostream &operator<<(ostream &out, Pica &other) {
        out << other.PizzaName << " - " << other.Ingridients << ", " << other.Price << " "
            << (other.Price - (other.Price * (other.Discount) / 100));
        return out;
    }

    //bool isti se
    bool istise(Pica &p) {
        return strcmp(this->Ingridients, p.Ingridients);
    }

    friend class Picerija;
};

class Picerija {
private:
    char PizzeriaName[15];
    Pica *Pizzas;
    int NumberOfPizzas;

    //void copy
    void copy(const Picerija &other) {
        strcpy(this->PizzeriaName, other.PizzeriaName);
        this->NumberOfPizzas = other.NumberOfPizzas;
        this->Pizzas = new Pica[other.NumberOfPizzas];
        for (int i = 0; i < other.NumberOfPizzas; i++) {
            this->Pizzas[i] = other.Pizzas[i];
        }
    }

public:
    //2 in 1 constrtor
    Picerija(char *PizzeriaName = (char *) "") {
        strcpy(this->PizzeriaName, PizzeriaName);
        this->NumberOfPizzas = 0;
        this->Pizzas = new Pica[0];
    }

    //copy constrotr
    Picerija(const Picerija &other) {
        copy(other);
    }

    //operator =
    Picerija &operator=(const Picerija &other) {
        if (this != &other) {
            delete[] Pizzas;
            copy(other);
        }
        return *this;
    }

    //dodadi pica
    Picerija &operator+=(Pica &p) {
        int flag = 1, counter = 0;
        /*for(int i=0;i<NumberOfPizzas;i++)
        {
            if(Pizzas[i].istise(p)==0)
            {
                flag=0;
                break;
            }
        }*/
        Pica *NewPizza = new Pica[NumberOfPizzas + 1];
        for (int i = 0; i < NumberOfPizzas; i++) {
            if (Pizzas[i].istise(p))
                NewPizza[counter++] = Pizzas[i];
        }
        NewPizza[counter++] = p;
        delete[] Pizzas;
        Pizzas = NewPizza;
        NumberOfPizzas = counter;
        return *this;
    }

    //void picinapromocija
    void piciNaPromocija() {
        for (int i = 0; i < NumberOfPizzas; i++) {
            if (Pizzas[i].Discount > 0 && Pizzas[i].Discount < 100) {
                cout << Pizzas[i] << endl;
            }
        }
    }

    //set ime
    void setIme(char *Name) {
        strcpy(this->PizzeriaName, Name);
    }

    //get ime
    char *getIme() {
        return PizzeriaName;
    }

    //destructor
    ~Picerija() {
        delete[] Pizzas;
    }

};

int main() {

    int n;
    char ime[15];
    cin >> ime;
    cin >> n;

    Picerija p1(ime);
    for (int i = 0; i < n; i++) {
        char imp[100];
        cin.get();
        cin.getline(imp, 100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki, 100);
        int popust;
        cin >> popust;
        Pica p(imp, cena, sostojki, popust);
        p1 += p;
    }

    Picerija p2 = p1;
    cin >> ime;
    p2.setIme(ime);
    char imp[100];
    cin.get();
    cin.getline(imp, 100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki, 100);
    int popust;
    cin >> popust;
    Pica p(imp, cena, sostojki, popust);
    p2 += p;

    cout << p1.getIme() << endl;
    cout << "Pici na promocija:" << endl;
    p1.piciNaPromocija();

    cout << p2.getIme() << endl;
    cout << "Pici na promocija:" << endl;
    p2.piciNaPromocija();

    return 0;
}

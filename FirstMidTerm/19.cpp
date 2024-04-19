//
// Created by hrist on 4/19/2024.
//
#include <iostream>
#include <cstring>

using namespace std;

class IceCream {
private:
    char *Name;
    char Items[100];
    float Price;
    int Discount;
public:
    //constructor
    IceCream(const char *Name = "", const char *Items = "", float Price = 0.0) {
        this->Name = new char[strlen(Name) + 1];
        strcpy(this->Name, Name);
        strcpy(this->Items, Items);
        this->Price = Price;
        Discount = 0;
    }

    //copy
    IceCream(const IceCream &s) {
        this->Name = new char[strlen(s.Name) + 1];
        strcpy(this->Name, s.Name);
        strcpy(this->Items, s.Items);
        this->Price = s.Price;
        this->Discount = s.Discount;
    }

    //opeeator =
    IceCream &operator=(const IceCream &s) {
        if (this != &s) {
            delete[] Name;
            this->Name = new char[strlen(s.Name) + 1];
            strcpy(this->Name, s.Name);
            strcpy(this->Items, s.Items);
            this->Price = s.Price;
            this->Discount = s.Discount;
        }
        return *this;
    }

    //destruct
    ~IceCream() {
        delete[] Name;
    }

    //operator <<
    friend ostream &operator<<(ostream &os, const IceCream &cream) {
        os << cream.Name << ": " << cream.Items << " " << cream.Price << " ";
        if (cream.Discount > 0) {
            os << "(" << cream.Price - (cream.Price * (cream.Discount / 100.0)) << ")";
        }
        return os;
    }

    //operator ++ ->prefiks
    IceCream &operator++() {
        Discount += 5;
        return *this;
    }

    //operator +
    IceCream &operator+(const char *addon) {
        char *Temp = new char[strlen(Name) + strlen(addon) + 4];
        strcpy(Temp, Name);
        strcat(Temp, " + ");
        strcat(Temp, addon);
        delete[] Name;
        Name = Temp;
        Price += 10;
        return *this;
    }

    //setDiscount
    void setDiscount(int discount) {
        this->Discount = discount;
    }

    //setname
    void setName(const char *name) {
        delete[] Name;
        Name = new char[strlen(name) + 1];
        strcpy(this->Name, name);
    }
};

class IceCreamShop {
private:
    char ShopName[50];
    IceCream *Creams;
    int NumOfIcecreams;

    //copy method
    void copy(const IceCreamShop &ics) {
        strcpy(this->ShopName, ics.ShopName);
        this->NumOfIcecreams = ics.NumOfIcecreams;
        this->Creams = new IceCream[ics.NumOfIcecreams];
        for (int i = 0; i < ics.NumOfIcecreams; i++) {
            this->Creams[i] = ics.Creams[i];
        }
    }

public:
    //2 in 1
    IceCreamShop(const char *ShopName) {
        strcpy(this->ShopName, ShopName);
        Creams = new IceCream[0];
        NumOfIcecreams = 0;
    }

    //copy constructor
    IceCreamShop(const IceCreamShop &ics) {
        copy(ics);
    }

    //opeator =
    IceCreamShop &operator=(const IceCreamShop &ics) {
        if (this != &ics) {
            delete[] Creams;
            copy(ics);
        }
        return *this;
    }

    //opetaor +=
    IceCreamShop &operator+=(const IceCream &ice) {
        IceCream *NewIceCream = new IceCream[NumOfIcecreams + 1];
        for (int i = 0; i < NumOfIcecreams; i++) {
            NewIceCream[i] = Creams[i];
        }
        NewIceCream[NumOfIcecreams++] = ice;
        delete[] Creams;
        Creams = NewIceCream;
        return *this;
    }

    //opeator <<
    friend ostream &operator<<(ostream &out, IceCreamShop &ics) {
        out << ics.ShopName << endl;
        for (int i = 0; i < ics.NumOfIcecreams; i++) {
            out << ics.Creams[i] << endl;
        }
        return out;
    }

    //destrucot
    ~IceCreamShop() {
        delete[] Creams;
    }
};

int main() {
    char name[100];
    char ingr[100];
    float price;
    int discount;

    int testCase;

    cin >> testCase;
    cin.get();
    if (testCase == 1) {
        cout << "====== TESTING IceCream CLASS ======" << endl;
        cin.getline(name, 100);
        cin.getline(ingr, 100);
        cin >> price;
        cin >> discount;
        cout << "CONSTRUCTOR" << endl;
        IceCream ic1(name, ingr, price);
        ic1.setDiscount(discount);
        cin.get();
        cin.getline(name, 100);
        cin.getline(ingr, 100);
        cin >> price;
        cin >> discount;
        IceCream ic2(name, ingr, price);
        ic2.setDiscount(discount);
        cout << "OPERATOR <<" << endl;
        cout << ic1 << endl;
        cout << ic2 << endl;
        cout << "OPERATOR ++" << endl;
        ++ic1;
        cout << ic1 << endl;
        cout << "OPERATOR +" << endl;
        IceCream ic3 = ic2 + "chocolate";
        cout << ic3 << endl;
    } else if (testCase == 2) {
        cout << "====== TESTING IceCream CONSTRUCTORS ======" << endl;
        cin.getline(name, 100);
        cin.getline(ingr, 100);
        cin >> price;
        //cin >> discount;
        cout << "CONSTRUCTOR" << endl;
        IceCream ic1(name, ingr, price);
        cout << ic1 << endl;
        cout << "COPY CONSTRUCTOR" << endl;
        IceCream ic2(ic1);
        cin.get();
        cin.getline(name, 100);
        ic2.setName(name);
        cout << ic1 << endl;
        cout << ic2 << endl;
        cout << "OPERATOR =" << endl;
        ic1 = ic2;
        cin.getline(name, 100);
        ic2.setName(name);
        cout << ic1 << endl;
        cout << ic2 << endl;

        cin >> discount;
        ic1.setDiscount(discount);


    } else if (testCase == 3) {
        cout << "====== TESTING IceCreamShop ======" << endl;
        char icsName[50];
        cin.getline(icsName, 100);
        cout << "CONSTRUCTOR" << endl;
        IceCreamShop ics(icsName);
        int n;
        cin >> n;
        cout << "OPERATOR +=" << endl;
        for (int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name, 100);
            cin.getline(ingr, 100);
            cin >> price;
            IceCream ic(name, ingr, price);
            ics += ic;
        }
        cout << ics;
    } else if (testCase == 4) {
        cout << "====== TESTING IceCreamShop CONSTRUCTORS ======" << endl;
        char icsName[50];
        cin.getline(icsName, 100);
        IceCreamShop ics(icsName);
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name, 100);
            cin.getline(ingr, 100);
            cin >> price;
            IceCream ic(name, ingr, price);
            ics += ic;
        }
        IceCream x("FINKI fruits", "strawberry ice cream, raspberry ice cream, blueberry ice cream", 60);
        IceCreamShop icp = ics;
        ics += x;
        cout << ics << endl;
        cout << icp << endl;
    }


    return 0;
}
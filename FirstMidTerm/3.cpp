//
// Created by hrist on 4/19/2024.
//
#include<iostream>
#include<cstring>

using namespace std;

// vasiot kod za klasite ovde

class StockRecord {
private:
    char ID[12];
    char NameCompany[50];
    double PriceItemsBought;
    double CurrentPrice;
    int NumStocks;
public:
    //defaukt
    StockRecord() {
        ID[0] = '\0';
        NameCompany[0] = '\0';
        PriceItemsBought = 0.0;
        CurrentPrice = 0.0;
        NumStocks = 0;
    }

    //With arguments
    StockRecord(char *ID, char *NameCompany, double PriceItemsBought, int NumStocks) {
        strcpy(this->ID, ID);
        strcpy(this->NameCompany, NameCompany);
        this->PriceItemsBought = PriceItemsBought;
        this->NumStocks = NumStocks;
        //this->CurrentPrice=0.0;
    }

    //copy construcyot
    StockRecord(const StockRecord &s) {
        strcpy(this->ID, s.ID);
        strcpy(this->NameCompany, s.NameCompany);
        this->PriceItemsBought = s.PriceItemsBought;
        this->NumStocks = s.NumStocks;
        this->CurrentPrice = s.CurrentPrice;
    }

    //set price
    void setNewPrice(double c) {
        this->CurrentPrice = c;
    }

    //value()
    double value() {
        return CurrentPrice * NumStocks;
    }

    //profit()
    double profit() {
        return NumStocks * (CurrentPrice - PriceItemsBought);
    }

    //opeeator <<
    friend ostream &operator<<(ostream &out, StockRecord &s) {
        out << s.NameCompany << " " << s.NumStocks << " " << s.PriceItemsBought << " " << s.CurrentPrice << " "
            << s.profit() << endl;
    }

    friend class Client;
};


class Client {
private:
    char NameClient[60];
    int ID;
    StockRecord *Companies;
    int NumCompanies;

    //copy stuff
    void Copy(const Client &c) {
        strcpy(this->NameClient, c.NameClient);
        this->ID = c.ID;
        this->NumCompanies = c.NumCompanies;
        this->Companies = new StockRecord[c.NumCompanies];
        for (int i = 0; i < NumCompanies; i++) {
            this->Companies[i] = c.Companies[i];
        }
    }

public:
    //defalut
    Client() {
        NameClient[0] = '\0';
        ID = 0;
        Companies = new StockRecord[0];
        NumCompanies = 0;
    }

    //arguments
    Client(char *NameClient, int ID) {
        strcpy(this->NameClient, NameClient);
        this->ID = ID;
        this->NumCompanies = 0;
        this->Companies = new StockRecord[0];
    }

    //copy
    Client(const Client &c) {
        Copy(c);
    }

    //operator =
    Client &operator=(const Client &c) {
        if (this != &c) {
            delete[] Companies;
            Copy(c);
        }
        return *this;
    }

    //destructor
    ~Client() {
        delete[] Companies;
    }

    //totalvalue
    double totalValue() {
        double sum = 0.0;
        for (int i = 0; i < NumCompanies; i++) {
            sum += Companies[i].value();
        }
        return sum;
    }

    //operator +=
    Client &operator+=(StockRecord &s) {
        StockRecord *NewCompany = new StockRecord[NumCompanies + 1];
        for (int i = 0; i < NumCompanies; i++) {
            NewCompany[i] = Companies[i];
        }
        NewCompany[NumCompanies++] = s;
        delete[] Companies;
        Companies = NewCompany;
        return *this;
    }

    //operator <<
    friend ostream &operator<<(ostream &out, Client &c) {
        out << c.ID << " " << c.totalValue() << endl;
        for (int i = 0; i < c.NumCompanies; i++) {
            cout << c.Companies[i];
        }
    }


};

// ne menuvaj vo main-ot

int main() {

    int test;
    cin >> test;

    if (test == 1) {
        double price;
        cout << "=====TEST NA KLASATA StockRecord=====" << endl;
        StockRecord sr("1", "Microsoft", 60.0, 100);
        cout << "Konstruktor OK" << endl;
        cin >> price;
        sr.setNewPrice(price);
        cout << "SET metoda OK" << endl;
    } else if (test == 2) {
        cout << "=====TEST NA METODITE I OPERATOR << OD KLASATA StockRecord=====" << endl;
        char id[12], company[50];
        double price, newPrice;
        int n, shares;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> id;
            cin >> company;
            cin >> price;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(id, company, price, shares);
            sr.setNewPrice(newPrice);
            cout << sr.value() << endl;
            cout << sr;
        }
    } else if (test == 3) {
        cout << "=====TEST NA KLASATA Client=====" << endl;
        char companyID[12], companyName[50], clientName[50];
        int clientID, n, shares;
        double oldPrice, newPrice;
        bool flag = true;
        cin >> clientName;
        cin >> clientID;
        cin >> n;
        Client c(clientName, clientID);
        cout << "Konstruktor OK" << endl;
        for (int i = 0; i < n; ++i) {
            cin >> companyID;
            cin >> companyName;
            cin >> oldPrice;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(companyID, companyName, oldPrice, shares);
            sr.setNewPrice(newPrice);
            c += sr;
            if (flag) {
                cout << "Operator += OK" << endl;
                flag = false;
            }
        }
        cout << c;
        cout << "Operator << OK" << endl;
    }
    return 0;

}

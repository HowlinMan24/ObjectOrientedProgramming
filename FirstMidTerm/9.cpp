//
// Created by hrist on 4/19/2024.
//
#include <iostream>
#include <cstring>

using namespace std;
struct Laptop {
    char Manufacturer[100];
    float SizeOfMonitor;
    bool IsTouch;
    int Price;
};
struct ITStore {
    char StoreName[100];
    char Location[100];
    Laptop Laptops[100];
    int NumberOfLaptops;
};

void Read(ITStore store[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        cin >> store[i].StoreName;
        cin >> store[i].Location;
        cin >> store[i].NumberOfLaptops;
        for (j = 0; j < store[i].NumberOfLaptops; j++) {
            cin >> store[i].Laptops[j].Manufacturer;
            cin >> store[i].Laptops[j].SizeOfMonitor;
            cin >> store[i].Laptops[j].IsTouch;
            cin >> store[i].Laptops[j].Price;
        }
    }
}

void print(ITStore store[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        cout << store[i].StoreName << " " << store[i].Location << endl;
        for (j = 0; j < store[i].NumberOfLaptops; j++) {
            cout << store[i].Laptops[j].Manufacturer << " " << store[i].Laptops[j].SizeOfMonitor << " "
                 << store[i].Laptops[j].Price << endl;
        }
    }
}

void najeftina_ponuda(ITStore store[], int n) {
    int i, j, flag = 1, min_j = 0, min_i = 0, min;
    //min=store[0].Laptops[0].Price;
    for (i = 0; i < n; i++) {
        for (j = 0; j < store[i].NumberOfLaptops; j++) {
            if (store[i].Laptops[j].IsTouch == 1) {
                //if(min>store[i].Laptops[j].Price)
                //{
                min = store[i].Laptops[j].Price;
                min_i = i;
                min_j = j;
                flag = 0;
                //}
            }
            if (flag == 0)
                break;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < store[i].NumberOfLaptops; j++) {
            if (store[i].Laptops[j].IsTouch == 1) {
                if (min > store[i].Laptops[j].Price) {
                    min = store[i].Laptops[j].Price;
                    min_i = i;
                    min_j = j;
                }
            }
        }
    }
    cout << "Najeftina ponuda ima prodavnicata:" << endl;
    cout << store[min_i].StoreName << " " << store[min_i].Location << endl;
    cout << "Najniskata cena iznesuva: " << store[min_i].Laptops[min_j].Price;
}

int main() {
    ITStore s[100];
    int n, i;
    cin >> n;
    Read(s, n);
    print(s, n);
    najeftina_ponuda(s, n);
}
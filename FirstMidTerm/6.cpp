//
// Created by hrist on 4/19/2024.
//
#include<iostream>
#include <cstring>

using namespace std;

typedef struct Voz {
    char Relation[50];
    float DistanceTraveled;
    int NumberPeople;
} Voz;

typedef struct ZeleznickaStanica {
    char Location[20];
    Voz Trains[30];
    int NumTrains;
} ZeleznickaStanica;

void najkratkaRelacija(ZeleznickaStanica *zs, int n, char *grad) {
    int i, j, maxI = 0, maxJ = 0;
    float maxDistance = 99999;
    for (int i = 0; i < n; i++) {
        for (j = 0; j < zs[i].NumTrains; j++) {
            if (strcmp(zs[i].Location, grad) == 0) {
                if (zs[i].Trains[j].DistanceTraveled <= maxDistance) {
                    maxI = i;
                    maxJ = j;
                    maxDistance = zs[i].Trains[j].DistanceTraveled;
                }
            }
        }
    }
    cout << "Najkratka relacija: " << zs[maxI].Trains[maxJ].Relation << " (" << zs[maxI].Trains[maxJ].DistanceTraveled
         << " km)";
}

int main() {

    int n;
    cin >> n; //se cita brojot na zelezlnichki stanici

    ZeleznickaStanica zStanica[100];
    for (int i = 0; i < n; i++) {
        //se citaat infomracii za n zelezlnichkite stanici i se zacuvuvaat vo poleto zStanica
        cin >> zStanica[i].Location;
        cin >> zStanica[i].NumTrains;
        for (int j = 0; j < zStanica[i].NumTrains; j++) {
            cin >> zStanica[i].Trains[j].Relation;
            cin >> zStanica[i].Trains[j].DistanceTraveled;
            cin >> zStanica[i].Trains[j].NumberPeople;
        }

    }

    char grad[25];
    cin >> grad;

    najkratkaRelacija(zStanica, n, grad);
    return 0;
}

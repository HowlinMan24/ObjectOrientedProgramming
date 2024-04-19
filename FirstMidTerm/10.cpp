//
// Created by hrist on 4/19/2024.
//
#include <iostream>
#include <cstring>

using namespace std;
struct Igrac {
    char Username[15];
    int LevelReached;
    int PointsGathered;
};
struct KompjuterskaIgra {
    char GameName[20];
    Igrac Players[30];
    int NumberOfPlayers;
};

void Read(KompjuterskaIgra Games[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        cin >> Games[i].GameName;
        cin >> Games[i].NumberOfPlayers;
        for (j = 0; j < Games[i].NumberOfPlayers; j++) {
            cin >> Games[i].Players[j].Username;
            cin >> Games[i].Players[j].LevelReached;
            cin >> Games[i].Players[j].PointsGathered;
        }
    }
}

void najdobarIgrac(KompjuterskaIgra *lista, int n) {
    int i, j, max_i = 0, max, maxPoints, max_j;
    max = lista[0].NumberOfPlayers;
    for (i = 0; i < n; i++) {
        if (lista[i].NumberOfPlayers > max) {
            max = lista[i].NumberOfPlayers;
            max_i = i;
        }
    }
    maxPoints = lista[max_i].Players[0].PointsGathered;
    max_j = 0;
    for (j = 0; j < lista[max_i].NumberOfPlayers; j++) {
        if (lista[max_i].Players[j].PointsGathered > maxPoints) {
            maxPoints = lista[max_i].Players[j].PointsGathered;
            max_j = j;
        } else if (lista[max_i].Players[j].PointsGathered > maxPoints) {
            maxPoints = lista[max_i].Players[j].PointsGathered;
            max_j = j;
        }
    }
    cout << "Najdobar igrac e igracot so korisnicko ime " << lista[max_i].Players[max_j].Username
         << " koj ja igra igrata " << lista[max_i].GameName;
}

int main() {
    KompjuterskaIgra Games[100];
    int n, i, j;
    cin >> n;
    Read(Games, n);
    najdobarIgrac(Games, n);
    return 0;
}
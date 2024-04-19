//
// Created by hrist on 4/19/2024.
//
#include <stdio.h>
#include <string.h>

typedef struct Vozenje {
    char RideName[100];
    int Duration;
    float Price;
    int StudentDiscount;
} Vozenje;

typedef struct ZabavenPark {
    char ParkName[100];
    char Location[100];
    Vozenje Rides[100];
    int NumRides;
} ZabavenPark;

void pecati(ZabavenPark *ff, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %s\n", ff[i].ParkName, ff[i].Location);
        for (int j = 0; j < ff[i].NumRides; j++) {
            printf("%s %d %.2f\n", ff[i].Rides[j].RideName, ff[i].Rides[j].Duration, ff[i].Rides[j].Price);
        }
    }
}

void najdobar_park(ZabavenPark *ff, int n) {
    int i, j, maxI = 0, maxJ = 0, counter = 0;
    int maxTime = 0, Time = 0, maxCounter = 0;
    for (i = 0; i < n; i++) {
        counter = 0;
        Time = 0;
        for (j = 0; j < ff[i].NumRides; j++) {
            if (ff[i].Rides[j].StudentDiscount) {
                counter++;
            }
            Time += ff[i].Rides[j].Duration;
        }
        if (counter > maxCounter) {
            maxI = i;
            maxCounter = counter;
            maxTime = Time;
            //printf("\n%d %d \n",counter)
        } else if (counter == maxCounter) {
            if (Time > maxTime) {
                maxI = i;
                maxCounter = counter;
                maxTime = Time;
            }
        }
    }
    printf("Najdobar park: %s %s", ff[maxI].ParkName, ff[maxI].Location);
}


int main() {
    int i, j, n, broj;
    //kreiraj niza od maksimum 100 zabavni parkovi
    ZabavenPark ff[100];
    scanf("%d", &n);
    //citanje na podatocite
    for (i = 0; i < n; i++) {
        scanf("%s", ff[i].ParkName);
        scanf("%s", ff[i].Location);
        scanf("%d", &ff[i].NumRides);
        for (j = 0; j < ff[i].NumRides; j++) {
            scanf("%s", ff[i].Rides[j].RideName);
            scanf("%d", &ff[i].Rides[j].Duration);
            scanf("%f", &ff[i].Rides[j].Price);
            scanf("%d", &ff[i].Rides[j].StudentDiscount);
        }
    }
    pecati(ff, n);
    najdobar_park(ff, n);

    return 0;
}

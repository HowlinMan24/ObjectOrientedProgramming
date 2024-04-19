//
// Created by hrist on 4/19/2024.
//
#include <stdio.h>

typedef struct SkiLift {
    char Lift[15];
    int Users;
    int InUse;;
} SkiLift;
typedef struct SkiCenter {
    char Center[20];
    char Country[20];
    SkiLift SkiLifts[20];
    int NumberLifts;
} SkiCenter;

void najgolemKapacitet(SkiCenter ski[], int n) {
    int i, j, max, totalcapacity, max_lift;
    int counter, capacity;
    max = 0;
    totalcapacity = 0;
    int flag = 1;
    for (i = 0; i < n; i++) {
        counter = 0;
        capacity = 0;
        for (j = 0; j < ski[i].NumberLifts; j++) {
            if (ski[i].SkiLifts[j].InUse) {
                capacity += ski[i].SkiLifts[j].Users;
                counter++;
            }
        }
        //  printf("Capacity: %d Counter: %d\n",capacity,counter);
        if (capacity > totalcapacity) {
            max = counter;
            max_lift = i;
            totalcapacity = capacity;
            //flag=0;
        } else if (capacity == totalcapacity) {
            if (counter > max) {
                max = counter;
                max_lift = i;
                totalcapacity = capacity;
            }
        }
        // printf("Counter: %d Totalcapacity:%d\n",max,totalcapacity);
    }
    printf("%s\n%s\n%d", ski[max_lift].Center, ski[max_lift].Country, totalcapacity);
}

int main() {
    SkiCenter ski[20];
    int i, j, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", ski[i].Center);
        scanf("%s", ski[i].Country);
        scanf("%d", &ski[i].NumberLifts);
        for (j = 0; j < ski[i].NumberLifts; j++) {
            scanf("%s", ski[i].SkiLifts[j].Lift);
            scanf("%d", &ski[i].SkiLifts[j].Users);
            scanf("%d", &ski[i].SkiLifts[j].InUse);
        }
    }
    najgolemKapacitet(ski, n);
    return 0;
}

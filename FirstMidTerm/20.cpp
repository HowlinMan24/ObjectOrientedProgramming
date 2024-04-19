//
// Created by hrist on 4/19/2024.
//
#include<stdio.h>

typedef struct Pacient {
    char NameSurname[100];
    int Insurance;
    int NumReviews;
} Pacient;

typedef struct MaticenDokotor {
    char NameDoctor[100];
    int NumPacients;
    Pacient Pacients[200];
    float Price;
} doktor;

void najuspesen_doktor(doktor *doc, int n) {
    int i, j, maxI = 0, totalreviews = 0, reviews = 0, privateReviews = 0;
    float sum = 0, maxSum = 0;
    for (i = 0; i < n; i++) {
        //sum=0;
        reviews = 0;
        privateReviews = 0;
        for (j = 0; j < doc[i].NumPacients; j++) {
            if (doc[i].Pacients[j].Insurance == 0) {
                //sum+=doc[i].Price*doc[i].Pacients[j].NumReviews;
                privateReviews += doc[i].Pacients[j].NumReviews;
            }
            reviews += doc[i].Pacients[j].NumReviews;
        }
        sum = privateReviews * doc[i].Price;
        if (sum > maxSum) {
            maxSum = sum;
            maxI = i;
            totalreviews = reviews;
        } else if (sum == maxSum) {
            if (reviews > totalreviews) {
                maxSum = sum;
                maxI = i;
                totalreviews = reviews;
            }
        }
    }
    printf("%s %.2f %d", doc[maxI].NameDoctor, maxSum, totalreviews);
}

int main() {
    int i, j, n, broj;
    doktor md[200];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", md[i].NameDoctor);
        scanf("%d", &md[i].NumPacients);
        scanf("%f", &md[i].Price);
        for (j = 0; j < md[i].NumPacients; j++) {
            scanf("%s", md[i].Pacients[j].NameSurname);
            scanf("%d", &md[i].Pacients[j].Insurance);
            scanf("%d", &md[i].Pacients[j].NumReviews);
        }
    }

    najuspesen_doktor(md, n);
    return 0;
}

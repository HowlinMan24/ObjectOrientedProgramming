//
// Created by hrist on 4/19/2024.
//
#include <stdio.h>
#include <string.h>

typedef struct Laptop {
    char Manufacturer[100];
    float SizeInch;
    int Touch;
    int Price;
} Laptop;

typedef struct ITStore {
    char StoreName[100];
    char Location[100];
    Laptop AvailableLaptop[100];
    int Elements;
} ITStore;

void print(ITStore *s, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("%s %s\n", s[i].StoreName, s[i].Location);
        for (j = 0; j < s[i].Elements; j++) {
            printf("%s %g %d\n", s[i].AvailableLaptop[j].Manufacturer, s[i].AvailableLaptop[j].SizeInch,
                   s[i].AvailableLaptop[j].Price);
        }
    }
}

void najeftina_ponuda(ITStore *s, int n) {
    int i, j, minI = 0, minJ = 0, minPrice = 0, flag = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < s[i].Elements; j++) {
            if (s[i].AvailableLaptop[j].Touch) {
                minI = i;
                minJ = j;
                minPrice = s[i].AvailableLaptop[j].Price;
                flag = 1;
            }
        }
        if (flag)
            break;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < s[i].Elements; j++) {
            if (s[i].AvailableLaptop[j].Touch && minPrice > s[i].AvailableLaptop[j].Price) {
                minI = i;
                minJ = j;
                minPrice = s[i].AvailableLaptop[j].Price;
            }
        }
    }
    printf("Najeftina ponuda ima prodavnicata:\n%s %s\n", s[minI].StoreName, s[minI].Location);
    printf("Najniskata cena iznesuva: %d", minPrice);
}


int main() {
    ITStore s[100];
    int n, i, j;
    scanf("%d", &n); //broj na IT prodavnici

    //vnesuvanje na prodavnicite edna po edna, zaedno so raspolozlivite laptopvi vo niv
    for (i = 0; i < n; i++) {
        scanf("%s", s[i].StoreName);
        scanf("%s", s[i].Location);
        scanf("%d", &s[i].Elements);
        for (j = 0; j < s[i].Elements; j++) {
            scanf("%s", s[i].AvailableLaptop[j].Manufacturer);
            scanf("%f", &s[i].AvailableLaptop[j].SizeInch);
            scanf("%d", &s[i].AvailableLaptop[j].Touch);
            scanf("%d", &s[i].AvailableLaptop[j].Price);
        }

    }


    //pecatenje na site prodavnici




    //povik na glavnata metoda
    print(s, n);
    najeftina_ponuda(s, n);

    return 0;
}

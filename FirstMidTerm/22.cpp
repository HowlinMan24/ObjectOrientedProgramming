//
// Created by hrist on 4/19/2024.
//
#include <stdio.h>
#include <string.h>

typedef struct Proizvod {
    char Barcode[20];
    int Price;
    int AvailableProducts;
} Proizvod;

typedef struct Narachka {
    char Name[15];
    Proizvod Proizvodi[10];
    int OrderedProducts[10];
    int NumberOfProducts;
} Narachka;

void pecatiFaktura(Narachka naracka) {
    printf("Faktura za %s\n", naracka.Name);
    int i, j, flag = 1, total = 0, totalprice = 0;
    for (i = 0; i < naracka.NumberOfProducts; i++) {
        if (naracka.Proizvodi[i].AvailableProducts >= naracka.OrderedProducts[i]) {

        } else {
            flag = 0;
            break;
        }
    }

    Proizvod temp;

    for (i = 0; i < naracka.NumberOfProducts; i++) {
        for (j = 0; j < naracka.NumberOfProducts; j++) {
            if (strcmp(naracka.Proizvodi[i].Barcode, naracka.Proizvodi[j].Barcode) < 0) {
                temp = naracka.Proizvodi[i];
                naracka.Proizvodi[i] = naracka.Proizvodi[j];
                naracka.Proizvodi[j] = temp;
            }
        }
    }

    if (flag) {
        for (i = 0; i < naracka.NumberOfProducts; i++) {
            totalprice = naracka.Proizvodi[i].Price * naracka.OrderedProducts[i];
            printf("%s %d %d %d\n", naracka.Proizvodi[i].Barcode, naracka.Proizvodi[i].Price,
                   naracka.OrderedProducts[i], totalprice);
            total += totalprice;
        }
    }

    if (flag)
        printf("Vkupnata suma na fakturata e %d", total);
    else
        printf("Fakturata ne moze da se izgotvi");
}

int main() {
    Narachka naracka;
    int i, j;
    scanf("%s", naracka.Name);
    scanf("%d", &naracka.NumberOfProducts);
    int n = naracka.NumberOfProducts;
    for (i = 0; i < n; i++) {
        scanf("%s", naracka.Proizvodi[i].Barcode);
        scanf("%d", &naracka.Proizvodi[i].Price);
        scanf("%d", &naracka.Proizvodi[i].AvailableProducts);
    }
    for (j = 0; j < n; j++) {
        scanf("%d", &naracka.OrderedProducts[j]);
    }
    pecatiFaktura(naracka);
    //printf("Faktura za %s",naracka.Name);
    return 0;
}
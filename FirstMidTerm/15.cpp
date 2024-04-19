//
// Created by hrist on 4/19/2024.
//
#include <stdio.h>
#include <string.h>

#define NEDELI 4
#define DENOVI 5

// ovde strukturata RabotnaNedela

typedef struct RabotnaNedela {
    int casovi[5];
    int NumberOfWeek;
} RN;

// ovde strukturata Rabotnik

typedef struct Rabotnik {
    char ime[50];
    RN nedeli[NEDELI];
} R;

// ovde funkciite

/*int maxNedela(Rabotnik *r)
{

}*/
void table(R *r, int n) {
    int i, j, k, vkupno, nedelivkupno;
    printf("Rab\t1\t2\t3\t4\tVkupno\n");
    for (i = 0; i < n; i++) {
        vkupno = 0;
        printf("%s\t", r[i].ime);
        for (j = 0; j < NEDELI; j++) {
            nedelivkupno = 0;
            for (k = 0; k < DENOVI; k++) {
                nedelivkupno += r[i].nedeli[j].casovi[k];
            }
            printf("%d\t", nedelivkupno);
            vkupno += nedelivkupno;
        }
        printf("%d\n", vkupno);
    }
}

int maxNedela(R *r) {
    int i, j, k, vkupno, nedelivkupno, max_j = 0, max = 0;
    for (j = 0; j < NEDELI; j++) {
        //vkupno=0;
        nedelivkupno = 0;
        for (k = 0; k < DENOVI; k++) {
            nedelivkupno += r->nedeli[j].casovi[k];
        }
        //vkupno+=nedelivkupno;
        if (max < nedelivkupno) {
            max = nedelivkupno;
            max_j = j + 1;
        }
    }
    return max_j;
}

int main() {
    int n;
    scanf("%d", &n);
    R rabotnici[n];
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%s", rabotnici[i].ime);
        int j;
        for (j = 0; j < NEDELI; ++j) {
            int k;
            for (k = 0; k < DENOVI; ++k) {
                scanf("%d", &rabotnici[i].nedeli[j].casovi[k]);
            }

        }
    }
    printf("TABLE\n");
    table(rabotnici, n);
    printf("MAX NEDELA NA RABOTNIK: %s\n", rabotnici[n / 2].ime);
    printf("%d\n", maxNedela(&rabotnici[n / 2]));
    return 0;
}

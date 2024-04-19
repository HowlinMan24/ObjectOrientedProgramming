//
// Created by hrist on 4/19/2024.
//
#include <iostream>
#include <cstring>

using namespace std;
struct Tanc {
    char Dance[15];
    char Origin[15];
};
struct Tancer {
    char Name[20];
    char Lastname[20];
    Tanc Dances[5];

};

void tancuvanje(Tancer tanceri[], int n, char *zemja) {
    int i, j, flag;
    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < 3; j++) {
            if (strncmp(tanceri[i].Dances[j].Origin, zemja, strlen(zemja)) == 0) {
                cout << tanceri[i].Name << " " << tanceri[i].Lastname << ", " << tanceri[i].Dances[j].Dance << endl;
                flag = 1;
            }
            if (flag)
                break;
        }
    }
}

int main() {
    int i, j, n;
    char zemja[15];
    Tancer tanceri[5];
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> tanceri[i].Name;
        cin >> tanceri[i].Lastname;
        for (j = 0; j < 3; j++) {
            cin >> tanceri[i].Dances[j].Dance;
            cin >> tanceri[i].Dances[j].Origin;
        }
    }
    cin >> zemja;
    tancuvanje(tanceri, n, zemja);
    return 0;
}
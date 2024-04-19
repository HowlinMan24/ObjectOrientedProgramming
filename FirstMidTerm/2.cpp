//
// Created by hrist on 4/19/2024.
//
#include <iostream>
#include <cstring>

using namespace std;

class List {
private:
    int *NumbersList;
    int NumNumbers;
public:
    //default
    List() {
        NumbersList = nullptr;
        NumNumbers = 0;
    }

    //argumetns
    List(int *NumbersList, int NumNumbers) {
        this->NumNumbers = NumNumbers;
        this->NumbersList = new int[NumNumbers];
        for (int i = 0; i < NumNumbers; i++) {
            this->NumbersList[i] = NumbersList[i];
        }
    }

    //copy
    List(const List &l) {
        this->NumNumbers = l.NumNumbers;
        this->NumbersList = new int[l.NumNumbers];
        for (int i = 0; i < NumNumbers; i++) {
            this->NumbersList[i] = l.NumbersList[i];
        }
    }

    //operator =
    List &operator=(const List &l) {
        if (this != &l) {
            delete[]  NumbersList;
            this->NumNumbers = l.NumNumbers;
            this->NumbersList = new int[l.NumNumbers];
            for (int i = 0; i < NumNumbers; i++) {
                this->NumbersList[i] = l.NumbersList[i];
            }
        }
    }

    //Destructor
    ~List() {
        delete[] NumbersList;
    }

    //sum
    int sum() {
        int sum = 0;
        for (int i = 0; i < NumNumbers; i++) {
            sum += NumbersList[i];
        }
        return sum;
    }

    //average
    double average() {
        int sum = 0;
        for (int i = 0; i < NumNumbers; i++) {
            sum += NumbersList[i];
        }
        return (double) sum / NumNumbers;
    }

    //pecati()
    void pecati() {
        cout << NumNumbers << ": ";
        for (int i = 0; i < NumNumbers; i++) {
            cout << NumbersList[i] << " ";
        }
        cout << "sum: " << sum();
        cout << " average: " << average();
    }

    friend class ListContainer;
};

class ListContainer {
private:
    List *Lists;
    int NumElements;
    int Failed;
    int Succesful;
public:
    //default
    ListContainer() {
        Lists = nullptr;
        NumElements = 0;
        Failed = 0;
        Succesful = 0;
    }

    //copy
    ListContainer(const ListContainer &l) {
        this->NumElements = l.NumElements;
        this->Failed = l.Failed;
        this->Succesful = l.Succesful;
        this->Lists = new List[l.NumElements];
        for (int i = 0; i < l.NumElements; i++) {
            this->Lists[i] = l.Lists[i];
        }
    }

    //operator =
    ListContainer &operator=(const ListContainer &l) {
        if (this != &l) {
            this->NumElements = l.NumElements;
            this->Failed = l.Failed;
            this->Succesful = l.Succesful;
            delete[] Lists;
            this->Lists = new List[l.NumElements];
            for (int i = 0; i < l.NumElements; i++) {
                this->Lists[i] = l.Lists[i];
            }
        }
        return *this;
    }

    //destructor
    ~ListContainer() {
        delete[] Lists;
    }

    //pecati
    void print() {
        if (NumElements == 0) {
            cout << "The list is empty";
            cout << endl;
            return;
        }
        for (int i = 0; i < NumElements; i++) {
            cout << "List number: " << i + 1 << " List info: ";
            Lists[i].pecati();
            cout << endl;
        }
        cout << "Sum: " << sum();
        cout << " Average: " << average() << endl;
        cout << "Successful attempts: " << Succesful << " Failed attempts: " << Failed;
        cout << endl;
    }

    //sum
    int sum() {
        int sum = 0;
        for (int i = 0; i < NumElements; i++) {
            for (int j = 0; j < Lists[i].NumNumbers; j++) {
                sum += Lists[i].NumbersList[j];
            }
        }
        return sum;
    }

    //average
    double average() {
        int sum = 0, counter = 0;;
        for (int i = 0; i < NumElements; i++) {
            for (int j = 0; j < Lists[i].NumNumbers; j++) {
                sum += Lists[i].NumbersList[j];
                counter++;
            }
        }
        return (double) sum / counter;
    }

    //add
    void addNewList(List l) {
        int flag = 1;
        List *NewList = new List[NumElements + 1];
        for (int i = 0; i < NumElements; i++) {
            if (Lists[i].sum() == l.sum()) {
                //NewList[i]=Lists[i];
                flag = 0;
            }
        }
        if (flag) {
            for (int i = 0; i < NumElements; i++) {
                NewList[i] = Lists[i];
            }
            NewList[NumElements++] = l;
            delete[] Lists;
            Lists = NewList;
            Succesful++;
        } else
            Failed++;
    }

};


int main() {

    ListContainer lc;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int n;
        int niza[100];

        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> niza[j];

        }

        List l = List(niza, n);

        lc.addNewList(l);
    }


    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "Test case for operator =" << endl;
        ListContainer lc1;
        lc1.print();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1 = lc;
        lc1.print();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1.sum();
        lc1.average();

    } else {
        lc.print();
    }
}

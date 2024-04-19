//
// Created by hrist on 4/19/2024.
//
#include<iostream>
#include<cstring>

using namespace std;

enum Extension {
    txt,
    pdf,
    exe

};

class File {
private:
    char *FileName;
    Extension Type;
    char *OwnerName;
    int FileSize;
public:
    //Default constructor
    File() {
        FileName = nullptr;
        Type = txt;
        OwnerName = nullptr;
        FileSize = 0;
    }

    //Constructor with arguments
    File(char *FileName, char *OwnerName, int FileSize, Extension Type) {
        this->FileName = new char[strlen(FileName) + 1];
        strcpy(this->FileName, FileName);
        this->OwnerName = new char[strlen(OwnerName) + 1];
        strcpy(this->OwnerName, OwnerName);
        this->FileSize = FileSize;
        this->Type = Type;
    }

    //Copy-constructor
    File(const File &f) {
        FileName = new char[strlen(f.FileName) + 1];
        strcpy(this->FileName, f.FileName);
        OwnerName = new char[strlen(f.OwnerName) + 1];
        strcpy(this->OwnerName, f.OwnerName);
        this->FileSize = f.FileSize;
        this->Type = f.Type;
    }

    //Opeartor =
    File &operator=(const File &f) {
        if (this != &f) {
            delete[] FileName;
            delete[] OwnerName;
            FileName = new char[strlen(f.FileName) + 1];
            strcpy(this->FileName, f.FileName);
            OwnerName = new char[strlen(f.OwnerName) + 1];
            strcpy(this->OwnerName, f.OwnerName);
            this->FileSize = f.FileSize;
            this->Type = f.Type;
        }
        return *this;
    }

    //Destructor
    ~File() {
        delete[] FileName;
        delete[] OwnerName;
    }

    //Void print
    void print() {
        cout << "File name: " << FileName;
        if (Type == 0)
            cout << ".pdf";
        else if (Type == 1)
            cout << ".txt";
        else
            cout << ".exe";
        cout << endl;
        //cout<<endl;
        cout << "File owner: " << OwnerName;
        cout << endl;
        cout << "File size: " << FileSize;
        cout << endl;

    }

    //bool equals(const File & that)
    bool equals(const File &that) {
        return (strcmp(this->FileName, that.FileName) == 0 && (this->Type == that.Type) &&
                strcmp(this->OwnerName, that.OwnerName) == 0);
    }

    // bool equalsType(const File & that)
    bool equalsType(const File &that) {
        return (strcmp(this->FileName, that.FileName) == 0 && (this->Type == that.Type));
    }

    friend class Folder;
};

class Folder {
private:
    char *FolderName;
    int NumFolders;
    File *Files;
public:
    //Default constructor
    Folder() {
        FolderName = nullptr;
        NumFolders = 0;
        Files = nullptr;
    }

    //Constructor with arguments
    Folder(char *FolderName) {
        this->FolderName = new char[strlen(FolderName) + 1];
        strcpy(this->FolderName, FolderName);
        NumFolders = 0;
        Files = nullptr;
    }

    //Copy-constructor
    Folder(const Folder &f) {
        this->FolderName = new char[strlen(f.FolderName) + 1];
        strcpy(this->FolderName, f.FolderName);
        this->NumFolders = f.NumFolders;
        this->Files = new File[f.NumFolders];
        for (int i = 0; i < f.NumFolders; i++) {
            this->Files[i] = f.Files[i];
        }
    }

    //Operator =
    Folder &operator=(const Folder &f) {
        delete[] FolderName;
        delete[] Files;
        this->FolderName = new char[strlen(f.FolderName) + 1];
        strcpy(this->FolderName, f.FolderName);
        this->NumFolders = f.NumFolders;
        this->Files = new File[f.NumFolders];
        for (int i = 0; i < f.NumFolders; i++) {
            this->Files[i] = f.Files[i];
        }
    }

    //Destructor
    ~Folder() {
        delete[] Files;
        delete[] FolderName;
    }

    //void print()
    void print() {
        cout << "Folder name: " << FolderName;
        cout << endl;
        for (int i = 0; i < NumFolders; i++) {
            Files[i].print();
            // cout<<endl;
        }
    }

    //void remove(const File & file)
    void remove(const File &file) {
        int i, counter;
        File *RemoveFiles = new File[NumFolders + 1];
        for (i = 0; i < NumFolders; i++) {
            if (Files[i].equals(file) == 0) {
                RemoveFiles[counter++] = Files[i];
            }
        }
        delete[] Files;
        Files = RemoveFiles;
        NumFolders = counter;
    }

    //void void add(const File & file)
    void add(const File &file) {
        File *NewFiles = new File[NumFolders + 1];
        for (int i = 0; i < NumFolders; i++) {
            NewFiles[i] = Files[i];
        }
        NewFiles[NumFolders++] = file;
        delete[] Files;
        Files = NewFiles;
    }


};

int main() {
    char fileName[20];
    char fileOwner[20];
    int ext;
    int fileSize;

    int testCase;
    cin >> testCase;
    if (testCase == 1) {
        cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File created = File(fileName, fileOwner, fileSize, (Extension) ext);
        File copied = File(created);
        File assigned = created;

        cout << "======= CREATED =======" << endl;
        created.print();
        cout << endl;
        cout << "======= COPIED =======" << endl;
        copied.print();
        cout << endl;
        cout << "======= ASSIGNED =======" << endl;
        assigned.print();
    } else if (testCase == 2) {
        cout << "======= FILE EQUALS & EQUALS TYPE =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File first(fileName, fileOwner, fileSize, (Extension) ext);
        first.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File second(fileName, fileOwner, fileSize, (Extension) ext);
        second.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File third(fileName, fileOwner, fileSize, (Extension) ext);
        third.print();

        bool equals = first.equals(second);
        cout << "FIRST EQUALS SECOND: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equals = first.equals(third);
        cout << "FIRST EQUALS THIRD: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        bool equalsType = first.equalsType(second);
        cout << "FIRST EQUALS TYPE SECOND: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equalsType = second.equals(third);
        cout << "SECOND EQUALS TYPE THIRD: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

    } else if (testCase == 3) {
        cout << "======= FOLDER CONSTRUCTOR =======" << endl;
        cin >> fileName;
        Folder folder(fileName);
        folder.print();

    } else if (testCase == 4) {
        cout << "======= ADD FILE IN FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        folder.print();
    } else {
        cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File file(fileName, fileOwner, fileSize, (Extension) ext);
        folder.remove(file);
        folder.print();
    }
    return 0;
}

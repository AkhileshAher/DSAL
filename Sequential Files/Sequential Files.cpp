#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

struct stud {
    int rno;
    char nm[10];
} s;

void create() {
    ofstream fout;
    int n, i;
    fout.open("stud1.txt", ios::out); // fout = write into file
    cout << "\nEnter the Number of records: ";
    cin >> n;
    for (i = 0; i < n; i++) {
        cout << "\nEnter roll no & name: ";
        cin >> s.rno >> s.nm;
        fout << s.rno << "\t" << s.nm << endl;
    }
    fout.close();
}

void display() {
    ifstream fin;
    fin.open("stud1.txt", ios::in); // fin = read from file
    cout << "\nRecords:\n";
    while (fin >> s.rno >> s.nm) {
        cout << s.rno << "\t" << s.nm << endl;
    }
    fin.close();
}

void search() {
    ifstream fin;
    int key, flag = 0;
    cout << "\nEnter roll number to search: ";
    cin >> key;
    fin.open("stud1.txt", ios::in); // fin = read from file
    while (fin >> s.rno >> s.nm) {
        if (s.rno == key) {
            flag = 1;
            cout << "\nElement found: " << s.rno << "\t" << s.nm << endl;
            break;
        }
    }
    if (flag == 0)
        cout << "\nElement not found!";
    fin.close();
}

void delete_rec() {
    ifstream fin;
    ofstream fout;
    int key, flag = 0;
    cout << "\nEnter the roll number to delete: ";
    cin >> key;
    fin.open("stud1.txt", ios::in); // fin = read from file
    fout.open("temp.txt", ios::out); // fout = write to temporary file

    while (fin >> s.rno >> s.nm) {
        if (key == s.rno) {
            flag = 1;
        } else {
            fout << s.rno << "\t" << s.nm << endl;
        }
    }
    fin.close();
    fout.close();
    remove("stud1.txt");
    rename("temp.txt", "stud1.txt");

    if (flag == 0)
        cout << "\nRecord not found!";
    else
        cout << "\nRecord deleted successfully!";
}

void update_rec() {
    ifstream fin;
    ofstream fout;
    int key, flag = 0;
    cout << "\nEnter the roll number to update: ";
    cin >> key;
    fin.open("stud1.txt", ios::in); // fin = read from file
    fout.open("temp.txt", ios::out); // fout = write to temporary file

    while (fin >> s.rno >> s.nm) {
        if (key == s.rno) {
            flag = 1;
            cout << "\nEnter new roll no and name: ";
            cin >> s.rno >> s.nm;
        }
        fout << s.rno << "\t" << s.nm << endl;
    }
    fin.close();
    fout.close();
    remove("stud1.txt");
    rename("temp.txt", "stud1.txt");

    if (flag == 0)
        cout << "\nRecord not found!";
    else
        cout << "\nRecord updated successfully!";
}

int main() {
    int ch;
    do {
        cout << "\n1. Create\n2. Display\n3. Search\n4. Delete Record\n5. Update\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            delete_rec();
            break;
        case 5:
            update_rec();
            break;
        case 6:
            cout << "\nExiting program...";
            break;
        default:
            cout << "\nInvalid choice! Try again.";
        }
    } while (ch != 6);

    return 0;
}

#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

struct Stack {
    char isi[100];
    int atas;
};

void push(Stack &s, char x) {
    if (s.atas == 99) {
        cout << "Tumpukan sudah penuh";
        getch();
    } else {
        s.atas = s.atas + 1;
        s.isi[s.atas] = x;
    }
}

char pop(Stack &s) {
    char hasil;
    if (s.atas == 0) {
        cout << "Tumpukan sudah kosong";
        hasil = ' ';
    } else {
        hasil = s.isi[s.atas];
        s.atas = s.atas - 1;
    }
    return hasil;
}

int main() {
    Stack s;
    s.atas = 0;
    char kalimat[100];
    cout << "Masukkan kalimat : ";
    gets(kalimat);
    system("cls");
    cout << "Kalimat asli : " << kalimat << endl;
    for (int i = 0; i < strlen(kalimat); i++) {
        push(s, kalimat[i]);
    }
    cout << "\nKalimat setelah di Balik : ";
    for (int i = 0; i < strlen(kalimat); i++) {
        cout << pop(s);
    }
    cout << endl;
    return 0;
}
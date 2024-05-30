#include <iostream>
#include <conio.h>
#include <string.h> 

using namespace std;

struct Stack {
  char isi[100]; 
  int atas;
};

void push(Stack &s, char x) { // Fungsi untuk menambahkan elemen ke tumpukan
  if (s.atas == 99) { // Memeriksa apakah tumpukan penuh
    cout << "Tumpukan sudah penuh"; // Menampilkan pesan error
    getch(); // Menunggu input pengguna
  } else {
    s.atas = s.atas + 1; // Meningkatkan indeks elemen terakhir
    s.isi[s.atas] = x; // Menyimpan elemen ke dalam tumpukan
  }
}

char pop(Stack &s) { // Fungsi untuk menghapus elemen dari tumpukan
  char hasil; // Variabel untuk menyimpan elemen yang dikeluarkan
  if (s.atas == 0) { // Memeriksa apakah tumpukan kosong
    cout << "Tumpukan sudah kosong"; // Menampilkan pesan error
    hasil = ' '; // Mengatur nilai default jika kosong
  } else {
    hasil = s.isi[s.atas]; // Menyimpan elemen terakhir ke variabel hasil
    s.atas = s.atas - 1; // Menurunkan indeks elemen terakhir
  }
  return hasil; // Mengembalikan elemen yang dikeluarkan
}

int main() { // Fungsi utama
  Stack s; // Menginisialisasi tumpukan `s`
  s.atas = 0; // Mengatur indeks elemen terakhir ke 0 (tumpukan kosong)
  char kalimat[100]; // Array karakter untuk menyimpan kalimat
  cout << "Masukkan kalimat : "; // Mencetak prompt untuk pengguna
  gets(kalimat); // Membaca kalimat dari pengguna
  system("cls"); // Membersihkan layar
  cout << "Kalimat asli : " << kalimat << endl; // Menampilkan kalimat asli
  for (int i = 0; i < strlen(kalimat); i++) { // Meloop melalui setiap karakter kalimat
    push(s, kalimat[i]); // Menambahkan karakter ke tumpukan
  }
  cout << "\nKalimat setelah di Balik : "; // Mencetak prompt untuk kalimat yang dibalik
  for (int i = 0; i < strlen(kalimat); i++) { // Meloop melalui setiap karakter kalimat
    cout << pop(s); // Mengeluarkan dan mencetak karakter dari tumpukan
  }
  cout << endl; // Menambahkan baris baru
  return 0; // Mengembalikan nilai 0 untuk menunjukkan program berhasil
}

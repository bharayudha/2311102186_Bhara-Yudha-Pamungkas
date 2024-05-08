# <h1 align="center"> Laporan Praktium Modul 6 Stack </h1>
<p align="center"> Bhara Yudha Pamungkas <p>
<p align="center"> 2311102186 </p>

## Dasar Teori
<p align = "justify">
Stack adalah struktur data yang mengikuti prinsip operasi Last In, First Out (LIFO), yang berarti elemen yang disisipkan terakhir akan menjadi elemen yang diambil pertama. Stack dapat didefinisikan sebagai kumpulan elemen data yang disimpan secara berurutan, dengan elemen terakhir yang disimpan sebagai elemen paling atas. Stack dapat digunakan dalam berbagai aplikasi, seperti evaluasi dan konversi ekspresi aritmatika, serta dalam implementasi algoritma seperti evaluasi ekspresi matematika dan konversi notasi infix ke postfix[1].
</p>

## Guided 
```C++
#include <iostream>
using namespace std;
string arrayBuku[5];
int maksimal = 5, top = 0;
bool isFull()
{
    return (top == maksimal);
}
bool isEmpty()
{
    return (top == 0);
}
void pushArrayBuku(string data)
{
    if (isFull())
    {
        cout << "Data telah penuh" << endl;
    }
    else
    {
        arrayBuku[top] = data;
        top++;
    }
}
void popArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else
    {
        arrayBuku[top - 1] = "";
        top--;
    }
}
void peekArrayBuku(int posisi)
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}
int countStack()
{
    return top;
}
void changeArrayBuku(int posisi, string data)
{
    if (posisi > top)
    {
        cout << "Posisi melebihi data yang ada" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        arrayBuku[index] = data;
    }
}
void destroyArraybuku()
{
    for (int i = top; i >= 0; i--)
    {
        arrayBuku[i] = "";
    }
    top = 0;
}
void cetakArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dicetak" << endl;
    }
    else
    {
        for (int i = top - 1; i >= 0; i--)
        {
            cout << arrayBuku[i] << endl;
        }
    }
}
int main()
{
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");
    cetakArrayBuku();
    cout << "\n";
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();
    return 0;
}
```
### Screenshot
![1](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/0f0fc2b9-a59b-47fc-b9ab-1b6d5b9cbe78)



## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

```C++
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

// Fungsi untuk mengecek apakah string adalah palindrome
bool isPalindrome(string str) {
  // Deklarasi stack untuk menyimpan karakter
  stack<char> st;

  // Menambahkan karakter dari string ke stack
  for (char c : str) {
    st.push(c);
  }

  // String kosong untuk menyimpan hasil kebalikan dari string input
  string reversed = "";

  // Mengambil karakter dari stack dan menambahkannya ke string reversed
  while (!st.empty()) {
    reversed += st.top();
    st.pop();
  }

  // Membandingkan string input dengan string reversed
  return str == reversed;
}

int main() {
  string input;

  // Meminta pengguna untuk memasukkan string
  cout << "Masukan string: ";
  getline(cin, input);

  // Memanggil fungsi isPalindrome untuk mengecek apakah string palindrome
  if (isPalindrome(input)) {
    cout << "String ini palindrome." << endl;
  } else {
    cout << "String ini bukan palindrome." << endl;
  }

  return 0;
}

```
### Screenshot
![WhatsApp Image 2024-05-08 at 20 31 50_9e46fd69](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/d1d7551d-595b-4cc8-b2e9-1e9c1abaad23)



### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?
```C++
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

```

### Screenshot
![WhatsApp Image 2024-05-08 at 20 10 06_f4c1c8d3](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/6f4752f7-62ae-4d56-90cc-e138bdae23c3)


## Kesimpulan 

<p align = "Justify">
Kesimpulan: Stack dalam konteks pemrograman adalah sebuah struktur data yang beroperasi dengan prinsip Last In, First Out (LIFO), yang memungkinkan elemen ditambahkan dan dihapus dari ujung yang disebut "top". Stack sangat penting dalam manajemen eksekusi fungsi atau subroutine, serta dalam parsing, manajemen memori, dan aplikasi lainnya. Dalam bahasa pemrograman C++, stack dapat diterapkan menggunakan array atau linked list, dan beberapa contoh implementasi stack dapat ditemukan dalam jurnal ilmiah dari tahun 2020 hingga 2024.

</p>

## Daftar Pustaka

[1]. Roida Sihotang, Haris Saputro, Satria Novari, SISTEM INFORMASI PENGGAJIAN LKPENGLISH ACADEMY MENGGUNAKAN EMBARCADERO XE2 BERBASIS CLIET SERVER, Vol. 4, No. 1, Jurnal Teknik Informatika Mahakarya (JTIM), Juni 2021.

# <h1 align="center"> Laporan Praktium Modul 6 Stack </h1>
<p align="center"> Bhara Yudha Pamungkas <p>
<p align="center"> 2311102186 </p>

## Dasar Teori
<p align = "justify">
Stack adalah struktur data yang mengikuti prinsip LIFO.Artinya, elemen terakhir yang dimasukkan adalah elemen pertama yang diambil.
Tumpukan dapat didefinisikan sebagai kumpulan item data yang disimpan secara berurutan, dengan item terakhir menjadi item paling atas.
Stack dapat digunakan dalam berbagai aplikasi seperti mengevaluasi dan mengkonversi ekspresi matematika, dan juga dapat digunakan untuk mengimplementasikan algoritma seperti mengevaluasi ekspresi matematika dan mengkonversi dari notasi infiks ke notasi postfix [1].
 

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
![Screenshot (273)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/86171838-8e91-45ce-9779-1a14378c7ac6)




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
### Screenshot Output
![Screenshot (274)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/6f3fbd12-88c1-4735-a0dd-2a79c1b8a65c)

## Deskripsi Program
Program ini mengecek apakah sebuah string adalah palindrome menggunakan stack. Setelah menerima input string dari pengguna, program memasukkan setiap karakter string tersebut ke dalam stack. Kemudian, program mengambil karakter dari stack satu per satu untuk membentuk string terbalik. Terakhir, program membandingkan string asli dengan string terbalik dan menampilkan hasil apakah string tersebut adalah palindrome (sama jika dibaca dari depan atau belakang) atau bukan.


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

### Screenshot Output
![Screenshot (275)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/edde2755-d636-4c3a-8270-84efeb20263b)

### Deskripsi Program
Program ini menggunakan stack untuk membalik urutan karakter dalam kalimat yang dimasukkan oleh pengguna. Dengan memanfaatkan operasi dasar stack (push dan pop), program membaca input, menambahkan setiap karakter ke stack, kemudian mengeluarkannya dalam urutan terbalik untuk menghasilkan kalimat yang telah dibalik.

## Kesimpulan 

<p align = "Justify">
Stack dalam konteksa pemrograman adalah  struktur data yang beroperasi berdasarkan prinsip LIFO, yang memungkinkan elemen ditambahkan dan dihapus di bagian akhir, yang disebut "atas".
Stack penting untuk eksekusi fungsi dan subprogram, penguraian, manajemen memori, dan manajemen aplikasi lainnya.
Dalam bahasa pemrograman C++, tumpukan dapat diimplementasikan menggunakan array atau daftar tertaut, dan beberapa contoh implementasi tumpukan telah dipublikasikan di jurnal akademik dari tahun 2020 hingga 2024.

</p>

## Daftar Pustaka

[1]. Roida Sihotang, Haris Saputro, Satria Novari, SISTEM INFORMASI PENGGAJIAN LKPENGLISH ACADEMY MENGGUNAKAN EMBARCADERO XE2 BERBASIS CLIET SERVER, Vol. 4, No. 1, Jurnal Teknik Informatika Mahakarya (JTIM), Juni 2021.

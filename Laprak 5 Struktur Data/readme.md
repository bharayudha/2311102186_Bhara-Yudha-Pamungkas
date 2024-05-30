# <h1 align="center"> Laporan Praktium Modul 5 Hash Table </h1>
<p align="center"> Bhara Yudha aAmungkas <p>
<p align="center"> 2311102186</p>

## Dasar Teori
<p align = "Justify">
Tabel hash adalah struktur data mendasar dalam ilmu komputer untuk beban kerja basis data analitis seperti agregasi, penggabungan, pemfilteran batch, dan deduplikasi catatan.
Mereka digunakan untuk menyimpan dan mengambil data secara efisien dengan memetakan kunci ke indeks, memungkinkan operasi waktu  konstan, overhead rendah, penyisipan, penghapusan, dan pencarian [1].
Teori di balik tabel hash melibatkan penggunaan fungsi hash untuk mendistribusikan data ke dalam satu set keranjang.
Setiap bucket berisi daftar nilai tertaut dengan nilai hash yang sama [2].
  
Tabel hash ini dirancang untuk meminimalkan jumlah tabrakan yang terjadi ketika dua atau lebih kunci melakukan hash ke indeks yang sama.
Teknik resolusi konflik seperti chaining dan open pengalamatan  digunakan untuk menangani konflik dan menjaga efisiensi struktur data [2].
Pilihan fungsi hash dan metode resolusi tabrakan dapat berdampak signifikan pada performa tabel hash.
Dalam beberapa tahun terakhir, desain tabel hash telah mengalami kemajuan dalam hal berikut: B.Gunung es hash.
Ini mendukung faktor beban hingga 1 - o(1) sekaligus memberikan jaminan kuat untuk efisiensi ruang, efisiensi cache, dan kemungkinan kegagalan yang rendah [3].
Selain itu, metode hashing yang optimal untuk sistem OLAP diusulkan untuk memungkinkan kueri dan penyimpanan data yang efisien.

Untuk pemahaman komprehensif tentang teori dan implementasi tabel hash, buku The Joys of Hashing: Hash Table Programming dengan C mencakup desain  tabel hash, termasuk strategi penyelesaian konflik, teknik pengubahan ukuran, dan cara menggunakan hash heuristik serta detail implementasi Fungsi [2].
</p>

## Guided

### Guided 1 
```C++
#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

// Fungsi hash sederhana

int hash_func(int key) {

return key % MAX_SIZE;

}

// Struktur data untuk setiap node

struct Node {

int key;

int value;

Node* next;

Node(int key, int value) : key(key), value(value),

next(nullptr) {}

};

// Class hash table

class HashTable {

private:

Node** table;

public:

HashTable() {

table = new Node*[MAX_SIZE]();

}

~HashTable() {

for (int i = 0; i < MAX_SIZE; i++) {

Node* current = table[i];

while (current != nullptr) {

Node* temp = current;

current = current->next;

delete temp;

}

}

delete[] table;

}

// Insertion

void insert(int key, int value) {

int index = hash_func(key);

Node* current = table[index];

while (current != nullptr) {

if (current->key == key) {

current->value = value;

return;

}

current = current->next;

}
Node* node = new Node(key, value);

node->next = table[index];

table[index] = node;

}

// Searching

int get(int key) {

int index = hash_func(key);

Node* current = table[index];

while (current != nullptr) {

if (current->key == key) {

return current->value;

}

current = current->next;

}

return -1;

}

// Deletion

void remove(int key) {

int index = hash_func(key);

Node* current = table[index];

Node* prev = nullptr;

while (current != nullptr) {

if (current->key == key) {

if (prev == nullptr) {

table[index] = current->next;

} else {

prev->next = current->next;

}

delete current;

return;

}

prev = current;

current = current->next;

}

}

// Traversal

void traverse() {

for (int i = 0; i < MAX_SIZE; i++) {

Node* current = table[i];

while (current != nullptr) {

cout << current->key << ": " << current->value

<< endl;

current = current->next;

}

}

}

};
int main() {

HashTable ht;

// Insertion

ht.insert(1, 10);

ht.insert(2, 20);

ht.insert(3, 30);

// Searching

cout << "Get key 1: " << ht.get(1) << endl;

cout << "Get key 4: " << ht.get(4) << endl;

// Deletion

ht.remove(4);

// Traversal

ht.traverse();

return 0;

}

```
#### Screenshot
![Screenshot (269)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/06b2e200-3134-46d4-8c19-bbedfa697675)




### Guided 2

```C++
#include <iostream>

#include <string>

#include <vector>

using namespace std;

const int TABLE_SIZE = 11;

string name;

string phone_number;

class HashNode {

public:

string name;

string phone_number;

HashNode(string name, string phone_number) {

this->name = name;

this->phone_number = phone_number;

}

};

class HashMap {

private:
vector<HashNode*> table[TABLE_SIZE];

public:

int hashFunc(string key) {

int hash_val = 0;

for (char c : key) {

hash_val += c;

}

return hash_val % TABLE_SIZE;

}

void insert(string name, string phone_number) {

int hash_val = hashFunc(name);

for (auto node : table[hash_val]) {

if (node->name == name) {

node->phone_number = phone_number;

return;

}

}

table[hash_val].push_back(new HashNode(name,

phone_number));

}

void remove(string name) {

int hash_val = hashFunc(name);

for (auto it = table[hash_val].begin(); it !=

table[hash_val].end(); it++) {

if ((*it)->name == name) {

table[hash_val].erase(it);

return;

}

}

}

string searchByName(string name) {

int hash_val = hashFunc(name);

for (auto node : table[hash_val]) {

if (node->name == name) {

return node->phone_number;

}

}

return "";

}

void print() {

for (int i = 0; i < TABLE_SIZE; i++) {

cout << i << ": ";

for (auto pair : table[i]) {

if(pair != nullptr){

cout << "[" << pair->name << ", " <<

pair->phone_number << "]";

}
}

cout << endl;

}

}

};

int main() {

HashMap employee_map;

employee_map.insert("Mistah", "1234");

employee_map.insert("Pastah", "5678");

employee_map.insert("Ghana", "91011");

cout << "Nomer Hp Mistah : "

<<employee_map.searchByName("Mistah") << endl;

cout << "Phone Hp Pastah : "

<<employee_map.searchByName("Pastah") << endl;

employee_map.remove("Mistah");

cout << "Nomer Hp Mistah setelah dihapus : "

<<employee_map.searchByName("Mistah") << endl << endl;

cout << "Hash Table : " << endl;

employee_map.print();

return 0;

}
```
#### ScreenShot
![Screenshot (270)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/09f9df66-d0f9-482d-9130-6c056edb8917)





## Unguided 


### Unguided 1
Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :

A. Setiap mahasiswa memiliki NIM dan nilai.

B. Program memiliki tampilan pilihan menu berisi poin C.

C. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

```C++
#include <iostream>
#include <list>
using namespace std;

// Class to represent a Mahasiswa (student)
class Mahasiswa {
public:
  int nim;  // Student ID
  int nilai; // Grade
};

// Class to implement a Hash Table for storing Mahasiswa data
class HashTable {
private:
  list<Mahasiswa> *table;  // Array of lists to store Mahasiswa objects
  int total_elements;     // Total number of elements in the hash table

public:
  // Constructor to initialize the hash table with a specified size
  HashTable(int n) {
    total_elements = n;
    table = new list<Mahasiswa>[total_elements]; // Allocate memory for the array of lists
  }


  // "// Fungsi ini untuk memasukkan data mahasiswa ke dalam hash table (insert Mahasiswa)"
  void insertMahasiswa(int nim, int nilai) {
    int index = nim % total_elements; // Calculate the hash index using modulo operator
    table[index].push_back({nim, nilai}); // Add the Mahasiswa object to the corresponding list
  }


  // "// Fungsi ini untuk menghapus data mahasiswa dari hash table berdasarkan nim (delete Mahasiswa)"
  void deleteMahasiswa(int nim) {
    int index = nim % total_elements;
    list<Mahasiswa>::iterator it;
    for (it = table[index].begin(); it != table[index].end(); it++) {
      if (it->nim == nim) {
        table[index].erase(it); // Remove the element from the list if nim matches
        break;
      }
    }
  }


  // "// Fungsi ini untuk mencari data mahasiswa berdasarkan nim (search Mahasiswa by NIM)"
  void searchMahasiswaByNIM(int nim) {
    int index = nim % total_elements;
    list<Mahasiswa>::iterator it;
    for (it = table[index].begin(); it != table[index].end(); it++) {
      if (it->nim == nim) {
        cout << "NIM: " << it->nim << ", Nilai: " << it->nilai << endl;
        break;
      }
    }
  }
  // "// Fungsi ini untuk mencari data mahasiswa berdasarkan range nilai (search Mahasiswa by range)"
  void searchMahasiswaByRange(int min, int max) {
    for (int i = 0; i < total_elements; i++) {
      list<Mahasiswa>::iterator it;
      for (it = table[index].begin(); it != table[index].end(); it++) {
        if (it->nilai >= min && it->nilai <= max) {
          cout << "NIM: " << it->nim << ", Nilai: " << it->nilai << endl;
        }
      }
    }
  }
};

int main() {
  int nim, nilai, min, max;

  // Create a HashTable object with a capacity of 100 elements
  HashTable ht(100);

  while (true) {
    cout << "Menu" << endl;
    cout << "1. Insert data" << endl;
    cout << "2. Delete data" << endl;
    cout << "3. Search by NIM" << endl;
    cout << "4. Search by range" << endl;
    cout << "\n";

    int pilihan;
    cout << "Masukan Pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
      case 1:
        cout << "Masukan nim: ";
        cin >> nim;
        cout << "Masukan Nilai: ";
        cin >> nilai;
        ht.insertMahasiswa(nim, nilai);
        break;
      case 2:
        cout << "Masukan nim: ";
        cin >> nim;
        ht.deleteMahasiswa(nim);
        break;
      case 3:
        cout << "Masukan NIM: ";
        cin >> nim;
        ht.searchMahasiswaByNIM(nim);
        break;
      case 4:
        cout << "Masukan nilai min: ";
        cin >> min;
        cout << "Masukan nilai max: ";
        cin >> max;
        ht.searchMahasiswaByRange(min, max);
        break;
      case 0:
        exit(0);
    }
  }

  return 0;
}

```
### Screenshot 
![Screenshot (272)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/a65d9b87-1fe1-415d-b883-9b1cfba2ff81)


## Kesimpulan
Hash table pada C++ adalah struktur data yang menyimpan pasangan kunci-nilai, memungkinkan operasi pencarian, penyisipan, dan penghapusan dengan efisiensi tinggi, biasanya dalam waktu O(1). Menggunakan fungsi hash untuk menghitung indeks kunci, hash table menangani tabrakan dengan chaining atau open addressing



## Daftar Pustaka

[1].	Michael A. Bender, Alex Conway, Martin Farach-Colton, William Kuszmaul, Guido Tagliavini, “Iceberg Hashing,” Optimizing Many Hash-Table Criteria at Once, Volume 70, Issue 6 December 2023.

[2].	Thomas Mailund, The Joys of Hashing: Hash Table Programming with C [1 ed.], Aarhus N, Denmark, 2019.

[3].	Tianqi Zheng,  Zhibin Zhang, Xueqi Cheng, “SAHA,”  A String Adaptive Hash Table for Analytical Databases, Volume 10, Issue 6, 11 March 2020

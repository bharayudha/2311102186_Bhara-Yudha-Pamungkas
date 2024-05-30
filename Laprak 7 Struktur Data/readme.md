# <h1 align="center"> Laporan Praktium Modul 7 Queue </h1>
<p align="center"> Bhara Yudha Pamungkas <p>
<p align="center"> 2311102186 </p>

## Dasar Teori
<p align ="justify"> 
Queue adalah struktur data yang mengikuti prinsip FIFO. Data masuk ke antrian di satu ujung dan keluar dari antrian di ujung yang lain. Artinya item pertama yang dimasukkan ke dalam antrian juga merupakan item pertama yang dihapus [1].

Algoritma antrian biasanya digunakan dalam berbagai aplikasi dan teknologi untuk mengatur antrian dan memproses data secara berurutan.
Dalam konteks aplikasi pemesanan obat berbasis seluler di Apotek Aruba Farma Depok, penerapan algoritma antrian  meningkatkan efisiensi dan kualitas layanan dengan memastikan bahwa pasien menerima obat sesuai urutan antriannya [1}.

Antrian algoritmik memungkinkan Anda  mengelola sistem antrian dengan lebih baik sehingga pasien mengetahui ketersediaan obat dan nomor antriannya tanpa harus datang ke apotek terlebih dahulu.
Hal ini mengurangi waktu tunggu pasien dan meningkatkan pengalaman pelayanan di apotek [1].

</p>


## Guided

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0;               // Penanda antrian
int back = 0;                // Penanda
    string queueTeller[5];       // Fungsi pengecekan

bool isFull()
{ // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue)
    {
        return true; // =1
    }
    else
    {
        return false;
    }
}
bool isEmpty()
{ // Antriannya kosong atau tidak
    if (back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void enqueueAntrian(string data)
{ // Fungsi menambahkan antrian
    if (isFull())
    {
        cout << "Antrian penuh" << endl;
    }
    else
    {
        if (isEmpty())
        { // Kondisi ketika queue kosong
            queueTeller[0] = data;
            front++;
            back++;
        }
        else
        { // Antrianya ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}
void dequeueAntrian()
{ // Fungsi mengurangi antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}
int countQueue()
{ // Fungsi menghitung banyak antrian
    return back;
}
void clearQueue()
{ // Fungsi menghapus semua antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}
void viewQueue()
{ // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++)
    {
        if (queueTeller[i] != "")
        {
            cout << i + 1 << ". " << queueTeller[i] <<

                endl;
        }
        else
        {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}
int main()
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```


### Screenshot
![Screenshot (276)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/ee6b7807-2f8a-417c-b4b6-8fbcfd6c038f)



## Unguided

### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list.
```C++
#include <iostream>
using namespace std;

struct Node {
  string data;
  Node* next;
};

Node* front = nullptr;
Node* back = nullptr;

bool isFull() {
  return false; // Linked list tidak memiliki batasan maksimum
}

bool isEmpty() {
  return front == nullptr;
}

void enqueueAntrian(string data) {
  Node* newNode = new Node;
  newNode->data = data;
  newNode->next = nullptr;

  if (isEmpty()) {
    front = newNode;
    back = newNode;
  } else {
    back->next = newNode;
    back = newNode;
  }
}

void dequeueAntrian() {
  if (isEmpty()) {
    cout << "Antrian kosong" << endl;
    return;
  }

  Node* temp = front;
  front = front->next;
  delete temp;

  if (front == nullptr) {
    back = nullptr;
  }
}

int countQueue() {
  int count = 0;
  Node* current = front;
  while (current != nullptr) {
    count++;
    current = current->next;
  }
  return count;
}

void clearQueue() {
  while (front != nullptr) {
    Node* temp = front;
    front = front->next;
    delete temp;
  }
  back = nullptr;
}

void viewQueue() {
  cout << "Data antrian teller:" << endl;
  Node* current = front;
  while (current != nullptr) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

int main() {
  enqueueAntrian("Andi");
  enqueueAntrian("Maya");
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;
  dequeueAntrian();
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;
  clearQueue();
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;
  return 0;
}
```

### Screenshot
![Screenshot (277)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/a9578e26-efd8-4de0-ae01-986f2d4f404e)


### Deskripsi Program
Program ini menunjukkan bagaimana linked list dapat digunakan untuk mengelola antrian dengan efisien tanpa batasan ukuran maksimum. Fungsi-fungsi yang diimplementasikan memudahkan pengelolaan antrian seperti menambah, menghapus, menghitung elemen, membersihkan, dan menampilkan isi antrian. Program ini bermanfaat untuk memahami dasar-dasar operasi antrian dan manipulasi data menggunakan linked list.



### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa
```C++
#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string namaMahasiswa;
    string nim;
    Node *next;
};

Node *front = nullptr;
Node *back = nullptr;

bool isFull()
{
    return false; // Linked list tidak memiliki batasan maksimum
}

bool isEmpty()
{
    return front == nullptr;
}

void enqueueAntrian(string nama, string nim)
{
    Node *newNode = new Node;
    newNode->namaMahasiswa = nama;
    newNode->nim = nim;
    newNode->next = nullptr;

    if (isEmpty())
    {
        front = newNode;
        back = newNode;
    }
    else
    {
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
        return;
    }

    Node *temp = front;
    front = front->next;
    delete temp;

    if (front == nullptr)
    {
        back = nullptr;
    }
}

int countQueue()
{
    int count = 0;
    Node *current = front;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue()
{
    while (front != nullptr)
    {
        Node *temp = front;
        front = front->next;
        delete temp;
    }
    back = nullptr;
}

void viewQueue()
{
    cout << "Data antrian mahasiswa:" << endl;
    Node *current = front;
    while (current != nullptr)
    {
        cout << "Nama: " << current->namaMahasiswa << ", NIM: " << current->nim << endl;
        current = current->next;
    }
}

int main()
{
    enqueueAntrian("Andi", "2311102186");
    enqueueAntrian("Budi", "2311102184");
    viewQueue();
    dequeueAntrian();
    viewQueue();
    return 0;
}
```
### Screenshot
![Screenshot (278)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/b30649d3-8f5d-4594-91dc-5e49e6d3c3a2)

### Deskripsi Program
Program ini menunjukkan cara mengelola antrian mahasiswa menggunakan linked list, dengan operasi dasar seperti menambah elemen (enqueue), menghapus elemen (dequeue), menghitung elemen, membersihkan antrian, dan menampilkan isi antrian. Linked list memungkinkan antrian ini memiliki fleksibilitas tanpa batasan maksimum jumlah elemen, serta efisiensi dalam penambahan dan penghapusan elemen.


## Kesimpulan 
<p align = "justify">
Queue merupakan salah satu struktur data yang digunakan untuk menyimpan sekumpulan elemen dengan prinsip FIFO (First In, First Out), mirip dengan antrian dalam kehidupan sehari-hari di mana elemen yang pertama dimasukkan ke dalam queue akan menjadi yang pertama pula untuk dikeluarkan.

Dengan memahami konsep dasar dan penggunaan queue dalam bahasa C++, pengembang dapat membuat kode yang lebih efisien dan mudah dipahami saat bekerja dengan struktur data queue dalam pengembangan perangkat lunak.
</p>

## Daftar Pustaka

[1]. Agam Rizky, PENERAPAN ALGORITMA QUEUE PADA APLIKASI PEMESANAN OBAT BERBASIS MOBILE PADA APOTEK ARUBA FARMA DEPOK, Volume 1, No. 5, LOGIC : Jurnal Ilmu Komputer dan Pendidikan, Agustus 2023.

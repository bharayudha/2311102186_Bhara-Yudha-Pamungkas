# <h1 align="center"> Laporan Praktium Modul 7 Queue </h1>
<p align="center"> Bhara Yudha Pamungkas <p>
<p align="center"> 2311102186 </p>

## Dasar Teori
<p align ="justify"> 
Queue adalah struktur data yang mengikuti prinsip "masuk pertama keluar pertama" (First In First Out/FIFO). Data dimasukkan ke dalam queue melalui satu ujung dan dikeluarkan melalui ujung yang lain. Ini berarti elemen pertama yang dimasukkan ke dalam queue akan menjadi elemen pertama yang dikeluarkan [1].

Algoritma queue sering digunakan dalam berbagai aplikasi dan teknologi untuk mengatur antrian dan proses data secara berurutan. Dalam konteks aplikasi pemesanan obat berbasis mobile di Apotek Aruba Farma Depok, penerapan algoritma queue membantu meningkatkan efisiensi dan kualitas pelayanan dengan memastikan pasien mendapatkan obat sesuai urutan antrian mereka [1]

Dengan menggunakan algoritma queue, sistem antrian dapat diatur dengan baik sehingga pasien dapat mengetahui ketersediaan obat dan nomor antrian mereka tanpa harus datang terlebih dahulu ke apotek. Hal ini membantu mengurangi waktu tunggu pasien dan meningkatkan pengalaman pelayanan di apotek [1].
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
![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/e11e6c0b-8c9b-4c19-9f0b-c5c24f23ec4d)

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
![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/b9a76f01-35c1-4d07-9e9c-c727e3ee9232)


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
    enqueueAntrian("Andi", "123456789");
    enqueueAntrian("Budi", "987654321");
    viewQueue();
    dequeueAntrian();
    viewQueue();
    return 0;
}
```
### Screenshot
![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/9430a651-1b87-4ef4-bfbb-5eb785e2ff08)

## Kesimpulan 
<p align = "justify">
Dalam konteks penerapan algoritma queue pada aplikasi pemesanan obat berbasis mobile di Apotek Aruba Farma Depok, dapat disimpulkan bahwa:

1. **Efisiensi Pelayanan**: Penggunaan algoritma queue membantu meningkatkan efisiensi pelayanan dengan mengatur antrian pasien secara berurutan, sehingga meminimalkan waktu tunggu dan mempercepat proses pemesanan obat [1].

2. **Ketersediaan Obat**: Pasien dapat dengan mudah mengetahui ketersediaan obat yang dibutuhkan melalui aplikasi mobile tanpa harus datang langsung ke apotek, sehingga memudahkan proses pemesanan dan pengambilan obat [1].

3. **Peningkatan Pengalaman Pasien**: Dengan adanya aplikasi mobile berbasis queue, pasien merasa lebih terbantu dan terlayani dengan baik, sehingga meningkatkan kualitas pelayanan di Apotek Aruba Farma Depok [1].

Dengan demikian, penerapan algoritma queue pada aplikasi pemesanan obat berbasis mobile memberikan manfaat yang signifikan dalam meningkatkan efisiensi, ketersediaan obat, dan pengalaman pasien dalam mendapatkan layanan farmasi.
</p>

## Daftar Pustaka

[1]. Agam Rizky, PENERAPAN ALGORITMA QUEUE PADA APLIKASI PEMESANAN OBAT BERBASIS MOBILE PADA APOTEK ARUBA FARMA DEPOK, Volume 1, No. 5, LOGIC : Jurnal Ilmu Komputer dan Pendidikan, Agustus 2023.

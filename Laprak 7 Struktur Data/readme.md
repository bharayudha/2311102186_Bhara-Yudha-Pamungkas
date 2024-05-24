# <h1 align="center"> Laporan Praktium Modul 7 Queue </h1>
<p align="center"> Bhara Yudha Pamungkas <p>
<p align="center"> 2311102186 </p>

## Dasar Teori
<p align ="justify"> 
Queue adalah struktur data yang mengikuti prinsip first-in-first-out (FIFO).
Data memasuki antrian di satu ujung dan keluar di ujung lainnya. Artinya item pertama yang dimasukkan ke dalam antrian juga merupakan item pertama yang dihapus [1].

Algoritma antrian banyak digunakan dalam berbagai aplikasi dan teknologi untuk mengatur antrian dan memproses data secara berurutan.
Dalam konteks aplikasi pemesanan obat berbasis seluler di Apotek Aruba Farma Depok, penerapan algoritma antrian membantu meningkatkan efisiensi dan kualitas layanan dengan memastikan bahwa pasien menerima obat sesuai urutan antriannya [1].

Menggunakan antrian algoritma, Anda dapat mengelola sistem antrian  dengan lebih baik sehingga pasien  mengetahui ketersediaan obat dan nomor antriannya tanpa harus datang ke apotek terlebih dahulu.
Hal ini  mengurangi waktu tunggu pasien dan meningkatkan pengalaman pelayanan di apotek [1].
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
![Screenshot (252)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/f1f686fd-7ef4-4cb7-8336-5ba79048d900)


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
![Screenshot (253)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/211b112b-ee49-42e6-ad82-66a4ff911acf)



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
![Screenshot (254)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/ac51395a-3fe3-43ec-8a68-2c0148884c63)


## Kesimpulan 
<p align = "justify">
Sehubungan dengan penerapan algoritma antrian pada aplikasi pemesanan obat berbasis mobile  Apotek Aruba Farma Depok, maka dapat diperhatikan hal-hal sebagai berikut

1. **Efisiensi Pelayanan**: Penggunaan algoritma antrian berkontribusi terhadap: Antrian pasien yang berurutan meningkatkan efisiensi layanan, meminimalkan waktu tunggu, dan mempercepat proses pemesanan obat [1].

2. **Ketersediaan Obat**: Pasien dapat dengan mudah mengecek ketersediaan obat yang dibutuhkan melalui aplikasi mobile tanpa harus datang langsung ke apotek sehingga  proses pemesanan dan pengambilan obat akan menjadi lebih mudah [1].

3. **Peningkatan pengalaman pasien**: Dengan  aplikasi seluler berbasis antrian , pasien merasakan dukungan dan layanan yang lebih  baik, sehingga meningkatkan kualitas layanan di Apotek Aruba Farma Depok [1].

Oleh karena itu, penerapan algoritma antrian pada aplikasi pemesanan obat secara mobile memberikan manfaat yang signifikan dalam meningkatkan efisiensi, ketersediaan obat, dan pengalaman pasien dalam memanfaatkan layanan obat.
</p>

## Daftar Pustaka

[1]. Agam Rizky, PENERAPAN ALGORITMA QUEUE PADA APLIKASI PEMESANAN OBAT BERBASIS MOBILE PADA APOTEK ARUBA FARMA DEPOK, Volume 1, No. 5, LOGIC : Jurnal Ilmu Komputer dan Pendidikan, Agustus 2023.

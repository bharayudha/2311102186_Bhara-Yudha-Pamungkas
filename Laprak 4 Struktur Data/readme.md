# <h1 align="center"> Laporan Praktium Modul 4 Circular dan Non-Circular Linked List </h1>
<p align="center"> Bhara Yudha Pamungkas <p>
<p align="center"> 2311102186 </p>

## Dasar Teori
<div style="text-align: right">
Daftar tertaut adalah struktur data yang bisa linier atau nonlinier, bergantung pada implementasinya. Dalam daftar tertaut, elemen dialokasikan secara acak di memori, dan elemen dihubungkan melalui pointer. Hal ini memungkinkan penggunaan memori yang lebih efisien dibandingkan dengan array. Dalam bab ini, kita akan membahas karakteristik empat jenis daftar tertaut: daftar tertaut tunggal, daftar tertaut ganda, daftar tertaut melingkar, dan daftar tertaut header.


Daftar tertaut melingkar adalah tipe khusus dari daftar tertaut di mana simpul terakhir menunjuk kembali ke simpul pertama, sehingga menciptakan perulangan. Hal ini memungkinkan akses berkelanjutan ke daftar tanpa awal atau akhir yang ditentukan. Daftar tertaut melingkar berguna dalam aplikasi di mana data perlu diproses secara terus menerus, seperti aplikasi atau simulasi waktu nyata [1].

Selain karakteristiknya, daftar tertaut juga digunakan dalam berbagai aplikasi. Mereka sangat berguna dalam sistem manajemen memori, di mana pengumpulan sampah dapat dilakukan ketika hanya ada sedikit ruang atau tidak ada ruang tersisa sama sekali dalam daftar penyimpanan kosong, atau ketika CPU menganggur dan mempunyai waktu untuk melakukan pengumpulan. Sistem manajemen memori menggunakan konsep pemadatan, yang mengumpulkan semua blok ruang kosong dan menempatkannya di satu lokasi dalam satu blok kosong. Hal ini memungkinkan penggunaan memori lebih efisien dan mengurangi fragmentasi [1].

</div>

## Guided

### Guided 1. Single linked Non-Circular List
```C++
#include <iostream>
using namespace std;
/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    int data;
    Node *next;
};
Node *head;
Node *tail;

// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}

// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}

// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}

// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List Kosong!" << endl;
    }
}
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
void hapusTengah(int posisi)
{
    Node *bantu, *hapus, *sebelum;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                sebelum = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}
void ubahDepan(int data)
{
    if (isEmpty() == 0)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == 0)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
void ubahBelakang(int data)
{
    if (isEmpty() == 0)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
init();
insertDepan(3);
tampil();
insertBelakang(5);
tampil();
insertDepan(2);
tampil();
insertDepan(1);
tampil();
hapusDepan();
tampil();
hapusBelakang();
tampil();
insertTengah(7, 2);
tampil();
hapusTengah(2);
tampil();
ubahDepan(1);
tampil();
ubahBelakang(8);
tampil();
ubahTengah(11, 2);
tampil();
return 0;
}
```

### Screenshot
![Screenshot (235)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/9f35944b-0339-4255-a516-baf6b04c0512)



### Guided 2 Single linked Circular 
```C++
#include <iostream>
#include <string>

using namespace std;

/// PROGRAM SINGLE LINKED LIST CIRCULAR

// Deklarasi Struct Node
struct Node
{
    string data;
    Node *next;
};

Node *head, *tail;

void init()
{
    head = NULL;
    tail = NULL;
}

// Pengecekan
int isEmpty()
{
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
Node* buatNode(string data)
{
    Node* baru = new Node;
    baru->data = data;
    baru->next = NULL;
    return baru;
}

// Tambah Depan
void insertDepan(string data)
{
    Node* baru = buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = baru;
        tail->next = head;
    }
    else
    {
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data)
{
    Node* baru = buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = baru;
        tail->next = head;
    }
    else
    {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
}

// Hapus Depan
void hapusDepan()
{
    if (isEmpty() == 0)
    {
        Node* hapus = head;
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next;
            tail->next = head;
        }
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        Node* hapus = tail;
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node* current = head;
            while (current->next != tail)
            {
                current = current->next;
            }
            current->next = head;
            tail = current;
        }
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Tampilkan List
void tampil()
{
    if (isEmpty() == 0)
    {
        Node* current = head;
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 0)
    {
        Node* baru = buatNode(data);
        if (posisi == 1)
        {
            insertDepan(data);
        }
        else
        {
            Node* bantu = head;
            for (int i = 1; i < posisi - 1; i++)
            {
                if (bantu->next != head)
                {
                    bantu = bantu->next;
                }
                else
                {
                    cout << "Posisi tidak valid!" << endl;
                    return;
                }
            }
            baru->next = bantu->next;
            bantu->next = baru;
        }
    }
    else
    {
        insertDepan(data);
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        if (posisi == 1)
        {
            hapusDepan();
        }
        else
        {
            Node* hapus;
            Node* bantu = head;
            for (int i = 1; i < posisi - 1; i++)
            {
                if (bantu->next != head)
                {
                    bantu = bantu->next;
                }
                else
                {
                    cout << "Posisi tidak valid!" << endl;
                    return;
                }
            }
            hapus = bantu->next;
            bantu->next = hapus->next;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();

    return 0;
}

```

### Screenshot
![Screenshot (236)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/13fd376c-f0a9-4c3b-9bd8-3df49cec3a44)




## Unguided

### Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM
mahasiswa, dengan menggunakan input dari user.

1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan
NIM mahasiswa, berikut contoh tampilan output dari nomor 1:

- Tampilan Menu

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/f123c124-e000-4cd7-a45d-24a5c40f3897)

- Tampilan Operasi Tambah

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/9c3f290c-f38f-4054-b66c-fda108e3efe3)

- Tampilan Operasi hapus

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/67df71ef-b2fb-4339-b2ee-5b5d12283c6d)

- Tampilan Operasi Ubah

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/7922b99b-a2f4-4f52-ba11-9c6eb8667d1f)

- Tampilan Operasi tampil data

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/24503401-6fdd-4ed7-826a-3e8c1eb4b0fd)

2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/6b09d7e6-2c62-411d-9fda-ba874d58a4d5)

3. Lakukan perintah berikut:

a) Tambahkan data berikut diantara Farrel dan Denis: Wati 2330004

b) Hapus data Denis

c) Tambahkan data berikut di awal: Owi 2330000

d) Tambahkan data berikut di akhir: David 23300100

e) Ubah data Udin menjadi data berikut: Idin 23300045

f) Ubah data terkahir menjadi berikut: Lucy 23300101

g) Hapus data awal

h) Ubah data awal menjadi berikut: Bagas 2330002

i) Hapus data akhir

j) Tampilkan seluruh data


```C++
#include <iostream>
#include <string>

using namespace std;

// Deklarasi struct Node
struct Node
{
    string nama;
    int nim;
    Node *next;
};

// Deklarasi variabel global
Node *head;
Node *tail;

// Fungsi untuk menginisialisasi linked list
void init()
{
    head = NULL;
    tail = NULL;
}

// Fungsi untuk mengecek apakah linked list kosong
bool isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Fungsi untuk memasukkan data di depan linked list
void insertDepan(string nama, int nim)
{
    // Membuat node baru
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;

    // Menghubungkan node baru ke node selanjutnya (sebelumnya head)
    baru->next = head;

    // Memperbarui head untuk menunjuk ke node baru
    head = baru;

    // Jika tail masih kosong, maka tail juga menunjuk ke node baru
    if (tail == NULL)
    {
        tail = baru;
    }
}

// Fungsi untuk memasukkan data di belakang linked list
void insertBelakang(string nama, int nim)
{
    // Membuat node baru
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;

    // Jika linked list kosong, maka node baru menjadi node pertama dan terakhir
    if (isEmpty())
    {
        head = tail = baru;
    }
    // Jika linked list tidak kosong, maka node baru ditambahkan di belakang tail
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

// Fungsi untuk menghitung jumlah node dalam linked list
int hitungList()
{
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Fungsi untuk memasukkan data di tengah linked list
void insertTengah(string nama, int nim, int posisi)
{
    // Mengecek apakah posisi valid
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan!" << endl;
        return;
    }
    // Jika posisi sama dengan 1, maka masukkan data di depan
    else if (posisi == 1)
    {
        insertDepan(nama, nim);
        return;
    }

    // Membuat node baru
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;

    // Mencari node di posisi sebelum posisi yang diinginkan
    Node *bantu = head;
    int nomor = 1;
    while (nomor < posisi - 1)
    {
        bantu = bantu->next;
        nomor++;
    }

    // Menghubungkan node baru di antara node bantu dan node selanjutnya
    baru->next = bantu->next;
    bantu->next = baru;
}

// Fungsi untuk menghapus data di depan linked list
void hapusDepan()
{
    // Jika linked list kosong, maka tampilkan pesan
    if (isEmpty())
    {
        cout << "Linked list kosong!" << endl;
        return;
    }

    // Menyimpan node yang akan dihapus
    Node *hapus = head;

    // Memperbarui head untuk menunjuk ke node selanjutnya
    head = head->next;

    // Jika head menjadi NULL, maka tail juga menjadi NULL
    if (head == NULL)
    {
        tail = NULL;
    }

    // Menghapus node yang disimpan
    delete hapus;
}

// Fungsi untuk menghapus data di belakang linked list
void hapusBelakang()
{
    // Jika linked list kosong, maka tampilkan pesan
    if (isEmpty())
    {
        cout << "Linked list kosong!" << endl;
        return;
    }

    // Menyimpan node yang akan dihapus
    Node *hapus = tail;

    // Mencari node sebelum node terakhir
    Node *bantu = head;
    while (bantu->next != tail)
    {
        bantu = bantu->next;
    }

    // Memperbarui tail
    // Memperbarui tail untuk menunjuk ke node sebelum node terakhir
    tail = bantu;
    tail->next = NULL;

    // Menghapus node yang disimpan
    delete hapus;
}

// Fungsi untuk menghapus data di tengah linked list
void hapusTengah(int posisi)
{
    // Mengecek apakah posisi valid
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan!" << endl;
        return;
    }
    // Jika posisi sama dengan 1, maka hapus data di depan
    else if (posisi == 1)
    {
        hapusDepan();
        return;
    }

    // Mencari node sebelum node yang akan dihapus
    Node *bantu = head;
    Node *hapus;
    int nomor = 1;
    while (nomor < posisi - 1)
    {
        bantu = bantu->next;
        nomor++;
    }

    // Menyimpan node yang akan dihapus
    hapus = bantu->next;

    // Menghubungkan node bantu ke node selanjutnya dari node yang dihapus
    bantu->next = hapus->next;

    // Jika node yang dihapus adalah tail, maka perbarui tail
    if (hapus == tail)
    {
        tail = bantu;
    }

    // Menghapus node yang disimpan
    delete hapus;
}

// Fungsi untuk mengubah data di depan linked list
void ubahDepan(string nama, int nim)
{
    // Jika linked list kosong, maka tampilkan pesan
    if (isEmpty())
    {
        cout << "Linked list kosong!" << endl;
        return;
    }

    // Mengubah data node head
    head->nama = nama;
    head->nim = nim;

    cout << "Data berhasil diubah!" << endl;
}

// Fungsi untuk mengubah data di belakang linked list
void ubahBelakang(string nama, int nim)
{
    // Jika linked list kosong, maka tampilkan pesan
    if (isEmpty())
    {
        cout << "Linked list kosong!" << endl;
        return;
    }

    // Mengubah data node tail
    tail->nama = nama;
    tail->nim = nim;

    cout << "Data berhasil diubah!" << endl;
}

// Fungsi untuk mengubah data di tengah linked list
void ubahTengah(string nama, int nim, int posisi)
{
    // Mengecek apakah posisi valid
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan!" << endl;
        return;
    }
    // Jika posisi sama dengan 1, maka ubah data di depan
    else if (posisi == 1)
    {
        ubahDepan(nama, nim);
        return;
    }

    // Mencari node di posisi yang diinginkan
    Node *bantu = head;
    int nomor = 1;
    while (nomor < posisi)
    {
        bantu = bantu->next;
        nomor++;
    }

    // Mengubah data node yang ditemukan
    bantu->nama = nama;
    bantu->nim = nim;

    cout << "Data berhasil diubah!" << endl;
}

// Fungsi untuk menghapus seluruh isi linked list
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "Linked list berhasil dihapus!" << endl;
}

// Fungsi untuk menampilkan isi linked list
void tampil()
{
    Node *bantu = head;
    if (isEmpty())
    {
        cout << "Linked list kosong!" << endl;
    }
    else
    {
        cout << "Data Mahasiswa" << endl;
        cout << "Nama"
             << "            "
             << "Nim" << endl
             << endl;
        while (bantu != NULL)
        {
            cout << bantu->nama << "            " << bantu->nim << endl;
            bantu = bantu->next;
        }
        cout << endl;
    }
}

int main()
{
    init();
    string nama;
    int nim;
    int posisi;
    while (true)
    {

        // Menu program
        cout << "Program Single Linked List Non-Circular" << endl
             << "\n";
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus list" << endl;
        cout << "11. Tampilkan" << endl;
        cout << "0. Break/End" << endl;
        int pilihan;
        cout << "Pilih Operasi: ";
        cin >> pilihan;
        cout << "\n";

        switch (pilihan)
        {
        case 1:
            cout << "-Tambah Depan-" << endl
                 << endl;
            cout << "Masukan Nama: ";
            cin >> nama;
            cout << "Masukan NIM: ";
            cin >> nim;
            cout << endl
                 << endl;
            insertDepan(nama, nim);
            cout << "Data telah dimasukan " << endl;
            break;
        case 2:
            cout << "-Tambah Belakang-" << endl
                 << endl;
            cout << "Masukan nama: ";
            cin >> nama;
            cout << "Masukan NIM: ";
            cin >> nim;
            insertBelakang(nama, nim);
            cout << "Data Telah dimasukan: " << endl;
            break;
        case 3:
            cout << "-Tambah Tengah-" << endl
                 << endl;
            cout << "Masukan Nama: ";
            cin >> nama;
            cout << "Masukan NIM: ";
            cin >> nim;
            cout << "Masukan Posisi: ";
            cin >> posisi;
            insertTengah(nama, nim, posisi);
            cout << "Data Telah dimasukkan" << endl;
            break;
        case 4:
            cout << "-Ubah Depan-" << endl
                << endl;
            cout << "Masukan Nama: ";
            cin >> nama;
            cout << "Masukan Nim: ";
            cin >> nim;
            ubahDepan(nama, nim);
            break;
        case 5:
            cout << "-Ubah Belakang-" << endl
                << "\n";
            cout << "Masukan Nama: ";
            cin >> nama;
            cout << "Masukan NIM: ";
            cin >> nim;
            ubahBelakang(nama, nim);
            cout << "n"
                << "\n";
            break;
        case 6:
            cout << "-Ubah tengah-" << endl
                << "\n";
            cout << "Masukan Nama: ";
            cin >> nama;
            cout << "Masukan NIM: ";
            cin >> nim;
            cout << "Masukan Posisi: ";
            cin >> posisi;
            ubahTengah(nama, nim, posisi);
            cout << "\n"
                << "\n";
            break;
        case 7:
            hapusDepan();
            break;
        case 8:
            hapusBelakang();
            break;
        case 9:
            cout << "\n";
            cout << "Masukan Posisi: ";
            cin >> posisi;
            hapusTengah(posisi);
            break;
        case 10:
            clearList();
            break;
        case 11:
            tampil();
            break;
        case 0:
            exit(0);
        }
    }
    return 0;
}
```

### Screenshot

1. Tampilan Prosedur

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/c8a6c19e-6ab1-4c3e-b63a-6d860e349ac2)


![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/980c879a-4675-4b0d-815e-382612296a94)


2. Tampilan Akhir

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/c32ae40c-c7d1-4991-9d6f-ef1459715a32)

3. Perintah

a). Tambahkan data berikut diantara Farrel dan Denis: Wati 2330004

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/e464b7c3-d506-4bc5-9504-c5d5092d6b6d) 
   
b). Hapus Data Denis

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/bfcb5dde-dd8e-47f1-b69e-1386e869d2b0)

c). Tambahkan data berikut di awal: Owi 2330000

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/15078d18-3e58-4c53-a101-2c3838d3edc5)

d). Tambahkan data berikut di akhir: David 23300100

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/2b1c46c2-5339-483a-b04f-9deb085ed338)

e). Ubah data Udin menjadi data berikut: Idin 23300045

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/2e1d2c58-4d63-4be3-b5bf-20e17f89b2c3)

f). Ubah data terkahir menjadi berikut: Lucy 23300101

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/23dad5b3-8919-462e-9870-4ea5baba6857)

g). Hapus Data Awal

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/23ebaab8-76ae-4f4d-8af3-12cec59f4ffe)


h). Ubah data awal menjadi berikut: Bagas 2330002

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/ad677666-57fb-4b4e-b52d-ef6dfecf323a)

i). Hapus data akhir

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/715f773c-0f4b-43b0-8fa8-e009cd806bf8)

J). Tampilkan Seluruh Data

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/1eaa7ba4-ca13-4bce-b284-8f24c04d5d30)

## Daftar Pustaka

[1]. Sachi Nandan Mohanty, Pabitra Kumar Tripathy, Data Structure and Algorithms Using C++: A Practical Implementation, New York:Scrivener Publishing LLC, 14 January 2021.

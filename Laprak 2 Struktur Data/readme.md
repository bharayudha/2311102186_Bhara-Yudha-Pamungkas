# <h1 align="center">Laporan Praktikum Modul 2 - Array</h1>
<p align="center">Bhara Yudha Pamungkas</p>
<p align="center">2311102186 / IF-11-E</p>


## Dasar Teori

A.Pengertian Array

Array adalah suatu struktur yang terdiri dari sejumlah elemen yang memiliki tipe data yang sama. Elemen-elemen array tersusun secara sekuensial dalam memori komputer. Semua elemem array bertipe sama. Array cocok untuk organisasi kumpulan data homogen yang ukuran atau jumlah elemen maksimumnya telah diketahui dari awal. Homogen adalah bahwa setiap elemen dari sebuah array tertentu haruslah mempunyai tipe data yang sama.
Array dibagi menjadi :
  
1. Array Satu Dimensi
    
Array satu dimensi tidak lain adalah kumpulan elemen-elemen identik yang tersusun dalam satu baris, tetapi isi dari elemen tersebut boleh berbeda.  Dapat disebut juga dengan istilah vektor yang menggambarkan data dalam suatu urutan
Deklarasi : Type_Data Nama_Variabel [index] 
Misalnya : int A[5]; 

2.  Array Dua Dimensi 

Array dua dimensi yang sering digambarkan sebagai sebuah matriks merupakan perluasan dari sebuah array satu dimensi. Jika array satu dimensi hanya terdiri dari sebuah baris dengan beberapa kolom elemen maka array dua dimensi terdiri dari beberapa baris dan beberapa kolom elemen yang bertipe sama. Pendeklarasian array dua dimensi hampir sama dengan pendeklarasian array satu dimensi, kecuali bahwa array dua dimensi terdapat dua jumlah elemen array yang terdapat di dalam kurung siku dan keduanya boleh tidak sama.
Deklarasi : Type_Data Nama_Variabel [Index1] [index2]; 
Misal : int A[3][2];

 3.   Array Tiga Dimensi 
 
Array tiga dimensi digunakan untuk mengelola data dalam bentuk 3 dimensi atau tiga sisi. 
Deklarasi : Type_Data Nama_Variabel [index1] [ndex2] [index3]; 
Misal : int A [3][4][2];

4.   Array Banyak Dimensi

Sebenarnya array banyak dimensi ini tidak terlalu sering dipakai seperti halnya array satu dimensi, dua dimensi, dan tiga dimensi. Array banyak dimensi ini pada dasarnya sama dengan array sebelimnya kecuali pada jumlah dimensinya.
Deklarasi : Type_Data Nama_Variabel [index1] [ndex2] [index3] [ndex4].....;
Misal : int A [3][4][2][5];

## Guided 

### 1. Program input array tiga dimensi

```C++
    #include <iostream>
    using namespace std;
    // PROGRAM INPUT ARRAY 3 DIMENSI
    int main()
    {
    // Deklarasi array
    int arr[2][3][3];
    // Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout <<endl;
    }
    }
```

    Program tersebut merupakan sebuah program dalam bahasa C++ yang memungkinkan pengguna untuk menginputkan data ke dalam array tiga dimensi dan kemudian menampilkannya. Program ini terdiri dari tiga bagian utama:

#### Deskripsi Program

Program tersebut berfungsi untuk menginputkan data ke dalam array tiga dimensi dan kemudian menampilkannya. Program ini terdiri dari tiga bagian utama:

1.Input Data:

Program meminta kita untuk memasukkan nilai-nilai ke dalam array tiga dimensi menggunakan tiga nested loop.

2.Output Data:

Setelah semua data dimasukkan, program akan menampilkan nilai-nilai dari array tiga dimensi yang telah dimasukkan oleh kita.

3.Tampilan Array:

Program juga menampilkan array dalam bentuk yang lebih sederhana, dengan menampilkan setiap baris dari array dalam satu baris dengan menggunakan perulangan.

### 2. Program mencari nilai maksimal pada array

```C++
     #include <iostream>
     using namespace std;
     int main()
     {
     int maks, a, i = 1, lokasi;
     cout << "Masukkan panjang array: ";
     cin >> a;
     int array[a];
     cout << "Masukkan " << a << " angka\n";
     for (i = 0; i < a; i++)
     {
     cout << "Array ke-" << (i) << ": ";
     cin >> array[i];
     }
     maks = array[0];
     for (i = 0; i < a; i++)
     {
     if (array[i] > maks)
     {
     maks = array[i];
     lokasi = i;
     }
     }
     cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
     }
```

#### Deskrpisi Program

Program tersebut bertujuan untuk mencari nikai maksimum yang sudah diinputkan.

## Unguided

### 1.Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!
```C++
#include <iostream> 
 
using namespace std; 
 
int main(){ 
    int array[10]; 
     
    cout << "Masukan data array: " << endl; 
    for (int i = 1; i <= 10; i++) { 
        cout<<"Array ke-"<<(i)<<" : "; 
        cin >> array[i]; 
    } 
     
    cout << "Data Array  : "; 
    for(int i = 1; i <= 10; i++) { 
        cout << array[i] << " "; 
    } 
    cout << endl; 
 
    cout << "Nomor genap : "; 
    for(int i = 1; i <= 10; i++) { 
        if (array[i] % 2 == 0){ 
            cout << array[i] << " "; 
        } 
    } 
    cout << endl; 
 
    cout << "Nomor ganjil: "; 
    for (int i = 1; i <= 10; i++) { 
        if (array[i] % 2 != 0) { 
            cout << array[i] << " "; 
        } 
    } 
    cout << endl; 
 
    return 0; 
} 
```

#### Output 

![Screenshot (222)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/f8c9bba0-4bbe-4f4e-85c9-61f139fd5829)



### Deskrpisi Program

Program tersebut bertujuan untuk memisahkan bilangan genap dan ganjil dari sebuah array yang berisi 10 bilangan yang diinputkan.

### 2.Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!
```C++
#include <iostream> 
 
using namespace std; 
 
int main() { 
  int x, y, z; 
 
  cout << "Masukkan ukuran array (x y z): "; 
  cin >> x >> y >> z; 
 
  int arr[x][y][z]; 
 
  for (int i = 0; i < x; i++) { 
    for (int j = 0; j < y; j++) { 
      for (int k = 0; k < z; k++) { 
        cout << "Input array [" << i << "][" << j << "][" << k 
<< "] = "; 
        cin >> arr[i][j][k]; 
      } 
    } 
    cout << endl; 
  } 
 
  cout << endl; 
  for (int i = 0; i < x; i++) { 
    for (int j = 0; j < y; j++) { 
      for (int k = 0; k < z; k++) { 
        cout << "Data array [" << i << "][" << j << "][" << k 
<< "] = " << arr[i][j][k] << endl; 
      } 
    } 
  } 
 
  cout << endl; 
  for (int i = 0; i < x; i++) { 
    for (int j = 0; j < y; j++) { 
for (int k = 0; k < z; k++) { 
cout << arr[i][j][k] << " "; 
} 
cout << endl; 
} 
cout << endl;  
} 
return 0; 
}
```

#### Output

![Screenshot (222)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/f8c9bba0-4bbe-4f4e-85c9-61f139fd5829)


### Deskrpisi Program

Program tersebut bertujuan untuk memasukkan jumlah elemen matriks dan ukuran matriks dalam format "baris kolom", kemudian meminta kita untuk memasukkan nilai-nilai elemen dari matriks tiga dimensi. Setelah itu, program akan menampilkan data matriks beserta tampilan matriks satu per satu dengan nomor urutan matriks.

### 3.Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!
```C++
#include <iostream> 
#include <conio.h> 
 
using namespace std; 
 
void menu() 
{ 
    cout << "=====Menu=====" << endl; 
    cout << "1. Input Array" << endl; 
    cout << "2. Tampil Array" << endl; 
    cout << "3. Cari Nilai Minimum" << endl; 
    cout << "4. Cari Nilai Maksimum" << endl; 
    cout << "5. Hitung Rata-Rata" << endl; 
    cout << "Masukkan Pilihan : "; 
} 
    
    int minimum(int isi[]){ 
    int min = isi[0]; 
 
 
    for (int x=1;x<10;x++){ 
        if (isi[x]<min){ 
            min = isi[x]; 
        } 
    } 
    cout << "Nilai Minimum: " << min << endl; 
} 
 
    int maksimum (int isi []){ 
    int max = 0; 
 
    for (int x=0;x<10;x++){ 
        if (isi[x]>max){ 
            max = isi[x]; 
        } 
    } 
    cout << "Nilai Maksimum: " << max << endl; 
    } 
 
    float rata(int isi[]){ 
    int i; 
    float total = 0; 
    float hasil; 
 
    for (i=0;i<10;i++){ 
        total += isi[i]; 
    } 
    hasil = total/10; 
    cout << "Rata-ratanya adalah: " << hasil << endl; 
} 
 
 
int main() 
{ 
    int pil, bil[10]; 
    char opsi; 
    bool x; 
 
    do{ 
    menu(); 
    cin >> pil; 
    cout << endl; 
 
    if (pil == 1 || x == true || pil == 0){ 
        x = true; 
    switch (pil){ 
        case 1: 
            cout << "Masukkan Bilangan yang Anda inginkan" << 
endl; 
        for(int i=0; i<10;i++){ 
            cout << "Bilangan ke-" << i+1 << " : "; 
            cin >> bil[i]; 
        } 
        break; 
 
        case 2: 
            cout << "Data Array yang sudah dimasukkan" << 
endl; 
            for(int b=0; b<10; b++){ 
                cout << bil[b] << " "; 
            } 
            break; 
 
        case 3: 
            minimum(bil); 
            cout << endl; 
        break; 
 
        case 4: 
            maksimum(bil); 
            cout << endl; 
        break; 
 
        case 5: 
            rata(bil); 
            cout << endl; 
        break; 
    } 
 
 
    }else if (x == false && pil != 1) 
    { 
    cout << "Silahkan input nomor 1 dulu."; 
    goto mainloop; 
    } 
 
    mainloop: 
    cout << endl; 
    cout << "Apa Anda ingin memilih menu yang lain? [y/n]"; 
    opsi=getch(); 
    cout << endl; 
 
    }while (opsi == 'y'); 
    if (opsi == 'n'){ 
        cout << "Selesai"; 
    } 
 
return 0; 
} 
```

#### Output

![Screenshot (222)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/f8c9bba0-4bbe-4f4e-85c9-61f139fd5829)

![Screenshot (222)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/f8c9bba0-4bbe-4f4e-85c9-61f139fd5829)

![Screenshot (222)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/f8c9bba0-4bbe-4f4e-85c9-61f139fd5829)


### Deskrpisi Program

Program tersebu bertujuan untuk memasukkan jumlah elemen dalam sebuah array, kemudian mengisi array dengan nilai-nilai yang dimasukkan oleh pengguna. Setelah itu, kita dapat memilih menu untuk mencari nilai maksimum, minimum, atau rata-rata dari elemen-elemen array yang dimasukkan. Program menggunakan switch case untuk mengimplementasikan pilihan kita, di mana setiap kasus melakukan iterasi melalui array untuk mencari nilai maksimum, minimum, atau menghitung rata-rata, dan kemudian menampilkan hasilnya sesuai dengan pilihan yang dibuat oleh kita. Jika kita memasukkan pilihan yang tidak valid, program akan memberikan pesan kesalahan.

## Kesimpulan

Array adalah sebuah struktur data yang terdiri dari kumpulan elemen dengan tipe data yang sama, yang tersimpan secara berurutan di dalam memori komputer. Setiap elemen dalam array diidentifikasi oleh indeksnya, dimulai dari angka 0. Ada tiga jenis array yang paling umum digunakan, yaitu array satu dimensi, array dua dimensi, dan array tiga dimensi atau multidimensi. Kelebihan dari penggunaan array adalah memungkinkan untuk menyimpan banyak nilai dengan satu nama variabel, serta memiliki kemampuan untuk menyimpan data dalam lebih dari satu dimensi. Hal ini membuat array menjadi sangat berguna dalam pemrograman untuk mempermudah pengelolaan data dan menghemat penggunaan variabel. Selain itu, array juga dapat digunakan untuk mempermudah proses pengolahan data, seperti mengurutkan, mencari nilai maksimum atau minimum, dan menghitung rata-rata. Namun, penggunaan array juga memiliki beberapa kelemahan. Alokasi memori yang tepat dan pengelolaan memori yang efisien sangat penting dalam penggunaan array untuk mencegah terjadinya kesalahan atau kebocoran memori. Oleh karena itu, diperlukan pemahaman yang baik tentang penggunaan dan manajemen array untuk menghindari masalah pada program yang dihasilkan.

## Referensi

https://osf.io/preprints/osf/vyech

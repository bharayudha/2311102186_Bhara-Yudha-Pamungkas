# <h1 align="center"> Laporan Praktium Modul 8 Searching</h1>
<p align="center"> Bhara Yudha Pamungkas <p>
<p align="center"> 2311102186 </p>

## Dasar Teori
<p align = "justify">    
Binary Search adalah metode pencarian  data yang diurutkan secara berurutan.
Algoritma ini bekerja dengan cara membagi data menjadi dua bagian kemudian memeriksa elemen tengah untuk menentukan apakah data yang dicari ada di sebelah kiri atau di sebelah kanan.
Proses ini berulang hingga data yang dicari ditemukan [1].
    
Prinsip dasar pencarian biner adalah “divide and Conquer” yaitu mempercepat proses pencarian dengan membagi ruang pencarian data  menjadi bagian-bagian yang lebih kecil.
Keuntungan dari pencarian biner adalah dapat secara efisien mencari data dalam jumlah besar dengan jumlah perhitungan yang sedikit.
Algoritma ini cocok digunakan dengan data yang diurutkan [1].

Regular Search [Removed]REGEX) merupakan metode pencarian string yang tidak hanya mencari string tertentu, namun juga mencari berdasarkan pola pada string tersebut.
Algoritme ini memungkinkan pencarian berdasarkan pola tertentu dalam data.
REGEX didasarkan pada konsep finite automata, dimana pencarian dilakukan dengan membentuk  grafik berarah dengan keadaan yang mewakili karakter dalam string pencarian [1].

Keuntungan ekspresi pencarian kanonik adalah Anda dapat mencari data berdasarkan pola tertentu tanpa harus mengurutkan data.
Algoritma ini secara efektif  mengeksekusi setiap karakter dalam jangka waktu yang tetap.
Dengan memahami teori dasar pencarian biner dan ekspresi pencarian reguler, Anda dapat memilih metode pencarian  sesuai dengan kebutuhan dan karakteristik data yang akan dicari [1].

</p>

## Guided

### Guided 1
Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.

```C++
#include <iostream>
using namespace std;
int main()
{
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;
    // algoritma Sequential Search
    for (i = 0; i < n; i++)
    {
        if (data[i] == cari)
        {
            ketemu = true;
            break;
        }
    }
    cout << "\t Program Sequential Search Sederhana\n " << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    if (ketemu)
    {
        cout << "\n angka " << cari << " ditemukan pada indeks ke -" << i << endl;
    }
    else
    {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}
```
### Screenshot Output
![Screenshot (282)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/b05c0db0-ba7c-4623-ac75-eb810252fe96)



### Guided 2
Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search.

```C++
#include <iostream>
#include <iomanip>
using namespace std;
// Deklarasi array dan variabel untuk pencarian
int arrayData[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;
void selection_sort(int arr[], int n)
{
    int temp, min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        // Tukar elemen
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
void binary_search(int arr[], int n, int target)
{
    int awal = 0, akhir = n - 1, tengah, b_flag = 0;
    while (b_flag == 0 && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (arr[tengah] == target)
        {
            b_flag = 1;
            break;
        }
        else if (arr[tengah] < target)
        {
            awal = tengah + 1;
        }
        else
        {
            akhir = tengah - 1;
        }
    }
    if (b_flag == 1)
        cout << "\nData ditemukan pada index ke-" << tengah << endl;
    else
        cout << "\nData tidak ditemukan\n";
}
int main()
{
    cout << "\tBINARY SEARCH" << endl;
    cout << "\nData awal: ";
    // Tampilkan data awal
    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << arrayData[x];
    }
    cout << endl;
    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari;
    // Urutkan data dengan selection sort
    selection_sort(arrayData, 7);
    cout << "\nData diurutkan: ";
    // Tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << arrayData[x];
    }
    cout << endl;
    // Lakukan binary search
    binary_search(arrayData, 7, cari);
    return 0;
}
```

### Screenshot Output
![Screenshot (284)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/7c512915-1eb3-472e-ac85-f05483dd6a6f)




## Unguided 

### Unguided 1
Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk mencari huruf dalam kalimat dengan Binary Search
bool binarySearch(string kalimat, char hurufDicari) {
  // Inisialisasi indeks awal dan akhir
  int low = 0;
  int high = kalimat.length() - 1;

  // Looping selama indeks awal lebih kecil dari atau sama dengan indeks akhir
  while (low <= high) {
    // Hitung indeks tengah
    int mid = (low + high) / 2;

    // Periksa apakah huruf di indeks tengah sama dengan huruf yang dicari
    if (kalimat[mid] == hurufDicari) {
      // Huruf ditemukan, kembalikan true
      return true;
    } else if (kalimat[mid] < hurufDicari) {
      // Huruf yang dicari lebih besar, perbarui indeks awal
      low = mid + 1;
    } else {
      // Huruf yang dicari lebih kecil, perbarui indeks akhir
      high = mid - 1;
    }
  }

  // Huruf tidak ditemukan, kembalikan false
  return false;
}

int main() {
  // Deklarasi variabel untuk kalimat dan huruf yang dicari
  string kalimat;
  char hurufDicari;

  // Minta input kalimat dari pengguna
  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  // Minta input huruf yang dicari dari pengguna
  cout << "Masukkan huruf yang ingin dicari: ";
  cin >> hurufDicari;

  // Panggil fungsi binarySearch untuk mencari huruf
  bool ditemukan = binarySearch(kalimat, hurufDicari);

  // Tampilkan pesan berdasarkan hasil pencarian
  if (ditemukan) {
    cout << "Huruf '" << hurufDicari << "' ditemukan dalam kalimat." << endl;
  } else {
    cout << "Huruf '" << hurufDicari << "' tidak ditemukan dalam kalimat." << endl;
  }

  return 0;
}

```

### Screenshot Output
![Screenshot (279)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/9a753413-b10f-4206-ad42-2e1223f4f94a)

### Deskripsi Program
Program ini memberikan contoh implementasi algoritma Binary Search dalam pencarian keberadaan sebuah huruf dalam sebuah kalimat. Algoritma Binary Search secara efisien membagi rentang pencarian menjadi setengah pada setiap iterasi, sehingga mengurangi jumlah langkah yang diperlukan untuk menemukan hasil pencarian. Dengan demikian, program ini mengilustrasikan penggunaan Binary Search untuk mencari elemen dalam data terurut secara efisien.


### Unguided 2
Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat menggunakan algoritma searching!

```C++
#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk menghitung jumlah huruf vokal dalam kalimat
int HitungVokal(string kalimat)
{
    // Inisialisasi variabel penghitung
    int count = 0;

    // Looping melalui setiap karakter dalam kalimat
    for (int i = 0; i < kalimat.length(); i++)
    {
        // Mendapatkan karakter saat ini
        char huruf = kalimat[i];

        // Memeriksa apakah karakter adalah huruf vokal
        if (huruf == 'a' || huruf == 'A' ||
            huruf == 'e' || huruf == 'E' ||
            huruf == 'i' || huruf == 'I' ||
            huruf == 'o' || huruf == 'O' ||
            huruf == 'u' || huruf == 'U')
        {
            // Jika vokal, tambahkan ke penghitung
            count++;
        }
    }

    // Mengembalikan jumlah vokal
    return count;
}

int main()
{
    // Deklarasi variabel untuk kalimat
    string kalimat;

    // Minta input kalimat dari pengguna
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    // Panggil fungsi untuk menghitung vokal
    int jumlahVokal = HitungVokal(kalimat);

    // Tampilkan hasil penghitungan
    cout << "Jumlah huruf vokal dalam kalimat: " << jumlahVokal << endl;

    return 0;
}

```

### Screenshot Output
![Screenshot (280)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/14f273d9-87bf-4276-9811-b02f078a045b)

### Deskripsi Program
Program ini memberikan contoh penggunaan fungsi untuk menghitung jumlah huruf vokal dalam sebuah kalimat. Dengan menggunakan loop dan pengujian kondisi, program secara efisien dapat mengidentifikasi huruf vokal dan menghitung jumlahnya. Program ini menunjukkan bagaimana penggunaan string dan loop dapat digunakan untuk melakukan operasi sederhana pada teks.


### Unguided 3
Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
#include <iostream>

using namespace std;

int main() {
  // Data yang diberikan
  int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
  int n = sizeof(data) / sizeof(data[0]); // Jumlah elemen dalam data

  // Inisialisasi variabel untuk menghitung angka 4
  int count = 0;

  // Algoritma sequential search
  for (int i = 0; i < n; i++) {
    if (data[i] == 4) {
      count++; // Hitung angka 4
    }
  }

  // Hasil
  cout << "Jumlah angka 4: " << count << endl;

  return 0;
}

```


### Screenshot Output
![Screenshot (281)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/a878a862-3595-4b5a-bfc5-d52b06af2fab)


### Deskripsi Program
Program ini memberikan contoh sederhana dari algoritma pencarian sekuensial (Sequential Search) untuk menghitung jumlah kemunculan suatu angka dalam sebuah array. Meskipun sederhana, algoritma ini efektif untuk mencari elemen dalam dataset yang tidak diurutkan. Dengan menggunakan loop dan kondisi, program ini secara efisien menghitung jumlah kemunculan angka yang dicari dalam array.


## kesimpulan

<p align = "justify">
Dari hasil analisis perbandingan algoritma “binary search” dan  “canonical search formula” dalam pengambilan data, dapat disimpulkan bahwa kedua algoritma tersebut mempunyai kelebihan dan kekurangan masing-masing.
Pencarian biner cocok untuk mencari data yang besar dan terurut.
Sebaliknya, ekspresi penelusuran kanonik lebih fleksibel saat mencari pola.
Pilihan algoritma pencarian harus disesuaikan dengan karakteristik data dan kebutuhan pencarian spesifik.
Membandingkan penelusuran biner dan algoritme penelusuran kanonik, kami menyimpulkan bahwa penelusuran biner efisien untuk mencari data terurut berskala besar, sedangkan penelusuran kanonik lebih fleksibel untuk penelusuran berbasis pola.
Pemilihan algoritma pencarian harus disesuaikan dengan karakteristik data dan kebutuhan pencarian tertentu [1]
</p>

## Daftar Pustaka
[1]. Fenina Adline Twince Tobing, Rena Nainggolan, ANALISIS PERBANDINGAN PENGGUNAAN METODE BINARY SEARCH DENGAN REGULAR SEARCH EXPRESSION, Vol. 4, No. 2, 168-172, Oktober 2020.

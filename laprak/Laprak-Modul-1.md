# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Arvinanto Bahtiar</p>

## Dasar Teori
Tipe Data 
Tipe data adalah konsep yang digunakan dalam pemrograman untuk menunjukkan jenis 
nilai atau informasi yang disimpan dalam suatu variabel atau konstanta. 
Macam-macam tipe data yang akan digunakan adalah sebagai berikut : 
    1.  Tipe Data Primitif. 
    2.  Tipe Data Abstrak. 
    3.  Tipe Data Koleksi.

Tipe Data Primitif 
Primitive data type adalah jenis data dasar yang dapat menampung satu nilai pada satu 
waktu dan nilai tersebut tidak dapat diubah melalui referensi dari jenis data non 
primitive. Jika dua nilai dari jenis data primitif sama, maka jenis data primitif tersebut 
dianggap sama. Adapun daftar tipe data primitif yang umum digunakan dalam bahasa 
pemrograman C++ yaitu :  
    1.  Int : Tipe data integer adalah salah satu tipe data primitif dalam pemrograman 
        yang digunakan untuk menyimpan bilangan bulat (bilangan yang tidak memiliki 
        pecahan atau desimal). 
    2.  Float : Tipe data float adalah salah satu tipe data primitif dalam pemrograman 
        yang digunakan untuk menyimpan bilangan pecahan (bilangan yang memiliki 
        bagian desimal). 
    3.  Double : Tipe data double adalah salah satu tipe data primitif dalam 
        pemrograman yang digunakan untuk menyimpan bilangan pecahan (bilangan 
        yang memiliki bagian desimal) dengan presisi ganda dibandingkan dengan tipe 
        data float. 
    4.  Char : Char atau karakter adalah tipe data primitif dalam pemrograman yang 
        digunakan untuk menyimpan satu karakter, seperti huruf, angka, tanda baca, atau 
        karakter khusus lainnya. 
    5.  Bool : Bool atau boolean adalah tipe data primitif dalam pemrograman yang 
        digunakan untuk menyimpan nilai kebenaran (true atau false). 
    6.  Void : Tipe data void adalah sebuah tipe data khusus dalam pemrograman yang 
        menandakan tidak adanya nilai atau data yang dihasilkan oleh suatu fungsi atau 
        prosedur. 

Tipe Data Abstrak 
Abstract data type atau tipe data abstrak adalah jenis tipe data dalam pemrograman 
yang digunakan untuk mendeskripsikan sifat dan perilaku suatu objek atau struktur 
data. Dalam tipe data ini biasanya dibuat dalam sebuah kelas (class), kelas ini 
merupakan pengembangan dari sebuah struct dalam bahasa pemrograman C++. 
    a.  Class : kelas berisi definisi data dan metode yang digunakan untuk 
        menggambarkan suatu objek dan perilakunya. 
    b.  Struct / structure :  Tipe data yang di bangun dan berisi kumpulan variabel 
        yang memiliki nama yang sama dan terkait satu sama lai

Tipe Data Koleksi  
Tipe data koleksi adalah tipe data dalam pemrograman yang digunakan untuk 
menyimpan kumpulan nilai atau objek yang serupa dalam satu variabel atau struktur 
data. Tipe data koleksi digunakan untuk menyimpan dan memanipulasi data yang 
berjumlah banyak dalam satu waktu.  
Tipe data koleksi umumnya terdiri dari beberapa jenis, di antaranya : 
    1.  Array : adalah tipe data koleksi yang digunakan untuk menyimpan data dengan 
        tipe data yang sama dalam urutan tertentu. Array memungkinkan programmer 
        untuk mengakses elemen data secara mudah dengan menggunakan indeks. 
    2.  Map atau Dictionary: adalah tipe data koleksi yang digunakan untuk 
        menyimpan data dalam bentuk pasangan key-value. Map memungkinkan 
        programmer untuk mengakses nilai berdasarkan key-nya dengan mudah. 
    3.  Vector adalah tipe data koleksi dalam pemrograman yang digunakan untuk 
        menyimpan data dengan tipe data yang sama dalam urutan tertentu dan 
        memiliki ukuran yang dapat diubah. Vector mirip dengan array, namun vector 
        memiliki kemampuan untuk mengubah ukurannya secara dinamis saat program 
        sedang berjalan.




## Guided 

### 1. Tipe Data Primitif
```C++
#include<iostream> 
 
using namespace std; 
 
int main() 
{ 
    char op; 
    float num1, num2; 
 
    cout<<"Masukan operasi bilangan : "; 
    cin>>op; 
    cout<<"Masukan bilangan 1 : "; 
    cin>>num1; 
    cout<<"Masukan bilangan 2 : "; 
    cin>>num2; 
 
    switch (op) 
    { 
    case '+': 
        cout << num1+num2; 
        break; 
 
    case '/': 
        cout << num1/num2; 
        break; 
 
    case '-': 
        cout << num1-num2; 
        break; 
 
    case '*': 
        cout << num1*num2; 
        break; 
 
    default: 
    cout << "error!"; 
    break; 
    } 
    return 0;
}
Program di atas merupakan contoh penggunaan tipe data primitif char dan float pada 
sebuah program kalkulator sederhana yang dapat melakukan operasi matematika 
dasar, yaitu penjumlahan, pengurangan, perkalian, dan pembagian. Program ini 
menggunakan struktur kontrol switch untuk mengevaluasi operator yang dimasukkan 
oleh pengguna dan melakukan operasi yang sesuai terhadap bilangan yang 
dimasukkan oleh pengguna. Program akan meminta pengguna untuk memasukkan 
operator dan dua bilangan, kemudian program akan menampilkan hasil operasi pada 
layar. Jika operator yang dimasukkan tidak sesuai dengan empat operator matematika 
dasar, maka program akan menampilkan pesan kesalahan "error!" pada layar.

### 2. Tipe Data Abstrak
'''C++
#include<stdio.h> 
using namespace std; 

struct mahasiswa{ 
    char *name; 
    char *address; 
    int age; 
}; 

int main(){ 

struct mahasiswa mhs1,mhs2; 
mhs1.name = "dian"; 
mhs1.address = "Mataram"; 
mhs1.age = 22; 

mhs2.name = "Bambang"; 
mhs2.address = "Mataram"; 
mhs2.age = 23; 

printf("Mahasiswa 1 \n"); 
printf("Nama: %s\n", mhs1.name); 
printf("Alamat: %s\n", mhs1.address); 
printf("Umur: %d \n", mhs1.age); 
printf("Mahasiswa 2 \n"); 
printf("Nama: %s \n", mhs2.name); 
printf("Alamat: %s \n", mhs2.address); 
printf("Umur: %d \n", mhs2.age); 

return 0;
} 
Program tersebut menginisialisasi dua variabel struktur "mahasiswa" yaitu "mhs1" 
dan "mhs2" dengan data mahasiswa tertentu. Kemudian program mencetak 
informasi mengenai data mahasiswa tersebut menggunakan fungsi printf() dengan 
format yang telah ditentukan. Output dari program tersebut adalah informasi 
mengenai data dua orang mahasiswa yang telah diinisialisasi sebelumnya, yaitu 
nama, alamat, dan umur.

### 3. Tipe Data Koleksi
'''C++
#include<iostream> 
using namespace std; 
int main() 
{ 
int nilai[5]; 
nilai[0]=23; 
nilai[1]=50; 
nilai[2]=34; 
nilai[3]=78; 
nilai[4]=90; 
cout << "Isi array Pertama: " << nilai[0]<<endl; 
cout << "Isi array Kedua: " << nilai[1]<<endl; 
cout << "Isi array Ketiiga: " << nilai[2]<<endl; 
return 0; 
}
Program menginisialisasi setiap elemen array dengan nilai tertentu menggunakan 
operator "=" dan indeks elemen pada array. Selanjutnya, program mencetak nilai 
dari tiga elemen pertama pada array menggunakan fungsi cout dengan format yang 
telah ditentukan. Output dari program adalah informasi mengenai isi tiga elemen 
pertama pada array "nilai".

## Unguided
 
 ### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

'''C++
#include <iostream> 
using namespace std; 

int main() { 
    double jari_jari, luas, keliling; 
    const double pi = 3.14; 

    cout << "Masukkan jari-jari lingkaran: "; 
    cin >> jari_jari; 

    luas = pi * jari_jari * jari_jari; 
    keliling = 2 * pi * jari_jari; 

    cout << "Luas lingkaran adalah: " << luas << endl; 
    cout << "Keliling lingkaran adalah: " << keliling << endl; 
    return 0; 
}
Program di atas menggunakan tipe data primitif double untuk menyimpan nilai 
jari-jari, luas, dan keliling. Variabel jari_jari digunakan untuk menyimpan nilai 
jari-jari lingkaran yang dimasukkan oleh pengguna melalui cin. Untuk 
menghitung luas dan keliling lingkaran, program menggunakan rumus yang 
sesuai dengan nilai pi yang dideklarasikan sebagai konstanta const double pi = 
3.14;. Luas lingkaran dihitung dengan rumus pi * jari_jari * jari_jari, 
sedangkan keliling lingkaran dihitung dengan rumus 2 * pi * jari_jari.Program 
kemudian menampilkan hasil perhitungan luas dan keliling lingkaran 
menggunakan ‘cout’.

Dari program di atas, kita dapat menyimpulkan bahwa tipe data primitif sangat 
berguna dalam pemrograman untuk menyimpan nilai numerik yang diperlukan 
dalam perhitungan matematis. Dalam contoh ini, tipe data double digunakan 
untuk mengakomodasi nilai desimal yang dihasilkan dari perhitungan. Selain 
itu, cin dan cout juga merupakan fitur penting dalam bahasa C++ untuk 
memungkinkan input dan output dari program. 

### 2. Jelaskan fungsi dari class dan structur secara detail dan berikan contoh programnya!

'''C++
#include<iostream> 
using namespace std; 

class Mahasiswa { 
    public: 
        string name; 
        int age; 
        string address; 
    void display() { 
        cout << "Nama: " << name << endl; 
        cout << "Umur: " << age << endl; 
        cout << "Alamat: " << address << endl; 
    } 
}; 

int main() { 
    Mahasiswa mhs; 
    mhs.name = "Raffy"; 
    mhs.age = 20; 
    mhs.address = "Bekasi"; 
    mhs.display(); 

return 0; 
} 
Pada program di atas, kita membuat sebuah class bernama Mahasiswa yang memiliki tiga properti, yaitu name, age, dan address. Kemudian, kita juga menambahkan sebuah metode bernama display() yang digunakanuntuk 
menampilkan properti dari objek Mahasiswa yang telah dibuat.

Struct : Struct mirip dengan class dalam hal menyimpan data, namun berbeda dalam hal aksesibilitas dan penggunaannya. Struct hanya dapat menyimpan data, tanpa adanya fungsi yang terkait di dalamnya. Selain itu, semua properti dalam struct dianggap sebagai public, yang berarti dapat diakses langsung tanpa harus melalui metode. Berikut adalah contoh program sederhana untuk mengilustrasikan struct:

#include<iostream> 
using namespace std; 

struct Mahasiswa { 
string name; 
int age; 
string address; 
}; 

int main() { 
Mahasiswa mhs; 
mhs.name = "Raffy"; 
mhs.age = 20; 
mhs.address = "Bekasi"; 

cout << "Nama: " << mhs.name << endl; 
cout << "Umur: " << mhs.age << endl; 
cout << "Alamat: " << mhs.address << endl; 

return 0; 
}

Class : Class adalah tipe data khusus dalam bahasa pemrograman yang dapat menyimpan data dan fungsi di dalamnya. Class digunakan untuk mewakili objek yang terdiri dari beberapa properti (data) dan metode (fungsi) yang digunakan untuk memanipulasi data tersebut

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan array dengan map.

'''C++
 #include <iostream> 
#include <map> 

using namespace std; 

int main() { 
    map<string, int> umur; 

    umur["Raffy"] = 20; 
    umur["Haikal"] = 21; 
    umur["Dimas"] = 31; 

    cout << "Umur Raffy: " << umur["Raffy"] << endl; 
    cout << "Umur Haikal: " << umur["Haikal"] << endl; 
    cout << "Umur Dimas: " << umur["Dimas"] << endl; 

    return 0; 
} 
Program di atas menggunakan fungsi map dari library <map> pada C++. map 
adalah tipe data asosiatif yang memetakan nilai kunci ke nilai data. Pada 
program di atas, kita membuat variabel umur yang berisi map dari string (nama) 
ke integer (umur). Kemudian, kita memasukkan beberapa data ke dalam umur 
menggunakan notasi array. Selanjutnya, kita mencetak umur setiap orang 
dengan mengakses nilai umur menggunakan notasi array. 

## Kesimpulan
Dalam praktikum ini, kita mempelajari tentang tipe data yang terdiri dari tiga jenis, yaitu tipe data primitif, tipe data abstrak, dan tipe data koleksi. Tipe data primitif merupakan tipe data yang dapat menyimpan satu nilai pada satu waktu dan nilainya tidak dapat berubah dengan cara tipe data non-primitif. Jika nilainya sama, maka tipe data primitif tersebut akan dianggap sama. Kemudian, tipe data abstrak adalah tipe data yang digunakan untuk menggambarkan karakteristik dan perilaku sebuah objek dan biasanya diimplementasikan dalam  sebuah kelas. Kelas merupakan pengembangan dari sebuah struct dalam bahasa pemrograman C++. Sementara itu, tipe data koleksi adalah tipe data yang terdiri dari rangkaian data atau objek dengan indeks. Mahasiswa dapat membuat program dengan menggunakan ketiga tipe data tersebut. Proses pembuatan program mengajarkan kepada mahasiswa tentang ketelitian,ketekunan, dan active critical thinking dalam memecahkan masalah dan menyelesaikan program. Meskipun mahasiswa sudah berhasil membuat program yang dimaksudkan, namun masih diperlukan penemuan kode yang lebih ringkas untuk memperbaiki program yang telah dibuat.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
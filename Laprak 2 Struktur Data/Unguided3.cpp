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
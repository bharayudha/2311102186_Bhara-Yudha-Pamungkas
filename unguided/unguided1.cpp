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
}s
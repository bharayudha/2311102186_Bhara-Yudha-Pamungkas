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
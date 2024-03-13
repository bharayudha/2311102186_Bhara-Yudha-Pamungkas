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
    mhs.name = "Bhara"; 
    mhs.age = 20; 
    mhs.address = "Bekasi"; 
    mhs.display(); 

    return 0; 
}s
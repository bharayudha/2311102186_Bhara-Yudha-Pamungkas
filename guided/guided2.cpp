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

    return 0;s
}
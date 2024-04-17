#include <iostream>
#include <list>
using namespace std;

class Mahasiswa {
public:
    int nim;
    int nilai;
};

class HashTable {
private:
    list<Mahasiswa> *table;
    int total_elements;

public:
    HashTable(int n) {
        total_elements = n;
        table = new list<Mahasiswa>[total_elements];
    }

    void insertMahasiswa(int nim, int nilai) {
        int index = nim % total_elements;
        table[index].push_back({nim, nilai});
    }

    void deleteMahasiswa(int nim) {
        int index = nim % total_elements;
        list<Mahasiswa>::iterator it;
        for (it = table[index].begin(); it != table[index].end(); it++) {
            if (it->nim == nim) {
                table[index].erase(it);
                break;
            }
        }
    }

    void searchMahasiswaByNIM(int nim) {
        int index = nim % total_elements;
        list<Mahasiswa>::iterator it;
        for (it = table[index].begin(); it != table[index].end(); it++) {
            if (it->nim == nim) {
                cout << "NIM: " << it->nim << ", Nilai: " << it->nilai << endl;
                break;
            }
        }
    }

    void searchMahasiswaByRange(int min, int max) {
        for (int i = 0; i < total_elements; i++) {
            list<Mahasiswa>::iterator it;
            for (it = table[i].begin(); it != table[i].end(); it++) {
                if (it->nilai >= min && it->nilai <= max) {
                    cout << "NIM: " << it->nim << ", Nilai: " << it->nilai << endl;
                }
            }
        }
    }
};

int main() {
    int nim;
    int nilai;
    int min;
    int max;
    
    // Create hash table
    HashTable ht(100);
    while (true){
        cout<<"Menu"<<endl;
        cout<<"1. insert data"<<endl;
      cout<< "2. delete data" <<endl;
      cout<< "3. search by him" <<endl;
      cout <<" 4. search by range"<< endl;
      cout<<"\n";
      int pilihan;
      cout << "Masukan Pilihan: ";
      cin>>pilihan;

      switch(pilihan) {
        case 1:
        cout<< "Masukan nim: ";cin >> nim;
        cout<< "Masukan Nilai: " ; cin >> nilai;
        ht.insertMahasiswa(nim, nilai);
        break;
        case 2:
        cout << " Masukan nim: "; cin>> nim;
        ht.deleteMahasiswa(nim) ;
        break;
        case 3:
        cout<<" Masukan Nim: " ;cin>>nim;
        ht.searchMahasiswaByNIM(nim);
        break;
        case 4:
        cout<<"Masukan nilai min: ";cin>> min;
        cout<<"Masukan nilai max: ";cin>> max;
        ht.searchMahasiswaByRange(min, max) ;
        break;
        case 0:
        exit(0);
      }
        
    }
    return 0;
}
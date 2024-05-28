#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Struktur data untuk menyimpan informasi kota
struct City {
  string name;
  map<string, int> connections; // Bobot koneksi ke kota lain
};

// Fungsi untuk meminta pengguna memasukkan nama simpul (kota)
void inputKota_2311102197(int numKota, vector<City>& Kota) {
  cout << "Masukan nama Simpul: " << endl;
  for (int i = 0; i < numKota; i++) {
    cout << "Simpul " << i + 1 << ": ";
    cin >> Kota[i].name;
  }
  cout << "\n";
}

// Fungsi untuk meminta pengguna memasukkan bobot koneksi antar simpul
void inputConnections(int numKota, vector<City>& Kota) {
  cout << "Masukan bobot antar simpul: " << endl;
  int self_weight;
  int forward_weight;
  int reversed_forward_weight;

  for (int i = 0; i < numKota; i++) {
    for (int j = 0; j < numKota; j++) {
      // Sertakan koneksi ke diri sendiri (self-connections)
      if (i != j) {
        cout << Kota[i].name << "-->" << Kota[i].name << ": ";  // Bobot koneksi ke diri sendiri
        cin >> self_weight;
        Kota[i].connections[Kota[i].name] = self_weight;

        cout << Kota[i].name << "-->" << Kota[j].name << ": ";  // Bobot koneksi maju
        cin >> forward_weight;
        Kota[i].connections[Kota[j].name] = forward_weight;

        cout << Kota[j].name << "-->" << Kota[i].name << ": ";  // Bobot koneksi mundur (biasanya sama dengan bobot maju)
        cin >> reversed_forward_weight;
        Kota[j].connections[Kota[i].name] = reversed_forward_weight;
      }
    }
  }
  cout << "\n";
}

// Fungsi untuk mencetak tabel koneksi lengkap
void printConnectionTable(int numKota, vector<City>& Kota) {
  cout << "\t" << "Nama Kota\t" << "Koneksi" << endl;  // Header tabel

  // Cetak koneksi secara simetris (menghindari duplikasi)
  for (int i = 0; i < numKota; i++) {
    for (int j = i + 1; j < numKota; j++) {
      cout << Kota[i].name << "\t" << Kota[i].connections[Kota[i].name] << "\t" << Kota[i].connections.at(Kota[j].name) << "\n";  // Bobot maju
      cout << Kota[j].name << "\t" << Kota[j].connections.at(Kota[i].name) << "\t" << Kota[j].connections[Kota[j].name] << "\n";  // Bobot mundur (jika berbeda)
    }
  }
}

int main() {
  int numKota;
  cout << "Silahkan masukan jumlah simpul: ";
  cin >> numKota;
  cout << endl;

  vector<City> Kota(numKota);

  inputKota_2311102197(numKota, Kota);
  inputConnections(numKota, Kota);
  printConnectionTable(numKota, Kota);

  return 0;
}
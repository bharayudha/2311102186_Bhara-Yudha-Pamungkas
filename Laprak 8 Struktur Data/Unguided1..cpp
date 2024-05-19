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
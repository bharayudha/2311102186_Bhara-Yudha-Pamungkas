#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

// Fungsi untuk mengecek apakah string adalah palindrome
bool isPalindrome(string str) {
  // Deklarasi stack untuk menyimpan karakter
  stack<char> st;

  // Menambahkan karakter dari string ke stack
  for (char c : str) {
    st.push(c);
  }

  // String kosong untuk menyimpan hasil kebalikan dari string input
  string reversed = "";

  // Mengambil karakter dari stack dan menambahkannya ke string reversed
  while (!st.empty()) {
    reversed += st.top();
    st.pop();
  }

  // Membandingkan string input dengan string reversed
  return str == reversed;
}

int main() {
  string input;

  // Meminta pengguna untuk memasukkan string
  cout << "Masukan string: ";
  getline(cin, input);

  // Memanggil fungsi isPalindrome untuk mengecek apakah string palindrome
  if (isPalindrome(input)) {
    cout << "String ini palindrome." << endl;
  } else {
    cout << "String ini bukan palindrome." << endl;
  }

  return 0;
}

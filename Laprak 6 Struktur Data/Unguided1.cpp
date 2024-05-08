#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string str) {
    stack<char> st;
    for (char c : str) {
        st.push(c);
    }
    string reversed = "";
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }
    return str == reversed;
}

int main() {
    string input;
    cout << "Masukan string: ";
    getline(cin, input);
    if (isPalindrome(input)) {
        cout << "String ini palindrome." << endl;
    } else {
        cout << "String ini bukan palindrome." << endl;
    }
    return 0;
}
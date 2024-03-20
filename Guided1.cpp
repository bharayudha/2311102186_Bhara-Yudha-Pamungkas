#include <iostream> 
 
using namespace std; 
 
int main() { 
  int arr[2][3][3]; 
 
  for (int x = 0; x < 2; x++) { 
    for (int y = 0; y < 3; y++) { 
      for (int z = 0; z < 3; z++) { 
        cout << "Input array [" << x << "][" << y << "][" 
<< z << "] = "; 
        cin >> arr[x][y][z]; 
      } 
    } 
    cout << endl; 
  } 
 
  cout << endl; 
  for (int x = 0; x < 2; x++) { 
    for (int y = 0; y < 3; y++) { 
      for (int z = 0; z < 3; z++) { 
        cout << "Data array [" << x << "][" << y << "][" 
<< z 
             << "] = " << arr[x][y][z] << endl; 
      } 
    } 
  }  
 
  cout << endl; 
  for (int x = 0; x < 2; x++) { 
    for (int y = 0; y < 3; y++) { 
      for (int z = 0; z < 3; z++) { 
        cout << arr[x][y][z] << " "; 
      } 
      cout << endl; 
    } 
    cout << endl;  
    } 
} 
#include <iostream> 
#include <map> 

using namespace std; 

int main() { 
    map<string, int> umur; 
    
    umur["Raffy"] = 20; 
    umur["Haikal"] = 21; 
    umur["Dimas"] = 31; 
    
    cout << "Umur Raffy: " << umur["Raffy"] << endl; 
    cout << "Umur Haikal: " << umur["Haikal"] << endl; 
    cout << "Umur Dimas: " << umur["Dimas"] << endl; 

    return 0; 
} 
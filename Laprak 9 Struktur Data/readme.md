# <h1 align="center">Laporan Praktikum Modul 9 Tree & Graph</h1>
<p align="center">Bhara Yudha Pamungkas</p>
<p align="center">2311102186</p>

## Dasar Teori
<p align="justify"> 
Tree dan Graph adalah dua struktur data fundamental dalam ilmu komputer. Tree adalah struktur data berhirarki yang terdiri dari simpul terhubung dimulai dari simpul khusus yang disebut root, sementara Graph adalah kumpulan simpul yang terhubung melalui edge. Dalam Tree, setiap simpul memiliki tepat satu simpul induk kecuali root, dan tree tidak boleh memiliki siklus. Graph dapat memiliki dua jenis, Directed Graph dan Undirected Graph, dan setiap simpul dalam graph dapat memiliki relasi dengan simpul lain melalui edge. Keduanya digunakan dalam berbagai aplikasi, seperti representasi hierarki data, algoritma pencarian, jaringan komputer, dan pemetaan.
</p>

## Guided
### Guided 1 
Graph
```C++
#include <iostream> 
#include <iomanip> 
using namespace std; 
 
string simpul[7] = { 
    "Ciamis",  
    "Bandung",  
    "Bekasi",  
    "tasikmalaya", 
    "Cianjur",  
    "Purwokerto",  
    "Yogyakarta"  
}; 
 
int busur[7][7] = { 
    {0, 7, 8, 0, 0, 0, 0}, 
    {0, 0, 5, 0, 0, 15, 0}, 
    {0, 6, 0, 0, 5, 0, 0}, 
    {0, 5, 0, 0, 2, 4, 0}, 
    {23, 0, 0, 10, 0, 0, 8}, 
    {0, 0, 0, 0, 7, 0, 3}, 
    {0, 0, 0, 0, 9, 4, 0} 
}; 
 
void tampilGraph(){ 
    for (int baris = 0; baris <7; baris ++){ 
        cout <<" " << setiosflags (ios::left)<<setw (15) 
        << simpul [baris] << " : "; 
        for (int kolom = 0; kolom<7; kolom++){ 
            if (busur[baris][kolom]!=0){ 
                cout << " " << simpul[kolom]<< "(" << busur[baris][kolom] 
<< ")"; 
            } 
        } 
        cout << endl; 
    }       
} 
 
int main(){ 
    tampilGraph(); 
    return 0; 
}
```

### Screenshot Output
![WhatsApp Image 2024-05-28 at 23 42 48_e3c9680c](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/e81b9c88-6eab-400d-bf2d-dbb40e0e39fd)



### Guided 2 
Tree
```C++
#include <iostream>
using namespace std;

// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent; // pointer
};

// pointer global
Pohon *root;

// Inisialisasi
void init()
{
    root = NULL;
}

bool isEmpty()
{
    return root == NULL;
}

Pohon *newPohon(char data)
{
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void buatNode(char data)
{
    if (isEmpty())
    {
        root = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!"
                 << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kanan!"
                 << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;

            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;

            if (node->parent != NULL && node->parent->left != node &&
                node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;

            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;

            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);

            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus."
             << endl;
    }
}

// Hapus Tree
void clear()
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);

            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic()
{
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}

int main()
{
    init();
    buatNode('A');

    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI,
        *nodeJ;

    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);

    update('Z', nodeC);
    update('C', nodeC);
    retrieve(nodeC);
    find(nodeC);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n"
         << endl;
    cout << "InOrder :" << endl;
    inOrder(root);
    cout << "\n"
         << endl;
    cout << "PostOrder :" << endl;
    postOrder(root);
    cout << "\n"
         << endl;
    characteristic();
    deleteSub(nodeE);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n"
         << endl;
    characteristic();
    return 0;
}
```

### Screenshot Output
![WhatsApp Image 2024-05-28 at 23 44 47_413b4dbe](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/ba5dde39-11f9-4693-a45b-3c4e88808453)
![WhatsApp Image 2024-05-28 at 23 44 47_a4b7087b](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/c35e1d14-bac8-482d-8693-3783fe0a290f)



## Unguided 

### Unguided 1 
Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.
```C++
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Struktur data untuk menyimpan informasi kota
struct City
{
    string name;
    map<string, int> connections;
};
// Fungsi untuk meminta pengguna memasukkan nama simpul (kota)
void inputKota_2311102186(int numKota, vector<City> &Kota)
{
    cout << "Masukan nama Simpul: " << endl;
    for (int i = 0; i < numKota; i++)
    {
        cout << "Simpul " << i + 1 << ": ";
        cin >> Kota[i].name;
    }
    cout << "\n";
}
// Fungsi untuk meminta pengguna memasukkan bobot koneksi antar simpul
void inputConnections(int numKota, vector<City> &Kota)
{
    cout << "Masukan bobot antar simpul: " << endl;
    int self_weight;
    int forward_weight;
    int reversed_forward_weight;
    for (int i = 0; i < numKota; i++)
    {
        for (int j = i; j < numKota; j++)
        {
            if (i != j)
            {
                cout << Kota[i].name << "-->" << Kota[i].name << ": ";
                cin >> self_weight;
                cout << Kota[i].name << "-->" << Kota[j].name << ": ";
                cin >> forward_weight;
                cout << Kota[j].name << "-->" << Kota[i].name << ": ";
                cin >> reversed_forward_weight;
                cout << Kota[j].name << "-->" << Kota[j].name << ": ";
                cin >> self_weight;
                Kota[i].connections[Kota[j].name] = forward_weight;
                Kota[j].connections[Kota[i].name] = reversed_forward_weight;
                Kota[i].connections[Kota[i].name] = self_weight;
                Kota[j].connections[Kota[j].name] = self_weight;
            };
        }
    }
    cout << "\n";
}
// Fungsi untuk mencetak tabel koneksi lengkap
void printConnectionTable(int numKota, vector<City> &Kota)
{

    for (int i = 0; i < numKota; i++)
    {
        for (int j = i + 1; j < numKota; j++)
        {
            cout << "\t" << Kota[i].name << "\t" << Kota[j].name << endl;
            cout << Kota[i].name << "\t" << Kota[i].connections[Kota[i].name] << "\t" << Kota[i].connections.at(Kota[j].name) << "\n"; // forwardweight
            cout << Kota[j].name << "\t" << Kota[j].connections.at(Kota[i].name) << "\t" << Kota[j].connections[Kota[j].name] << "\n"; // reversedweight
        }
    }
}
int main()
{
    int numKota;
    cout << "Silahkan masukan jumlah simpul: ";
    cin >> numKota;
    cout << endl;

    vector<City> Kota(numKota);

    inputKota_2311102186(numKota, Kota);
    inputConnections(numKota, Kota);
    printConnectionTable(numKota, Kota);

    return 0;
}
```
### Screenshot Output
![Screenshot (285)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/64adfb67-e872-41a8-a424-9d8fb07e5234)

### Deskripsi Program
Program ini merupakan sebuah implementasi sederhana untuk membuat tabel koneksi antar simpul (kota) dalam suatu jaringan. Program ini meminta pengguna untuk memasukkan jumlah simpul (kota), nama-nama simpul tersebut, dan bobot koneksi antar simpul. Bobot koneksi antar simpul diinputkan sebagai matriks bobot, yang mencakup bobot dari simpul ke dirinya sendiri, ke simpul lain, dan bobot mundur dari simpul lain ke simpul ini.


### Unguided 2
Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!
```C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Deklarasi Pohon
struct Pohon {
    char data;
    Pohon *left, *right, *parent; // pointer
};

// pointer global
Pohon *root;

// Inisialisasi
void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

Pohon *newPohon(char data) {
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void buatNode_2311102186(char data) {
    if (isEmpty()) {
        root = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;

            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;

            if (node->parent != NULL && node->parent->left != node &&
                node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;

            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;

            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            if (node != root) {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);

            if (node == root) {
                delete root;
                root = NULL;
            } else {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear() {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    } else {
        if (!node)
            return 0;
        else {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node)
            return 0;
        else {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);

            if (heightKiri >= heightKanan)
                return heightKiri + 1;
            else
                return heightKanan + 1;
        }
    }
}

// Karakteristik Tree
void characteristic() {
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}

int main() {
    init();

    int choice;
    char data;
    Pohon *node =root;
    Pohon *nodeParent = root;
    Pohon *nodeUpdate = root;
    Pohon *nodeRetrieve = root;
    Pohon *nodeFind = root;
    Pohon *nodeDelete = root;
    Pohon *nodeDeleteSub = root;


    while (true) {
        cout << "\n1. Buat Node\n2. Insert Left\n3. Insert Right\n4. Update\n5. Retrieve\n6. Find\n7. PreOrder\n8. InOrder\n9. PostOrder\n10. Delete Tree\n11. Delete SubTree\n12. Clear\n13. Characteristic\n14. Exit" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan data node: ";
                cin >> data;
                buatNode_2311102186(data);
                break;
            case 2:
                cout << "Masukkan data node: ";
                cin >> data;        
                while (true) {
                    cout << "Masukkan node parent (1 untuk root): ";
                    cin >> choice;
                    if (choice == 1)
                        node = root;
                    else if (node->left != NULL && choice == 2)
                        node = node->left;
                    else if (node->right != NULL && choice == 3)
                        node = node->right;
                    else
                        break;
                }
                insertLeft(data, node);
                break;
            case 3:
                cout << "Masukkan data node: ";
                cin >> data;
                while (true) {
                    cout << "Masukkan node parent (1 untuk root): ";
                    cin >> choice;
                    if (choice == 1)
                        nodeParent = root;
                    else if (nodeParent->left != NULL && choice == 2)
                        nodeParent = nodeParent->left;
                    else if (nodeParent->right != NULL && choice == 3)
                        nodeParent = nodeParent->right;
                    else
                        break;
                }
                insertRight(data, nodeParent);
                break;
            case 4:
                cout << "Masukkan data node: ";
                cin >> data;
                while (true) {
                    cout << "Masukkan node (1 untuk root): ";
                    cin >> choice;
                    if (choice == 1)
                        nodeUpdate = root;
                    else if (nodeUpdate->left != NULL && choice == 2)
                        nodeUpdate = nodeUpdate->left;
                    else if (nodeUpdate->right != NULL && choice == 3)
                        nodeUpdate = nodeUpdate->right;
                    else
                        break;
                }
                update(data, nodeUpdate);
                break;
            case 5:
                cout << "Masukkan node: ";
                
                while (true) {
                    cout << "Masukkan node (1 untuk root): ";
                    cin >> choice;
                    if (choice == 1)
                        nodeRetrieve = root;
                    else if (nodeRetrieve->left != NULL && choice == 2)
                        nodeRetrieve = nodeRetrieve->left;
                    else if (nodeRetrieve->right != NULL && choice == 3)
                        nodeRetrieve = nodeRetrieve->right;
                    else
                        break;
                }
                retrieve(nodeRetrieve);
                break;
            case 6:
                cout << "Masukkan node: ";
                
                while (true) {
                    cout << "Masukkan node (1 untuk root): ";
                    cin >> choice;
                    if (choice == 1)
                        nodeFind = root;
                    else if (nodeFind->left != NULL && choice == 2)
                        nodeFind = nodeFind->left;
                    else if (nodeFind->right != NULL && choice == 3)
                        nodeFind = nodeFind->right;
                    else
                        break;
                }
                find(nodeFind);
                break;
            case 7:
                preOrder(root);
                break;
            case 8:
                inOrder(root);
                break;
            case 9:
                postOrder(root);
                break;
            case 10:
                cout << "Masukkan node: ";
                
                while (true) {
                    cout << "Masukkan node (1 untuk root): ";
                    cin >> choice;
                    if (choice == 1)
                        nodeDelete = root;
                    else if (nodeDelete->left != NULL && choice == 2)
                        nodeDelete = nodeDelete->left;
                    else if (nodeDelete->right != NULL && choice == 3)
                        nodeDelete = nodeDelete->right;
                    else
                        break;
                }
                deleteTree(nodeDelete);
                break;
            case 11:
                cout << "Masukkan node: ";
                
                while (true) {
                    cout << "Masukkan node (1 untuk root): ";
                    cin >> choice;
                    if (choice == 1)
                        nodeDeleteSub = root;
                    else if (nodeDeleteSub->left != NULL && choice == 2)
                        nodeDeleteSub = nodeDeleteSub->left;
                    else if (nodeDeleteSub->right != NULL && choice == 3)
                        nodeDeleteSub = nodeDeleteSub->right;
                    else
                        break;
                }
                deleteSub(nodeDeleteSub);
                break;
            case 12:
                clear();
                break;
            case 13:
                characteristic();
                break;
            case 14:
                return 0;
            default:
                cout << "Pilihan tidak tersedia." << endl;
        }
    }
    return 0;
}
```

### Screenshot Output
![Screenshot (286)](https://github.com/bharayudha/Struktur-Data-Assignment/assets/161665640/1059382c-d219-4cb6-81ac-ce27b8895100)


### Deskripsi Program
Program ini adalah implementasi dari struktur data pohon biner menggunakan C++. Pada program ini, pengguna dapat membuat, memodifikasi, dan menghapus simpul dalam pohon biner. Setiap simpul memiliki data karakter dan dapat memiliki maksimal dua anak (kiri dan kanan). Program menyediakan berbagai fungsi, seperti membuat simpul baru, menambahkan simpul anak kiri atau kanan, memperbarui data simpul, mencari informasi tentang simpul tertentu (seperti orang tua, saudara kandung, atau anak-anaknya), melakukan penelusuran pohon (preOrder, inOrder, postOrder), menghapus seluruh pohon atau hanya subpohon tertentu, serta menghitung karakteristik pohon seperti ukuran dan tinggi.


## Kesimpulan 
<p align="justify">

Tree dan Graph adalah dua struktur data yang penting dalam pemrograman dan representasi data. Pohon (Tree) merupakan struktur hierarkis yang terdiri dari simpul-simpul yang terhubung secara berjenjang, dimulai dari simpul akar (root) yang memiliki anak-anak di bawahnya. Setiap simpul dalam pohon memiliki anak-anak yang merupakan simpul-simpul lainnya. Graph, di sisi lain, adalah kumpulan simpul (node) yang terhubung oleh sisi (edge). Graph dapat digunakan untuk merepresentasikan berbagai jenis hubungan antara objek, seperti jaringan sosial, jaringan transportasi, atau jaringan komputer. Baik Tree maupun Graph memiliki beragam aplikasi dalam pemodelan data dan pemecahan masalah di berbagai bidang, termasuk pemrosesan bahasa alami, analisis jaringan, optimisasi rute, dan banyak lagi.
</p>

## Daftar Pustaka

[1]. Berry, A., Simonet, G., Computing the Atom Graph of a Graph and the Union Join Graph of a Hypergraph, Vol. 14, Hal. 1-20, 28 November 2021.

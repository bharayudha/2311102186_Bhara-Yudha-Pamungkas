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

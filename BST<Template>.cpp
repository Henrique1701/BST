#include <bits/stdc++.h>
using namespace std;

template <class T>
class BST{
private:
    T value;
    BST *left;
    BST *right;

public:
    BST(){
        this->value = *new T;
        this->left = nullptr;
        this->right = nullptr;
    }

    BST *bst_search(BST *root, T v){
        if(root == nullptr){
            return nullptr;
        } else if (v < root->value){
            return bst_search(root->left, v);
        } else if (v > root->value){
            return bst_search(root->right, v);
        } else {
            return root;
        }
    }

    BST *bst_insert(BST *root, T v){ //Erro na hora de criar um objeto novo
        if (root == nullptr){
            BST *n = new BST(); //Ele esta criando um objeto no mesmo espaco de memoria do anterior, logo tambem atualiza o valor do objeto anterior
            n->value = v;
            n->left = nullptr;
            n->right = nullptr;
            return n;
        } else if (v < root->value){
            root->left = bst_insert(root->left, v);
            return root;
        } else if (v > root->value){
            root->right = bst_insert(root->right, v);
            return root;
        }
    }

    BST *bst_delete(BST *root, T v){
        if(root == nullptr){
            return nullptr;
        } else if(v < root->value){
            root->left = bst_delete(root->left, v);
            return root;
        } else if(v > root->value){
            root->right = bst_delete(root->right, v);
            return root;
        } else {
            if (root->left == nullptr){
                BST *r = root->right;
                delete(root);
                return r;
            } else if (root->right == nullptr){
                BST *r = root->left;
                delete(root);
                return r;
            } else {
                pair<BST*, int> aux = bst_delete_min(root->right);
                root->right = aux.first;
                root->value = aux.second;
                return root;
            }
        }
    }

    pair<BST*, T> bst_delete_min(BST *root){
        if(root->left == nullptr){
            pair<BST*, T> aux;
            aux.first = root->right;
            aux.second = root->value;
            delete(root);
            return aux;
        } else {
            pair<BST*, T> aux = bst_delete_min(root->left);
            return aux;
        }
    }
};

int main() {
    BST<char> *root = nullptr;
    root = root->bst_insert(root, 'c');
    root = root->bst_insert(root, 'b');
    root = root->bst_insert(root, 'e');
    root = root->bst_insert(root, 'f');
    root = root->bst_insert(root, 'g');

    root = root->bst_insert(root, 'd');

    root = root->bst_delete(root, 'e');


    return 0;
}

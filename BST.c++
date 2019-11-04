#include <bits/stdc++.h>
using namespace std;

class BST{
private:
    int value;
    BST *left;
    BST *right;

public:
    BST(){
        this->value = -1;
        this->left = nullptr;
        this->right = nullptr;
    }

     BST *bst_search(BST *root, int v){
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

    BST *bst_insert(BST *root, int v){ //Erro na hora de criar um objeto novo
        if (root == nullptr){
            BST n; //Ele esta criando um objeto no mesmo espaco de memoria do anterior, logo tambem atualiza o valor do objeto anterior
            n.value = v;
            n.left = nullptr;
            n.right = nullptr;
            return &n;
        } else if (v < root->value){
            root->left = bst_insert(root->left, v);
            return root;
        } else if (v > root->value){
            root->right = bst_insert(root->right, v);
            return root;
        }
    }

    BST *bst_delete(BST *root, int v){
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

    pair<BST*, int> bst_delete_min(BST *root){
        if(root->left == nullptr){
            pair<BST*, int> aux;
            aux.first = root->right;
            aux.second = root->value;
            delete(root);
            return aux;
        } else {
            pair<BST*, int> aux = bst_delete_min(root->left);
            return aux;
        }
    }
};

int main() {
    BST *root = nullptr;
    root = root->bst_insert(root, 3);
    root = root->bst_insert(root, 2);
    root = root->bst_insert(root, 1);
    root = root->bst_insert(root, 5);
    root = root->bst_insert(root, 6);
    root = root->bst_insert(root, 7);

    //Erro no bst_insert

    return 0;
}

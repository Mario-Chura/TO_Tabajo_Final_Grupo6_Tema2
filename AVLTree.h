#ifndef AVLTREE_H
#define AVLTREE_H

#include "Registro.h"

struct Node {
    Registro* registro;
    Node* left;
    Node* right;
    int height;
};

class AVLTree {
private:
    Node* root;

    Node* createNode(Registro* registro);
    Node* insertNode(Node* node, Registro* registro);
    Node* deleteNode(Node* root, int id);
    Node* minValueNode(Node* node);
    Node* rotateLeft(Node* x);
    Node* rotateRight(Node* y);
    int getBalance(Node* N);
    int height(Node* N);

public:
    AVLTree();
    void insert(Registro* registro);
    void deleteRegistro(int id);
    Registro* search(int id);
};

#endif // AVLTREE_H





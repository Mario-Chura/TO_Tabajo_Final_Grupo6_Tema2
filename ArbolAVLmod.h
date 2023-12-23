#ifndef ARBOLAVLMOD_H
#define ARBOLAVLMOD_H

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
    std::string ordenacionActual;

    Node* createNode(Registro* registro);
    Node* insertNode(Node* node, Registro* registro, const std::string& ordenacion);
    Node* deleteNode(Node* root, int id);
    Node* minValueNode(Node* node);
    Node* rotateLeft(Node* x);
    Node* rotateRight(Node* y);
    int getBalance(Node* N);
    int height(Node* N);

public:
    AVLTree(const std::string& ordenacion);
    void insert(Registro* registro);
    void deleteRegistro(int id);
    Registro* search(int id);
};

#endif // ARBOLAVLMOD_H

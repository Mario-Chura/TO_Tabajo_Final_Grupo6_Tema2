#ifndef BTREE_H
#define BTREE_H

// BTree.h
#include <vector>
#include <string>
#include "Registro.h"

class BTreeNode {
public:
    Registro *keys;
    int t;
    BTreeNode **C;
    int n;
    bool leaf;

    BTreeNode(int _t, bool _leaf);

    void insertNonFull(Registro k);
    void splitChild(int i, BTreeNode *y);
    void traverse();

    BTreeNode *search(Registro k);
    void remove(Registro k);
    void removeFromLeaf(int idx);
    void removeFromNonLeaf(int idx);
    Registro getPred(int idx);
    Registro getSucc(int idx);
    void fill(int idx);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);
    void merge(int idx);

    friend class BTree;
};

class BTree {
public:
    BTree(int _t);
    void insert(Registro k);
    void remove(Registro k);
    void traverse();
    BTreeNode* search(Registro k);

private:
    BTreeNode *root;
    int t;
};


#endif // BTREE_H

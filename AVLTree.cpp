#include "AVLTree.h"
#include <algorithm>

Node* AVLTree::createNode(Registro* registro) {
    Node* node = new Node();
    node->registro = registro;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return(node);
}

Node* AVLTree::insertNode(Node* node, Registro* registro) {
    if (node == nullptr)
        return(createNode(registro));

    if (registro->getUuid() < node->registro->getUuid())
        node->left = insertNode(node->left, registro);
    else if (registro->getUuid() > node->registro->getUuid())
        node->right = insertNode(node->right, registro);
    else
        return node;

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && registro->getUuid() < node->left->registro->getUuid())
        return rotateRight(node);

    if (balance < -1 && registro->getUuid() > node->right->registro->getUuid())
        return rotateLeft(node);

    if (balance > 1 && registro->getUuid() > node->left->registro->getUuid()) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && registro->getUuid() < node->right->registro->getUuid()) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

Node* AVLTree::deleteNode(Node* root, int id) {
    if (root == nullptr)
        return root;

    if (id < root->registro->getUuid())
        root->left = deleteNode(root->left, id);

    else if(id > root->registro->getUuid())
        root->right = deleteNode(root->right, id);

    else {
        if((root->left == nullptr) || (root->right == nullptr)) {
            Node *temp = root->left ? root->left : root->right;

            if(temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;
            free(temp);
        }
        else {
            Node* temp = minValueNode(root->right);
            root->registro = temp->registro;
            root->right = deleteNode(root->right, temp->registro->getUuid());
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + std::max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

Node* AVLTree::minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node* AVLTree::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* AVLTree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;
    return x;
}

int AVLTree::getBalance(Node* N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

int AVLTree::height(Node* N) {
    if (N == nullptr)
        return 0;
    return N->height;
}

AVLTree::AVLTree() {
    root = nullptr;
}

void AVLTree::insert(Registro* registro) {
    root = insertNode(root, registro);
}

void AVLTree::deleteRegistro(int id) {
    root = deleteNode(root, id);
}

Registro* AVLTree::search(int id) {
    Node* current = root;
    while (current != nullptr) {
        if (id < current->registro->getUuid())
            current = current->left;
        else if (id > current->registro->getUuid())
            current = current->right;
        else
            return current->registro;
    }
    return nullptr;
}

void AVLTree::inOrderTraversal(Node* root, std::vector<Registro*>& result) {
    if (root != nullptr) {
        inOrderTraversal(root->left, result);
        result.push_back(root->registro);
        inOrderTraversal(root->right, result);
    }
}


std::vector<Registro*> AVLTree::getAllRegistros() {
    std::vector<Registro*> result;
    inOrderTraversal(root, result);
    return result;
}


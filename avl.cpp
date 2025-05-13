#include <iostream>
#include <algorithm>
using namespace std;

// Node structure
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    
    Node(int val) : key(val), left(nullptr), right(nullptr), height(1) {}
};

// AVL Tree class
class AVLTree {
public:
    Node* root;

    AVLTree() {
        root = nullptr;
    }

    // Get height of a node
    int height(Node* n) {
        return n ? n->height : 0;
    }

    // Get balance factor
    int getBalance(Node* n) {
        return n ? height(n->left) - height(n->right) : 0;
    }

    // Right rotation
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    // Left rotation
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    // Insert a node
    Node* insert(Node* node, int key) {
        if (!node)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node; // No duplicates

        // Update height
        node->height = 1 + max(height(node->left), height(node->right));

        // Balance factor
        int balance = getBalance(node);

        // LL Case
        if (balance > 1 && key < node->left->key)
            return rotateRight(node);

        // RR Case
        if (balance < -1 && key > node->right->key)
            return rotateLeft(node);

        // LR Case
        if (balance > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // RL Case
        if (balance < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    // Public insert
    void insert(int key) {
        root = insert(root, key);
    }

    // Preorder traversal
    void preorder(Node* node) {
        if (node) {
            cout << node->key << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void displayPreorder() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }
};

// Main function
int main() {
    AVLTree tree;

    int values[] = {30, 20, 40, 10, 25, 35, 50, 5};
    for (int val : values)
        tree.insert(val);

    tree.displayPreorder(); // Check balance and structure

    return 0;
}

#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    // Recursive insertion
    Node* insert(Node* node, int value) {
        if (!node)
            return new Node(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        return node;
    }

    // Find minimum node in subtree
    Node* findMin(Node* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    // Recursive deletion
    Node* deleteNode(Node* node, int key) {
        if (!node) return nullptr;

        if (key < node->data)
            node->left = deleteNode(node->left, key);
        else if (key > node->data)
            node->right = deleteNode(node->right, key);
        else {
            // Node with one or no child
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    // Recursive inorder traversal
    void inorderRecursive(Node* node) {
        if (node) {
            inorderRecursive(node->left);
            cout << node->data << " ";
            inorderRecursive(node->right);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void deleteKey(int key) {
        root = deleteNode(root, key);
    }

    void inorderRecursive() {
        cout << "Recursive Inorder: ";
        inorderRecursive(root);
        cout << endl;
    }

    void inorderNonRecursive() {
        cout << "Non-Recursive Inorder: ";
        stack<Node*> s;
        Node* current = root;

        while (current || !s.empty()) {
            while (current) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            cout << current->data << " ";
            current = current->right;
        }

        cout << endl;
    }
};

// Driver code
int main() {
    BST tree;

    // Insert nodes
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Display traversals
    tree.inorderRecursive();
    tree.inorderNonRecursive();

    // Delete a node
    cout << "Deleting 50...\n";
    tree.deleteKey(50);

    // Display again
    tree.inorderRecursive();
    tree.inorderNonRecursive();

    return 0;
}

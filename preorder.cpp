#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    // Recursive preorder traversal
    void preorderRecursive(Node* node) {
        if (node) {
            cout << node->data << " ";
            preorderRecursive(node->left);
            preorderRecursive(node->right);
        }
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!root) {
            root = newNode;
            return;
        }

        Node* current = root;
        Node* parent = nullptr;

        while (current) {
            parent = current;
            if (value < current->data)
                current = current->left;
            else
                current = current->right;
        }

        if (value < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    void preorderRecursive() {
        cout << "Recursive Preorder: ";
        preorderRecursive(root);
        cout << endl;
    }

    void preorderNonRecursive() {
        cout << "Non-Recursive Preorder: ";
        if (!root) {
            cout << "Tree is empty\n";
            return;
        }

        stack<Node*> stk;
        stk.push(root);

        while (!stk.empty()) {
            Node* current = stk.top();
            stk.pop();

            cout << current->data << " ";

            // Push right child first so that left is processed first
            if (current->right)
                stk.push(current->right);
            if (current->left)
                stk.push(current->left);
        }

        cout << endl;
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.preorderRecursive();
    tree.preorderNonRecursive();

    return 0;
}

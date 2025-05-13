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

    // Insert node into BST
    void insert(Node*& node, int value) {
        if (node == nullptr) {
            node = new Node(value);
        } else if (value < node->data) {
            insert(node->left, value);
        } else {
            insert(node->right, value);
        }
    }

    // Recursive function to compute the height of the tree
    int height(Node* node) {
        if (!node) return 0;
        return max(height(node->left), height(node->right)) + 1;
    }

    // Count the nodes in the tree
    int countNodes(Node* node) {
        if (node == nullptr) return 0;
        return countNodes(node->left) + countNodes(node->right) + 1;
    }

    // Mirror the binary tree
    void mirror(Node* node) {
        if (node == nullptr) return;

        // Swap the left and right subtrees
        swap(node->left, node->right);

        // Recursively mirror the subtrees
        mirror(node->left);
        mirror(node->right);
    }

    // Inorder traversal (for testing purposes)
    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    BST() : root(nullptr) {}

    // Public insert function
    void insert(int value) {
        insert(root, value);
    }

    // Function to calculate height
    int height() {
        return height(root);
    }

    // Function to count nodes
    int countNodes() {
        return countNodes(root);
    }

    // Function to get mirror image of the tree
    void mirror() {
        mirror(root);
    }

    // Function to print inorder traversal
    void inorder() {
        inorder(root);
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

    cout << "Inorder traversal before mirror: ";
    tree.inorder();  // Print inorder traversal of the original tree

    // Mirror the tree
    tree.mirror();

    cout << "Inorder traversal after mirror: ";
    tree.inorder();  // Print inorder traversal of the mirrored tree

    // Count the number of nodes
    cout << "Number of nodes: " << tree.countNodes() << endl;

    // Calculate the height of the tree
    cout << "Height of tree: " << tree.height() << endl;

    return 0;
}

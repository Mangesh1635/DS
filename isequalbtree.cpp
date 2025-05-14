#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to check if two trees are the same
bool isEqual(TreeNode* root1, TreeNode* root2) {
    // Both nodes are null
    if (root1 == NULL && root2 == NULL) return true;

    // One is null, the other is not
    if (root1 == NULL || root2 == NULL) return false;

    // Check current value and recurse on left and right children
    return (root1->val == root2->val) &&
           isEqual(root1->left, root2->left) &&
           isEqual(root1->right, root2->right);
}

// Sample usage
int main() {
    // Tree 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    // Tree 2
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    if (isEqual(root1, root2))
        cout << "Trees are equal." << endl;
    else
        cout << "Trees are NOT equal." << endl;

    return 0;
}

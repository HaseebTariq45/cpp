#include <iostream>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    TreeNode* root;

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        TreeNode* newNode = new TreeNode(value);
        if (!root) {
            root = newNode;
            return;
        }

        TreeNode** nodes[100];
        int front = 0, back = 0;

        nodes[back++] = &root;

        while (front < back) {
            TreeNode** current = nodes[front++];
            if (!(*current)->left) {
                (*current)->left = newNode;
                return;
            } else if (!(*current)->right) {
                (*current)->right = newNode;
                return;
            } else {
                nodes[back++] = &((*current)->left);
                nodes[back++] = &((*current)->right);
            }
        }
    }

    void displayInOrder() {
        cout << "In-order Traversal: ";
        inOrderTraversal(root);
        cout << endl;
    }

    void inOrderTraversal(TreeNode* node) {
        if (!node) return;
        inOrderTraversal(node->left);
        cout << node->value << " ";
        inOrderTraversal(node->right);
    }

    bool isCompleteBinaryTree() {
        if (!root) return true;

        TreeNode** nodes[100];
        int front = 0, back = 0;
        nodes[back++] = &root;

        bool foundIncompleteNode = false;

        while (front < back) {
            TreeNode** current = nodes[front++];
            if (!(*current)) {
                foundIncompleteNode = true;
            } else {
                if (foundIncompleteNode) return false;
                nodes[back++] = &((*current)->left);
                nodes[back++] = &((*current)->right);
            }
        }
        return true;
    }

    bool isFullBinaryTree() {
        return checkFullBinaryTree(root);
    }

    bool checkFullBinaryTree(TreeNode* node) {
        if (!node) return true;

        if ((node->left && !node->right) || (!node->left && node->right)) {
            return false;
        }

        return checkFullBinaryTree(node->left) && checkFullBinaryTree(node->right);
    }
};

int main() {
    BinaryTree bt;

    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);

    bt.displayInOrder();

    if (bt.isCompleteBinaryTree()) {
        cout << "The tree is a Complete Binary Tree." << endl;
    } else {
        cout << "The tree is NOT a Complete Binary Tree." << endl;
    }

    if (bt.isFullBinaryTree()) {
        cout << "The tree is a Full Binary Tree." << endl;
    } else {
        cout << "The tree is NOT a Full Binary Tree." << endl;
    }

    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

class AVLTree {
public:
    // Node structure
    struct Node {
        int value;
        int height;
        Node* left;
        Node* right;

        Node(int val) : value(val), height(1), left(nullptr), right(nullptr) {}
    };

    AVLTree() : root(nullptr) {}

    // Public method to insert a value into the AVL tree
    void insert(int value) {
        root = insert(root, value);
    }

    // Public method to print the tree in-order
    void inorder() {
        inorder(root);
        cout << endl;
    }

private:
    Node* root;

    // Helper method to get the height of a node
    int height(Node* node) {
        return node ? node->height : 0;
    }

    // Helper method to get the balance factor of a node
    int balanceFactor(Node* node) {
        return height(node->left) - height(node->right);
    }

    // Helper method to update the height of a node
    void updateHeight(Node* node) {
        node->height = max(height(node->left), height(node->right)) + 1;
    }

    // Right rotation
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        updateHeight(y);
        updateHeight(x);

        return x;
    }

    // Left rotation
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        updateHeight(x);
        updateHeight(y);

        return y;
    }

    // Insert a new node into the AVL tree and balance the tree
    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);

        // Standard BST insertion
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else if (value > node->value) {
            node->right = insert(node->right, value);
        } else {
            return node; // Duplicate values are not allowed
        }

        // Update height of the ancestor node
        updateHeight(node);

        // Get the balance factor
        int balance = balanceFactor(node);

        // Balance the tree if it is unbalanced

        // Left-Left case
        if (balance > 1 && value < node->left->value) {
            return rightRotate(node);
        }

        // Right-Right case
        if (balance < -1 && value > node->right->value) {
            return leftRotate(node);
        }

        // Left-Right case
        if (balance > 1 && value > node->left->value) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right-Left case
        if (balance < -1 && value < node->right->value) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // In-order traversal of the tree
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }
};

int main() {
    AVLTree tree;

    // Insert values into the AVL tree
    int values[] = {30, 20, 10, 5, 15, 25, 40, 50, 35, 45};
    for (int value : values) {
        tree.insert(value);
    }

    // Print the AVL tree in-order
    cout << "In-order traversal of AVL Tree: ";
    tree.inorder();

    return 0;
}

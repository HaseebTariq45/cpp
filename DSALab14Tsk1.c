#include <iostream>
using namespace std;

class AVLTree {
public:
    struct Node {
        int value;
        int height;
        Node* left;
        Node* right;

        Node(int val) : value(val), height(1), left(nullptr), right(nullptr) {}
    };

    AVLTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

private:
    Node* root;

    int height(Node* node) {
        return node ? node->height : 0;
    }

    int balanceFactor(Node* node) {
        return height(node->left) - height(node->right);
    }

    void updateHeight(Node* node) {
        node->height = max(height(node->left), height(node->right)) + 1;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);

        if (value < node->value) {
            node->left = insert(node->left, value);
        } else if (value > node->value) {
            node->right = insert(node->right, value);
        } else {
            return node;
        }

        updateHeight(node);

        int balance = balanceFactor(node);

        if (balance > 1 && value < node->left->value) {
            return rightRotate(node);
        }

        if (balance < -1 && value > node->right->value) {
            return leftRotate(node);
        }

        if (balance > 1 && value > node->left->value) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && value < node->right->value) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }
};

int main() {
    AVLTree tree;

    int values[] = {30, 20, 10, 5, 15, 25, 40, 50, 35, 45};
    for (int value : values) {
        tree.insert(value);
    }

    cout << "In-order traversal of AVL Tree: ";
    tree.inorder();

    return 0;
}

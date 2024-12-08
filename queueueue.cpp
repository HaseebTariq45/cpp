#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int value) {
        if (root == nullptr) {
            root = new Node(value);
            return;
        }

        Node* current = root;
        while (true) {
            if (value < current->data) {
                if (current->left == nullptr) {
                    current->left = new Node(value);
                    break;
                } else {
                    current = current->left;
                }
            } else if (value > current->data) {
                if (current->right == nullptr) {
                    current->right = new Node(value);
                    break;
                } else {
                    current = current->right;
                }
            } else {
                break; // Value already exists in the BST
            }
        }
    }

    bool search(int value) {
        Node* current = root;
        while (current != nullptr) {
            if (value == current->data) {
                return true; // Value found
            } else if (value < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false; // Value not found
    }

    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    void preOrderTraversal(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

    void postOrderTraversal(Node* node) {
        if (node != nullptr) {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            cout << node->data << " ";
        }
    }

    void displayInOrder() {
        inOrderTraversal(root);
        cout << endl;
    }

    void displayPreOrder() {
        preOrderTraversal(root);
        cout << endl;
    }

    void displayPostOrder() {
        postOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "In-order Traversal: ";
    bst.displayInOrder();

    cout << "Pre-order Traversal: ";
    bst.displayPreOrder();

    cout << "Post-order Traversal: ";
    bst.displayPostOrder();

    int searchValue = 40;
    cout << "Search for " << searchValue << ": " << (bst.search(searchValue) ? "Found" : "Not Found") << endl;

    searchValue = 90;
    cout << "Search for " << searchValue << ": " << (bst.search(searchValue) ? "Found" : "Not Found") << endl;

    return 0;
}

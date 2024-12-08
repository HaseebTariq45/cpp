#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left, * right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    Node* root;

public:
    BinaryTree() : root(nullptr) {}

    // Public wrapper for insertion
    void insert(int data) {
        insert(this->root, data);
    }

    // Public wrapper for deletion
    void deleteValue(int data) {
        this->root = deleteNode(this->root, data);
    }

    // Public wrappers for traversals
    void inorder() {
        inorder(this->root);
        cout << endl;
    }

    void preorder() {
        preorder(this->root);
        cout << endl;
    }

    void postorder() {
        postorder(this->root);
        cout << endl;
    }

private:
    void insert(Node*& root, int data) {
        if (!root) {
            root = new Node(data);
        } else if (data < root->data) {
            insert(root->left, data);
        } else {
            insert(root->right, data);
        }
    }

    Node* deleteNode(Node* root, int data) {
        if (!root) {
            return root;
        }
        if (data < root->data) {
            root->left = deleteNode(root->left, data);
        } else if (data > root->data) {
            root->right = deleteNode(root->right, data);
        } else {
            // Node to delete found
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // Node with two children
            Node* temp = findmin(root->right); // Inorder successor
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    Node* findmin(Node* root) {
        while (root && root->left) {
            root = root->left;
        }
        return root;
    }

    void inorder(Node* root) {
        if (root) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void preorder(Node* root) {
        if (root) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node* root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }
};

int main() {
    BinaryTree tree;

    // Insert nodes into the tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Display the tree using inorder traversal
    cout << "Inorder traversal before deletion: ";
    tree.inorder();

    // Delete nodes and display the tree after each deletion
    tree.deleteValue(20);
    cout << "Inorder traversal after deleting 20: ";
    tree.inorder();

    tree.deleteValue(30);
    cout << "Inorder traversal after deleting 30: ";
    tree.inorder();

    tree.deleteValue(50);
    cout << "Inorder traversal after deleting 50: ";
    tree.inorder();

    return 0;
}

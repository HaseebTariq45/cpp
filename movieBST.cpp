#include <iostream>
#include <string>
using namespace std;

class MovieInfo {
public:
    string name;
    string details;

    MovieInfo(string name = "", string details = "") : name(name), details(details) {}
};

class BSTNode {
public:
    string key;
    MovieInfo info;
    BSTNode* left;
    BSTNode* right;

    BSTNode(string key, MovieInfo info) : key(key), info(info), left(nullptr), right(nullptr) {}
};

class BST {
    BSTNode* root;

    BSTNode* insert(BSTNode* node, string key, MovieInfo info) {
        if (!node) {
            return new BSTNode(key, info);
        }
        if (key < node->key) {
            node->left = insert(node->left, key, info);
        } else if (key > node->key) {
            node->right = insert(node->right, key, info);
        }
        return node;
    }

    BSTNode* search(BSTNode* node, string key) {
        if (!node || node->key == key) {
            return node;
        }
        if (key < node->key) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }

    void inOrderTraversal(BSTNode* node) {
        if (node) {
            inOrderTraversal(node->left);
            cout << node->key << ": " << node->info.details << endl;
            inOrderTraversal(node->right);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(string key, MovieInfo info) {
        root = insert(root, key, info);
    }

    MovieInfo* search(string key) {
        BSTNode* result = search(root, key);
        if (result) {
            return &(result->info);
        }
        return nullptr;
    }

    void displayInOrder() {
        cout << "In-Order Traversal of BST:\n";
        inOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    BST bst;

    bst.insert("shahid", MovieInfo("Shahid Jutt", "Famous Police officier in road movies"));
    bst.insert("nasir", MovieInfo("Nasir Khan Jan", "Famous Influencer works in movies"));
    bst.insert("avengers", MovieInfo("Avengers Endgame", "Sci-fi movie directed by some Bros"));

    bst.displayInOrder();

    string query;
    cout << "Enter a name to search: ";
    cin >> query;

    MovieInfo* result = bst.search(query);
    if (result) {
        cout << "Found: " << result->name << " - " << result->details << endl;
    } else {
        cout << "Not found in the BST.\n";
    }

    return 0;
}

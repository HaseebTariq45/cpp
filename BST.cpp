#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data): data(data), right(nullptr), left(nullptr){}
};


class BinarySearchTree {
    public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    Node* insert(Node* root,int data) {
        if (root == nullptr) {
            return new Node(data);
        }
        if (data<root->data)
        {
            root->left = insert(root->left,data);
        }
        else if (data>root->data)
        {
            root->right = insert(root->right,data);
        }
        else{
            cout<<"Cannot Add Duplicate values!!!!!";
        }
        return root;
    }
    void insert(int data) {
        root = insert(root, data);
    }


    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }


    void display() {
        inOrderTraversal(root);
        cout << endl;
    }
};


int main() {
    BinarySearchTree b;
    b.insert(50);
    b.insert(30);
    b.insert(70);
    b.insert(20);
    b.insert(40);
    b.insert(60);
    b.insert(80);

    cout << "In-order Traversal: ";
    b.display();


    return 0;
}

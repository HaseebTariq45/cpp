#include<iostream>
using namespace std;

class Node{
    public:
    int height;
    int data;
    Node *left, *right;
    Node(int data) : data(data),left(nullptr),right(nullptr),height(1){}
};
int getheight(Node* node)
{
    return node == NULL ? 0 : node->height;
}
int getBalance(Node* node){
    return node == NULL ? 0 : getheight(node->left) - getheight(node->right);
}
    Node* rightRotate(Node* y){
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        x->height = max(getheight(x->left), getheight(x->right))+1;
        y->height = max(getheight(y->left), getheight(y->right))+1;
        return x;
    }
    Node* rightRotate(Node* x){
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getheight(x->left), getheight(x->right))+1;
        y->height = max(getheight(y->left), getheight(y->right))+1;

        return y;
    }
    Node* insert(Node* root, int data){
        if(!root)
        {
            return new Node(data);
        }
        if (data < root->data) {
        root->left = Insert(root->left, data);
    } else if (data > root->data) {
        root->right = Insert(root->right, data);
    } else {
        cout << "\nCannot Repeat the Values." << endl;
        return root;
    }

    }
int main()
{

    return 0;
}
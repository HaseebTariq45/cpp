#include <iostream>
using namespace std;

class Node {
    public:
        int key;
        Node *left;
        Node *right;
        int height;

        Node(int key) {
            this->key = key;
            left = NULL;
            right = NULL;
            height = 1; // Initial height of a new node is 1
        }
};
int getheight(Node* node){
    return node==nullptr ? 0 : node->height;
}
int getBalance(Node* node){
    return node==nullptr ? 0 : getheight(node->left) - getheight(node->right);
}
Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;

    return x;
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;

}
Node* Insert( Node* root , int key){
    if (root==nullptr)
    {
        return root;    
    }
    if(key<root->key){
        root->left = Insert(root->left,key);
    }
    else if (key>root->key)
    {
        root->right = Insert(root->right,key);
    }
    else{
        cout<<"\nRepeating values";
        return;
    }
    root->height = max(getheight(root->left), getheight(root->right)) + 1;

    int balance = getBalance(root);

    //left left case
    if (balance > 1 && key < root->left->key)
    {
        return rightRotate(root);
    }
    if(balance < -1 && key > root->right->key)
    {
        return leftRotate(root);
    }
    if(balance > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance < -1 && key < root->right->key){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
}
Node* findMin(Node* root)
{
    Node* temp = root;
    while(temp->left!=nullptr)
    {
        temp = temp->left;
    }
    return root;
}
    
    

    Node* Delete(Node* root , int key)
    {
        if(!root)
        {
            return root;
        }
        if(key<root->key)
        {
            root->left = Delete(root->left,key);
        }
        else if(key>root->key){
            root->right = Delete(root->right, key);
        }
        else{
            if (root->left==NULL || root->right==NULL)
            {
                Node* temp = root->left ? root->left : root->right;

                if (temp==NULL)
                {
                    temp == root;
                    root == NULL;
                }
                else
                {
                    *root = *NULL;
                }
                delete temp;
            }
            else
            {

            }
            
        }

    }
    
    
    

#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* left, * right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};
class BinaryTree
{
    public:
    Node* root;
    BinaryTree() : root(nullptr) {}

    void insert(Node*& root, int data)
    {
        if(!root)
        {
        root = new Node(data);
        }    
        if(data<root->data)
        {
            insert(root->left, data);
        }
        else if(data>root->data)
        {
           insert(root->right, data);
        }
    }

    Node* deleteNode(Node* root, int data)
    {
        if (!root) 
        {
            return root;
        }
        if(data<root->data)
        {
            root->left = deleteNode(root->left, data);
        }
        else if(data>root->data)
        {
            root->right = deleteNode(root->right, data);
        }
        else 
        {
            if(!root->left)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if(!root->right)
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else 
            {
                Node* temp = findmin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        return root;

    }
    Node* findmin(Node* root)
    {
        while(root && root->left)
        {
            root = root->left;
        }
        return root;
    }
    void inOrder(Node* root)
    {
        if(root)
        {
            inOrder(root->left);
            cout<<root->data<<" ";
            inOrder(root->right);
        }
    }
};
int main()
{
    BinaryTree t;
    t.insert(t.root, 50);
    t.insert(t.root, 10);
    t.insert(t.root, 20);
    t.insert(t.root, 40);
    t.insert(t.root, 30);
    t.insert(t.root, 60);
    t.insert(t.root, 100);
    t.insert(t.root, 70);
    t.insert(t.root, 90);
    t.insert(t.root, 80);

    cout<<"Displaying Elements in order fashion: ";
    t.inOrder(t.root);
    cout<<endl;
    t.root = t.deleteNode(t.root,50);

    return 0;
}
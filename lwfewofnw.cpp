#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* left, * right;
    Node(int data) : data(data), left(nullptr),right(nullptr) {}
};
class BinaryTree
{
    public:
    Node* root;
    BinaryTree() : root(nullptr) {}
     

    void insert(Node*& root,int data)
    {
        if(!root)
        {
            root  = new Node(data);
        }
        else if (data<root->data)
        {
            insert(root->left, data);
        }
        else
        {
            insert(root->right, data);
        }
    }
    Node* deleteNode(Node* root, int data)
    {
        if(!root)
        {
            return root;
        }
        ///////////////
        if(data<root->data)
        {
            root->left = deleteNode(root->left, data);
        }
        else if(data>root->data)
        {
            root->right = deleteNode(root->right , data);
        }
        else
        {
            if(!root->left)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right)
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            //////////// case 3 for inorder successor /////////
           else
           {
             Node* temp = findmin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
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
    void inorder(Node* root)
    {
        if(root)
        {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
        }

    }

    void preorder(Node* root)
    {
        if(root)
        {
        preorder(root->left);
        preorder(root->right);
        cout<<root->data<<" ";
        }
               

    }
    void postorder(Node* root)
    {
        if(root)
        {
        cout<<root->data<<" ";
        postorder(root->left);
        postorder(root->right);
        }
    }
};

int main() {
    BinaryTree tree;
    tree.insert(tree.root,50);
    tree.insert(tree.root,30);
    tree.insert(tree.root,70);
    tree.insert(tree.root,20);
    tree.insert(tree.root,40);
    tree.insert(tree.root,60);
    tree.insert(tree.root,80);

    cout << "Inorder traversal before deletion: ";
    tree.inorder(tree.root);
    cout<<endl;

    tree.root = tree.deleteNode(tree.root,20);
    cout << "Inorder traversal after deleting 20: ";
    tree.inorder(tree.root);
    cout<<endl;

    tree.root = tree.deleteNode(tree.root,30);
    cout << "Inorder traversal after deleting 30: ";
    tree.inorder(tree.root);
    cout<<endl;

    tree.root = tree.deleteNode(tree.root,50);
    cout << "Inorder traversal after deleting 50: ";
    tree.inorder(tree.root);
    cout<<endl;

    return 0;
}
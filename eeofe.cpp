#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
    public:
    Node* root;
    BinaryTree() : root(nullptr) {}
    Node* insert(Node* node, int data)
    {
        if(node==nullptr)
        {
            return new Node(data);
        }
        if(data<node->data)
        {
            node->left = insert(node->left, data);
        }
        else
        {
            node->right = insert(node->right, data);
        }
        return node;
    }
    void inOrderTravese(Node* node)
    {
        if(node != nullptr)
        {
            cout<<"\nIn Order Traversal: ";
            inOrderTravese(node->left);
            cout<<node->data<<" ";
            inOrderTravese(node->right);
        }
       
    }
    void preOrderTraversal(Node* node)
    {
        if(node!=nullptr)
        {
            cout<<"\npre Order Traversal: ";
            cout<<node->data<<" ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }
    void postOrderTraversal(Node* node)
    {
        if(node!=nullptr)
        {
            cout<<"\npost Order Traversal: ";
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            cout<<node->data<<" ";
        }
    }
    bool search(Node* node, int data)
    {
        if(node==nullptr)
        {
            return false;
        }
        if(node->data==data)
        {
            return true;
        }
        if(data<node->data)
        {
           return search(node->left,data);
        }
        else
        {
            return search(node->right, data);
        }
    }

};

int main()
{
    BinaryTree b;
    b.root = b.insert(b.root, 10);
    b.insert(b.root, 20);
    b.insert(b.root, 30);
    b.insert(b.root, 40);
    b.insert(b.root, 50);
    b.insert(b.root, 60);
    b.insert(b.root, 70);

    cout<<"\n Traversing: ";
    b.inOrderTravese(b.root);
    b.postOrderTraversal(b.root);
    
    b.preOrderTraversal(b.root);

    return 0;
}
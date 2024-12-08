#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
    Node *root;
    BinaryTree() : root(nullptr) {}

    void insert(Node*& root, int data)
    {
        if (!root)
        {
            root = new Node(data);
            return;
        }
        if (data < root->data)
        {
            insert(root->left, data);
        }
        else if (data > root->data)
        {
            insert(root->right, data);
        }
    }

    Node* deletenode(Node *root, int data)
    {
        if (!root)
        {
            return root;
        }
        if (data < root->data)
        {
            root->left = deletenode(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = deletenode(root->right, data);
        }
        else
        {
            if (!root->left)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                Node *temp = findmin(root->right);
                root->data = temp->data;
                root->right = deletenode(root->right, temp->data);
            }
        }
        return root;
    }

    Node *findmin(Node *root)
    {
        while (root && root->left)
        {
            root = root->left;
        }
        return root;
    }

    void Print(Node *root)
    {
        if (root)
        {
            Print(root->left);
            cout << root->data << " ";
            Print(root->right);
        }
    }

    Node *search(Node *root, int data)
    {
        if (!root || data == root->data)
        {
            return root;
        }
        if (data < root->data)
        {
            return search(root->left, data);
        }
        else
        {
            return search(root->right, data);
        }
    }
};

int main()
{
    BinaryTree t;

    t.insert(t.root, 40);
    t.insert(t.root, 20);
    t.insert(t.root, 50);
    t.insert(t.root, 60);
    t.insert(t.root, 70);
    t.insert(t.root, 90);
    t.insert(t.root, 12);

    cout << "Printing inOrder: ";
    t.Print(t.root);
    cout << endl;

    t.root = t.deletenode(t.root, 60);
    cout << "Printing inOrder after deleting 60: ";
    t.Print(t.root);
    cout << endl;

    cout << "Enter the value to search: ";
    int data;
    cin >> data;

    Node *result = t.search(t.root, data);
    if (result)
    {
        cout << "Value " << data << " found in the tree." << endl;
    }
    else
    {
        cout << "Value " << data << " not found in the tree." << endl;
    }

    return 0;
}

#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* left,* right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }

};
void travel(Node* next)
{
    if(next==nullptr)
    {
        return;
    }
    travel(next->left);
    cout<<next->data<<" ";
    travel(next->right);
}

int main()
{

    Node* firstNode = new Node(5);
    Node* secondNode = new Node(6);
    Node* thirdNode = new Node(10);
    Node* forthNode = new Node(7);
    Node* fifthNode = new Node(9);
    Node* sixthNode = new Node(11);
    Node* seventhNode = new Node(12);
    Node* eighthNode = new Node(29);
    Node* ninthNode = new Node(15);
    Node* tenthNode = new Node(20);
    Node* eleventhNode = new Node(23);
    Node* twelvethNode = new Node(22);
    Node* thirteenthNode = new Node(25);
    Node* forteenthNode = new Node(28);

    firstNode->left = secondNode;
    firstNode->right = thirdNode;
    secondNode->left = forthNode;
    secondNode->right = fifthNode;
    thirdNode->left = sixthNode;
    thirdNode->right = seventhNode;
    forthNode->left = eighthNode;
    forthNode->right = ninthNode;
    fifthNode->left = tenthNode;
    fifthNode->right = eleventhNode;
    sixthNode-> left = twelvethNode;
    sixthNode->right = thirteenthNode;
    thirteenthNode->left = forteenthNode;
    cout << "traversal of the binary tree: ";
    travel(firstNode);
    cout << endl;
    return 0;
}
#include<iostream>
using namespace std;

class Node
{
    int data;
    Node* left, * right;
    Node(int val) : data{val}, right(nullptr), left(nullptr) {}

    int height(Node* root) {

    if (!root) return 0;

    return 1 + max(height(root->left), height(root->right));

}

};
int main()
{


    return 0;
}
#include <iostream>
#include <stdio.h>
using namespace std;

class Node
{
    public:
    int val;
    Node* next;

    Node(int data)
    { 
        val = data;
        next = NULL; 
    }
};

int main()
{
    Node* n = new Node(1);
    cout<<n->val<<" value  "<<n->next<<" pointer";
    return 0;
}
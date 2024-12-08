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

void InsertAtHead(Node* &head, int val)
{
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}
void Display(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->val<<endl;
        temp = temp->next;
    }    
    cout<<"NULL"<<endl;
}
void InsertAtEnd(Node* head, int val)
{
    Node* new_node = new Node(val);
    
    Node* temp = head;
    while (temp!=NULL)
    {
        
    }
    temp->next = new_node;
}
int main()
{
    Node* head = NULL;
    InsertAtHead(head,1211);
    InsertAtHead(head,121);
    InsertAtHead(head,123);
    InsertAtHead(head,1212);
    Display(head);
return 0;
}
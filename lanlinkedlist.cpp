#include<iostream>
using namespace std;
class Node
{
    public:
    Node* next;
    int data;
    Node(int data) : data(data) , next (nullptr) {}
};
class Linkedlist
{
    Node* head;
    public:
    Linkedlist() : head(nullptr) {}
    void insertAtBeginning(int data)
    {
        Node* newnode = new Node(data);
        newnode->next = head;
        head = newnode;
        cout<<"Inserted value at the biginning: "<<newnode->data<<endl;

       
    }
    void insertAtEnd(int data)
    {
        Node* newnode = new Node(data);

        if(head==nullptr)
        {
            head=newnode;
            return;
        }
        Node* temp = head;
        while(temp->next!=nullptr)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        cout<<"Inserted value at the end of the list: "<<newnode->data<<endl;
    }
    void insertAtPosition(int data, int position)
    {
        Node* newnode = new Node(data);
        if(head==nullptr)
        {
            head = newnode;
            return;
        }
        if(position<=0)
        {
            insertAtBeginning(data);
            return;
        }
        Node* temp = head;
        for (int i = 0; temp!=nullptr || i < position - 1; i++)
        {
            temp = temp->next;
        }
        if(temp==nullptr)
        {
            cout<<"Position is beyond the length of the list.\n Inserting at the end instead.";
            insertAtEnd(data);
            return;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        cout<<"Inserted at position\n";
        
    }
    void display()
    {
        if(head == nullptr)
        {
            cout<<"List is empty:";
            return;
        }
        Node* temp = head;
        cout<<"Printing list: ";
        while(temp!=nullptr)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"nullptr\n";
    }

};
int main()
{
    Linkedlist list;
    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.insertAtEnd(30);
    list.insertAtPosition(15, 1); // Insert 15 at position 1
    list.insertAtPosition(25, 3); // Insert 25 at position 3
    list.insertAtPosition(35, 10); 
    list.display();



    return 0;
}
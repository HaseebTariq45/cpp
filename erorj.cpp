#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int data) : data(data),next(nullptr){}
};

class Stack
{
    Node* top;
    public:
    Stack() : top(nullptr) {}

    void push(int data)
    {
        Node* newnode = new Node(data);
        newnode->next = top;
        top = newnode;
    }
    void pop()
    {
        if(top==nullptr)
        {
            cout<<"\nStack is Empty\n";
            return;
        }
       Node* temp = top;
        top = top->next;
        cout << "Popped -> " << temp->data << endl;
        delete temp;
    }
    int peek()
    {
        if(top==nullptr)
        {
            cout<<"Stack is empty\n";
        }
        else
        {
            cout<<"Topped data: ";
        return top->data;
        }
    }
    void print()
    {
        if(top==nullptr)
        {
            cout<<"Nothing to print\nStack is empty\n";
            return;
        }
        Node* temp = top;
            cout<<"\nPrinting stack Data: ";
        while(temp->next != nullptr)
        {

            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};
int main()
{
    Stack s;
    cout<<"Pushing Elements: \n";
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);
    s.push(90);
    cout<<"Printing elements.\n";
    s.print();
    cout<<"Poping Elements\n";
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    s.print();

    return 0;
}
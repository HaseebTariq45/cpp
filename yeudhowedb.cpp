#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int data) : data(data),next(nullptr){}
};
class Queue
{
    Node* front, * back;
    public:
    Queue() : front(nullptr), back(nullptr) {}

    void enqueue(int data)
    {
        Node* newnode = new Node(data);
        if(back==nullptr)
        {
            front = back = newnode;
            return;
        }
        back->next = newnode;
        back = newnode;
        
    }
    void dequeue()
    {
        if(front==nullptr)
        {
            cout<<"Queue is empty.";
            return;
        }
        Node* temp = front;
        front = front->next;

        if(front == nullptr)
        {
            back = nullptr;
        }
        cout<<"Dequeeud -> "<<temp->data<<endl;
        delete temp;
    }
    void print()
    {
        Node* temp = front;
        while(temp!=nullptr)
        {
            cout<<temp->data;
            if(temp->next==nullptr)
            {
                cout<<"->nullptr";
            }
            else
            {
                cout<<"->";
            }
            temp = temp->next;
        }
        delete temp;
    }

};
int main()
{
    Queue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout<<"Printing queued elements: ";
    q.print();
    cout<<"\nDequeuing first 2 elements\n";
    q.dequeue();
    q.dequeue();

    cout<<"Orinting after Dequeued Elements\n";
    q.print();

return 0;

}
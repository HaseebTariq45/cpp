#include<iostream>using namespace std;

class Node
{
    public:
    int data;
    Node* front,* back;
    Node(int data) : data(data), front(nullptr), back(nullptr) {}
};
class queue
{
    Node* head;
    public:
    queue() : head(nullptr) {}

    void enqueue(int data)
    {
        Node* newnode = new Node(data);
        if(newnode->back == nullptr)
        {
            newnode->back = newnode;
            return;
        }
        if(newnode->front==nullptr)
        {
            newnode->front = front->next;
        }
    }

};
int main()
{

}
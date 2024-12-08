#include <iostream>
#define size 5 
using namespace std;

class CircularQueue {
    int arr[size];
    int front, back;
    public:
    CircularQueue() : front(-1), back(-1) {}

    bool isFull()
    {
        return (back+1)%size == front;
    }
    bool isEmpty()
    {
        return (front==-1);
    }

    void enqueue(int data)
    {
        if(isFull())
        {
            cout<<"Queue is full";
            return;
        }
        if(isEmpty())
        {
            front++;
        }
        back = (back+1)%size;
        arr[back] = data;
        cout<<"Data Enqueued."<<arr[back]<<"\n";
    }
    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty.";
            return;
        }
        cout<<"Dequeued: "<<arr[front]<<" ";
        if(front==back)
        {
            front = back = -1;
        }
        else
        {
            front = (front+1)%size;
        }
    }
    void displayFront()
    {
        if (isEmpty())
        {
            cout<<"Nothin to display.";
        }
        else
        {
            cout<<"Front element: "<<arr[front];
        }
        
    }

};
int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.displayFront();  // Should display 10

    q.dequeue();       // Removes 10
    q.enqueue(60);     // Should wrap around and add 60 to the queue

    q.displayFront();  // Should display 20

}
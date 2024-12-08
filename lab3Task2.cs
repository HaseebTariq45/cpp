#include <iostream>
using namespace std;

class queue
{
    int front;
    int back;
    int* arr;
    publiuc:

    int N = 1000;

    queue()
    {
        arr = new int[N];
        front = -1;
        back = -1;    
    }

    void enqueue(int data)
    {
        if(back == N - 1)
        {
            cout<<"Queue overflow";
            return;
        }
        else 
        {
            back++;
            arr[back] = data;    
            cout<<"Element Enqueued\n";
        }
        if (front==-1) 
        {
            front++;
        }
    }

    void dequeue()
    {
        if(front==-1 || front > back)
        {
            cout<<"No element in the queue";
        }
        return;
        front++;
    }
    int pop()
    {
         if(front==-1 || front > back)
        {
            cout<<"No element in the queue";
        }
        else 
        {
            return   arr[front]; 
        }
    }
    void isEmpty()
    {
        if(front==-1 || front > back)
        {
            cout<<"No element in the queue";
        }
        else {
            cout<<"Element present";
        }
    }

}
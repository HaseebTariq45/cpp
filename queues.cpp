#include <iostream>
using namespace std;

class queue
{
    int* arr;
    int front;
    int back;
    int N = 1000;
    public:
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
            cout<<"Queue overflow.";
            return;
        }
        else 
        {
            back++;
            arr[back] = data;
            cout<<"Element enqueued\n";
        }
        if (front == -1) 
        {
            front++;
        }

    }
    void dequeue()
    {
        if(front == -1 || front > back)
        {
            cout<<"No elements in queue";
            return;
        }
        front++;
    }
    int top()
    {
        if(front == -1 || front > back)
        {
            cout<<"No elements in queue";
            return -1;
        }
        return arr[front];
    }
    bool isEmpty()
    {
         if(front == -1 || front > back)
        {
           return true;
        }
        else
        {
           return false;
        }
    }


};

int main()
{
    queue q;
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(14);
    q.enqueue(15);
    q.enqueue(16);
    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout<<"\n<---------------- Showing top element --------------->"<<endl;
    cout<<q.top()<<endl;
    cout<<"<------------- Checking if the Queue id empty ------------->\n";
    q.isEmpty();
    
    
    
   


}
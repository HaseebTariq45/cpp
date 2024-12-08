#include <iostream>
using namespace std;

    class queue
    {
        int front;
        int back;
        int* arr;
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
            if(back==N-1)
            {
                cout<<"Queue is full";
                return;
            }
            else
            {
                back++;
                arr[back] == data;
            }
            if(front==-1)
            {
                front++;
            }
        }
        void dequeue()
        {
            if(front==-1 || front>back)
            {
                cout<<"Queue is empty";
                return;
            }
            front++;
        }
    };

 int main()
 {
    queue q;
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(14);
    q.dequeue();

 }
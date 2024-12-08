#include<iostream>
using namespace std;
#define size 5
class Stack
{
    int top;
    int arr[size];
    public:
    Stack() : top(-1) {}

    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == size-1;
    }
    void push(int data)
    {
        if(isFull())
        {
            cout<<"Stack is Full.";
            return;
        }
        top++;
        arr[top] = data;
        cout<<"Data pushed: "<<arr[top]<<"\n";
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty";
            return;
        }
        
    cout<<"\nElement topped: "<<arr[top];
    top--;
    }

    void dtop()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty";
            return;
        }
        cout<<"top element: "<<arr[top];
    }

};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();




    return 0;
}
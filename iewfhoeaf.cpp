#include<iostream>
using namespace std;
  
    struct stack
    {
        int* arr;
        int top = -1;
        int size = 10;
        stack()
        {
            arr = new int[size];
        }

    }s;
        void push(int data)
        {
            if(s.top>s.size-1)
            {
                cout<<"Stack is full";
            }
            else
            {
                s.top++;
                s.arr[s.top]=data;
            }
        }
        void top()
        {
            if(s.top==-1)
            {
                cout<<"Stack empty";
            }
            else
            {
                cout<<"Top element "<<s.arr[s.top];
            }
        }
        void pop()
        {
            if(s.top==-1)
            {
                cout<<"Stack empty";
            }
            else
            {
                cout<<"Removed element "<<s.arr[s.top];
            }
        }
        void display()
        {
            if(s.top==-1)
            {
                cout<<"Stack empty";
            }
            else
            {
                for (int i = 0; i < s.top; i++)
                {
                    cout<<s.arr[i]<<" ";
                }
                
            }
        }

int main()
{
    push(12);
    push(12);
    push(145);
    push(1234);
    push(1212);
    display();


}
#include <iostream>
using namespace std;

class circularQueue {
public:
    int* arr;
    int front;
    int back;
    int size = 5;

    circularQueue() {
        arr = new int[size];
        front = -1;
        back = -1;
    }

    bool isFull() {
        return ((back + 1) % size == front);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full." << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            back = (back + 1) % size;
            arr[back] = data;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            int data = arr[front];
            if (front == back) {
                front = -1;
                back = -1;
            } else {
                front = (front + 1) % size;
            }
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        } else {
            cout << "Queue elements: ";
            int i = front;
            while (i != back) {
                cout << arr[i] << " ";
                i = (i + 1) % size;
            }
            cout << arr[back] << endl;  // print the last element
        }
    }
};

int main() {
    circularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();   // Shows the queue contents
    q.dequeue();
    q.display();   // Shows the queue after one dequeue
    q.enqueue(60); // Enqueue after dequeue
    q.display();   // Shows the updated queue
}

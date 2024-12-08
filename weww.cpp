#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class CircularDoublyLinkedListQueue {
    public:
    Node* head;
    Node* tail;

    CircularDoublyLinkedListQueue() {
        head = NULL;
        tail = NULL;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->next = head;
            newNode->prev = head;
        } else {
            newNode->prev = tail;
            newNode->next = head;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
    }

    void dequeue() {
        if (head == NULL) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
        } else {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }
    }

    void printQueue() {
        if (head == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Queue (Forward): ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void printQueueBackward() {
        if (head == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = tail;
        cout << "Queue (Backward): ";
        do {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != tail);
        cout << endl;
    }
};

int main() {
    CircularDoublyLinkedListQueue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(5);

    queue.printQueue();
    queue.printQueueBackward();

    cout << "Dequeuing..." << endl;
    queue.dequeue();
    queue.printQueue();

    cout << "Dequeuing..." << endl;
    queue.dequeue();
    queue.printQueue();

    cout << "Enqueueing 50 and 60..." << endl;
    queue.enqueue(50);
    queue.enqueue(60);
    queue.printQueue();
    queue.printQueueBackward();

    return 0;
}

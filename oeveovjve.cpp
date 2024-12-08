#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}  // Constructor to initialize data and next
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}  // Initialize head to nullptr

    // Insert a new node at the beginning
    void insertAtBeginning(int data) {
        Node* newnode = new Node(data);
        newnode->next = head;
        head = newnode;
        cout << "Inserted value at the beginning: " << data << "\n";
    }

    // Insert a new node at the end
    void insertAtEnd(int data) {
        Node* newnode = new Node(data);
        if (head == nullptr) {
            head = newnode;
            cout << "Inserted value at the end of the list (first node): " << data << "\n";
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
        cout << "Inserted value at the end of the list: " << data << "\n";
    }

    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr\n";
    }
};

int main() {
    LinkedList list;
    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.insertAtEnd(30);
    
    list.display();  // Expected output: 5 -> 10 -> 20 -> 30 -> nullptr

    return 0;
}

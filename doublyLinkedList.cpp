#include <iostream>
using namespace std;

class Node {
    public:
    int value;
    Node* prev;
    Node* next;
    Node(int value) : value(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {

    Node* head;
    Node* tail;
    int size;

    public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void InsertNode(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
        cout << "Inserted: " << value << endl;
        Display();
    }

    bool DeleteNode(int value) {
        Node* current = head;
        while (current) {
            if (current->value == value) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }

                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }

                delete current;
                size--;
                cout << "Deleted: " << value << endl;
                Display();
                return true;
            }
            current = current->next;
        }

        cout << "Value " << value << " not found in the list." << endl;
        return false;
    }

    bool MoveHead(int position) {
        if (position < 0 || position >= size) {
            cout << "Invalid position: " << position << endl;
            return false;
        }

        Node* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }

        if (current == head) {
            cout << "Head is already at position " << position << endl;
            return true;
        }

        tail->next = head;
        head->prev = tail;

        head = current;
        tail = current->prev;
        tail->next = nullptr;
        head->prev = nullptr;

        cout << "Moved head to position: " << position << endl;
        Display();
        return true;
    }

    void Display() {
        Node* current = head;
        cout << "List: ";
        while (current) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

};

int main() {
    DoublyLinkedList d;

    d.InsertNode(10);
    d.InsertNode(20);
    d.InsertNode(30);
    d.InsertNode(40);

    d.DeleteNode(20);
    d.DeleteNode(50);

    d.MoveHead(2);
    d.MoveHead(5);

    return 0;
}

#include<iostream>
using namespace std;

class Node
{
    public:
    Node* next,* prev;
    int data;
    Node(int data) : data(data) , next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList
{
    Node* head;
    public:
    DoublyLinkedList() : head(nullptr) {}

    void insertAtBiginning(int data)
    {
        Node* newnode = new Node(data);
        newnode->next = head;
        if (head!=nullptr) {
            head->prev = newnode;
        }
        head = newnode;
        cout<<"Inserted at the beginning: "<<newnode->data<<endl;
    }
    void insertAtEnd(int data)
    {
        Node* newnode = new Node(data);
        if (head==nullptr) {
            newnode = head;
            return;
        }
        Node* temp = head;
        while(temp->next!=nullptr)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    void insertAtPosition(int data , int position)
    {
        Node* newnode = new Node(data);
        if(position<=0)
        {
            insertAtBiginning(data);
            return;
        }
        Node* temp = head;
        for(int i=0; temp!=nullptr || i<position-1; i++)
        {
            temp = temp->next;
        }
        if (temp==nullptr) {
            cout<<"Position is greater than the List itself\n";
            insertAtEnd(data);
            return;
        }
        newnode->next = temp->next;
        if(temp!=nullptr)
        {
            temp->next->prev = newnode;
        }
        temp->next = newnode;
        newnode->prev = temp;
            
        }
         void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Printing list: ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "nullptr\n";
    }

    // Function to display the list from end to head
    void displayReverse() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        // Traverse to the end of the list
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        // Print the list in reverse
        cout << "Printing list in reverse: ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "nullptr\n";
    }

    void deleteList(int data)
    {
        if(head==nullptr)
        {
            cout<<"List already Empty";
            return;
        }
        Node* temp = head;
        for(int i=0; temp <= data-1 || temp!= nullptr; i++)
        {
            
        }

    }

    };


int main() {
    DoublyLinkedList list;
    list.insertAtBiginning(10);
    list.insertAtEnd(20);
    list.insertAtBiginning(5);
    list.insertAtEnd(30);
    
    // Inserting at specific positions
    list.insertAtPosition(15, 1); // Insert 15 at position 1
    list.insertAtPosition(25, 3); // Insert 25 at position 3
    list.insertAtPosition(35, 10); // Position is beyond length, insert at end

    list.display();          // Print the list
    list.displayReverse();   // Print the list in reverse
    list.deleteList();
    return 0;
}
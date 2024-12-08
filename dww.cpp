#include <iostream>

using namespace std;

struct Customer {
  string name;
  bool urgent;
  Customer* next;
};

class Queue {
public:
  Customer* front;
  Customer* rear;

  Queue() { 
    front = nullptr; 
    rear = nullptr; 
  }

  void enqueue(string name) {
    Customer* newCustomer = new Customer;
    newCustomer->name = name;
    newCustomer->urgent = false; 
    newCustomer->next = nullptr;

    if (isEmpty()) {
      front = rear = newCustomer;
    } else {
      rear->next = newCustomer;
      rear = newCustomer;
    }
    cout << name << " added to the queue." << endl;
  }

  void enqueueUrgent(string name) {
    Customer* newCustomer = new Customer;
    newCustomer->name = name;
    newCustomer->urgent = true; 
    newCustomer->next = front;
    front = newCustomer;
    cout << "Urgent customer " << name << " added to the front of the queue." << endl;
  }

  void dequeue() {
    if (isEmpty()) {
      cout << "Queue is empty." << endl;
      return;
    }

    Customer* temp = front;
    string dequeuedName = front->name;
    front = front->next;

    if (front == nullptr) {
      rear = nullptr;
    }

    delete temp;
    cout << dequeuedName << " served." << endl;
  }

  bool isEmpty() { return front == nullptr; }

  void display() {
    if (isEmpty()) {
      cout << "Queue is empty." << endl;
      return;
    }
    Customer* current = front;
    cout << "Customers in queue: ";
    while (current != nullptr) {
      cout << current->name << (current->urgent ? " (urgent) " : " ") ;
      current = current->next;
    }
    cout << endl;
  }
};

int main() {
  Queue callCenter;

  callCenter.enqueue("Haseeb");
  callCenter.enqueue("Munawar");
  callCenter.enqueueUrgent("Abdullah");
  callCenter.enqueue("Ali");
  callCenter.display(); 
  callCenter.dequeue();
  callCenter.display(); 
  callCenter.enqueue("Ashfaq");
  callCenter.enqueueUrgent("Azam"); 
  callCenter.display();
  callCenter.dequeue(); 
  callCenter.display(); 
  callCenter.dequeue();
  callCenter.display(); 
  callCenter.dequeue(); 
  callCenter.display(); 
  callCenter.dequeue(); 
  callCenter.display(); 
  callCenter.dequeue();
  callCenter.display(); 

  return 0;
}
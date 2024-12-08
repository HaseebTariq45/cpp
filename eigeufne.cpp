#include <iostream>
using namespace std;

class Node
{
public:
    Node* next;
    Node* prev;
    string name;
    bool status;
    int seatNum;

    Node(int seat = 0)
        : next(nullptr), prev(nullptr), name(""), status(false), seatNum(seat) {}
};

class train
{
    Node* head;

public:
    train() : head(nullptr) {}

    void createSeats() {
        Node* prev = nullptr;
        for (int i = 1; i <= 20; ++i) {
            Node* newnode = new Node(i);  
            if (!head) {
                head = newnode;
            }
            if (prev) {
                prev->next = newnode;
                newnode->prev = prev;
            }
            prev = newnode;
        }
        head->prev = prev;
        prev->next = head;  
    }

    void reserve(string name, int seatNum) {
        Node* temp = head;
        do {
            if (temp->seatNum == seatNum) {
                if (!temp->status) {
                    temp->name = name;
                    temp->status = true;
                    cout << "Seat " << seatNum << " reserved by " << name << ".\n";
                } else {
                    cout << "Seat " << seatNum << " is already reserved.\n";
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Seat " << seatNum << " not found.\n";
    }

    void cancelSeat(int seatNum) {
        Node* temp = head;
        do {
            if (temp->seatNum == seatNum && temp->status) {
                temp->name = "";
                temp->status = false;
                cout << "Seat " << seatNum << " reservation cancelled.\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Seat " << seatNum << " is not reserved.\n";
    }

    void rowTraversal(int seatNum) {
        Node* temp = head;
        cout << "Displaying all seat statuses starting from seat " << seatNum << ":\n";
        do {
            if (temp->status) {
                cout << "Seat " << temp->seatNum << " is reserved by " << temp->name << ".\n";
            } else {
                cout << "Seat " << temp->seatNum << " is available.\n";
            }
            temp = temp->next;
        } while (temp != head);
    }

    void passengerSearch(string sname) {
        Node* temp = head;
        do {
            if (temp->name == sname) {
                cout << "Passenger found:\nName: " << temp->name
                     << "\nSeat Number: " << temp->seatNum << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Passenger " << sname << " not found.\n";
    }

    void printPassengers() 
        Node* temp = head;
        cout << "Printing all reserved passengers:\n";
        do {
            if (temp->status) {
                cout << "Name: " << temp->name << "\nSeat Number: " << temp->seatNum << endl;
            }
            temp = temp->next;
        } while (temp != head);
    }
};

int main() {
    train t;
    t.createSeats();

    t.reserve("Haseeb", 3);
    t.reserve("Munawar", 5);
    t.reserve("Abdullah", 6);
    t.reserve("Basit", 8);
    t.reserve("Nouman", 10);

    cout << "---------- Passenger Search ----------\n";
    t.passengerSearch("Haseeb");

    cout << "\n------ Printing All Reserved Passengers -------\n";
    t.printPassengers();

    cout << "\n---------- Row Traversal from Seat 3 ----------\n";

    t.rowTraversal(3);
    cout<<"--------Cancel Seats-----------";
    t.cancelSeat(1);!¬1

    return 0;
}

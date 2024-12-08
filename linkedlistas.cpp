#include <iostream>
#include <stdio.h>
using namespace std;

    class Student
    {
        public:
        string name;
        string enroll;
    };
    class Node
    {
        public:
        Student data;
        int marks;
        Node* next;

        Node(const string& n, const string& e, int m) :
        data{ n , e } , marks {m} , next(nullptr) {}
    };
    class List {
public:
Node* head;
List() : head(nullptr) {}
void addNode(const string& name, const string& enroll, int marks) {
Node* newNode = new Node(name, enroll, marks);
newNode->next = head;
head = newNode;
}
};


int main()
{

    List studentList;

studentList.addNode("Ali", "01-234123-001", 85);
studentList.addNode("Bilal", "01-234123-002", 92);
studentList.addNode("Amir", "01-234123-003", 78);

    Node* current = studentList.head;

    while (current) 
    {
    cout << "Name: " << current->data.name << ", Enrollment: " << current->data.enroll << ", Marks: " << current->marks << endl;
    current = current->next;
    }

return 0;
}
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string email;
    string password;
    Node* next;

    Node(string email, string password) : email(email), password(password), next(nullptr) {}
};

class HashTable {
    Node** table;
    int numBuckets;

    int hashFunction(string email) {
        int hash = 0;
        for (char c : email) {
            hash = (hash * 31 + c) % numBuckets;
        }
        return hash;
    }

public:
    HashTable(int buckets) : numBuckets(buckets) {
        table = new Node*[numBuckets];
        for (int i = 0; i < numBuckets; i++) {
            table[i] = nullptr;
        }
    }

    void insert(string email, string password) {
        int index = hashFunction(email);
        Node* current = table[index];

        while (current) {
            if (current->email == email) {
                cout << "Email already exists. Insertion failed.\n";
                return;
            }
            current = current->next;
        }

        Node* newNode = new Node(email, password);
        newNode->next = table[index];
        table[index] = newNode;
        cout << "Credentials added successfully.\n";
    }

    void remove(string email) {
        int index = hashFunction(email);
        Node* current = table[index];
        Node* prev = nullptr;

        while (current) {
            if (current->email == email) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    table[index] = current->next;
                }
                delete current;
                cout << "Credentials removed successfully.\n";
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Email not found. Deletion failed.\n";
    }

    void display() {
        cout << "Hash Table Contents:\n";
        for (int i = 0; i < numBuckets; i++) {
            cout << "Bucket " << i << ": ";
            Node* current = table[i];
            if (!current) {
                cout << "Empty";
            }
            while (current) {
                cout << "[" << current->email << " | " << current->password << "] -> ";
                current = current->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    int buckets;
    cout << "Enter the number of buckets for the hash table: ";
    cin >> buckets;

    HashTable hashTable(buckets);
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert credentials\n";
        cout << "2. Delete credentials\n";
        cout << "3. Display hash table\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string email, password;
            cout << "Enter email: ";
            cin >> email;
            cout << "Enter password: ";
            cin >> password;
            hashTable.insert(email, password);
        } else if (choice == 2) {
            string email;
            cout << "Enter email to delete: ";
            cin >> email;
            hashTable.remove(email);
        } else if (choice == 3) {
            hashTable.display();
        } else if (choice != 4) {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    cout << "Exiting program.\n";
    return 0;
}

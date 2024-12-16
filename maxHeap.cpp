#include <iostream>  
using namespace std;  

const int MAX_SIZE = 100; // Maximum size of the heap  

class MaxHeap {
private:
    int heap[MAX_SIZE]; // Array to store the heap
    int size; // Current size of the heap

    void swap(int &a, int &b) { // Pass by reference for simplicity
        int temp = a;
        a = b;
        b = temp;
    }

    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1, right = 2 * i + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {  
            swap(heap[i], heap[largest]);  
            heapify(largest);  
        }  
    }  

public:  
    MaxHeap() : size(0) {} // Constructor to initialize size  

    void insert(int newNum) {  
        if (size < MAX_SIZE) {  
            heap[size] = newNum;  
            size++;  

            for (int current = size - 1; current > 0;) {  
                int parent = (current - 1) / 2;  
                if (heap[current] > heap[parent]) {  
                    swap(heap[current], heap[parent]);  
                    current = parent;  
                } else {  
                    break;  
                }  
            }  
        } else {  
            cout << "Heap is full!" << endl;  
        }  
    }  

    void deleteNode(int num) {  
        int i;  
        for (i = 0; i < size; i++) {  
            if (num == heap[i]) break;  
        }  

        if (i < size) {  
            swap(heap[i], heap[size - 1]);  
            size--;  
            heapify(i);  
        } else {  
            cout << "Element not found in the heap!" << endl;  
        }
    }  

    void printHeap() const {  
        for (int j = 0; j < size; j++)  
            cout << heap[j] << " ";  
        cout << endl;  
    }  
};  

int main() {  
    MaxHeap heap;  

    heap.insert(3);  
    heap.insert(4);  
    heap.insert(9);  
    heap.insert(5);  
    heap.insert(2);  

    cout << "Max-Heap array: ";  
    heap.printHeap();  

    heap.deleteNode(4);  
    cout << "After deleting an element: ";  
    heap.printHeap();  

    return 0;  
}
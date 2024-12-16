#include<iostream>
using namespace std;
const int MaxSize = 100;
class MaxHeap
{
    public:
    int heap[MaxSize];
    int size;

    void swap (int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    void heapify(int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < size && heap[left] > heap[largest])
        {
            largest = left;
        }
        if (left < size && heap[left] > heap[largest])
        {
            largest = right;
        }
        if (largest!=i)
        {
            swap(heap[i], heap[largest]);
            heapify(largest);;
        }
    }
    
            MaxHeap(): size(0) {}

        void insert(int num)
        {
            if(size < MaxSize)
            {
                heap[size] = num;
                size++;
            for(int current = size  - 1; current > 0; )
            {
                int parent = (current - 1)/2; 
                if(heap[current] > heap[parent])
                {
                    swap(heap[current],heap[parent] );
                    current = parent;
                }
                else
                {
                    break;
                }
            }
            }
            else
            {
                cout<<"Heap is full\n";
            }
        }

        void deleteNode(int num)
        {
            int i;
            for (int i = 0; i < size; i++)
            {
                if(num==heap[i])
                {
                    break;
                }
            }
            if(i < size)
            {
                swap(heap[i], heap[size - 1]);
                size--;
                heapify(i);
            }
            else
            {
                cout<<"Element not found in the heap\n";
            }
            
        }
        void printHeap()
        {
            for (int i = 0; i < size; i++)
            {
                cout<<heap[i]<<" ";
            }
            
        }
};
int main()
{
    MaxHeap heap;  

    heap.insert(3);  
    heap.insert(1);  
    heap.insert(4);  
    heap.insert(1);  
    heap.insert(5);
    heap.insert(9);
    heap.insert(2);
    heap.insert(6);

    cout << "Max-Heap array: ";  
    heap.printHeap();  

    heap.deleteNode(4);  
    cout << "After deleting an element: ";  
    heap.printHeap();  
    return 0;
}
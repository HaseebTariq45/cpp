#include<iostream>
using namespace std;
class Heap{
    int* heap;
    int size,capacity;
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return (2*i+1);
    }
    int right(int i){
        return (2*i+2);
    }
    void heapifyDown(int i){
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < size && heap[l] < heap[smallest])
            smallest = l;
        if (r<size && heap[r] < heap[smallest]) 
            smallest = r;
        
        if(smallest != i){
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        };
    }
    void heapifyUp(int i){
        while (i > 0 && heap[i] < heap[parent(i)])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
        
    }
};
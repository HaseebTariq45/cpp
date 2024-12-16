#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if(left < n && arr[left] > arr[largest])
    largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if(largest!=i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapsort(int arr[], int n)
{
    for (int i = n/2-1; i >= 0; i--)
    {
        heapify(arr,n,i);
    }
    
    for(int i = n -1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr,i,0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[] = {15, 19, 10, 7, 17, 16};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Original Array: ";
    printArray(arr, n);
    cout<<endl;
    heapsort(arr,n);
    cout<<"Sorted Array: ";
    printArray(arr,n);
    cout<<endl;
    return 0;
}
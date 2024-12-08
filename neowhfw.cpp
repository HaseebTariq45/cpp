#include<iostream>
using namespace std;

void swap(int& a,int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[],int low, int high)
{
  int pivot = arr[high];
  int i = low-1;

  for (int j = low; j < high; j++)
  {
    if (arr[j]<=pivot)
    {
        i++;
        swap(arr[i],arr[j]);
    }
  }
    swap(arr[i+1],arr[high]);
    return i+1;
  
}
void QuickSort(int arr[], int low, int high)
{
  if (low<high)
  {
     int pi = partition(arr,low,high);

   QuickSort(arr,low,pi-1);
   QuickSort(arr,pi+1,high);
  }
  
    
}

void print(int arr[], int arrsize)
{
    for (int i = 0; i < arrsize; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[] = {1,23,5,4,656,67,6,8,6654,3,34,34,5454,565,23};
    int arrsize = sizeof(arr) / sizeof(arr[0]);
    cout<<"Original Array: ";
    print(arr,arrsize);
    QuickSort(arr,0,arrsize-1);
    cout<<"Sorted Array: ";
    print(arr,arrsize);
}
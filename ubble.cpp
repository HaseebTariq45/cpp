#include <iostream>
#include <stdio.h>
using namespace std;

int binarySearch(int arr[], int key,int size)
{
    int left = 0;
    int right = size - 1;

    while(left<=right)
    {
        int mid = (left + right)/2;
        if (arr[mid]==key)
        {
            return mid;
        }
        else if (arr[mid]>=key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;

}

int main()
{
    int size = 10;
    int arr[size]  = {1,7,9,23,34,45,56,7,78,89};
    int key;
    while (true)
    {
        cout<<"\nEnter key: ";
    cin>>key;
    int result = binarySearch(arr,  key, size);
    if (result!=-1)
    {
        cout<<"Key found at Location: "<<result+1;
    }
    else
    {
        cout<<"Key not found";
    }
    }
    
    


return 0;
}
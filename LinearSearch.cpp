#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int search;
    int arr[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    cout<<"Enter the number to Search: ";
    cin>>search;
    bool found = false;
    for (int i = 0; i < 20; i++)
    {
        if (search==arr[i])
        {
            found = true;
            cout<<"Number found at Location of the Array: "<<i+1;
                       
        }
    }
     if(found!=true)
    {
        cout<<"Number not found";
    }

    




return 0;
}
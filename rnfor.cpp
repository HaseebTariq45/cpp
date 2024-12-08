#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int size = 10 ;
    int arr[size] = {1,2,3,0,5,6,0,1,8,7};
    int key;
    cout<<"Enter key:";
    cin>>key;
    int location;
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (key==arr[i])
        {
            found = true;
            location = i+1;
        }
    }
    if (found=true)
    {
        cout<<"Key found at location "<<location;
    }
    else
    {
        cout<<"Key not found";
    }
    
    


return 0;
}
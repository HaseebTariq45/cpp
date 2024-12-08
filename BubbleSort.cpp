#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int arr[10] = {10,9,8,7,5,6,4,2,3,1};
    int temp,pass;
    for (int pass = 0; pass < 10; pass++)
    {
        for (int j = 0; j < 10 - pass; j++)
        {
            if (arr[j] >  arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
        }
        
    }
    cout<<"The sorted Array is below\n";
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";        
    }
    
    


return 0;
}
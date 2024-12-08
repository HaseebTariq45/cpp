#include <iostream>
using namespace std;

int main()
{
    //Static Arrays////////
    // int n = 5;
    // int arr[n];
    // for(int i = 0; i < n; i++)
    // {
    //     cout<<"Add Entry: ";
    //     cin>>arr[i];
    //     cout<<"Entry Added\n";
    // }



//////////////  dynamic Arrays   //////////////
// int *arr;
// int n = 5;

// arr = new int[n];


    // for(int i = 0; i < n; i++)
    //     {
    //         cout<<"Add Entry: ";
    //         cin>>arr[i];
    //         cout<<"Entry Added\n";
    //     }
    // cout<<"Shwoing data\n";
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<endl;
    // }
    
    // delete []arr;




int a[] = {1, 2, 3, 4, 5};
int *p;
p=a;
for(int i=0; i<5; i++)
{
//Subscript notation with array name
cout<<a[i];
//Subscript notation with pointer name
cout<<p[i];
//Offset notation using array name
cout<<*(a+i);
//Offset notation using pointer name
cout<<*(p+i);

}





}
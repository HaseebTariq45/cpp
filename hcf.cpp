#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n1,n2,hcf;
    cout<<"Enter two numbers\n";
    cin>>n1>>n2;

    while (n1!=n2)
    {
        if (n1>n2)
        {
            n1-=n2;
        }
        else
        {
            n2-=n1;
        }
    
}
cout<<"HCF = "<<n1;
}
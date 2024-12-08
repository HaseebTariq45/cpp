#include <iostream>
#include <stdio.h>
using namespace std;
int total;
int square(int x)
{
    return x*x;
}
int sumofSquare(int x,int y)
{
    int z = square(x+y);
    return z;
}
int main()
{
    int a = 4,
    b = 8;
    total = sumofSquare(a,b);
    printf("%d",total);
    
return 0;
}
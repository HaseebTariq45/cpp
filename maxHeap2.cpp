#include<iostream>
using namespace std;

void insert(int a[], int n)
 {
    int i = n;
    int temp = a[i];

    while (i > 1 && temp > a[i / 2])
     {
        a[i] = a[i / 2];  // Move the parent down
        i = i / 2;        // Move up the tree
    }
    a[i] = temp;  // Place temp in its correct position
}

int del(int a[], int n) 
{
    int val = a[1];  // Store the root value to be deleted
    int x = a[n];    // Take the last element
    a[1] = x;        // Move the last element to the root
    int i = 1, j = 2 * i;

    while (j <= n - 1) {
        if (j + 1 <= n - 1 && a[j + 1] > a[j]) {
            j = j + 1;  // Find the larger child
        }
        if (a[i] < a[j]) {
            swap(a[i], a[j]);  // Swap if parent is smaller
            i = j;
            j = 2 * i;
        } else {
            break;
        }
    }
    return val;
}

int main()
 {
    int h[]{ 0, 10, 20, 30, 25, 5, 40, 35 };

    // Insert elements into the heap
    for (int i = 2; i <= 7; i++) 
    {
        insert(h, i);
    }

    // Delete the root element
    del(h, 7);

    // Print the heap array
    for (int i = 1; i <= 7; i++) {
        cout << h[i] << " ";
    }

    return 0;
}
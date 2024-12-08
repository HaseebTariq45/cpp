#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function to place the pivot in the correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // choosing the last element as pivot
    int i = low - 1;       // index of the smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]); // swap
        }
    }
    swap(arr[i + 1], arr[high]); // swap the pivot element with the element at i + 1
    return i + 1; // return the partitioning index
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // partitioning index

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void print(int arr[], int size) {
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 3, 4, 7, 34, 45, 65, 67, 8734, 23, 43, 65, 76, 3, 23, 45, 6, 7, 56, 3, 34, 4, 65, 76, 76, 8686, 76, 767, 6, 5, 3, 4, 6, 8};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    print(arr, arrSize);

    quickSort(arr, 0, arrSize - 1);

    cout << "Sorted Array: ";
    print(arr, arrSize);

    return 0;
}

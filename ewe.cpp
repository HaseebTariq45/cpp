#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid;    // Size of the right subarray

    int l[n1], r[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        l[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        r[i] = arr[mid + 1 + i]; // Fixed indexing here
    }

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) {
            arr[k] = l[i];
            i++;
        } else {
            arr[k] = r[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of l[] if any
    while (i < n1) {
        arr[k] = l[i];
        i++;
        k++;
    }

    // Copy remaining elements of r[] if any
    while (j < n2) {
        arr[k] = r[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

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

    mergeSort(arr, 0, arrSize - 1);

    cout << "Sorted Array: ";
    print(arr, arrSize);

    return 0;
}

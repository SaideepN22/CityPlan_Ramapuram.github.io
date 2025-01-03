#include <iostream>
using namespace std;

// Function to partition the array
int Partition(int A[], int l, int r) {
    int pivot = A[l]; // Pivot is the first element
    int i = l;
    int j = r + 1;

    while (true) {
        // Move i to the right until an element >= pivot is found
        do {
            i++;
        } while (i <= r && A[i] <= pivot);

        // Move j to the left until an element <= pivot is found
        do {
            j--;
        } while (A[j] > pivot);

        // If pointers cross, partitioning is complete
        if (i >= j)
            break;

        // Swap elements at i and j
        swap(A[i], A[j]);
    }

    // Swap pivot with the element at the partition index
    swap(A[l], A[j]);

    return j; // Return the partition index
}

// QuickSort function
void QuickSort(int A[], int l, int r) {
    if (l < r) {
        // Partition the array and get the split position
        int s = Partition(A, l, r);

        // Recursively sort the left and right subarrays
        QuickSort(A, l, s - 1);
        QuickSort(A, s + 1, r);
    }
}

// Main function
int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int A[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Call QuickSort
    QuickSort(A, 0, n - 1);

    // Display sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}

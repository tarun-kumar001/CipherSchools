#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n, int &totalSwaps, int &totalPasses) {
    totalSwaps = 0;
    totalPasses = 0;
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        totalPasses++;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                totalSwaps++;
                swapped = true;
            }
        }

        if (!swapped) {
            break; // Exit early if no swaps were made in this pass
        }
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int array[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    int totalSwaps = 0, totalPasses = 0;

    // Perform bubble sort
    bubbleSort(array, size, totalSwaps, totalPasses);

    // Output the sorted array
    cout << "Sorted Array: [";
    for (int i = 0; i < size; i++) {
        cout << array[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    // Output total swaps and passes
    cout << "Total Swaps: " << totalSwaps << endl;
    cout << "Total Passes: " << totalPasses << endl;

    return 0;
}

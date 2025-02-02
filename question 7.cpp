#include <iostream>
using namespace std;

// Function to merge two subarrays and count inversions
long long mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;    // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left;    // Starting index to be sorted
    long long invCount = 0;

    while ((i <= mid) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1); // Count inversions
        }
    }

    // Copy the remaining elements of left subarray, if any
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements of right subarray, if any
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the sorted subarray into the original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

// Function to count inversions using Divide and Conquer
long long mergeSortAndCount(int arr[], int temp[], int left, int right) {
    long long invCount = 0;
    if (left < right) {
        int mid = (left + right) / 2;

        invCount += mergeSortAndCount(arr, temp, left, mid);
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);

        invCount += mergeAndCount(arr, temp, left, mid, right);
    }
    return invCount;
}

int main() {
    int size = 5;
    int array[] = {2, 4, 1, 3, 5};

    int temp[size];
    long long totalInversions = mergeSortAndCount(array, temp, 0, size - 1);

    cout << "Total Inversions: " << totalInversions << endl;

    return 0;
}

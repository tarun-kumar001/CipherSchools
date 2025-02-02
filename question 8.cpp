#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Function to perform counting sort based on a specific character position
void countingSort(vector<string> &arr, int size, int pos) {
    vector<string> output(size);
    int count[26] = {0};

    // Count occurrence of each character at position 'pos'
    for (int i = 0; i < size; i++) {
        count[arr[i][pos] - 'a']++;
    }

    // Update count array to contain actual positions
    for (int i = 1; i < 26; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i][pos] - 'a'] - 1] = arr[i];
        count[arr[i][pos] - 'a']--;
    }

    // Copy sorted strings back to the original array
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

// Function to perform Radix Sort on strings
void radixSort(vector<string> &arr, int size, int stringLength) {
    // Sort by each character position, starting from the last character
    for (int pos = stringLength - 1; pos >= 0; pos--) {
        countingSort(arr, size, pos);
    }
}

int main() {
    int size = 5;
    vector<string> arr = {"cat", "bat", "rat", "car", "bar"};

    // Determine the length of the strings (all strings are assumed to have the same length)
    int stringLength = arr[0].length();

    // Perform Radix Sort
    radixSort(arr, size, stringLength);

    // Output the sorted array
    cout << "Sorted Array: [";
    for (int i = 0; i < size; i++) {
        cout << '"' << arr[i] << '"';
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}

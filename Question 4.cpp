#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    // Step 1: Prompt the user to enter the number of elements
    cout << "Enter the number of elements you want to store in the dynamic array: ";
    cin >> n;

    // Step 2: Create a vector to store the elements
    vector<int> dynamicArray;

    // Step 3: Input elements from the user
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        dynamicArray.push_back(element); // Add each element to the vector
    }

    // Step 4: Display the elements of the vector
    cout << "The elements in the dynamic array are:" << endl;
    for (int i = 0; i < dynamicArray.size(); i++) {
        cout << dynamicArray[i] << " ";
    }
    cout << endl;

    // Step 5: Add a new element to the vector
    cout << "Enter a new element to add to the dynamic array: ";
    int newElement;
    cin >> newElement;
    dynamicArray.push_back(newElement);

    // Display the updated vector
    cout << "The updated dynamic array is:" << endl;
    for (int i = 0; i < dynamicArray.size(); i++) {
        cout << dynamicArray[i] << " ";
    }
    cout << endl;

    return 0;
}

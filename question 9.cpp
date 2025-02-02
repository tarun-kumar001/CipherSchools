#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class SquareRootDecomposition {
private:
    vector<int> arr;
    vector<int> blocks;
    int blockSize;

public:
    // Constructor to initialize data structures
    SquareRootDecomposition(const vector<int> &input) {
        arr = input;
        int n = arr.size();
        blockSize = sqrt(n);
        blocks.resize((n + blockSize - 1) / blockSize, 0);

        // Precompute block sums
        for (int i = 0; i < n; i++) {
            blocks[i / blockSize] += arr[i];
        }
    }

    // Update the value at a specific index
    void update(int index, int value) {
        int blockIndex = index / blockSize;
        blocks[blockIndex] += value - arr[index];
        arr[index] = value;
    }

    // Query the sum of a range [L, R]
    int query(int left, int right) {
        int sum = 0;
        int startBlock = left / blockSize;
        int endBlock = right / blockSize;

        if (startBlock == endBlock) {
            for (int i = left; i <= right; i++) {
                sum += arr[i];
            }
        } else {
            for (int i = left; i < (startBlock + 1) * blockSize; i++) {
                sum += arr[i];
            }
            for (int i = startBlock + 1; i < endBlock; i++) {
                sum += blocks[i];
            }
            for (int i = endBlock * blockSize; i <= right; i++) {
                sum += arr[i];
            }
        }
        return sum;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SquareRootDecomposition srd(arr);

    for (int i = 0; i < q; i++) {
        string type;
        cin >> type;

        if (type == "UPDATE") {
            int index, value;
            cin >> index >> value;
            srd.update(index - 1, value); // Convert to 0-based index
        } else if (type == "QUERY") {
            int left, right;
            cin >> left >> right;
            cout << srd.query(left - 1, right - 1) << endl; // Convert to 0-based index
        }
    }

    return 0;
}

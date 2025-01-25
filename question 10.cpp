#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to calculate the stock span
vector<int> calculateSpan(const vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        // Pop elements from the stack while the stack is not empty and the
        // current price is greater than the price at the index stored on top of the stack
        while (!s.empty() && prices[s.top()] <= prices[i]) {
            s.pop();
        }

        // Calculate the span
        span[i] = (s.empty()) ? (i + 1) : (i - s.top());

        // Push this element's index onto the stack
        s.push(i);
    }

    return span;
}

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    vector<int> span = calculateSpan(prices);

    for (int i = 0; i < n; i++) {
        cout << span[i] << " ";
    }
    cout << endl;

    return 0;
}

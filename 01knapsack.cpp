#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapsack_dp(int W, vector<int>& wt, vector<int>& val, int n) {
    // Create a 2D DP table with n+1 rows and W+1 columns
    vector<vector<int>> K(n + 1, vector<int>(W + 1, 0));

    // Fill the table in a bottom-up manner
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            // Base case: No items or no capacity
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            }
            // If the current item can be included in the knapsack
            else if (wt[i - 1] <= w) {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            }
            else {
                // If the current item cannot be included
                K[i][w] = K[i - 1][w];
            }
        }
    }

    // The maximum value will be in the bottom-right cell of the table
    return K[n][W];
}

int main() {
    // Input handling
    int n;
    cout << "Enter Number of elements: ";
    cin >> n;

    vector<int> wt(n), val(n);

    // Input weights and values
    cout << "Enter Weight (space separated): ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    cout << "Enter Value (space separated): ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    // Input the capacity of the knapsack
    int W;
    cout << "Enter Capacity: ";
    cin >> W;

    // Output the maximum profit the knapsack can hold
    cout << "Maximum possible profit = " << knapsack_dp(W, wt, val, n) << endl;

    return 0;
}

// # Enter Number of elements
// # 4
// # Enter Weight: 10 20 30 40
// # Enter value: 60 100 120 150
// # Enter Capacity
// # 50

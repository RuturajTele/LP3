#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Class to represent an item with weight, value, and its index
class ItemValue {
public:
    int wt;
    int val;
    int ind;
    double cost;  // Value-to-weight ratio

    ItemValue(int wt_, int val_, int ind_) {
        wt = wt_;
        val = val_;
        ind = ind_;
        cost = (double)val / wt_;  // Cost per unit weight
    }

    // Overloading < operator to sort by cost in descending order
    bool operator < (const ItemValue& other) const {
        return cost > other.cost;  // Sort in descending order
    }
};

// Function to solve the fractional knapsack problem
double fractionalKnapSack(vector<int>& wt, vector<int>& val, int capacity) {
    vector<ItemValue> iVal;

    // Create a vector of ItemValue objects
    for (int i = 0; i < wt.size(); i++) {
        iVal.push_back(ItemValue(wt[i], val[i], i));
    }

    // Sort the items based on their value-to-weight ratio in descending order
    sort(iVal.begin(), iVal.end());

    double totalValue = 0;  // Variable to store the total value in knapsack

    // Process each item
    for (const auto& item : iVal) {
        int curWt = item.wt;
        int curVal = item.val;

        // If the item can be fully accommodated in the knapsack
        if (capacity - curWt >= 0) {
            capacity -= curWt;
            totalValue += curVal;
        } else {
            // If the item cannot be fully accommodated, take a fraction
            double fraction = (double)capacity / curWt;
            totalValue += curVal * fraction;
            capacity = 0;  // Knapsack is full now
            break;
        }
    }

    return totalValue;
}

int main() {
    // Example input
    vector<int> wt = {10, 60, 20, 40};
    vector<int> val = {50, 40, 100, 150};
    int capacity = 50;

    // Call the fractional knapsack function
    double maxValue = fractionalKnapSack(wt, val, capacity);

    // Output the maximum value in the knapsack
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}

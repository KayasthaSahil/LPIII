#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int knapsackDP(int W, const vector<int>& wt, const vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (wt[i - 1] > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            }
        }
    }

    return dp[n][W];
}


int main() {
    int n; 
    int W; 

    cout << "-------------------------------------------\n";
    cout << "  0-1 Knapsack Problem Solver (DP)\n";
    cout << "-------------------------------------------\n";

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the total capacity of the knapsack: ";
    cin >> W;

    vector<int> val(n);
    vector<int> wt(n);

    cout << "Enter the value and weight for each item:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Item " << i + 1 << " (Value Weight): ";
        cin >> val[i] >> wt[i];
        if (wt[i] <= 0 || val[i] < 0) {
            cout << "Error: Weight must be positive and value must be non-negative. Please try again." << endl;
            --i;
        }
    }

    int maxValue = knapsackDP(W, wt, val, n);

    cout << "\n-------------------------------------------\n";
    cout << "Maximum value in knapsack = " << maxValue << endl;
    cout << "-------------------------------------------\n";

    return 0;
}
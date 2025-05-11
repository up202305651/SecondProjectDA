//
// Created by bia on 5/11/25.
//
#include <vector>
#include <iostream>
#include "pallet.h"

using namespace std;

// Time complexity: O(n * W)
// Space complexity: O(n * W) for the dp table

void dynamicProgramming(Data& data, vector<Pallet>& pallets) {
    int n = data.n_pallets;
    int W = data.capacity;

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the dp table
    for (int i = 1; i <= n; i++) {
        int wt = pallets[i - 1].weight;
        int pf = pallets[i - 1].profit;
        for (int w = 0; w <= W; ++w) {
            if (wt > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt] + pf);
            }
        }
    }

    // Retrieve the selected pallets
    int w = W;
    vector<Pallet> solution;
    for (int i = n; i >= 1; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            solution.push_back(pallets[i - 1]);
            w -= pallets[i - 1].weight;
        }
    }

    // Compute total weight
    int totalWeight = 0;
    for (auto& p : solution) {
        totalWeight += p.weight;
    }

    // Output the result
    cout << "[Dynamic Programming Algorithm]\n";
    cout << "Total Profit: " << dp[n][W] << "\n";
    cout << "Total Weight: " << totalWeight << "\n";
    cout << "Selected Pallets: ";
    for (auto& p : solution)    {
        cout << p.id << " ";
    }
    cout << "\n\n";
}
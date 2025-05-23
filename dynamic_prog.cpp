/**
 * @file dynamic_prog.cpp
 * @brief Implementação do algoritmo de programação dinâmica para resolver o problema da mochila.
 *
 * Este arquivo contém a implementação do algoritmo de programação dinâmica para resolver o problema da mochila,
 * que é uma variação do Problema da Mochila 0/1. O algoritmo utiliza uma abordagem bottom-up para construir uma tabela
 * onde dp[i][w] representa o lucro máximo que pode ser obtido com os primeiros i paletes e uma capacidade de peso w.
 *
 * @note Complexidade de Tempo: O(n * W), onde n é o número de paletes e W é a capacidade do caminhão.
 *       Isso ocorre porque o algoritmo preenche uma tabela de dimensões (n+1) x (W+1).
 * @note Complexidade de Espaço: O(n * W), devido à tabela dp de dimensões (n+1) x (W+1).
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include "pallet.h"

using namespace std;

/**
 * @brief Solves the 0/1 Knapsack Problem using dynamic programming approach
 *
 * This function implements a bottom-up dynamic programming solution to the Delivery
 * Truck Pallet Packing Optimization Problem, which is a variation of the 0/1 Knapsack Problem.
 * The algorithm creates a 2D table where dp[i][w] represents the maximum profit that can be obtained
 * with the first i pallets and a weight capacity of w.
 *
 * For each pallet i and capacity w, the algorithm decides whether to include the pallet in the solution
 * by comparing:
 * 1. The profit from not including the pallet (dp[i-1][w])
 * 2. The profit from including the pallet (dp[i-1][w-wt] + pf)
 *
 * After building the table, the algorithm traces back the selected pallets and outputs
 * the total profit, total weight, and the IDs of the selected pallets.
 *
 * @param data A struct containing problem parameters such as the number of pallets and truck capacity
 * @param pallets A vector of Pallet objects, each with an ID, weight, and profit
 *
 * @note Time Complexity: O(n * W) where n is the number of pallets and W is the truck capacity.
 *       This is because the algorithm fills a table of dimensions (n+1) x (W+1).
 * @note Space Complexity: O(n * W) due to the dp table of dimensions (n+1) x (W+1).
 *
 * @see Pallet
 * @see Data
 */

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
    reverse(solution.begin(), solution.end());
    for (auto& p : solution)    {
        cout << p.id << " ";
    }
    cout << "\n\n";
}

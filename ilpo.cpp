#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

void solve_knapsack_ILP(int capacity, const std::vector<int>& weights, const std::vector<int>& profits) {
    std::ofstream fout("input.txt");
    int n = weights.size();
    fout << capacity << "\n" << n << "\n";
    for (int i = 0; i < n; ++i) {
        fout << weights[i] << " " << profits[i] << "\n";
    }
    fout.close();

    system("python3 knapsack_solver.py input.txt output.txt");

    std::ifstream fin("output.txt");
    if (!fin.is_open()) {
        std::cerr << "Failed to open output.txt\n";
        return;
    }

    int totalProfit, count;
    fin >> totalProfit >> count;
    std::vector<int> selected(count);
    for (int i = 0; i < count; ++i) {
        fin >> selected[i];
    }
    fin.close();

    int totalWeight = 0;
    for (int idx : selected) {
        totalWeight += weights[idx];
    }

    std::cout << "Total profit: " << totalProfit << "\n";
    std::cout << "Total weight: " << totalWeight << "\n";
    std::cout << "Selected pallets:";
    for (int idx : selected) {
        std::cout << " " << idx;
    }
    std::cout << "\n";
}

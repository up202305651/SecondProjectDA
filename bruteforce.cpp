//
// Created by tomas on 15-04-2025.
//

#include "bruteforce.h"
#include <iostream>
#include <vector>
using namespace std;

void bruteforce(Data& data,vector<Pallet>& pallets) {
    vector<Pallet> solution;
    int n = pallets.size(); //later i will use data.n_pallets
    int maxProfit = 0;
    int bestMask = 0;

    for (int mask = 0; mask < (1 << n); ++mask) {
        int currentWeight = 0;
        int currentProfit = 0;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                currentWeight += pallets[i].weight;
                currentProfit += pallets[i].profit;
            }
        }

        if (currentWeight <= data.capacity && currentProfit > maxProfit) {
            maxProfit = currentProfit;
            bestMask = mask;
        }
    }

    //constrói a melhor solução
    solution.clear();
    for (int i = 0; i < n; ++i) {
        if (bestMask & (1 << i)) {
            solution.push_back(pallets[i]);
        }
    }

    //output
    int totalWeight = 0;
    for (const auto& p : solution)
        totalWeight += p.weight;

    cout << "[Brute Force Algorithm]\n";
    std::cout << "Total Profit: " << maxProfit << "\n";
    std::cout << "Total Weight: " << totalWeight << "\n";
    std::cout << "Selected Pallets: ";
    for (const auto& p : solution)
        std::cout << p.id << " ";
    std::cout << "\n\n";
}

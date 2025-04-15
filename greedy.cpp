//
// Created by tomas on 15-04-2025.
//

#include "greedy.h"

#include <algorithm>
#include <iostream>


bool compare(const Pallet& a, const Pallet& b) {
    double ratioA=static_cast<double>(a.profit)/a.weight;
    double ratioB=static_cast<double>(b.profit)/b.weight;
    return ratioA>ratioB;
}

void greedy(Data& data, std::vector<Pallet>& pallets) {
    // Sort using the comparison function
    std::sort(pallets.begin(), pallets.end(), compare);

    std::vector<Pallet> selected;
    int currentWeight = 0;
    int totalProfit = 0;

    for (const auto& pallet : pallets) {
        if (currentWeight + pallet.weight <= data.capacity) {
            selected.push_back(pallet);
            currentWeight += pallet.weight;
            totalProfit += pallet.profit;
        }
    }

    std::cout << "[Greedy Approximation Algorithm]\n";
    std::cout << "Total Profit: " << totalProfit << "\n";
    std::cout << "Total Weight: " << currentWeight << "\n";
    std::cout << "Selected Pallets: ";
    for (const auto& p : selected)
        std::cout << p.id << " ";
    std::cout << "\n\n";
}

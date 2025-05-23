//
// Created by tomas on 15-04-2025.
//

#include "greedy.h"

#include <algorithm>
#include <iostream>
using namespace std;

bool compare_ratio(const Pallet& a, const Pallet& b) {
    double ratioA=static_cast<double>(a.profit)/a.weight;
    double ratioB=static_cast<double>(b.profit)/b.weight;
    return ratioA>ratioB;
}

void greedy(Data& data, std::vector<Pallet>& pallets) {
    // ordenar pallets por maior profit/weight
    sort(pallets.begin(),pallets.end(),compare_ratio);

    vector<Pallet> pal_sel;
    int current_weight=0;
    int total_profit=0;

    for (const auto& pallet : pallets){
        if (current_weight+pallet.weight<=data.capacity) {
            pal_sel.push_back(pallet);
            current_weight+=pallet.weight;
            total_profit+=pallet.profit;
        }
    }

    cout << "Greedy Approximation Algorithm\n";
    cout << "Lucro total: " << total_profit << "\n";
    cout << "Peso total: " << current_weight << "\n";
    cout << "Pallets selecionados: ";
    for (const auto& p : pal_sel)
        cout << p.id << " ";
    cout << "\n\n";
}

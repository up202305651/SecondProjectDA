//
// Created by tomas on 15-04-2025.
//

#include "bruteforce.h"
#include <iostream>
#include <vector>
using namespace std;

void bruteforce(Data& data,vector<Pallet>& pallets) {
    vector<Pallet> solucao;
    int n=pallets.size(); //mesma coisa que usar a o parametro da data
    int max_profit = 0;
    int best_mask = 0;

    for (int mask=0; mask<(1<<n);++mask){
        int cur_weight=0;
        int cur_profit=0;

        for (int i=0; i<n;++i) {
            if (mask & (1<<i)) {
                cur_weight+=pallets[i].weight;
                cur_profit+=pallets[i].profit;
            }
        }
        if (cur_weight<=data.capacity && cur_profit>max_profit) {
            max_profit=cur_profit;
            best_mask=mask;
        }
    }

    //constrói a melhor solução
    solucao.clear();
    for (int i = 0; i < n; ++i) {
        if (best_mask & (1 << i)) {
            soluç.push_back(pallets[i]);
        }
    }

    //output
    int total_weight = 0;
    for (const auto& p : solucao)
        total_weight += p.weight;

    cout << "Brute Force Algorithm\n";
    cout << "Lucro total: "<<max_profit<<"\n";
    cout << "Peso total: "<<total_weight<<"\n";
    cout << "Pallets selecionados: ";
    for (const auto& p : solucao)
        cout<<p.id<<" ";
    cout << "\n\n";
}

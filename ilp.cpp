#include "ilp.h"
#include "read_write.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void runILP(const Data& data, const vector<Pallet>& pallets) {
    createInputFile(data, pallets);
    system("python \"C:/Users/Dival/Documents/Universidade/2ANO/2_SEM/DA/SecondProject/SecondProjectDA/knapsack_Solver.py\" input.txt output.txt");

    int totalProfit, totalWeight;
    vector<int> selected;
    readOutputFile(totalProfit, totalWeight, selected);

    cout << "[Integer Linear Programming Algorithm]" << endl;
    cout << "Total Profit: " << totalProfit << endl;
    cout << "Total Weight: " << totalWeight << endl;
    cout << "Selected Pallets:";
    for (const int id : selected) {
        cout << " " << (id);
    }
    cout << endl;
}

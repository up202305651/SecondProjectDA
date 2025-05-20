#ifndef ILP_H
#define ILP_H
#include <vector>
#include "pallet.h"

struct ILPSolution {
    std::vector<int> selected;
    int totalProfit;
    int totalWeight;
    int iterations;
};


void ilp(const Data& data, const std::vector<Pallet>& pallets);

#endif

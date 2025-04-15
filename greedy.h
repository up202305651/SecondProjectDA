//
// Created by tomas on 15-04-2025.
//

#ifndef GREEDY_H
#define GREEDY_H

#include "pallet.h"
#include <vector>

using namespace std;

void greedy(Data& data,vector<Pallet>& pallets);
bool compare(const Pallet& a, const Pallet& b);


#endif //GREEDY_H

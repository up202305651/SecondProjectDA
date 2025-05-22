#ifndef READ_WRITE_H
#define READ_WRITE_H

#include <vector>
#include "pallet.h"

void createInputFile(const Data& data, const std::vector<Pallet>& pallets);
void readOutputFile(int& totalProfit, int& totalWeight, std::vector<int>& selected);

#endif // READ_WRITE_H

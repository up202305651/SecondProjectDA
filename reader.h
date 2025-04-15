#ifndef READER_H
#define READER_H
#include "pallet.h"
#include <vector>

void readTruckFile(const std::string& filename, Data& data);
void readPalletsFile(const std::string& filename, std::vector<Pallet>& pallets);




#endif //READER_H

#include <sstream>
#include "reader.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>


void readTruckFile(const std::string& filename, Data& data) {
    std::ifstream file(filename);
    if (!file.is_open())  return;

    std::string line;
    std::getline(file, line);  // skip header

    if (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string capStr, countStr;
        std::getline(ss, capStr, ',');
        std::getline(ss, countStr, ',');
        data.capacity = std::stoi(capStr);
        data.n_pallets = std::stoi(countStr);
    }

    file.close();
}

void readPalletsFile(const std::string& filename, std::vector<Pallet>& pallets) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout<<"Not opening";
        return;
    }

    std::string line;
    std::getline(file, line); // skip header
    pallets.clear();

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string idStr, weightStr, profitStr;

        std::getline(ss, idStr, ',');
        std::getline(ss, weightStr, ',');
        std::getline(ss, profitStr, ',');

        pallets.push_back({std::stoi(idStr), std::stoi(weightStr), std::stoi(profitStr)});
    }

    file.close();
}

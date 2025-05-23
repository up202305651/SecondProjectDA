#include "read_write.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "pallet.h"

using namespace std;

void createInputFile(const Data& data, const vector<Pallet>& pallets) {
    ofstream inputFile("input.txt");
    inputFile << pallets.size() << endl;
    inputFile << data.capacity << endl;
    for (const auto& pallet : pallets) {
        inputFile << pallet.weight << " ";
    }
    inputFile << endl;
    for (const auto& pallet : pallets) {
        inputFile << pallet.profit << " ";
    }
    inputFile << endl;
    inputFile.close();
}

void readOutputFile(int& totalProfit, int& totalWeight, vector<int>& selected) {
    ifstream outputFile("output.txt");
    outputFile >> totalProfit;
    outputFile >> totalWeight;
    string line;
    getline(outputFile, line);
    getline(outputFile, line);
    outputFile.close();

    size_t pos = 0;
    while ((pos = line.find(" ")) != string::npos) {
        int index = stoi(line.substr(0, pos));
        selected.push_back(index);
        line.erase(0, pos + 1);
    }
    if (!line.empty()) {
        int index = stoi(line);
        selected.push_back(index);
    }
}
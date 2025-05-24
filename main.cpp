#include <iostream>
#include <string>

#include "bruteforce.h"
#include "greedy.h"
#include "dynamic_prog.h"
#include "reader.h"
#include "pallet.h"
#include "read_write.h"
#include "ilp.h"

using namespace std;

int main() {
    vector<Pallet> pallets;
    Data data;

    int datasetOption;
    cout << "Choose a dataset (1 to 10):\n";
    cin >> datasetOption;

    if (datasetOption < 1 || datasetOption > 10) {
        cout << "Invalid dataset option. Please run the program again and choose a valid option.\n";
        return 1;
    }

    string palletsFilePath;
    string truckFilePath;

    if (datasetOption >= 1 && datasetOption <= 9) {
        palletsFilePath = "C:/Users/Dival/Documents/Universidade/2ANO/2_SEM/DA/SecondProject/SecondProjectDA/datasets-extra/datasets-extra/Pallets_0" + to_string(datasetOption) + ".csv";
        truckFilePath = "C:/Users/Dival/Documents/Universidade/2ANO/2_SEM/DA/SecondProject/SecondProjectDA/datasets-extra/datasets-extra/TruckAndPallets_0" + to_string(datasetOption) + ".csv";
    } else {
        palletsFilePath = "C:/Users/Dival/Documents/Universidade/2ANO/2_SEM/DA/SecondProject/SecondProjectDA/datasets-extra/datasets-extra/Pallets_" + to_string(datasetOption) + ".csv";
        truckFilePath = "C:/Users/Dival/Documents/Universidade/2ANO/2_SEM/DA/SecondProject/SecondProjectDA/datasets-extra/datasets-extra/TruckAndPallets_" + to_string(datasetOption) + ".csv";
    }

    if (!readPalletsFile(palletsFilePath, pallets)) {
        cerr << "Error reading pallets file: " << palletsFilePath << endl;
        return 1;
    }

    if (!readTruckFile(truckFilePath, data)) {
        cerr << "Error reading truck file: " << truckFilePath << endl;
        return 1; // Adiciona o valor de retorno
    }

    int option;
    cout << "Choose an algorithm:\n";
    cout << "1 - Brute Force\n";
    cout << "2 - Dynamic Programming\n";
    cout << "3 - Greedy Approach\n";
    cout << "4 - Integer Linear Programming\n";
    cout << "Enter your choice: ";
    cin >> option;

    // Executa o algoritmo escolhido pelo usuário
    switch (option) {
        case 1: {
            bruteforce(data, pallets);
            break;
        }
        case 2: {
            dynamicProgramming(data, pallets);
            break;
        }
        case 3: {
            greedy(data, pallets);
            break;
        }
        case 4: {
            createInputFile(data, pallets);

            runILP();
            int totalProfit, totalWeight;
            vector<int> selected;
            readOutputFile(totalProfit, totalWeight, selected);

            cout << "[Integer Linear Programming Algorithm]" << endl;
            cout << "Total Profit: " << totalProfit << endl;
            cout << "Total Weight: " << totalWeight << endl;
            cout << "Selected Pallets:";
            for (const int index : selected) {
                cout << " " << index + 1;
            }
            cout << endl;
            break;
        }
        default:
            cout << "Invalid option. Please run the program again and choose a valid option.\n";
    }

    return 0;
}

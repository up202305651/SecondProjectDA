#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include "bruteforce.h"
#include "greedy.h"
#include "dynamic_prog.h"
#include "reader.h"
#include "pallet.h"
#include "read_write.h"
#include "ilp.h"

using namespace std;
using namespace std::chrono;

int main() {
    struct DatasetInfo {
        int datasetOption;
        size_t palletCount;
    };

    vector<DatasetInfo> datasets;

    // Primeiro passo: descobrir o tamanho de pallets de cada dataset
    for (int datasetOption = 1; datasetOption <= 10; ++datasetOption) {
        vector<Pallet> pallets;
        Data data;

        string palletsFilePath;
        if (datasetOption <= 9)
            palletsFilePath ="C:/Users/Dival/Documents/Universidade/2ANO/2_SEM/DA/SecondProject/SecondProjectDA/datasets-extra/datasets-extra/Pallets_0" + to_string(datasetOption) + ".csv";
        else
            palletsFilePath = "C:/Users/Dival/Documents/Universidade/2ANO/2_SEM/DA/SecondProject/SecondProjectDA/datasets-extra/datasets-extra/Pallets_" + to_string(datasetOption) + ".csv";

        ifstream palletsFile(palletsFilePath);
        if (!palletsFile.is_open()) continue;
        palletsFile.close();

        readPalletsFile(palletsFilePath, pallets);
        datasets.push_back({datasetOption, pallets.size()});
    }

    // Ordenar os datasets pelo tamanho de pallets (do menor para o maior)
    sort(datasets.begin(), datasets.end(), [](const DatasetInfo& a, const DatasetInfo& b) {
        return a.palletCount < b.palletCount;
    });

    // Agora executa os testes na ordem ordenada
    vector<vector<long long>> bruteForceTimes, dynamicProgrammingTimes, greedyTimes, ilpTimes;

    for (const auto& info : datasets) {
        int datasetOption = info.datasetOption;
        vector<Pallet> pallets;
        Data data;

        string palletsFilePath, truckFilePath;
        if (datasetOption <= 9) {
            palletsFilePath = "C:/Users/Dival/Documents/Universidade/2ANO/2_SEM/DA/SecondProject/SecondProjectDA/datasets-extra/datasets-extra/Pallets_0" + to_string(datasetOption) + ".csv";
            truckFilePath   = "C:/Users/Dival/Documents/Universidade/2ANO/2_SEM/DA/SecondProject/SecondProjectDA/datasets-extra/datasets-extra/TruckAndPallets_0" + to_string(datasetOption) + ".csv";
        } else {
            palletsFilePath = "C:/Users/Dival/Documents/Universidade/2ANO/2_SEM/DA/SecondProject/SecondProjectDA/datasets-extra/datasets-extra/Pallets_" + to_string(datasetOption) + ".csv";
            truckFilePath   = "C:/Users/Dival/Documents/Universidade/2ANO/2_SEM/DA/SecondProject/SecondProjectDA/datasets-extra/datasets-extra/TruckAndPallets_" + to_string(datasetOption) + ".csv";
        }

        ifstream palletsFile(palletsFilePath), truckFile(truckFilePath);
        if (!palletsFile.is_open() || !truckFile.is_open()) {
            cerr << "Error: Could not open files for dataset " << datasetOption << endl;
            continue;
        }
        palletsFile.close();
        truckFile.close();

        readPalletsFile(palletsFilePath, pallets);
        readTruckFile(truckFilePath, data);

        cout << "Dataset: " << datasetOption << " (Pallets: " << pallets.size() << ")" << endl;

        auto start = high_resolution_clock::now();
        std::chrono::high_resolution_clock::time_point stop;
        int temp = bruteforce_benchmark(data, pallets);
        if ( temp == -1) {
            bruteForceTimes.push_back({datasetOption, 0});
        }
        else {
            stop = high_resolution_clock::now();
            bruteForceTimes.push_back({datasetOption, duration_cast<microseconds>(stop - start).count()});
        }

        start = high_resolution_clock::now();
        dynamicProgramming_benchmark(data, pallets);
        stop = high_resolution_clock::now();
        dynamicProgrammingTimes.push_back({datasetOption, duration_cast<microseconds>(stop - start).count()});

        start = high_resolution_clock::now();
        greedy_benchmark(data, pallets);
        stop = high_resolution_clock::now();
        greedyTimes.push_back({datasetOption, duration_cast<microseconds>(stop - start).count()});

        createInputFile(data, pallets);
        start = high_resolution_clock::now();
        runILP();
        stop = high_resolution_clock::now();
        ilpTimes.push_back({datasetOption, duration_cast<microseconds>(stop - start).count()});
        cout << "\n----------------------------------------" << endl;
    }

    cout << "\nAll Execution Times:\n";

    cout << "Brute Force Times:\n";
    for (const auto& time : bruteForceTimes) {
        auto it = find_if(datasets.begin(), datasets.end(), [&](const DatasetInfo& d) {
            return d.datasetOption == time[0];
        });
        cout << "Dataset " << time[0] << " (Pallets: " << it->palletCount << "): " << time[1] << " microseconds\n";
    }

    cout << "\nDynamic Programming Times:\n";
    for (const auto& time : dynamicProgrammingTimes) {
        auto it = find_if(datasets.begin(), datasets.end(), [&](const DatasetInfo& d) {
            return d.datasetOption == time[0];
        });
        cout << "Dataset " << time[0] << " (Pallets: " << it->palletCount << "): " << time[1] << " microseconds\n";
    }

    cout << "\nGreedy Algorithm Times:\n";
    for (const auto& time : greedyTimes) {
        auto it = find_if(datasets.begin(), datasets.end(), [&](const DatasetInfo& d) {
            return d.datasetOption == time[0];
        });
        cout << "Dataset " << time[0] << " (Pallets: " << it->palletCount << "): " << time[1] << " microseconds\n";
    }

    cout << "\nInteger Linear Programming Times:\n";
    for (const auto& time : ilpTimes) {
        auto it = find_if(datasets.begin(), datasets.end(), [&](const DatasetInfo& d) {
            return d.datasetOption == time[0];
        });
        cout << "Dataset " << time[0] << " (Pallets: " << it->palletCount << "): " << time[1] << " microseconds\n";
    }

    return 0;
}

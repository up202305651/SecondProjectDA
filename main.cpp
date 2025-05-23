/**
 * @file main.cpp
 * @brief Função principal do programa para resolver o problema da mochila.
 *
 * Este arquivo contém a função principal que lê os dados dos paletes e do caminhão, exibe as informações lidas
 * e permite ao usuário escolher um algoritmo para resolver o problema da mochila. O programa oferece
 * quatro opções de algoritmos: Força Bruta, Programação Dinâmica, Abordagem Gulosa e Programação Linear Inteira.
 *
 * @note Complexidade de Tempo: Depende do algoritmo escolhido pelo usuário.
 * @note Complexidade de Espaço: Depende do algoritmo escolhido pelo usuário.
 */

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

/**
 * @brief Função principal do programa.
 *
 * Esta função lê os dados dos paletes e do caminhão, exibe as informações lidas e permite ao usuário escolher
 * um algoritmo para resolver o problema da mochila.
 *
 * @return int Retorna 0 em caso de execução bem-sucedida.
 */
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

    string palletsFilePath = "C:/Users/Dival/Documents/Universidade/2ANO/2_SEM/DA/SecondProject/SecondProjectDA/datasets-extra/datasets-extra/Pallets_0" + to_string(datasetOption) + ".csv";
    string truckFilePath = "C:/Users/Dival/Documents/Universidade/2ANO/2_SEM/DA/SecondProject/SecondProjectDA/datasets-extra/datasets-extra/TruckAndPallets_0" + to_string(datasetOption) + ".csv";

    // Lê os dados dos paletes de um arquivo CSV
    readPalletsFile(palletsFilePath, pallets);

    // Lê os dados do caminhão de um arquivo CSV
    readTruckFile(truckFilePath, data);

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
            runILP(data, pallets);
            break;
        }
        default:
            cout << "Invalid option. Please run the program again and choose a valid option.\n";
    }

    return 0;
}

/**
 * @file ilp.cpp
 * @brief Implementação do algoritmo de Programação Linear Inteira para resolver o problema da mochila.
 *
 * Este arquivo contém a implementação da função que executa o algoritmo de Programação Linear Inteira
 * para resolver o problema da mochila. O algoritmo utiliza um solver externo (em Python) para resolver
 * o problema de otimização linear inteira.
 *
 * @note Complexidade de Tempo: Depende do solver de Programação Linear Inteira utilizado. Geralmente,
 *       solvers de ILP têm complexidade exponencial no pior caso, mas são eficientes na prática para
 *       problemas de tamanho moderado.
 * @note Complexidade de Espaço: Depende do solver de Programação Linear Inteira utilizado. O espaço
 *       adicional é usado principalmente para armazenar os dados de entrada e saída.
 */

#include "ilp.h"
#include <iostream>
#include <cstdlib>
#include "read_write.h"

using namespace std;

/**
 * @brief Executa o algoritmo de Programação Linear Inteira para resolver o problema da mochila.
 *
 * Esta função cria um arquivo de entrada, executa um script Python para resolver o problema da mochila usando
 * Programação Linear Inteira e lê os resultados do arquivo de saída. O solver de ILP é chamado externamente
 * e resolve o problema de otimização.
 *
 * @param data Referência para a estrutura Data contendo a capacidade e o número de paletes.
 * @param pallets Referência para o vetor de Pallet contendo os dados dos paletes.
 *
 * @note Complexidade de Tempo: Depende do solver de Programação Linear Inteira utilizado. Geralmente,
 *       solvers de ILP têm complexidade exponencial no pior caso, mas são eficientes na prática para
 *       problemas de tamanho moderado.
 * @note Complexidade de Espaço: Depende do solver de Programação Linear Inteira utilizado. O espaço
 *       adicional é usado principalmente para armazenar os dados de entrada e saída.
 */
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
    for (const int index : selected) {
        cout << " " << index + 1; // Increment index by 1 to start from 1
    }
    cout << endl;
}

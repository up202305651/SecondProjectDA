/**
 * @file read_write.cpp
 * @brief Implementação das funções para criação e leitura de arquivos de entrada e saída.
 *
 * Este arquivo contém a implementação das funções que criam arquivos de entrada com os dados dos paletes
 * e lêem os resultados de arquivos de saída. Essas funções são essenciais para a interação com o solver de
 * Programação Linear Inteira, permitindo a comunicação entre o programa C++ e o script Python.
 *
 * @note Complexidade de Tempo: O(n), onde n é o número de paletes, para a função createInputFile.
 * @note Complexidade de Espaço: O(n), onde n é o número de paletes, para a função createInputFile.
 */

#include "read_write.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "pallet.h"

using namespace std;

/**
 * @brief Cria um arquivo de entrada com os dados fornecidos.
 *
 * Esta função cria um arquivo de entrada com os dados dos paletes e a capacidade do caminhão.
 *
 * @param data Referência para a estrutura Data contendo a capacidade e o número de paletes.
 * @param pallets Referência para o vetor de Pallet contendo os dados dos paletes.
 *
 * @note Complexidade de Tempo: O(n), onde n é o número de paletes.
 * @note Complexidade de Espaço: O(n), onde n é o número de paletes.
 */
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

/**
 * @brief Lê os resultados de um arquivo de saída.
 *
 * Esta função lê o arquivo de saída e extrai o lucro total, o peso total e os índices dos paletes selecionados.
 *
 * @param totalProfit Referência para o inteiro onde o lucro total será armazenado.
 * @param totalWeight Referência para o inteiro onde o peso total será armazenado.
 * @param selected Referência para o vetor de inteiros onde os índices dos paletes selecionados serão armazenados.
 *
 * @note Complexidade de Tempo: O(m), onde m é o número de paletes selecionados.
 * @note Complexidade de Espaço: O(m), onde m é o número de paletes selecionados.
 */
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

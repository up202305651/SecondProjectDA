/**
 * @file reader.cpp
 * @brief Implementação das funções para leitura de arquivos.
 *
 * Este arquivo contém a implementação das funções que lêem os dados dos paletes e do caminhão
 * a partir de arquivos CSV. Essas funções são responsáveis por carregar os dados necessários para
 * resolver o problema da mochila.
 *
 * @note Complexidade de Tempo: O(n), onde n é o número de linhas no arquivo de paletes.
 * @note Complexidade de Espaço: O(n), onde n é o número de paletes.
 */

#include <sstream>
#include "reader.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Lê os dados do caminhão de um arquivo.
 *
 * Esta função lê o arquivo especificado e extrai a capacidade e o número de paletes.
 *
 * @param filename Nome do arquivo a ser lido.
 * @param data Referência para a estrutura Data onde os dados serão armazenados.
 *
 * @note Complexidade de Tempo: O(1), pois lê apenas duas linhas do arquivo.
 * @note Complexidade de Espaço: O(1), pois armazena apenas dois valores.
 */
bool readTruckFile(const std::string& filename, Data& data) {
    std::ifstream file(filename);
    if (!file.is_open())  return false;

    std::string line;
    std::getline(file, line);

    if (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string capStr, countStr;
        std::getline(ss, capStr, ',');
        std::getline(ss, countStr, ',');
        data.capacity = std::stoi(capStr);
        data.n_pallets = std::stoi(countStr);
    }

    file.close();
    return true;
}

/**
 * @brief Lê os dados dos paletes de um arquivo.
 *
 * Esta função lê o arquivo especificado e extrai os dados dos paletes.
 *
 * @param filename Nome do arquivo a ser lido.
 * @param pallets Referência para o vetor de Pallet onde os dados serão armazenados.
 *
 * @note Complexidade de Tempo: O(n), onde n é o número de linhas no arquivo de paletes.
 * @note Complexidade de Espaço: O(n), onde n é o número de paletes.
 */
bool readPalletsFile(const std::string &filename, std::vector<Pallet> &pallets) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout<<"Not opening";
        return false;
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
    return true;
}

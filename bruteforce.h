//
// Created by tomas on 15-04-2025.
//

#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include <vector>
#include "pallet.h"

using namespace std;

/**
 * @brief Executa o algoritmo de força bruta para resolver o problema da mochila.
 *
 * Esta função avalia todas as combinações possíveis de paletes para encontrar a combinação
 * que maximiza o lucro sem exceder a capacidade do caminhão.
 *
 * @param data Referência para a estrutura Data contendo a capacidade e o número de paletes.
 * @param pallets Referência para o vetor de Pallet contendo os dados dos paletes.
 */
void bruteforce(Data& data, vector<Pallet>& pallets);

int bruteforce_benchmark(Data& data, vector<Pallet>& pallets);
#endif //BRUTEFORCE_H

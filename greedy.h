//
// Created by tomas on 15-04-2025.
//

#ifndef GREEDY_H
#define GREEDY_H

#include "pallet.h"
#include <vector>

using namespace std;

/**
 * @brief Executa o algoritmo guloso para resolver o problema da mochila.
 *
 * Esta função ordena os paletes pela razão lucro/peso e seleciona os paletes com a maior razão
 * até que a capacidade do caminhão seja atingida.
 *
 * @param data Referência para a estrutura Data contendo a capacidade e o número de paletes.
 * @param pallets Referência para o vetor de Pallet contendo os dados dos paletes.
 */
void greedy(Data& data, vector<Pallet>& pallets);

int greedy_benchmark(Data& data, vector<Pallet>& pallets);
/**
 * @brief Compara dois paletes com base na razão lucro/peso.
 *
 * Esta função é usada para ordenar os paletes pela razão lucro/peso.
 *
 * @param a Primeiro pallet.
 * @param b Segundo pallet.
 * @return true se a razão lucro/peso do primeiro pallet for maior que a do segundo.
 */
bool compare_ratio(const Pallet& a, const Pallet& b);

#endif //GREEDY_H

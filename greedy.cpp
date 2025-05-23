/**
 * @file greedy.cpp
 * @brief Implementação do algoritmo guloso para resolver o problema da mochila.
 *
 * Este arquivo contém a implementação do algoritmo guloso para resolver o problema da mochila,
 * ordenando os paletes pela razão lucro/peso. O algoritmo guloso é uma abordagem heurística que
 * seleciona localmente a melhor opção em cada etapa, com a esperança de encontrar uma solução globalmente ótima.
 *
 * @note Complexidade de Tempo: O(n log n), devido à ordenação dos paletes pela razão lucro/peso.
 *       A ordenação é feita uma vez, e depois o algoritmo itera sobre os paletes uma vez.
 * @note Complexidade de Espaço: O(n), onde n é o número de paletes. O espaço adicional é usado
 *       principalmente para armazenar a solução atual.
 */

#include "greedy.h"

#include <algorithm>
#include <iostream>
using namespace std;

/**
 * @brief Compara dois paletes com base na razão lucro/peso.
 *
 * Esta função é usada para ordenar os paletes pela razão lucro/peso.
 *
 * @param a Primeiro pallet.
 * @param b Segundo pallet.
 * @return true se a razão lucro/peso do primeiro pallet for maior que a do segundo.
 */
bool compare_ratio(const Pallet& a, const Pallet& b) {
    double ratioA = static_cast<double>(a.profit) / a.weight;
    double ratioB = static_cast<double>(b.profit) / b.weight;
    return ratioA > ratioB;
}

/**
 * @brief Executa o algoritmo guloso para resolver o problema da mochila.
 *
 * Esta função ordena os paletes pela razão lucro/peso e seleciona os paletes com a maior razão
 * até que a capacidade do caminhão seja atingida. O algoritmo guloso não garante a solução ótima,
 * mas é eficiente em termos de tempo.
 *
 * @param data Referência para a estrutura Data contendo a capacidade e o número de paletes.
 * @param pallets Referência para o vetor de Pallet contendo os dados dos paletes.
 *
 * @note Complexidade de Tempo: O(n log n), devido à ordenação dos paletes pela razão lucro/peso.
 *       A ordenação é feita uma vez, e depois o algoritmo itera sobre os paletes uma vez.
 * @note Complexidade de Espaço: O(n), onde n é o número de paletes. O espaço adicional é usado
 *       principalmente para armazenar a solução atual.
 */
void greedy(Data& data, std::vector<Pallet>& pallets) {
    // ordenar pallets por maior profit/weight
    sort(pallets.begin(), pallets.end(), compare_ratio);

    vector<Pallet> pal_sel;
    int current_weight = 0;
    int total_profit = 0;

    for (const auto& pallet : pallets) {
        if (current_weight + pallet.weight <= data.capacity) {
            pal_sel.push_back(pallet);
            current_weight += pallet.weight;
            total_profit += pallet.profit;
        }
    }

    cout << "Greedy Approximation Algorithm\n";
    cout << "Lucro total: " << total_profit << "\n";
    cout << "Peso total: " << current_weight << "\n";
    cout << "Pallets selecionados: ";
    for (const auto& p : pal_sel)
        cout << p.id << " ";
    cout << "\n\n";
}

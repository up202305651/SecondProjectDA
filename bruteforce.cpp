/**
 * @file bruteforce.cpp
 * @brief Implementação do algoritmo de força bruta para resolver o problema da mochila.
 *
 * Este arquivo contém a implementação do algoritmo de força bruta para resolver o problema da mochila,
 * avaliando todas as combinações possíveis de paletes. O algoritmo de força bruta é uma abordagem exaustiva
 * que verifica todas as combinações possíveis de itens para encontrar a solução ótima.
 *
 * @note Complexidade de Tempo: O(2^n), onde n é o número de paletes. Isso ocorre porque o algoritmo
 *       precisa verificar todas as combinações possíveis de paletes, que é 2^n para n itens.
 * @note Complexidade de Espaço: O(n), onde n é o número de paletes. O espaço adicional é usado
 *       principalmente para armazenar a solução atual e a melhor solução encontrada.
 */

#include "bruteforce.h"
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Executa o algoritmo de força bruta para resolver o problema da mochila.
 *
 * Esta função avalia todas as combinações possíveis de paletes para encontrar a combinação
 * que maximiza o lucro sem exceder a capacidade do caminhão. O algoritmo utiliza uma máscara de bits
 * para representar cada combinação possível de paletes.
 *
 * @param data Referência para a estrutura Data contendo a capacidade e o número de paletes.
 * @param pallets Referência para o vetor de Pallet contendo os dados dos paletes.
 *
 * @note Complexidade de Tempo: O(2^n), onde n é o número de paletes. Isso ocorre porque o algoritmo
 *       precisa verificar todas as combinações possíveis de paletes, que é 2^n para n itens.
 * @note Complexidade de Espaço: O(n), onde n é o número de paletes. O espaço adicional é usado
 *       principalmente para armazenar a solução atual e a melhor solução encontrada.
 */
void bruteforce(Data& data, vector<Pallet>& pallets) {
    vector<Pallet> solucao;
    int n = pallets.size(); // mesma coisa que usar o parâmetro da data
    int max_profit = 0;
    int best_mask = 0;

    for (int mask = 0; mask < (1 << n); ++mask) {
        int cur_weight = 0;
        int cur_profit = 0;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                cur_weight += pallets[i].weight;
                cur_profit += pallets[i].profit;
            }
        }
        if (cur_weight <= data.capacity && cur_profit > max_profit) {
            max_profit = cur_profit;
            best_mask = mask;
        }
    }

    // constrói a melhor solução
    solucao.clear();
    for (int i = 0; i < n; ++i) {
        if (best_mask & (1 << i)) {
            solucao.push_back(pallets[i]);
        }
    }

    // output
    int total_weight = 0;
    for (const auto& p : solucao)
        total_weight += p.weight;

    cout << "Brute Force Algorithm\n";
    cout << "Lucro total: " << max_profit << "\n";
    cout << "Peso total: " << total_weight << "\n";
    cout << "Pallets selecionados: ";
    for (const auto& p : solucao)
        cout << p.id << " ";
    cout << "\n\n";
}

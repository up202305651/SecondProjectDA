#ifndef ILP_H
#define ILP_H

#include <vector>
#include "pallet.h"

/**
 * @brief Executa o algoritmo de Programação Linear Inteira para resolver o problema da mochila.
 *
 * Esta função cria um arquivo de entrada, executa um script Python para resolver o problema da mochila usando
 * Programação Linear Inteira e lê os resultados do arquivo de saída.
 *
 * @param data Referência para a estrutura Data contendo a capacidade e o número de paletes.
 * @param pallets Referência para o vetor de Pallet contendo os dados dos paletes.
 */
void runILP();

#endif // ILP_H

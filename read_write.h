#ifndef READ_WRITE_H
#define READ_WRITE_H

#include <vector>
#include "pallet.h"

/**
 * @brief Cria um arquivo de entrada com os dados fornecidos.
 *
 * Esta função cria um arquivo de entrada com os dados dos paletes e a capacidade do caminhão.
 *
 * @param data Referência para a estrutura Data contendo a capacidade e o número de paletes.
 * @param pallets Referência para o vetor de Pallet contendo os dados dos paletes.
 */
void createInputFile(const Data& data, const std::vector<Pallet>& pallets);

/**
 * @brief Lê os resultados de um arquivo de saída.
 *
 * Esta função lê o arquivo de saída e extrai o lucro total, o peso total e os índices dos paletes selecionados.
 *
 * @param totalProfit Referência para o inteiro onde o lucro total será armazenado.
 * @param totalWeight Referência para o inteiro onde o peso total será armazenado.
 * @param selected Referência para o vetor de inteiros onde os índices dos paletes selecionados serão armazenados.
 */
void readOutputFile(int& totalProfit, int& totalWeight, std::vector<int>& selected);

#endif // READ_WRITE_H

#ifndef READER_H
#define READER_H
#include "pallet.h"
#include <vector>

/**
 * @brief Lê os dados do caminhão de um arquivo.
 *
 * Esta função lê o arquivo especificado e extrai a capacidade e o número de paletes.
 *
 * @param filename Nome do arquivo a ser lido.
 * @param data Referência para a estrutura Data onde os dados serão armazenados.
 */
bool readTruckFile(const std::string& filename, Data& data);

/**
 * @brief Lê os dados dos paletes de um arquivo.
 *
 * Esta função lê o arquivo especificado e extrai os dados dos paletes.
 *
 * @param filename Nome do arquivo a ser lido.
 * @param pallets Referência para o vetor de Pallet onde os dados serão armazenados.
 */
bool readPalletsFile(const std::string& filename, std::vector<Pallet>& pallets);

#endif //READER_H

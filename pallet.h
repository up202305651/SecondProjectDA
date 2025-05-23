#ifndef PALLET_H
#define PALLET_H

/**
 * @brief Estrutura que representa um Pallet.
 *
 * Esta estrutura contém informações sobre um pallet, incluindo um identificador único,
 * o peso do pallet e o lucro associado ao pallet. É utilizada para armazenar e manipular
 * dados de pallets no contexto do problema da mochila.
 *
 * @note Cada instância de Pallet representa um item que pode ser incluído ou não na solução
 *       do problema da mochila, dependendo de sua contribuição para o lucro total e seu peso.
 * @note A escolha de usar uma estrutura simples para representar os pallets permite uma manipulação
 *       eficiente e direta dos dados, facilitando a implementação dos algoritmos.
 */
struct Pallet {
    int id;     /**< ID do pallet. Identificador único para cada pallet. */
    int weight; /**< Peso do pallet. Representa o peso do pallet, que é um fator limitante na capacidade do caminhão. */
    int profit; /**< Lucro do pallet. Representa o lucro obtido ao incluir o pallet na solução. */
};

/**
 * @brief Estrutura que representa os dados do caminhão.
 *
 * Esta estrutura contém informações sobre o caminhão, incluindo sua capacidade máxima
 * e o número total de paletes disponíveis. É utilizada para definir os parâmetros do problema
 * da mochila e limitar as soluções possíveis.
 *
 * @note A capacidade do caminhão é um fator crucial que limita o peso total dos paletes
 *       que podem ser incluídos na solução. O número de paletes é usado para dimensionar
 *       as estruturas de dados e loops necessários para resolver o problema.
 * @note A utilização de uma estrutura para representar os dados do caminhão permite uma
 *       gestão centralizada dos parâmetros do problema, facilitando a passagem de informações
 *       entre as diferentes funções e algoritmos.
 */
struct Data {
    int capacity;  /**< Capacidade do caminhão. Representa o peso máximo que o caminhão pode transportar. */
    int n_pallets; /**< Número de paletes. Representa o número total de paletes disponíveis para seleção. */
};

#endif // PALLET_H

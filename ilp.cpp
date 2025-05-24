/**
 * @file ilp.cpp
 * @brief Implementação do algoritmo de Programação Linear Inteira para resolver o problema da mochila.
 *
 * Este arquivo contém a implementação da função que executa o algoritmo de Programação Linear Inteira
 * para resolver o problema da mochila. O algoritmo utiliza um solver externo (em Python) para resolver
 * o problema de otimização linear inteira.
 *
 * @note Complexidade de Tempo: Depende do solver de Programação Linear Inteira utilizado. Geralmente,
 *       solvers de ILP têm complexidade exponencial no pior caso, mas são eficientes na prática para
 *       problemas de tamanho moderado.
 * @note Complexidade de Espaço: Depende do solver de Programação Linear Inteira utilizado. O espaço
 *       adicional é usado principalmente para armazenar os dados de entrada e saída.
 */

#include "ilp.h"
#include <iostream>
#include <cstdlib>
#include "read_write.h"

using namespace std;

/**
 * @brief Executa o solver de Programação Linear Inteira para resolver o problema da mochila.
 *
 * Esta função executa um script Python para resolver o problema da mochila usando
 * Programação Linear Inteira.
 *
 * @note Complexidade de Tempo: Depende do solver de Programação Linear Inteira utilizado.
 * @note Complexidade de Espaço: Depende do solver de Programação Linear Inteira utilizado.
 */
void runILP() {
    system("python \"C:/Users/Dival/Documents/Universidade/2ANO/2_SEM/DA/SecondProject/SecondProjectDA/knapsack_Solver.py\" input.txt output.txt");
}
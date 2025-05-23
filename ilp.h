#ifndef ILP_H
#define ILP_H

#include <vector>
<<<<<<< HEAD
#include <chrono>
#include "pallet.h"

/*
 * @brief Solves de 0/1 Knapsack problem using Integer Linear Programming (ILP) with GLPK.
 *
 * This function formulates the 0/1 Knapsack problem as an ILP problem
 * and solves it using the GNU Linear Programming Kit (GLPK) solver. The mathematical formulation is:
 *
 * Maximize: sum(profit_i * x_i) for i = 1 to n
 * Subject to: sum(weight_i * x_i) <= capacity for i = 1 to n
 *              x_i in {0, 1} for i = 1 to n
 * Where x_i is a binary variable indicating weather pallet i is included (1) or not (0) in the knapsack.
 *
 * @param data The truck data containing capacity and number of pallets.
 * @param pallets Vector of pallets, each with an ID, weight and profit.
 * @return void (Results are printed to console)
 *
 * Time complexity: Solving ILP is NP-hard in general case. While specific time complexity
 *              depends on the solver's implementation and the problem instance, it can be
 *              exponential in the worst case.
 * Space complexity: O(n) where n is the number of pallets (for the decision variables).
 */

void integerLinearProgramming(const Data& data, const std::vector<Pallet>& pallets);

#endif //ILP_H
=======
#include "pallet.h"

void runILP(const Data& data, const std::vector<Pallet>& pallets);

#endif // ILP_H
>>>>>>> ILP

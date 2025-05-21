//
// Created by bia on 5/11/25.
//

#ifndef DYNAMIC_PROG_H
#define DYNAMIC_PROG_H

#include <vector>
#include "pallet.h"

/**
 * @brief Solves the 0/1 Knapsack Problem using dynamic programming approach
 *
 * This function implements a bottom-up dynamic programming solution to the Delivery
 * Truck Pallet Packing Optimization Problem. It computes the maximum achievable profit
 * while respecting the truck's weight capacity constraint.
 *
 * @param data A struct containing problem parameters such as the number of pallets and truck capacity
 * @param pallets A vector of Pallet objects, each with an ID, weight, and profit
 *
 * @note Time Complexity: O(n * W) where n is the number of pallets and W is the truck capacity
 * @note Space Complexity: O(n * W) for the dynamic programming table
 *
 * @see Pallet
 * @see Data
 */

void dynamicProgramming(Data& data, std::vector<Pallet>& pallets);

#endif //DYNAMIC_PROG_H

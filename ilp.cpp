#include <vector>
#include <algorithm>
#include <iostream>
#include "pallet.h"
#include "ilp.h"

using namespace std;
class KnapsackILP {
private:
    struct Node {
        int level;
        int profit;
        int weight;
        double bound;
        vector<bool> selections;
    };
    static double calculateBound(Node node, int capacity,
        const vector<Pallet>& items,
        const vector<int>& sortedIndices) {
        if (node.weight >= capacity) {
            return 0;
        }
        double bound = node.profit;
        int j = node.level;
        int totalWeight = node.weight;

        while (j < items.size() && totalWeight + items[sortedIndices[j]].weight <= capacity) {
            totalWeight += items[sortedIndices[j]].weight;
            bound += items[sortedIndices[j]].profit;
            j++;
        }

        if (j < items.size() && totalWeight < capacity) {
            bound += (capacity - totalWeight) *
                      ((double)items[sortedIndices[j]].profit / items[sortedIndices[j]].weight);
        }
        return bound;
    }

public:
    static ILPSolution solve(const Data& data, const vector<Pallet>& pallets) {
        int n = pallets.size();
        ILPSolution solution = {vector<int>(), 0, 0, 0};

        if (n == 0) {
            return solution;
        }
        vector<pair<double, int>> ratios(n);
        for (int i = 0; i < n; i++) {
            ratios[i] = {static_cast<double>(pallets[i].profit) / pallets[i].weight, i};
        }
        sort(ratios.begin(), ratios.end(), greater<pair<double, int>>());

        vector<int> sortedIndices(n);
        for (int i = 0; i < n; i++) {
            sortedIndices[i] = ratios[i].second;
        }
        vector<Node> queue;
        Node root = {0, 0, 0, 0, vector<bool>(n, false)};
        root.bound = calculateBound(root, data.capacity, pallets, sortedIndices);
        queue.push_back(root);

        int maxProfit = 0;
        vector<bool> bestSolution(n, false);
        int iterations = 0;

        while (!queue.empty()) {
            iterations++;
            Node node = queue.back();
            queue.pop_back();

            if (node.level == n) {
                if (node.profit > maxProfit) {
                    maxProfit = node.profit;
                    bestSolution = node.selections;
                }
                continue;
            }
            if (node.bound <= maxProfit) {
                continue;
            }

            int itemIndex = sortedIndices[node.level];

            if (node.weight + pallets[itemIndex].weight <= data.capacity) {
                Node leftChild = node;
                leftChild.level = node.level + 1;
                leftChild.profit = node.profit + pallets[itemIndex].profit;
                leftChild.weight = node.weight + pallets[itemIndex].weight;
                leftChild.selections[itemIndex] = true;
                leftChild.bound = calculateBound(leftChild, data.capacity, pallets, sortedIndices);
                if (leftChild.profit > maxProfit && leftChild.weight <= data.capacity) {
                    maxProfit = leftChild.profit;
                    bestSolution = leftChild.selections;
                }
                if (leftChild.bound > maxProfit) {
                    queue.push_back(leftChild);
                }
            }

            Node rightChild = node;
            rightChild.level = node.level + 1;
            rightChild.selections[itemIndex] = false;
            rightChild.bound = calculateBound(rightChild, data.capacity, pallets, sortedIndices);

            if (rightChild.bound > maxProfit) {
                queue.push_back(rightChild);
            }
        }

        solution.totalProfit = maxProfit;
        solution.iterations = iterations;

        for (int i = 0; i < n; i++) {
            if (bestSolution[i]) {
                solution.selected.push_back(i);
                solution.totalWeight += pallets[i].weight;
            }
        }
        return solution;
    }
};

void ilp(const Data& data, const vector<Pallet>& pallets) {
    ILPSolution solution = KnapsackILP::solve(data, pallets);

    cout << "[Integer Linear Programming Algorithm]" << endl;
    cout << "Total Profit: " << solution.totalProfit << endl;
    cout << "Total Weight: " << solution.totalWeight << endl;
    cout << "Selected Pallets:";

    vector<int> selectedPalletIds;
    for (int idx : solution.selected) {
        selectedPalletIds.push_back(pallets[idx].id);
    }
    sort(selectedPalletIds.begin(), selectedPalletIds.end());

    for (int id : selectedPalletIds) {
        cout << " " << id;
    }
    cout << endl;
}
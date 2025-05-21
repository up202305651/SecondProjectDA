#include "ilp.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <glpk.h>

using namespace std;

void integerLinearProgramming(const Data& data, const std::vector<Pallet>& pallets) {
    std::cout << "[Integer Linear Programming Algorithm]\n";

    auto start = chrono::high_resolution_clock::now();

    int n = pallets.size();

    glp_prob *lp = glp_create_prob();
    glp_set_prob_name(lp, "Knapsack");
    glp_set_obj_dir(lp, GLP_MAX);

    // add cols: one for each pallet
    glp_add_cols(lp, n);
    for (int i = 0; i < n; i++) {
        string col_name = "x_" + to_string(pallets[i].id);
        glp_set_col_name(lp, i + 1, col_name.c_str());
        glp_set_col_kind(lp, i + 1, GLP_BV); // Binary variable (0 or 1)
        glp_set_obj_coef(lp, i + 1, pallets[i].profit); // profit is the objective coefficient
    }

    // Add rows: capacity constraint
    glp_add_rows(lp, 1);
    glp_set_row_name(lp, 1, "weight");
    glp_set_row_bnds(lp, 1, GLP_UP, 0.0, data.capacity); // upper bound

    // constraint coefficients (weights of pallets)
    int *ind = new int[n+1];
    double *val = new double[n+1];

    for (int i = 0; i < n; i++) {
        ind[i + 1] = i + 1; // column index
        val[i + 1] = pallets[i].weight; // weight of pallet
    }

    glp_set_mat_row(lp, 1, n, ind, val);

    // set GLPK params
    glp_iocp parm;
    glp_init_iocp(&parm);
    parm.presolve = GLP_ON; // Presolver

    int res = glp_intopt(lp, &parm);

    if (res == 0) {
        double total_profit = glp_mip_obj_val(lp);
        double total_weight = 0.0;

        cout << "ILP Solution:\n";
        cout << "Selected pallets:\n";

        for (int i = 0; i < n; i++) {
            if (glp_mip_col_val(lp, i + 1) > 0.5) { // pallet is selected
                cout << "Pallet " << pallets[i].id
                    << " (Weight: " << pallets[i].weight
                    << ", Profit: " << pallets[i].profit << ")\n";
                total_weight += pallets[i].weight;
            }
        }

        cout << "\nTotal profit: " << total_profit << "\n";
        cout << "Total weight: " << total_weight << " (Capacity: " << data.capacity << ")\n";

        if (parm.msg_lev >= GLP_MSG_ALL) {
            cout << "Solution is optimal.\n";
        }
    } else {
        cout << "The problem could not be solved. Error code: " << res << "\n";
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;

    cout << "\nILP Approach Details:\n";
    cout << "- Used formulation: Maximize sum(profit_i * x_i) subject to sum(weight_i * x_i) <= capacity\n";
    cout << "- Variables: " << n << " binary variables (one per pallet)\n";
    cout << "- Constraints: 1 main constraint (total weight <= capacity)\n";
    cout << "- Solver used: GNU Linear Programming Kit (GLPK)\n";

    delete[] ind;
    delete[] val;
    glp_delete_prob(lp);
}

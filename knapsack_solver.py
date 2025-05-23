"""
@file knapsack_Solver.py
@brief Solver de Programação Linear Inteira para o Problema da Mochila.

Este script Python utiliza a biblioteca PuLP para resolver o Problema da Mochila 0/1 usando
Programação Linear Inteira (ILP). O script lê os dados de entrada de um arquivo, define o problema de otimização,
resolve-o usando um solver de ILP e escreve os resultados em um arquivo de saída.

@note Complexidade de Tempo: Depende do solver de Programação Linear Inteira utilizado. Geralmente,
       solvers de ILP têm complexidade exponencial no pior caso, mas são eficientes na prática para
       problemas de tamanho moderado.
@note Complexidade de Espaço: Depende do solver de Programação Linear Inteira utilizado. O espaço
       adicional é usado principalmente para armazenar os dados de entrada e saída.
"""

from pulp import LpProblem, LpMaximize, LpVariable, lpSum, PULP_CBC_CMD
import sys

# Read input from file
with open(sys.argv[1], 'r') as f:
    lines = f.readlines()
    n = int(lines[0].strip())
    capacity = int(lines[1].strip())
    weights = list(map(int, lines[2].strip().split()))
    profits = list(map(int, lines[3].strip().split()))

# Setup LP problem
model = LpProblem("Knapsack", LpMaximize)
x = [LpVariable(f"x{i}", cat="Binary") for i in range(n)]

model += lpSum(x[i] * profits[i] for i in range(n))
model += lpSum(x[i] * weights[i] for i in range(n)) <= capacity

# Solve
model.solve(PULP_CBC_CMD(msg=False))

selected = [str(i) for i in range(n) if x[i].varValue > 0.5]
total_profit = sum(profits[int(i)] for i in selected)
total_weight = sum(weights[int(i)] for i in selected)

# Write result to output file
with open(sys.argv[2], 'w') as f:
    f.write(f"{total_profit}\n")
    f.write(f"{total_weight}\n")
    f.write(" ".join(selected) + "\n")

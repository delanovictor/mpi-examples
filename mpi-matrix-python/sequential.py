from mpi4py import MPI
import numpy as np

comm = MPI.COMM_WORLD
rank = comm.Get_rank()
size = comm.Get_size()


# Função para realizar a multiplicação de matrizes
def matrix_multiplication(A, B):
    return np.dot(A, B)


# Tamanho das matrizes
rows, cols = 5000, 5000
matrix_size = rows * cols

# Divisão das linhas da matriz A entre os processos
local_rows = rows // size

np.random.seed(1234)

# Matrizes a serem multiplicadas (podem ser geradas aleatoriamente)
A = np.random.rand(matrix_size).reshape(rows, cols)
B = np.random.rand(matrix_size).reshape(rows, cols)

local_A = np.empty((local_rows, cols))

comm.Scatter(A, local_A)

# # Multiplicação local de matrizes
local_C = matrix_multiplication(local_A, B)

# # Reunião das matrizes resultantes de cada processo
C = np.empty((rows, cols))

comm.Gather(local_C, C)

if rank == 0:
    print("Result: ")
    print(C)

from mpi4py import MPI
import time
import sys

def solve(bo):
    find = find_empty(bo)
    if not find:
        return True
    else:
        row, col = find

    for i in range(1,10):
        if valid(bo, i, (row, col)):
            bo[row][col] = i

            if solve(bo):
                return True

            bo[row][col] = 0

    return False


def valid(bo, num, pos):
    # Check row
    for i in range(len(bo[0])):
        if bo[pos[0]][i] == num and pos[1] != i:
            return False

    # Check column
    for i in range(len(bo)):
        if bo[i][pos[1]] == num and pos[0] != i:
            return False

    # Check box
    box_x = pos[1] // 3
    box_y = pos[0] // 3

    for i in range(box_y*3, box_y*3 + 3):
        for j in range(box_x * 3, box_x*3 + 3):
            if bo[i][j] == num and (i,j) != pos:
                return False

    return True


def print_board(bo):
    for i in range(len(bo)):
        if i % 3 == 0 and i != 0:
            print("- - - - - - - - - - - - - ")

        for j in range(len(bo[0])):
            if j % 3 == 0 and j != 0:
                print(" | ", end="")

            if j == 8:
                print(bo[i][j])
            else:
                print(str(bo[i][j]) + " ", end="")


def find_empty(bo):
    for i in range(len(bo)):
        for j in range(len(bo[0])):
            if bo[i][j] == 0:
                return (i, j)  # row, col

    return None

start = time.time()

list_of_games = [
	[
		[0, 0, 3, 0, 2, 0, 6, 0, 0],
		[9, 0, 0, 3, 0, 5, 0, 0, 1],
		[0, 0, 1, 8, 0, 6, 4, 0, 0],
		[0, 0, 8, 1, 0, 9, 0, 0, 0],
		[7, 0, 0, 0, 0, 0, 0, 0, 8],
		[0, 0, 0, 7, 0, 8, 0, 0, 0],
		[0, 0, 6, 2, 0, 0, 0, 0, 0],
		[0, 0, 0, 5, 0, 3, 0, 0, 9],
		[0, 0, 0, 0, 4, 0, 0, 7, 0]
	],
	[
		[0, 0, 0, 0, 0, 5, 0, 8, 0],
		[0, 0, 0, 0, 0, 0, 1, 4, 0],
		[0, 0, 0, 0, 0, 9, 7, 0, 0],
		[0, 7, 0, 0, 0, 0, 8, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 2, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 1, 0, 0, 0, 0],
		[3, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 1, 0, 7, 0, 0, 0, 0]
	],
	[
		[5, 3, 0, 0, 7, 0, 0, 0, 0],
		[6, 0, 0, 1, 9, 5, 0, 0, 0],
		[0, 9, 8, 0, 0, 0, 0, 6, 0],
		[8, 0, 0, 0, 6, 0, 0, 0, 3],
		[4, 0, 0, 8, 0, 3, 0, 0, 1],
		[7, 0, 0, 0, 2, 0, 0, 0, 6],
		[0, 6, 0, 0, 0, 0, 2, 8, 0],
		[0, 0, 0, 4, 1, 9, 0, 0, 5],
		[0, 0, 0, 0, 8, 0, 0, 7, 9]
	],
	[
		[5, 3, 0, 0, 7, 0, 0, 0, 0],
		[6, 0, 0, 1, 9, 5, 0, 0, 0],
		[0, 9, 8, 0, 0, 0, 0, 6, 0],
		[8, 0, 0, 0, 6, 0, 0, 0, 3],
		[4, 0, 0, 8, 0, 3, 0, 0, 1],
		[7, 0, 0, 0, 2, 0, 0, 0, 6],
		[0, 6, 0, 0, 0, 0, 2, 8, 0],
		[0, 0, 0, 4, 1, 9, 0, 0, 5],
		[0, 0, 0, 0, 8, 0, 0, 7, 9]
	],
	[
		[0, 0, 0, 0, 0, 5, 0, 8, 0],
		[0, 0, 0, 0, 0, 0, 1, 4, 0],
		[0, 0, 0, 0, 0, 9, 7, 0, 0],
		[0, 7, 0, 0, 0, 0, 8, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 2, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 1, 0, 0, 0, 0],
		[3, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 1, 0, 7, 0, 0, 0, 0]
	],
	[
		[0, 0, 0, 0, 0, 5, 0, 8, 0],
		[0, 0, 0, 0, 0, 0, 1, 4, 0],
		[0, 0, 0, 0, 0, 9, 7, 0, 0],
		[0, 7, 0, 0, 0, 0, 8, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 2, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 1, 0, 0, 0, 0],
		[3, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 1, 0, 7, 0, 0, 0, 0]
	],
	[
		[0, 0, 0, 0, 0, 5, 0, 8, 0],
		[0, 0, 0, 0, 0, 0, 1, 4, 0],
		[0, 0, 0, 0, 0, 9, 7, 0, 0],
		[0, 7, 0, 0, 0, 0, 8, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 2, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 1, 0, 0, 0, 0],
		[3, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 1, 0, 7, 0, 0, 0, 0]
	],
	[
		[0, 0, 0, 0, 0, 5, 0, 8, 0],
		[0, 0, 0, 0, 0, 0, 1, 4, 0],
		[0, 0, 0, 0, 0, 9, 7, 0, 0],
		[0, 7, 0, 0, 0, 0, 8, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 2, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 1, 0, 0, 0, 0],
		[3, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 1, 0, 7, 0, 0, 0, 0]
	],
	[
		[5, 3, 0, 0, 7, 0, 0, 0, 0],
		[6, 0, 0, 1, 9, 5, 0, 0, 0],
		[0, 9, 8, 0, 0, 0, 0, 6, 0],
		[8, 0, 0, 0, 6, 0, 0, 0, 3],
		[4, 0, 0, 8, 0, 3, 0, 0, 1],
		[7, 0, 0, 0, 2, 0, 0, 0, 6],
		[0, 6, 0, 0, 0, 0, 2, 8, 0],
		[0, 0, 0, 4, 1, 9, 0, 0, 5],
		[0, 0, 0, 0, 8, 0, 0, 7, 9]
	],
	[
		[5, 3, 0, 0, 7, 0, 0, 0, 0],
		[6, 0, 0, 1, 9, 5, 0, 0, 0],
		[0, 9, 8, 0, 0, 0, 0, 6, 0],
		[8, 0, 0, 0, 6, 0, 0, 0, 3],
		[4, 0, 0, 8, 0, 3, 0, 0, 1],
		[7, 0, 0, 0, 2, 0, 0, 0, 6],
		[0, 6, 0, 0, 0, 0, 2, 8, 0],
		[0, 0, 0, 4, 1, 9, 0, 0, 5],
		[0, 0, 0, 0, 8, 0, 0, 7, 9]
	],
]

comm = MPI.COMM_WORLD
node_id = comm.Get_rank()
number_of_nodes = comm.Get_size()

number_of_games = int(sys.argv[1]) 
number_of_games_per_node = int(number_of_games / number_of_nodes) 

lower_bound =  node_id * (number_of_games_per_node - 1); 
upper_bound =  (node_id + 1) * number_of_games_per_node; 

solvable = 0;
unsolvable = 0;
result_list = []

# Loop through the numbers using rank number to divide the work
for i in range(lower_bound, upper_bound):
    index = i % len(list_of_games);

    grid = list_of_games[index]

    result = solve(grid)

    result_list.append(result)

    if result:
        solvable = solvable + 1
    else:
        unsolvable = solvable + 1


master_result_list = comm.gather(result_list, root=0)

if node_id == 0: 
    end = round(time.time() - start, 2)

    print('Time elasped: ' + str(end) + ' seconds')
    #Quantos resultados possuem solução:
    number_of_solvable_games = len([item for sublist in master_result_list for item in sublist if item == True])

    print(f"Solvable: {number_of_solvable_games}")
    print(f"Unsolvable: {number_of_games - number_of_solvable_games}")

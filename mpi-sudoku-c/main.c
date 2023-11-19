#define NUMBER_OF_GAMES_IN_LIST 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <mpi.h>
#include <time.h>
#include <stdbool.h>

int list_of_games [10][9][9] = {
	{
		{0, 0, 3, 0, 2, 0, 6, 0, 0},
		{9, 0, 0, 3, 0, 5, 0, 0, 1},
		{0, 0, 1, 8, 0, 6, 4, 0, 0},
		{0, 0, 8, 1, 0, 9, 0, 0, 0},
		{7, 0, 0, 0, 0, 0, 0, 0, 8},
		{0, 0, 0, 7, 0, 8, 0, 0, 0},
		{0, 0, 6, 2, 0, 0, 0, 0, 0},
		{0, 0, 0, 5, 0, 3, 0, 0, 9},
		{0, 0, 0, 0, 4, 0, 0, 7, 0}
	},
	{
		{0, 0, 0, 0, 0, 5, 0, 8, 0},
		{0, 0, 0, 0, 0, 0, 1, 4, 0},
		{0, 0, 0, 0, 0, 9, 7, 0, 0},
		{0, 7, 0, 0, 0, 0, 8, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 2, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0},
		{3, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 7, 0, 0, 0, 0}
	},
	{
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	},
	{
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	},
	{
		{0, 0, 0, 0, 0, 5, 0, 8, 0},
		{0, 0, 0, 0, 0, 0, 1, 4, 0},
		{0, 0, 0, 0, 0, 9, 7, 0, 0},
		{0, 7, 0, 0, 0, 0, 8, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 2, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0},
		{3, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 7, 0, 0, 0, 0}
	},
	{
		{0, 0, 0, 0, 0, 5, 0, 8, 0},
		{0, 0, 0, 0, 0, 0, 1, 4, 0},
		{0, 0, 0, 0, 0, 9, 7, 0, 0},
		{0, 7, 0, 0, 0, 0, 8, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 2, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0},
		{3, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 7, 0, 0, 0, 0}
	},
	{
		{0, 0, 0, 0, 0, 5, 0, 8, 0},
		{0, 0, 0, 0, 0, 0, 1, 4, 0},
		{0, 0, 0, 0, 0, 9, 7, 0, 0},
		{0, 7, 0, 0, 0, 0, 8, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 2, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0},
		{3, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 7, 0, 0, 0, 0}
	},
	{
		{0, 0, 0, 0, 0, 5, 0, 8, 0},
		{0, 0, 0, 0, 0, 0, 1, 4, 0},
		{0, 0, 0, 0, 0, 9, 7, 0, 0},
		{0, 7, 0, 0, 0, 0, 8, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 2, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0},
		{3, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 7, 0, 0, 0, 0}
	},
	{
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	},
	{
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	},
};

int main();
void printGrid(int grid[9][9]);
bool solveSudoku(int grid[9][9]);
bool findEmptyCell(int grid[9][9], int* row, int* col);
bool isValidMove(int grid[9][9], int row, int col, int num);

int current_game[9][9];
int result_game[9][9];


int main(int argc, char **argv)
{
	clock_t tic = clock();

    int number_of_games = argc == 2 ? atoi(argv[1]) : NUMBER_OF_GAMES_IN_LIST;       

    int node_id, number_of_nodes;              

	MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &node_id);
    MPI_Comm_size(MPI_COMM_WORLD, &number_of_nodes);

	int number_of_games_per_node = number_of_games / number_of_nodes;

	// printf ("%s: %d\n",    "rank",        node_id);
	// printf ("%s: %d\n",    "size",        number_of_nodes);
	// printf ("%s: %d\n",    "number_of_games",        number_of_games);
	// printf ("%s: %d\n",    "number_of_games_per_node",        number_of_games_per_node);

	int lower_bound =  node_id * number_of_games_per_node;
	int upper_bound =  (node_id + 1) * number_of_games_per_node;

	int solvable = 0;
	int unsolvable = 0;

	int total_number_of_solvables = 0;
	// printf("lower_bound %d\n", lower_bound);
	// printf("upper_bound %d\n", upper_bound);

	for(int i = lower_bound; i < upper_bound; i++) {
		int index = i % NUMBER_OF_GAMES_IN_LIST;

		if (solveSudoku(list_of_games[index])) {
			// printGrid(list_of_games[index]);
			solvable++;
		} else {
			// printf("No solution exists for the given puzzle.\n");
			unsolvable++;
		}

	}

	// printf("\nFinish!\n");
	// printf("Solvable: %d\n", solvable);
	// printf("Unsolvable: %d\n", unsolvable);

    MPI_Reduce(&solvable, &total_number_of_solvables, 1, MPI_INT,  MPI_SUM, 0, MPI_COMM_WORLD);

    clock_t toc = clock();
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    if (node_id == 0) {
		printf("\ntotal: %d\n", number_of_games);
		printf("solvables: %d\n", total_number_of_solvables);
		printf("unsolvables: %d\n", number_of_games - total_number_of_solvables);
    }

    MPI_Finalize();

	return 0;
}

bool solveSudoku(int grid[9][9]) {
    int row, col;
    
    // Find the next empty cell or a cell with 0
    if (!findEmptyCell(grid, &row, &col))
        return true;  // Puzzle solved
    
    // Try all possible values from 1 to 9
    for (int num = 1; num <= 9; num++) {
        // Check if the current value is valid
        if (isValidMove(grid, row, col, num)) {
            // Assign the value and recursively solve
            grid[row][col] = num;
            
            if (solveSudoku(grid))
                return true;  // Puzzle solved
            
            // Undo the assignment and try the next value
            grid[row][col] = 0;
        }
    }
    
    return false;  // No solution found
}

bool findEmptyCell(int grid[9][9], int* row, int* col) {
    for (*row = 0; *row < 9; (*row)++) {
        for (*col = 0; *col < 9; (*col)++) {
            if (grid[*row][*col] == 0)
                return true;  // Found an empty cell
        }
    }
    
    return false;  // No empty cell found
}

bool isValidMove(int grid[9][9], int row, int col, int num) {
    // Check if the number already exists in the same row
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num)
            return false;
    }
    
    // Check if the number already exists in the same column
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num)
            return false;
    }
    
    // Check if the number already exists in the same 3x3 sub-grid
    int subgridRow = (row / 3) * 3;
    int subgridCol = (col / 3) * 3;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[subgridRow + i][subgridCol + j] == num)
                return false;
        }
    }
    
    return true;  // Valid move
}

void printGrid(int grid[9][9])
{
	int i, j;

	for (i = 0; i < 10; i++) {
		if (i % 3 == 0)
			printf("+-------+-------+-------+\n");

		if (i == 9)
			return;

		for (j = 0; j < 9; j++) {
			if (j % 3 == 0)
				printf("| ");

			grid[i][j] != 0 ? printf("%d ", grid[i][j]) : printf(". ");
		}

		printf("|\n");
	}
}
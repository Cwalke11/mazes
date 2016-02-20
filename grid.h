#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define N_LINK 1
#define E_LINK 2
#define S_LINK 4
#define W_LINK 8
#define ENTRANCE1 16
#define ENTRANCE2 32

typedef struct cell_s{
	int row;
	int column;
	uint8_t links;
	
} cell_t;;

typedef struct grid_s{
	int rows;
	int columns;
	cell_t* cells;
} grid_t;

int grid_index(int x, int y, int width);
int link_north(grid_t* grid, int x, int y);
int link_east(grid_t* grid, int x, int y);
int link_south(grid_t* grid, int x, int y);
int link_west(grid_t* grid, int x, int y);
grid_t* blank_grid(int x, int y);
void print_grid(grid_t* grid);

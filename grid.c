#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grid.h"

//used to easily index into grid
//the x and y are wrong here... shit
int grid_index(int x, int y, int width){
	int i = (y * width) + x;
	return i;
}

//set a link to the north of selected cell,
//set a link to the south of norther cell
int link_north(grid_t* grid, int x, int y){
	grid->cells[grid_index(x, y, grid->columns)].links += N_LINK;
	grid->cells[grid_index(x-1, y, grid->columns)].links += S_LINK;
	//printf("North Link at %d, %d\n", x, y);
}

int link_east(grid_t* grid, int x, int y){
	grid->cells[grid_index(x, y, grid->columns)].links += E_LINK;
	grid->cells[grid_index(x, y+1, grid->columns)].links += W_LINK;
	//printf("East Link at %d, %d\n", x, y);
}

int link_south(grid_t* grid, int x, int y){
	grid->cells[grid_index(x+1, y, grid->columns)].links += N_LINK;
	grid->cells[grid_index(x, y, grid->columns)].links += S_LINK;
	//printf("South Link at %d, %d\n", x, y);
}

int link_west(grid_t* grid, int x, int y){
	grid->cells[grid_index(x, y-1, grid->columns)].links += E_LINK;
	grid->cells[grid_index(x, y, grid->columns)].links += W_LINK;
	//printf("West Link at %d, %d\n", x, y);
}

cell_t* initialize_cells(int row, int column){
	
	int i, j;
	cell_t* cell;
	cell_t* cells = (cell_t*)malloc(sizeof(cell_t)*(row*column));
	for(i = 0; i < row; i++){
		for(j = 0; j < column; j++){
			cell = &cells[grid_index(i, j, column)];
			cell->row = i;
			cell->column = j;
			cell->links = 0;
		}
	}
	return cells;
}

grid_t* blank_grid(int rows, int columns){

	grid_t* new_grid = malloc(sizeof(grid_t));
	new_grid->rows = rows;
	new_grid->columns = columns;
	new_grid->cells = malloc(sizeof(cell_t)*(rows*columns));
	//initialize_cells(new_grid->cells, rows, columns);
	new_grid->cells = initialize_cells(rows, columns);
	return new_grid;
}

void print_grid(grid_t* grid){
	// Simply printing a full grid
	// will modify to print maze eventually
	int i, j;
	cell_t* cell;
	int buffer_size = (grid->rows * grid->columns * 4);
	char* buffer = malloc(sizeof(char)*buffer_size);
	memset(buffer, 0, sizeof(buffer));
	strcat(buffer, "+");
	for(i = 0; i < grid->columns; i++){
		if(grid->cells[grid_index(0, i, grid->columns)].links & ENTRANCE1){
			strcat(buffer, "   +");
		}else{
			strcat(buffer, "---+");
		}
	}
	strcat(buffer, "\n");

	for(i = 0; i < grid->rows; i++){
	
		//build eastern walls
		strcat(buffer,"|");
		for(j = 0; j < grid->columns-1; j++){
			strcat(buffer,"   ");
			//TOUCH THIS UP
			cell = &grid->cells[grid_index(i, j, grid->columns)];
			(cell->links & E_LINK)? strcat(buffer, " "):strcat(buffer, "|");
		}
		strcat(buffer, "   |\n");

		//build southern walls
		strcat(buffer, "+");
		for(j = 0; j < grid->columns; j++){
	
			cell = &grid->cells[grid_index(i, j, grid->columns)];
			(cell->links & S_LINK || cell->links & ENTRANCE2)? strcat(buffer,"   +"):strcat(buffer,"---+");
		}
		strcat(buffer,"\n");	
			
	}
	printf("%s", buffer);

}

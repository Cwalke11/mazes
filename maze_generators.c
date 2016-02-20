#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grid.h"
#include "maze_generators.h"


int binary_tree_generator(grid_t* grid){
	int columns = grid->columns;
	int rows = grid->rows;
	int i, j;
	srand(time(NULL));
	
	for(i = 0; i < rows; i++){
		for(j = 0; j < columns; j++){
			//top row edge case
			if(i == 0){ 
				link_east(grid, i, j); 
			}
			//far right column edge case
			else if(j == (columns-1)){
				 link_north(grid, i, j);
			}
			else if(rand()%2){
				link_east(grid, i, j);
			}
			else{
				link_north(grid, i, j);
			}
		}
	}	
	return 0;

}
int cell_choice(int j, int start){
	srand(time(NULL));
	if(j){
		return (rand() % j) + start;
	}
	else{
		return 0;
	}

	
}
//TODO: Fix this
int side_winder_generator(grid_t* grid){
	//start in bottom left corner
	//move left to right, bottom up
	int columns = grid->columns;
	int rows = grid->rows;
	int i, j, start, col_choice;
	uint8_t is_new_run = 1;
	srand(time(NULL));	

	for(i = rows; i > 0; i--){
		for(j = 0; j < columns; j++){
			//far right column edge case
			if(is_new_run){
			//remember start of current run
				start = j;
				is_new_run = 0;
			}
			if(j == (columns) ){ 
				//close out run and pick a cell to link north
				col_choice = cell_choice(j, start);
				link_north(grid, i, col_choice);
				is_new_run = 1; 
			}
			else if(rand()%2){
				link_east(grid, i, j);
			}
			else{
				//close out run and pick a cell to link north
				col_choice = cell_choice(j, start);
				link_north(grid, i, col_choice);
				is_new_run = 1;
			}
			
		}
	}
	
	
	return 0;
}

//Simple test to see if print_grid is working
int test_maze_generator(grid_t* grid){
	
	int i;
	int x, y;
	srand(time(NULL));
	int len = (grid->rows) * (grid->columns);
	for(i = 0; i < len; i++){
		x = rand();
		y = rand();
		grid->cells[i].links += (x%2)? E_LINK : 0;
		grid->cells[i].links += (y%2)? S_LINK : 0;
	}
	return 0;
}

//TODO make this return grid, put call inside maze generators
int make_entrances(grid_t* grid){

	srand(time(NULL));
	int entrance1, entrance2;
	entrance1 = rand()%grid->columns;
	entrance2 = rand()%grid->columns;
	grid->cells[grid_index(0, entrance1, grid->columns)].links += ENTRANCE1;
	grid->cells[grid_index(grid->rows-1, entrance2, grid->columns)].links += ENTRANCE2;	

	return 0;
}

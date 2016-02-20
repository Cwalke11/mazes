#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include "maze_generators.h"

int main(){

	grid_t* grid = blank_grid(10, 10);
//	test_maze_generator(grid);
//	link_north(grid, 4, 4);
//	link_east(tes
	binary_tree_generator(grid);
//	side_winder_generator(grid);
	make_entrances(grid);
	print_grid(grid);

}

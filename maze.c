#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include "maze_generators.h"

int main(){

	grid_t* test = blank_grid(10, 10);
//	test_maze_generator(test);
//	link_north(test, 4, 4);
//	link_east(tes
//	binary_tree_generator(test);
	side_winder_generator(test);
	make_entrances(test);
	print_grid(test);

}

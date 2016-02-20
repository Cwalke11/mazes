all: maze

maze: maze.o maze_generators.o grid.o
	gcc -o maze maze.o maze_generators.o grid.o

%.o: %.c
	gcc -O0 -g -o $@ -c $<

clean:
	rm -f *.o maze 

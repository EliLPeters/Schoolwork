// PA 2
// CS 211 Data Structures Spring 2018
// Eli Peters

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Maze.h"

using namespace std;

int main(void)
{
	Maze the_maze = Maze();
	the_maze.read_maze("maze2.txt");
	the_maze.print_maze();
	return 0;
}
// PA 2
// CS 211 Data Structures Spring 2018
// Eli Peters

#include <iostream>
#include <string>

#include "Maze.h"

using namespace std;

int main(void)
{
	Maze the_maze = Maze();

	cout << "Which maze file would you like analyzed?" << endl;
	string maze_file = "";
	cin >> maze_file;

	the_maze.read_maze(maze_file);

	cout << endl << "The maze in " << maze_file << ":" << endl;
	the_maze.print_maze();

	cout << endl << endl;
	cout << "Which search method would you like to run?" << endl;
	cout << "JK, this feature hasn't actually been implemented yet!" << endl;
	return 0;
}
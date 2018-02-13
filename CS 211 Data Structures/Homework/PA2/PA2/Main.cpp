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

	the_maze.readMaze(maze_file);

	cout << endl << "The maze in " << maze_file << ":" << endl;
	the_maze.printMaze();
	the_maze.searchMazeStack();

	cout << endl << endl;
	cout << "Which search method would you like to run?" << endl;
	the_maze.searchMazeStack();
	the_maze.printMaze();
	return 0;
}
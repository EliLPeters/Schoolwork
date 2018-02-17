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

	cout << endl << endl;

	bool terminate = false;
	while (terminate == false)
	{
		cout << "Which search method would you like to run?" << endl;
		cout << "1: Depth-First Search" << endl << "2: Breadth-First Search" << endl;
		cout << "-1: End program." << endl;
		int choice = ' ';
		cin >> choice;

		switch (choice)
		{
			case 1:
				the_maze.searchMazeDepth();
				break;
			case 2:
				the_maze.searchMazeBreadth();
				break;
			case -1:
				terminate = true;
				break;
		}
	}
	return 0;
}
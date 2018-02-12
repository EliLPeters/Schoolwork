#pragma once
#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

class Maze
{
	int _maze_width = 0;
	int _maze_height = 0;

	int _start_x = 0;
	int _start_y = 0;

	string _file_name = "";

	vector<vector<char>> _maze_vector;

	public:
	void readMaze(string the_file)
	{
		_file_name = the_file;

		ifstream input_stream;
		input_stream.open(the_file);

		while (input_stream.is_open() && input_stream.good())
		{
			string current_line = "";
			getline(input_stream, current_line);

			int WS_pos = current_line.find(" ");

			// TODO: make this mess less ugly
			_maze_width = stoi(current_line.substr(0, WS_pos));
			_maze_height = stoi(current_line.substr((WS_pos + 1), ((current_line.length() - 1) - WS_pos)));

			_maze_vector.resize(_maze_height);

			for (int i = 0; i < _maze_height; i++)
			{
				getline(input_stream, current_line);
				_maze_vector[i].resize(_maze_width);

				for (int j = 0; j < _maze_width; j++)
				{
					if (current_line.at(j) == 'o')
					{
						_start_y = j;
						_start_x = i;
					}
					_maze_vector[i][j] = current_line.at(j);
				}
			}
		}

		input_stream.close();
	}

	void printMaze()
	{
		for (int i = 0; i < _maze_height; i++)
		{
			for (int j = 0; j < _maze_width; j++)
			{
				cout << _maze_vector[i][j];
			}
			cout << endl;
		}
	}

	// Makes handling x and y coordinates more intuitive.
	char getSymbol(int x, int y)
	{
		return _maze_vector[x][y];
	}

	void searchMazeStack()
	{
		int cur_x = _start_x;
		int cur_y = _start_y;

		stack<int[2]> process_stack;
		process_stack.push({cur_x, cur_y});

		while (!process_stack.empty())
		{
			switch (getSymbol(process_stack.top()[0], process_stack.top()[1]))
			{

			}
		}
	}

	void searchMazeQueue()
	{
		int cur_x = _start_x;
		int cur_y = _start_y;
	}
};

/*
switch statement during search
#: it's a wall, ignore
.: it's floor, add it to be examined
x: already explored, ignore
o: starting position, ignore
*: the target.  End the search.
*/

#endif // !MAZE_H

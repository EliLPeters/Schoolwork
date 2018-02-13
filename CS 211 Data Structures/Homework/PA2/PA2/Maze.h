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

	int _end_x = -1;
	int _end_y = -1;

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
	void setSymbol(int x, int y, char replacement)
	{
		_maze_vector[x][y] = replacement;
	}

	void searchMazeStack()
	{
		bool found_end = false;

		int cur_x = _start_x;
		int cur_y = _start_y;

		stack<int> x_stack;
		stack<int> y_stack;
		x_stack.push(_start_x);
		y_stack.push(_start_y);

		while (x_stack.empty() == false && y_stack.empty() == false && found_end == false)
		{
			cur_x = x_stack.top();
			cur_y = y_stack.top();
			setSymbol(x_stack.top(), y_stack.top(), 'x');

			x_stack.pop();
			y_stack.pop();

			char above = getSymbol(cur_x, (cur_y - 1));
			char below = getSymbol(cur_x, (cur_y + 1));
			char left = getSymbol((cur_x - 1), cur_y);
			char right = getSymbol((cur_x + 1), cur_y);

			//above
			switch (above)
			{
			case '#':
				break;
			case '.':
				x_stack.push(cur_x);
				y_stack.push(cur_y - 1);
				break;
			case 'x':
				break;
			case '*':
				found_end = true;
				break;
			}

			//below
			switch (below)
			{
			case '#':
				break;
			case '.':
				x_stack.push(cur_x);
				y_stack.push(cur_y + 1);
				break;
			case 'x':
				break;
			case '*':
				found_end = true;
				break;
			}

			//left
			switch (left)
			{
			case '#':
				break;
			case '.':
				x_stack.push(cur_x - 1);
				y_stack.push(cur_y);
				break;
			case 'x':
				break;
			case '*':
				found_end = true;
				break;
			}

			//right
			switch (right)
			{
			case '#': 
				break;
			case '.':
				x_stack.push(cur_x + 1);
				y_stack.push(cur_y);
				break;
			case 'x':
				break;
			case '*':
				found_end = true;
				break;
			}

		}
	}

	void searchMazeQueue()
	{
		bool found_end = false;

		int cur_x = _start_x;
		int cur_y = _start_y;

		queue<int> x_queue;
		queue<int> y_queue;
		x_queue.push(_start_x);
		y_queue.push(_start_y);

		while (x_queue.empty() == false && y_queue.empty() == false && found_end == false)
		{
			cur_x = x_queue.front();
			cur_y = y_queue.front();
			setSymbol(x_queue.front(), y_queue.front(), 'x');

			x_queue.pop();
			y_queue.pop();

			char above = getSymbol(cur_x, (cur_y - 1));
			char below = getSymbol(cur_x, (cur_y + 1));
			char left = getSymbol((cur_x - 1), cur_y);
			char right = getSymbol((cur_x + 1), cur_y);

			//above
			switch (above)
			{
			case '#':
				break;
			case '.':
				x_queue.push(cur_x);
				y_queue.push(cur_y - 1);
				break;
			case 'x':
				break;
			case '*':
				found_end = true;
				break;
			}

			//below
			switch (below)
			{
			case '#':
				break;
			case '.':
				x_queue.push(cur_x);
				y_queue.push(cur_y + 1);
				break;
			case 'x':
				break;
			case '*':
				found_end = true;
				break;
			}

			//left
			switch (left)
			{
			case '#':
				break;
			case '.':
				x_queue.push(cur_x - 1);
				y_queue.push(cur_y);
				break;
			case 'x':
				break;
			case '*':
				found_end = true;
				break;
			}

			//right
			switch (right)
			{
			case '#':
				break;
			case '.':
				x_queue.push(cur_x + 1);
				y_queue.push(cur_y);
				break;
			case 'x':
				break;
			case '*':
				found_end = true;
				break;
			}

		}
	}
};

#endif // !MAZE_H

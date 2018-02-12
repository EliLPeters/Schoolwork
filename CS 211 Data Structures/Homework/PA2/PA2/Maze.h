#pragma once
#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Maze
{
	int _maze_width = 0;
	int _maze_height = 0;

	vector<vector<char>> _maze_vector;

	public:
	void read_maze(string the_file)
	{
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
					_maze_vector[i][j] = current_line.at(j);
				}
			}
		}

		input_stream.close();
	}

	void print_maze()
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
};

#endif // !MAZE_H

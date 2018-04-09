#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>

#include "Actor.h"
#include "Movie.h"
#include "StringSplitter.h"

using namespace std;

int main(void)
{
	string file_name;
	cout << "Enter file name: ";
	getline(cin, file_name);

	unordered_map<string, Actor*> all_actors{};
	unordered_map<string, Movie*> all_movies{};

	ifstream graph_file{ file_name };

	if (graph_file.is_open() == true)
	{
		string line;
		getline(graph_file, line);

		while (graph_file.good() == true)
		{
			getline(graph_file, line);

			vector<string> pieces = StringSplitter::split(line, "\t");

			//[0] = actor ID
			//[1] = actor name
			//[5] - actor movies (in CSV format)
			string actor_id = pieces[0];
			string actor_name = pieces[1];
			vector<string> movie_ids = StringSplitter::split(pieces[5], ",");

			//new object tor represent this actor
			Actor* some_actor = nullptr;

			//check the graph to see if this actor already exists.
			//if they do, grab a pointer to that actor, otherwise,
			//create a new actor and attach to the graph.
			if (all_actors.find(actor_id) == all_actors.end())
			{
				some_actor = new Actor{};
				some_actor->setName(actor_name);
				some_actor->setId(actor_id);

				//this line attaches the actor to the graph
				all_actors[some_actor->getId()] = some_actor;
			}

			//repopulate some_actor
			some_actor = all_actors[actor_id];

			//attach movies to actors and vice versa
			for (auto movie_id : movie_ids)
			{
				// same thing as above.  Check graph to see if movie doesn't exist
				// if it doesn't make one, then atach the actor to the movie and vice versa
				Movie* some_movie = nullptr;
				if (all_movies.find(movie_id) == all_movies.end())
				{
					some_movie = new Movie{};
					some_movie->setId(movie_id);
					all_movies[some_movie->getId()] = some_movie;
				}
				some_movie = all_movies[movie_id];

				// finally connect actors to movies and vice versa
				some_actor->addMovie(some_movie);
				some_movie->addActor(some_actor);
			}
		}
	}

	return 0;
}
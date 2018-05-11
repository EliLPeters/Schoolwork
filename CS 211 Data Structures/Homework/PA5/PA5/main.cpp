#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <stack>

#include "Actor.h"
#include "Movie.h"
#include "StringSplitter.h"

using namespace std;

void list_movies(unordered_map<string, Actor*>& all_actors)
{
	string actor_ID = "";
	cout << "Enter Actor ID: ";
	cin >> actor_ID;
	cout << "Actor Name: " << all_actors[actor_ID]->getName() << endl;
	cout << "Movie IDs: ";

	vector<Movie*> actors_movies = all_actors[actor_ID]->getMovies();

	for (auto item : actors_movies)
	{
		cout << item->getId() << " ";
	}

	cout << endl;
}

bool connect_actors_helper(string target_ID, Movie* checked_movie, queue<Movie*>& movies_to_check, queue<queue<Movie*>>& route_taken)
{
	vector<Actor*> actors_in_movie = checked_movie->getActors();
	for (auto actor : actors_in_movie)
	{
		
		if (actor->getId() == target_ID)
		{
			route_taken.push(route_taken.front());
			return true;
		}
		else
		{
			vector<Movie*> new_movies = actor->getMovies();
			for (auto movie : new_movies)
			{
				queue<Movie*> temp = route_taken.front();
				temp.push(checked_movie);
				route_taken.push(temp);
				movies_to_check.push(movie);
			}
		}
	}
}

void connect_actors(unordered_map<string, Actor*>& all_actors)
{
	string actor_ID1 = "";
	cout << "Enter Actor#1's ID: ";
	cin >> actor_ID1;

	string actor_ID2 = "";
	cout << "Enter Actor#2's ID: ";
	cin >> actor_ID2;

	queue<Movie*> movies_to_check;
	queue<queue<Movie*>> route_taken;
	vector<Movie*> actors_movies = all_actors[actor_ID1]->getMovies();

	for (auto item : actors_movies)
	{
		queue<Movie*> temp;
		temp.push(item);
		route_taken.push(temp);
		movies_to_check.push(item);
	}

	bool connection_found = false;

	while (connection_found == false && movies_to_check.empty() == false)
	{

		connection_found = connect_actors_helper(actor_ID2, movies_to_check.front(), movies_to_check, route_taken);
		movies_to_check.pop();
		route_taken.pop();
	}

	if (connection_found)
	{
		queue<Movie*> ult_route = route_taken.back();
		cout << "Connection found through (DOESN\'T WORK YET)" << endl << "\* ";
		while (ult_route.empty() == false)
		{
			cout << ult_route.front()->getId() << " ";
			ult_route.pop();
		}
	}
	else
	{
		cout << "No connection found." << endl;
	}
}

vector<Actor*> degrees_helper(queue<Movie*>& new_movies, queue<Movie*> movies_to_visit)
{
	vector<Actor*> actors_at_degree;
	while (movies_to_visit.empty() == false)
	{
		vector<Actor*> actors_in_movie = movies_to_visit.front()->getActors();
		for (auto actor : actors_in_movie)
		{
			actors_at_degree.push_back(actor);
			vector<Movie*> other_movies = actor->getMovies();
			for (auto movie : other_movies)
			{
				new_movies.push(movie);
			}
		}
		movies_to_visit.pop();
	}
	return actors_at_degree;
}

void degrees(unordered_map<string, Actor*> all_actors)
{
	string actor_ID;
	cout << "Enter Actor ID: ";
	cin >> actor_ID;

	int num_degrees;
	cout << "Enter maximum degrees: ";
	cin >> num_degrees;

	cout << "Actor: " << all_actors[actor_ID]->getName() << endl;

	queue<vector<Actor*>> degree_actors;
	queue<Movie*> movies_to_visit;
	vector<Actor*> seen_actors;
	seen_actors.push_back(all_actors[actor_ID]);

	for (auto movie : all_actors[actor_ID]->getMovies())
	{
		movies_to_visit.push(movie);
	}
	for (int i = 1; i <= num_degrees; i++)
	{
		queue<Movie*> new_movies;
		degree_actors.push(degrees_helper(new_movies, movies_to_visit));
		movies_to_visit = new_movies;
	}

	for (int i = 1; i <= num_degrees; i++)
	{
		cout << "Degree " << i << " connections: ";
		vector<Actor*> cur_actors = degree_actors.front();
		degree_actors.pop();
		for (auto actor : cur_actors)
		{
			bool seen = false;
			for (auto seen_actor : seen_actors)
			{
				if (actor->getId() == seen_actor->getId())
				{
					seen = true;
				}
			}
			if (seen == false)
			{
				cout << actor->getName() << ", ";
				seen_actors.push_back(actor);
			}
		}
		cout << endl;
	}
}

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

	graph_file.close();

	//list_movies(all_actors);
	//connect_actors(all_actors);
	degrees(all_actors);

	return 0;
}
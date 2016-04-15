
/*****************************************************************************************
 *
 *
 *
 * Vishal Patel 
 * Melbourne
 * +61 439 590 446
 * vis8051@gmail.com
 * 26/04/2015
 *
 *
 *
 *****************************************************************************************/

#include <stdio.h>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define fin cin;

using std::vector;

class Movie {
private:
	int movieId;
	float rating;
	vector<Movie*> similarMovies; // Similarity is bidirectional

	// VP: Added to keep track of visited nodes.
	bool visited; 


public:

	Movie(int movieId, float rating) {
		this->movieId = movieId;
		this->rating = rating;
	}

	int getId() {
		return movieId;
	}

	float getRating() {
		return rating;
	}

	void addSimilarMovie(Movie* movie) {
		similarMovies.push_back(movie);
		movie->similarMovies.push_back(this);
	}

	vector<Movie *>& getSimilarMovies() {
		return similarMovies;
	}

	/*
	* Implement a function to return top rated movies in the network of movies
	* reachable from the current movie
	* eg:            A(Rating 1.2)
	*               /   \
	*            B(2.4)  C(3.6)
	*              \     /
	*               D(4.8)
	* In the above example edges represent similarity and the number is rating.
	* getMovieRecommendations(A,2) should return C and D (sorting order doesn't matter so it can also return D and C)
	* getMovieRecommendations(A,4) should return A, B, C, D (it can also return these in any order eg: B,C,D,A)
	* getMovieRecommendations(A,1) should return D. Note distance from A to D doesn't matter,
	*                             return the highest rated.
	*
	*     @param movie
	*     @param numTopRatedSimilarMovies
	*                      number of movies we want to return
	*     @return List of top rated similar movies
	*/

	static void getMovieRecommendations(Movie& movie, int numTopRatedSimilarMovies, vector<Movie *>& recommendedMovies) {

		// VP: properity queue to maintain heap.
		priority_queue<Movie *, vector<Movie *>, greater<vector<Movie*>::value_type > >  movieQueue;
		
		// VP: static method to fill up queue.
		Movie::createRecommandations(movie, movieQueue);

		// VP: adding required number of movies to passed on vector.
		int i = 1;
		while ( !movieQueue.empty() )
		{
			Movie *m = movieQueue.top();
			recommendedMovies.push_back(m);
			movieQueue.pop();
			if (i == numTopRatedSimilarMovies)
				break;
			i++;
		}

		return;
	}

	/**
     * VP:
	 * Core logic for the problem.
	 * I'm running BFS to scan movies in movie's network.
	 * while scanning I'm also adding found items in priority queue.
	 * priority queue will maintain ratings. (i.e. It will keep top rated movies at top of the heap )
	 *
	 *
	 * Running time will be combining time taken by graph traversal and maintaining the heap.
	 * O((V+E)logn)
	 */

	static void createRecommandations(Movie& movie, priority_queue<Movie *, vector<Movie *>, greater<vector<Movie*>::value_type > >& movieQueue)
	{
		movie.visited = true;

		list<Movie> queue;
		queue.push_back(movie); 
		movieQueue.push(&movie);

		while (!queue.empty())
		{
			Movie m = queue.front();
			vector<Movie *> v = m.getSimilarMovies();
			queue.pop_back();
			for (auto i = 0; i < v.size(); i++)
			{
				if (v[i]->visited == false)
				{
					v[i]->visited = true;
					queue.push_back(*v[i]);
					movieQueue.push(v[i]);
				}
			}
		}
	}
};



// VP: client
/*
int main()
{
	Movie movie1(1, 1.2);
	Movie movie2(2, 2.4);
	Movie movie3(3, 3.6);
	Movie movie4(4, 4.8);

	movie3.addSimilarMovie(&movie4);
	movie2.addSimilarMovie(&movie4);

	movie1.addSimilarMovie(&movie3);
	movie1.addSimilarMovie(&movie2);

	vector<Movie *> recomendations;
	Movie::getMovieRecommendations( movie1, 2, recomendations);

	for (auto i = 0; i < recomendations.size(); i++)
	{
		cout << "Movie id: " << recomendations[i]->getId() << endl;
	}

	return 0;
}*/
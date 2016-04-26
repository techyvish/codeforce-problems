//
// Created by Vishal Patel on 4/25/16.
//

#include <fstream>
#include <vector>
#include <queue>
#include <iostream>

namespace BP {
    using namespace std;

    // Define new type for Edge. (vetext,weight).
    typedef pair<int, int> ii;

    // Define new type for Vector of edges.
    typedef vector<ii> vii;

    // Defire new type for Vector of vertext.
    typedef vector<int> vi;
/*
 v[0] -> vii -> ii
                ii
                ii
                ii

 v[1] -> vii -> ii
                ii
                ii
                ii

*/

#define fin cin
#define INF 100000000

    vector<vii> AdjList;
    int V, E, a, b, s;
    vi p;
    // Vector with all infinity assigned
    vi color(V, INF);

    // a queue to process BFS
    queue<int> q;

    void bipartite_check(int s){

        // Assign color 0 to first vertex.
        color[s] = 0;
        bool isBipartite = true;

        // Push it on queue
        q.push(s);
        while ( !q.empty() && isBipartite ){

            // Pop from queue
            int u = q.front(); q.pop();

            // Iterate through Adjecent vertices
            for ( int j = 0 ; j < AdjList[u].size() ; j++ ){

                // Get <Vertext,Weight> pair
                ii v = AdjList[u][j];

                // Check if vertex is already processed or not ?
                if ( color[v.first] == INF ){

                    // If not assign different color then the Adjecent vetex ( the vertex it came from)
                    color[v.first] = 1 - color[u];

                    // Push back on the queue
                    q.push(v.first);

                    // If alrady processed then check the color of parent with current color
                    // If both matches then graph is not bipertite graph.
                }else if (color[v.first] == color[u]) {

                    // return bipertite = false
                    isBipartite = false ;
                    break;
                }
            }
        }

    }

    void run() {
        // Read input file in
        fstream fin("../bfs_traversal.txt");

        // Read no of vertices and no of pairs
        fin >> V >> E;

        // Assign all vertices empty vector of pairs
        AdjList.assign(V, vii());

        // Build graph
        for (int i = 0; i < E; i++) {
            // Read vertex a and vertex b
            fin >> a >> b;
            // connect a to b
            AdjList[a].push_back(ii(b, 0));
            // connect b to a
            AdjList[b].push_back(ii(a, 0));
        }


        bipartite_check(0);
    }

};



int main() {

    BP::run();
    return 0;
}
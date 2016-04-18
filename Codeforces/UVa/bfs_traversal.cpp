//
// Created by Vishal Patel on 4/17/16.
//

#include <fstream>
#include <vector>
#include <queue>
#include <iostream>

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

namespace  bfs {

    vector<vii> AdjList;
    int V, E, a, b, s;
    vi p;


    void run(){

        // Read input file in
        fstream fin("../bfs_traversal.txt");

        // Read no of vertices and no of pairs
        fin >> V >> E;

        // Assign all vertices empty vector of pairs
        AdjList.assign(V,vii());

        // Build graph
        for ( int i = 0 ; i < E ; i ++ ){
            // Read vertex a and vertex b
            fin >> a >> b;
            // connect a to b
            AdjList[a].push_back(ii(b,0));
            // connect b to a
            AdjList[b].push_back(ii(a,0));

        }

        // Create vector of distance and assign max value
        vi dist(V,100000000);

        // Source vertex i.e. 5
        s = 5;

        // distance to source vertext is 0;
        dist[s] = 0;


        // Create a queue
        queue<int> q;
        // Push source vertext in.
        q.push(s);

        // Layer for printing
        int layer = -1;

        // Parent vector
        p.assign(V,-1);
        bool isBipertite = true ;

        // Loop until queue is not empty
        while (!q.empty()) {

            // pop from font
            int u = q.front();
            q.pop();

            // If distance of vertex is not equal to current layer count
            // Print layer, its start of new layer.
            if (dist[u] != layer)
                cout << endl << "layer " << dist[u] << " : ";

            // Assign current distance to layer
            layer = dist[u];

            // Print visited
            cout << "visited " << u << " ";


            // Loop through all adjecent vertices
            for (int j = 0; j < AdjList[u].size(); j++) {

                // Ger vertex with its edge weight
                ii v = AdjList[u][j];

                // if vertex distance is MAX or not visited
                if (dist[v.first] == 100000000) {

                    // Increase distance
                    dist[v.first] = dist[u] + 1;

                    // Add u as perent
                    p[v.first] = u;

                    // Push vertex to the end of queue.
                    q.push(v.first);
                }
            }
        }
    }
}

int main(){

    bfs::run();
    return 0;
}
//
// Created by Vishal Patel on 4/25/16.
//

#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


namespace  TP {
    typedef pair<int, int> ii;
    typedef vector<ii> vii;
    typedef vector<int> vi;

    vector<vii> AdjList;


    vi dfs_num;
    vi ts;
    int numCC;

#define  DFS_BLACK 1
#define  DFS_WHITE -1
#define fin cin

    void dfs(int u) {

        // print node
        // printf("%d", u);

        // asign vertex to BLACK
        dfs_num[u] = DFS_BLACK;

        // Loop through that node's Adjecency list
        for (int j = 0; j < AdjList[u].size(); j++) {

            // get pair
            ii v = AdjList[u][j];

            // if vertext is white
            if (dfs_num[v.first] == DFS_WHITE) {

                //Run DFS on that vertex.
                dfs(v.first);
            }
        }

        // For topological sort store visited vertex in list.
        // push stuff to the stack and while unwinding stack put last visited vertex first
        // and printing list in reverse order you'll get topological sort.
        ts.push_back(u);

    }


    void run() {

        fstream fin("../topological_sort.txt");

        int V, totalNeighbours, id, weight;

        // Get number of vertices
        fin >> V;

        ts.clear();

        // fill up Adjcency list with epty vector of pairs
        AdjList.assign(V, vii());

        // Assign all DFS_NUM to white
        dfs_num.assign(V, DFS_WHITE);

        // Loop through all vertices
        for (int i = 0; i < V; i++) {

            // get number of neighbours
            fin >> totalNeighbours;

            // loop through number of neighbours
            for (int j = 0; j < totalNeighbours; j++) {

                // Get id and weight
                fin >> id >> weight;

                // add into current node's Adjecency list.
                AdjList[i].push_back(ii(id, weight));
            }
        }


        // Run DFS on each unvisited node, input graph must be undirected.
        for (int i = 0; i < V; i++) {
            if (dfs_num[i] == DFS_WHITE )
                dfs(i);
        }


        // Print list in revese order
        for ( int i = ts.size()-1 ; i >= 0 ;i --){

            string separator =  (i != 0) ? " -> " : "";
            cout << ts[i] << separator;
        }

    }
};

int main() {

    TP::run();
    return  0;
}
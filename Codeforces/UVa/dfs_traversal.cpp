//
// Created by Vishal Patel on 4/16/16.
//


#include <vector>
#include <fstream>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vii> AdjList;

vi dfs_num;
int numCC;

#define  DFS_BLACK 1
#define  DFS_WHITE -1
#define fin cin

void dfs(int u){

    // print node
    printf("%d",u);

    // asign vertex to BLACK
    dfs_num[u] = DFS_BLACK;

    // Loop through that node's Adjecency list
    for ( int j = 0 ; j < AdjList[u].size(); j++ ){

        // get pair
        ii v = AdjList[u][j];

        // if vertext is white
        if ( dfs_num[v.first ] == DFS_WHITE){

            //Run DFS on that vertex.
             dfs(v.first);
        }
    }

}

int main_dfs(){


    fstream fin("../dfs_traversal.txt");

    int V,totalNeighbours,id,weight;

    // Get number of vertices
    fin >> V;



    // fill up Adjcency list with epty vector of pairs
    AdjList.assign(V,vii());

    // Assign all DFS_NUM to white
    dfs_num.assign(V, DFS_WHITE);

    // Loop through all vertices
    for ( int i =0 ; i < V; i ++ ){

        // get number of neighbours
        fin >> totalNeighbours;

        // loop through number of neighbours
        for ( int j = 0 ; j < totalNeighbours ; j++ ){

            // Get id and weight
            fin >> id >> weight;

            // add into current node's Adjecency list.
            AdjList[i].push_back(ii(id,weight));
        }
    }

    // Run DFS demo, input graph must be undirected.
    dfs(0);

    // Reset all DFS_NUM to white
    dfs_num.assign(V,DFS_WHITE);
    int c = 0;

    // Loop through all vertices
    for ( int i = 0 ; i < V ; i++){

        // if dfs_num is white then count ++ and start dfs from that node.
        if (dfs_num[i] == DFS_WHITE )
            c++, dfs(i);
    }

    // Print number of connected components.
    printf("number of connected components = %d", c);

    return 0;

}
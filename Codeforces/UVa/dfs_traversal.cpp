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

    printf("%d",u);
    dfs_num[u] = DFS_BLACK;

    for ( int j = 0 ; j < AdjList[u].size(); j++ ){
        ii v = AdjList[u][j];
        if ( dfs_num[v.first ] == DFS_WHITE){
             dfs(v.first);
        }
    }

}

int main_dfs_traversal(){


    fstream fin("../dfs_traversal.txt");

    int V,totalNeighbours,id,weight;
    fin >> V;

    AdjList.assign(V,vii());
    dfs_num.assign(V, DFS_WHITE);

    for ( int i =0 ; i < V; i ++ ){
        fin >> totalNeighbours;
        for ( int j = 0 ; j < totalNeighbours ; j++ ){
            fin >> id >> weight;
            AdjList[i].push_back(ii(id,weight));
        }
    }

    // DFS demo, input graph must be undirected.
    dfs(0);

    return 0;

}
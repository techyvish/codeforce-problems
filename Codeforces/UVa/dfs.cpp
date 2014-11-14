//
//  dfs.cpp
//  Codeforces
//
//  Created by Vishal Patel on 13/11/2014.
//  Copyright (c) 2014 Vishal Patel. All rights reserved.
//

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

using namespace std;

// Basic macros
#define st          first
#define se          second
#define ALL(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fr(i,n)     re(i,0,n)
#define repv(i,f,t) for(int i = f; i >= t; --i)
#define rev(i,f,t)  repv(i,f - 1,t)
#define frv(i,n)    rev(i,n,0)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define CLR(a) a.clear()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define FORi(i,a,b) for(LET(i,a) ; i<b; i++)
#define repi(i,n) FORi(i,(__typeof(n))0,n)
#define FOR(i,a,b) for(i=a ; i<b; i++)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pi(n) printf("%d",n)
#define piw(n) printf("%d ",n)
#define pin(n) printf("%d\n",n)
#define sortv(a) sort(a.begin(),a.end())
#define DRT()  int t; cin>>t; while(t--)
#define DRI(n)  int n; cin>>n;
#define DRII(n,m)  int n,m; cin>>n>>m;

const int oo = 2000000009;
const double eps = 1e-9;

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<vector<int > > vvi;
typedef vector<string> vs;

#define fin cin

#define VISITED 1
namespace dfs {
    class Graph
    {
        
        vector<vii> adjList;
        vi dfs_linked;
        int v;
        
    public:
        
        vi dfs_num;
        vi reachability;
        
        Graph(int v )
        {
            this->v = v;
            adjList.resize(v+1);
            dfs_num.resize(v+1);
            dfs_linked.resize(v+1);
            reachability.resize(v+1);
        }
        
        void addEdge(int p, int q, int weight)
        {
            adjList[p].push_back(make_pair(q, weight));
        }
        
        void dfs(int u )
        {
            dfs_num[u] = VISITED;
            
            for ( int j = 0 ; j < adjList[u].size() ;j++ )
            {
                ii v = adjList[u][j];
//                for ( int i = 1 ; i <= dfs_num.size() ; i++ )
//                {
//                    if ( dfs_num[i] && v.first == u )
//                    {
//                        reachability[i] = 1;
//                    }
//                }
                if ( dfs_num[v.first] != VISITED && v.second == 1 )
                {
                    
                    dfs(v.first);
                }
            }
        }
        
        bool isReachable(int from,int to)
        {
            
            return false;
        }
        void updateSelfLinks(int p)
        {
            if ( reachability[p] == 1 )
            {
                dfs_num[p] = VISITED;
            }
            else
            {
                dfs_num[p] = !VISITED;
            }
        }
        
        void clear()
        {
            dfs_num.clear();
            dfs_num.resize(v+1);
        }
    };
}

int main_dfs()
//int main()
{
    //FILE *fp = freopen("/Users/Shared/codeforces/codeforces/in.txt", "rt", stdin);
    fstream fin("/Users/Shared/codeforces/codeforces/uva/dfs.txt");
    
    char sti[1024];
    string buffstr;
    bool end = false;
    while (getline(fin, buffstr) )
    {
        if ( buffstr == "0")
            break;
        
        int numvert = 0;
        sscanf(buffstr.c_str(), "%d",&numvert);
        dfs::Graph g(numvert);

        while (getline(fin, buffstr) )
        {
            if ( buffstr == "0")
                break;
            sscanf(buffstr.c_str(), "%[^\n\r]", sti);
            stringstream ss(sti);
            int p;
            ss >> p;
            int q;
            while (ss>>q) {
                if ( q != 0 )
                    g.addEdge(p, q, 1);
            }
        }
        
        getline(fin, buffstr);
        sscanf(buffstr.c_str(), "%[^\n\r]", sti);
        if ( buffstr == "0" ){
            end =  true;
            break;
        }
        stringstream A(sti);
        int a ;
        A >>a;
        int b;
        while (A >> b) {
            g.clear();
            g.dfs(b);
            g.updateSelfLinks(b);
            string str;
            int count = 0;;
            for (int i = 1 ; i <= numvert ;i++)
            {
                if ( !g.dfs_num[i] )
                {
                    str += " ";
                    stringstream ss;
                    ss << i ;
                    string s;
                    ss >> s;
                    str += s;
                    count ++;
                }
            }
            
            stringstream ss;
            ss << count;
            string s;
            ss >> s;
            s += str;
            cout << s << endl;
        }
        
        //if ( end )
        //break;
    }
    
    return 0;
}

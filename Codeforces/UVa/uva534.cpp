//
//  uva534.cpp
//  Codeforces
//
//  Created by Vishal Patel on 22/11/2014.
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
#include <math.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;

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
#define fin cin
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<vector<int > > vvi;
typedef vector<string> vs;

namespace floyed {
    class Graph
    {
        
        vector<vii> adjList;
        vi dfs_linked;
        int v;
        
    public:
        
        vi dfs_num;
        vi reachability;
        set<int> visitvert;
        int nodeToFind;
        
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
            for ( int j = 0 ; j < adjList[u].size() ;j++ )
            {
                ii v = adjList[u][j];
                

            }
        }
        
        void clear()
        {
            dfs_num.clear();
            dfs_num.resize(v+1);
        }
    };
};

const int N = 1002;
double g[N][N];
double minrange = 999999;
#define INF 999999999

int main()
{
    //fstream fin("/Users/Shared/codeforces/codeforces/uva/uva534.txt");
    cout << fixed << setprecision(3);
    int a ;
    cin >> a;
    vector<pi> pairs;
    int numvert = 0;
    int k = 1;
    while ( a != 0 ) {
        int b = a;
        int fredx,fredy;
        int fionax,fionay;
        pairs.push_back(make_pair(-1, -1));
        cin >> fredx >> fredy;
        pairs.push_back(make_pair(fredx, fredy));
        cin >> fionax >> fionay;
        vector<pi> loc;

        int j = 0;
        b -= 2;
        loc.push_back(make_pair(fredx, fredy));
        j++;
        numvert += 2;
        while ( b != 0 )
        {
            int p,q;
            cin >> p >> q;
            pairs.push_back(make_pair(p, q));
            numvert ++;
            b--;
        }
        
        pairs.push_back(make_pair(fionax, fionay));
        
        for (int i = 1 ; i <= numvert ; i++ ) g[i][i] = 0;
        for (int i = 1 ; i <= numvert ; i++ )
        {
            for (int j = i + 1 ; j <= numvert ; j++ )
            {
                g[i][j] = g[j][i] =  abs (pairs[i].first - pairs[j].first) * abs (pairs[i].first - pairs[j].first) +
                                 abs (pairs[i].second - pairs[j].second) * abs (pairs[i].second - pairs[j].second) ;
            }
        }
        
        for ( int k = 1 ; k <= numvert ; k++)
        {
            for ( int i = 1 ; i <= numvert ; i++)
            {
                for ( int j = 1 ; j <= numvert ; j++)
                {
                    g[i][j]=min(g[i][j],max(g[i][k],g[k][j]));
                }
            }
        }
        
//        for ( int i = 1 ; i <= numvert ;i++)
//        {
//            for ( j = 1 ; j  <= numvert ; j ++ )
//            {
//                if (g[i][j] == INF)
//                    cout << g[i][j] << "   ";
//                else
//                    cout << g[i][j] << " ";
//            }
//            cout << endl;
//        }
        
        cin >> a;
        cout << "Scenario #" << k++ << endl;
        cout << "Frog Distance = "<< sqrt(g[1][numvert]) << endl ;
        if (a != 0)
            cout << endl;
        numvert = 0;
        pairs.clear();
   
        memset(g, 0, sizeof(g));
    }
    return 0;
}
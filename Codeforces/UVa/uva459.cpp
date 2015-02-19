//
//  uva459.cpp
//  Codeforces
//
//  Created by Vishal Patel on 1/18/15.
//  Copyright (c) 2015 Vishal Patel. All rights reserved.
//

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
#include <list>

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
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int , ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<vector<int > > vvi;
typedef vector<string> vs;
#define VISITED 1

#define fin cin

namespace UVA459 {
    
char grid[1000][1000] ={};

int R = 0;
int C = 0;

int dr[] = {1,1,0,-1,-1,-1, 0, 1};  // Trick to explore implicit 2D grid
int dc[] = {0,1,1, 1, 0,-1,-1,-1};  // S,SE,E,NE,N,NW,W,SW

int floodFill(int r, int c, char c1, char c2 ) // returns the size of Connected components.
{
    
    if ( r < 0 || r >= R || c < 0 || c >= C) // outside of the grid
    {
        return 0;
    }
    if ( grid[r][c] != c1 ) // does not have the color c1
        return 0;
    
    int ans = 1; // add 1 to the answer because vertex (r,c) has c1 as its color.
    grid[r][c] = c2 ; // now recolors vertex(r,c) to c2 to avoid cycling.
    for ( int d = 0 ; d < 8 ; d ++)
    {
        ans += floodFill(r + dr[d], c + dc[d], c1 , c2 );
    }
    
    
    return  ans ;
}

}

int main()
{
    //fstream fin("/Users/vishal/Cerebro/codeforce-problems/Codeforces/UVa/uva459.txt");

    int tc = 0;
    fin >> tc;

    while (tc ) {
    
        int k = 0;

        string str;
        fin >> str;

        while ( str.length() > 1 ) {

            for (int i = 0 ; i < str.length() ; i++ )
            {
                UVA459::grid[k][i] = str[i];
            }
            UVA459::R = (int)str.length();
            k++;
            fin >> str;
        }
        
        UVA459::C = k;
        
        stringstream ss;
        ss << str ;
        int x , y;
        ss >> x ;
        fin >> y;
        vii v;
        v.push_back(make_pair(x, y));

        int ans = UVA459::floodFill(x-1, y-1, 'W', '.');
        string buffstr;
        getline(fin, buffstr);
        cout << ans << endl;
         while (getline(fin, buffstr) && sscanf(buffstr.c_str(), "%d %d",&x,&y) == 2)
        {
            v.push_back(make_pair(x, y));
            ans = UVA459::floodFill(x-1, y-1, 'W', '.');
            cout << ans << endl;
        }
        cout << endl;
        tc --;
    }
    
    return 0;
}




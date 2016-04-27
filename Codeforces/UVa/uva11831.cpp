//
//  uva12577.cpp
//  Codeforces
//
//  Created by Vishal Patel on 18/11/2014.
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

// Sticker collection robot
int main()
{
	char g[101][101];

    std::ios::sync_with_stdio(false);
    fstream fin("../../uva11831.txt");
    
	int row, col, ins;	

	fin >> row >> col >> ins;
	int si, sj = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			char c;
			fin >> c;
			g[i][j] = c;
			if (c == 'N' || c == 'S' || c == 'L' || c == 'O')
			{
				si = i;
				sj = j;
			}
		}
	}
	string inss;

	fin >> inss;

	int stickers = 0;
	int a = 0;
	while (inss[a])
	{
		char currentDir = g[si][sj];
		char c = inss[a];
		if (c == 'F')
		{
			if (currentDir == 'N')
			{
				if (si >= 0 && g[si-1][sj] != '#')
				{
					if (g[si - 1][sj] == '*')
					{
						stickers++;
					}
					g[si - 1][sj] = 'N';
					g[si][sj] = '.';
				}
			}
			else if (currentDir == 'S')
			{
				if (si < row && g[si + 1][sj] != '#')
				{
					if (g[si + 1][sj] == '*')
						stickers++;
					g[si + 1][sj] = 'S';
					g[si][sj] = '.';
				}
			}
			else if (currentDir == 'L')
			{
				if (si >= 0 && g[si][sj - 1]  != '#')
				{
					if (g[si][sj - 1] == '*')
						stickers++;

					g[si][sj -1] = 'L';
					g[si][sj] = '.';
				}
			}
			else if (currentDir == 'O')
			{
				if (si < col && g[si][sj + 1] != '#')
				{
					if (g[si][sj + 1] == '*')
						stickers++;
					g[si][sj + 1] = 'O';
					g[si][sj] = '.';
				}
			}
		}
		
		a++;
	}


    return 0;
}
//
//  uva12503.cpp
//  Codeforces
//
//  Created by Vishal Patel on 14/11/2014.
//  Copyright (c) 2014 Vishal Patel. All rights reserved.
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

struct Int
{
    char dir;
    char step;
};
typedef struct Int Instruction;
int main()
{
    //FILE *fp = freopen("/Users/Shared/codeforces/codeforces/in.txt", "rt", stdin);
    //fstream fin("/Users/Shared/codeforces/codeforces/uva/uva12503.txt");
    
    char sti[1024];
    string buffstr;
    int ts;
    fin >> ts;
    int step = 0;
    vector<Instruction> instList;
    while (ts != 0) {
        
        int nCommands;
        fin >> nCommands;
        
        getline(fin,buffstr);
        
        while (nCommands != 0) {
            
            getline(fin,buffstr);
            int steps;
            Instruction i;
            if ( buffstr == "LEFT")
            {
                i.dir = 'L';
            }
            else if ( buffstr == "RIGHT")
            {
                i.dir = 'R';
            }
            else if ( sscanf( buffstr.c_str(), "SAME AS %d", &steps ) == 1)
            {
                Instruction in  = instList[steps-1];
                i.dir = in.dir;
            }
            
            instList.push_back(i);
            nCommands --;
        }
        
        for ( int i = 0 ; i < instList.size() ; i++)
        {
            if ( instList[i].dir == 'L')
            {
                step = step - 1;
            }
            else
            {
                step = step + 1;
            }
        }
    
        cout << step << endl;
    
        instList.clear();
        step = 0;
        ts --;
    }
    
    
    //while ( sscanf(buffstr.c_str(), "%[^\n\r]",sti) == 1) {
    //}
}
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

int main_uva534()
{
    
    //fstream fin("/Users/Shared/codeforces/codeforces/uva/uva534.txt");
    cout << fixed << setprecision(3);
    int a ;
    cin >> a;
    int k = 1;
    while ( a != 0 ) {
        int b = a;
        int fredx,fredy;
        int fionax,fionay;
        
        cin >> fredx >> fredy;
        cin >> fionax >> fionay;
        vector<pi> loc;
        double maxdistance = 9999999;
        int j = 0;
        b -= 2;
        loc.push_back(make_pair(fredx, fredy));
        j++;
        while ( b != 0 )
        {
            int p,q;
            cin >> p >> q;
            loc.push_back(make_pair(p, q));
            double dist = 0;
            if ( loc.size() > 1) {
              dist  = sqrt( (abs(loc[j].first - loc[j-1].first) * abs(loc[j].first - loc[j-1].first)) +
                           (abs(loc[j].second - loc[j-1].second) * abs(loc[j].second - loc[j-1].second)));
                           }
            
            if ( dist <= maxdistance )
                maxdistance = dist;
            b--;
        }
        if ( loc.size() > 1)
        {
            double dist  = sqrt( (fionax - loc[j-1].first) * abs(fionax - loc[j-1].first) +
                         (abs(fionay - loc[j-1].second) * abs(fionay - loc[j-1].second)));
            if ( dist <= maxdistance )
                maxdistance = dist;
        }
    
        if ( maxdistance == 9999999 )
        {
            maxdistance = sqrt( abs(fionax - fredx ) * abs(fionax - fredx ) +
                               abs( fionay - fredy) *  abs( fionay - fredy));
        
        }
        cout << "Scenario #"<< k++ << endl;
        cout << "Frog Distance = " << maxdistance << endl;
        cin >> a;
        if ( a )
            cout << endl;
        
    }
    return 0;
}
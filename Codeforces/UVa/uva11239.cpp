//
//  uva11239.cpp
//  Codeforces
//
//  Created by Vishal Patel on 16/10/2014.
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
#include <unordered_map>
#include <algorithm>

using namespace std;

//typedef long long ll;
//typedef vector<int> vi;
//typedef pair<int,int> pi;
//typedef vector<string> vs;
//
//// Basic macros
//#define st          first
//#define se          second
//#define all(x)      (x).begin(), (x).end()
//#define ini(a, v)   memset(a, v, sizeof(a))
//#define re(i,s,n)  	for(int i=s;i<(n);++i)
//#define rep(i,s,n)  for(int i=s;i<=(n);++i)
//#define fr(i,n)     re(i,0,n)
//#define repv(i,f,t) for(int i = f; i >= t; --i)
//#define rev(i,f,t)  repv(i,f - 1,t)
//#define frv(i,n)    rev(i,n,0)
//#define pu          push_back
//#define mp          make_pair
//#define sz(x)       (int)(x.size())
//
//#define PB push_back
//#define MP make_pair
//#define F first
//#define S second
//#define SZ(a) (int)(a.size())
//#define CLR(a) a.clear()
//#define SET(a,b) memset(a,b,sizeof(a))
//#define LET(x,a) __typeof(a) x(a)
//#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
//#define FORi(i,a,b) for(LET(i,a) ; i<b; i++)
//#define repi(i,n) FORi(i,(__typeof(n))0,n)
//#define FOR(i,a,b) for(i=a ; i<b; i++)
//#define rep(i,n) FOR(i,0,n)
//#define si(n) scanf("%d",&n)
//#define sll(n) scanf("%lld",&n)
//#define pi(n) printf("%d",n)
//#define piw(n) printf("%d ",n)
//#define pin(n) printf("%d\n",n)
//#define sortv(a) sort(a.begin(),a.end())
//#define DRT()  int t; cin>>t; while(t--)
//#define DRI(n)  int n; cin>>n;
//#define DRII(n,m)  int n,m; cin>>n>>m;
//
//const int oo = 2000000009;
//const double eps = 1e-9;
//
//#ifdef TRACE
//#define trace1(x)                cerr << #x << ": " << x << endl;
//#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
//#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
//#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
//#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
//#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
//
//#else
//
//#define trace1(x)
//#define trace2(x, y)
//#define trace3(x, y, z)
//#define trace4(a, b, c, d)
//#define trace5(a, b, c, d, e)
//#define trace6(a, b, c, d, e, f)
//
//#endif
#define fin cin

auto CompareKeys = [](std::pair<string,int> const & a, std::pair<string,int> const & b)
{
    return a.second != b.second?  a.second > b.second : a.first < b.first;
};

int main()
{
    //FILE *fp = freopen("/Users/Shared/codeforces/codeforces/in.txt", "rt", stdin);
    //fstream fin("/Users/Shared/codeforces/codeforces/uva/uva11239.txt");
    
    char stp[1024];
    char std[1024];
    string buffstr;
    map<string, set<string>> project;
    map<string,int> repeated;
    vector<pair<string,int>> final;
    getline(fin, buffstr) ;
    sscanf(buffstr.c_str(), "%[A-Z ]%*[^\n\r]",stp);
    while ( string(stp) != "") {
        if ( buffstr == "0")
            break;
        if ( string(stp) == "1")
        {
            //print solution
            int p = 0;
            for ( auto i = project.begin() ; i != project.end() ; i++ , p++)
            {
                set<string> s = i->second;
              for ( auto it = s.begin()   ; it != s.end() ; it++ )
                {
                    string std = *it;
                    int i = repeated[std];
                    repeated[std] = i + 1;
                }
            }
            
            vector<pair<string, int> > v;
            copy(repeated.begin(), repeated.end(), back_inserter(v));
            sort(v.begin(), v.end(), CompareKeys);
            
            for ( auto it = v.begin() ; it != v.end() ; it++ )
            {
                if ( it->second >= 2)
                {
                    for ( auto i = project.begin() ; i != project.end() ; i++ , p++)
                    {
                        set<string> studset = i->second;
                        if ( studset.find(it->first) != studset.end())
                        {
                            set<string>::iterator itr = studset.find(it->first);
                            studset.erase(itr);
                            project[i->first] = studset;
                        }
                    }
                }
                else
                {
                    break;
                }
            }
            
            for ( auto i = project.begin() ; i != project.end() ; i++ )
            {
                final.push_back(make_pair(i->first, (i->second).size()));
            }
            sort(final.begin(),final.end(),CompareKeys);
            for ( auto i = final.begin()  ; i != final.end() ; i++ )
            {
                cout << i->first << " ";
                cout << i->second;
                cout << endl;
            }
            project.clear();
            repeated.clear();
            final.clear();
        }
        
        set<string> students;
        buffstr = "";
        while (getline(fin, buffstr) && sscanf(buffstr.c_str(), "%[a-z0-9 ]",std) == 1) {
            if ( string(std) == "0" || string(std) == "1")
                break;
            students.insert(string(std));
        }
        if (string(stp) != "1")
            project[string(stp)] = students;
        
        //if ( string(std) != "0" || string(std) != "1")
        fill_n(stp, 50, 0);
        memcpy(stp, buffstr.c_str(), buffstr.size());
        buffstr = "";
    }
}





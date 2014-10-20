//
//  uva417.cpp
//  Codeforces
//
//  Created by Vishal Patel on 18/10/2014.
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
#include <algorithm>

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
/*
// case-independent (ci) string less_than
// returns true if s1 < s2
struct ci_less : binary_function<string, string, bool>
{
    
	// case-independent (ci) compare_less binary function
    
	struct nocase_compare : public binary_function<unsigned char,unsigned
    char,bool>
	{
		bool operator() (const unsigned char& c1, const unsigned char& c2) const
		{
            cout << c1  << ":" << c2 <<endl;
            return tolower (c1) < tolower (c2);
        }
	};
    
	bool operator() (const string & s1, const string & s2) const
	{
		return lexicographical_compare
        (s1.begin (), s1.end (),   // source range
         s2.begin (), s2.end (),   // dest range
         nocase_compare());  // comparison
	}
}; // end of ci_less

// OR a simpler (and probably faster) version (by dave):
struct ci_less2
{
    bool operator() (const string & s1, const string & s2) const
    {
        if ( s1.size () == s2.size() )
        {
            return s1 < s2;
        }
        else
        {
            return s1.size() < s2. size();
        }
    }
};


int main()
{
    //FILE *fp = freopen("/Users/Shared/codeforces/codeforces/in.txt", "rt", stdin);
    //fstream fin("/Users/Shared/codeforces/codeforces/uva/uva417.txt");

    map<string,int,ci_less2> words;
    
    int P = 1;
 
    for ( int i = 0 ; i < 26 ; i++ )
    {
        char c = i + 97;
        string  s ;
        s+=c;
        words[s] = P++;
    }
    
    for ( int i = 0 ; i < 26; i ++ )
    {
        for ( int j = i + 1; j < 26 ; j ++ )
        {
            char c = i + 97;
            string  s ;
            s+=c;
            char d = j + 97;
            s+=d;
            words[s] = P++;
        }
    }
    
    for ( int i = 0 ; i < 26; i ++ )
    {
        for ( int j = i + 1; j < 26 ; j ++ )
        {
            for ( int k = j + 1; k < 26 ; k ++ )
            {
                
                char c = i + 97;
                string  s ;
                s+=c;
                char d = j + 97;
                s+=d;
                char e = k + 97;
                s+=e;
                words[s] = P++;
            }
        }
    }
    
    
    for ( int i = 0 ; i < 26; i ++ )
    {
        for ( int j = i + 1; j < 26 ; j ++ )
        {
            for ( int k = j + 1; k < 26 ; k ++ )
            {
                for ( int l = k + 1; l < 26 ; l ++ )
                {
                    char c = i + 97;
                    string  s ;
                    s+=c;
                    char d = j + 97;
                    s+=d;
                    char e = k + 97;
                    s+=e;
                    char f = l + 97;
                    s+=f;
                    words[s] = P++;
                }
            }
        }
    }
    
    for ( int i = 0 ; i < 26; i ++ )
    {
        for ( int j = i + 1; j < 26 ; j ++ )
        {
            for ( int k = j + 1; k < 26 ; k ++ )
            {
                for ( int l = k + 1; l < 26 ; l ++ )
                {
                    for ( int m = l + 1; m < 26 ; m ++ )
                    {
                        char c = i + 97;
                        string  s ;
                        s+=c;
                        char d = j + 97;
                        s+=d;
                        char e = k + 97;
                        s+=e;
                        char f = l + 97;
                        s+=f;
                        char g = m + 97;
                        s+=g;
                        words[s] = P++;
                        
                        if ( P > 83681)
                            break;
                    }
                }
                if ( P > 83681)
                    break;
            }
            if ( P > 83681)
                break;
        }
        if ( P > 83681)
            break;
    }
    
    
    
    char sti[1024];
    string buffstr;
    while (getline(fin, buffstr) && sscanf(buffstr.c_str(), "%[^\n\r]",sti) == 1) {
        string s = string(sti);
        if ( words[s] == 0 )
        {
            cout << "0" << endl;
        }
        else
        {
            cout << words[s] << endl;
        }
    }
}

 */

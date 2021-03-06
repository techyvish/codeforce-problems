    //
//  uva12219.cpp
//  Codeforces
//
//  Created by Vishal Patel on 17/11/2014.
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

struct _node
{
    vector<int> parents;
    _node* nodes[101];
    _node *parent;
    int value;
};
typedef  struct _node node;
bool gfound = false ;

node *nodes[300008];

bool testParent(node *node, int parent)
{
    bool found = false;
    if (std::find(node->parents.begin(),node->parents.end(), parent) != node->parents.end())
    {
        found = true;
    }
//    while ( node->parent != NULL ) {
//        
//        node = node->parent;
//        
//        if ( node->value == parent )
//        {
//            found = true;
//            break;
//        }
//    }
    
    return found;
}

void dfs(node *root, int parent, int child)
{
    node *n = nodes[child];
    if ( testParent(n, parent ))
    {
        gfound= true;
        return;
    }
}

int main_uva1357()
{
    //fstream fin("/Users/Shared/codeforces/codeforces/uva/uva1357.txt");

    string buffstr;
    int ts;
    fin >> ts;
    int k = 1;
    while ( ts != 0 )
    {
        int N;
        fin >> N;
        node *root = NULL;
        int j = 0;
        queue<node *> items;
        int childern = 0;
        
        node *head = new node;
        root = new node;
        root->value = j;
        root->parent = NULL;
        head = root;
        items.push(root);
        nodes[j] = root;
        j++;
        
        while (!items.empty())
        {
            if ( childern == N ){
                break;
            }
            childern ++;
            root = items.front();
            items.pop();
            int child ;
            fin >> child;
            for (int i = 0 ; i < child ; i++ )
            {
                node *n = new node;
                n->parents = root->parents;
                n->parents.push_back(root->value);
                n->value = j;
                n->parent = root;
                root->nodes[i] = n ;
                items.push(n);
                nodes[j] = n;
                j++;
            }
        }
        

        int query;
        cin >> query;
        cout << "Case " << k++ << ":" << endl;
        while ( query != 0) {
            int child;
            int parent;
            cin >> parent;
            cin >> child;
            dfs(head,parent,child);
            if (gfound )
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            gfound = false;
            query--;
        }
        ts--;
        memset(nodes, 0, sizeof(node *)*300008);
        if ( ts > 0 )
            cout << endl;
    }
    return 0;
}
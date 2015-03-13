//
//  uva102.cpp
//  Codeforces
//
//  Created by Vishal Patel on 3/13/15.
//  Copyright (c) 2015 Vishal Patel. All rights reserved.
//

#include <stdio.h>
#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <set>

using namespace std;

#define bit(x, i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb, n) asm ("bsrl %1,%0" : "=r" (msb) : "r" (n)) //get the highest bit of x, maybe the fastest

#define max(a, b)                           (a < b ? b : a)
#define abs(x)                              (x < 0 ? (-x) : x) // big bug here if "-x" is not surrounded by "()"

#define IN(i, l, r)                         (l < i && i < r) //the next for are for checking bound
#define LINR(i, l, r)                       (l <= i && i <= r)
#define LIN(i, l, r)                        (l <= i && i < r)
#define INR(i, l, r)                        (l < i && i <= r)

#define F(i, L, R)                          for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i, L, R)                         for (int i = L; i <= R; i++)
#define FF(i, L, R)                         for (int i = L; i > R; i--)
#define FFE(i, L, R)                        for (int i = L; i >= R; i--)

#define getI(a)                             scanf("%d", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define getII(a, b)                         scanf("%d%d", &a, &b)
#define getIII(a, b, c)                     scanf("%d%d%d", &a, &b, &c)
#define wez(n) int (n);                     scanf("%d", &(n)) //handy if the input is right after the definition of a variable
#define wez2(n, m) int (n), (m);            scanf("%d %d", &(n), &(m))
#define wez3(n, m, k) int (n), (m), (k);    scanf("%d %d %d", &(n), &(m), &(k))

#define TESTS wez(testow)                   while (testow--) //for multilple cases problems
#define whileZ int T;                       getI(T); while (T--) // the same as above

#define getS(x)                             scanf("%s", x) //get a char* string
#define clr(a, x)                           memset(a, x, sizeof(a)) //set elements of array to some value

#define char2Int(c)                         (c-'0')

#define lastEle(vec)                        vec[vec.size()-1]
#define SZ(x)                               ((int)((x).size()))
#define REMAX(a, b)                         (a) = max((a), (b)) // set a to the maximum of a and b
#define REMIN(a, b)                         (a) = min((a), (b));

#define FOREACH(i, t)                       for (typeof(t.begin())i = t.begin(); i != t.end(); i++) // traverse an STL data structure
#define ALL(c)                              (c).begin(), (c).end() //handy for function like "sort()"

#define PRESENT(c, x)                       ((c).find(x) != (c).end())
#define CPRESENT(c, x)                      (find(ALL(c), x) != (c).end())

#define ll                                  long long //data types used often, but you don't want to type them time by time
#define ull                                 unsigned long long
#define ui                                  unsigned int
#define us                                  unsigned short
#define IOS                                 ios_base::sync_with_stdio(0); //to synchronize the input of cin and scanf
#define INF                                 1001001001
#define PI                                  3.1415926535897932384626
//for map, pair
#define mp                                  make_pair
#define fi                                  first
#define se s                                econd
// for debug
inline void pisz(int n)
{
    printf("%d\n", n);
}

#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define printA(a, L, R) FE(i, L, R) cout << a[i] << (i == R ? '\n' : ' ')
#define printV(a) printA(a, 0, a.size()-1)
#define MAXN 10000
//for vectors
#define pb push_back
typedef int elem_t;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
// directions
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
template<typename T, typename TT> ostream& operator <<(ostream &s, pair<T, TT> t)
{
    return s<<"("<<t.first<<","<<t.second<<")";
}

template<typename T> ostream& operator <<(ostream &s, vector<T> t)
{
    F(i, 0, SZ(t)) s<<t[i]<<" "; return s;
}

using namespace std;


int  main()
{
     fstream fin("/Users/vishal/Cerebro/codeforce-problems/Codeforces/UVa/uva102.txt");
    
    string str;
    while (getline(fin, str,'\n')) {
        int a,b,c,d,e,f,g,h,i;
        int arr[4][4]={0};
        sscanf(str.c_str(), "%d %d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h,&i);
        
        int p = 0 ;
        int q = 0;
        
        arr[p][q++] =  b+c;
        arr[p][q++] =  e+f;
        arr[p][q++] =  h+i;
        
        p++;
        q=0;
        arr[p][q++] =  a+c;
        arr[p][q++] =  d+f;
        arr[p][q++] =  g+i;
        
        p++;
        q=0;
        arr[p][q++] =  a+b;
        arr[p][q++] =  d+e;
        arr[p][q++] =  g+h;
        
        int k = 0;
        char colors[] = {'B','G','C'};
        std::pair<int, int > ij[3];
        std::pair<int, char> AB[3];
        int sum = 0;
        int x,y;
        F(i , 0, 3)
        {
            int min = 9999999;
            F(j, 0, 3)
            {
                if ( arr[i][j] < min)
                {
                    min = arr[i][j];
                    x = i ;
                    y = j ;
                }
            }
        
            AB[k] = mp(min,colors[k] );
            sum += min;
            k++;
        }
        
        sort(AB,AB+3);
        string str ;
        for ( int i =0 ; i < 3; i++)
        {
            str+= AB[i].second;
        }
        
        cout << str << " "<< sum;
        
        
    }
    return 0;
}

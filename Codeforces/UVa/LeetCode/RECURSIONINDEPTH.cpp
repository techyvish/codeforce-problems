//
// Created by Vishal Patel on 11/30/16.
//


#include <fstream>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <stack>
#include <map>


using namespace std;
#define fin cin
bool isAnagram(string s, string t) {

    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    return  s == t;
}

void nestedLoops(int n)
{
    for( int i = 1 ; i <= n ; i ++ )
    {
        for( int j = 1 ; j <= n ; j ++ )
        {
            for( int k = 1 ; k <= n ; k ++ )
            {
                printf (" %d %d %d \n", i , j , k  );
            }
        }
    }
}

void printLoop(vector<u_long> &v)
{
    for ( int i = 0 ; i < 3 ; i++ )
    {
        printf( "%d " ,v[i] );
    }
    printf("\n");
}


void recursion(u_long currentLoop , u_long noOfLoops, u_long noOfIterations, vector<u_long> &v)
{
    if (currentLoop == noOfLoops )
    {
        printLoop(v);
        return;
    }

    for (u_long i = 1 ; i <= noOfIterations ; i ++ )
    {
        v[currentLoop] = i;
        recursion( currentLoop + 1 , noOfLoops, noOfIterations, v);
    }

}

int main() {


    fstream fin("../LeetCode/RECURSIONINDEPTH.txt");
    u_long n, k  ;

    // nestedLoops(3);

    cin >> n >> k;
    vector<u_long> v(k);
    recursion( 0, n, k, v);

    printf("\n");
    return 0 ;
}

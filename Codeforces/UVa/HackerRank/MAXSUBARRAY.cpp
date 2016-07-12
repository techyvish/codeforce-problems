// Maximum Sum Subarray

#include <fstream>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>

using namespace std;
#define fin cin

typedef struct {
    int i,j,max;
} maxx;

int main() {

    int n, t, tc, a[1000000];
    fstream fin("../HackerRank/MAXSUBARRAY.txt");
    fin >> tc;


    while (tc-- ){
        fin >> n;
        for ( int i = 0 ; i < n ; i ++ ){
            fin >> a[i];
        }

        maxx result;
        int max_so_far = 0, max_ending_here = 0;
        for ( int i = 0; i < n ; i ++ ) {
            max_ending_here = max_ending_here + a[i];
            if ( max_ending_here < 0 ) {
                max_ending_here = 0 ;
                result.i = i;
                result.j = i;
                result.max = max_ending_here;
            } else if ( max_so_far < max_ending_here ) {
                max_so_far = max_ending_here;
                result.j = i;
                result.max = max_so_far;
            }
        }

        cout << "i: " << result.i << " j: " << result.j << " max: " << result.max << endl;
    }

}

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

int main_maxsumsubarray() {

    int n, t, tc, a[1000000];
    fstream fin("../HackerRank/MAXSUBARRAY.txt");
    fin >> tc;


    while (tc-- ){
        fin >> n;
        for ( int i = 0 ; i < n ; i ++ ){
            fin >> a[i];
        }

        maxx result = {0,0,0};
        int non_cont_sum = 0 ;
        int max_negative = -INT_MAX;
        int max_so_far = 0, max_ending_here = 0;
        for ( int i = 0; i < n ; i ++ ) {
            if ( a[i] > 0 ) {
                non_cont_sum += a[i];
            } else if ( a[i] > max_negative ){
                max_negative = a[i];
            }
            max_ending_here = max_ending_here + a[i];
            if ( max_ending_here < 0 ) {
                max_ending_here = 0 ;
                result.i = i;
                result.j = i;
            } else if ( max_so_far < max_ending_here ) {
                max_so_far = max_ending_here;
                result.j = i;
                result.max = max_so_far;
            }
        }

        int max2 = 0 ;
        if (non_cont_sum > 0 ){
            max2 = non_cont_sum;
        }else {
            max2 = max_negative;
        }
        int max1 = 0 ;
        if ( result.max > 0 ){
            max1 = result.max;
        }else {
            max1 = max2;
        }
        cout << max1 << " " << max2 << endl;
        //cout << "i: " << result.i << " j: " << result.j << " max: " << result.max << endl;
    }

}

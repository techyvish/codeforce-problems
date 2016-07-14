//
// Created by Vishal Patel on 7/13/16.
//


#include <fstream>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>

using namespace std;
#define fin cin

typedef struct _max{
    int i ;
    int j ;
    int max ;


}maxx;

int main_uva10684() {

    int n, t, tc, a[1000000];
    fstream fin("../UVA10684.txt");

    fin >> n;
    while ( n != 0 ) {
        for ( int i = 0 ; i < n ; i ++ ){
            fin >> a[i];
        }

        maxx maxres = {0,0,0};

        int max_so_far = 0, max_end_here = 0 ;
        for ( int i = 0 ; i < n ; i ++ ){
            max_end_here = max_end_here + a[i];
            if ( max_end_here < 0 ) {
                max_end_here = 0;
                maxres.i = i;
                maxres.j = i;
            } else if ( max_so_far < max_end_here ){
                max_so_far = max_end_here;
                maxres.j = i;
                maxres.max = max_so_far;
            }
        }

        if ( maxres.max > 0 ) {
            printf("The maximum winning streak is %d.\n",maxres.max);
        }else {
            printf("Losing streak.\n");
        }

        fin >> n;

    }
    printf("\n");

}

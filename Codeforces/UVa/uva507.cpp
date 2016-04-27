//
// Created by Vishal Patel on 4/27/16.
//

#include <iostream>
#include <fstream>

#define fin cin
using namespace std;

typedef struct res {
    int i ;
    int j ;
    int sum;
} res;

int main() {


    fstream fin("../uva507.txt");



    int tc ;
    fin >> tc;

    while ( tc-- ) {
        int n;
        fin >> n;
        int a[n+1];

        struct res max_sub[n+1], max, max_cur;
        max_cur.sum = -1 * INT_MAX;
        max.sum = max_cur.sum;
        max.i = max_cur.i;
        max.j = max_cur.j;

        int sum = 0 ;

        for (int i = 0 ; i < n ; i ++ ) {
            fin >> a[i];
            sum += a[i];

            if (max_cur.sum < 0  ){
                max_cur.sum = a[i];
                max_cur.i = i;
                max_cur.j = i;

            } else {
                max_cur.sum += a[i];
                max_cur.j = i;
            }

            if ( max_cur.sum > max.sum ){
                max.sum = max_cur.sum;
                max.i = max_cur.i;
                max.j = max_cur.j;
            }

            max_sub[i] = max;
        }

        cout << "start " << max_sub[n-1].i + 1<< " end " << max_sub[n-1].j + 1 << endl;
//        if ( start == finish){
//            cout << "There is no nice road";
//        }else if ( finish > start ){
//            cout << "There is nice reoad";
//        }

    }



    return  0;
}
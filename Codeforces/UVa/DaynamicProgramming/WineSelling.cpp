//
// Created by Vishal Patel on 8/12/17.
//

/*
 * 		"Imagine you have a collection of N wines placed next to each other on a shelf. For simplicity,
 * 		let's number the wines from left to right as they are standing on the shelf with integers from 1 to N, respectively.
 * 		The price of the ith wine is pi. (prices of different wines can be different).
		Because the wines get better every year, supposing today is the year 1, on year y the price of the ith wine will be y*pi,
		i.e. y-times the value that current year.
		You want to sell all the wines you have, but you want to sell exactly one wine per year, starting on this year.
		One more constraint - on each year you are allowed to sell only either the leftmost or the rightmost wine on the
		shelf and you are not allowed to reorder the wines on the shelf (i.e. they must stay in the same order as they are in the beginning).
		You want to find out, what is the maximum profit you can get, if you sell the wines in optimal order?"
 */

#include "iostream"
using namespace std;

// N^3 solution
int solve(int be, int en, int year, int *a){

    if ( be == en ){
        return a[be] * year;
    }

    return max( solve(be+1,en,year+1,a) + year * a[be],
                solve(be,en-1,year+1,a) + year * a[en]);
}

// N^2 solution
int solve1(int be, int en, int year, int *a, int **cache){

    if ( be == en ){
        return a[be] * year;
    }

    if ( cache[be][en] != -1 )
        return cache[be][en];

    cache[be][en] = max( solve(be+1,en,year+1,a) + year * a[be],
                         solve(be,en-1,year+1,a) + year * a[en]);

    return cache[be][en];
}

int main() {


//    int n;
//    cin >> n;
//    int *a = new int[n];
//    for (int i = 0 ; i < n ; i++ ){
//        cin >> a[i];
//    }
    int n = 5;
    int a[5] = { 2, 3, 5 ,1, 4 };
    int final = solve(0,4,1,a);

    int **cache = new int*[n];
    for (int i = 0; i < n ;i++ ){
        int *a  = new int[n];
        memset(a,-1,n*sizeof(int));
        cache[i]=a;
    }

    int final1 = solve1(0,4,1,a,cache);
    return 0;
}


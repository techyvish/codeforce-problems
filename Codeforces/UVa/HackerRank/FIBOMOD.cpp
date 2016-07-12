//
// Created by Vishal Patel on 6/28/16.
//

#include <fstream>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>

using namespace std;
//#define fin cin
int main_fibomod() {

    // Read input file in
    fstream fin("../HackerRank/FIBOMOD.txt");
    long long a,b,n;

    fin >> a >> b >> n;
    long long dp = pow(b,2)+ a ;
    for ( int i = 3 ; i < n ; i ++ ){
        dp = pow(dp,2) + 1;
    }
    cout << dp;
    return 0;

}
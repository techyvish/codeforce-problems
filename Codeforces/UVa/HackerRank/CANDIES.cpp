//
// Created by Vishal Patel on 6/29/16.
//


#include <fstream>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>

using namespace std;
#define fin cin

int main_CANDIES() {

    int n , t;
    fstream fin("../HackerRank/CANDIES.txt");
    fin >> n ;
    vector<int> a(n);
    for ( int i = 0 ; i < n ; i ++ ){
        fin >> a[i];
    }

    vector<int> dp(n,1);
    for ( int i = 0 ; i < n ; i ++ ){
        if ( a[i] > a[i-1] ){
            dp[i] = dp[i-1]+1;
        }
    }

    for (int i = n - 1 ; i >= 0 ; i-- ){
        if(a[i-1]>a[i]) {
            dp[i - 1] = max(dp[i] + 1, dp[i - 1]);
        }

    }

    for ( int i = 0 ; i < n ; i++ ){
        t += dp[i];
    }

    cout << t;
    return 0;
}
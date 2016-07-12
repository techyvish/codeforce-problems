//
// Created by Vishal Patel on 6/11/16.
//

#include <fstream>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


int main_SPOJ() {

    // Read input file in
    fstream fin("../ABA12C.txt");

    int tc;
    fin >> tc;
    while (tc--) {

        int a[10001] = {0};
        int dp[1000][1000] = {0};
        int n, k;
        fin >> n >> k;

        for (int i = 0; i < k; i++) {
            fin >> a[i];
        }

    }
    return 0;
}
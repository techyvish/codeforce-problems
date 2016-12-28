//
// Created by Vishal Patel on 12/28/16.
//

#include <fstream>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <stack>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>
#include <cctype>

using namespace std;
#define fin cin

int main()
{
    fstream fin("../HackerEarth/LEAFANDLIMELIGHTATTACK.txt");

    vector<int> nums;
    unsigned int n ;
    fin >>  n;
    vector<vector<int>> m;

    // TODO buid spiral matrix in reverse order

    for ( int i = 0 ; i < n ; i ++ ) {
        vector<int> v(n);
        for ( int j = 0 ; j < n ; j++ ) {
            cin >> v[j];
        }

        m.push_back(v);
    }
    int sum = 0;
    int sum2 = 0;
    for ( int i = 0 ; i < n ; i ++ ) {
        for (int j = 0; j < n; j++) {
            if ( i == j )
                sum += m[i][j];
            if ( ((n-1-i) + j) == n - 1)
                sum2 += m[n-1-i][j];
        }
    }

    return sum+sum2;
}
//
// Created by Vishal Patel on 8/13/17.
//

#include "iostream"
#include "vector"
using namespace std;


int main() {

    string s1 = "";
    string s2 = "";
    int maxL = s1.length() > s2.length() ? s1.length() + 1 : s2.length() + 1;
    int **dp = new int*[maxL];
    for ( int i = 0; i < maxL ; i++){
        dp[i] = new int[maxL];
    }

    for ( int i =0 ; i < s2.length() ; i ++ ) {
        dp[i][0] = 0;
    }

    for ( int j =0 ; j < s1.length() ; j++ ) {
        dp[0][j] = 0;
    }

    for (int i = 0; i < s1.length() ; i++ ){
        for ( int  j = 0 ; j < s2.length() ; j++ ){



        }
    }

    return 0;
}
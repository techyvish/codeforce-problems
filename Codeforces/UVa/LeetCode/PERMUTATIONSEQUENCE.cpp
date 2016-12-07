//
// Created by Vishal Patel on 12/7/16.
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


void permute(int n , int k,int l, bool found, vector<int> &res , int iter , string resstr)
{
    if ( l == n  )
    {
        if ( iter == k - 1 ) {
            found = true;
            string str;
            str.resize(n);
            for (int i = 0; i < n; i++)
                str[i] = (char) res[i] + 48;
            cout << str << endl;
            resstr = str;
        }
        return;
    }
    for ( int i = l ; i < n ; i ++ )
    {
        if  (found )
            break;

        int  temp = res[l];
        res[l] = res[i] ;
        res[i] = temp;

        permute(n,k,l+1,found,res,iter,resstr);

        temp = res[l];
        res[l] = res[i] ;
        res[i] = temp;
    }
}

string getPermutation(int n, int k)
{
    string str;
    bool  found  = false;
    str.resize(n);
    vector<int> res(n);
    for ( int i = 0 ; i < n ; i ++ )
        res[i] = i+1;
    int iter = 0;
    string resstr;
    permute(n,k,0,found,res,iter + 1,resstr);
    return resstr;
}

int main() {

    fstream fin("../LeetCode/PERMUTATIONSEQUENCE.txt");

    vector<int> nums;
    int n , k;
    fin >>  n >> k;

    getPermutation(n,k);

    return 0 ;
}


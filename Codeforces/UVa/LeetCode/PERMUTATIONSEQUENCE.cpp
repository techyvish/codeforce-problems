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

static int iter1 = 0;
static bool found = false;
static string resstr = "";

void permute(int n , int k,int l, vector<int> &res)
{
    if ( l == n  )
    {
        if ( iter1 == k - 1 ) {
            found = true;
            string str;
            str.resize(n);
            for (int i = 0; i < n; i++)
                str[i] = (char) res[i] + 48;
            cout << str << endl;
            resstr = str;
        }
        iter1 ++;
        return;
    }
    for ( int i = l ; i < n ; i ++ )
    {
        if  (found )
            break;

        int  temp = res[l];
        res[l] = res[i] ;
        res[i] = temp;

        permute(n,k,l+1,res);

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
    permute(n,k,0,res);
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


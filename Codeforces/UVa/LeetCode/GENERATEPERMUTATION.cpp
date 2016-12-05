//
// Created by Vishal Patel on 12/3/16.
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

void permute(int n, int l, vector<vector<int> > &list)
{
    for ( int i = 0 ; i < n ; i ++ )
    {
        permute(n, l + 1, list);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> list;
    string str;
    permute( n ,0,list);
    return list;
}

vector<string> generateParenthesis(int n) {
    vector<string> list;
    string str;
    str.resize( n * 2 );
    generatePara( n * 2 ,0,list,str);
    return list;
}

int main() {

    int n ;
    fstream fin("../LeetCode/GENERATEPERMUTATION.txt");

    fin >> n;
    vector<string> s = generateParenthesis(n);
    return 0 ;
}



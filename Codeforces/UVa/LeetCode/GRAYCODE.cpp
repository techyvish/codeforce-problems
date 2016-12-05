//
// Created by Vishal Patel on 12/6/16.
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

int convert(string& str)
{
    int sum = 0 ;
    for ( int i = str.size() - 1 , j = 0  ; i >= 0 ; i-- , j++)
    {
        sum += ( pow ( 2 , j) * (str[i] - 48) );
    }
    return sum;
}

void compute(int n,int l, vector<int> &res, string &str)
{
    if ( n == l )
    {
        res.push_back(convert(str));
        return;
    }

    for ( int i = 0 ; i < 2 ; i ++ )
    {
        str[l] = (i % 2 == 0 ? '1' : '0') ;//l % 2 == 0 ?  (i % 2 == 0 ? '1' : '0') : (i % 2 == 0 ? '0' : '1');
        compute(n, l + 1, res,str);
    }
}

vector<int> grayCode(int n) {

    vector<int> res;
    string str;
    str.resize(n);
    compute(n, 0 ,res,str);
    return res;
}


int main() {

    fstream fin("../LeetCode/GRAYCODE.txt");

    vector<int> nums;
    int n ;
    fin >>  n;

    grayCode(n);

    return 0 ;
}


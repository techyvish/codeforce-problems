//
// Created by Vishal Patel on 11/29/16.
//


#include <fstream>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <stack>

using namespace std;
#define fin cin

void permute(string &s,int l,int r )
{
    if ( l == r )
    {
        cout << s << endl;
        return;
    }

    for ( int i = l ; i < s.length() ; i ++ )
    {
        char temp = s[i];
        s[i] = s[l];
        s[l] = temp;

        permute(s,l+1,r);

        temp = s[i];
        s[i] = s[l];
        s[l] = temp;

    }

}

int main() {

    int n, t, tc;
    string str;
    fstream fin("../LeetCode/LETTERCOMBO.txt");

    fin >> str;

    permute(str, 0 ,str.length() - 1);

    printf("\n");
    return 0 ;
}

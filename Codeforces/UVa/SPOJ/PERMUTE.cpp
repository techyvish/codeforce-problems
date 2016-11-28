//
// Created by Vishal Patel on 11/26/16.
//

#include <fstream>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <stack>

using namespace std;
#define fin cin


// running time of the algorithm will be O(N * N!)
// N = for printing string
// N! = we permute string by N-1 * N-2 ... till N

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
        // backtracking requires to restore string in original configuration
        // as we passed string by reference, if we copy string we don't need above step.
    }

}

//void recurse(int l, int r  )
//{
//
//    if ( l == 2  )
//    {
//        return;
//    }
//
//    for ( int i = l ; i < 3 ; i ++ )
//    {
//        printf ( "%d \n", i  );
//        recurse( l + 1, r);
//    }
//}

int main() {

    int n, t, tc;
    string str;
    fstream fin("../SPOJ/PERMUTE.txt");

    fin >> str;

    permute(str, 0 ,str.length() - 1);

    //recurse(0,2);
    printf("\n");
    return 0 ;
}

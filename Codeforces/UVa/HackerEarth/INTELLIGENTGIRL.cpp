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
    //fstream fin("../HackerEarth/INTELLIGENTGIRL.txt");
    ios::sync_with_stdio(false);cin.tie(0);

    string s;
    fin >>  s;

    reverse(s.begin(),s.end());
    int *a = new int[s.length()];
    int i = 0;
    for ( const char* p = s.c_str() ; *p != '\0' ; ++p , i++ ) {
        if ( (*p - '0') % 2 == 0) {
            if ( i == 0 ) {
                a[i] = 1;
            } else {
                a[i] = a[i-1] + 1;
            }
        }else {
            a[i] = a[i-1];
        }
    }

    for (  int i = s.length() - 1 ; i >= 0 ; i -- ){
        cout << a[i] << endl;
    }
}
//
// Created by Vishal Patel on 11/26/16.
//

#include <fstream>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <stack>
#include <map>

using namespace std;
#define fin cin

int main() {

    fstream fin("../SPOJ/LIFEUNIVERSE.txt");
    int n = 0;

    while ( true  ) {
        fin >> n;

        if ( n == 42 )
            break;

        cout << n << endl;
    }


}



//
// Created by Vishal Patel on 7/17/16.
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

    fstream fin("../HackerEarth/Comrades2.txt");
    u_long n, t, tc;

    fin >> tc;

    while ( tc-- ) {

        //long long a[1000000];
        map<string,int> m;

        fin >> n;
        vector<int> a(n);
        for (int i = 1; i <= n; i++) {
            fin >> a[i];
            //m[a[i]] = 0;
        }

        for (int i = 1; i <= n; i++) {
            if ( a[i] > 0 ) {
                int d = a[i];
                int p = a[d];
                char e[256];
                sprintf(e,"%d-%d",p,d);
                int c = m[e];
                m[e] = (c+=1);
            }
        }

        long long  handshakes = 0;
        long long  feastbumps = 0;

        for (auto it : m) { // calls a_map.begin() and a_map.end()
            handshakes += it.second ;
            feastbumps += it.second ? ((it.second-1) * (it.second))/2 :0;
        }


        cout << handshakes << " " << feastbumps << endl;
    }

    return 0;
}

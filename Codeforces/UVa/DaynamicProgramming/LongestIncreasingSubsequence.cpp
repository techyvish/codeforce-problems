//
// Created by Vishal Patel on 8/12/17.
//

#include "iostream"
using namespace std;

int main() {

    int n = 7;
    int a[7] = {3,4,-1,0,6,2,3};
    int k[7] = {1,1, 1,1,1,1,1};

    int i=1,j=0;

    for ( i = 1 ; i < n ; ){
        for ( j = 0 ; j < i ; j ++){
            if ( a[i] >= a[j]) {
                if (k[i] < k[j]+1 ){
                    k[i] = k[j]+1;
                }
            }
        }
        i++;
    }

    cout << "length of LIS : " << k[6];

    return 0;
}
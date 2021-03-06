//
//  272Bnew.cpp
//  Codeforces
//
//  Created by Vishal Patel on 17/10/2014.
//  Copyright (c) 2014 Vishal Patel. All rights reserved.
//

#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
long long fact(long long n)
{
    long long f = 1;
    for ( long long i = 1 ; i <= n ; i++)
        f *= i;
    return f;
}
/*
int main()
{
    //FILE *fp = freopen("/Users/Shared/codeforces/codeforces/272/B.txt", "rt", stdin);
    //fstream fin("/Users/Shared/codeforces/codeforces/272/A.txt");
    long long persons,teams;
    long long a[1000000] = {0};
    scanf("%lld %lld", &persons,&teams);
    
    long long k = 0;
    for ( long long i = 0 ; i < persons ; i++ )
    {
        for ( long long j = 0 ; j < teams ; j++ )
        {
            if ( k < persons )
            {
                a[j] += 1;
                k++;
            }
            else
            {
                break;
            }
        }
    }
    
    sort ( a, a+teams);
    
    long long minperson = 0;
    long long count  = 0;
    long long minpair = 0;
    for (long long   i = 0 ; i < teams ; i++ )
    {
        if (a[i] >= 2 ) {
            minpair = a[i];
            break;
        }
    }

    for (long long   i = 0 ; i < teams ; i++ )
    {
        if ( a[i] == minpair )
        {

            minperson = a[i];
            count ++;
        }
        
        if ( a[i] >= 2 && a[i] > minperson  )
        {
            break;
        }
    }
    
    long long min = fact(minperson) / (fact(minperson-2) * 2);
    cout << min * count << " ";
    long long  maxpersons = persons - (teams-1);
    long long max = fact(maxpersons) / (fact(maxpersons-2) * 2);
    cout << max << endl;
    
}*/
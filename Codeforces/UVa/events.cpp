//
//  events.cpp
//  Codeforces
//
//  Created by Vishal Patel on 2/28/15.
//  Copyright (c) 2015 Vishal Patel. All rights reserved.
//

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Complete the function below.
 */
int getWinner(vector < int > events) {
    
    
    sort(events.begin(), events.end(), std::greater<int>());
    
    map<int,int> m;
    for ( int i = 0 ; i < events.size() ; i++ )
    {
        int p = m[events[i]];
        p ++;
        m[events[i]] = p;
    }
    
    int max = 0;
    int item = 0;
    for (auto it = m.begin(); it  != m.end() ; it++ ) {
        
        if ( it->second == max )
        {
            if ( item < it->first )
                item = it->first;
        }
        
        if ( it->second > max  )
        {
            max = it->second ;
            item = it->first;
        }
    }
    
    return item;
}



int main() {
    ofstream fout("/Users/vishal/Cerebro/codeforce-problems/Codeforces/UVa/eventsout.txt");
    int res;
    
    fstream cin("/Users/vishal/Cerebro/codeforce-problems/Codeforces/UVa/events.txt");
    
    
    int _events_size;
    cin >> _events_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _events;
    int _events_item;
    for(int _events_i=0; _events_i<_events_size; _events_i++) {
        cin >> _events_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _events.push_back(_events_item);
    }
    
    res = getWinner(_events);
    fout << res << endl;
    
    fout.close();
    return 0;
}

//
//  testsrm.cpp
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


struct greaterNumber : public std::binary_function<string,string,bool>
{
    inline bool operator()(const string& a, const string& b)
    {
        unsigned long na = 0,nb = 0;
        stringstream ss1;
        ss1 << a;
        ss1 >> na ;
        stringstream ss2;
        ss2 << b ;
        ss2 >> nb;
        //cout << na << "  ,  " << nb << endl;
        if ( na == nb )
        {
            return b.length() > a.length();
        }
        return  nb > na ;
        
        //return a > b;
    }
};



vector <string> findAll(vector < string > String) {
    
    int n = String.size();
    vector<string> numList;
    vector<string > aVector(n);
    aVector.push_back("TEST");
    for ( int j = 0 ; j < n ; j ++ )
    {
        int i = 0 ;
        string numString ;
        
        
        string str = String[j];
        while ( str[i] != '\n' ) {
            if  (str[i]- '0' >= 0 && str[i] - '0' <= 9 )
            {
                numString += str[i];
            }
            else
            {
                if ( numString !=  "")
                {
                    numList.push_back(numString);
                    numString = "";
                }
            }
            if ( i == str.length() )
                break;
            
            i++;
        }
    }
    
    
    sort(numList.begin(), numList.end(),  greaterNumber());

    if ( numList.size() )
    {
        if ( numList.size() /2  != 0 )
        {
            vector<string> v2;
            
            int  i =  0 ;
            i =  numList.size() / 2;
            for ( ; i  <  (int)numList.size() ; i++ )
            {
                v2.push_back(numList[i]);
            }
            return v2;
        }
        else
        {
            
            vector<string> v2;
            
            int  i =  0 ;
            i =  numList.size() -1 / 2;
            for ( ; i  <  (int)numList.size() ; i++ )
            {
                v2.push_back(numList[i]);
            }
            return v2;


        }
    }
    return vector<string>();
}
int main_teststr() {
    ofstream fout("/Users/vishal/Cerebro/codeforce-problems/Codeforces/UVa/SRM220out.txt");
    vector < string > res;
    
    fstream cin("/Users/vishal/Cerebro/codeforce-problems/Codeforces/UVa/SRM220.txt");
    
    int _String_size;
    cin >> _String_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<string> _String;
    string _String_item;
    
    for(int _String_i=0; _String_i<_String_size; _String_i++) {
        getline(cin, _String_item);
        _String.push_back(_String_item);
    }
    
    res = findAll(_String);
    for(int res_i=0; res_i < res.size(); res_i++) {
        fout << res[res_i] << endl;;
    }
    
    fout.close();
    return 0;
}
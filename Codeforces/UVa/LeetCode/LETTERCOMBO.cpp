////
//// Created by Vishal Patel on 11/29/16.
////
//
//
//#include <fstream>
//#include <vector>
//#include <queue>
//#include <iostream>
//#include <cmath>
//#include <stack>
//#include <map>
//#include <algorithm>
//#include <string>
//#include <iostream>
//#include <cctype>
//
//using namespace std;
//#define fin cin
//
//
//void permute(string &s , int l , int noOfLoops , int noOfIteration,  map<char,vector<char> > &amap, string &res, vector<string> &result)
//{
//    if ( l == noOfLoops )
//    {
//        string k = res;
//        k.erase(remove_if(k.begin(), k.end(), ::isspace), k.end());
//        if ( k.length() == s.length() )
//            result.push_back(k);
//        return;
//    }
//
//    for ( int i = 0  ; i < noOfIteration ; i ++ )
//    {
//        res[l] = amap[s[l]][i];
//        permute(s,l+1,noOfLoops,noOfIteration,amap,res,result);
//    }
//}
//
//int main() {
//
//
//    int n, t, tc;
//    string str;
//
//    fstream fin("../LeetCode/LETTERCOMBO.txt");
//
//    fin >> str;
//
//    string res;
//
//    map<char,vector<char> > amap;
//    amap['2'] = vector<char> {'a','b','c',' '};
//    amap['3'] = vector<char> {'d','e','f',' '};
//    amap['4'] = vector<char> {'g','h','i',' '};
//    amap['5'] = vector<char> {'j','k','l',' '};
//    amap['6'] = vector<char> {'m','n','o',' '};
//    amap['7'] = vector<char> {'p','q','r','s'};
//    amap['8'] = vector<char> {'t','u','v',' '};
//    amap['9'] = vector<char> {'w','x','y','z'};
//
//    res.resize(str.length());
//    vector<string> result;
//    permute(str, 0 , str.length() , 4 , amap , res , result);
//
//    return 0 ;
//}




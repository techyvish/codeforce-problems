//
//  main.cpp
//  Codeforces
//
//  Created by Vishal Patel on 9/09/2014.
//  Copyright (c) 2014 Vishal Patel. All rights reserved.
//

#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <unistd.h>
#include <climits>
#include <list>
#include <string>
#include <map>
#include <set>
#include <iostream>

using namespace std;

class Pelisection17E {
public:
    int getCrossingPairs(int number, string input) {
      
//        int n = (int)input.size();
//        std::vector<int> v(n);
//        std::fill(v.begin() + n - (n/2), v.end(), 1);
//        do {
//            for (int i = 0; i < n; ++i) {
//                if (v[i]) {
//                    cout << input[i] << " ";
//                }
//                else
//                {
//                    cout << "_ ";
//                }
//            }
//            cout << endl;
//
//        } while (std::next_permutation(v.begin(), v.end()));
        
        vector<vector<int> > final;
        for ( int i = 0 ; i < input.size(); i++)
        {
            for ( int j = i ; j < input.size() ; j++ )
            {
                if ( isPalindrom(i, j, input) )
                {
                    vector<int> v ;
                    v.push_back(i+1);
                    v.push_back(j+1);
                    final.push_back(v);
                }
            }
        }
        
        int count = 0 ;
        for ( int i = 0 ; i < final.size() ; i++ )
        {
            vector<int> item = final[i];
           
            for (int  j = i+1 ; j < final.size() ; j ++ )
            {
                vector<int> checkInItems = final[j];
                if ( ( item[0] >= checkInItems[0] && item[0] <= checkInItems[1] ) ||
                     ( item[1] >= checkInItems[0] && item[0] <= checkInItems[1] ))
                {
                    count ++;
                }
            }
        }
        
        return count;
    }
    
    
    bool isPalindrom(int i , int j , string s )
    {
        if ( j == i - 1 )
            return true;
        
        if ( i == j )
            return true;
        if ( s[i] == s[j] )
            return isPalindrom(i+1, j-1,s);
        else
            return false;
    }
};

//// CUT begin
//ifstream data("/Users/Shared/codeforces/codeforces/input.txt");
//
//string next_line() {
//    string s;
//    getline(data, s);
//    return s;
//}
//
//template <typename T> void from_stream(T &t) {
//    stringstream ss(next_line());
//    ss >> t;
//}
//
//void from_stream(string &s) {
//    s = next_line();
//}
//
//template <typename T> void from_stream(vector<T> &ts) {
//    int len;
//    from_stream(len);
//    ts.clear();
//    for (int i = 0; i < len; ++i) {
//        T t;
//        from_stream(t);
//        ts.push_back(t);
//    }
//}
//
//template <typename T>
//string to_string(T t) {
//    stringstream s;
//    s << t;
//    return s.str();
//}
//
//string to_string(string t) {
//    return "\"" + t + "\"";
//}
//
//bool double_equal(const double &a, const double &b) { return b==b && a==a && fabs(b - a) <= 1e-9 * max(1.0, fabs(a) ); }
//
//bool do_test(int number,string input,int __answer) {
//    Pelisection17E *instance = new Pelisection17E();
//    int __result = instance->getCrossingPairs(number, input);
//    delete instance;
//    if (__answer == __result ) {
//        cout << "PASSED!" << endl;
//        return true;
//    }
//    else {
//        cout << "FAILED!" << endl;
//        cout << "           Expected: " << to_string(__answer) << endl;
//        cout << "           Received: " << to_string(__result) << endl;
//        return false;
//    }
//    return true;
//}
//int run_test(bool mainProcess, const set<int> &case_set, const string command) {
//    int cases = 0, passed = 0;
//    // skip first four lines.
//    next_line();
//    next_line();
//    next_line();
//    next_line();
//    while (true) {
//        if (next_line().find("input") != 0)
//            break;
//        //start writing here
//        int number;
//        from_stream(number);
//        string input;
//        from_stream(input);
//        next_line();
//        int __answer;
//        from_stream(__answer);
//        cases++;
//        cout << "  Testcase #" << cases - 1 << " ... ";
//        if( do_test(number,input,__answer)) {
//            passed++;
//        }
//        //end writing here
//    }
//    return 0;
//}
//
////std::string trim(std::string const& str)
////{
////    std::size_t first = str.find_first_not_of(' ');
////    std::size_t last  = str.find_last_not_of(' ');
////    return str.substr(first, last-first+1);
////}
//
//template <typename T>
//void getUserInput(T &input_var) {
//    while (true)
//    {
//
//        if (std::cin >> input_var)
//            break;
//        else if (std::cin.eof())
//            exit(EXIT_FAILURE);
//    }
//}
//
//string getStringInput()
//{
//    string s = "";
//    while (std::getline(std::cin, s, '\n')) {
//        if ( s != "")
//            break;
//    }
//    return s;
//}
//
//int main(int argc, char *argv[]) {
//    cout.setf(ios::fixed, ios::floatfield);
//    cout.precision(2);
//    set<int> cases;
//    bool mainProcess = true;
//    for (int i = 1; i < argc; ++i) {
//        if ( string(argv[i]) == "-") {
//            mainProcess = false;
//        } else {
//            cases.insert(atoi(argv[i]));
//        }
//    }
//    //cout << "Start testing" << endl << endl << endl;
//    //return run_test(mainProcess, cases, argv[0]);
//    //start input for on line judge
//    int number ;
//    cin >> number ;
//    string input = getStringInput();
//        //calling class
//    Pelisection17E *instance = new Pelisection17E() ;
//    int __result = instance->getCrossingPairs(number, input);
//    cout << __result ;
//    delete instance;
//    //end input for on line judge
//}

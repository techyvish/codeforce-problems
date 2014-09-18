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

class PinProblem {
public:
    
    std::vector<std::string> split(std::string s) {
        std::stringstream A(s);
        std::vector<std::string> res;
        std::string t;
        while (A>>t) res.push_back(t);
        return res;
    }
    
    vector<long> getIntVectorFromString(string input)
    {
        vector<string> s1 = split(input);
        vector<long> b;
        for (int i = 0 ; i < s1.size() ; i++ )
        {
            long c ;
            stringstream buffer(s1[i]);
            buffer >> c;
            b.push_back(c);
        }
        return b;
    }
    
    long getPin(string input1, string input2) {
        
        vector<long> a = getIntVectorFromString(input1);
        vector<long> b = getIntVectorFromString(input2);
        long  n = a[0];
        long m = a[1];
        
        long total = 0;
        for ( long long i = 1 ; i <= n ; i++ )
        {
            int count = 0;
            for (long j = 0 ; j < m ; j++)
            {
                if ( i % b[j] == 0 )
                    count ++;
            }
            if (count == m )
                total++;
        }
        
        return total;
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
//bool do_test(string input1,string input2,int __answer) {
//    PinProblem *instance = new PinProblem();
//    long __result = instance->getPin(input1, input2);
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
//        string input1;
//        from_stream(input1);
//        string input2;
//        from_stream(input2);
//        next_line();
//        int __answer;
//        from_stream(__answer);
//        cases++;
//        cout << "  Testcase #" << cases - 1 << " ... ";
//        if( do_test(input1,input2,__answer)) {
//            passed++;
//        }
//        //end writing here
//    }
//    return 0;
//}

//std::string trim(std::string const& str)
//{
//    std::size_t first = str.find_first_not_of(' ');
//    std::size_t last  = str.find_last_not_of(' ');
//    return str.substr(first, last-first+1);
//}

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
//    int testcases = 0;
//    cin >> testcases;
//    vector<string> s1;
//    vector<string> s2;
//    for ( int i = 0 ;  i < testcases ; i++ )
//    {
//        string input1 = getStringInput();
//        s1.push_back(input1);
//        string input2 = getStringInput();
//        s2.push_back(input2);
//    }
//        //calling class
//    for ( int i = 0 ; i < testcases ; i++)
//    {
//    PinProblem *instance = new PinProblem() ;
//    string input1 = s1[i];
//    string input2 = s2[i];
//    long __result = instance->getPin(input1, input2);
//    cout << __result << endl;
//    delete instance;
//    }
//    //end input for on line judge
//}

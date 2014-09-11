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

class Joke {
public:
    string amusingJoke(vector<string> input) {
        
        string a = input[0];
        string b = input[1];
        string c = input[2];
        string ab = a + b;
        sort(ab.begin(), ab.end());
        sort(c.begin(), c.end());
        
        if ( ab == c )
            return "YES";
        else
            return "NO";
    }
};
// CUT begin
ifstream data("/Users/Shared/Codeforces/Codeforces/input.txt");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool double_equal(const double &a, const double &b) { return b==b && a==a && fabs(b - a) <= 1e-9 * max(1.0, fabs(a) ); }

bool do_test(vector<string> input,string __answer) {
    Joke *instance = new Joke();
    string __result = instance->amusingJoke(input);
    delete instance;
    if (__answer == __result ) {
        cout << "PASSED!" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << endl;
        cout << "           Expected: " << to_string(__answer) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
    return true;
}
int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    // skip first four lines.
    next_line();
    next_line();
    next_line();
    next_line();
    while (true) {
        if (next_line().find("input") != 0)
            break;
        //start writing here
        vector<string> input;
        from_stream(input);
        next_line();
        string __answer;
        from_stream(__answer);
        cases++;
        cout << "  Testcase #" << cases - 1 << " ... ";
        if( do_test(input,__answer)) {
            passed++;
        }
        //end writing here
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
//    cout << "Start testing" << endl << endl << endl;
    //return run_test(mainProcess, cases, argv[0]);
    //start input for on line judge
//    cout << "enter no of elements :";
//    int size_input ;
//    cin >> size_input ;
    vector<string> input ;
//    cin.clear() ;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for ( int i = 0 ; i < 3 ; i++ ) {
        //cout << "enter " << i << "th string :";
        string  input_var ;
        cin.clear();
        getline(cin, input_var) ;
        input.push_back( input_var ) ;
        cin.clear();
    }
    //calling class
    Joke *instance = new Joke() ;
    cout << instance->amusingJoke(input);
    delete instance;
    //end input for on line judge
}

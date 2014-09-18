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

class Pangrams {
public:
    string checkPangrams(string input1) {
        char a[500] = {0};
        transform(input1.begin(), input1.end(), input1.begin(), ::tolower);
        for ( int i = 0 ; i < input1.size() ; i++)
        {
            a[input1[i]] ++;
        }
        
        int count = 0 ;
        for ( int i = 'a' ; i <= 'z' ;i++)
        {
            if (a[i] != 0)
                count ++;
        }
        if (count == 26)
            return  "pangram";
        else
            return "not pangram";
    }
    
};
class PinProblem {
public:
    int getPin(string input1, string input2) {
        return 0;
    }
};

// CUT begin
ifstream data("/Users/Shared/codeforces/codeforces/input.txt");

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

bool do_test(string input1,string __answer) {
    Pangrams *instance = new Pangrams();
    string __result = instance->checkPangrams(input1);
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
        string input1;
        from_stream(input1);
        next_line();
        string __answer;
        from_stream(__answer);
        cases++;
        cout << "  Testcase #" << cases - 1 << " ... ";
        if( do_test(input1,__answer)) {
            passed++;
        }
        //end writing here
    }
    return 0;
}

//std::string trim(std::string const& str)
//{
//    std::size_t first = str.find_first_not_of(' ');
//    std::size_t last  = str.find_last_not_of(' ');
//    return str.substr(first, last-first+1);
//}

template <typename T>
void getUserInput(T &input_var) {
    while (true)
    {

        if (std::cin >> input_var)
            break;
        else if (std::cin.eof())
            exit(EXIT_FAILURE);
    }
}

string getStringInput()
{
    string s = "";
    while (std::getline(std::cin, s, '\n')) {
        if ( s != "")
            break;
    }
    return s;
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
    //cout << "Start testing" << endl << endl << endl;
    //return run_test(mainProcess, cases, argv[0]);
    //start input for on line judge
    string input1 = getStringInput();
        //calling class
    Pangrams *instance = new Pangrams() ;
    string __result = instance->checkPangrams(input1);
    cout << __result ;
    delete instance;
    //end input for on line judge
}

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

class MartianString149E {
public:
    int beautifulwords(string eyesequence, vector<string> words) {
        set<string> stringset;
        for ( int r = 0 ; r < eyesequence.size() ; r++ )
        {
            int n = (int)eyesequence.size();
            std::vector<bool> v(n);
            
            for (int i = 0; i < n; ++i) {
                v[i] = (i >= (n - r));
            }
            do {
                string s = "";
                for (int i = 0; i < n; ++i) {
                    if (v[i]) {
                        //cout << eyesequence[i] << " ";
                        stringstream buffer;
                        string temp;
                        buffer << eyesequence[i];
                        buffer >> temp;
                        s += temp;
                    }
                    else
                    {
                        //cout << "_ ";
                    }
                }
                //cout << endl;

                for (int i = 0 ; i < words.size() ;i++)
                {
                    if (words[i] == s)
                        stringset.insert(s);
                }
            } while (std::next_permutation(v.begin(), v.end()));
        }

        for (int i = 0 ; i < words.size() ;i++)
        {
            if (words[i] == eyesequence)
                stringset.insert(eyesequence);;
        }
        
        return (int)stringset.size();
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
//bool do_test(string eyesequence,vector<string> words,int __answer) {
//    MartianString149E *instance = new MartianString149E();
//    int __result = instance->beautifulwords(eyesequence, words);
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
//        string eyesequence;
//        from_stream(eyesequence);
//        vector<string> words;
//        from_stream(words);
//        next_line();
//        int __answer;
//        from_stream(__answer);
//        cases++;
//        cout << "  Testcase #" << cases - 1 << " ... ";
//        if( do_test(eyesequence,words,__answer)) {
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
//    cout << "Start testing" << endl << endl << endl;
//    return run_test(mainProcess, cases, argv[0]);
//    //start input for on line judge
//    string eyesequence = getStringInput();
//    //cout << "enter no of elements :";
//    int size_words ;
//    getUserInput(size_words);
//    vector<string> words ;
//    for ( int i = 0 ; i < size_words ; i++ ) {
//        //cout << "enter " << i << "th string :";
//        string input_var = getStringInput();;
//        words.push_back( input_var ) ;
//    }
//        //calling class
//    MartianString149E *instance = new MartianString149E() ;
//    int __result = instance->beautifulwords(eyesequence, words);
//    cout << __result ;
//    delete instance;
//    //end input for on line judge
//}

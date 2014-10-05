
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


struct MyComparator
{
    const vector<int> & value_vector;
    
    MyComparator(const vector<int> & val_vec):
    value_vector(val_vec) {}
    
    bool operator()(int i1, int i2)
    {
        return value_vector[i1] < value_vector[i2];
    }
};

class MuhAndImportantThingsB {
    
    vector<int> order;
    vector<int> diff;
    
    bool comp (int a, int b)
    {
        return  diff[a] < diff[b];
    }
    
    std::vector<std::string> split(std::string s) {
        std::stringstream A(s);
        std::vector<std::string> res;
        std::string t;
        while (A>>t) res.push_back(t);
        return res;
    }
    
    vector<int> getIntVectorFromString(string input)
    {
        vector<string> s1 = split(input);
        vector<int> b;
        for (int i = 0 ; i < s1.size() ; i++ )
        {
            int c ;
            stringstream buffer(s1[i]);
            buffer >> c;
            b.push_back(c);
            order.push_back(i);
        }
        return b;
    }
    
    
    struct sortstruct
    {
        MuhAndImportantThingsB *m;
        sortstruct(MuhAndImportantThingsB *p): m(p){};
        
        bool operator()( int a , int b )
        {
            return ( m->diff[a] < m->diff[b] );
        }
        
        
    };
    
public:

    vector<int> getPlans(int tasks, string difficulty) {
        map<int,int> ma;
        int ok = 0;
        diff = getIntVectorFromString(difficulty);
        
        // sort one vector based on another;
//        vector<int> b;
//        for ( int i = 0 ; i < diff.size() ; i++ )
//        {
//            b.push_back(i+1);
//        }
//        sort(b.begin(), b.end(), MyComparator(diff));
        
        for ( int i = 0 ; i < diff.size() ; i++ )
        {
            ma[diff[i]] ++;
            if ( ma[diff[i]] >= 2)
                ok++;
        }
        
        if ( ok <= 1 )
            cout << "NO";
        
        
        cout << "YES\n";
        sortstruct s(this);
        sort(order.begin(),order.end(),s);
        for(int x: order) {
            cout << x + 1 << " ";
        }
        cout << "\n";
        int cnt = 0;
        
        for(int i = 0; i + 1 < diff.size(); ++i) {
            if(diff[order[i]] == diff[order[i + 1]]) {
                ++cnt;
                swap(order[i], order[i + 1]);
                for(int x: order) {
                    cout << x + 1 << " ";
                }
                cout << "\n";
                if(cnt == 2) {
                    break;
                }
            }
        }
        cout << endl;
        return vector<int>();
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
//    s << &t;
//    return s.str();
//}
//
//string to_string(string t) {
//    return "\"" + t + "\"";
//}
//
//bool double_equal(const double &a, const double &b) { return b==b && a==a && fabs(b - a) <= 1e-9 * max(1.0, fabs(a) ); }
//
//bool do_test(int tasks,string difficulty,vector<int> __answer) {
//    MuhAndImportantThingsB *instance = new MuhAndImportantThingsB();
//    vector<int> __result = instance->getPlans(tasks, difficulty);
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
//        int tasks;
//        from_stream(tasks);
//        string difficulty;
//        from_stream(difficulty);
//        next_line();
//        vector<int> __answer;
//        from_stream(__answer);
//        cases++;
//        cout << "  Testcase #" << cases - 1 << " ... ";
//        if( do_test(tasks,difficulty,__answer)) {
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
//    int tasks ;
//    cin >> tasks ;
//    string difficulty = getStringInput();
//        //calling class
//    MuhAndImportantThingsB *instance = new MuhAndImportantThingsB() ;
//    vector<int> __result = instance->getPlans(tasks, difficulty);
//    //cout << __result ;
//    delete instance;
//    //end input for on line judge
//
//}

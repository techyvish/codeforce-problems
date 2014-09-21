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
#define NMAX 50

class Game24 {
public:
    
    bool finished = false;
    
    bool is_a_solution(int a[],int k, int n)
    {
        return ( k == n - 1 );
    }
    
    void process_solution(int a[],int k , int n)
    {
        
    }
    
    void construct_candidates(int a[],int k, int n, int c[], int *ncandidates)
    {
        c[*ncandidates] = '*';
        c[*ncandidates+1] = '+';
        c[*ncandidates+2] = '-';
        *ncandidates = *ncandidates + 3;
    }
    
    void backtrack(int a[],int k , int  n)
    {
        int c[4] = {0};
        int ncandidates =0;
        int i ;
        
        if ( is_a_solution(a,k,n))
            process_solution(a,k,n);
        else
        {
            k = k+2;
            construct_candidates(a,k,n,c,&ncandidates);
            for ( i = 0 ; i < ncandidates ; i++ )
            {
                //a[k] = c[i];
                backtrack(a,k,n);
                if ( finished )
                    return;
            }
        }
    }
    
    void startit(int n )
    {
        int a[NMAX] = {0};  /* solution vector */
        int k = 0;
        for ( int i = n ; i > 0 ; i-- )
        {
            a[k++] = i;
        }
        backtrack(a,-1,n);
    }
    string makeTwentyFour(int num) {
        startit(num);
        return " ";
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

bool do_test(int num,string __answer) {
    Game24 *instance = new Game24();
    string __result = instance->makeTwentyFour(num);
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
        int num;
        from_stream(num);
        next_line();
        string __answer;
        from_stream(__answer);
        cases++;
        cout << "  Testcase #" << cases - 1 << " ... ";
        if( do_test(num,__answer)) {
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
    cout << "Start testing" << endl << endl << endl;
    return run_test(mainProcess, cases, argv[0]);
    //start input for on line judge
    int num ;
    cin >> num ;
        //calling class
    Game24 *instance = new Game24() ;
    string __result = instance->makeTwentyFour(num);
    cout << __result ;
    delete instance;
    //end input for on line judge
}

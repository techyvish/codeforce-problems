//
// Created by Vishal Patel on 7/13/16.
//

#include <fstream>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <stack>

using namespace std;
#define fin cin

bool  isMathingPair(char opening,char closing) {

    if ( opening == '(' && closing == ')' )return true;
    if ( opening == '[' && closing == ']' )return true;
    if ( opening == '{' && closing == '}' )return true;
    return false;
}

bool isMatchingParanthesis(string exp) {

    stack<char> s;
    for ( int i = 0 ; i < exp.length() ; i ++ ){
        if ( exp[i] == '(' || exp[i] == '{' || exp[i] == '[' ) {
            s.push(exp[i]);
        }

        if ( exp[i] == ')' || exp[i] == '}' || exp[i] == ']' ) {
            if ( s.empty() ){
                return  false;
            }else if ( !isMathingPair(s.top(), exp[i]) ){
                return false;
            }else {
                s.pop();
            }
        }
    }

    return s.empty() ? true : false;
}

bool replaceParanthesis(string str){

}

int main() {

    int n, t, tc;
    char ch[1000000];
    fstream fin("../SPOJ/MREPLBRC.txt");

    string exp ;
    fin >> n;
    fin >> exp ;

    bool r = isMatchingParanthesis(exp);
    //for ( int i = 0 ; i < n ; i ++ ){
    //    fin >> ch[i];
    //}

    printf("\n");
    return 0 ;
}

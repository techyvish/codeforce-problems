//
// Created by Vishal Patel on 12/2/16.
//

//
// Created by Vishal Patel on 11/29/16.
//


#include <fstream>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <stack>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>
#include <cctype>

using namespace std;
#define fin cin

bool isMatching(char a , char b )
{
    return  (a == '(' && b == ')') ? true : false;
}
bool isValid(string &s) {
    stack<char> st;
    int total = 0;

    for (int i = 0 ; i < s.size(); i++)
    {
        if (s[i] == '(') {
            st.push('(');

        }

        if ( s[i] == ')')
        {
            if ( st.empty() )
                return  false;
            else if ( !isMatching(st.top() , s[i] ))
                return  false;
            else
                st.pop();
        }
    }
    return st.empty() ? true : false;
}
void generatePara(int n, int l, vector<string> &list,string &str)
{
    if ( l == n )
    {
        cout << str << endl;
        if ( isValid(str) ) {
            list.push_back(str);
        }
        return ;
    }
    for ( int i = 0 ; i < 2 ; i ++ )
    {
        str[l] = i % 2 == 0 ? '(' : ')';
        generatePara(n, l + 1, list,str);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> list;
    string str;
    str.resize( n * 2 );
    generatePara( n * 2 ,0,list,str);
    return list;
}

int main() {


    int n, t, tc;


    fstream fin("../LeetCode/GENERATEPARENTHESES.txt");

    fin >> n;
    vector<string> s = generateParenthesis(n);
    return 0 ;
}



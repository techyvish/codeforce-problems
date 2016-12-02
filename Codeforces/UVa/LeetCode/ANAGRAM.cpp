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


using namespace std;
#define fin cin



#include <fstream>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <stack>
#include <map>


using namespace std;
#define fin cin
bool isAnagram(string s, string t) {

    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    return  s == t;
}

int main() {


    fstream fin("../LeetCode/ANAGRAM.txt");
    string s, t  ;
    fin >> s;
    fin >> t ;

    bool a = isAnagram(s,t);

    printf("\n");
    return 0 ;
}

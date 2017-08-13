//
// Created by Vishal Patel on 8/13/17.
//

/*
 *



 Problem Statement for RepeatStringEasy


Problem Statement
    	A string S is called a square if there is some string T such that S = T + T. For example, the strings "",
    	aabaab" and "xxxx" are squares, but "a", "aabb" and "aabbaa" are not.

You are given a String s. Find the longest square string that can be obtained from s by erasing some (possibly none, possibly all) of its characters.
In other words, we are looking for the longest square that occurs in s as a subsequence. Return the length of that square.

Note that the answer is well-defined, as the square "" (the empty string) will always occur in s as a subsequence.

Definition

Class:	RepeatStringEasy
Method:	maximalLength
Parameters:	String
Returns:	int
Method signature:	int maximalLength(String s)
(be sure your method is public)


Constraints
-	s will contain between 1 and 50 characters, inclusive.
-	Each character in s will be a lowercase English letter ('a'-'z').

Examples
0)

"frankfurt"
Returns: 4
The longest square that occurs in "frankfurt" is "frfr". Its length is 4.
1)

"single"
Returns: 0
The letters in the string "single" are all distinct. Hence, the only square that occurs in this string is "". The length of this square is zero.
2)

"singing"
Returns: 6
3)

"aababbababbabbbbabbabb"
Returns: 18
4)

"x"
Returns: 0

 */



#include "iostream"
#include "vector"
using namespace std;

int main() {

    int n = 7;
    string s = "aababbababbabbbbabbabb";
    int i=1,j=0;
    int c = 0;
    for ( i = 1 ; i < s.length() ; ){
        for ( j = 0 ; j < i ; j ++){
            if ( s[i] == s[j]) {
                c++;
            }
        }
        i++;
    }

    cout << c * 2 ;

    return 0;
}
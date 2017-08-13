//
// Created by Vishal Patel on 8/12/17.
//

/*
from the end, when there are only two cards left on the table. We know that the last two cards must have indexes 0 (leftmost) and N-1 (rightmost).
 Now we try to guess which card was removed in the last turn. For each such card with index i, the score for the move is cards[i] * (cards[0] + cards[N-1]).
 Once we guess the card, we divide the original problem into two subproblems where the indexes of the leftmost and rightmost cards are:
    0 and i
    i and N-1
Solutions to these subproblems are independent of each other, so we solve them recursively and return the best answer.
 */


#include "iostream"
using namespace std;

// 2^N solution
int solve(int be, int en , int *cards){

    if ( be + 1 == en ){
        return 0;
    }

    for ( int i = be+1; i < en ; i++ ){
        int m1 = max( cards[i] * (cards[be] + cards[en]) , solve(be+1,en,cards));
        int m2 = max( cards[i] * (cards[be] + cards[en]) , solve(be,en-1,cards));
        return  max(m1,m2);
    }

}

//// N^2 solution
//int solve1(int be, int en, int year, int *a, int **cache){
//
//    if ( be == en ){
//        return a[be] * year;
//    }
//
//    if ( cache[be][en] != -1 )
//        return cache[be][en];
//
//    cache[be][en] = max( solve(be+1,en,year+1,a) + year * a[be],
//                         solve(be,en-1,year+1,a) + year * a[en]);
//
//    return cache[be][en];
//}

int main() {


//    int n;
//    cin >> n;
//    int *a = new int[n];
//    for (int i = 0 ; i < n ; i++ ){
//        cin >> a[i];
//    }
    int n = 5;
    int cards[5] = { 2, 3, 5 ,1, 4 };
    int final = solve(0,4,cards);

        int **cache = new int*[n];
    for (int i = 0; i < n ;i++ ){
        int *a  = new int[n];
        memset(a,-1,n*sizeof(int));
        cache[i]=a;
    }

    //int final1 = solve1(0,4,1,cards,cache);
    return 0;
}


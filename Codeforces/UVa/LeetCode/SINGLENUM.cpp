//
// Created by Vishal Patel on 11/26/16.
//

//
// Created by Vishal Patel on 11/25/16.
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
int singleNumber(vector<int>& nums) {
    map<int,int> m;
    for (int i = 0 ; i < nums.size() ; i ++)
    {
            m[nums[i]] ++;
    }
    for (int i = 0 ; i < nums.size() ; i ++)
    {
        if (m[nums[i]] == 1 )
            return  nums[i];
    }
    return 0;
}

int main() {

    fstream fin("../LeetCode/SINGLENUM.txt");
    int n, target;
    fin >> n;
    vector<int> nums(n);
    map<int,int> dict;
    for ( int i = 0 ; i < n ; i ++ )
    {
        fin >> nums[i];
    }


    int ans = singleNumber(nums);
    return 0;
}



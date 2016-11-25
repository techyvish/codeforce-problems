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
vector<int> twoSum(vector<int>& nums, int target) {
    for ( int i = 0  ; i < nums.size() ; i ++ )
    {
        for ( int j = i + 1 ; j < nums.size() ; j++ )
        {
            if ( nums[i] + nums[j] == target ){
                vector<int> ans ;
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
}
int main() {

    fstream fin("../LeetCode/TWOSUM.txt");
    int n, target;
    fin >> n;
    vector<int> nums(n);
    map<int,int> dict;
    for ( int i = 0 ; i < n ; i ++ )
    {
        fin >> nums[i];
    }

    fin >> target ;

    vector<int> ans = twoSum(nums,target);
    return 0;
}



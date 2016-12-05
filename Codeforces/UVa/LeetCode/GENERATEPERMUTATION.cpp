//
// Created by Vishal Patel on 12/3/16.
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

void permute1(int n, int l, vector<int> &nums, vector<vector<int> > &list)
{
    if ( n == l )
    {
        list.push_back(nums);
        return;
    }
    for ( int i = l ; i < n ; i ++ )
    {
        //str[l] = nums[i] ;

        int temp = nums[l];
        nums[l] = nums[i];
        nums[i] = temp;

        permute1(n, l + 1, nums, list);

        temp = nums[l];
        nums[l] = nums[i];
        nums[i] = temp;

    }
}

vector<vector<int>> permute(vector<int >& nums) {
    vector<vector<int>> list;
    string str;
    str.resize(nums.size());
    permute1( nums.size() ,0, nums, list );
    return list;
}

int main() {

    fstream fin("../LeetCode/GENERATEPERMUTATION.txt");

    vector<int> nums;
    int n ;
    fin >>  n;

    for (int i = 0 ; i < n ; i ++ )
    {
        int k ;
        fin >> k;
        nums.push_back(k);
    }
    vector<vector<int>> s = permute(nums);
    return 0 ;
}



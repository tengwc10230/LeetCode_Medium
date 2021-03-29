/*
Given an integer array nums, return true if 
there exists a triple of indices (i, j, k) 
such that i < j < k and nums[i] < nums[j] < nums[k]. 
If no such indices exists, return false.
*/
#include <bits/stdc++.h>

using namespace std;

bool increasingTriplet(vector<int>& nums) {
    bool ans = false;
    int first = (int)INFINITY;
    int second = (int)INFINITY;
    for(auto &p : nums){
        if(p <= first)  first = p;
        else if(p <= second)  second = p;
        else{
            ans = true;
            break;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {2,1,5,0,4,6};
    cout << increasingTriplet(nums) << endl;
}
/*
Given an array nums of n integers, are there elements 
a, b, c in nums such that a + b + c = 0? Find all unique 
triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.
*/

#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    map<int, int> num_cnt;
    for(auto &p : nums){
        num_cnt[p] ++;
    }
    if (num_cnt[0] > 0){
        if (num_cnt[0] > 2) ans.push_back({0,0,0});
        for(auto &p : num_cnt){
            if(p.first < 0 && num_cnt[-(p.first)] > 0){
                vector<int> tmp_vec = {p.first, 0, -p.first};
                ans.push_back(tmp_vec);
            } 
            if(p.first == 0)    break;
        }
    }
    
    for (auto p = num_cnt.begin(); p != num_cnt.end(); p++){
        if (p->second == 0) continue;
        if (p->first < 0){
            for(auto q = num_cnt.cbegin(); q != num_cnt.cend(); q++){
                int tmp = p->first + q->first;
                if (q->second == 0) continue;
                if (q->first > 0 && tmp < 0) {
                    if (-tmp == q->first && q->second > 1)
                    {
                        vector<int> tmp_vec = {p->first, q->first, q->first};
                        ans.push_back(tmp_vec);
                        break;
                    }
                    else if (-tmp != q->first && num_cnt[-tmp] > 0 && q->first < -tmp){
                        vector<int> tmp_vec = {p->first, q->first, -tmp};
                        ans.push_back(tmp_vec);
                    }  
                    if (q->first > -tmp)    break;          
                }
            }
        }
        else if (p->first > 0){
            for(auto q = num_cnt.begin(); q != num_cnt.end(); q ++){
                if (q->second == 0) continue;
                if (q->first >= 0)   break;
                else {
                    int tmp = p->first + q->first;
                    if (tmp > 0){
                        if (-tmp == q->first && q->second > 1){
                            vector<int> tmp_vec = {q->first, q->first, p->first};
                            ans.push_back(tmp_vec);
                        }
                        else if(-tmp != q->first && num_cnt[-tmp] > 0 && q->first < -tmp){
                            vector<int> tmp_vec = {q->first, -tmp, p->first};
                            ans.push_back(tmp_vec);
                        }
                        if (q->first > -tmp)    break;  
                    }
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main(){
    vector<int> nums = {1,1,-2};
    vector<vector<int>> output = threeSum(nums);
    for (auto &p : output){
        for (auto &i : p){
            cout << i << " ";
        }
        cout << endl;
    }
}
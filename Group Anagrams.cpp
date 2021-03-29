/*
Given an array of strings strs, group the anagrams together. 
You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters 
of a different word or phrase, typically using all the original 
letters exactly once.

*/
#include <bits/stdc++.h>

using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> outputs;
    vector<string> str_sort = strs;
    bool str_used[strs.size()] = {false};
    for (int i = 0; i < strs.size(); i ++){
        sort(str_sort[i].begin(), str_sort[i].end());
    }
    map<string, vector<int>> pos_map;
    for (int i = 0; i < str_sort.size(); i ++){
        pos_map[str_sort[i]].push_back(i);
    }
    for(auto &v_p:pos_map){
        vector<string> same_str;
        for(auto &p:v_p.second){
            same_str.push_back(strs[p]);
        }
        outputs.push_back(same_str);
    }
    return outputs;
}

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> outputs = groupAnagrams(strs);
    
    for(auto &v_p : outputs){
        for(auto &p : v_p){
            cout << p << " ";
        }
        cout<<endl;
    }
    
}
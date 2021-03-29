/*
A string s is called good if there are no two different 
characters in s that have the same frequency.

Given a string s, return the minimum number of characters
 you need to delete to make s good.

The frequency of a character in a string is the number of 
times it appears in the string. For example, in the string 
"aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.
*/

#include <bits/stdc++.h>

using namespace std;
int minDeletions(string s) {
    int ans = 0;
    int letter[26] = {0};
    map<int, int> cnt;
    for(auto &c : s){
        letter[c-97] ++;
    }
    for (auto &p : letter){
        while(cnt[p] != 0 && p > 0){
            p --;
            ans ++;
        }
        if (p > 0)    cnt[p] ++;
    }
    return ans;
}
int main(){
    string s = "ceabaacb";
    cout << minDeletions(s) << endl;
}
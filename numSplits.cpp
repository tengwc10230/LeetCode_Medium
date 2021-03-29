/*
You are given a string s, a split is called good 
if you can split s into 2 non-empty strings p and 
q where its concatenation is equal to s and the 
number of distinct letters in p and q are the same.

Return the number of good splits you can make in s.
*/
#include <bits/stdc++.h>

using namespace std;
int numSplits(string s) {
    int ans = 0, cnt = 0;
    int letter[26] = {0};
    int distinct_p[s.size()];
    int distinct_q[s.size()];
    for (int i = 0; i < s.size(); i ++){
        if (letter[s[i]-97] == 0){
            letter[s[i]-97] ++;
            distinct_p[i] = ++cnt;
        }
        distinct_p[i] = cnt;
    } 
    for (int i = 0; i < 26; i ++)   letter[i] = 0;
    cnt = 0;
    for (int i = s.size()-1; i >= 0; i --){
        if (letter[s[i]-97] == 0){
            letter[s[i]-97] ++;
            distinct_q[i] = ++cnt;
        }
        distinct_q[i] = cnt;
    }

    for (int i = 0; i < s.size() - 1; i ++){
        if (distinct_p[i] == distinct_q[i+1])   ans ++;
    }
    return ans;
}
int main(){
    string s = "aacaba";
    cout << numSplits(s) << endl;
}
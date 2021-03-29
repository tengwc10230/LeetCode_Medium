/*
2021/03/20 
Given an m x n matrix. If an element is 0, set its entire row
and column to 0. Do it in-place.

Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
#include <bits/stdc++.h>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    //use last row to solve 0 col <- 浪費時間 改用其他row存time complexity 低
    int last_row = -1;
    for(int i = matrix.size()-1; i >= 0 && last_row == -1; i --){
        for(int j = 0; j < matrix[i].size(); j ++){
            if (matrix[i][j] == 0){
                last_row = i;
                break;    
            }
        }
        
    }
    
    if (last_row == -1) return;
    for(int i = 0; i < last_row; i ++){
        bool zero_row = false;
        for(int j = 0; j < matrix[i].size(); j ++){
            if (matrix[i][j] == 0){
                zero_row = true;
                matrix[last_row][j] = 0;    
            }
        }
        for(int j = 0; j < matrix[i].size() && zero_row; j++){
            matrix[i][j] = 0;
        }
    }

    for(int i = 0; i < matrix.size(); i ++){
        for(int j = 0; j < matrix[i].size(); j ++){
            if (matrix[last_row][j] == 0){
                matrix[i][j] = 0;    
            }
        }
    }
    
    for (int j = 0; j < matrix[last_row].size(); j ++)
        matrix[last_row][j] = 0;

}
int main(){
    vector<vector<int>> matrix = {{7,8,0,5,7,7},{9,3,2,1,7,0}};
    setZeroes(matrix);
    for(auto &i : matrix){
        for(auto &j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
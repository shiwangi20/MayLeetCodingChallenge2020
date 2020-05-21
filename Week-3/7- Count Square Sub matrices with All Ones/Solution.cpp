
// Created on : 21 May, 2020

// Title : Count Square Submatrices with All Ones

// Author : Shiwangi Garg

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        int **dp = new int*[matrix.size()];
        for(int i = 0;i < matrix.size();i++){
            dp[i] = new int[matrix[i].size()];
            for(int j = 0;j < matrix[i].size();j++){
                dp[i][j] = -1;
            }
        }
        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j < matrix[0].size();j++){
                ans += getCount(matrix,dp,i,j);
            }
        }
        return ans;
    }
    int getCount(vector<vector<int>>& matrix,int **dp,int row,int col){
        if(row >= matrix.size() || col >= matrix[0].size() || matrix[row][col] == 0){
            return 0;
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int right = getCount(matrix,dp,row,col+1);
        int down = getCount(matrix,dp,row+1,col);
        int diagonal = getCount(matrix,dp,row+1,col+1);
        dp[row][col] = 1+min(right,min(down,diagonal));
        return dp[row][col];
    }
};


// Created On : 31 May, 2020

// Title : Edit Disatnce

// Author : Shiwangi Garg

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i = 1;i <= m;i++){
            dp[0][i] = dp[0][i-1] + 1;
        }
        for(int i = 1;i <= n;i++){
            dp[i][0] = dp[i-1][0] + 1;
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;
                }
            }
        }
        return dp[n][m];
    }
};

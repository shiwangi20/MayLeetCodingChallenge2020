
// Created on : 28 May, 2020

// Title : Counting Bits

// Author : Shiwangi Garg

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        ans.push_back(0);
        for(int i = 1;i <= num;i++){
            ans.push_back((i%2 + ans[i>>1]));
        }
        return ans;
    }
};

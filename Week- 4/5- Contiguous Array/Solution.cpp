
// Created on 26 May , 2020

// Title : contiguous Array

// Author : Shiwangi Garg

#include<bits/stdc++.h>
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> umap;
        int count = 0;
        int max = 0;
        for(int i = 0;i < nums.size();i++){
            count += (nums[i] == 0) ? -1 : 1;
            if(count == 0){
                max = i+1;
            }else{
                if(umap.find(count) == umap.end()){
                    umap[count] = i;
                }else{
                    int len = i - umap[count];
                    if(len > max){
                        max = len;
                    }
                }
            }
        }
        return max;
    }
};

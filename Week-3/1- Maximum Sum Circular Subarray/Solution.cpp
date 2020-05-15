
// Created on : 15 May, 2020

// Title : Maximum Sum Circular Subarray

// Author : Shiwangi Garg

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int sum = A[0];
        int max_so_far = A[0];
        int max_ending_here = A[0];
        int min_so_far = A[0];
        int min_ending_here = A[0];
        for(int i = 1;i < A.size();i++){
            sum += A[i];
            max_ending_here = max(max_ending_here + A[i],A[i]);
            max_so_far = max(max_so_far,max_ending_here);
            min_ending_here = min(min_ending_here + A[i],A[i]);
            min_so_far = min(min_ending_here,min_so_far);
        }
        if(max_so_far < 0){
            return max_so_far;
        }
        return max(max_so_far,sum-min_so_far);
    }
    int max(int a,int b){
        return a>b ? a:b;
    }
    int min(int a,int b){
        return a<b ? a:b;
    }
};

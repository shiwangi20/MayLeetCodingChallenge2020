
// Created on : 12 May, 2020

// Title : Single Element in a Sorted Array

// Author : Shiwangi Garg

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        return helper(nums,0,n-1);
    }
    int helper(vector<int>& nums,int start,int end){
        if(start == end){
            return nums[start];
        }
        int mid = (start + end)/2;
        if(mid%2 == 0){
            if(nums[mid] == nums[mid+1]){
                return helper(nums,mid+2,end);
            }else if(nums[mid] == nums[mid-1]){
                return helper(nums,start,mid-2);
            }else{
                return nums[mid];
            }
        }else{
            if(nums[mid] == nums[mid-1]){
                return helper(nums,mid+1,end);
            }else if(nums[mid] == nums[mid+1]){
                return helper(nums,start,mid-1);
            }else{
                return nums[mid];
            }
        }
    }
};

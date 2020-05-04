
// Created on : May 1,2020

// Title : First Bad Version

// Author : Shiwangi Garg


class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        return getBadVersion(start,end);
    }
    int getBadVersion(int start,int end){
        if (start > end){
            return 0;
        }
        if(start == end){
            return start;
        }
        int mid = (start/2) + (end/2) + ((start%2) + (end%2))/2;
        bool smallAns = isBadVersion(mid);
        if(smallAns){
            return getBadVersion(start,mid);
        }else{
            return getBadVersion(mid+1,end);
        }
    }
};

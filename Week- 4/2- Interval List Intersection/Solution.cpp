
// Created on 23 May, 2020

// Title : Interval List Intersections

// Author : Shiwangi Garg

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int i,j;
        i = j = 0;
        while(i < A.size() && j < B.size()){
            int a = max(A[i][0],B[j][0]);
            int b = min(A[i][1],B[j][1]);
            if(a<=b){
                vector<int> temp;
                temp.push_back(a);
                temp.push_back(b);
                ans.push_back(temp);
            }
            if(b == A[i][1]){
                i++;
            }else{
                j++;
            }
        }
        return ans;
    }
};


// Created On : 30 May, 2020

// Title : K Closest Points to Origin

// Author : Shiwangi Garg

#include<bits/stdc++.h>
class Solution {
public:
    int distance(vector<int> point){
        return pow(point[0],2) + pow(point[1],2);
    }
    bool static sortbysec(pair<int,int> a,pair<int,int> b){
        return (a.second < b.second);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = points.size();
        if(K == n){
            return points;
        }
        vector<pair<int,int>> p;
        for(int i = 0;i < n;i++){
            p.push_back({i,distance(points[i])});
        }
        sort(p.begin(),p.end(),sortbysec);
        vector<vector<int>> ans;
        for(int i = 0; i < K;i++){
            ans.push_back(points[p[i].first]);
        }
        return ans;
    }
};

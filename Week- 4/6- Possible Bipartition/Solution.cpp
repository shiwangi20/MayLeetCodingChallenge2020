
// Created on : 27 May, 2020

// Title : Possible Bipartition

// Author : Shiwangi Garg

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> adj[N+1];
        vector<int> visited(N+1,false);
        vector<int> color(N+1,0);
        for(int i = 0;i < dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        queue<int> q;
        for(int i = 1;i <= N;i++){
            if(!visited[i]){
                color[i] = 1;
                q.push(i);
                while(!q.empty()){
                    int num = q.front();
                    q.pop();
                    if(visited[num]){
                        continue;
                    }
                    visited[num] = true;
                    for(int j = 0;j < adj[num].size();j++){
                        if(color[num] == color[adj[num][j]]){
                            return false;
                        }
                        if(color[num] == 1){
                            color[adj[num][j]] = 2;
                        }else{
                            color[adj[num][j]] = 1;
                        }
                        q.push(adj[num][j]);
                    }
                }
            }
        }
        return true;
    }
};

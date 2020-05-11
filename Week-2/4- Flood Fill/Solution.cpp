
// Created on : 11 May, 2020

// Title : Flood Fill

// Author : Shiwangi Garg

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        vector<vector<bool>> visited;
        for(int i = 0;i < image.size();i++){
            vector<bool> temp;
            for(int j = 0;j < image[0].size();j++){
                temp.push_back(false);
            }
            visited.push_back(temp);
        }
        helper(image,visited,sr,sc,newColor,color);
        return image;
    }
    void helper(vector<vector<int>>& image,vector<vector<bool>>& visited,int sr,int sc,int newColor,int color){
        if(visited[sr][sc]){
            return;
        }
        visited[sr][sc] = true;
        image[sr][sc] = newColor;
        if(valid(image,sr-1,sc,color)){
            helper(image,visited,sr-1,sc,newColor,color);
        }
        if(valid(image,sr+1,sc,color)){
            helper(image,visited,sr+1,sc,newColor,color);
        }
        if(valid(image,sr,sc-1,color)){
            helper(image,visited,sr,sc-1,newColor,color);
        }
        if(valid(image,sr,sc+1,color)){
            helper(image,visited,sr,sc+1,newColor,color);
        }
    }
    bool valid(vector<vector<int>>& image,int row,int col,int color){
        int row_size = image.size();
        int col_size = image[0].size();
        return ((row>=0) && (row < row_size) && (col>=0) && (col < col_size) && (image[row][col] == color));
    }
};

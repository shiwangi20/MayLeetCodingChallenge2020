
// Created on : 29 May, 2020

// Title : Course Schedule

// Author : Shiwangi Garg

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        bool *visited = new bool[numCourses];
        bool *course = new bool[numCourses];
        memset(visited,false,numCourses);
        memset(course,false,numCourses);
        vector<int> arr[numCourses];
        for(int i = 0;i < prerequisites.size();i++){
            arr[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i = 0;i < numCourses;i++){
            if(!match(numCourses,arr,visited,course,i)){
                return false;
            }
        }
        return true;
    }
    bool match(int numCourses,vector<int> arr[numCourses],bool *visited,bool *course,int index){
        if(index >= numCourses){
            return true;
        }
        if(visited[index]){
            return course[index];
        }
        visited[index] = true;
        for(int j = 0;j < arr[index].size();j++){
            if(! match(numCourses,arr,visited,course,arr[index][j])){
                return false;
            }
        }
        course[index] = true;
        return true;
    }
};

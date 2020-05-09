
// Created on : 9 May, 2020

// Title : Valid Perfect Square

// Author : Shiwangi Garg

class Solution {
public:
    bool isPerfectSquare(int num) {
        long int i = 1;
        for(i = 1;i*i < num;i++){
            
        }
        if(i*i == num){
            return true;
        }
        else{
            return false;
        }
    }
};

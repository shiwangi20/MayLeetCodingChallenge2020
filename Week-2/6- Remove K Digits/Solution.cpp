
// Created on : 13 May, 2020

// Title : Remove K Digits

// Author : Shiwangi Garg

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length() == k){
            return "0";
        }
        for(int i = 0;i < k;i++){
            int j = 0;
            while(j < num.length()-1 && num[j] <= num[j+1]){
                j++;
            }
            num.erase(num.begin()+j);
        }
        while(num.length() > 1 && num[0] == '0'){
            num.erase(num.begin()+0);
        }
        if(num.length() == 0){
            return "0";
        }
        return num;
    }
};

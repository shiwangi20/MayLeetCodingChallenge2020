
// Created on : 18 May, 2020

// Title : Permutation In String

// Author : Shiwangi Garg

#define MAX 26
class Solution {
public:
    bool isPermutation(int pat[MAX],int str[MAX]){
        for(int i = 0;i < MAX;i++){
            if(pat[i] != str[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int plen = s1.length();
        int slen = s2.length();
        if(plen > slen){
            return false;
        }
        int pat[MAX] = {0};
        int str[MAX] = {0};
        for(int i = 0;i < plen;i++){
            pat[s1[i]-'a']++;
            str[s2[i]-'a']++;
        }
        if(isPermutation(pat,str)){
            return true;
        }
        for(int i = plen;i < slen;i++){
            str[s2[i-plen]-'a']--;
            str[s2[i]-'a']++;
            if(isPermutation(pat,str)){
                return true;
            }
        }
        return false;
    }
};

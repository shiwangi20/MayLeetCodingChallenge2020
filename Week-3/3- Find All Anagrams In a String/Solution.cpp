
// Created on : 17 May, 2020

// Title : Find All Anangrams in a String

// Author : Shiwangi Garg

#define MAX 26
class Solution {
public:
    bool compare(int pat[MAX],int str[MAX]){
        for(int i = 0;i < MAX;i++){
            if(pat[i] != str[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int slen = s.length();
        int plen = p.length();
        if(plen > slen){
            return ans;
        }
        int pat[MAX] = {0};
        int str[MAX] = {0};
        for(int i = 0;i < plen;i++){
            pat[p[i]-'a']++;
            str[s[i]-'a']++;
        }
        if(compare(pat,str)){
            ans.push_back(0);
        }
        for(int i = plen;i < slen;i++){
            str[s[i-plen]-'a']--;
            str[s[i]-'a']++;
            if(compare(pat,str)){
                ans.push_back(i-plen+1);
            }
        }
        return ans;
    }
};

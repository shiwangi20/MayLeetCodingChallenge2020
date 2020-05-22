
// Created on : 20 May, 2020

// Title : Sort Characters by Frequency

// Author : Shiwangi Garg

class Solution {
public:
    string frequencySort(string s) {
        int freq[256] = {0};
        int index[256];
        for(int i = 0;i < 256;i++){
            index[i] = i;
        }
        for(int i = 0;s[i] != '\0';i++){
            freq[s[i]]++;
        }
        sort(begin(index), end(index), 
             [&](const int a, const int b) { return freq[a]>freq[b]; });
        string ans = "";
        for(int i = 0;i < 256;i++){
            if(freq[index[i]] == 0){
                break;
            }
            ans += string(freq[index[i]],index[i]);
        }
        return ans;
    }
};

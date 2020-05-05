
// Created on :  4 May, 2020

// Title : Number Complement

// Author : Shiwangi Garg


class Solution {
public:
    int findComplement(int num) {
        int *arr = new int[32];
        int count = 0;
        int copy = num;
        while(copy > 0){
            int rem = copy%2;
            arr[count] = rem == 0 ? 1 : 0;
            copy = copy / 2;
            count++;
        }
        signed int ans = 0;
        long int p = 1;
        for(int i = 0;i < count;i++){
            ans += p * arr[i];
            p = p*2;
        }
        delete[] arr;
        return ans;
    }
};


# Created on : 5 May, 2020

# Title : First Character in a String

# Author : Shiwangi Garg

class Solution:
    def firstUniqChar(self, s: str) -> int:
        dict1 = {}
        for st in s:
            dict1[st] = dict1.get(st,0) + 1
        for i in range(len(s)):
            if dict1[s[i]] == 1:
                return i
        return -1

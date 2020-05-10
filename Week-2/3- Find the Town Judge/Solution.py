
# Created on: 10 May,2020

# Title :  Find the Town Judge

# Author : Shiwangi Garg

class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        if N == 1:
            return 1;
        dict1 = {}
        li = set()
        for fp,sp in trust:
            li.add(fp)
            if sp not in dict1:
                dict1[sp] = set()
            dict1[sp].add(fp)
        for key,value in dict1.items():
            if ((len(value) == N-1) and (key not in li)):
                return key
        return -1
        

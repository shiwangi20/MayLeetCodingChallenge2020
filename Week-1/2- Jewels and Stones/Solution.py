
# Created on : 2 May, 2020

# Title : Jewels and Stones

# Author : Shiwangi Garg


class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        count = 0
        dict1 = {}
        for i in S:
            dict1[i] = dict1.get(i,0)+1
        for i in dict1:
            if i in J:
                count += dict1[i]
        return count

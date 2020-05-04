
# Created on : 3 May, 2020

# Title : Ransom Note

# Author : Shiwangi Garg


class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        if len(ransomNote) > len(magazine):
            return False
        ransomDict = {}
        magazineDict = {}
        for st in magazine:
            magazineDict[st] = magazineDict.get(st,0) + 1
        for st in ransomNote:
            if st not in magazineDict:
                return False
            ransomDict[st] = ransomDict.get(st,0) + 1
        flag = 0
        #print(ransomDict,magazineDict)
        for key in ransomDict:
            if ransomDict[key] > magazineDict[key]:
                    return False
        return True
        

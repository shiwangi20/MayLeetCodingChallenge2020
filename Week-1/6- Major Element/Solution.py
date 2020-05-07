
# Created on : 6 May, 2020

# Title : Majority Element 

# Author : Shiwangi Garg

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        return nums[len(nums)//2]

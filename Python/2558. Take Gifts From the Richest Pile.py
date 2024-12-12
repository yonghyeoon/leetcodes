"""
Problem URL : https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/

Example 1:
Input: gifts = [25,64,9,4,100], k = 4
Output: 29

Example 2: 
Input: gifts = [1,1,1,1], k = 4
Output: 4
"""
from typing import List
from math import sqrt, floor

class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        for _ in range(k):
            max_value = max(gifts)
            max_index = gifts.index(max_value)
            gifts[max_index] = floor(sqrt(max_value))

        return sum(gifts)
    

# Example 1
gifts, k = [25,64,9,4,100], 4

# Example 2
# gifts, k = [1,1,1,1], 4

solution = Solution()
print(solution.pickGifts(gifts=gifts, k=k))

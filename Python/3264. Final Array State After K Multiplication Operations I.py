"""
Problem : https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/description/

Example 1:
Input: nums = [2,1,3,5,6], k = 5, multiplier = 2
Output: [8,4,6,5,6]

Example 2:
Input: nums = [1,2], k = 3, multiplier = 4
Output: [16,8]

"""

from typing import List

class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        for _ in range(k):
            idx = nums.index(min(nums))
            nums[idx] *= multiplier

        return nums
    

# Example 1
# nums, k, multiplier = [2,1,3,5,6], 5, 2

# Example 2
nums, k, multiplier = [1,2], 3, 4

solution = Solution()
ret = solution.getFinalState(nums, k, multiplier)
print(nums)
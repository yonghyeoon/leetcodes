"""
Problem URL : https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/
Example 1:
Input: prices = [8,4,6,2,3]
Output: [4,2,4,2,3]

Example 2:
Input: prices = [1,2,3,4,5]
Output: [1,2,3,4,5]

Example 3:
Input: prices = [10,1,1,6]
Output: [9,0,1,6] 
"""

from typing import List

class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        for i in range(len(prices) - 1):
            for j in range(i+1, len(prices)):
                if prices[i] >= prices[j]:
                    prices[i] -= prices[j]
                    break
        
        return prices
    

# Example 1
prices = [8,4,6,2,3]

# Example 2
# prices = [1,2,3,4,5]

# Example 3
# prices = [10,1,1,6]

solution = Solution()
print(solution.finalPrices(prices))
'''
Problem URL = https://leetcode.com/problems/adding-spaces-to-a-string/description/

Example 1:
Input: s = "LeetcodeHelpsMeLearn", spaces = [8,13,15]
Output: "Leetcode Helps Me Learn"

Example 2:
Input: s = "icodeinpython", spaces = [1,5,7,9]
Output: "i code in py thon"

Example 3:
Input: s = "spacing", spaces = [0,1,2,3,4,5,6]
Output: " s p a c i n g"
'''

from typing import List

class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        # use set because searching time complexity of set is O(1)
        set_spaces = set(spaces)
        ans = ""
        for i in range(len(s)):
            if i in set_spaces:
                ans += " "
            ans += s[i]
        return ans

s, spaces = "LeetcodeHelpsMeLearn", [8,13,15]
# s, spaces = "icodeinpython", [1,5,7,9]
# s, spaces = "spacing", [0,1,2,3,4,5,6]

solution = Solution()
print(solution.addSpaces(s=s, spaces=spaces))
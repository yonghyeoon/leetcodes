"""
Problem URL : https://leetcode.com/problems/counting-words-with-a-given-prefix/description/

2185. Counting Words With a Given Prefix

You are given an array of strings words and a string pref.
Return the number of strings in words that contain pref as a prefix.
A prefix of a string s is any leading contiguous substring of s.

Example 1:
Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".

Example 2:
Input: words = ["leetcode","win","loops","success"], pref = "code"
Output: 0
Explanation: There are no strings that contain "code" as a prefix.
 

Constraints:
1 <= words.length <= 100
1 <= words[i].length, pref.length <= 100
words[i] and pref consist of lowercase English letters.

"""

from typing import List

class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        answer = 0
        for word in words:
            if word.startswith(pref):
                answer += 1
        
        return answer
    

# Example 1
# words, pref = ["pay","attention","practice","attend"], "at"

# Example 2
words, pref = ["leetcode","win","loops","success"], "code"

solution = Solution()
result = solution.prefixCount(words, pref)
print(result)
"""

Problem URL : https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description

Example 1:
Input: words = ["a","aba","ababa","aa"]
Output: 4
Explanation: In this example, the counted index pairs are:
i = 0 and j = 1 because isPrefixAndSuffix("a", "aba") is true.
i = 0 and j = 2 because isPrefixAndSuffix("a", "ababa") is true.
i = 0 and j = 3 because isPrefixAndSuffix("a", "aa") is true.
i = 1 and j = 2 because isPrefixAndSuffix("aba", "ababa") is true.
Therefore, the answer is 4.

Example 2:
Input: words = ["pa","papa","ma","mama"]
Output: 2
Explanation: In this example, the counted index pairs are:
i = 0 and j = 1 because isPrefixAndSuffix("pa", "papa") is true.
i = 2 and j = 3 because isPrefixAndSuffix("ma", "mama") is true.
Therefore, the answer is 2.

Example 3:
Input: words = ["abab","ab"]
Output: 0
Explanation: In this example, the only valid index pair is i = 0 and j = 1, and isPrefixAndSuffix("abab", "ab") is false.
Therefore, the answer is 0.

"""

from typing import List

class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        answer = 0
        for i in range(len(words)):
            len1 = len(words[i])
            for j in range(i+1, len(words)):
                len2 = len(words[j])
                if len1 <= len2 and words[j].startswith(words[i]) and words[j].endswith(words[i]):
                    answer += 1

        return answer


# Example 1
# words = ["a","aba","ababa","aa"]

# Example 2
# words = ["pa","papa","ma","mama"]

# Example 3
words = ["abab","ab"]

solution = Solution()
result = solution.countPrefixSuffixPairs(words)
print(result)
"""
Example 1:
Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4

Example 2:
Input: sentence = "this problem is an easy problem", searchWord = "pro"
Output: 2

Example 3:
Input: sentence = "i am tired", searchWord = "you"
Output: -1
"""

class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        for i, word in enumerate(sentence.split()):
            if len(word) < len(searchWord):
                continue

            if word[0:len(searchWord)] == searchWord:
                return i+1

        return -1


# sentence, searchWord = "i love eating burger", "burg"
# sentence, searchWord = "this problem is an easy problem", "pro"
sentence, searchWord = "i am tired", "you"

solution = Solution()
print(solution.isPrefixOfWord(sentence=sentence, searchWord=searchWord))
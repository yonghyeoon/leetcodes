/*

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

*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPrefixAndSuffix(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // length compare
    if (len1 > len2) {
        return false;
    }

    // prefix compare
    if (strncmp(str1, str2, len1) != 0) {
        return false;
    }

    // suffix compare
    for (int i=len1-1, j=len2-1; i >=0 && j >= 0; i--, j--) {
        // printf("str1 : %c, str2 : %c\n", str1[i], str2[j]);
        if (str1[i] != str2[j]) {
            return false;
        }
    }
    
    return true;

}

int countPrefixSuffixPairs(char** words, int wordsSize) {
    int answer = 0;
    for (int i=0; i < wordsSize; i++) {
        for (int j=i+1; j < wordsSize; j++) {
            bool result = isPrefixAndSuffix(words[i], words[j]);
            if (result) { answer += 1; }
        }
    }
    return answer;
}

int main(void){
    // Example 1
    // char* words[] = {"a","aba","ababa","aa"};
    // int wordsSize = 4;

    // Example 2
    // char* words[] = {"pa","papa","ma","mama"};
    // int wordsSize = 4;

    // Example 3
    char* words[] = {"abab","ab"};
    int wordsSize = 2;

    int ret = countPrefixSuffixPairs(words, wordsSize);
    printf("count : %d", ret);
    
    return 0;
    
}

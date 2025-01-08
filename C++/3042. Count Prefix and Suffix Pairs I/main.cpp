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

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int answer = 0;
        for (int i=0; i < words.size(); i++) {
            int len1 = words[i].size();
            for (int j=i+1; j < words.size(); j++) {
                int len2 = words[j].size();
                if ((len1 <= len2) && (words[j].find(words[i]) == 0) && (words[j].rfind(words[i]) == (len2-len1))) {
                    answer++;
                }
            }
        }

        return answer;
    }
};

int main(void){
    // Example 1
    // vector<string> words = {"a","aba","ababa","aa"};
    // Example 2
    // vector<string> words = {"pa","papa","ma","mama"};
    // Example 3
    vector<string> words = {"abab","ab"};
    
    Solution solution = Solution();
    int result = solution.countPrefixSuffixPairs(words);
    cout << result << endl;

}





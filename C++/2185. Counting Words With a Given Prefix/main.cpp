/*

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

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int answer = 0;
        for (string word : words) {
            if (word.find(pref) == 0) {
                answer++;
            }
        }

        return answer;
    }
};

int main(void){
    // Example 1
    // vector<string> words = {"pay","attention","practice","attend"};
    // string pref = "at";

    // Example 2
    vector<string> words = {"leetcode","win","loops","success"};
    string pref = "code";

    Solution solution = Solution();
    int result = solution.prefixCount(words, pref);
    cout << result << endl;

    return 0;
}

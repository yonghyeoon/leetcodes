/*
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
*/


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        unordered_set<int> set_spaces(spaces.begin(), spaces.end());

        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (set_spaces.find(i) != set_spaces.end()) {
                ans += " ";
            }
            ans += s[i];
        }

        return ans;
    }
};

int main() {
    //string s = "LeetcodeHelpsMeLearn";
    //vector<int> spaces = { 8, 13, 15 };

    //string s = "icodeinpython";
    //vector<int> spaces = { 1, 5, 7, 9 };

    string s = "spacing";
    vector<int> spaces = { 0,1,2,3,4,5,6 };

    Solution solution = Solution();
    string result = solution.addSpaces(s, spaces);
    cout << result << endl;
}
/*
Problem: https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/description/

Example 1 :
Input : nums = [2, 1, 3, 5, 6], k = 5, multiplier = 2
Output : [8, 4, 6, 5, 6]

Example 2 :
Input : nums = [1, 2], k = 3, multiplier = 4
Output : [16, 8]

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int len = nums.size();
        for (int i = 0; i < k; i++) {

            int min_value = nums[0];
            int min_ind = 0;

            for (int j = 1; j < len; j++) {
                if (nums[j] < min_value) {
                    min_value = nums[j];
                    min_ind = j;
                }
            }

            nums[min_ind] *= multiplier;
        }

        return nums;
    }
};

int main() {
    vector<int> ans;
    // Example 1
    vector<int> nums = { 2, 1, 3, 5, 6 };
    int k = 5;
    int multiplier = 2;

    // Example 2
    // vector<int> nums = { 1, 2 };
    // int k = 3;
    // int multiplier = 4;

    Solution solution = Solution();
    ans = solution.getFinalState(nums, k, multiplier);

    for (int n : ans) {
        cout << n << endl;
    }

    return 0;
}
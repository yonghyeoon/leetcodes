/*

Problem URL : https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description

You are given an array of integers nums. Return the length of the longest 
subarray of nums which is either strictly increasing or strictly decreasing.

Example 1:
Input: nums = [1,4,3,3,2]
Output: 2
Explanation:
The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].
The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].
Hence, we return 2.

Example 2:
Input: nums = [3,3,3,3]
Output: 1
Explanation:
The strictly increasing subarrays of nums are [3], [3], [3], and [3].
The strictly decreasing subarrays of nums are [3], [3], [3], and [3].
Hence, we return 1.

Example 3:
Input: nums = [3,2,1]
Output: 3
Explanation:
The strictly increasing subarrays of nums are [3], [2], and [1].
The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1], and [3,2,1].
Hence, we return 3.

Constraints:
• 1 <= nums.length <= 50
• 1 <= nums[i] <= 50

*/

#include <stdio.h>

int longestMonotonicSubarray(int* nums, int numsSize) {
    int maxLength = 1, incLength = 1, decLength = 1;

    for (int i=0; i < numsSize - 1; i++) {
        if (nums[i+1] > nums[i]) {
            incLength++;
            decLength = 1;
        }
        else if (nums[i+1] < nums[i]) {
            decLength++;
            incLength = 1;
        }
        else {
            incLength = 1;
            decLength = 1;
        }

        if (incLength > maxLength) maxLength = incLength;
        if (decLength > maxLength) maxLength = decLength;
    }

    return maxLength;
}

int main(void){

    // Example 1
    int nums[5] = {1,4,3,3,2};
    int numsSize = 5;

    // Example 2
    // int nums[4] = {3,3,3,3};
    // int numsSize = 4;

    // Example 3
    // int nums[3] = {3,2,1};
    // int numsSize = 3;

    int result = longestMonotonicSubarray(nums, numsSize);
    printf("%d", result);
}

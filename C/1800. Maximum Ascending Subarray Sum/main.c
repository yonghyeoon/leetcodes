/*

Problem URL : https://leetcode.com/problems/maximum-ascending-subarray-sum/description/

Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.
A subarray is defined as a contiguous sequence of numbers in an array.
A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is ascending.


Example 1:
Input: nums = [10,20,30,5,10,50]
Output: 65
Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.

Example 2:
Input: nums = [10,20,30,40,50]
Output: 150
Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.

Example 3:
Input: nums = [12,17,15,13,10,11,12]
Output: 33
Explanation: [10,11,12] is the ascending subarray with the maximum sum of 33.

Constraints:
• 1 <= nums.length <= 100
• 1 <= nums[i] <= 100

*/

#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int maxAscendingSum(int* nums, int numsSize) {
    int maxSum = 0;
    int sum = 0;
    int prev = 0;

    for (int i=0; i < numsSize; i++) {
        if (nums[i] > prev) {
            sum += nums[i]; 
        }
        else {
            sum = nums[i];
        }

        prev = nums[i];

        maxSum = MAX(sum, maxSum);
    }

    return maxSum;
}

int main(void){

    // Example 1
    int nums[6] = {10,20,30,5,10,50};
    int numsSize = 6;

    // Example 2
    // int nums[5] = {10,20,30,40,50};
    // int numsSize = 5;

    // Example 3
    // int nums[7] = {12,17,15,13,10,11,12};
    // int numsSize = 7;

    int result = maxAscendingSum(nums, numsSize);
    printf("%d", result);
}

/*

Problem URL : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
There may be duplicates in the original array.
Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

Example 1:
Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].

Example 2:
Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.

Example 3:
Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 

Constraints:
• 1 <= nums.length <= 100
• 1 <= nums[i] <= 100

*/

#include <stdio.h>
#include <stdbool.h>

bool checkIncreasingOrder(int* nums, int numsSize) {
    int prev = 0;

    for (int i=0; i < numsSize; i++) {
        if (nums[i] < prev) {
            return false;
        }
        prev = nums[i];
    }

    return true;
}

void rotateNums(int* nums, int numsSize) {
    int lastnum = nums[numsSize-1];

    for (int i=numsSize-1; i > 0; i--) {
        nums[i] = nums[i-1];
    }

    nums[0] = lastnum;
}

bool check(int* nums, int numsSize) {

    bool ret = checkIncreasingOrder(nums, numsSize);
    if (ret) { return true; }

    for (int i=0; i < numsSize; i++) {
        rotateNums(nums, numsSize);
        ret = checkIncreasingOrder(nums, numsSize);
        if (ret) { return true; }
    }

    return false;
}

int main(void){

    // Example 1
    int nums[5] = {3,4,5,1,2};
    int numsSize = 5;

    // Example 2
    // int nums[4] = {2,1,3,4};
    // int numsSize = 4;
    
    // Example 3
    // int nums[3] = {1,2,3};
    // int numsSize = 3;

    bool ret = check(nums, numsSize);
    printf("%s", ret ? "true":"false");

    return 0;
}

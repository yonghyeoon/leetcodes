/*

Problem URL : https://leetcode.com/problems/partition-array-according-to-given-pivot/description/

You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:
    * Every element less than pivot appears before every element greater than pivot.
    * Every element equal to pivot appears in between the elements less than and greater than pivot.
    * The relative order of the elements less than pivot and the elements greater than pivot is maintained.
        More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. If i < j and both elements are smaller (or larger) than pivot, then pi < pj.

Return nums after the rearrangement.

Example 1:
Input: nums = [9,12,5,10,14,3,10], pivot = 10
Output: [9,5,3,10,10,12,14]
Explanation: 
The elements 9, 5, and 3 are less than the pivot so they are on the left side of the array.
The elements 12 and 14 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [9, 5, 3] and [12, 14] are the respective orderings.

Example 2:
Input: nums = [-3,4,3,2], pivot = 2
Output: [-3,2,4,3]
Explanation: 
The element -3 is less than the pivot so it is on the left side of the array.
The elements 4 and 3 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [-3] and [4, 3] are the respective orderings.
 

Constraints:
    * 1 <= nums.length <= 105
    * -106 <= nums[i] <= 106
    * pivot equals to an element of nums.
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    int le_arr[100000] = {0};
    int le_arr_len = 0;

    int eq_arr[100000] = {0};
    int eq_arr_len = 0;

    int gt_arr[100000] = {0};
    int gt_arr_len = 0;

    for (int i=0; i < numsSize; i++) {
        if (nums[i] < pivot) {
            le_arr[le_arr_len++] = nums[i];
        }
        else if (nums[i] > pivot) {
            gt_arr[gt_arr_len++] = nums[i];
        }
        else {
            eq_arr[eq_arr_len++] = nums[i];
        }
    }

    int total_len = le_arr_len + gt_arr_len + eq_arr_len;
    int* ans = (int*)malloc(sizeof(int) * total_len);

    int mem_pos = 0;
    for (int i=0; i < le_arr_len; i++) {
        ans[mem_pos++] = le_arr[i];
    }

    for (int i=0; i < eq_arr_len; i++) {
        ans[mem_pos++] = eq_arr[i];
    }

    for (int i=0; i < gt_arr_len; i++) {
        ans[mem_pos++] = gt_arr[i];
    }

    *returnSize = total_len;
    return ans;

}

int main(void) {
    // Example 1
    int nums[] = {9,12,5,10,14,3,10};
    int numsSize = 7;
    int pivot = 10;
    
    // Example 2
    // int nums[] = {-3,4,3,2};
    // int numsSize = 4;
    // int pivot = 2;

    int returnSize = 0;
    int* result = pivotArray(nums, numsSize, pivot, &returnSize);

    printf("%d", returnSize);

    for (int i=0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    free(result);

    return 0;
}

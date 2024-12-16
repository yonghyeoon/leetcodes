#include <stdio.h>


int findMinValueInd(int* nums, int numsSize) {
    int min_value = nums[0];
    int min_ind = 0;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < min_value) {
            min_value = nums[i];
            min_ind = i;
        }
    }

    return min_ind;
}

int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {

    int* arr = (int*)malloc(sizeof(int) * numsSize);
    arr = nums;

    for (int i = 0; i < k; i++) {
        int min_ind = findMinValueInd(arr, numsSize);
        arr[min_ind] *= multiplier;
        //printf("%d\n", min_ind);
    }

    *returnSize = numsSize;
    return arr;
}

int main() {
    int nums[] = { 2, 1, 3, 5, 6 };
    int numSize = 5;
    int k = 5;
    int multiplier = 2;
    int returnSize = 0;

    int* ret = getFinalState(nums, numSize, k, multiplier, &returnSize);

    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf(" %d", ret[i]);
    }
    printf(" ]");

    return 0;

}
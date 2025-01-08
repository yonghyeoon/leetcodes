/*
* Problem URL : https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/
* Example 1:
* Input: prices = [8,4,6,2,3]
* Output: [4,2,4,2,3]
*
* Example 2:
* Input: prices = [1,2,3,4,5]
* Output: [1,2,3,4,5]
*
* Example 3:
* Input: prices = [10,1,1,6]
* Output: [9,0,1,6]
*/

#include <stdio.h>
#include <stdlib.h>

int* finalPrices(int* prices, int pricesSize, int* returnSize) {

    int* arr = (int*)malloc(sizeof(int) * pricesSize);
    
    for (int i = 0; i < pricesSize; i++) {
        arr[i] = prices[i];
        for (int j = i + 1; j < pricesSize; j++) {
            if (prices[i] >= prices[j]) {
                arr[i] = prices[i] - prices[j];
                break;
            }
        }
    }

    *returnSize = pricesSize;
    return arr;
}

int main(void) {

    // Example 1
    // nt prices[] = {8,4,6,2,3};
    //int pricesSize = 5;
    //int returnSize = 0;

    // Example 2
    // int prices[] = { 1,2,3,4,5 };
    // int pricesSize = 5;
    // int returnSize = 0;

    // Example 3
    int prices[] = { 10,1,1,6 };
    int pricesSize = 4;
    int returnSize = 0;

    int* ret = finalPrices(prices, pricesSize, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", ret[i]);
    }

    free(ret);

    return 0;
}
/*
* Problem URL : https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/
* 
* Example 1:
* Input: gifts = [25,64,9,4,100], k = 4
* Output: 29
* 
* Example 2: 
* Input: gifts = [1,1,1,1], k = 4
* Output: 4
* 
*/

#include <stdio.h>
#include <math.h>

long long pickGifts(int* gifts, int giftsSize, int k) {
    for (int i = 0; i < k; i++) {
        int max_value = 0;
        int max_index = 0;
        for (int j = 0; j < giftsSize; j++) {
            if (gifts[j] > max_value) {
                max_value = gifts[j];
                max_index = j;
            }
        }

        gifts[max_index] = floor(sqrt(max_value));
    }

    long long answer = 0;
    for (int k = 0; k < giftsSize; k++) {
        answer += gifts[k];
    }

    return answer;
}

int main() {

    // Example 1
    //int gifts[] = { 25,64,9,4,100 };
    //int giftsSize = 5;
    //int k = 4;

    // Example 2
    int gifts[] = { 1,1,1,1 };
    int giftsSize = 4;
    int k = 4;

    long long result = pickGifts(gifts, giftsSize, k);
    printf("%lld", result);

    return 0;
}
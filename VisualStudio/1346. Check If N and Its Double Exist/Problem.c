/*
* Example 1:
* Input: arr = [10,2,5,3]
* Output: true
* 
* Example 2: 
* Input: arr = [3,1,7,11]
* Output: false
*/

#include <stdio.h>
#include <stdbool.h>

bool checkIfExist(int* arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 != 0) {
            continue;
        }

        for (int j = 0; j < arrSize; j++) {
            if (i == j) {
                continue;
            }

            if (arr[i] == 2 * arr[j]) {
                return true;
            }
        }
    }

    return false;
}

int main(void) {
    // int arr[] = { 10,2,5,3 };
    // int arrSize = 4;
    int arr[] = { 3,1,7,11 };
    int arrSize = 4;

    bool result = checkIfExist(arr, arrSize);
    printf("%s", result ? "true" : "false");

    return 0;
}
/*

Problem URL : https://leetcode.com/problems/product-of-the-last-k-numbers/description/

Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.

Implement the ProductOfNumbers class:

ProductOfNumbers() Initializes the object with an empty stream.
void add(int num) Appends the integer num to the stream.
int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always the current list has at least k numbers.
The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.

Example:
Input
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

Output
[null,null,null,null,null,null,20,40,0,null,32]

Explanation
ProductOfNumbers productOfNumbers = new ProductOfNumbers();
productOfNumbers.add(3);        // [3]
productOfNumbers.add(0);        // [3,0]
productOfNumbers.add(2);        // [3,0,2]
productOfNumbers.add(5);        // [3,0,2,5]
productOfNumbers.add(4);        // [3,0,2,5,4]
productOfNumbers.getProduct(2); // return 20. The product of the last 2 numbers is 5 * 4 = 20
productOfNumbers.getProduct(3); // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
productOfNumbers.getProduct(4); // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
productOfNumbers.add(8);        // [3,0,2,5,4,8]
productOfNumbers.getProduct(2); // return 32. The product of the last 2 numbers is 4 * 8 = 32 
 

Constraints:
0 <= num <= 100
1 <= k <= 4 * 104
At most 4 * 104 calls will be made to add and getProduct.
The product of the stream at any point in time will fit in a 32-bit integer.
 

Follow-up: Can you implement both GetProduct and Add to work in O(1) time complexity instead of O(k) time complexity?

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE    100000

typedef struct {
    int arr[MAX_SIZE];
    int size;
} ProductOfNumbers;

ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers *obj = (ProductOfNumbers*)malloc(sizeof(ProductOfNumbers));
    obj->size = 0;
    return obj;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    if (obj->size >= MAX_SIZE) {
        printf("arrry size is full");
        return;
    }
    obj->arr[obj->size++] = num;
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    int lastNum = obj->size - 1;
    int sum = 1;
    for (int i = lastNum; i > lastNum-k; i--) {
        sum *= obj->arr[i];
    }

    return sum;
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    free(obj);
}


int main(void){
    ProductOfNumbers* obj = productOfNumbersCreate();
    int result;

    /* Example 1 */ 
    productOfNumbersAdd(obj, 3);
    productOfNumbersAdd(obj, 0);
    productOfNumbersAdd(obj, 2);
    productOfNumbersAdd(obj, 5);
    productOfNumbersAdd(obj, 4);
    result = productOfNumbersGetProduct(obj, 2);
    printf("%d ", result);
    result = productOfNumbersGetProduct(obj, 3);
    printf("%d ", result);
    result = productOfNumbersGetProduct(obj, 4);
    printf("%d ", result);
    productOfNumbersAdd(obj, 8);
    result = productOfNumbersGetProduct(obj, 2);
    printf("%d\n", result);

    productOfNumbersFree(obj);

    return 0;

}

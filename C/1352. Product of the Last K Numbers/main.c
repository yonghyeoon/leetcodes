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

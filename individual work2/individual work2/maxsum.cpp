#include <stdio.h>  
#include "maxsum.h"

int main() {
    int n;
    int a[100];
    printf("Enter the number of elements: ");
    scanf_s("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &a[i]);
    }
    int maxSum = MaxSum(a, 0, n - 1, n);
    printf("Maximum contiguous sum is: %d\n", maxSum);
    return 0;
}
//
// Created by longmensparkle on 16/5/19.
//
#include <stdio.h>

#define MAXN 100

void SortIntegerArray(int *arr, int n) {
    int i = 0, j = 0;
    for (i = 0; i < n; i++) {
        for (j = n - 2; j >= i; j--) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main() {
    int num[MAXN];
    int i = 0;
    printf("Please input the number of all the numbers that need sorting\n");
    int n;
    scanf("%d", &n);
    printf("Please input each number that is seperated by space.\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    SortIntegerArray(num, n);
    printf("That's the numbers after sorting.\n");
    for (i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    return 0;
}
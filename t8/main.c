//
// Created by longmensparkle on 16/5/19.
//
#include <stdio.h>

#define MAXN 100


int RemoveDuplicates(int * arr, int n) {
    int res[MAXN];
    int i;
    int j = 0;
    for (i = 0; i < n; i++) {
        if (j == 0 || (j > 0 && arr[i] != res[j - 1]))
            res[j++] = arr[i];
    }
    for (i = 0; i < j; i++) {
        arr[i] = res[i];
    }
    return j;
}

int main() {
    int num[MAXN];
    int i = 0;
    printf("Please input the number of all the sorted numbers\n");
    int n;
    scanf("%d", &n);
    printf("Please input each number that is seperated by space.\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    int j = 0;
    j = RemoveDuplicates(num, n);
    printf("%d\n", j);
    for (i = 0; i < j; i++) {
        printf("%d ", num[i]);
    }
    return 0;
}
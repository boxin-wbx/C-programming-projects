#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int res[10000], len = 0;

void print(int len) {
    int i;
    for (i = 0; i < len - 1; i++) {
        printf("%d", res[i]);
        putchar('+');
    }
    printf("%d", res[i]);
    putchar('\n');
}

void split(int num, int dim) {
    if (dim != 0 && res[dim - 1] >= num) {
        res[dim] = num;
        res[dim + 1] = 0;
        print(dim + 1);
    }
    int i;
    for (i = num - 1; i >= 1; i--)
        if (dim == 0 || (dim != 0 && res[dim - 1] >= i)) {
        res[dim] = i;
        split(num - i, dim + 1);
    }
}

int main() {
    int num;
    scanf("%d", &num);
    split(num, 0);
}
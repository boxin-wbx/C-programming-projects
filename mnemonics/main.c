//
// Created by longmensparkle on 16/5/25.
//
#include <stdio.h>
#include <string.h>

char num[10][4] = {{1, '0'},
                   {1, '1'},
                   {3, 'A', 'B', 'C'},
                   {3, 'D', 'E', 'F'},
                   {3, 'G', 'H', 'I'},
                   {3, 'J', 'k', 'L'},
                   {3, 'M', 'N', 'O'},
                   {3, 'P', 'R', 'S'},
                   {3, 'T', 'U', 'V'},
                   {3, 'W', 'X', 'Y'}
};

char str[100];

char scan[100];

int length;

void search(int dim) {
    if (dim == length) {
        str[dim + 1] = 0;
        printf("%s ", str);
    }
    else {
        int no = scan[dim] - '0', i;
        for (i = 1; i <= num[no][0]; i++) {
            str[dim] = num[no][i];
            search(dim + 1);
            if (dim == 0) printf("\n");
        }
    }
}

int main() {
    scanf("%s", scan);
    length = strlen(scan);
    search(0);
    return 0;
}
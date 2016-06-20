#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAXN 100000

int num[MAXN];

clock_t begin, end;
double time_spent;

void numGenerator() {
    int i = 0;
    for (i = 0; i < MAXN / 100; i++) {
        int j, k = rand();
        for (j = 0; j < 100; j++)
            num[i * 100 + j] = k;
    }
}

void print() {
    int i = 0;
    for (i = 0; i < MAXN; i++) {
        printf("%d\n", num[i]);
    }
}

void scan() {
    int i = 0;
    for (i = 0; i < MAXN; i++) {
        scanf("%d", &num[i]);
    }
}

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int lomutoPartition(int num[], int lo, int hi) {
    int pivot = num[hi];
    int j, i = lo;
    for (j = lo; j < hi; j++)
        if (num[j] <= pivot) {
            swap(num + j, num + i);
            i++;
        }
    swap(num + i, num + hi);
    return i;
}

void lomutoQuicksort(int num[], int lo, int hi) {
    if (lo < hi) {
        int pivot = lomutoPartition(num, lo, hi);
        lomutoQuicksort(num, lo, pivot - 1);
        lomutoQuicksort(num, pivot + 1, hi);
    }
}

int hoarePartition(int num[], int lo, int hi) {
    int pivot = num[lo];
    int i = lo - 1;
    int j = hi + 1;
    while (1) {
        do
            i++;
        while (num[i] < pivot);
        do
            j--;
        while (num[j] > pivot);
        if (i >= j) return j;
        swap(num + i, num + j);
    }
}

void hoareQuicksort(int num[], int lo, int hi) {
    if (lo < hi) {
        int p = hoarePartition(num, lo, hi);
        hoareQuicksort(num, lo, p);
        hoareQuicksort(num, p + 1, hi);
    }
}

double lomutoTest(char *s) {
    freopen(s, "r", stdin);
    scan();
    begin = clock();
    lomutoQuicksort(num, 0, MAXN - 1);
    end = clock();
    return (double) (end - begin) / CLOCKS_PER_SEC;
}

double hoareTest(char *s) {
    freopen(s, "r", stdin);
    scan();
    begin = clock();
    hoareQuicksort(num, 0, MAXN - 1);
    end = clock();
    return (double) (end - begin) / CLOCKS_PER_SEC;
}

void medianOfThree(int num[], int lo, int hi) {
    int middle = lo + hi;
    middle /= 2;
    if (num[lo] > num[hi]) swap(num + lo, num + hi);
    if (num[lo] > num[middle]) swap(num + lo, num + middle);
    if (num[middle] > num[hi]) swap(num + middle, num + hi);
    swap(num + middle, num + lo);
}

int wbxPartition(int num[], int lo, int hi) {
    medianOfThree(num, lo, hi);
    int pivot = num[lo];
    int i = lo - 1;
    int j = hi + 1;
    while (1) {
        do
            i++;
        while (num[i] < pivot);
        do
            j--;
        while (num[j] > pivot);
        if (i >= j) return j;
        swap(num + i, num + j);
    }
}

void wbxQuicksort(int num[], int lo, int hi) {
    if (lo < hi) {
        int p = wbxPartition(num, lo, hi);
        int j = p - 1, i;
        for (i = p - 1; i >= lo; i--)
            if (num[p] == num[i]) {
                swap(num + i, num + j);
                j--;
            }
        j = p + 1;
        for (i = p + 1; i <= hi; i++)
            if (num[p] == num[i]) {
                swap(num + i, num + j);
                j++;
            }
        wbxQuicksort(num, lo, p);
        wbxQuicksort(num, p + 1, hi);
    }
}

double wbxTest(char * s) {
    freopen(s, "r", stdin);
    scan();
    begin = clock();
    wbxQuicksort(num, 0, MAXN - 1);
    end = clock();
    return (double) (end - begin) / CLOCKS_PER_SEC;
}


int main() {
//    srand(time(NULL));
//    freopen("/Users/longmen/ClionProjects/quicksort/data3.txt", "w", stdout);
//    numGenerator();
//    print();

    double t1 = 0;
    char *s = "/Users/longmen/ClionProjects/quicksort/res1.txt";
    int i = 0;
//    for (i = 0; i < 10; i++)
//        t1 += lomutoTest(s);
//    printf("The time that Lomuto Quicksort algorithm uses is : \n %lf", t1 / 10);

    double t2 = 0;
//    for (i = 0; i < 10; i++)
        t2 += hoareTest(s);
    printf("\nThe time that Hoare Quicksort algorithm uses is : \n%lf", t2 / 10);

//    double t3 = 0;
//    for (i = 0; i < 1; i++)
//        t3 += wbxTest(s);
//    printf("\nThe time that wbx Quicksort algorithm uses is : \n%lf", t3 / 10);

//    print();

    return 0;
}
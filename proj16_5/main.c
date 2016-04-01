#include "rational.h"
#include <stdio.h>

int a[10][10];
int (*b)[];
int pr(int (*b)[3])
{
//    return b[0][0];
}
int main()
{
    a[0][0]=1;
    b=a;
    printf("%d\n",(*b)[10]);
    printf("This program adds a list of rational numbers.\n");
    printf("Signal end of list with a 0.\n");
    rationalT r,sum;
    sum = CreateRational(0,1);
    while(r=GetRational())
    {
        sum = AddRational(sum, r);
    };
    printf("the total is ");
    PrintRational(sum);
    /*here is the version of rational*rational
    printf("This program multiply a list of rational numbers.\n");
    printf("Signal end of list with a 0.\n");
    rationalT r,sum;
    sum = CreateRational(1,1);
    while(r=GetRational())
    {
        sum = MultiplyRational(sum, r);
    };
    printf("the total is ");
    PrintRational(sum);
     */
    return 0;
}
//
// Created by longmensparkle on 16/3/13.
//

#include "rational.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

rationalT test;

rationalT NewRational()
{
    return malloc(sizeof(rationalT));
}

int gcd(int a, int b)
{
    if (a<b) return gcd(b,a);
    if (b==0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b)
{
    return a*b/gcd(a,b);
}

rationalT CreateRational(int num, int den)
{
    rationalT r;
    r = NewRational();
    int factor = gcd(den,num);
    r->den = den/factor;
    r->num = num/factor;
    return r;
}

rationalT AddRational(rationalT r1, rationalT r2)
{
    int den = lcm(r1->den, r2->den);
    int num = r1->num*den/r1->den + r2->num*den/r2->den;
    return CreateRational(num,den);
}

void PrintRational(rationalT r)
{
    int factor = gcd(r->den,r->num);
    r->den /= factor;
    r->num /= factor;
    printf("%d/%d\n",r->num,r->den);
}

rationalT MultiplyRational(rationalT r1, rationalT r2)
{
    return CreateRational(r1->num * r2->num, r2->den * r1->den);
}

rationalT GetRational()
{
    char str[100];
    int num=0, den=0;
    scanf("%s", str);
    if (!strcmp(str,"0")) return NULL;
    int i=0;
    for (i=0; str[i]!='/'; i++)
    {
        num = num*10 + str[i]-'0';
    }
    for (i++; i<strlen(str); i++)
    {
        den = den*10 + str[i]-'0';
    }
    return CreateRational(num, den);
}
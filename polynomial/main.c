//
// Created by longmensparkle on 16/3/30.
//
#include <stdio.h>
#include "poly.h"

int main() {
    polyADT poly1, poly2, _indent;
    poly1 = newPoly();
    poly2 = newPoly();
    _indent = newPoly();
    enTerm(_indent, -1, 0);
    printf("This function scan all the terms of the polynomial in the whatsoever order\n"
                   "and in the format like (coefficient, exponent).\n"
                   "After you input a term, press ENTER to input another term ended with a term (0,0).\n"
                   "This program can add, subtract and multiply two polynomials.\n\n");
    printf("Please input one polinomial\n");
    scanPoly(poly1);
    printf("Please input +/-/* to calculate two polynomials\n");
    char c;
    scanf("%c", &c);
    getchar();
    printf("Please input the other polinomial\n");
    scanPoly(poly2);
    switch (c) {
        case '+':
            printPoly(plusPoly(poly1, poly2));
            break;
        case '-':
            printPoly(plusPoly(poly1, multiPoly(poly2, _indent)));
            break;
        case '*':
            printPoly(multiPoly(poly1, poly2));
            break;
        default:
            printf("Invalid input. Game over!\n");
            return 0;
    }
    return 0;
}
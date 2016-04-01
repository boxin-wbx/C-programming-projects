//
// Created by longmensparkle on 16/4/1.
//

#include "poly.h"
#include <stdio.h>
#include <stdlib.h>

#define MINI -0x7fffffff

/*
 * Type: polyCDT
 * --------------
 * This type provides the concrete counterpart to the polyADT.
 * The representation used here consists of a term of coeffienct and exponent
 * with a pointer pointing to the next term.
 */

struct polyCDT {
    int coef, expo;
    polyADT next;
};

/*
 * Function: NewPoly
 * ------------------
 * This function allocates and initializes the storage for a
 * new polynomial.
 */

polyADT newPoly(void) {
    polyADT poly;

    poly = malloc(sizeof(poly));
    poly->coef = 0;
    poly->expo = MINI;
    poly->next = 0;
    return poly;
}

/*
 * Function: newNode
 * ------------------
 * This function allocates and initializes the storage for a
 * new node.
 */


polyADT newNode(int coef, int expo) {
    polyADT node;

    node = malloc(sizeof(node));
    node->coef = coef;
    node->expo = expo;
    node->next = 0;
    return node;
}

/*
 * Function: enTerm
 * -----------------
 * This function adds a new term to the polynomial.
 */
void enTerm(polyADT poly, int coef, int expo) {
    polyADT temp = poly;
    while (temp->next != 0 && temp->next->expo <= expo) temp = temp->next;
    if (temp->expo == expo) {
        temp->coef += coef;
    }
    else if (temp->next == 0) {
        polyADT node = newNode(coef, expo);
        temp->next = node;
    }
    else {
        polyADT node = newNode(coef, expo);
        polyADT temp2 = temp->next;
        temp->next = node;
        temp->next = node;
        node->next = temp2;
    }
}


void printTerm(polyADT node) {
    if (node->coef == -1)
        printf("-");
    else if (node->coef < 0)
        printf("%d", node->coef);
    else if (node->coef == 1)
        printf("+");
    else if (node->coef > 0)
        printf("+%d", node->coef);
    else return;

    if (node->expo == 1)
        printf("x");
    else if (node->expo < 0)
        printf("x^(%d)", node->expo);
    else if (node->expo != 0)
        printf("x^%d", node->expo);
}

void printFirstTerm(polyADT node) {
    if (node->coef == -1)
        printf("-");
    else if (node->coef < 0)
        printf("%d", node->coef);
    else if (node->coef > 0 && node->coef != 1)
        printf("%d", node->coef);

    if (node->expo == 1)
        printf("x");
    else if (node->expo < 0)
        printf("x^(%d)", node->expo);
    else if (node->expo != 0)
        printf("x^%d", node->expo);
}

/*
 * Function: printPoly
 * -----------------
 * This function all the terms of the polynomial in the proper format like 1+2x+x^2.
 */

void printPoly(polyADT poly) {
    polyADT temp;
    int flag = 0;
    temp = poly;
    temp = temp->next;
    if (temp != 0) {
        if (temp->coef != 0)
            printFirstTerm(temp), flag = 1;
        temp = temp->next;
    }
    while (temp != 0) {
        if (temp->coef != 0)
            printTerm(temp), flag = 1;
        temp = temp->next;
    };
    if (!flag) printf("0");
    printf("\n");
}

/*
 * Function: scanPoly
 * Usage: scanPoly(void);
 * ---------------------------
 * This function scan all the terms of the polynomial in the whatsoever order
 * and in the format like (coefficient, exponent).
 * After you input a term, press ENTER to input another term.
 * This function ended with a (0, 0).
 */

void scanPoly(polyADT poly) {
    int coef, expo;
    scanf("(%d,%d)", &coef, &expo);
    getchar();
    while (!(coef == 0 && expo == 0)) {
        enTerm(poly, coef, expo);
        scanf("(%d,%d)", &coef, &expo);
        getchar();
    }
}

/*
 * Function: plusPoly
 * Usage: plusPoly(poly1, poly2);
 * ---------------------------
 * This function adds two polynomials and return the answer.
 */

polyADT plusPoly(polyADT poly1, polyADT poly2) {
    polyADT temp;
    temp = poly1->next;
    while (temp != 0) {
        enTerm(poly2, temp->coef, temp->expo);
        temp = temp->next;
    }
    return poly2;
};

/*
 * Function: multiPoly
 * Usage: multiPoly();
 * ---------------------------
 * This function multiplies two polynomials and return the answer.
 */

polyADT multiPoly(polyADT poly1, polyADT poly2) {
    polyADT temp1, temp2, ans;
    temp1 = poly1->next;
    ans = newPoly();
    while (temp1 != 0) {
        temp2 = poly2->next;
        while (temp2 != 0) {
            enTerm(ans, temp1->coef * temp2->coef, temp1->expo + temp2->expo);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return ans;
}
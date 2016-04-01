//
// Created by longmensparkle on 16/4/1.
//

#ifndef POLYNOMIAL_POLY_H
#define POLYNOMIAL_POLY_H

#endif //POLYNOMIAL_POLY_H

/*
 *  Type: polyADT
 *  --------------
 *  This line defines the abstract polynomial type as a pointer to
 *  its concrete counterpart. CLients have no access to the
 *  underlying representation.
 */

typedef struct polyCDT *polyADT;

/*
 * Function: newPoly
 * Usage: poly = newPoly();
 * --------------------------
 * This function allocates and returns an empty polynomial.
 */

polyADT newPoly();

/*
 * Function: enTerm
 * Usage: enTerm(polynomial, coefficient, exponent);
 * ---------------------------
 * This function adds a new term to the polynomial in the proper place.
 * Remember the maximum value of coefficient and exponent should be in the range of int.
 */

void enTerm(polyADT queue, int coefficient, int exponent);

/*
 * Function: printPoly
 * Usage: printPoly(polynomial);
 * ---------------------------
 * This function print all the terms of the polynomial in the proper format like x^2+x+1.
 */

void printPoly(polyADT queue);

/*
 * Function: scanPoly
 * Usage: scanPoly(poly);
 * ---------------------------
 * This function scan all the terms of the polynomial in the whatsoever order
 * and in the format like (coefficient, exponent).
 * This function ended with a (0, 0).
 */

void scanPoly(polyADT poly);


/*
 * Function: plusPoly
 * Usage: plusPoly(poly1, poly2);
 * ---------------------------
 * This function adds two polynomials and return the answer.
 */

polyADT plusPoly(polyADT poly1, polyADT poly2);

/*
 * Function: multiPoly
 * Usage: multiPoly();
 * ---------------------------
 * This function multiplies two polynomials and return the answer.
 */

polyADT multiPoly(polyADT poly1, polyADT poly2);
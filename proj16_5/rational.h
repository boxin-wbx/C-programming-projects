//
// Created by longmensparkle on 16/3/13.
//

#ifndef PROJ16_5_RATIONAL_H
#define PROJ16_5_RATIONAL_H

typedef struct rational{
    int num,den;
} *rationalT;

rationalT NewRational();

rationalT CreateRational(int num,int den);

rationalT AddRational(rationalT r1, rationalT r2);

rationalT MultiplyRational(rationalT r1, rationalT r2);

rationalT GetRational();

void PrintRational(rationalT r);

#endif //PROJ16_5_RATIONAL_H

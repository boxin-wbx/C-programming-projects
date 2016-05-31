#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>
#include <math.h>


#define Pi                    3.1415926535

double ANGLE = 0;


/*
 * Function: turn
 * Usage: turn(rad)
 * ---------------------------------------
 * This function turns the ANGLE clockwise from the previous ANGLE that is set before
 * the function is called. Remember the parameter 'rad' is in the form of radian.
 */

void turn(double rad) {
    ANGLE += rad;
}

/*
 * Function: move
 * Usage: move(distance)
 * ---------------------------------------
 * This function makes Pen move the distance from the previous point
 * along the ANGLE that is set before the function is called.
 * Remember that this function will not draw any lines.
 */

void move(double distance) {
    MovePen(GetCurrentX() + distance * cos(ANGLE), GetCurrentY() + distance * sin(ANGLE));
}

void forward(double distance) {
    DrawLine(distance * cos(ANGLE), distance * sin(ANGLE));
//    move(distance);
}

double length;


void drawOneSide(int order) {
    if (order == 0) {
        forward(length);
    }
    else if (order == 1) {
        forward(length);
        turn(-Pi / 3);
        forward(length);
        turn(2 * Pi / 3);
        forward(length);
        turn(-Pi / 3);
        forward(length);
    }
    else {
        drawOneSide(order - 1);
        turn(-Pi / 3);
        drawOneSide(order - 1);
        turn(2 * Pi / 3);
        drawOneSide(order - 1);
        turn(-Pi / 3);
        drawOneSide(order - 1);
    }
}

void Main() {
    InitGraphics();

    SetPenColor("Black");
    double cx, cy;
    length = GetWindowHeight() * 0.5;
    cx = GetWindowWidth() * 0.3;
    cy = GetWindowHeight() * 0.4;
    MovePen(cx, cy);
    SetPenSize(1);
    InitConsole();
    int order;
    printf("请输入迭代次数:\n");
    scanf("%d", &order);
    FreeConsole();
    length = length / pow(3, order);
    drawOneSide(order);
    turn(Pi * 2 / 3);
    drawOneSide(order);
    turn(Pi * 2 / 3);
    drawOneSide(order);
}
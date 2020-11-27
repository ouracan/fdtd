//
//  abcfirst.cpp
//  Improved_1D_FDTD_v05
//
//  Created by Zheng Zu on 12.06.20.
//  Copyright © 2020 Zheng Zu. All rights reserved.
//

/* Function to implement a first-order ABC */

#include "fdtd3.h"
#include <cmath>

static int initDone = 0;
static double ezOldLeft = 0.0, ezOldRight = 0.0;
static double abcCoefLeft, abcCoefRight;

/* Initialization function for first-order ABC. */
void abcInit(Grid *g){
    double temp;
    
    initDone=1;
    
    /* calculate coefficient on left end of grid */
    temp = sqrt(Cezh(0) * Chye(0));
    abcCoefLeft = (temp - 1.0) / (temp + 1.0);
    
    /* calculate coefficient on right end of grid */
    temp = sqrt(Cezh(SizeX-1) * Chye(SizeX-2));
    abcCoefRight = (temp-1.0) / (temp + 1.0);
    
}

/* First-order ABC. */
void abc(Grid *g){
    
    /* check if abcinit() has been called */
    if (!initDone){
        fprintf(stderr,
                "abc: abcInit must be called before abc.\n");
        exit(-1);
    }
    
    /* ABC for left side of grid */
    Ez(0) = ezOldLeft + abcCoefLeft * (Ez(1) - Ez(0));
    ezOldLeft = Ez(1);


    /* ABC for right side of grid */
    Ez(SizeX-1) = ezOldRight + abcCoefRight * (Ez(SizeX-2)-Ez(SizeX-1));
    ezOldRight = Ez(SizeX-2);

}

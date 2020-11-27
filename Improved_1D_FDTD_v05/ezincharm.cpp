//
//  ezinc3.cpp
//  Improved_1D_FDTD_v03
//
//  Created by Zheng Zu on 10.06.20.
//  Copyright © 2020 Zheng Zu. All rights reserved.
//


#include "ezinc3.h"

/* global variable  -- but privately to this file */
static double ppw = 0,cdtds;

/* prompt user for source-function points per wavelength. */
void ezIncInit(Grid *g){
    cdtds = Cdtds;
    printf("Enter points per wavelength: ");
    scanf(" %lf", &ppw);
}

/* calculate source function at a given time and location */
double ezInc(double time, double location){
    if (ppw <=0){
        fprintf(stderr,"ezInc: must call ezIncInit before ezInc. \n"
                "       Points per wavelength must be positive.\n");
        exit(-1);
    }
    return sin(2.0 * M_PI / ppw*(cdtds *time - location));
}

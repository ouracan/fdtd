//
//  tfsf.cpp
//  Improved_1D_FDTD_v03
//
//  Created by Zheng Zu on 10.06.20.
//  Copyright © 2020 Zheng Zu. All rights reserved.
//

#include <cmath>
#include "fdtd3.h"
#include "ezinc3.h"

static int tfsfBoundary = 0;

void tfsfInit(Grid *g){
    printf("Enter location of TFSF boundary: ");
    scanf(" %d", &tfsfBoundary);
    
    ezIncInit(g); //initialize source function

}

void tfsfUpdate(Grid *g){
    /* check if tfsfInit() has been called */
    if(tfsfBoundary <= 0){
        fprintf(stderr,
                "tfsfUpdate: tfsfInit must be called before tfsfUpdate, \n"
                "Boundary location must be set a positive value.\n");
        exit(-1);
    }
    
    /* correct Hy adjacent to TFSF boundary */
    Hy(tfsfBoundary + 1) += ezInc(Time + 0.5,-0.5);
    
    /* correct Ez adjacent to TFSF boudnary */
    Ez(tfsfBoundary + 1) += ezInc(Time + 0.5,-0.5);
}

//
//  main.cpp
//  Improved_1D_FDTD_v03
//
//  Created by Zheng Zu on 09.06.20.
//  Copyright © 2020 Zheng Zu. All rights reserved.
//

#include "fdtd3.h"

int main(int argc, const char * argv[]) {
    Grid *g;
    
    ALLOC_1D(g,1,Grid); //allocate memory
    
    GridInit(g);       //initialize the grid
    abcInit(g);
    tfsfInit(g);        //initialize TFSF boudary
    snapshotInit(g);        //initialize snapshots
    
    /* do time stepping */
    for(Time =0; Time <MaxTime; Time++){
        updateH3(g);        //update magnetic field
        tfsfUpdate(g);      //correct field on TFSF boundary
        updateE3(g);        //update the electric field
        abc(g);
        snapshot(g);        //take a snapshot
    }// end of time stepping
    return 0;
}

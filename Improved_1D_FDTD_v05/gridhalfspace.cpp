//
//  gridhalfspace.cpp
//  Improved_1D_FDTD_v03
//
//  Created by Zheng Zu on 10.06.20.
//  Copyright © 2020 Zheng Zu. All rights reserved.
//

#include "fdtd3.h"


#define EPSR 9.0



void GridInit(Grid *g){
    double imp0 = 377.0;
    int mm;
    
    SizeX = 200; //sie of domain
    MaxTime = 450; //duration of simulation
    Cdtds = 1.0; //Courant number
    
    ALLOC_1D(g->ez, SizeX, double);
    ALLOC_1D(g->ceze,SizeX, double);
    ALLOC_1D(g->cezh,SizeX,double);
    ALLOC_1D(g->hy,SizeX-1,double);
    ALLOC_1D(g->chyh,SizeX-1,double);
    ALLOC_1D(g->chye,SizeX-1,double);
    
    /* set electric-field update coefficients */
    for (mm=0;mm<SizeX;mm++){
        if(mm<100){
            Ceze(mm) = 1.0;
            Cezh(mm) = imp0;
        }else{
            Ceze(mm) = (1.0);
            Cezh(mm) = imp0/EPSR;
        }
    }
    /* set magnetic-field update coefficients */
    for(mm=0;mm<SizeX-1;mm++){
        
            Chyh(mm) = 1.0;
            Chye(mm)=1.0/imp0;
        
                
    }
    
}

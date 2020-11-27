//
//  update3.cpp
//  Improved_1D_FDTD_v03
//
//  Created by Zheng Zu on 10.06.20.
//  Copyright © 2020 Zheng Zu. All rights reserved.
//

#include "fdtd3.h"

/* update magnetic field */
void updateH3(Grid *g){
    int mm;
    
    for(mm=0; mm<SizeX-1;mm++)
        Hy(mm) = Chyh(mm) * Hy(mm) + Chye(mm) *
        (Ez(mm+1)-Ez(mm));
}

void updateE3(Grid *g){
    int mm;
    
    for(mm=1;mm<SizeX-1;mm++)
        Ez(mm)=Ceze(mm) * Ez(mm) + Cezh(mm) *
        (Hy(mm) - Hy(mm-1));
}

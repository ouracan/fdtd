//
//  ezinc3.h
//  Improved_1D_FDTD_v03
//
//  Created by Zheng Zu on 10.06.20.
//  Copyright © 2020 Zheng Zu. All rights reserved.
//

#ifndef ezinc3_h
#define ezinc3_h

#include <iostream>
#include <cmath>
#include "fdtd3.h"

void ezIncInit(Grid *g);
double ezInc(double time,double location);

#endif /* ezincharm_h */

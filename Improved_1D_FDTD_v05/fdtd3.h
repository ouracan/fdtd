//
//  fdtd3.h
//  Improved_1D_FDTD_v03
//
//  Created by Zheng Zu on 09.06.20.
//  Copyright © 2020 Zheng Zu. All rights reserved.
//

#ifndef fdtd3_h
#define fdtd3_h

#include <iostream>

struct Grid{
    double *ez, *ceze, *cezh;
    double *hy, *chyh, *chye;
    int sizeX;
    int time, maxTime;
    double cdtds;
};

typedef struct Grid Grid;

/* macros for accessing arrays and such */
#define Hy(MM)    g->hy[MM]
#define Chyh(MM)  g->chyh[MM]
#define Chye(MM)  g->chye[MM]

#define Ez(MM)    g->ez[MM]
#define Ceze(MM)  g->ceze[MM]
#define Cezh(MM)  g->cezh[MM]

#define SizeX     g->sizeX
#define Time      g->time
#define MaxTime   g->maxTime
#define Cdtds     g->cdtds

/* memory alocation macro */
#define ALLOC_1D(PNTR, NUM, TYPE)                                       \
PNTR = (TYPE *)calloc(NUM,sizeof(TYPE));                                \
    if(!PNTR){                                                          \
    perror("ALLOC_1D");                                                 \
    fprintf(stderr,"Allocation failed for " #PNTR ". Terminting...\n"); \
    exit(-1);                                                           \
}
/* Function prototypes */
void abcInit(Grid *g);
void abc(Grid *g);

void GridInit(Grid *g);

void snapshotInit(Grid *g);
void snapshot(Grid *g);

void tfsfInit(Grid *g);
void tfsfUpdate(Grid *g);

void updateE3(Grid *g);
void updateH3(Grid *g);





#endif /* fdtd3_h */

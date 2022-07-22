#include <mpi.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define LUMP 1

static long int numSteps = 1000000000;

int main(int argc, char **argv) {
  
  int numP, procID;

  // the usual mpi initialization
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numP);
  MPI_Comm_rank(MPI_COMM_WORLD, &procID);

  double *globalData=NULL;
  double localData[LUMP];

  // process 0 is only 1 that needs global data
  if (procID == 0) {
    globalData = malloc(LUMP * numP * sizeof(double) );
    for (int i=0; i<LUMP*numP; i++)
      globalData[i] = 0;
  }

  // determine localData first
  double tmpPI = 0;
  double dx = 1./numSteps;
  double x = dx*0.50;

  for (int i = procID; i < numSteps; i += numP) { 
    x = (i+.5)*dx;
    tmpPI += 4./(1.+x*x);
  }

  tmpPI *= dx;

  //for (int i=0; i<LUMP; i++) {
    //localData[i] = procID*10+i;
    //localData[i] = tmpPI;
    //}
   
  MPI_Gather(&tmpPI, LUMP, MPI_DOUBLE, globalData, LUMP, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  
  double pi = 0;
  if (procID == 0) {
    for (int i=0; i<numP; i++)
      pi += globalData[i]; 
    printf("PI = %f Difference from math.h definition %f \n", pi, pi-M_PI);
    //printf("\n");
  }

  if (procID == 0)
    free(globalData);

  MPI_Finalize();
}

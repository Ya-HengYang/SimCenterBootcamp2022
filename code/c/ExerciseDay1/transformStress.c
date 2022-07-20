// program to transform stress to a rotated coordinate system

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void transformStress(float *arrayStress, float theta, float *arrayTranStress);


int main(int argc, char **argv) {

  if (argc != 5) {
    printf("Usage: appName sigmaXX SIGMAyy tauXY theta\n");
    exit(-1);
  }
  
  float arrayStress[3], arrayTranStress[3];
  arrayStress[0] = atof(argv[1]);
  arrayStress[1] = atof(argv[2]);
  arrayStress[2] = atof(argv[3]);
  float theta   = atof(argv[4]); 
  if (theta < 360) {
    transformStress(arrayStress, theta, arrayTranStress);
    printf("SigmaXX' = %f, SigmaYY' = %f, TauXY' = %f\n", arrayTranStress[0],arrayTranStress[1],arrayTranStress[2]);
  } else {
    theta = fmod(theta,360);
    transformStress(arrayStress, theta, arrayTranStress);
    printf("SigmaXX' = %f, SigmaYY' = %f, TauXY' = %f\n", arrayTranStress[0],arrayTranStress[1],arrayTranStress[2]);
  }
  return 0;
}

void transformStress(float *arrayStress, float theta, float *arrayTranStress) {

  float sigmaXX  = arrayStress[0];
  float sigmaYY  = arrayStress[1];
  float tauXY    = arrayStress[2];

  float thetaToRad = theta*M_PI/180.0;
  float cosX  = cos(thetaToRad);
  float sinX  = sin(thetaToRad);

  arrayTranStress[0] = sigmaXX*cosX*cosX + sigmaYY*sinX*sinX + 2*tauXY * sinX*cosX;
  arrayTranStress[1] = sigmaXX*sinX*sinX + sigmaYY*cosX*cosX - 2*tauXY * sinX*cosX;
  arrayTranStress[2] = (sigmaYY-sigmaXX)*sinX*cosX + tauXY * (cosX*cosX - sinX*sinX);

};

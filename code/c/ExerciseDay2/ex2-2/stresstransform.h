#ifndef STRESSTRANSFORM_H
#define STRESSTRANSFORM_H


// DEFINE S typedef struct STRESS ...
typedef struct stress{
  double sigx;
  double sigy;
  double tau;
}STRESS; 

void StressTransform(STRESS s, STRESS *sp, double theta);

#endif


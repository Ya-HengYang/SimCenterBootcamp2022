// program to solve quadratic equation
//        ax^2 + bx + c = 0
//
// soln: x = -b/2a +/- sqrt(b^2-4ac)/2a
//
// write a program to take 3 inputs and output the soln
// deal with possible errors in input, i.e. b^2-4ac negative

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  if (argc != 4) {
    printf("Usage: appName a b c\n");
    exit(-1);
  }

  float a = atof(argv[1]);
  float b = atof(argv[2]);
  float c = atof(argv[3]);
  
  double coef1 = b*b - 4*a*c;
  double coef2 = -b/(2*a);

  if (coef1 >= 0.0) {
    
    float coef3 = sqrt(coef1)/(2*a);
    float x1 = coef2 - coef3;
    float x2 = coef2 + coef3;
    printf("We have real solution x1: %f  x3   %f\n",x1,x2);
  } else {
    float coef3 = sqrt(-coef1)/(2*a);
    printf("We have imaginary solution x1 %f + %1fi, x2 %f + %fi\n",coef2,-coef3,coef2,coef3);
  }


  printf("Have a Nice Day!\n");
  return 0;
}


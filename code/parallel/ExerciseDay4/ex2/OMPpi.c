#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

static int long numSteps = 1000000000;

int main(int argc, const char **argv) {
  
  double pi = 0;
  double dx = 1./numSteps;
  
  #pragma omp parallel
  {
    double tmpPI = 0;
    double x = 0.5*x;
    //int tid omp_get_thread_num();
    //int numT = omp_get_num_threads();
    #pragma omp for
      for (int i = 0; i < numSteps; i++) {
	x = (i+.5) * dx;
	tmpPI += 4./(1.+x*x);
      }
    #pragma omp critical
      {
        pi += tmpPI; 
      } 

  }  
  pi *= dx;
  
printf("PI = %f Difference from math.h definition %f \n",pi, pi-M_PI);

  return 0;
}

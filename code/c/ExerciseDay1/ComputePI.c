#include<stdio.h>
#include<time.h>
#include<math.h>

static int long numSteps = 100000;

int main() {
  
  clock_t tic = clock();

  double pi = 0; double time = 0;
  double dx = 1.0/numSteps;
  
  for (int i = 0; i < numSteps; i++){
    pi += 4.0/(1 + i*dx*i*dx)*dx;
  }

  clock_t toc = clock();
  time = (double)(toc - tic)/CLOCKS_PER_SEC;

  printf("PI = %f duration: %20.10f ms\n",pi,time);
  printf("Difference compared with M_PI = %f\n", pi-M_PI);
  
  return 0;
}

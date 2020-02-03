#include <stdio.h>
#include <omp.h>
static long num_steps = 1000000000;
double step;
void main ()
{	  int i; 	  double x, pi, sum = 0.0;

	  step = 1.0/(double) num_steps;

	  double start_time, run_time;
	  start_time = omp_get_wtime();

	  for (i=0;i< num_steps; i++){
		  x = (i+0.5)*step;
		  sum = sum + 4.0/(1.0+x*x);
	  }
	  pi = step * sum;
	  run_time = omp_get_wtime() - start_time;
	  printf("\n pi is %f in %f seconds\n ",pi,run_time);
}


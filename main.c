/**
* @file main.c
* @Brief   The main function for solving the Possion equation with Neumann boundary condition.
* @author Dong Yijing,1701110028@pku.edu.cn
* @version 1
* @date 2017-11-14
*/

#include <stdio.h>
#include <math.h>
#include <time.h>
#include "solve.h"

int main(){
    int n;
    double delta_x;/**< Step length in x direction*/
    double delta_y;/**< Step length in y direction*/
    double a, b;
    double E;
    double start,finish;
    double cputime;


    n = (2*N-1)*(N-1);
    delta_x = 2*sqrt(3)/(3*N);
    delta_y = sqrt(3)*delta_x;

    a = 1/(delta_x*delta_x);
    b = 1/(delta_y*delta_y); 

    E = 0.000001;
    start = clock();
    jacobi(n, E, a, b);
    finish = clock();
    cputime = (finish - start)/CLOCKS_PER_SEC;
    printf("time = %f sec\n",cputime);
}


   

/**
* @file jacobi.c
* @Brief  Using the Jacobi iterection to calculate the solutions
* @author Dong Yijing,1701110028@pku.edu.cn
* @version 1
* @date 2017-11-04
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solve.h"


/**
* @Param n 
*/
void jacobi( int n, double E, double b, double c){
	int i;/**< for circle*/
    int k = 0;/**< record the number of iterations*/
	double maxE;/**< the error between two iterations*/;
    double *a;
    double *temp;
    double **d;
    double *f;
    FILE *fp;
		
    printf("b=%f,c=%f\n",b,c);
		
		/**< initial a */ 
	a = (double *)malloc(sizeof(double)*n);
	for (i=0;i<n;i++){
		a[i] = 0.0;
	}
    /* printf("\n");*/

    /**< store the new value after a iteration*/
    printf("n= %d\n",n);
	temp =(double *)malloc(sizeof(double)*n);
    /**< declar a \f$(2N-1)\times(5)\f& matrix d,where d contains all none zero elements in the matrix */
	d = malloc(sizeof(double*)*n);
	for(i = 0; i < n; i++){
		d[i] = malloc(sizeof(double)*n);
	}
	/**< use the function calculatea to fulfill the matrix A，only save none zero elements by diagonal*/
    matrixa(d, b, c);
    /**< declar the right hand side vector f with (2N-1)dimention*/
	f = (double*)malloc(sizeof(double)*n);
	vectorf(f, b, c);
		do{
				calculateJ(a,temp,n,b,c,d,f);
				k++;
				/*for(i = 0; i < n; i++){
						printf("X%d=%f,",i,temp[i]);
				}
				printf("\n");*/
				swapU(temp,a,n);
				maxE=fabs(temp[0]-a[0]);
				for (i=0;i<n;i++){
						if(maxE<fabs(temp[i]-a[i])){
							maxE=fabs(temp[i]-a[i]);
                        }
				}
		}while(maxE >=E || k < 20000);
    fp = fopen("/home/dongyijing/pictures/a.txt","w");
    for (i = 0; i < n; i++){
        if (fp != NULL){
            fprintf(fp,"%f ",a[i]);
            if ((i+1)%(15) == 0){
                fprintf(fp,"\n");
            }
        }
            printf("a[%d]=%f\n", i, a[i]);
    }
    fclose(fp);
		return;
}
	



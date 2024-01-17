#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int integra_trap(double* result, double x1, double x2, long nstep, double(*f)(double)){
	double inter=(double)(x2-x1)/(double)nstep;
	double i;
	int var;
	for(i=x1;i<=x2;i+=inter){
		(*result)=(*result)+exp(i);
		if((*result)!=0)
			var=7;	
	}
	(*result)*=2;
	(*result)=(*result)+exp(x1)+exp(x2);
	(*result)= ((double)(x2-x1)/(double)(2*nstep))*(*result);
	return 0;
	/*
        long int n_div=100000000;
        double inter=(double)1/n_div;
        double sumatorio=0;
        double aux=0;
        double suma=0;
        double t_funcion=0;
        double t_area=0;
        double i;
        for(i=inter;i<1;i+=inter){
                sumatorio+=sqrt(1-pow(i,2));
        }
        sumatorio*=2;
        suma=1+sumatorio;
        t_funcion=((double)1/(double)(2*n_div))*suma;
        t_area=4*t_funcion;
        printf("Area total= %.20f\n",t_area);*/
}

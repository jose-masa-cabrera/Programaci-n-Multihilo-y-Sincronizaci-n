#include<stdio.h>
#include<stdlib.h>
#include"practica3.h"
#include<math.h>
double funcion(double var);
int main(int argv,char* argc[]){
	double (*f)(double)=funcion;
	double var;
	var=f(3);
	printf("valor=%f\n",var);
	double result=0; 
	double x1;
	double x2;
	long nstep;
	int correcto;
	//funcion a integrar
	x1=atoi(argc[1]);
	x2=atoi(argc[2]);
	nstep=atoi(argc[3]);
	if(argv!=4)
		perror("[-]Error en el número de parametros\n");
	correcto=integra_trap(&result,x1,x2,nstep,exp);
	if(correcto==0){		
		printf("Resultado del calculo %f\n",result);
	}
	else{
		perror("[-]Error en el calculo\n");
	}


}
double funcion(double var){
		var*=3;
		return var;
}

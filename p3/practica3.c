#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include "practica3.h"
int main(int argc, char** argv){
//int main(){
	double t_area;
	long  n_div;
        int n_hilos;
	p.inexacto=false;
	p.ultimo=false;
	//double  t_area,t_funcion,suma;
	if(argc!=3)
		perror("[-]Error de parametros");
	n_hilos=atoi(argv[1]);
	n_div=atoi(argv[2]);
	p.n_div=n_div;
	//n_hilos=1;
	//n_div=10000000;
	pthread_t h;
        p.intervalo=(double)1/n_div;
	p.veces=n_div/n_hilos;
	p.modulo=n_div%n_hilos;
        if(p.modulo!=0){
		p.inexacto=true;
	}
        p.inicio=p.intervalo;
	int contador=1;
	int i=1;
        for(i=1;i<=n_hilos;i++){
		if(i==n_hilos){
			p.ultimo=true;
		}
                if(pthread_create(&h,NULL,f_suma,(void*)&p))
                        perror("[-]Error al crear hilo");
                pthread_join(h,NULL);
        	p.inicio=p.intervalo*((contador*p.veces)+1);
		contador++;
        }
	//******************
	/*sumatorio*=2;
	suma=1+sumatorio;
	t_funcion=((double)1/(double)(2*n_div))*suma;*/
	t_area=4*sumatorio;
	//f2(n_hilos,n_div);
	printf("Area total= %.14f\n",t_area);

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

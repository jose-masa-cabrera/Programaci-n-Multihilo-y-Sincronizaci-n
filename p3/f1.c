#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include "practica3.h"
pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;

/*void f1(int n_hilos,int n_div){
	pthread_t h;
	p.intervalo=(double)1/n_div;
	p.veces=n_div/n_hilos;
	p.inicio=p.intervalo;
	int hh_proc=1;
	int contador=1;
	for(int i=0;i<n_hilos;i++){
		if(pthread_create(&h,NULL,f_suma,(void*)&p))
			perror("[-]Error al crear hilo");
		pthread_join(h,NULL);
		p.inicio=p.intervalo*((contador*p.veces)+1);
	}
}*/

void  *f_suma(void* arg){
	double  t_funcion,suma;
	struct parametros* p;
	double aux;
	p=(struct parametros*)arg;
	aux=p->inicio;
	int i=1;
	if(p->inexacto==true && p->ultimo==true){
		p->veces=p->veces+(p->modulo);
		for(i;i<=p->veces;i++){
			pthread_mutex_lock(&mutex);
	                sumatorio+=sqrt(1-pow(aux,2));
			aux+=p->intervalo;
			pthread_mutex_unlock(&mutex);
			if(aux>1){
				aux=1;
			}
		}
	
	
	}else
	for(i;i<=p->veces;i++){
		pthread_mutex_lock(&mutex);
                sumatorio+=sqrt(1-pow(aux,2));
		aux+=p->intervalo;
		pthread_mutex_unlock(&mutex);
		if(aux>1){
			aux=1;
		}
	}
	if(p->ultimo==true){
		 sumatorio*=2;
	         suma=1+sumatorio;
 	         t_funcion=((double)1/(double)(2*p->n_div))*suma;
		 sumatorio=t_funcion;
 	         //t_area=4*t_funcion;
 	         //f2(n_hilos,n_div);
 	         //printf("Area total= %.14f\n",t_area);
	}
}


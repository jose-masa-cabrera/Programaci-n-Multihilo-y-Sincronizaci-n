#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "practica3.h"
#include <pthread.h>
pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;
void *f_suma(void *arg){
	double  t_area,t_funcion,suma;
	struct parametros* p;
        double aux;
        p=(struct parametros*)arg;
        aux=p->inicio;
        int i=1;
        if(p->inexacto==true && p->ultimo==true){
                p->veces=p->veces+(p->modulo);
                for(i;i<p->veces;i++){
                        pthread_mutex_lock(&mutex);
                        sumatorio+=1/(1+(pow(aux,2)));
                        aux+=p->intervalo;
                        pthread_mutex_unlock(&mutex);
                        if(aux>1){
                                aux=1;
                        }
                }


        }else{
	for(i;i<=p->veces;i++){
                pthread_mutex_lock(&mutex);
                sumatorio+=1/(1+(pow(aux,2)));
                aux+=p->intervalo;
                pthread_mutex_unlock(&mutex);
                if(aux>1){
                        aux=1;
                }
        }
	}
	if(p->ultimo==true){
		sumatorio*=2;
		suma=1.5+sumatorio;
		t_funcion=((double)1/(double)(2*p->n_div))*suma;
		sumatorio=t_funcion;
		//t_area=4*t_funcion;
		//printf("Area total= %.14f\n",t_area);

	
	}


}

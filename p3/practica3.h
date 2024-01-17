#include<stdbool.h>
struct parametros{
	double intervalo;
	int veces;
	double inicio;
	bool inexacto;
	bool ultimo;
	double modulo;
	long n_div;
};
struct parametros p;
double sumatorio;
//void f1(int n_hilos,int n_div);
void *f_suma(void* arg);
//void f2(int n_hilos,int n_div);

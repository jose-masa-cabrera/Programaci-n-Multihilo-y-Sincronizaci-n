integra_trap:	practica3.o integra_trap.o
	gcc -g -o integra_trap practica3.o integra_trap.o -lm
practica3.o: practica3.c practica3.h
	gcc -g -c practica3.c -lm
integra_trap.o: integra_trap.c practica3.h
	gcc -g -c integra_trap.c -lm
clean:
	rm *.o* integra_trap

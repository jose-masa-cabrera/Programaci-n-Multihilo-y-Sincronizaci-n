TARGET_F1=f1
TARGET_F2=f2

all: $(TARGET_F1) $(TARGET_F2)

$(TARGET_F1):f1.o practica3.o
	cc f1.o practica3.o -lphtread -lm -o $(TARGET_F1)
	
$(TARGET_F2):f2.o practica3.o
	cc f2.o practica3.o -lpthread -lm -o $(TARGET_F2)

practica3.o: practica3.c practica3.h
	cc -c practica3.c -g  
f1.o:f1.c practica3.h
	cc -c f1.c -g 
f2.o:f2.c practica3.h
	cc -c f2.c -g
clean:
	rm -f *.o
	rm -f *.solve

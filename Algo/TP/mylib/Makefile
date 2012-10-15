#Creer un binaire a partir de mainpalin.o et palin.o

1mainpalin.o : mainpalin.c palin.h
	gcc -c -Wall mainpalin.c

1palin.o : palin.c palin.h
	gcc -c -Wall palin.c

1palin : mainpalin.o palin.o       
	gcc -o palin mainpalin.o palin.o -lreadline   

#Creer un binaire a partir de mainana.o et ana.o

2mainana.o : mainana.c palin.h
	gcc -c -Wall mainana.c

2ana.o : ana.c ana.h
	gcc -c -Wall ana.c

2ana : mainana.o ana.o
	gcc -o ana mainana.o ana.o -lreadline


#Creer une library en incluant palin.o et ana.o

palin : mainpalin.o
	gcc -o palin mainpalin.o -L. -lmylib -lreadline

mainpalin.o : mainpalin.c
	gcc -c -Wall mainpalin.c

libmylib.a : palin.o ana.o
	ar -rs libmylib.a palin.o ana.o

palin.o : palin.c mylib.h
	gcc -Wall -c palin.c

ana.o : ana.c mylib.h
	gcc -Wall -c ana.c

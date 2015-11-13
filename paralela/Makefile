ALL: parallel suma pi
.PHONY=clean, run

clean:
	\rm -f parallel suma pi

parallel: main.c
	gcc -fopenmp main.c -o parallel

suma: suma.c
	gcc -fopenmp suma.c -o suma

pi: ejercicio.c
	gcc -fopenmp ejercicio.c -o pi

run: parallel
	./parallel

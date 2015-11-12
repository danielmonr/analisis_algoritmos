ALL: parallel
.PHONY=clean, o

clean:
	\rm -f parallel

parallel: main.c
	gcc -fopenmp main.c -o parallel

o: parallel
	./parallel

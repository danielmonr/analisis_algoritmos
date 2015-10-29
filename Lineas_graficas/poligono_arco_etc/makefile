ALL: ej1 ej2 ej3
.PHONY = clean 1 2 3

clean:
	\rm -f ej*

ej1:main.c
	gcc main.c -lgraph -lm -o ej1

ej2:arco.c
		gcc arco.c -lgraph -lm -o ej2

ej3:figuras.c
	gcc figuras.c -lgraph -lm -o ej3

1:ej1
	./ej1

2:ej2
	./ej2

3:ej3
	./ej3

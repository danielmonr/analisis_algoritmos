/* Algoritmo DDA para el trazado de líneas */

#include <stdio.h>
#include <math.h>
#include <graphics.h>

#define PI 3.14159265

int DDALine(int x0, int y0, int x1, int y1, int puntos[]);
void generaArchivo(int puntos[], int count);
int poligono(int n, int puntos[]);

int main(int argc, char **argv)
{
	int nl, x1, y1, x2, y2;
	
	int gd = DETECT, gm = VGAMAX;

	int puntos[1000], count;

	printf("Entre el numero de lados: ");
	scanf("%d", &nl);

	initgraph(&gd, &gm, NULL);

	poligono(nl, puntos);

	getch();

	closegraph();
	
	return 0;
}

int poligono(int n, int puntos[]){
	int x1, y1, x2, y2;
	int r = 360;
	x1 = getmaxx()/ 2 - 100;
	y1 = getmaxy()/2;
	int i, m = 0;
	for (m = 0; m < n; ++m){
		i = i + (360/n);
		x2 = getmaxx()/2 + (100*cos(i*PI/180.0));
		y2 = getmaxy()/2 + (100*sin(i*PI/180.0));
		DDALine(x1, y1, x2, y2, puntos);
		x1 = x2;
		y1 = y2;
		//printf("Se creo una linea de coordenadas x1: %d, x2: %d, y1: %d, y2: %d", x1, x2, y1, y2);
	}
return i;	
}

/* Algoritmo DDA */
int DDALine(int x0, int y0, int x1, int y1, int puntos[])
{
	int maxY, i;

	float dx, dy, m, x, y;
	
	i=0;

	dx=x1-x0;
	dy=y1-y0;

	maxY=getmaxy();

	if (dx == 0) /* Es una línea vertical */
	{
		for(y = y0; y <= y1; ++y)
		{
			putpixel(x0, maxY-y, WHITE);
			puntos[i] = x0;
			puntos[i+1] = y;
			i += 2;
		}
	}
	else if (dy == 0) /* Es una línea horizontal */
	{
		for(x = x0; x <= x1; ++x)
		{
			putpixel(x, y0, WHITE);
			puntos[i] = x0;
			puntos[i+1] = y;
			i += 2;
		}
	}
	else if (dy <= dx) /* Es una línea con pendiente < 1 */
	{
		m = dy/dx;
		y = y0;
		
		for(x = x0; x <= x1; ++x)
		{
			putpixel(x, (int)(maxY-y), WHITE);
			puntos[i] = x;
			puntos[i+1] = (int)y;
			i += 2;
			y = y + m;
		}
	}
	else /* Es una línea con pendiente > 1 */
	{
		m = dx/dy;
		x = x0;
		for(y = y0; y <= y1; ++y)
		{
			putpixel((int)x, maxY-y, WHITE);
			puntos[i] = (int)x; 
			puntos[i+1] = y;
			i += 2;
			x = x + m;
		}
	}
	
	return i;
 }


/* Guardar los puntos dibujados en un archivo */
void generaArchivo(int puntos[], int count)
{
	FILE *fp;
	
	int i,np;
	
	fp=fopen("puntos.txt","w");

	fprintf(fp,"%s","Los puntos dibujados son:\n");

	np=0;

	for(i = 0; i < count; i += 2)
	{
		fprintf(fp,"(%d, %d) ", puntos[i], puntos[i+1]);

		np++;

		if(np==5) { fprintf(fp,"\n"); np=0; }
	}

	fclose(fp);
}

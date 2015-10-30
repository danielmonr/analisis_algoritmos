/*
 * =====================================================================================
 *
 *       Filename:  modificacion.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  29/10/15 13:38:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <graphics.h>
#include <vector>

#define PI 3.14159265
#define N 5

void init();
int DDALine(int x0, int y0, int x1, int y1);
int poligono(int n);

typedef struct punto{
  int x;
  int y;
}*p;

punto* origen;
std::vector<p> poligono;
punto solucion[5];
int traslacion[3][3];

int main(){
  int gd = DETECT, gm = VGAMAX;
  initgraph(&gd, &gm, NULL);
  init();

  closegraph();
  return 0;
}

void init(){
	origen->x = getmaxx()/2;
	origen->y = getmaxy()/2;
	poligono(N);
	for (auto item:poligono){
		solucion[i].x = item->x;
		solucion[i].y = item->y;

	}
}

void transformar(char t, int xi, yi){
	switch(t){
		case 't':
			solucion
			break;
		case 'r':
			break;
		case 'e':
			break;
		case 'f':
			break;
	}
}

void traslacion(int xi, int yi){
	for (int i = 0; i <N; ++i){
		solucion[i].x += xi;
		solucion[i].y += yi;
	}
}

void rotacion(int a){
	for(int i = 0; i < N; ++i){
		solucion[i].x = cos(a*PI/180.0)*solucion[i].x - sin(a*PI/180.0)*solucion[i].y;
		solucion[i].y = cos(a*PI/180.0)*solucion[i].y + sin(a*PI/180.0)*solucion[i].x;
	}
}

int poligono(int n){
	int x1, y1, x2, y2;
	int r = 360;
	int mitadx = getmaxx()/2 + 100;
	int mitady = getmaxy()/2 + 100;
	x1 = mitadx + 100;
	y1 = mitady;
	float i = 0;
	int m = 0;
	p  p1= new (struct punto);
	p1->x = x1;
	p1->y = y1;
	poligono.push_back();
	for (m = 0; m < n; ++m){
		i = i + (360/n);
		x2 = mitadx + (100*cos(i*PI/180.0));
		y2 = mitady + (100*sin(i*PI/180.0));
		DDALine(x1, y1, x2, y2);
		p1 = new (struct punto);
		p1->x = x2;
		p1->y = y2;
		poligono.push_back(p1);

		x1 = x2;
		y1 = y2;
	}
return i;
}

/* Algoritmo DDA */
int DDALine(int x0, int y0, int x1, int y1)
{
	int maxY, i, temp;

 	float dx, dy, m, x, y;

 	i=0;



	dx=x1-x0;
	dy=y1-y0;

	maxY=getmaxy();

	if (dx == 0) /* Es una línea vertical */
	{
	  if (y0 > y1){
	    temp = y1;
	    y1 = y0;
	    y0 = temp;
			temp = x1;
			x1 = x0;
			x0 = temp;

	  }
		for(y = y0; y <= y1; ++y)
		{
			putpixel(x0, maxY-y, WHITE);
			i += 2;
		}
	}
	else if (dy == 0) /* Es una línea horizontal */
	{
		if (x0 > x1){
	    temp = y1;
	    y1 = y0;
	    y0 = temp;
			temp = x1;
			x1 = x0;
			x0 = temp;

	  }
		for(x = x0; x <= x1; ++x)
		{
			putpixel(x, y0, WHITE);
			i += 2;
		}
	}
	else if (dy <= dx) /* Es una línea con pendiente < 1 */
	{
		if (x0 > x1){
			temp = y1;
			y1 = y0;
			y0 = temp;
			temp = x1;
			x1 = x0;
			x0 = temp;

		}
		m = dy/dx;
		y = y0;

		for(x = x0; x <= x1; ++x)
		{
			putpixel(x, (int)(maxY-y), WHITE);
			i += 2;
			y = y + m;
		}
	}
	else /* Es una línea con pendiente > 1 */
	{
		if (y0 > y1){
	    temp = y1;
	    y1 = y0;
	    y0 = temp;
			temp = x1;
			x1 = x0;
			x0 = temp;

	  }
		m = dx/dy;
		x = x0;

		for(y = y0; y <= y1; ++y)
		{
			putpixel((int)x, maxY-y, WHITE);
			i += 2;
			x = x + m;
		}
	}

	return i;
 }

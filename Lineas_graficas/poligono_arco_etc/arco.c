/*
 * =====================================================================================
 *
 *       Filename:  arco.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  28/10/15 19:32:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */


 /* Algoritmo MidPointCircle */
 #include <graphics.h>
 #include <stdio.h>

 int circlePoints(int x, int y, int puntos[], int i);
 int midPointCircle(int radius, int puntos[]);

 int main()
 {
 	int gd=DETECT, gm;
 	int radius;

 	int puntos[10000];
 	int count=0;

 	printf("Entre el radio de la circunferencia: ");
 	scanf("%d",&radius);

 	initgraph(&gd, &gm, NULL);

 	count = midPointCircle(radius, puntos);

 	getch();
 	closegraph();

 	return 0;
 }

 /* Dibuja por simetría en todos los octantes */
 int circlePoints(int x, int y, int puntos[], int i)
 {
 	int maxx = getmaxx()/2;
 	int maxy = getmaxy()/2;

 	putpixel(maxx+x,maxy+y,WHITE);

 	puntos[i]=maxx+x;
 	puntos[i+1]=maxy+y;
 	i+=2;

 	putpixel(maxx+y,maxy+x,WHITE);
 	putpixel(maxx-x,maxy+y,WHITE);
 	//putpixel(maxx+y,maxy-x,WHITE);
 	//putpixel(maxx+x,maxy-y,WHITE);
 	putpixel(maxx-y,maxy+x,WHITE);
 	//putpixel(maxx-x,maxy-y,WHITE);
 	//putpixel(maxx-y,maxy-x,WHITE);

 	return i;
 }

 /* Algoritmo MidPointCircle */
 int midPointCircle(int radius, int puntos[])
 {
 	int x = 0, y = radius;
 	double p = 5.0/4.0-radius;
 	int i = 0;

 	i = circlePoints(x, y, puntos, i);

 	while(y>x)
 	{
 		if(p < 0)
 			p += 2.0 * x + 1.0;
 		else
 		{
 			p += 2.0 * (x - y) + 1.0;
 			y--;
 		}

 		x++;

 		i = circlePoints(x, y, puntos, i);
 	}

 	return i;
 }

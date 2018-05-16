#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include<stdio.h>
#include <iostream>
#include <math.h>
#include<stdlib.h>
int x1, b, x2, y2;

void myInit() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y)
{
	glBegin(GL_POINTS);
	glColor3f (1.0, 1.0, 1.0);
	glVertex2i(x, y);
	glEnd();
}
void draw_gray(int x, int y)
{
	glBegin(GL_POINTS);
	glColor3f (0.5, 0.5, 0.5);
	glVertex2i(x, y);
	glEnd();
}
void draw_line(int x1, int x2, int b, int y2)
{
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2-x1;
	dy = y2-b;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1)
		incx = -1;
	incy = 1;
	if (y2 < b)
		incy = -1;
	x = x1;
	y = b;
	if (dx > dy) 
	{
		draw_pixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) 
		{
			if (e >= 0)
			{
				y += incy;
				draw_gray(x,y);
				e += inc1;
				x += incx;
			}
			else
				{e += inc2;x += incx;
				draw_gray(x,y-incy);}
			draw_pixel(x, y);
		}
	}
	else
	{
		draw_pixel(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++)
		{
			if (e >= 0)
			{
				x += incx;
				draw_gray(x,y);
				y += incy;
				e += inc1;
				
			}
			else
				{e += inc2; y += incy;
			draw_gray(x+incx,y);}
			
			draw_pixel(x, y);
		}
	}
}

void myDisplay() 
{
	//draw_line(0,500,250,250);
	//draw_line(250,250,0,500);
	draw_line(x1, x2, b, y2);
	glFlush();
}

void main(int argc, char **argv)
{

	printf( "Enter (x1, b, x2, y2)\n");
	scanf("%d %d %d %d", &x1, &b, &x2, &y2);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham's Line Drawing");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
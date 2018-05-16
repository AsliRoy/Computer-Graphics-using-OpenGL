#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<Windows.h>
int h,k;
float a,b;

void drawDot (GLint x, GLint y, GLfloat r, GLfloat g, GLfloat b)
{ glColor3f(r,g,b);
glPointSize(1.0);
  glBegin (GL_POINTS);
          glVertex2i (x,y);
  glEnd();
}

void symmetricPixels (int x, int y, int xc, int yc, float r, float g, float b)
{ drawDot (xc + x, yc + y, r,g,b);
  drawDot (xc - x, yc + y,r,g,b);
  drawDot (xc + x, yc - y,r,g,b);
  drawDot (xc - x, yc - y,r,g,b);
}

void Ellipse (int a, int b, int xc, int yc, float r, float g, float bl)
{ int aSq,bSq,twoASq,twoBSq,d,dx,dy,x,y;
  aSq = a*a;
  bSq = b*b;
  twoASq = 2*aSq;
  twoBSq = 2*bSq;
  d = bSq - b*aSq + aSq/4;
  dx = 0;
  dy = twoASq*b;
  x = 0;
  y = b;
  symmetricPixels(x,y,xc,yc,r,g,bl);
  while (dx < dy)
  { x++;
    dx += twoBSq;
    if (d >= 0)
    { y--;
      dy -= twoASq;
    }
    if (d < 0)
     d += bSq + dx;
    else
     d += bSq + dx - dy;
    symmetricPixels (x,y,xc,yc,r,g,bl);
  }
  d = (int)(bSq*(x+0.5)*(x+0.5) + aSq*(y-1)*(y-1) -
                 aSq*bSq);
  while (y > 0)
  { y--;
    dy -= twoASq;
    if (d <= 0)
    { x++;
      dx += twoBSq;
    }
    if (d > 0)
         d += aSq - dy;
    else
         d += aSq -dy +dx;
    symmetricPixels(x,y,xc,yc,r,g,bl);
  }
  glFlush();
}


 void display(void)
 {

         double I,J;
         int i,j;
         glClear (GL_COLOR_BUFFER_BIT);
         glColor3f (1.0, 0.0, 0.0);
         glBegin(GL_POINTS);
         while(1)
         {
                Ellipse (a,b,h,k,1,1,1);
                Sleep(100);        
                Ellipse (a,b,h,k,0,0,0);

				Ellipse (a-10,b,h,k,1,1,1);
				Sleep(100);        
				Ellipse (a-10,b,h,k,0,0,0);

				Ellipse (a-20,b,h,k,1,1,1);
				Sleep(100);        
				Ellipse (a-20,b,h,k,0,0,0);

         Ellipse (a-30,b,h,k,1,1,1);
         Sleep(100);        
         Ellipse (a-30,b,h,k,0,0,0);
         }
         
         glEnd();
         glFlush();
 }
void init(void)
{
        glClearColor (0.0, 0.0, 0.0, 0.0);
        glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}
int main(int argc, char** argv)
{
         printf("Enter the center of ellipse:\n");
         scanf("%d %d",&h,&k);
         printf("Enter the parameters a & b:\n");
         scanf("%f %f",&a,&b);
         glutInit(&argc, argv);
         glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
         glutInitWindowSize (500, 500);
         glutInitWindowPosition (100, 100);
         glutCreateWindow ("Ellipse : Polynomial Method ");
         init ();
         glutDisplayFunc(display);
         glutMainLoop();
         return 0;
}
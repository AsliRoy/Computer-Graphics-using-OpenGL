#include <gl/glut.h>
#include <stdio.h>

int x1, y1, x2, y2;
float m;
int c;
int x,y,x_new,y_new;
float mat[3][3];
void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}


void draw_line(float m,int c){
	int x1,x2,y1,y2;
	x1 = 0;
	x2 = 400;
	if(m>=0){
	y1 = m * x1 + c;
	y2 = m * x2 + c;
	
	}
	else
	{
		y1 = 400;
		y2 = 0;
		x1 = (y1 - c) / m;
		x2 = (y2 - c) / m;
	}
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();

	mat[0][0] = (1-m*m) / (1+m*m);
	mat[0][1] = (2*m) / (1+m*m);
	mat[0][2] = ( -2 * c * m) / (1+m*m);
	mat[1][0] = (2*m) / (1+m*m);
	mat[1][1] = (m*m - 1) / (1+m*m);
	mat[1][2] = ( 2 * c ) / (1+m*m);
	mat[2][0] = 0;
	mat[2][1] = 0;
	mat[2][2] = 1;

	int i,j;
	x_new = mat[0][0]*x + mat[0][1]*y + mat[0][2];
	y_new = mat[1][0]*x + mat[1][1]*y + mat[1][2];

	glPointSize(5);
	glBegin(GL_POINTS);	
	glVertex2i(x, y);
	glVertex2i(x_new, y_new);
	glEnd();
}


void myDisplay() {
	draw_line(m,c);
	glFlush();
}

void main(int argc, char **argv) {

	printf("\nEnter the value of m : ");
	scanf("%f",&m);
	printf("\nEnter the value of c : ");
	scanf("%d",&c);
	printf("\nEnter the x-coordinate of the point : ");
	scanf("%d",&x);
	printf("\nEnter the y-coordinate of the point : ");
	scanf("%d",&y);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham's Line Drawing");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
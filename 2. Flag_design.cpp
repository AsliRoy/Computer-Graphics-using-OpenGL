#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <math.h>

#define HEIGHT 600
#define WIDTH 600

unsigned char matrix[HEIGHT][WIDTH][3]; // r,g,b
double offset=0;

void init()
{
    int i,j;
	//stick
	for(i=50;i<500;i++)
		for(j=25;j<50;j++)
        {
            matrix[i][j][0] = 139; // red
            matrix[i][j][1] = 69; // green
            matrix[i][j][2] = 19; // blue
        }


    for(i=350;i<400;i++)
        for(j=50;j<275;j++) // 2:3 ratio flag
        {
            matrix[i][j][0] = 0; // red
            matrix[i][j][1] = 255; // green
            matrix[i][j][2] = 0; // blue
        }

    for(i=400;i<450;i++)
        for(j=50;j<275;j++)
        {
            matrix[i][j][0] = 255; // red
            matrix[i][j][1] = 255; // green
            matrix[i][j][2] = 255; // blue
        }

    for(i=450;i<500;i++)
        for(j=50;j<275;j++)
        {
            matrix[i][j][0] = 255; // red
            matrix[i][j][1] = 153; // green
            matrix[i][j][2] = 51; // blue
        }
	
		
    glClearColor(0,0,0.4,0);
    glOrtho(-1,1,-1,1,-1,1);
}
void DrawCircle(float cx, float cy, float r, int num_segments) 
{ 
	glBegin(GL_LINE_LOOP); 
	glColor3d(0,0,255);
	for(int ii = 0; ii < num_segments; ii++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 

	} 
	glEnd();
	
}
void DrawLines(float cx, float cy, float r, int num_segments) 
{ 
	glBegin(GL_LINE_LOOP); 
	glColor3d(0,0,255);
	for(int ii = 0; ii < num_segments; ii++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 
		
		glBegin(GL_LINES);
		glVertex2f(-0.48, 0.415);
	} 
	glEnd();
	
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawPixels(WIDTH,HEIGHT,GL_RGB,GL_UNSIGNED_BYTE,matrix);

	
	DrawCircle(-0.48,0.415,0.07,200);
	DrawLines(-0.48,0.415,0.07,24);
    glutSwapBuffers();


}

void idle()
{
    static float count = 0.0;

    int i,j;
    count += 0.05;
    offset-=0.14;

     for(i=350;i<400;i++)
        for(j=50;j<275;j++)
        {
            matrix[i][j][0] = 0; // red
            matrix[i][j][1] = 230 + 25 * sin(count + j * 0.02); // green
            matrix[i][j][2] = 0; // blue
        }

	for(i=400;i<450;i++)
        for(j=50;j<275;j++)
        {
            matrix[i][j][0] = 230 + 25 * sin(count + j * 0.02); // red
            matrix[i][j][1] = 230 + 25 * sin(count + j * 0.02); // green
            matrix[i][j][2] = 230 + 25 * sin(count + j * 0.02); // blue
        }

    for(i=450;i<500;i++)
        for(j=50;j<275;j++)
        {
            matrix[i][j][0] = 230 + 25 * sin(count + j * 0.02); // red
            matrix[i][j][1] = 128 + 25 * sin(count + j * 0.02); // green
            matrix[i][j][2] = 26 + 25 * sin(count + j * 0.02); // blue
        }

    glutPostRedisplay();
}

void main( int argc, char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutInitWindowPosition(100,100);
    glutCreateWindow("FLAG");
    glutDisplayFunc(display);
	
    glutIdleFunc(idle);
    init();
	
    glutMainLoop();
}
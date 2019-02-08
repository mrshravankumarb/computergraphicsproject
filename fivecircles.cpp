#include "stdafx.h"
#include<GL/glut.h>
#include<math.h>

#define max 5

GLint ini[max] = { 10, 2, 4, 6, 8 }; //initial state of circle
typedef struct circle
{
	GLfloat x, y, r;
}circle;

circle cc[max];

void initial_c()
{

	for (int i = 0; i<max; i++)
	{
		cc[i].r = ini[i] * 2;
		cc[i].y = 50;
		if (i != 0)
			cc[i].x = cc[i - 1].x + 30;
		else
			cc[i].x = 50.0;
		printf("i=%d x=%f y %f r %f\n",i ,cc[i].x, cc[i].y, cc[i].r);
	}
}

void draw(circle c)
{
	float i;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(c.x, c.y);
	for (i = 0; i<360; i++)
		glVertex2f(c.x + sin(i)*c.r, c.y + cos(i)*c.r);
	glEnd();
	glutSwapBuffers();

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(0.0,1.0,0.0);
	//circle cc;
	for (int i = 0; i<max; i++)
	{
		//glColor3f(1.0,1.0,0.0);
		draw(cc[i]);
	}
	glFlush();

}

void init(void)
{
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0, 150.0);

}



void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowPosition(50, 50);
	glutInitWindowSize(900, 600);
	glutCreateWindow("CG PROJECT");

	init();
	initial_c();

	glutDisplayFunc(display);

	glutMainLoop();



}
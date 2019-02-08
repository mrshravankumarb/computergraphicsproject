// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<glut.h>
#include<math.h>

#define max 5
#define screenmax 200

GLfloat ini[max] = { 10, 2, 6, 4, 8 }; 
GLfloat sum=0,difference;
//initial state of circle
typedef struct circle
{
	GLfloat x, y, r;
}circle;

circle cc[max];

void initial_c()
{
	for (int i = 0; i < max; i++)
		sum =sum + ini[i];
	printf("sum=%f", sum*2);
	difference = (screenmax - sum * 4 - 10) / 5;
	printf("dif=%f", difference);

	for (int i = 0; i<max; i++)
	{
		cc[i].r = ini[i] * 2;
		cc[i].y = 100;
		if (i != 0)
			cc[i].x = cc[i-1].x + cc[i - 1].r + cc[i].r+difference;
		else
			cc[i].x = cc[i].r+10;
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
	//gluOrtho2D(0, 200, 0,200);

}

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		gluOrtho2D(0, screenmax, 0 * (GLfloat)h / (GLfloat)w, screenmax * (GLfloat)h / (GLfloat)w);
	else
		gluOrtho2D(0 * (GLfloat)w / (GLfloat)h, screenmax * (GLfloat)w / (GLfloat)h, 0, screenmax);
	glMatrixMode(GL_MODELVIEW);
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
	glutReshapeFunc(myReshape);
	glutMainLoop();



}
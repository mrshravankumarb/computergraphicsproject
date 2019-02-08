
// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<glut.h>
#include<math.h>

#define max 5
#define screenmax 200
GLint flag;

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


void front_text(float x,float y,float z,char *text)
{

//char *i;
glRasterPos3f(x,y,z);
for(char *i=text;*i!='\0';i++)
{
	glColor3f(0.0,0.0,1.0);

	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*i);
}

}

void frontscreen(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0,0,1);
 front_text(56.0,190.0,0.0,"RAJARAJESHWARI COLLEGE OF ENGINEERING ");
 glColor3f(0.7,0,1);
  front_text(40.0,175.0,0.0,"DEPARTMENT OF COMPUTER SCIENCE \nAND \nENGINEERING");
 glColor3f(1,0.5,0);
  front_text(90.0,160.0,0.0,"A MINI PROJECT ON");
 glColor3f(1,0,0);
  front_text(75.0,145.0,0.0,"BUBBLE SORT ALGORITHM");
 glColor3f(1,0.5,0);
  front_text(00.0,110.0,0.0,"BY:");
 glColor3f(0.5,0,0.5);
  front_text(0.0,95.0,0.0,"SITHARA NS		(1RR15CS106)");
  front_text(0.0,80.0,0.0,"SHRAVAN KUMAR B   (1RR15CS104)");
 glColor3f(1,0.5,0);
  front_text(100.0,50.0,0.0,"PRESS ENTER TO START");
 glFlush();
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

	if(flag==0)
	frontscreen ();


	if(flag==1)
	{
	for (int i = 0; i<max; i++)
	{
		//glColor3f(1.0,1.0,0.0);
		draw(cc[i]);
	}
	}
	glFlush();
	

}
void myKeyboardFunc( unsigned char key, int x, int y )

{
  switch(key)
 {
 case 13:if(flag==0) //Ascii of 'enter'= 13
    flag=1;
  break;
       }
    display();
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
	glutInitWindowSize(1024, 768);
	glutCreateWindow("CG PROJECT");

	init();
	initial_c();

	glutDisplayFunc(display);
	glutReshapeFunc(myReshape);
	glutKeyboardFunc(myKeyboardFunc);
	glutMainLoop();



}

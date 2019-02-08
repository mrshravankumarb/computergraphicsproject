// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<glut.h>
#include<math.h>

#define max 5
#define screenmax 200
#define bigO(n) n*(n+1)/2 
GLfloat ini[max] = { 8, 9, 3, 5, 1 };
GLfloat temp[max] = { 8, 9, 3, 5,1 };
GLfloat mat[bigO(max)][max];
int changes[bigO(max)];
GLfloat  sum = 0, difference,temp1;
int count = 0, n = 5,stage=0;
bool first = true;
//initial state of circle
void bubbleSort();
void copy();
void print_matrix();
typedef struct circle
{
	GLfloat x, y, r;
}circle;

circle cc[max];

void initial_c()
{
	if (first){
		bubbleSort();//on console
		print_matrix();
		printf("\n");
		for (int i = 0; i < count; i++)
			printf("%f ", (GLfloat)changes[i]);
		printf("\n");
		for (int i = 0; i < max; i++)
			sum = sum + ini[i];
		printf("sum=%f", sum * 2);
		difference = (screenmax - sum * 4 - 10) / 5;
		printf("dif=%f", difference);
		first = false;
		//return;
	}
	for (int i = 0; i<max; i++)
	{
		cc[i].r = mat[stage][i] * 2;
		cc[i].y = 100;
		if (i != 0)
			cc[i].x = cc[i - 1].x + cc[i - 1].r + cc[i].r + difference;
		else
			cc[i].x = cc[i].r + 10;
		printf("\ni=%d x=%f y %f r %f", i, cc[i].x, cc[i].y, cc[i].r/2);
	}
	printf("\ns%d %d",stage, count);
	
}

void draw(circle c,int inde)
{
	float i;
	glBegin(GL_TRIANGLE_FAN);
	printf("cha%d %d", changes[stage], inde);
	if (changes[stage] == inde )
		glColor3f(1.0, 0.0, 0.0);
	else if (changes[stage] + 1 == inde)
		glColor3f(1.0, 1.0, 0.0);
	else
		glColor3f(0.0, 1.0, 0.0);
	glVertex2f(c.x, c.y);
	for (i = 0; i<360; i++)
		glVertex2f(c.x + sin(i)*c.r, c.y + cos(i)*c.r);
	glEnd();
	glutSwapBuffers();

}
void wait(void)
{
	int i, j;
	for (i = 1; i<9000; i++)
		for (j = 1; j<9000; j++);
}
void display()
{	
	printf("display count %d", stage);
		glClear(GL_COLOR_BUFFER_BIT);
		//glColor3f(0.0,1.0,0.0);
		//circle cc;
		
		for (int i = 0; i < max; i++)
		{
			//glColor3f(1.0,1.0,0.0);
			draw(cc[i],i);
		}
		initial_c();
		glFlush();
		//for (int i = 0; i < 10;i++)
		//wait();
	

}

void init(void)
{
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	//gluOrtho2D(0, 200, 0,200);

}

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h){
		gluOrtho2D(0, screenmax, 0 * (GLfloat)h / (GLfloat)w, (GLfloat)screenmax * (GLfloat)h / (GLfloat)w);
	//	printf("\n%f %f %f %f here", 0, (200.0), 0 * (GLfloat)h / (GLfloat)w, (GLfloat)screenmax * (GLfloat)h / (GLfloat)w);
	}
	else
	{
		gluOrtho2D(0 * (GLfloat)w / (GLfloat)h, (GLfloat)screenmax * (GLfloat)w / (GLfloat)h, 0, (GLfloat)screenmax);
		//printf("\n%f %f %f %f", 0 * w / h,(GLfloat)w, 0, (float)screenmax);
	}
	glMatrixMode(GL_MODELVIEW);
}
void key(unsigned char key, int x, int y)
{
	//printf("%d %d", key, enter);
	if (key == 'n' || key == 'N')
	{
		if (stage<count - 1)
			stage++;
		display();
	}

}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("CG PROJECT");
	init();
	glutKeyboardFunc(key);
	//initial_c();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	
	glutMainLoop();



}

void change(int j){
	changes[count-1] = j;
}

void bubbleSort()

{

	int i, j;
	copy();
	change(-999);
	for (i = 0; i < n - 1; i++)



		// Last i elements are already in place   

		for (j = 0; j < n - i - 1; j++)

			if (temp[j] > temp[j + 1]){
				temp1 = temp[j];
				temp[j]= temp[j + 1];
				temp[j + 1] = temp1;
				copy();
				change(j);
			}

}

void copy()

{
	for (int k = 0; k < max; k++){

		mat[count][k] = temp[k];
		printf("p%f ", (float)mat[count][k]);
	}
	printf("\n");
	count++;
}

void print_matrix()
{
	for (int i = 0; i < count; i++){
		for (int j = 0; j < n; j++)
			printf("%f ", (float)mat[i][j]);
		printf("\n");
		}
}

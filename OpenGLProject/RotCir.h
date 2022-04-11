#include <iostream>
#include <GL\glut.h>
#include <GL\GLU.h>
#include <GL\GL.h>

static float r = 0;
static bool canRot = false;

void rot(int)
{
	r += 1;
	glutTimerFunc(100, rot, 0);
	glutPostRedisplay();
}

void quartCircle(float raduis)
{
	glBegin(GL_POLYGON);
	{
		glVertex3f(0, 0, 0);
		for (int i = 0; i < 20; i++)
		{
			float theta = 0.55 * 3.1415926f * i / 20;

			float x = raduis * cosf(theta ) ;
			float z = raduis * sinf(theta ) ;

			glVertex3f(x, 0, z);
		}
	}
	glEnd();
}

void rotCircle()
{
	glPushMatrix();
	glTranslatef(0, 0, -4.5);
	glRotatef(r, 0, 1, 0);
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
		{
			glColor3f(1, 1, 1);
		}
		else
		{
			glColor3f(1, 0, 0);
		}
		glRotatef(90 , 0, 1, 0);
		quartCircle(1);
	}
	glPopMatrix();
}
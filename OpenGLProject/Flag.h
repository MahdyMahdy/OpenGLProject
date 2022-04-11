#include <iostream>
#include <GL\glut.h>
#include <GL\GLU.h>
#include <GL\GL.h>

static float fx =0;
static bool goingLeft = true;


void arze(float height, float width)
{
	glPushMatrix();
	glTranslatef(fx, 0, 0);
	glBegin(GL_POLYGON);
	{
		glColor3f(0, 1, 0);
		glVertex3f(0, 0, width / 6);
		glVertex3f(height/5, 0, -width / 6);
		glVertex3f(-height / 5, 0, -width / 6);
	}
	glEnd();
	glBegin(GL_POLYGON);
	{
		glColor3f(0, 1, 0);
		glVertex3f(height / 16, 0, -width / 6);
		glVertex3f(height / 16, 0, -width / 4.5);
		glVertex3f(-height / 16, 0, -width / 4.5);
		glVertex3f(-height / 16, 0, -width / 6);
	}
	glEnd();
	glPopMatrix();
}

void flag(float height,float width)
{
	glPushMatrix();
	glBegin(GL_QUADS);
	{
		glColor3f(1, 0, 0);
		glVertex3f(height / 2, 0, width / 2);
		glVertex3f(-height / 2, 0, width / 2);
		glVertex3f(-height / 2, 0, width / 4);
		glVertex3f(height / 2, 0, width / 4);

		glVertex3f(height / 2, 0, -width / 2);
		glVertex3f(-height / 2, 0, -width / 2);
		glVertex3f(-height / 2, 0, -width / 4);
		glVertex3f(height / 2, 0, -width / 4);

		glColor3f(1, 1, 1);
		glVertex3f(height / 2, 0, width / 4);
		glVertex3f(-height / 2, 0, width / 4);
		glVertex3f(-height / 2, 0, -width / 4);
		glVertex3f(height / 2, 0, -width / 4);
		
	}
	glEnd();
	arze(height, width);
	glPopMatrix();
}
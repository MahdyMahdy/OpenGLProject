#include <GL\glut.h>
#include <GL\GLU.h>
#include <GL\GL.h>

void standing(float height,float tranZ)
{
	glPushMatrix();
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	glTranslatef(0, 0, tranZ);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(quadratic, 0.025, 0.025, height, 32, 32);
	glPopMatrix();
}

void bar(float width,float transY)
{
	glPushMatrix();
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	glTranslatef(0, transY, -width / 2);
	gluCylinder(quadratic, 0.025, 0.025, width, 32, 32);
	glPopMatrix();
}

void goal(float width,float height)
{
	glPushMatrix();
	glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(0.1, 0, width / 2);
	glRotatef(90, 0, 1, 0);
	bar(0.2, height);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.1, 0, -width / 2);
	glRotatef(90, 0, 1, 0);
	bar(0.2, height);
	glPopMatrix();
	standing(height, width/2);
	standing(height, -width / 2);
	bar(width, height);
	glTranslatef(0.2, 0, 0);
	standing(height, width / 2);
	standing(height, -width / 2);
	bar(width, height);
	glPopMatrix();
}


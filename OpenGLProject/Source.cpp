#include <iostream>
#include <GL/glut.h>
#include <GL\GLU.h>
#include <GL\GL.h>
#include "Floor.h"
#include "Goal.h"
#include "AD.h"
#include "Modaraj.h"
#include "RotCir.h"
#include "Flag.h"


using namespace std;

float x = 0,y = 3,z = 0;
float height = 11,width = 5;
bool jumping = false, flagMove = false , seleted = false;
int rightScore = 0,leftScore=0;

void jump(int)
{
	if(canRot)
		r+=2;
	if (flagMove)
	{
		if (goingLeft)
			fx += 0.1;
		else
			fx -= 0.1;
		if (fx > 1)
		{
			goingLeft = false;
		}
		if (fx < -1)
		{
			goingLeft = true;
		}
	}
	if (y <3 && jumping)
	{
		y += 0.2;
	}
	else if (y == 3 && jumping)
	{
		jumping = false;
	}
	else if(y>0 && !jumping)
	{
		y -= 0.2;
	}
	glutPostRedisplay();
}

void ball()
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glColor3f(1, 1, 1);
	glutSolidSphere(0.1, 50, 50);
	glPopMatrix();
	glutTimerFunc(100, jump, 0);
}

void displayScore(float x, float y, float z,int score)
{
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos3f(x, y,z);
	char s[3];
	sprintf_s(s, "%d", score);
	void * font = GLUT_BITMAP_9_BY_15;

	for (int i = 0; i <3; i++)
	{
		char c = s[i];
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
	glPopMatrix();
}

void display()
{
	glClearColor(0, 1, 1,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	garden(30, 15);
	allModarajat(height, width);
	floor(height, width, 13);
	ad(height + 1, width + 1, 0.3, 11, 5);
	glPushMatrix();
	glTranslatef(height/2, 0, 0);
	goal(1, 0.5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-height / 2, 0, 0);
	glRotatef(180, 0, 1, 0);
	goal(1, 0.5);
	glPopMatrix();
	rotCircle();
	ball();
	glPushMatrix();
	glTranslatef(5, 0, -4.5);
	flag(3, 2);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-5, 0, -4.5);
	flag(3, 2);
	glPopMatrix();
	displayScore(2.5,0,-4.5,leftScore);
	displayScore(-2.5, 0, -4.5, rightScore);
	glFlush();
}


void special(int key,int k1,int k2)
{
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		if(x>-(height+0.5)/2)
			x-= 0.1;
		if (x < -height / 2 && z<0.5 && z>-0.5)
		{
			x = 0;
			z = 0;
			leftScore++;
		}
		break;
	case GLUT_KEY_LEFT:
		if (x<(height + 0.5) / 2)
			x += 0.1;
		if (x > height / 2 && z<0.5 && z>-0.5)
		{
			x = 0;
			z = 0;
			rightScore++;
		}
		break;
	case GLUT_KEY_UP:
		if (z<(width + 0.5) / 2 )
			z += 0.1;
		break;
	case GLUT_KEY_DOWN:
		if (z>-(width + 0.5) / 2)
			z -= 0.1;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


void keyboard(unsigned char key,int ,int )
{
	if (key == ' ' && !jumping)
	{
		jumping = true;
	}
	else if (key == 's')
	{
		canRot = !canRot;
	}
	else if (key == 'm')
	{
		flagMove = !flagMove;
	}
	glutPostRedisplay();
}


void reshape(GLint w, GLint h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30, GLfloat(w) / GLfloat(h), 0, 30);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 12, -15, 0, 0, 0, 0, 1, 0);
}

int wasAtx,wasAty;
void mouse(int button,int state,int mx,int my)
{
	if (button == 0)
	{
		x = (600 - mx)*0.017;
		z = (300 - my)*0.025;
	}
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(1200, 600);
	glutCreateWindow("Football");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	glutMouseFunc(mouse);
	glutMainLoop();
}
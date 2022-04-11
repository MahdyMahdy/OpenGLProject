#include <GL\glut.h>
#include <GL\GLU.h>
#include <GL\GL.h>

void Modaraj(float b1x, float b1z, float b2x, float b2z, float by, float height, float llong , int side)
{
	glBegin(GL_QUADS);
	{
		glColor3f(0.5, 0.5, 0.5);
		glVertex3f(b1x,by,b1z);
		glVertex3f(b2x, by, b2z);
		glVertex3f(b2x, by+height, b2z);
		glVertex3f(b1x, by+height, b1z);

		glColor3f(0, 0, 1);
		glVertex3f(b2x, by + height, b2z);
		glVertex3f(b1x, by + height, b1z);
		if (side >= 0)
		{
			b2x -= llong;
		}
		if (side <= 0)
		{
			b1x += llong;
		}
		glVertex3f(b1x, by + height, b1z + llong);
		glVertex3f(b2x , by+height, b2z+llong);
	}
	glEnd();
}

void Modarajat(int n,float b1x, float b1z, float b2x, float b2z, float height, float llong,int side)
{
	glPushMatrix();
	float llongPerN = llong / n;
	for (int i = 0; i < n; i++)
	{
		Modaraj(b1x + llongPerN * i, b1z+llongPerN*i , b2x - llongPerN * i, b2z + llongPerN*i,height*i, height, llong - llongPerN*i,side);
	}
	glPopMatrix();
}

void allModarajat(float height, float width)
{
	Modarajat(10, + (height + 1.4) / 2, (width + 1.4) / 2, -(height + 1.4) / 2, (width + 1.4) / 2, 0.3,3,0);
	glPushMatrix();
	glTranslatef(3, 0, 0);
	glRotatef(90, 0, 1, 0);
	Modarajat(10, (width + 1.4) / 2, (width + 1.4) / 2, -(width + 1.4) / 2, (width + 1.4) / 2, 0.3, 3,1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-3, 0, 0);
	glRotatef(-90, 0, 1, 0);
	Modarajat(10, (width + 1.4) / 2, (width + 1.4) / 2, -(width + 1.4) / 2, (width + 1.4) / 2, 0.3, 3,-1);
	glPopMatrix();
}

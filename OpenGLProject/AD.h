#include <GL\glut.h>
#include <GL\GLU.h>
#include <GL\GL.h>

void rectangleAD(
	float p1x, float p1z,
	float p2x, float p2z,
	float p3x, float p3y,float p3z,
	float p4x, float p4y,float p4z)
{
	glBegin(GL_QUADS);
	{
		glPushMatrix();
		glVertex3f(p1x,0 , p1z);
		glVertex3f(p2x, 0, p2z);
		glVertex3f(p3x, p3y, p3z);
		glVertex3f(p4x, p4y, p4z);
		glPopMatrix();
	}
	glEnd();
}

void ad(float floorHeight,float floorWidth,float height,int bigPart,int smallPart)
{
	float heighPerPart = floorHeight / bigPart;
	float widthPerPart = floorWidth / smallPart;
	for (int i = 0; i < bigPart; i++)
	{
		if (i % 2 != 0)
		{
			glColor3f(1, 0, 0);
		}
		else
		{
			glColor3f(1, 1, 1);
		}
		rectangleAD(
			-floorHeight/2+i*heighPerPart,floorWidth/2,
			-floorHeight / 2 + (i+1)*heighPerPart, floorWidth / 2,
			-floorHeight / 2 + (i+1)*heighPerPart, height, floorWidth / 2,
			-floorHeight / 2 + i *heighPerPart, height, floorWidth / 2
		);
	}
	for (int i = 0; i < smallPart; i++)
	{
		if (i % 2 == 0)
		{
			glColor3f(1, 0, 0);
		}
		else
		{
			glColor3f(1, 1, 1);
		}
		rectangleAD(
			-floorHeight / 2, floorWidth / 2 - i*widthPerPart,
			-floorHeight / 2, floorWidth / 2 - (i + 1)*widthPerPart,
			-floorHeight / 2, height, floorWidth / 2 - (i + 1)*widthPerPart,
			-floorHeight / 2, height, floorWidth / 2 - i *widthPerPart
		);
		rectangleAD(
			floorHeight / 2, floorWidth / 2 - i*widthPerPart,
			floorHeight / 2, floorWidth / 2 - (i + 1)*widthPerPart,
			floorHeight / 2, height, floorWidth / 2 - (i + 1)*widthPerPart,
			floorHeight / 2, height, floorWidth / 2 - i *widthPerPart
		);
	}

}
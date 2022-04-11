#include <GL\glut.h>
#include <GL\GLU.h>
#include <GL\GL.h>
#define PI 3.1415926f

void point(float cx, float cz)
{
	glBegin(GL_POLYGON);
	{
		for (int i = 0; i < 20; i++)
		{
			float theta = 2.0f * PI * i / 20;

			float x = 0.05 * cosf(theta) +cx;
			float z = 0.05 * sinf(theta) + cz;

			glVertex3f(x, 0, z);

		}
	}
	glEnd();
}

void penaltyRectangle(float p1x, float p1z, float p2x, float p2z, float p3x, float p3z, float p4x, float p4z)
{
	glBegin(GL_LINE_LOOP);
	{
		glPushMatrix();
		glVertex3f(p1x,0, p1z);
		glVertex3f(p2x,0, p2z);
		glVertex3f(p3x, 0, p3z);
		glVertex3f(p4x, 0, p4z);
		glPopMatrix();
	}
	glEnd();
}

void circle(float raduis , float part , float rot ,float cx,float cz)
{
	glBegin(GL_LINE_LOOP);
	{
		if (part == 0.5)
		{
			glVertex3f(cx, 0, cz);
		}
		for (int i = 0; i < 20; i++)
		{
			float theta = part * 3.1415926f * i / 20;

			float x = raduis * cosf(theta + rot)+cx;
			float z = raduis * sinf(theta + rot) + cz;

			glVertex3f(x, 0, z);

		}
	}
	glEnd();
}

void rectangle(float p1x, float p1z, float p2x, float p2z, float p3x, float p3z, float p4x, float p4z)
{
	glBegin(GL_QUADS);
	{
		glPushMatrix();
		glVertex3f(p1x, 0,p1z);
		glVertex3f(p2x, 0,p2z);
		glVertex3f(p3x, 0,p3z);
		glVertex3f(p4x, 0,p4z);
		glPopMatrix();
	}
	glEnd();
}


void outsideFloor(float height, float width)
{
	glPushMatrix();
	glColor3f(0, 0.5f, 0);
	rectangle(-height/2,width/2, -height / 2, width / 2 + 0.5, height / 2, width / 2 + 0.5, height / 2, width / 2  );
	rectangle(-height / 2, -width / 2, -height / 2, -width / 2 - 0.5, height / 2, -width / 2 -0.5, height / 2, -width / 2);
	rectangle(height / 2 , width / 2 + 0.5, height / 2+ 0.5, width / 2+ 0.5, height / 2+ 0.5, -width / 2 - 0.5, height / 2, -width / 2- 0.5);
	rectangle(-height / 2, -width / 2 -0.5, -height / 2 - 0.5, -width / 2 - 0.5, -height / 2 - 0.5, width / 2 + 0.5, -height / 2, width / 2 + 0.5);
	glPopMatrix();
}

void floor(float height,float width,int partitions)
{
	glPushMatrix();
	float partHeight = height / partitions;
	glBegin(GL_QUADS);
	{
		//stade floor with 2 colors 
		for (int i = 0; i < partitions; i++)
		{
			if (i % 2 == 0)
			{
				glColor3f(0, 0.3f, 0);
			}
			else
			{
				glColor3f(0, 0.5f, 0);
			}
			rectangle(-height / 2 + i*partHeight, -width / 2, -height / 2 + i*partHeight, width / 2, -height / 2 + (i + 1)*partHeight, width / 2, -height / 2 + (i + 1)*partHeight, -width / 2);
		}
	}
	glEnd();
	outsideFloor(height, width);
	glColor3f(1, 1, 1);
	//out lines
	glBegin(GL_LINE_LOOP);
	{
		glVertex3f(-height / 2,0, width / 2);
		glVertex3f(height / 2,0, width / 2);
		glVertex3f(height / 2,0, -width / 2);
		glVertex3f(-height / 2,0, -width / 2);
	}
	glEnd();
	//center line
	glBegin(GL_LINE_LOOP);
	{
		glVertex3f(0,0, width / 2);
		glVertex3f(0,0, -width / 2);
	}
	glEnd();
	//center circle
	circle(width/4,2.0f,0,0,0);
	//Penalty rectangles
	penaltyRectangle(-height / 2, width / 4, -height / 3, width / 4, -height / 3, -width / 4, -height / 2, -width / 4);
	penaltyRectangle(height / 2, -width / 4, height / 3, -width / 4, height / 3, width / 4, height / 2, width / 4);
	penaltyRectangle(-height / 2, width / 6.5, -height / 2.3, width / 6.5, -height / 2.3, -width / 6.5, -height / 2, -width / 6.5);
	penaltyRectangle(height / 2, -width / 6.5, height / 2.3, -width / 6.5, height / 2.3, width / 6.5, height / 2, width / 6.5);
	circle(width / 20, 0.5f, PI, height / 2, width / 2);
	circle(width / 20, 0.5f, PI/2, height / 2, -width / 2);
	circle(width / 20, 0.5f, 0, -height / 2, -width / 2);
	circle(width / 20, 0.5f, -PI / 2, -height / 2, width / 2);
	point(height / 2.6, 0);
	point(-height / 2.6, 0);
	circle(width / 6, 0.55f,3*PI/4-0.01, height / 2.6, 0);
	circle(width / 6, 0.55f, - PI / 4 - 0.01, -height / 2.6, 0);
	glPopMatrix();
}


void axes()
{
	glPushMatrix();
	glBegin(GL_QUADS);
	{
		glColor3f(1, 0, 0);
		glVertex3f(-10, 0, 0);
		glVertex3f(10, 0, 0);
		glVertex3f(10, 0.01, 0.01);
		glVertex3f(-10, 0.01, 0.01);

		glColor3f(0, 1, 0);
		glVertex3f(0, -10, 0);
		glVertex3f(0, 10, 0);
		glVertex3f(0.01, 10, 0.01);
		glVertex3f(0.01, -10, 0.01);

		glColor3f(0, 0, 1);
		glVertex3f(0, 0, -10);
		glVertex3f(0, 0, 10);
		glVertex3f(0.01, 0.01, 10);
		glVertex3f(0.01, 0.01, -10);
	}
	glEnd();
	glPopMatrix();
}

void garden(float height,float width)
{
	glPushMatrix();
	glColor3f(0, 1, 0);
	glTranslatef(0, 0, -3);
	glBegin(GL_POLYGON);
	{
		glVertex3f(height / 2,0, width / 2);
		glVertex3f(height / 2,0, -width / 2);
		glVertex3f(-height / 2,0, -width / 2);
		glVertex3f(-height / 2,0, width / 2);
	}
	glEnd();
	glPopMatrix();
}


#include <math.h>

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "drawfunctions.h"
#include "OpenGL.h"
#include <string>
#include "MyForm.h"

float xfrom = 0;
float xto = 10;
float v = 5;
int startTime = 0;

float vx = 5;
float yfrom = 0;
float yto = 10;
float vy = 3;
int startTimex = 0;
int startTimey = 0;

float vr = 90;
float rx = 10;
float ry = 5;

typedef double (*pf)(double x);

bool createMas = false;
float **masF, **masFF;
int masSize;

void InitOpenGL(int width, int height)
{
   glViewport(0,0,width,height);
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   gluPerspective(45.0, (GLfloat)width / height, 1.0, 10000.0);
   //glFrustum(-1.0,1.0,-1.0,1.0,1.5,100.0);

   glMatrixMode( GL_MODELVIEW );

   glEnable(GL_DEPTH_TEST); 
   glClearColor(0.2, 0.3, 0.4, 0.0);

   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
   glEnable(GL_POINT_SMOOTH);

}

void DrawPoint(float x, float y)
{
	glPointSize(10);
	glBegin(GL_POINTS);
		glColor3f(0, 1, 0);
		glVertex3f(x, y, 0);
	glEnd();
}

void DrawLine(float x1, float y1, float z1, float x2, float y2, float z2, float r1, float g1, float b1, float r2, float g2, float b2)
{
	glBegin(GL_LINES);
		glColor3d(r1, g1, b1);
		glVertex3d(x1, y1, z1);
		glColor3d(r2, g2, b2);
		glVertex3d(x2, y2, z2);
    glEnd();
}

void DrawLine(float x1, float y1, float z1, float x2, float y2, float z2, float r1, float g1, float b1)
{
	DrawLine(x1, y1, z1, x2, y2, z2, r1, g1, b1, r1, g1, b1); 
}

void DrawLine(float x1, float y1, float x2, float y2, float r1, float g1, float b1, float r2, float g2, float b2)
{
	DrawLine(x1, y1, 0, x2, y2, 0, r1, g1, b1, r2, g2, b2); 
}

void DrawLine(float x1, float y1, float x2, float y2, float r1, float g1, float b1)
{
	DrawLine(x1, y1, 0, x2, y2, 0, r1, g1, b1, r1, g1, b1); 
}

void DrawLine(float x1, float y1, float x2, float y2)
{
	DrawLine(x1, y1, 0, x2, y2, 0, 1, 1, 1, 1, 1, 1); 
}

void DrawLine(float x1, float y1, float x2, float y2, float size)
{
	glLineWidth(size);
	DrawLine(x1, y1, 0, x2, y2, 0, 1, 1, 1, 1, 1, 1); 
}

void DrawOs()
{
	glPushMatrix();
	double dx = 2;
	DrawLine(-10 * dx, 0, 10 * dx, 0);
	DrawLine(0, -10 * dx, 0, 10 * dx);
	for (int i = -10; i <= 10; i++)
	{
		DrawLine(i * dx, 0.1 * dx, i * dx, -0.1 * dx);
		DrawLine(0.1 * dx, i * dx, -0.1 * dx, i * dx);
	}
	glPopMatrix();
}

float f(float x, short i)
{
	switch (i)
	{
	case 1:
		return sin(x);
	case 2:
		return cos(x) * sin(2 * x);
	case 3:
		return cos(x) * x * x;
	case 4:
		return log(x) + sin(x);
	case 5:
		return exp(x) + sin(x);
	case 6:
		return sqrt(x) * tan(x) * sin(2 * x);
	default:
		break;
	}
}

void GenerateMasByFunc(float** mas, float x1, float x2, float dx)
{
	for (int i = 0; i < masSize; i++)
	{
		mas[0][i] = x1 + dx * i;
		mas[1][i] = f(x1 + dx * i, OpenGL::findex);
	}
}

void DrawFuncMas(float** mas, float xScale, float yScale, float r, float g, float b)
{
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);
	glColor3f(r, g, b);
	for (int i = 0; i < masSize; i++)
		glVertex3f(mas[0][i] * xScale, mas[1][i] * yScale, 0);
	glEnd();
}

void DrawFuncMas(float** dmas, float** mas, float xScale, float yScale)
{
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < masSize; i++)
	{
		glColor3f(1, dmas[1][i], -dmas[1][i]);
		glVertex3f(mas[0][i] * xScale, mas[1][i] * yScale, 0);
	}
	glEnd();
}


void DeleteMas()
{
	if (createMas)
	{
		delete masF[0];
		delete masF[1];
		delete masF;
		delete masFF[0];
		delete masFF[1];
		delete masFF;
	}
}

void CalcDFuncMas(float** mas, float** dmas, float dx)
{
	for (int i = 0; i < masSize; i++)
	{
		dmas[0][i] = mas[0][i];
		if (i < masSize - 1)
			dmas[1][i] = (mas[1][i + 1] - mas[1][i]) / dx;
		else
			dmas[1][i] = (mas[1][i] - mas[1][i - 1]) / dx;
	}
}

void DrawMaxMin(float** mas, float xScale, float yScale)
{
	USHORT maxs, mins = 0;
	for (USHORT i = 0; i < masSize; i += 1)
	{
		if ((mas[0][i] > OpenGL::begin) && (mas[0][i] < OpenGL::end))
		{
			if (mas[1][i] > mas[1][maxs])
				maxs = i;
			if (mas[1][i] < mas[1][mins])
				mins = i;
		};
	}

	DrawPoint(mas[0][maxs] * xScale, mas[1][maxs] * yScale);
	DrawPoint(mas[0][mins] * xScale, mas[1][mins] * yScale);
}

void DrawLocMaxMin(float** masF, float** masFF, float xScale, float yScale)
{
	for (USHORT i = 0; i < masSize; i += 1)
	{
		if (((masFF[1][i] > 0) && (masFF[1][i+1] < 0)) || ((masFF[1][i] < 0) && (masFF[1][i+1] > 0)))
			DrawPoint(masF[0][i+1] * xScale, masF[1][i+1] * yScale);
	}
}

void DrawFuncMasExample2()
{
	float xScale = 5, yScale = 5, x1 = -5, x2 = 5, 
    dx = 0.1; 
    masSize = int((x2 - x1)/dx);
	if (OpenGL::refresh == true)
	{
		DeleteMas();
		createMas = false;
	}

	if (createMas == false) 
	{
		masF = new float *[2];
		masF[0] = new float [masSize];
		masF[1] = new float [masSize];

		GenerateMasByFunc(masF, x1, x2, dx);
		createMas = true;

		masFF = new float *[2];
		masFF[0] = new float [masSize];
		masFF[1] = new float [masSize];

		CalcDFuncMas(masF, masFF, dx);
	}

	if (OpenGL::osvis == true)
		DrawOs();

	if (OpenGL::funcvis == true)
	{
		if (OpenGL::colvis == true)
			DrawFuncMas(masFF, masF, xScale, yScale);
		else
			DrawFuncMas(masF, xScale, yScale, 1, 0, 0);
	}

	if (OpenGL::dervis == true)
		DrawFuncMas(masFF, xScale, yScale, 0, 1, 0);

	if (OpenGL::maxvis == true)
		DrawMaxMin(masF, xScale, yScale);

	if (OpenGL::locmaxvis == true)
		DrawLocMaxMin(masF, masFF, xScale, yScale);
}


void Draw()
{	
	DrawFuncMasExample2();
}
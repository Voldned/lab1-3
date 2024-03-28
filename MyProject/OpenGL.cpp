#include <windows.h>
#include <Windowsx.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "OpenGL.h"
#include "glaux.h"
#include <math.h>
#include"drawfunctions.h"
#include"MyForm.h"

#pragma comment (lib,"opengl32.lib")

using namespace System::Windows::Forms;
using namespace MyProject;


/// ������������� OpenGL
bool OpenGL::InitGL(GLvoid)
{
	glShadeModel(GL_SMOOTH);
	glClearColor(0.1f, 0.2f, 0.3f, 0.5f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	return TRUE;
}

/// �������, ������������ ��� ��������� �������� ������� ������ 
GLvoid OpenGL::ReSizeGLScene(GLsizei width, GLsizei height)// Resize and initialise the gl window
{
	if (height == 0) { height = 1; }

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLfloat)width / height, 1.0, 10000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
/// �������, �������� ������ �������
GLint OpenGL::MySetPixelFormat(HDC hdc)
{
	static PIXELFORMATDESCRIPTOR pfd = {
   sizeof(PIXELFORMATDESCRIPTOR),// Size Of This Pixel Format Descriptor
   1,// Version Number
   PFD_DRAW_TO_WINDOW |// Format Must Support Window
   PFD_SUPPORT_OPENGL |// Format Must Support OpenGL
   PFD_DOUBLEBUFFER,// Must Support Double Buffering
   PFD_TYPE_RGBA,// Request An RGBA Format
   16,// Select Our Color Depth
   0, 0, 0, 0, 0, 0,// Color Bits Ignored
   0,// No Alpha Buffer
   0,// Shift Bit Ignored
   0,// No Accumulation Buffer
   0, 0, 0, 0,// Accumulation Bits Ignored
16,// 16Bit Z-Buffer (Depth Buffer)  
0,// No Stencil Buffer
0,// No Auxiliary Buffer
PFD_MAIN_PLANE,// Main Drawing Layer
0,// Reserved
0, 0, 0// Layer Masks Ignored
	};

	GLint  iPixelFormat;
	if ((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
	{
		MessageBox::Show("ChoosePixelFormat Failed");
		return 0;
	}
	if (SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
	{
		MessageBox::Show("SetPixelFormat Failed");	return 0;
	}
	if ((m_hglrc = wglCreateContext(m_hDC)) == NULL)
	{
		MessageBox::Show("wglCreateContext Failed");	return 0;
	}
	if ((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
	{
		MessageBox::Show("wglMakeCurrent Failed");	return 0;
	}

	return 1;
}

/// �����������
OpenGL::OpenGL(System::Windows::Forms::Form^ parentForm, GLsizei iWidth, GLsizei iHeight)
{
	rotated = true;
	speed = 1;
	r = 1;
	g = 1;
	b = 1;
	value = 0;
	CreateParams^ cp = gcnew CreateParams;
	cp->X = 0;  cp->Y = 0;  cp->Height = iHeight;  cp->Width = iWidth;
	cp->Parent = parentForm->Handle;
	cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
	this->CreateHandle(cp);
	m_hDC = GetDC((HWND)this->Handle.ToPointer());
	if (m_hDC) {
		MySetPixelFormat(m_hDC);
		ReSizeGLScene(iWidth, iHeight);
		InitGL();
	}
}

/// ����������
OpenGL::~OpenGL(System::Void)
{
	this->DestroyHandle();
}

/// ������� ���������
System::Void OpenGL::Render(System::Void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClearColor(120, 120, 120, 0);
	glLoadIdentity();
	//������ �������� ������ ��� ������������� z?
	glTranslatef(0, 0, -OpenGL::scalsebyte);

	Draw();

	SwapBuffers(m_hDC);
}

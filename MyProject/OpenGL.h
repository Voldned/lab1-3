#pragma once
#pragma once
#include <windows.h>
#include <Windowsx.h>
#include <GL/gl.h>
#include <GL/glu.h>
ref class OpenGL : public System::Windows::Forms::NativeWindow
{
private:
	HDC m_hDC;
	HGLRC m_hglrc;
	bool rotated;
	float angle;
	int speed;
	float r, g, b;
	int value;
public:
		OpenGL(System::Windows::Forms::Form^ parentForm, GLsizei iWidth, GLsizei iHeight);

		System::Void Render(System::Void);
		~OpenGL(System::Void);
		GLint MySetPixelFormat(HDC hdc);
		bool InitGL(GLvoid);
		byte scalsebyte = 10;
		static short findex = 2;
		static short begin = -5;
		static short end = 5;
		static bool funcvis = true;
		static bool osvis = true;
		static bool locmaxvis, dervis, maxvis, colvis, refresh;
		GLvoid ReSizeGLScene(GLsizei width, GLsizei height);
		void FlipRotated() { rotated = !rotated; };
		void SetSpeed(int value) { speed = value; };
		void SetColor(float r, float g, float b)
		{
			this->r = r;
			this->g = g;
			this->b = b;
		}
		void SetValue(int value) { this->value = value; };
};



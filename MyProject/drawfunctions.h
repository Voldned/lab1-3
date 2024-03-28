struct vector3
{
 float x, y, z;
} ;

struct color3
{
 float r, g, b;
};

vector3 vector(float x, float y, float z=0);

color3 color(float r, float g, float b);

void DrawLine(float x1, float y1, float z1, float x2, float y2, float z2, float r1, float g1, float b1, float r2, float g2, float b2);
void DrawLine(float x1, float y1, float z1, float x2, float y2, float z2, float r1, float g1, float b1);
void DrawLine(float x1, float y1, float x2, float y2, float r1, float g1, float b1, float r2, float g2, float b2);
void DrawLine(float x1, float y1, float x2, float y2, float r1, float g1, float b1);
void DrawLine(float x1, float y1, float x2, float y2);
void DrawLine(vector3 v1, vector3 v2, color3 c1, color3 c2);
void DrawLine(vector3 v1, vector3 v2, color3 c);
void DrawLine(float x1, float y1, float x2, float y2, float size);

void InitOpenGL(int width, int height);

void Draw();

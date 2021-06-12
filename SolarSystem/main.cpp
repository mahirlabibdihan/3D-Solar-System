#include <GL/glut.h>
#include <math.h>
#define HEIGHT 950
#define WIDTH 1200
#define PI (acos(-1.0))

GLfloat r = 0;
GLfloat X = 0, Y = 0;

void line(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
	glBegin(GL_LINE_STRIP);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}
void rectangle(GLfloat left, GLfloat bottom, GLfloat width, GLfloat height)
{
	GLfloat x1, y1, x2, y2;
	x1 = left;
	y1 = bottom;
	x2 = x1 + width;
	y2 = y1 + height;

	// Draw rectangle 
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glVertex2f(x1, y1);
	glEnd();
}
void circle(GLfloat x, GLfloat y, GLfloat r, GLint slices = 100)
{
	// Draw circle filler
	GLfloat t, dt = 2 * PI / slices;
	glBegin(GL_LINE_STRIP);
	for (t = 0; t <= 2 * PI + dt; t += dt)
	{
		glVertex2f(x + r * cos(t), y + r * sin(t));
	}
	glEnd();
}
void text(GLfloat x, GLfloat y, const char* str, GLfloat size)
{
	glLineWidth(2.0);
	glPushMatrix();
	glTranslatef(x, y, 1);
	glScalef(size, 1.3 * size, 1.0);
	GLint i;
	for (i = 0; str[i]; i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str[i]); // GLUT_STROKE_ROMAN  , GLUT_STROKE_MONO_ROMAN
	glPopMatrix();
	glLineWidth(1.0);
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	glColor3f(1, 1, 1);
	line(-WIDTH/2,Y,WIDTH/2,Y);
	line(X,-HEIGHT/2,X,HEIGHT/2);

	glPushMatrix();
	glTranslatef(X, Y, 0);

	glColor4f(1, 1, 1,0.5);
	rectangle(-590, 400, 360, 70);
	glColor3f(0, 0, 0);
	text(-580, 420, "THE SOLAR SYSTEM", 0.25);
	
	glRotatef(r, 1, 0, 0);
	glRotatef(r, 0, 1, 0);
	glRotatef(r, 0, 0, 1);


	glColor3f(0.8, 0.8, 0.8);
	circle(0, 0, 100);
	circle(0, 0, 130);
	circle(0, 0, 170);
	circle(0, 0, 210);
	circle(0, 0, 270);
	circle(0, 0, 330);
	circle(0, 0, 390);
	circle(0, 0, 450);


	glPushMatrix();
	glRotatef(r, 0.0, 0.0, 1.0);
	glTranslatef(0,0, 0);
	glColor3f(255/255.0,165/255.0, 0);
	glutSolidSphere(70, 50, 50);
	glPopMatrix();

	

	glPushMatrix();
	glRotatef(r, 0.0, 0.0, 1.0);
	glTranslatef(0,-100, 0);
	glColor3f(160/255.0,82/255.0,45/255.0);
	glutSolidSphere(10, 50, 50);
	glPopMatrix();


	glPushMatrix();
	glRotatef(1.15 * r, 0.0, 0.0, 1.0);
	glTranslatef(130, 0, 0);
	glColor3f(255/255.0,140/255.0, 0);
	glutSolidSphere(10, 50, 50);
	glPopMatrix();


	glPushMatrix();
	glRotatef(0.9 * r, 0.0, 0.0, 1.0);
	glTranslatef(0, 170, 0);
	glColor3f(25/255.0,25/255.0,112/255.0);
	glutSolidSphere(15, 50, 50);
	glPopMatrix();


	glPushMatrix();
	glRotatef(1.4 * r, 0.0, 0.0, 1.0);
	glTranslatef(-210, 0, 0);
	glColor3f(1.0, 69/255.0, 0);
	glutSolidSphere(20, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glRotatef(1.2 * r, 0.0, 0.0, 1.0);
	glTranslatef(0,-270, 0);
	glColor3f(139/255.0,69/255.0,19/255.0);
	glutSolidSphere(30, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glRotatef(1.3 * r, 0.0, 0.0, 1.0);
	glTranslatef(330, 0, 0);
	glColor3f(205/255.0,133/255.0,63/255.0);
	glutSolidSphere(25, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glRotatef(1.1 * r, 0.0, 0.0, 1.0);
	glTranslatef(0,390, 0);
	glColor3f(70/255.0,130/255.0,180/255.0);
	glutSolidSphere(25, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glRotatef(1.5 * r, 0.0, 0.0, 1.0);
	glTranslatef(-450, 0, 0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere(25, 50, 50);
	glPopMatrix();

	glPopMatrix();


	glFlush();
}
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);//resizing the window

	// Setup viewing volume
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-w / 2, w / 2, -h / 2, h / 2, -w / 2, h / 2);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void init()
{
	GLfloat mat_specular[] = {1.0, 1.0, 1.0};
	GLfloat mat_shininess[] = {50.0};
	GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
	glClearColor(0, 0, 0, 0);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LINE_SMOOTH);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glLineWidth(1.0);
}

void update(int n)
{
	r += .5;
	glutPostRedisplay();
	glutTimerFunc(n, update, n);
}
// Keyboard input processing routine.
void specialKeyInput(int key, int /*x*/, int /*y*/)
{
	switch (key)
	{
	case GLUT_KEY_DOWN:
		Y -= 5;
		break;
	case GLUT_KEY_UP:
		Y += 5;
		break;
	case GLUT_KEY_LEFT:
		X -= 5;
		break;
	case GLUT_KEY_RIGHT:
		X += 5;
		break;

	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Scene");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(specialKeyInput);
	glutTimerFunc(30, update, 30);
	glutMainLoop();
	return 0;
}

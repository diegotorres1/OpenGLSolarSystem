#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <time.h>
#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif
//global//
int winw = 900;
int winh = 600;
float r = 0.0;
int counter = 0;
int speed =20;
typedef struct CoordsofPlanets
{
	float xMer; float yMer;
	float xVen; float yVen;
	float xEar; float yEar;
	float xMar; float yMar;
	float xJup; float yJup;
	float xSat; float ySat;
	float xUra; float yUra;
	float xNep; float yNep;
}Coords;
Coords* orbitsP;
void zoom()
{
}
void delay(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}
void orbit(void) {
	orbitsP = AllOrbits();
	r += .2;
	delay(speed);
	glutPostRedisplay();
}
typedef struct Button
{
	int x;
	int y;
	int width;
	int height;
	char* label;
}Button;
Button MyButton = { 0,0,70,30,"INCREMENT" };
Button MyButton1 = { 80,0,70,30,"DECREMENT" };
void incrementButton(int x, int y)
{
	if ((x > MyButton.x && (x < MyButton.x + MyButton.width)) && (y > MyButton.y && y < (MyButton.y + MyButton.height)))
	{
		printf("Increment the speed");
		if (speed != 0)
			speed -= 2;
		else
			printf("Can't go any faster");
	}


}
void decrementButton(int x, int y)
{
	if ((x > MyButton1.x && (x < MyButton1.x + MyButton1.width)) && (y > MyButton1.y && y < (MyButton1.y + MyButton1.height)))
	{
		printf("Decrement the speed");
		if (speed != 100)
			speed += 2;
		else
			printf("Don't go any slower");
	}
}
void ButtonHandler(int x, int y)
{
	incrementButton(x, y);
	decrementButton(x, y);
}
typedef struct Mouse
{
	int x;
	int y;
	int lmb;
	int mmb;
	int rmb;

	int xPress;
	int yPress;
}Mouse;

Mouse MyMouse = { 0,0,0,0,0 };
void font(void *font, char *text, int x, int y)
{
	glRasterPos2i(x, y);
	while (*text != '\0')
	{
		glutBitmapCharacter(font, *text);
		++text;
	}
}
void ButtonDraw(Button *b)
{
	glColor3f(.9, .9, .8);
	glBegin(GL_QUADS);
	glVertex2i(b->x, b->y);
	glVertex2i((b->x) + (b->width)+4, b->y);
	glVertex2i((b->x) + (b->width)+4, (b->y) + (b->height)+4);
	glVertex2i(b->x, (b->y) + (b->height)+4);
	glEnd();

	glColor3f(1, 1, .8);
	glBegin(GL_QUADS);
	glVertex2i(b->x, b->y);
	glVertex2i((b->x) + (b->width), b->y);
	glVertex2i((b->x) + (b->width), (b->y) + (b->height));
	glVertex2i(b->x, (b->y) + (b->height));
	glEnd();

	int fontx = b->x + (b->width - glutBitmapLength(GLUT_BITMAP_HELVETICA_10, b->label)) / 2;
	int fonty = b->y + (b->height + 10) / 2;
	glColor3f(0, 0, 0);
	font(GLUT_BITMAP_HELVETICA_10, b->label, fontx, fonty);


}
void ThreeD()
{
	//int *px;
	//int *py;


	gluLookAt(0, 5, 1, 0, 0, 0, 0, 0, 1);
	glRotatef(r*1.0,0,0,1);
	GLfloat sunDiffuseMaterial[] = { 1.0, 1.0, 0.0, 0.0 }; //sun
	GLfloat mercuryDiffuseMaterial[] = { 0.8, 0.75, 0.44, 0.0 }; //mercury
	GLfloat venusDiffuseMaterial[] = { 0.8, 0.4, 0.0, 0.0 }; //venus
	GLfloat earthDiffuseMaterial[] = { 0.0, 0.0, 1.0, 0.0 }; //earth
	GLfloat marsDiffuseMaterial[] = { 0.8, 0.22, 0.0, 0.0 }; //mars
	GLfloat jupiterDiffuseMaterial[] = { 0.9, 0.74, 0.23, 0.0 }; //jupiter
	GLfloat saturnDiffuseMaterial[] = { 0.89, 0.81, 0.34, 0.0 }; //saturn
	GLfloat uranusDiffuseMaterial[] = { 0.22, 0.99, 0.99, 0.0 }; //uranus
	GLfloat neptuneDiffuseMaterial[] = { 0.21, 0.47, 0.86, 0.0 }; //neptune

	glMaterialfv(GL_FRONT, GL_DIFFUSE, sunDiffuseMaterial);
	glLineWidth(6.0);
	glutWireSphere(.8,20,15);

	if (counter == 100)
	{
		for (int i = 0; i < 8; i++)
			glPushMatrix();

		glTranslatef(orbitsP->xMer, orbitsP->yMer, 0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mercuryDiffuseMaterial);
		glLineWidth(.5);
		glutWireSphere(.3, 20, 15);

		glPopMatrix();
		glTranslatef(orbitsP->xVen, orbitsP->yVen, 0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, venusDiffuseMaterial);
		glLineWidth(1);
		glutWireSphere(.3, 20, 15);

		glPopMatrix();
		glTranslatef(orbitsP->xEar, orbitsP->yEar, 0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, earthDiffuseMaterial);
		glLineWidth(.5);
		glutWireSphere(.3, 20, 15);
		
		glPopMatrix();
		glTranslatef(orbitsP->xMar, orbitsP->yMar, 0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, marsDiffuseMaterial);
		glLineWidth(.5);
		glutWireSphere(.3, 20, 15);

		glPopMatrix();
		glTranslatef(orbitsP->xJup, orbitsP->yJup, 0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, jupiterDiffuseMaterial);
		glLineWidth(1);
		glutWireSphere(.3, 20, 15);

		glPopMatrix();
		glTranslatef(orbitsP->xSat, orbitsP->ySat, 0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, saturnDiffuseMaterial);
		glLineWidth(6);
		glutWireSphere(.3, 20, 15);

		glPopMatrix();
		glTranslatef(orbitsP->xUra, orbitsP->yUra, 0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, uranusDiffuseMaterial);
		glLineWidth(.5);
		glutWireSphere(.3, 20, 15);

		glPopMatrix();
		glTranslatef(orbitsP->xNep, orbitsP->yNep, 0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, neptuneDiffuseMaterial);
		glLineWidth(.5);
		glutWireSphere(.3, 20, 15);

	}
	else
		counter++;

}
void TwoD_Overlay(void)
{
	glColor3f(.77,.76,.67);
	glBegin(GL_QUADS);
	glVertex2i(0,0);
	glVertex2i(0,60);
	glVertex2i(160,60);
	glVertex2i(160,0);
	glEnd();
	glColor3f(0, 0, 0);
	font(GLUT_BITMAP_HELVETICA_10, "SPEED", 60, 50);
	ButtonDraw(&MyButton);
	ButtonDraw(&MyButton1);
}
void Init(void)
{
	glEnable(GL_LIGHT0);
}
void display(void)
{
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (winh == 0) ? (1) : (float)winw / winh, 1, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	ThreeD();

	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, winw, winh, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	TwoD_Overlay();

	glutSwapBuffers();
}
void reshape(int w, int h)
{
	winw = w;
	winh = h;
	glViewport(0, 0, w, h);
}
void MouseButton(int button, int state, int x, int y)
{
	MyMouse.x = x;
	MyMouse.y = y;
	if (state == GLUT_DOWN)
	{
		if (!(MyMouse.lmb || MyMouse.mmb || MyMouse.rmb)) {
			MyMouse.xPress = x;
			MyMouse.yPress = y;
		}
		switch (button) {
		case GLUT_LEFT_BUTTON:
			MyMouse.lmb = 1;
		case GLUT_MIDDLE_BUTTON:
			MyMouse.mmb = 1;
			break;
		case GLUT_RIGHT_BUTTON:
			MyMouse.rmb = 1;
			break;
		}
		if ((x > MyButton.x && (x < MyButton.x + MyButton.width)) && (y > MyButton.y && y < (MyButton.y + MyButton.height)))
		{
			printf("Increment");
		}
		ButtonHandler(MyMouse.x,MyMouse.y);
	}
	else
	{
		switch (button)
		{
		case GLUT_LEFT_BUTTON:
			MyMouse.lmb = 0;
			break;
		case GLUT_MIDDLE_BUTTON:
			MyMouse.mmb = 0;
			break;
		case GLUT_RIGHT_BUTTON:
			MyMouse.rmb = 0;
			break;
		}
	}
}
void MouseMotion(int x, int y)
{
	int dx = x - MyMouse.x;
	int dy = y - MyMouse.y;

	MyMouse.x = x;
	MyMouse.y = y;
	glutPostRedisplay();
}
void MousePassiveMotion(int x, int y)
{
	int dx = x - MyMouse.x;
	int dy = y - MyMouse.y;

	MyMouse.x = x;
	MyMouse.y = y;

}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(winw, winh);
	glutCreateWindow("Earth and Sun");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(MouseButton);
	glutMotionFunc(MouseMotion);
	glutPassiveMotionFunc(MousePassiveMotion);
	glutIdleFunc(orbit);

	Init();
	glutMainLoop();

}
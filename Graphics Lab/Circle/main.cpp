/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#include <math.h>


static float	tx	=  0.0;
static float	ty	=  0.0;

//float p=-2.3;
void DrawCircle(float cx, float cy, float rx,float ry, int num_segments)
{
	glBegin(GL_TRIANGLE_FAN);
	for(int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float x = rx * cosf(theta);//calculate the x component
		float y = ry * sinf(theta);//calculate the y component

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
}
void display(void)
{




    glClear(GL_COLOR_BUFFER_BIT);
  //1sr circle
	//glPushMatrix();

	glColor3f(0.0, 1.0, 0.0);

	//glTranslatef(tx+200,ty+200,0);

DrawCircle(0,0,100,100,500);
 //glPopMatrix();
    //3rd circle
 /* glPushMatrix();

	glColor3f(0.0, 0.0, 1.0);
glTranslatef(tx+400,ty-75,0);

DrawCircle(-50,0,40,30,500);


	glPopMatrix();
	//2nd circle
  glPushMatrix();

	glColor3f(0.0, 1.0, 1.0);
glTranslatef(tx+300,ty+75,0);
DrawCircle(-50,0,40,30,500);
//DrawCircle(-400,0,100,100,10);


	glPopMatrix(); */
	glFlush();
}
void init(void)
{
	glClearColor (1.0, 0.0, 0.0, 0.0);
	 glOrtho(-500.0, 500.0, -300.0, 300.0, -1.0, 1.0);
}

int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("circle");
	init();
    glutDisplayFunc(display);
	//glutKeyboardFunc(my_keyboard);
	//glutSpecialFunc(spe_key);
	//glutMouseFunc(my_mouse);
	glutMainLoop();
	return 0;
}



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

float p=-2.3;

void display(void)
{


        if(p<=2.0){
     p=p+0.0009;}

  else{
        p=-2.3;}
    glutPostRedisplay();

    glClear(GL_COLOR_BUFFER_BIT);




glPushMatrix();

	glColor3f(1.0, 1.0, 1.0);
//glTranslatef(tx,ty,0);

 /*glBegin(GL_QUADS);
   glVertex2f(0.25,0.25);
   glVertex2f(-0.25,0.25);
   glVertex2f(-0.25,-0.25);
   glVertex2f(0.25,-0.25);
  glEnd();*/

  glBegin(GL_QUADS);
   glVertex2f(p+(-1.25),0.25);
   glVertex2f(p+(-0.75),0.25);
   glVertex2f(p+(-0.75),-0.25);
   glVertex2f(p+(-1.25),-0.25);
  glEnd();

	glPopMatrix();

	glFlush();
}
void init(void)
{
	glClearColor (1.0, 0.0, 0.0, 0.0);

}

int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("moving_object");
	init();
    glutDisplayFunc(display);
	//glutKeyboardFunc(my_keyboard);
	//glutSpecialFunc(spe_key);
	//glutMouseFunc(my_mouse);
	glutMainLoop();
	return 0;
}



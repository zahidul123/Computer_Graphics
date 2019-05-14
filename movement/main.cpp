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
#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
//#include<stdarg.h>

static GLfloat spin = 0.0;
static float	tx1	=  -40.0;
static float	ty1	=  -40.0;
static float	tx2	=  -30.0;
static float	ty2	=  -30.0;



void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();

	glRotatef(spin, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);

	//glTranslatef(tx,ty,0);

	glRectf(-40.0, -40.0, 40.0, 40.0);
	glColor3f(1.0, 0.0, 1.0);
	glRectf(tx1, ty1, tx2, ty2);
	glPopMatrix();

	glFlush();
}

void spinDisplay_left(void)
{
   tx1 = tx1 + 10;
    tx1 = tx2 + 10;
   glutPostRedisplay();
}

void spinDisplay_right(void)
{
   spin = spin - 10;

   glutPostRedisplay();
}


void init(void)
{
	glClearColor (1.0, 0.0, 0.0, 0.0);
	glOrtho(-100.0, 100.0, -100.0,100.0, -1.0, 1.0);
}


void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

		case 'l':
			spinDisplay_left();
			break;

		case 'r':
			spinDisplay_right();
			break;

		case 's':
			 glutIdleFunc(NULL);
			 break;

	  default:
			break;
	}
}

void spe_key(int key, int x, int y)
{
   printf("%d",key);
	switch (key) {

		case GLUT_KEY_UP:
		    if(ty1>25&&ty2>35){
                ty1=30;
                ty2=40;
		    }else{
		        ty1 = ty1 + 10;
                ty2 = ty2 + 10;
		    }

				PlaySound("Horn Honk-SoundBible.com-1162546405.wav", NULL, SND_ASYNC|SND_FILENAME);
				glutPostRedisplay();
				break;



		case GLUT_KEY_DOWN:

		    PlaySound("Horn Honk-SoundBible.com-1162546405.wav", NULL, SND_ASYNC|SND_FILENAME);
		    if(ty1<-30&&ty2<-25){
                ty1=-40;
                ty2=-30;
		    }else{
		        ty1 = ty1 -10;
                ty2 = ty2 - 10;
		    }
				//ty1 = ty1 - 10;
               // ty2 = ty2 - 10;
				glutPostRedisplay();
				break;

				case GLUT_KEY_RIGHT:
            PlaySound("Horn Honk-SoundBible.com-1162546405.wav", NULL, SND_ASYNC|SND_FILENAME);
            if(tx1>25&&tx2>35){
                tx1=30;
                tx2=40;
		    }else{
		        tx1 = tx1 + 10;
                tx2 = tx2 + 10;
		    }
				//tx1 = tx1 - 10;
               // tx2 = tx2 - 10;
				glutPostRedisplay();
				break;



		case GLUT_KEY_LEFT:
		    PlaySound("Horn Honk-SoundBible.com-1162546405.wav", NULL, SND_ASYNC|SND_FILENAME);
		    if(tx1<-35&&tx2<-25){
                tx1=-40;
                tx2=-30;
		    }else{
		        tx1 = tx1 - 10;
                tx2 = tx2 - 10;
		    }
				//tx1 = tx1 + 10;
                //tx2 = tx2 + 10;
				glutPostRedisplay();
				break;



	  default:
			break;
	}
}




int main()
{
	//PlaySound("Horn Honk-SoundBible.com-1162546405.wav", NULL, SND_ASYNC|SND_FILENAME);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("LAB3");
	init();
    glutDisplayFunc(display);
	glutKeyboardFunc(my_keyboard);
	glutSpecialFunc(spe_key);
	//glutMouseFunc(my_mouse);
	glutMainLoop();
	return 0;
}



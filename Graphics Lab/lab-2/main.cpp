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
//#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void init()
{
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glOrtho(-8,10,-8,10,-8,8);
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
        glColor3f(1.0f,0.0f,0.0f);

        glVertex3d(5.0,5.0,0.0);
        glVertex3d(5.0,1.0,0.0);
        glVertex3d(1.0,1.0,0.0);
        glVertex3f(1.0,5.0,0.0);

        glColor3f(0.0f,1.0f,0.0f);

        glVertex3d(-1.0,5.0,0.0);
        glVertex3d(-1.0,1.0,0.0);
        glVertex3d(-5.0,1.0,0.0);
        glVertex3f(-5.0,5.0,0.0);

        glColor3f(0.0f,0.0f,1.0f);

        glVertex3d(2.0,2.0,0.0);
        glVertex3d(2.0,-2.0,0.0);
        glVertex3d(-2.0,-2.0,0.0);
        glVertex3f(-2.0,2.0,0.0);
    glEnd();

    glFlush();
}

void myDisplay2()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3d(6.0,3.0,0.0);
        glVertex3d(6.0,1.0,0.0);
        glVertex3d(2.0,1.0,0.0);
        glVertex3f(2.0,3.0,0.0);

        glColor3f(0.0f,1.0f,0.0f);
        glVertex3d(4.0,2.0,0.0);
        glVertex3d(4.0,0.0,0.0);
        glVertex3d(0.0,0.0,0.0);
        glVertex3f(0.0,2.0,0.0);

        glColor3f(1.0f,0.0f,0.0f);
        glVertex3d(2.0,1.0,0.0);
        glVertex3d(2.0,-1.0,0.0);
        glVertex3d(-2.0,-1.0,0.0);
        glVertex3f(-2.0,1.0,0.0);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(1.0f,0.0f,1.0f);
        glVertex3d(-2.0,-1.0,0.0);
        glVertex3d(2.0,1.0,0.0);

        glColor3f(1.0f,1.0f,0.0f);
        glVertex3d(2.0,1.0,0.0);
        glVertex3d(4.0,2.0,0.0);

        glColor3f(0.0f,1.0f,1.0f);
        glVertex3d(4.0,2.0,0.0);
        glVertex3d(6.0,3.0,0.0);
    glEnd();

    glFlush();
}

void myDisplay3()
{
    glBegin(GL_TRIANGLES);
        glColor3f(0.28f,0.28f,0.545f);

        glVertex3d(4.0,0.0,0.0);
        glVertex3d(0.0,0.0,0.0);
        glVertex3d(2.0,4.0,0.0);

    glEnd();

    glFlush();
}



int main()
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(200,200);
    glutCreateWindow("DEMO");
    init();
    glutDisplayFunc(myDisplay3);
    glutMainLoop();
    return 0;
}

#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float r=2.3;
void circle(){
    if(r>-100.0){
     r=r-0.08;}

  else{
        r=-2.3;}
glutPostRedisplay();
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   // glColor3d(1,0,0);
  int i;
    int triangleAmount =180; //# of triangles used to draw circle

   GLfloat radius ;
    GLfloat twicePi = 2*3.1416;
        glBegin(GL_TRIANGLE_FAN);
         radius=50;
        for(i = 0; i <= 200;i++) {
            glVertex2f(
                    r+202+(radius * cos(  i*twicePi  /triangleAmount)),
                 200+(radius * sin(i*twicePi / triangleAmount))
            );
        }
    glEnd();

glColor3f(0.0f,1.0f,0.0f);
        glBegin(GL_TRIANGLE_FAN);
         radius=60;
        for(i = 0; i <= 200;i++) {
            glVertex2f(
                     r+200+(radius * cos(  i*twicePi  /triangleAmount)),
                 180+(radius * sin(i*twicePi / triangleAmount))
            );
        }
    glEnd();


// void neck(float r){

   glBegin(GL_QUADS);
      glVertex2d(r+150,270);
      glVertex2d(r+175,200);
      glVertex2d(r+155,200);
      glVertex2d(r+135,260);
   glEnd();

   //head

      glBegin(GL_TRIANGLE_FAN);
         radius=18;
        for(i = 0; i <= 200;i++) {
            glVertex2f(
                     r+140+(radius * cos(  i*twicePi  /triangleAmount)),
                 275+(radius * sin(i*twicePi / triangleAmount))
            );
        }
    glEnd();

    //eye
    glColor3f(1.0f,1.0f,0.0f);
      glBegin(GL_TRIANGLE_FAN);
         radius=5;
        for(i = 0; i <= 200;i++) {
            glVertex2f(
                     r+135+(radius * cos(  i*twicePi  /triangleAmount)),
                 280+(radius * sin(i*twicePi / triangleAmount))
            );
        }
    glEnd();

 //void mought(float r){

 glBegin(GL_POLYGON);
      glVertex2d(r+125,280);
      glVertex2d(r+125,270);
      glVertex2d(r+115,270);
      glVertex2d(r+112,275);
     glVertex2d(r+115,280);
   glEnd();

// void taill(float r){

     glBegin(GL_POLYGON);
      glVertex2d(r+255,205);
      glVertex2d(r+255,175);
      glVertex2d(r+265,190);
      glVertex2d(r+275,215);
     glVertex2d(r+260,195);
   glEnd();



   glBegin(GL_QUADS);
      glVertex2d(r+208,122);
      glVertex2d(r+190,122);  //leg
      glVertex2d(r+190,90);
      glVertex2d(r+204,90);
   glEnd();

//fingure

   glBegin(GL_POLYGON);
      glVertex2d(r+190,95);
      glVertex2d(r+180,70);
      glVertex2d(r+195,80);
      glVertex2d(r+200,60);
      glVertex2d(r+205,85);
   glEnd();
    glBegin(GL_POLYGON);
      glVertex2d(r+195,80);
      glVertex2d(r+200,60);
      glVertex2d(r+205,85);
      glVertex2d(r+220,90);
      glVertex2d(r+190,95);
   glEnd();
 }
void display(){
    //glTranslatef(100,360,0);
   // glScalef(2, 2,0);


    glColor3f(1.0f,1.0f,0.0f);
    circle();
   // glColor3f(0.0f,1.0f,0.0f);
    //circle(p+200,180,60);
   // neck(p);
    //circle(p+140,275,18);
    //glColor3f(1.0f,1.0f,0.0f);
   // circle(p+135,280,5);
   // mought(p);
   // taill(p);
    //leg(p);
    //finger(p);

    glFlush();
}
void init(){
glClearColor(0.5f,0.33f,0.1f,0.0f);
glPointSize(1.0);
	gluOrtho2D(0.0,600.0,0.0,600.0);
}

int main(int argc, char *argv[])
{
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("duck");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

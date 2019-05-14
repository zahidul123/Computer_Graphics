#include<windows.h>
#include<GL/glut.h>
#include <GL/glu.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>

#define PI 3.1416

GLint i;
GLfloat xBoat1 = -1000.0;
GLfloat yBoat1 = -330.0;

GLfloat xBoat2 = -400.0;
GLfloat yBoat2 = -425.0;
float wave1 = -100.0;
float wave2 = 100.0;
float wave3 = -200.0;
float xCloud = -650.0;



void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;
    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}


void blackLines()
{

    glScalef(1.5, 0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (-50, 0, 0.0);
    glVertex3f (-50, -10, 0.0);
    glVertex3f (50, -10, 0.0);
    glVertex3f (50, 0.0, 0.0);

    glEnd();
}


void riverSide() /// or cloud
{

    glPushMatrix();
    glTranslatef(4,5.5,0);
    circle(4);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-8,5.5,0);
    circle(3.5);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-3.5,9,0);
    circle(3.5);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1,9,0);
    circle(3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1.5,5.5,0);
    circle(4);
    glPopMatrix();
}

void flower()
{
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(2, -70, 0);
    glRotatef(45, 0,1,0);
    glScalef(4.0, 4.0, 4.0);
    riverSide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2, -90, 0);
    glScalef(4.0, 4.0, 4.0);
    riverSide();
    glPopMatrix();

    glColor3f(0.9 , 0.4   , 0.5 );
    glBegin(GL_POLYGON);
    glVertex3f (0, 30, 0.0);
    glVertex3f (-10, 10, 0.0);
    glVertex3f (10, 10, 0.0);
    glEnd();

    glColor3f(0.2, 0.7, 0.2);
    glRotatef(45, 0,1,0);
    glBegin(GL_POLYGON);
    glVertex3f (0, 10, 0.0);
    glVertex3f (-20, 20, 0.0);
    glVertex3f (0, -10.0, 0.0);
    glVertex3f (20, 20, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f (-2, 0, 0.0);
    glVertex3f (-2, -40, 0.0);
    glVertex3f (2, -40, 0.0);
    glVertex3f (2, 0, 0.0);

    glEnd();


}

void wave()
{
    ///******** Line One ****************
    glColor3f(0 , 0.8  , 0.8 );
    glPushMatrix();
    glTranslatef(-450,0,0);
    blackLines();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-250,0,0);
    blackLines();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-50,0,0);
    blackLines();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(150,0,0);
    blackLines();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(350,0,0);
    blackLines();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(500,0,0);
    blackLines();
    glPopMatrix();
}

void river()
{
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0 , 1  , 1 );
        glVertex3f (-500, -220, 0.0);
        glVertex3f (-500, -500, 0.0);
        glVertex3f (-200, -500, 0.0);
        glVertex3f (-200, -220, 0.0);
        glVertex3f (-300, -200, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0 , 1  , 1 );
        glVertex3f (-200, -220, 0.0);
        glVertex3f (-200, -500, 0.0);
        glVertex3f (200, -500, 0.0);
        glVertex3f (200, -250, 0.0);
        glVertex3f (100, -220, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0 , 1  , 1 );
        glVertex3f (200, -250, 0.0);
        glVertex3f (200, -500, 0.0);
        glVertex3f (500, -500, 0.0);
        glVertex3f (500, -200, 0.0);
    glEnd();
    glPopMatrix();


    ///***** Wave *************

    glPushMatrix();
    glTranslatef(wave1,-250,0);
    wave();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(wave3,-300,0);
    wave();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(wave2,-350,0);
    wave();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(wave3,-400,0);
    wave();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(wave1,-450,0);
    wave();
    glPopMatrix();


/// river Left side

    glColor3f(0.2, 0.7, 0.2);
    glPushMatrix();
    glTranslatef(-420,-260,0);
    glScalef(8, 8, 0.0);
    riverSide();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-300,-260,0);
    glScalef(8, 8, 0.0);
    riverSide();
    glPopMatrix();
    glPopMatrix();

    /// river Right side
    glPushMatrix();
    glTranslatef(450,-260,0);
    glScalef(8, 8, 0.0);
    riverSide();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(310,-270,0);
    glScalef(8, 8, 0.0);
    riverSide();
    glPopMatrix();
    glPopMatrix();





}


void river_down_flower()  /// river down side
{
/// ***** Started Left Side
    glPushMatrix();
    glTranslatef(-450,-440,0);
    glScalef(.8, .8, 0.0);
    flower();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-310,-440,0);
    glScalef(.8, .8, 0.0);
    flower();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-150,-440,0);
    glScalef(.8, .8, 0.0);
    flower();
    glPopMatrix();

/// Middle Flower**********

    glPushMatrix();
    glTranslatef(0,-440,0);
    glScalef(.8, .8, 0.0);
    flower();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30,-470,0);
    glRotatef(45, 1, 1, 0);
    glScalef(.8, .8, 0.0);
    flower();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-30,-470,0);
    glRotatef(180, 0, 1, 0);
    glScalef(.8, .8, 0.0);
    flower();
    glPopMatrix();

/// ***************

    glPushMatrix();
    glTranslatef(130,-440,0);
    glScalef(.8, .8, 0.0);
    flower();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(150,-440,0);
    glRotatef(45, 1, 1, 0);
    glScalef(.8, .8, 0.0);
    flower();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(310,-440,0);
    glScalef(.8, .8, 0.0);
    flower();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(450,-440,0);
    glScalef(.8, .8, 0.0);
    flower();
    glPopMatrix();
    glPopMatrix();

}

void leavese()
{

    glScalef(1.5, 1, 0.0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.8, 0.0);
    glVertex3f(0.0,35.0,0.0);
    glVertex3f(-35.0,-30.0,0.0);
    glVertex3f(35.0,-30.0,0.0);
    glEnd();

}

void treeBody()
{

    glPushMatrix();
    glTranslatef(0,-75,0);
    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(-10,0,0);
    glVertex3f(-10,-100,0);
    glVertex3f(10,-100,0);
    glVertex3f(10,0,0);

    glEnd();


    /// Root
    glTranslatef(0,-100,0);
    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(-10,0,0);
    glVertex3f(-15,-15,0);
    glVertex3f(0,-5,0);
    glVertex3f(15,-15,0);
    glVertex3f(10,0,0);
    glEnd();
    glPopMatrix();
}

void tree()
{
    glColor3f(1.0, 1.0, 0.0);

    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(0.5, 1.0, 0.0);
    leavese();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-20,0);
    glScalef(0.8, 0.8, 0.0);
    leavese();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-45,0);
    glScalef(1, 1, 0.0);
    leavese();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(1, 1, 0.0);
    treeBody();
    glPopMatrix();



}
void bigTree()
{
    glPushMatrix();
    glTranslatef(5,100,0);
    treeBody();
    glPopMatrix();

    glColor3f(0, 0.3, 0);
    glPushMatrix();
    glTranslatef(0,0,0);
    glRotatef(45, 0,1,0);
    glScalef(6, 6,0);
    riverSide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(20,0,0);
    glRotatef(45, 0,1,0);
    glScalef(6, 6,0);
    riverSide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,30,0);
    glRotatef(45, 0,1,0);
    glScalef(6, 6,0);
    riverSide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,60,0);
    glRotatef(45, 0,1,0);
    glScalef(6, 6,0);
    riverSide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,80,0);
    glRotatef(45, 0,1,0);
    glScalef(5, 5,0);
    riverSide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,100,0);
    glRotatef(45, 0,1,0);
    glScalef(4, 7,0);
    riverSide();
    glPopMatrix();




}


void field_side()
{
/// tree Left side
    glPushMatrix();
    glTranslatef(-100,200,0);
    glScalef(0.5, 0.5,0);
    bigTree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-50,275,0);
    glScalef(0.5, 0.5,0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,205,0);
    glScalef(0.7, 0.7,0);
    bigTree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50,250,0);
    glScalef(0.5, 0.5,0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(100,250,0);
    glScalef(0.6, 0.6,0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(150,250,0);
    glScalef(0.6, 0.6,0);
    bigTree();
    glPopMatrix();

/// third line

    glPushMatrix();
    glTranslatef(-50,150,0);
    glScalef(0.9, 0.9,0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,160,0);
    glScalef(0.9, 0.9,0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(120,170,0);
    glScalef(0.6, 0.6,0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(75,100,0);
    tree();
    glPopMatrix();

    ////////////////////////

    glPushMatrix();
    glTranslatef(-60,10,0);
    glScalef(1.0, 1.0,1.0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-20,10,0);
    glScalef(1.0, 1.0,1.0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40,0,0);
    tree();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(110,-100,0);
    glScalef(1.0, 1.0,1.0);
    bigTree();
    glPopMatrix();

    /////////////////

    glPushMatrix();
    glTranslatef(0,-90,0);
    glScalef(0.3, 0.3,0.0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(65,-80,0);
    glScalef(0.3, 0.3,0.0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(55,-110,0);
    glScalef(0.3, 0.3,0.0);
    tree();
    glPopMatrix();


}
void field()
{
    glBegin(GL_POLYGON);
    glColor3f(0.1372554,  0.556863 , 0.137255);
    glVertex3f (-500, 200, 0.0);
    glVertex3f (-500, -200, 0.0);
    glVertex3f (500, -200, 0.0);
    glVertex3f (500, 200, 0.0);
    glEnd();

    /// Display Tree Left Side
    glPushMatrix();
    glTranslatef(-400,0,0);
    field_side();
    glPopMatrix();

    /// Display Tree Right Side
    glPushMatrix();
    glTranslatef(350,0,0);
    field_side();
    glPopMatrix();


}
 void cloud()
 {
    glColor3f(1.0,1.0, 1.0);
    glPushMatrix();
    glTranslatef(0.0, 0, 0.0);
    glScalef(5,5,0);
    glRotatef(45, 0, 1, 0);
    riverSide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, -30, 0.0);
    glScalef(5,5,0);
    riverSide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(100.0, 10, 0.0);
    glScalef(5,5,0);
    riverSide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130.0, -60, 0.0);
    glScalef(5,5,0);
    riverSide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-50.0, -90, 0.0);
    glScalef(5,5,0);
    riverSide();
    glPopMatrix();

    glColor3f(1.0,1.0, 1.0);
    glPushMatrix();
    glTranslatef(80.0, -150, 0.0);
    glScalef(3,3,0);
    glRotatef(45, 0, 1, 0);
    riverSide();
    glPopMatrix();
 }

void sky()
{

    glBegin(GL_POLYGON);
    glColor3f(0.1 , 0.847059 , 1.0);
    glVertex3f (-500, 500, 0.0);
    glVertex3f (-500, 200, 0.0);
    glVertex3f (500, 200, 0.0);
    glVertex3f (500, 500, 0.0);

    glEnd();

    /// SUN
    glColor3f(1 , .8 ,0.0);
    glPushMatrix();
    glTranslatef(300, 400, 0.0);
    circle(40);
    glPopMatrix();

    /// Cloud
    glPushMatrix();
    glTranslatef(xCloud, 400, 0.0);
    cloud();
    glPopMatrix();



}

void home()
{
    ///front
    glColor3ub(50,0,90);
    glBegin(GL_POLYGON);
    glVertex3f(3,14, 0.0);
    glVertex3f(3,5, 0.0);
    glVertex3f(8,2, 0.0);
    glVertex3f(8,12, 0.0);
    glVertex3f(6,18, 0.0);
    glEnd();
//side
    glColor3ub(190,120,100);
    glBegin(GL_POLYGON);
    glVertex3f(8,2, 0.0);
    glVertex3f(8,12, 0.0);
    glVertex3f(20,12, 0.0);
    glVertex3f(20,2, 0.0);
    glEnd();
///up
    glColor3ub(50,100,200);
    glBegin(GL_POLYGON);
    glVertex3f(8,12, 0.0);
    glVertex3f(6,18, 0.0);
    glVertex3f(17,18, 0.0);
    glVertex3f(21,12, 0.0);
    glEnd();
///front window
    glColor3ub(200,255,250);
    glBegin(GL_POLYGON);
    glVertex3f(5,8.2, 0.0);
    glVertex3f(5,11, 0.0);
    glVertex3f(6,11, 0.0);
    glVertex3f(6,8, 0.0);
    glEnd();
///door
    glColor3ub(50,50,50);
    glBegin(GL_POLYGON);
    glVertex3f(12,2, 0.0);
    glVertex3f(12,10, 0.0);
    glVertex3f(15,10, 0.0);
    glVertex3f(15,2, 0.0);
    glEnd();
///side window2
    glColor3ub(50,50,50);
    glBegin(GL_POLYGON);
    glVertex3f(17,7, 0.0);
    glVertex3f(17,10, 0.0);
    glVertex3f(18,10, 0.0);
    glVertex3f(18,7, 0.0);
    glEnd();
///side window1
    glColor3ub(50,50,50);
    glBegin(GL_POLYGON);
    glVertex3f(9,7, 0.0);
    glVertex3f(9,10, 0.0);
    glVertex3f(10,10, 0.0);
    glVertex3f(10,7, 0.0);
    glEnd();
}

void people()
{

    glPushMatrix();
    //glRotatef(4, 1.0, 0.0, 0.0);
    glColor3f(0 , 0 , 0 );
    circle(10); ///head of man
    glPopMatrix();


    glPushMatrix();
    glScalef(1, .7, 0.0);///define the body of man
    glBegin(GL_POLYGON);
    glVertex3f (-2, 0, 0.0);
    glVertex3f (-2, -40, 0.0);
    glVertex3f (2, -40, 0.0);
    glVertex3f (2, 0, 0.0);
    glEnd();
    glPopMatrix();

    ///hand of boatman
    glPushMatrix();
    glBegin(GL_LINES);
    glVertex3f (0, 0, 0.0);
    glVertex3f (10, -40, 0.0);
    glEnd();
    glPopMatrix();


    ///boat rudder
    glPushMatrix();
    glTranslatef(20, 160, 0.0);
    glScalef(2.5, 4.7, 0.0); ///it define the scale how long it should be
    glRotatef( 1, 0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (-2.0, -37.0, 0.0);
    glVertex3f (-10, -57, 0.0);
    glVertex3f (-12, -55, 0.0);
    glVertex3f (-2, -33, 0.0);
    glEnd();
    glPopMatrix();


}

void boat()
{
    ///it is upper part that means bottom of the boat
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.2 , 0.2   , 0.1 );
    glVertex3f (-50, 0, 0.0);
    glVertex3f (-30, -25, 0.0);
    glVertex3f (30, -25, 0.0);
    glVertex3f (50, 0, 0.0);

    glEnd();

    ///it is upper part that means roof of the boat
    glBegin(GL_POLYGON);
    glColor3f(0.623529   , 0.623529     , 0.372549 );
    glVertex3f (-25, 15, 0.0);
    glVertex3f (-25, 0, 0.0);
    glVertex3f (25, 0, 0.0);
    glVertex3f (25, 15, 0.0);
    glEnd();


    glTranslatef(-40,13, 0);
    glScalef(0.5, 0.5,0);
    people();
    glPopMatrix();


}

void roadCreate()
{

    glBegin(GL_POLYGON);
    glVertex3f (-10, 10, 0.0);
    glVertex3f (-20, -20, 0.0);
    glVertex3f (20, -20, 0.0);
    glVertex3f (10, 10, 0.0);
    glEnd();
}

void road()
{
    ///first road from big room
    glColor3f(0.5 , 0.333   , 0.1 );
    glPushMatrix();
    glTranslatef(35,10,0);
    glScalef(1.5, 11.3,0);
    roadCreate();
    glPopMatrix();


    ///second road from big room
    glPushMatrix();
    glTranslatef(250,100,0);
    glRotatef(180, 1, 1, 0);
    glScalef(.8, 5,0);
    blackLines();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(135,30,0);
    glRotatef(45, 1, 1, 0);
    glScalef(1.8, 8,0);
    blackLines();
    glPopMatrix();

}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

///***** Display SKY *******
    glPushMatrix();
    sky();
    glPopMatrix();
/// ***** Display FIELD *******
    glPushMatrix();
    field();
    glPopMatrix();

//*

    glPushMatrix();
    road();
    glPopMatrix();

//*/
///**** Display Home *********

    glPushMatrix();
    glTranslatef(-275,150,0);   //first home
    glScalef(6, 4,0);
    home();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-100,100,0);    //second home
    glScalef(10, 10,0);
    home();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(190,120,0);     //third home
    glScalef(4, 4,0);
    home();
    glPopMatrix();



///***** Display River *******
    glPushMatrix();
    river();
    glPopMatrix();

///***** Display Boat *******

    glPushMatrix();
    glTranslatef(xBoat1, yBoat1,0.0);
    glScalef(1, 1,0);
    boat();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(xBoat2, yBoat2,0.0);
    glScalef(1.5, 1.5,0);
    boat();
    glPopMatrix();

///****** River down side *****
    glPushMatrix();
    river_down_flower();
    glPopMatrix();

///******* Small Boat  *****
///static stand boat
    glPushMatrix();
    glTranslatef(0,-220,0);
    glScalef(.7, .7,0);
    boat();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(70,-220,0);
    glScalef(.7, .7,0);
    glRotatef(220, 0,1, 0);
    boat();
    glPopMatrix();

    glutSwapBuffers();

}


void initOpenGl() ///select the area and background color
{
    glClearColor(0.1372554,  0.556863 , 0.137255, 1.0);
	glOrtho(-500, 500.0, -500.0, 500.0, 500.0, -500.0);
}

void arrow_key( int key, int x, int y) ///this function work for moving boat up down
{
    switch(key) {

        case GLUT_KEY_UP:

            if(yBoat1<-250){
                yBoat1 = yBoat1 + 10;
                glutPostRedisplay();
                break;
            }
            else
                break;


        case GLUT_KEY_DOWN:
            if(yBoat1 > -500) ///it select the coordinate of boat to move down
                {
                yBoat1 = yBoat1-10;
                glutPostRedisplay();
                break;
            }
            else
                break;

        default:
            break;


    }
}

void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {
		case 's':
			 PlaySound("river-2.wav", NULL, SND_ASYNC|SND_FILENAME);
			 break;
        case 'o':
            PlaySound(NULL,NULL,NULL);
            break;

	  default:
			break;
	}
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);

    if(xBoat1<550){
        xBoat1 = xBoat1 + 2;
    }
    else
        xBoat1 = -550.0;

    if(xBoat2<550){
        xBoat2 = xBoat2 + .5;
    }
    else
        xBoat2 = -550.0;

///  ****** wave one ******
    if(wave1<0){
        wave1 += 0.5;
    }
    else
        wave1 = -100.0;


 ///  ****** wave Two Move ******

    if(wave2 > 0){
        wave2 -= 0.50;
    }
    else
        wave2 = 100.0;

///  ****** wave three Move ******
    if(wave3<0){
        wave3 += 0.5;
    }
    else
        wave3 = -200.0;

    ///  ****** Cloud ******
    if(xCloud<650){
        xCloud += .5;
    }
    else
        xCloud = -650.0;

}


int main(int argc, char **argv)
{
    printf("Press 's' for sound!\n");
    printf("Press 'o' for stop the sound!\n");
    printf("Press Arrow key(up-down) for movement of small boat!\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE| GLUT_DEPTH | GLUT_RGB);
    glutInitWindowSize(1100, 560);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Project");
    initOpenGl();

    glutDisplayFunc(display);
    glutTimerFunc(0,timer,0);
    glutSpecialFunc(arrow_key);
    glutKeyboardFunc(my_keyboard);
    glutMainLoop();

    return 0;
}

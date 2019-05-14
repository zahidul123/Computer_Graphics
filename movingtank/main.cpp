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
 #include<stdlib.h>
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
float mov=-2.5;
GLfloat xBoat2 = -400.0;
GLfloat yBoat2 = -425.0;
float wave1 = -100.0;
float wave2 = 100.0;
float wave3 = -200.0;
float xCloud =150.0;
static float	tx	=  0.0;
static float	ty	=  0.0;
float tx1=0;
float sn=0;
float q=-2.3;
int cnt=0;
int blt=0;
const float DEG2RAD = 3.14159/180;
void display1();
void stars();
int p;
void stars1();
void static_rocket();
void rocket_to_cam_pos();
void rocket_in_motion();
void mars(float radius);

float j,count=0,count1=0,count3=0,flag=0,flag1=0,t=0,f=0,flag3=0,finish=0;
void semicircle(float radius,float u,float v)
{

	glColor3f(1.0 ,1.0 ,1.0);
   glBegin(GL_POLYGON);

   for (int i=135; i<=315; i++)
   {
      float degInRad = i*DEG2RAD;
      glVertex2f(u+cos(degInRad)*radius,v+(sin(degInRad))*radius);//100,100 specifies centre of the circle
   }

   glEnd();
}

void display1()
{

count1++;
 if(count1==250)
      flag=1;
   if(flag==0)
       static_rocket();
 else if((count1==151)| (count1==152))
       rocket_to_cam_pos();
  else
      rocket_in_motion();
}

void stars()
{

	glColor3f(1.0,1.0,1.0);
	glPointSize(0.37);
	glBegin(GL_POINTS);
	glVertex2i(10,20);
	glVertex2i(20,100);
	glVertex2i(30,10);
	glVertex2i(15,150);
	glVertex2i(17,80);
	glVertex2i(200,200);
	glVertex2i(55,33);
	glVertex2i(400,300);
	glVertex2i(330,110);
	glVertex2i(125,63);
	glVertex2i(63,125);
	glVertex2i(20,10);
	glVertex2i(110,330);
	glVertex2i(440,430);
	glVertex2i(32,65);
	glVertex2i(110,440);
	glVertex2i(210,230);
	glVertex2i(390,490);
	glVertex2i(12,90);
	glVertex2i(400,322);
	glVertex2i(420,366);
	glVertex2i(455,400);
	glVertex2i(20,20);
	glVertex2i(111,120);
	glVertex2i(401,200);
	glVertex2i(230,30);
	glVertex2i(220,20);
	glVertex2i(122,378);
	glVertex2i(133,340);
	glVertex2i(345,420);
	glVertex2i(130,360);
	glVertex2i(333,120);
	glVertex2i(250,22);
	glVertex2i(242,11);
	glVertex2i(280,332);
	glVertex2i(233,40);
	glVertex2i(210,418);
	glVertex2i(256,12);
	glVertex2i(288,232);
	glVertex2i(247,36);
	glVertex2i(229,342);
	glVertex2i(257,47);
	glVertex2i(290,63);
	glVertex2i(232,72);
	glVertex2i(243,143);
	glVertex2i(100,200);
	glVertex2i(90,250);
	glVertex2i(80,225);
	glVertex2i(50,333);
	glVertex2i(60,350);
	glVertex2i(243,143);
	glVertex2i(243,143);
	glEnd();
}

void stars1()
{
	int l;
	glColor3f(1.0,1.0,1.0);
	glPointSize(0.3);
	glBegin(GL_POINTS);
	glVertex2i(50,20);
	glVertex2i(70,100);
	glVertex2i(80,10);
	glVertex2i(65,150);
	glVertex2i(67,80);
	glVertex2i(105,33);
	glVertex2i(450,300);
	glVertex2i(380,110);
	glVertex2i(175,63);
	glVertex2i(113,125);
	glVertex2i(70,10);
	glVertex2i(160,330);
	glVertex2i(490,430);
	glVertex2i(82,65);
	glVertex2i(160,440);
	glVertex2i(440,490);
	glVertex2i(62,90);
	glVertex2i(450,322);
	glVertex2i(420,366);
	glVertex2i(455,400);
	glVertex2i(60,20);
	glVertex2i(111,120);
	glVertex2i(451,200);
	glVertex2i(280,30);
	glVertex2i(220,20);
	glVertex2i(132,378);
	glVertex2i(173,340);
	glVertex2i(325,420);
	glVertex2i(180,360);
	glVertex2i(383,120);
	glVertex2i(200,22);
	glVertex2i(342,11);
	glVertex2i(330,332);
	glVertex2i(283,40);
	glVertex2i(210,418);
	glVertex2i(256,12);
	glVertex2i(288,232);
	glVertex2i(247,36);
	glVertex2i(229,342);
	glVertex2i(257,47);
	glVertex2i(290,63);
	glVertex2i(232,72);
	glVertex2i(243,143);
	glVertex2i(100,200);
	glVertex2i(90,250);
	glVertex2i(80,225);
	glVertex2i(50,333);
	glVertex2i(60,350);
	glVertex2i(243,143);
	glVertex2i(243,143);
	glEnd();
	for(l=0;l<=10000;l++)
		;
}
void static_rocket()
{

count1++;
if(count1==150)
flag=1;
  if(flag==0)
  {
	glClearColor(0.196078  ,0.6 ,0.8,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glColor3f(0.4,0.25,0.1);
		glBegin(GL_POLYGON);//green ground
		glVertex2f(0.0,0.0);
		glVertex2f(0.0,250.0);
		glVertex2f(270.0,250.0);
		glVertex2f(500.0,50.0);
		glVertex2f(500.0,0.0);
		glEnd();
		glBegin(GL_POLYGON);//green ground
		glVertex2f(280.0,250.0);
		glVertex2f(500.0,250.0);
		glVertex2f(500.0,60.0);
		glEnd();
		glColor3f(0.0,0.0,0.0);
			glBegin(GL_POLYGON);//road
		glVertex2f(260.0,250.0);
		glVertex2f(290.0,250.0);
		glVertex2f(500.0,70.0);
		glVertex2f(500.0,40.0);
		glEnd();
		glColor3f(0.0,0.0,0.0);


		glColor3f(0.8,0.498039 ,0.196078);
			glBegin(GL_POLYGON);//house 1
		glVertex2f(250.0,250.0);
		glVertex2f(300.0,250.0);
		glVertex2f(300.0,350.0);
		glVertex2f(250.0,350.0);
		glEnd();
		glColor3f(0.7,0.7,0.7);
		glBegin(GL_POLYGON);//HOUSE A
			glVertex2f(255,267.5);
			glVertex2f(275.0,267.5);
			glVertex2f(275.0,277.5);
			glVertex2f(255.0,277.5);
			glEnd();
		glBegin(GL_POLYGON);//HOUSE B
			glVertex2f(255,285.0);
			glVertex2f(275.0,285);
			glVertex2f(275.0,295);
			glVertex2f(255.0,295);
			glEnd();

		glBegin(GL_POLYGON);//HOUSE C
			glVertex2f(255,302.5);
			glVertex2f(275.0,302.5);
			glVertex2f(275.0,312.5);
			glVertex2f(255.0,312.5);
			glEnd();

		glBegin(GL_POLYGON);//HOUSE D
			glVertex2f(255,320.0);
			glVertex2f(275.0,320.0);
			glVertex2f(275.0,330.0);
			glVertex2f(255.0,330.0);
			glEnd();

		glBegin(GL_POLYGON);//HOUSE E
			glVertex2f(285,267.5);
			glVertex2f(295.0,267.5);
			glVertex2f(295.0,277.5);
			glVertex2f(285.0,277.5);
			glEnd();

		glBegin(GL_POLYGON);//HOUSE F
			glVertex2f(285,285.0);
			glVertex2f(295.0,285);
			glVertex2f(295.0,295);
			glVertex2f(285.0,295);
			glEnd();

		glBegin(GL_POLYGON);//HOUSE G
			glVertex2f(285,302.5);
			glVertex2f(295.0,302.5);
			glVertex2f(295.0,312.5);
			glVertex2f(285.0,312.5);
			glEnd();

		glBegin(GL_POLYGON);//HOUSE H
			glVertex2f(285,320.0);
			glVertex2f(295.0,320.0);
			glVertex2f(295.0,330.0);
			glVertex2f(285.0,330.0);
			glEnd();
			glColor3f(0.647059 ,0.164706  ,0.164706);
			glBegin(GL_POLYGON);//solid cone
			glVertex2f(26,250);
			glVertex2f(52,250);
			glVertex2f(39,290);
			glEnd();
			semicircle(20.0,50,300);

	glColor3f(0.0,0.0 ,0.0);
			glBegin(GL_LINES);//wires
			glVertex2f(37,313);
			glVertex2f(62,310);
			glVertex2f(63,287);
			glVertex2f(62,310);
			glEnd();
		glColor3f(1.0,1.0,1.0);

		glEnd();
		glPointSize(2.0);

	glColor3f(1.0,1.0 ,1.0);
			glBegin(GL_POINTS);//road paint
			glVertex2f(497,56);
			glVertex2f(488,65);
			glVertex2f(479,74);
			glVertex2f(470,83);
			glVertex2f(460,92);
			glVertex2f(450,101);
			glVertex2f(439,110);
			glVertex2f(428,119);
			glVertex2f(418,128);
			glVertex2f(408,137);
			glVertex2f(398,146);
			glVertex2f(388,155);
			glVertex2f(378,164);
			glVertex2f(366,173);
			glVertex2f(356,182);
			glVertex2f(346,191);
			glVertex2f(336,200);
			glVertex2f(324,209);
			glVertex2f(314,218);
			glVertex2f(304,227);
			glVertex2f(294,234);
			glVertex2f(284,243);
	        glVertex2f(278,248);

			glEnd();

	glColor3f(0.8,0.498039 ,0.196078);
	glBegin(GL_POLYGON);//core
		glVertex2f(237.5,20.0);
		glVertex2f(262.5,20.0);
		glVertex2f(262.5,120.0);
		glVertex2f(237.5,120.0);


	glEnd();

	glColor3f(1.0,1.0,1.0);//bonnet
	glBegin(GL_POLYGON);//front
	glVertex2f(237.5,120.0);
	glVertex2f(262.5,120.0);
	glVertex2f(250,170.0);
	glEnd();
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);//left_side_top
	glVertex2f(237.5,120.0);
	glVertex2f(217.5,95.0);
	glVertex2f(237.5,95.0);
	glEnd();
		glBegin(GL_POLYGON);//left_side_bottom
	glVertex2f(237.5,20.0);
	glVertex2f(217.5,20.0);
	glVertex2f(237.5,70.0);
	glEnd();
		glBegin(GL_POLYGON);//right_side_bottom
	glVertex2f(262.5,20.0);
	glVertex2f(282.5,20.0);
	glVertex2f(262.5,70.0);
	glEnd();
		glBegin(GL_POLYGON);//right_side_top
	glVertex2f(262.5,120.0);
	glVertex2f(262.5,95.0);
	glVertex2f(282.5,95.0);
	glEnd();
	glColor3f(0.556863 ,0.137255  ,0.419608);
		glBegin(GL_POLYGON);//bottom_1_exhaust
	glVertex2f(237.5,20.0);
	glVertex2f(244.5,20.0);
	glVertex2f(241,0.0);
	glEnd();
		glBegin(GL_POLYGON);//bottom_2_exhaust
	glVertex2f(246.5,20.0);
	glVertex2f(253.5,20.0);
	glVertex2f(249.5,0.0);
	glEnd();
		glBegin(GL_POLYGON);//bottom_3_exhaust
	glVertex2f(262.5,20.0);
	glVertex2f(255.5,20.0);
	glVertex2f(258.5,0.0);
	glEnd();

	glBegin(GL_POLYGON);//left_stand_holder
	glVertex2f(182.5,85.0);
	glVertex2f(182.5,0.0);
	glVertex2f(187.5,0.0);
	glVertex2f(187.5,80.0);
	glVertex2f(237.5,80.0);
	glVertex2f(237.5,85.0);
	glVertex2f(182.5,85.0);
	glEnd();
	glBegin(GL_POLYGON);
glVertex2f(312.5,85.0);//right_stand_holder
	glVertex2f(312.5,0.0);
	glVertex2f(307.5,0.0);
	glVertex2f(307.5,80.0);
	glVertex2f(262.5,80.0);
	glVertex2f(262.5,85.0);
	glVertex2f(312.5,85.0);
	glEnd();

	for(j=0;j<=1000000;j++)
		;
	glutSwapBuffers();
	glutPostRedisplay();
	glFlush();
}

}
void rocket_to_cam_pos()
{
	count++;
count3++;

for(i=0;i<=200;i++)
{

	glClearColor(0.196078  ,0.6 ,0.8,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glColor3f(0.8,0.498039 ,0.196078);
	glBegin(GL_POLYGON);//core
		glVertex2f(237.5,20.0+i);
		glVertex2f(262.5,20.0+i);
		glVertex2f(262.5,120.0+i);
		glVertex2f(237.5,120.0+i);


	glEnd();

	glColor3f(1.0,1.0,1.0);//bonnet
	glBegin(GL_POLYGON);//front
	glVertex2f(237.5,120.0+i);
	glVertex2f(262.5,120.0+i);
	glVertex2f(250,170.0+i);
	glEnd();
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);//left_side_top
	glVertex2f(237.5,120.0+i);
	glVertex2f(217.5,95.0+i);
	glVertex2f(237.5,95.0+i);
	glEnd();
		glBegin(GL_POLYGON);//left_side_bottom
	glVertex2f(237.5,20.0+i);
	glVertex2f(217.5,20.0+i);
	glVertex2f(237.5,70.0+i);
	glEnd();
		glBegin(GL_POLYGON);//right_side_bottom
	glVertex2f(262.5,20.0+i);
	glVertex2f(282.5,20.0+i);
	glVertex2f(262.5,70.0+i);
	glEnd();
		glBegin(GL_POLYGON);//right_side_top
	glVertex2f(262.5,120.0+i);
	glVertex2f(262.5,95.0+i);
	glVertex2f(282.5,95.0+i);
	glEnd();
	glColor3f(0.556863 ,0.137255  ,0.419608);
		glBegin(GL_POLYGON);//bottom_1_exhaust
	glVertex2f(237.5,20.0+i);
	glVertex2f(244.5,20.0+i);
	glVertex2f(241,0.0+i);
	glEnd();
		glBegin(GL_POLYGON);//bottom_2_exhaust
	glVertex2f(246.5,20.0+i);
	glVertex2f(253.5,20.0+i);
	glVertex2f(249.5,0.0+i);
	glEnd();
		glBegin(GL_POLYGON);//bottom_3_exhaust
	glVertex2f(262.5,20.0+i);
	glVertex2f(255.5,20.0+i);
	glVertex2f(258.5,0.0+i);
	glEnd();

	if((p%2)==0)
				 glColor3f(1.0,0.25,0.0);
				 else
					 glColor3f(1.0,0.816,0.0);

        glBegin(GL_POLYGON);//outer fume
		glVertex2f(237.5,20+i);
		glVertex2f(234.16,16.66+i);
		glVertex2f(230.82,13.32+i);
		glVertex2f(227.48,9.98+i);
		glVertex2f(224.14,6.64+i);
		glVertex2f(220.8,3.3+i);
		glVertex2f(217.5,0+i);
		glVertex2f(221.56,-5+i);
		glVertex2f(225.62,-10+i);
		glVertex2f(229.68,-15+i);
		glVertex2f(233.74,-20+i);
		glVertex2f(237.8,-25+i);
		glVertex2f(241.86,-30+i);
		glVertex2f(245.92,-35+i);
		glVertex2f(250,-40+i);
		glVertex2f(254.06,-35+i);
		glVertex2f(258.12,-30+i);
		glVertex2f(262.18,-25+i);
		glVertex2f(266.24,-20+i);
		glVertex2f(270.3,-15+i);
		glVertex2f(274.36,-10+i);
		glVertex2f(278.42,-5+i);
		glVertex2f(282.5,0+i);
		glVertex2f(278.5,4+i);
		glVertex2f(274.5,8+i);
		glVertex2f(270.5,12+i);
		glVertex2f(266.5,16+i);
		glVertex2f(262.5,20+i);//28 points
		glEnd();

				 	if((p%2)==0)
				 glColor3f(1.0,0.816,0.0);
				 else
					 glColor3f(1.0,0.25,0.0);

		glBegin(GL_POLYGON);//inner fume
		glVertex2f(237.5,20+i);
		glVertex2f(236.5,17.5+i);
		glVertex2f(235.5,15+i);
		glVertex2f(234.5,12.5+i);
		glVertex2f(233.5,10+i);
		glVertex2f(232.5,7.5+i);
		glVertex2f(236,5+i);
		glVertex2f(239.5,2.5+i);
		glVertex2f(243,0+i);
		glVertex2f(246.5,-2.5+i);
		glVertex2f(250,-5+i);
		glVertex2f(253.5,-2.5+i);
		glVertex2f(257,0+i);
		glVertex2f(260.5,2.5+i);
		glVertex2f(264,5+i);
		glVertex2f(267.5,7.5+i);
		glVertex2f(266.5,10+i);
		glVertex2f(265.5,12.5+i);
		glVertex2f(264.5,15+i);
		glVertex2f(263.5,17.5+i);
		glVertex2f(261.5,20+i);
		glVertex2f(260.5,20+i);
		glVertex2f(259.5,20+i);
		glVertex2f(262.5,20+i);
		glVertex2f(258.5,20+i);
		glVertex2f(257.5,20+i);
		glVertex2f(256.5,20+i);
		glVertex2f(255.5,20+i);
		glVertex2f(254.5,20+i);
		glVertex2f(253.5,20+i);
		glVertex2f(251.5,20+i);
		glVertex2f(250.5,20+i);
		glVertex2f(249.5,20+i);
		glVertex2f(248.5,20+i);//21 points

		glEnd();
		p=p+1;
	///for(j=0;j<=1000000;j++);
	glutSwapBuffers();
	glutPostRedisplay();

	glFlush();
}
}
void rocket_in_motion()
{
	count++;


for(i=195;i<=200;i++)
{
     if(count>=5)
	 {
		 	glClearColor(0.0 ,0.0 ,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	if(flag1==0)
	{
	stars();
	flag1=1;
	}
	else
	{
		stars1();

		flag1=0;
	}

	 }
	 else
	 {
	glClearColor(0.196078  ,0.6 ,0.8,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	 }
	 if(count>=100)
	 mars(20.0);
	glColor3f(0.8,0.498039 ,0.196078);
	glBegin(GL_POLYGON);//core
		glVertex2f(237.5,20.0+i);
		glVertex2f(262.5,20.0+i);
		glVertex2f(262.5,120.0+i);
		glVertex2f(237.5,120.0+i);


	glEnd();

	glColor3f(1.0,1.0,1.0);//bonnet
	glBegin(GL_POLYGON);//front
	glVertex2f(237.5,120.0+i);
	glVertex2f(262.5,120.0+i);
	glVertex2f(250,170.0+i);
	glEnd();
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);//left_side_top
	glVertex2f(237.5,120.0+i);
	glVertex2f(217.5,95.0+i);
	glVertex2f(237.5,95.0+i);
	glEnd();
		glBegin(GL_POLYGON);//left_side_bottom
	glVertex2f(237.5,20.0+i);
	glVertex2f(217.5,20.0+i);
	glVertex2f(237.5,70.0+i);
	glEnd();
		glBegin(GL_POLYGON);//right_side_bottom
	glVertex2f(262.5,20.0+i);
	glVertex2f(282.5,20.0+i);
	glVertex2f(262.5,70.0+i);
	glEnd();
		glBegin(GL_POLYGON);//right_side_top
	glVertex2f(262.5,120.0+i);
	glVertex2f(262.5,95.0+i);
	glVertex2f(282.5,95.0+i);
	glEnd();
	glColor3f(0.556863 ,0.137255  ,0.419608);
		glBegin(GL_POLYGON);//bottom_1_exhaust
	glVertex2f(237.5,20.0+i);
	glVertex2f(244.5,20.0+i);
	glVertex2f(241,0.0+i);
	glEnd();
		glBegin(GL_POLYGON);//bottom_2_exhaust
	glVertex2f(246.5,20.0+i);
	glVertex2f(253.5,20.0+i);
	glVertex2f(249.5,0.0+i);
	glEnd();
		glBegin(GL_POLYGON);//bottom_3_exhaust
	glVertex2f(262.5,20.0+i);
	glVertex2f(255.5,20.0+i);
	glVertex2f(258.5,0.0+i);
	glEnd();
	if((p%2)==0)
				 glColor3f(1.0,0.25,0.0);
				 else
					 glColor3f(1.0,0.816,0.0);

				 glBegin(GL_POLYGON);//outer fume
		glVertex2f(237.5,20+i);
		glVertex2f(234.16,16.66+i);
		glVertex2f(230.82,13.32+i);
		glVertex2f(227.48,9.98+i);
		glVertex2f(224.14,6.64+i);
		glVertex2f(220.8,3.3+i);
		glVertex2f(217.5,0+i);
		glVertex2f(221.56,-5+i);
		glVertex2f(225.62,-10+i);
		glVertex2f(229.68,-15+i);
		glVertex2f(233.74,-20+i);
		glVertex2f(237.8,-25+i);
		glVertex2f(241.86,-30+i);
		glVertex2f(245.92,-35+i);
		glVertex2f(250,-40+i);
		glVertex2f(254.06,-35+i);
		glVertex2f(258.12,-30+i);
		glVertex2f(262.18,-25+i);
		glVertex2f(266.24,-20+i);
		glVertex2f(270.3,-15+i);
		glVertex2f(274.36,-10+i);
		glVertex2f(278.42,-5+i);
		glVertex2f(282.5,0+i);
		glVertex2f(278.5,4+i);
		glVertex2f(274.5,8+i);
		glVertex2f(270.5,12+i);
		glVertex2f(266.5,16+i);
		glVertex2f(262.5,20+i);//28 points
		glEnd();

				 	if((p%2)==0)
				 glColor3f(1.0,0.816,0.0);
				 else
					 glColor3f(1.0,0.25,0.0);

		glBegin(GL_POLYGON);//inner fume
		glVertex2f(237.5,20+i);
		glVertex2f(236.5,17.5+i);
		glVertex2f(235.5,15+i);
		glVertex2f(234.5,12.5+i);
		glVertex2f(233.5,10+i);
		glVertex2f(232.5,7.5+i);
		glVertex2f(236,5+i);
		glVertex2f(239.5,2.5+i);
		glVertex2f(243,0+i);
		glVertex2f(246.5,-2.5+i);
		glVertex2f(250,-5+i);
		glVertex2f(253.5,-2.5+i);
		glVertex2f(257,0+i);
		glVertex2f(260.5,2.5+i);
		glVertex2f(264,5+i);
		glVertex2f(267.5,7.5+i);
		glVertex2f(266.5,10+i);
		glVertex2f(265.5,12.5+i);
		glVertex2f(264.5,15+i);
		glVertex2f(263.5,17.5+i);
		glVertex2f(262.5,20+i);//21 points

		glEnd();
		p=p+1;


	for(j=0;j<=1000000;j++)
		;
	glutSwapBuffers();
	glutPostRedisplay();




	if(finish==10000){
        exit(0);
	}
	finish++;
	printf("%lf",finish);
	glFlush();
}
}

void mars(float radius)
{


   glBegin(GL_POLYGON);

   for (int i=0; i<=359; i++)
   {
      float degInRad = i*DEG2RAD;
      glVertex2f(300+f+cos(degInRad)*radius,500-t+(sin(degInRad))*radius);//100,100 specifies centre of the circle
   }

   glEnd();
   t=t+0.1;
   f=f+0.1;
}


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
void sun(GLdouble rad)
{
    if(sn<=200.0){
     sn=sn+.04;}

  else{
        sn=0;}
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;
    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta)-sn+590,480+sn+rad * sin(theta));
        }
    }
    glEnd();
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


}
void field()
{
    glBegin(GL_POLYGON);
    glColor3f(0.1372554,  0.556863 , 0.137255);
    glVertex3f (0,175, 0.0);
    glVertex3f (0,455, 0.0);
    glVertex3f (600,455, 0.0);
    glVertex3f (600,175, 0.0);
    glEnd();

    /// Display Tree Left Side
    glPushMatrix();
    glTranslatef(80,90,0);
    field_side();
    glPopMatrix();

    /// Display Tree Right Side
    glPushMatrix();
    glTranslatef(350,90,0);
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
    glTranslatef(250.0,10, 0.0);
    glScalef(3,3,0);
    glRotatef(45, 0, 1, 0);
    riverSide();
    glPopMatrix();
 }
void sky()
{

    glBegin(GL_POLYGON);
    glColor3f(0.1 , 0.847059 , 1.0);
    glVertex3f (0.0, 450, 0.0);
    glVertex3f (0.0, 600, 0.0);
    glVertex3f (600,600, 0.0);
    glVertex3f (600,450, 0.0);

    glEnd();

    /// SUN
    glColor3f(1 , .8 ,0.0);
    glPushMatrix();
   // glTranslatef(590, 450, 0.0);
    sun(30);
    glPopMatrix();

 /// Cloud
    glPushMatrix();
    glTranslatef(xCloud, 540, 0.0);
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


void init()
{
    glClearColor(0.5f,0.33f,0.1f,0.0f);
   //glOrtho(-500, 500.0, -500.0, 500.0, 500.0, -500.0);
   // glOrtho2D(0.0,15,-2,15,-1,0);
   glPointSize(1.0);
	gluOrtho2D(0.0,600.0,0.0,600.0);
}

void tank(void){
cnt++;

if(cnt>=2500){
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutIdleFunc(display1);
	glutInitWindowSize(500,500);
   display1();
glFlush();
}else{
if(q<=500.0){
     q=q+1;}

  else{
        q=-2.3;}
    glutPostRedisplay();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);
glPushMatrix();
     glBegin(GL_QUADS);
        glColor3f(0.18f,0.30f,0.30f);
        glVertex3d(q+0.0,80+ty,0.0);
        glVertex3d(q+100,80+ty,0.0);
        glVertex3d(q+100,50+ty,0.0);
        glVertex3f(q+0.0,50+ty,0.0);

    glEnd();
   glPopMatrix();


    glPushMatrix();
   glBegin(GL_QUADS);
   glColor3f(0.18f,0.30f,0.30f);
       glVertex3d(q+0.0,80+ty,0.0);
       glVertex3d(q+0.0,110+ty,0.0);
       glVertex3d(q+90,110+ty,0.0);
       glVertex3f(q+100.0,80+ty,0.0);
    glEnd();
glPopMatrix();



    glPushMatrix();
   glBegin(GL_QUADS);
   glColor3f(0.18f,0.30f,0.30f);
       glVertex3d(q+40,110+ty,0.0);
       glVertex3d(q+40,116+ty,0.0);
       glVertex3d(q+60,116+ty,0.0);
       glVertex3f(q+60,110+ty,0.0);
    glEnd();
glPopMatrix();

    int i;
    int triangleAmount = 100; //# of triangles used to draw circle

    GLfloat radius = 15.0f; //radius
    GLfloat twicePi = 2.0f * 3.1416;


    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.0f,0.0f);
        //glVertex2f(1.5,2.5); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    q+43 + (radius * cos(  i*twicePi  /triangleAmount)),
                155+ty+ (radius * sin(i*twicePi / triangleAmount))
            );
        }
    glEnd();
   glPopMatrix();



    glPushMatrix();
   glBegin(GL_QUADS);
   glColor3f(0.18f,0.30f,0.30f);
       glVertex3d(q+20,116+ty,0.0);
       glVertex3d(q+20,155+ty,0.0);
       glVertex3d(q+80,155+ty,0.0);
       glVertex3d(q+80,116+ty,0.0);
    glEnd();
glPopMatrix();


    glPushMatrix();
  glBegin(GL_QUADS);
   glColor3f(0.18f,0.30f,0.30f);
       glVertex3d(q+80,127+ty,0.0);
       glVertex3d(q+80,142+ty,0.0);
       glVertex3d(q+115,142+ty,0.0);
       glVertex3d(q+115,127+ty,0.0);
    glEnd();

    glPopMatrix();

///head of cylinder

glPushMatrix();
        glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.18f,0.30f,0.30f);
       // glVertex2f(3.5,2.3); // center of circle
        for(i = 0; i <= 100;i++) {
            glVertex2f(
                    q+110 + (radius * cos(  i*twicePi  /triangleAmount)),
                134+ty+(radius * sin(i*twicePi / triangleAmount))
            );
        }
    glEnd();
    glPopMatrix();

///wheel drawing


glPushMatrix();
        radius=10;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f,0.0f,0.0f);
        for(i = 0; i <= 1000;i++) {
            glVertex2f(
                     q+13+(radius * cos(  i*twicePi  /triangleAmount)),
                 40+ty+(radius * sin(i*twicePi / triangleAmount))
            );
        }
    glEnd();
    glPopMatrix();


    glPushMatrix();
     radius=10;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f,0.0f,0.0f);
        for(i = 0; i <= 1000;i++) {
            glVertex2f(
                     q+27+(radius * cos(  i*twicePi  /triangleAmount)),
                 40+ty+(radius * sin(i*twicePi / triangleAmount))
            );
        }
    glEnd();

    glPopMatrix();

    glPushMatrix();
     radius=10;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f,0.0f,0.0f);
        for(i = 0; i <= 1000;i++) {
            glVertex2f(
                     q+72+(radius * cos(  i*twicePi  /triangleAmount)),
                 40+ty+(radius * sin(i*twicePi / triangleAmount))
            );
        }
    glEnd();
glPopMatrix();


    glPushMatrix();
     radius=10;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f,0.0f,0.0f);
        for(i = 0; i <= 1000;i++) {
            glVertex2f(
                    q+85+(radius * cos(  i*twicePi  /triangleAmount)),
                 40+ty+(radius * sin(i*twicePi / triangleAmount))
            );
        }
    glEnd();

glPopMatrix();

glBegin(GL_QUADS);
glColor3f(0.14,.54,0.34);
glVertex2d(q+50,65+ty);
glVertex2d(q+50,90+ty);
glVertex2d(q+85,90+ty);
glVertex2d(q+85,65+ty);
glEnd();

glPushMatrix();
 radius=5;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f,0.0f,0.0f);
        for(i = 0; i <= 1000;i++) {
            glVertex2f(
                    q+70+(radius * cos(  i*twicePi  /triangleAmount)),    //flag circle
                 75+ty+(radius * sin(i*twicePi / triangleAmount))
            );
        }
    glEnd();
glPopMatrix();
      if(mov<500)
        {
            mov+=2;
        }
        else{
            mov=-2.5;
        }
        tx=q+110+mov;
        if(blt==1){
            glBegin(GL_POLYGON);
            glColor3f(1,.25,0);
            glVertex2d(tx-8,134-8+ty);
            glVertex2d(tx-8,134+8+ty);
            glVertex2d(tx+8,134+8+ty);
            glVertex2d(tx+12,134+ty);
            glVertex2d(tx+8,134-8+ty);
            glEnd();
          //  blt=0;
        }



sky();
/// ***** Display FIELD *******
    glPushMatrix();
    field();
    glPopMatrix();

    ///**** Display Home *********

    glPushMatrix();
    glTranslatef(435,270,0);   //first home
    glScalef(8,7,0);
    home();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(280,200,0);    //second home
    glScalef(10, 10,0);
    home();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(100,360,0);     //third home
    glScalef(4, 4,0);
    home();
    glPopMatrix();
glFlush();
}
}

void special_key(int key,int x, int y){
    switch (key) {
		case GLUT_KEY_UP:
		    if(ty>2){
                ty=2;
		    }else{
		    ty+=1;
		    }
		    glutPostRedisplay();
				break;
		case GLUT_KEY_DOWN:
		    if(ty<-8){
                ty=-4;
		    }else{
		    ty-=1;
		    }

				glutPostRedisplay();
				break;
        case GLUT_KEY_RIGHT:
				blt=1;

            PlaySound("MortarRound.wav", NULL, SND_ASYNC|SND_FILENAME);
				break;
		case GLUT_KEY_LEFT:
		    PlaySound("Horn Honk-SoundBible.com-1162546405.wav", NULL, SND_ASYNC|SND_FILENAME);
                blt=0;
				glutPostRedisplay();
				break;

	  default:
			break;
	}
}

 void display(void)
{
 tank();
    glFlush();
}




int main(int argc, char *argv[])
{
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("tank");
    init();
    glutDisplayFunc(display);
   // glutSpecialFunc(arrow_key);
    glutSpecialFunc(special_key);
    glutMainLoop();
    return 0;
}

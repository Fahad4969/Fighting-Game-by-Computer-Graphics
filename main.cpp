#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <GL/glut.h>
#include<mmsystem.h>
#include<string.h>
#pragma region
using namespace std;
//20,144,255
int a=135,b=205,c=250,t1=255,t2=255,t3=255,t4=20,t5=144,t6=255;
double x=-0.9,x1=-0.95,y=-7.3,xy=-0.32,r2=1,xy1=0.6,ch=0,ch1=0,p=1000,p1=70,p2=150;
bool full=false,pause=false,menu=false,ins=false;
int level=0,menu1=0;

//double move_unit = 15;

float xr=0,yr=0;
//colCountL=enemyhealth
//colCountR=Herohealth
int colCountL=0,colCountR=0;





//Initializes 3D rendering
void initRendering()
{
    glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
    //PlaySound(TEXT("Shot.wav"),NULL,SND_ASYNC);

}

float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;


//Draws the 3D scene
void drawmenu()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
    glLoadIdentity(); //Reset the drawing perspective
    glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
    glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units

    glPushMatrix();
    glTranslatef(0.50, 0.20, 0.0);
    glScalef(0.5,0.5,0);
    //glRotatef(_angle, 0.0, 0.0, 1.0);

    glPushMatrix();
    //glTranslatef(-0.0, 0.0, 0.0);
    glScalef(0.50, 0.50, 0.0);


    glPushMatrix();


    glBegin(GL_QUADS);


    glColor3ub(192,192,192);///silver


    glutSolidTorus(.2,.5,100,100);


    glPopMatrix();



///arrow (square) start
    glPushMatrix();

    glColor3ub(t1,t2,t3);///blue
    glBegin(GL_QUADS);


    glVertex3f(0.9, -03.7, 0.0);
    glVertex3f(0.9, -04.3, 0.0);
    glVertex3f(-01.10, -04.3, 0.0);
    glVertex3f(-01.10, -03.7, 0.0);

    glVertex3f(02.7, -03.9, 0.0);
    glVertex3f(02.7, -03.9, 0.0);
    glVertex3f(0.9, -04.5, 0.0);
    glVertex3f(0.9, -03.55, 0.0);




    glEnd();


    glPopMatrix();


    glPushMatrix();

    glBegin(GL_TRIANGLES);
///spike

    glVertex3f(-01.20, -0.80, 0.0);
    glVertex3f(0.0, 01.7, 0.0);
    glVertex3f(01.20, -0.80, 0.0);


    glVertex3f(-01.20, 0.80, 0.0);
    glVertex3f(0.0, -01.7, 0.0);
    glVertex3f(01.20, 0.80, 0.0);

    glEnd();

    glPopMatrix();
    glPopMatrix();


    glPopMatrix();

    ///setting end


    ///pause start
    glPushMatrix();
    glTranslatef(-0.50, 0.20, 0.0);
    glScalef(0.5,0.5,0);
    //glRotatef(_angle, 0.0, 0.0, 1.0);



    glPushMatrix();
    //glTranslatef(-0.0, 0.0, 0.0);
    glScalef(0.50, 0.50, 0.0);

    glPushMatrix();
    glColor3ub(t4,t5,t6);///blue

    glutSolidTorus(.2,1,100,100);


    glPopMatrix();


    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(192,192,192);///silver


    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(0.35, -0.5, 0.0);
    glVertex3f(0.35, 0.5, 0.0);



    glVertex3f(0.10, 0.5, 0.0);
    glVertex3f(0.10, -0.5, 0.0);
    glVertex3f(0.25, -0.5, 0.0);
    glVertex3f(0.25, 0.5, 0.0);




    glEnd();




    glPopMatrix();


    glPushMatrix();

    glBegin(GL_TRIANGLES);



    glVertex3f(0.08, -0.0, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glVertex3f(-0.5, -0.5, 0.0);

    glEnd();

    glPopMatrix();
    glPopMatrix();


///arrow (square) start
    glPushMatrix();
    glBegin(GL_QUADS);

    glColor3ub(t4,t5,t6);///blue


    glVertex3f(0.6, -01.85, 0.0);
    glVertex3f(0.6, -02.15, 0.0);
    glVertex3f(-0.45, -02.15, 0.0);
    glVertex3f(-0.45, -01.85, 0.0);


    glVertex3f(-0.45, -01.7, 0.0);
    glVertex3f(-0.45, -02.25, 0.0);
    glVertex3f(-01.5, -02.0, 0.0);
    glVertex3f(-01.5, -02.0, 0.0);



    glEnd();


    glPopMatrix();

///arrow (square) end



    glPopMatrix();

    ///pause end

///hero start
    glPushMatrix();
    glTranslatef(-01.80, -01.40, 0.0);
    glScalef(0.7,0.7,0);
    glRotatef(45, 0.0, 0.0, 1.0);



    glPushMatrix(); //Save the transformations performed thus far
    //glTranslatef(1.0, -1.0, 0.0);
    //glScalef(2.5,2.5,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
    //hand


    glColor3ub(85,107,47);
    glBegin(GL_QUADS);

    glVertex3f(0.4, -0.2, 0.0);
    glVertex3f(-0.2, -0.2, 0.0);
    glVertex3f(-0.2,-0.4, 0.0);
    glVertex3f(0.4,-0.4,0);


    glVertex3f(0.4,-0.2, 0.0);
    glVertex3f(0.4,-0.4,0);
    glVertex3f(0.8, -0.6, 0.0);
    glVertex3f(0.8, 0.0, 0.0);

    glVertex3f(0.8,-0.6, 0.0);
    glVertex3f(1.0,-0.6,0);
    glVertex3f(1.0, -0.5, 0.0);
    glVertex3f(0.8, -0.5, 0.0);

    glVertex3f(0.8,-0.0, 0.0);
    glVertex3f(1.0,-0.0,0);
    glVertex3f(1.0, -0.1, 0.0);
    glVertex3f(0.8, -0.1, 0.0);

    glEnd();

    glTranslatef(-0.3, -0.3, 0.0);

    glColor3ub(72,61,139);
    //HAND

    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.15;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();

    glPopMatrix();


    glPushMatrix(); //Save the transformations performed thus far
    //glTranslatef(1.0, -1.0, 0.0);
    //glScalef(2.5,2.5,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
    glBegin(GL_QUADS);


    glColor3ub(0,100,0);
    //spot

    glVertex3f(-0.60, -0.10, 0.0);
    glVertex3f(-0.50, -0.2, 0.0);
    glVertex3f(-0.5, -0.4, 0.0);
    glVertex3f(-0.55,-0.10,0);


    glVertex3f(-0.60, -0.50, 0.0);
    glVertex3f(-0.50, -0.4, 0.0);
    glVertex3f(-0.5, -0.48, 0.0);
    glVertex3f(-0.55,-0.50,0);


    glVertex3f(-0.60, -0.80, 0.0);
    glVertex3f(-0.50, -0.7, 0.0);
    glVertex3f(-0.5, -0.68, 0.0);
    glVertex3f(-0.55,-0.80,0);


    glVertex3f(-0.40, -0.90, 0.0);
    glVertex3f(-0.30, -0.85, 0.0);
    glVertex3f(-0.3, -0.7, 0.0);
    glVertex3f(-0.35,-0.90,0);

    glVertex3f(-0.10, -0.95, 0.0);
    glVertex3f(-0.08, -0.75, 0.0);
    glVertex3f(-0.2, -0.60, 0.0);
    glVertex3f(-0.15,-0.85,0);

    glVertex3f(-0.10, -0.45, 0.0);
    glVertex3f(-0.08, -0.55, 0.0);
    glVertex3f(-0.2, -0.60, 0.0);
    glVertex3f(-0.15,-0.5,0);

    glVertex3f(-0.30, -0.45, 0.0);
    glVertex3f(-0.28, -0.65, 0.0);
    glVertex3f(-0.35, -0.60, 0.0);
    glVertex3f(-0.25,-0.55,0);

    glVertex3f(-0.30, -0.0, 0.0);
    glVertex3f(-0.28, -0.1, 0.0);
    glVertex3f(-0.35, -0.1, 0.0);
    glVertex3f(-0.25,-0.0,0.0);

    glVertex3f(-0.0, -0.0, 0.0);
    glVertex3f(-0.08, -0.1, 0.0);
    glVertex3f(-0.05, -0.1, 0.0);
    glVertex3f(-0.05,-0.0,0.0);


    glColor3ub(160,82,45);



    glVertex3f(-0.55, -0.10, 0.0);
    glVertex3f(-0.50, -0.2, 0.0);
    glVertex3f(-0.56, -0.4, 0.0);
    glVertex3f(-0.50,-0.10,0);


    glVertex3f(-0.4, -0.50, 0.0);
    glVertex3f(-0.40, -0.4, 0.0);
    glVertex3f(-0.50, -0.48, 0.0);
    glVertex3f(-0.45,-0.50,0);


    glVertex3f(-0.10, -0.80, 0.0);
    glVertex3f(-0.20, -0.7, 0.0);
    glVertex3f(-0.1, -0.5, 0.0);
    glVertex3f(-0.15,-0.80,0);


    glVertex3f(-0.50, -0.90, 0.0);
    glVertex3f(-0.20, -0.85, 0.0);
    glVertex3f(-0.44, -0.7, 0.0);
    glVertex3f(-0.53,-0.90,0);

    glVertex3f(-0.10, -0.85, 0.0);
    glVertex3f(-0.08, -0.55, 0.0);
    glVertex3f(-0.2, -0.40, 0.0);
    glVertex3f(-0.15,-0.75,0);

    glVertex3f(-0.20, -0.45, 0.0);
    glVertex3f(-0.08, -0.55, 0.0);
    glVertex3f(-0.22, -0.60, 0.0);
    glVertex3f(-0.09,-0.5,0);

    glVertex3f(-0.50, -0.45, 0.0);
    glVertex3f(-0.48, -0.65, 0.0);
    glVertex3f(-0.25, -0.60, 0.0);
    glVertex3f(-0.55,-0.55,0);

    glVertex3f(-0.30, -0.20, 0.0);
    glVertex3f(-0.28, -0.14, 0.0);
    glVertex3f(-0.35, -0.06, 0.0);
    glVertex3f(-0.25,-0.20,0.0);

    glVertex3f(-0.10, -0.0, 0.0);
    glVertex3f(-0.15, -0.1, 0.0);
    glVertex3f(-0.25, -0.1, 0.0);
    glVertex3f(-0.35,-0.0,0.0);


    glColor3ub(240,230,140);
    //Body

    glVertex3f(-0.0, 0.0, 0.0);

    glColor3ub(245,222,179);

    glVertex3f(-0.0, -1.0, 0.0);
    glVertex3f(-0.6, -1.0, 0.0);

    glColor3ub(176,196,222);
    glVertex3f(-0.6,0.0,0);






    //Eye
    glColor3ub(25,25,112);

    glVertex3f(0.2,0.7,0);
    glVertex3f(0.0,0.7,0);
    glVertex3f(0.0,0.9,0);
    glVertex3f(0.2,0.9,0);


    glVertex3f(-0.0,0.7,0);
    glVertex3f(-0.0,0.9,0);
    glVertex3f(-0.2,1.1,0);
    glVertex3f(-0.2,0.7,0);
//mouth
    glColor3ub(192,192,192);
    glVertex3f(0.1,0.5,0);
    glVertex3f(0.0,0.5,0);
    glVertex3f(0.1,0.40,0);
    glVertex3f(0.2,0.40,0);

    //Head
    glColor3ub(165,42,42);

    glVertex3f(0.2,0.1,0);
    glVertex3f(-1.0,0.5,0);
    glVertex3f(-1.0,1.2,0);
    glVertex3f(0.2,1.4,0);



    //neck
    glColor3ub(255,215,0);

    glVertex3f(-0.2, 0.0, 0.0);
    glVertex3f(-0.4, 0.0, 0.0);
    glVertex3f(-0.4, 0.5, 0.0);
    glVertex3f(-0.2,0.5,0);

    //Thai
    glVertex3f(-0.2, -1.0, 0.0);
    glVertex3f(-0.4, -1.0, 0.0);
    glVertex3f(-0.4, -1.65, 0.0);
    glVertex3f(-0.2,-1.65,0);
    glEnd();

    glPopMatrix(); //Undo the move to the center of the trapezoid

    glPushMatrix(); //Save the transformations performed thus far
    //glTranslatef(1.0, -1.0, 0.0);
    //glScalef(2.5,2.5,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
    //Leg



    glTranslatef(-0.3, -1.7, 0.0);
    glRotatef(_ang_tri ,0.0, 0.0, 1.0);

    glBegin(GL_POLYGON);

    glColor3ub(0,0,0);

    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();


    glBegin(GL_POLYGON);

    glColor3ub(105,112,142);

    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.3;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();




    glBegin(GL_POLYGON);

    glColor3ub(155,0,0);

    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.45;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();

    glPopMatrix(); //Undo the move to the center of the trapezoid




    glPopMatrix();

    ///hero end

    ///villain start

    glPushMatrix();
    glTranslatef(2.0,01.0, 0.0);
    glScalef(0.7,0.7,0);
    glRotatef(45, 0.0, 0.0, 1.0);

    glPushMatrix(); //Save the current state of transformations

    glTranslatef(-0.1, 0.6, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)


    /// bru

    glColor3ub(105,105,105);
    glBegin(GL_QUADS);

    glVertex3f(-0.20, 01.40, 0.0);
    glVertex3f(-0.10, 01.45, 0.0);
    glVertex3f(0.03,  01.44, 0.0);
    glVertex3f(0.01, 01.42,0);


    glVertex3f(-0.20, 01.40, 0.0);
    glVertex3f(-0.10, 01.45, 0.0);
    glVertex3f(-0.3,  01.44, 0.0);
    glVertex3f(-0.35, 01.32,0);



    //horne
    glColor3ub(255,0,0);



    glVertex3f(-0.4, 02.10, 0.0);
    glVertex3f(-0.12, 01.55, 0.0);
    glVertex3f(-0.3,  01.55, 0.0);
    glVertex3f(-0.4, 02.10,0);


    glVertex3f(0.08, 02.0, 0.0);
    glVertex3f(-0.2, 01.55, 0.0);
    glVertex3f(0.0,  01.55, 0.0);
    glVertex3f(0.08, 02.0,0);


    glVertex3f(-0.2, 02.0, 0.0);
    glVertex3f(-0.2, 01.55, 0.0);
    glVertex3f(0.0,  01.55, 0.0);
    glVertex3f(-0.2, 02.0,0);

    glVertex3f(0.22, 02.0, 0.0);
    glVertex3f(-0.09, 01.55, 0.0);
    glVertex3f(0.1,  01.55, 0.0);
    glVertex3f(0.22, 02.0,0);



    glVertex3f(0.30, 02.0, 0.0);
    glVertex3f(0.25, 01.55, 0.0);
    glVertex3f(0.05,  01.55, 0.0);
    glVertex3f(0.30, 02.0,0);


    glVertex3f(0.50, 02.0, 0.0);
    glVertex3f(0.4, 01.55, 0.0);
    glVertex3f(0.1,  01.55, 0.0);
    glVertex3f(0.50, 02.0,0);


    glVertex3f(0.80, 02.0, 0.0);
    glVertex3f(0.5, 01.55, 0.0);
    glVertex3f(0.3,  01.55, 0.0);
    glVertex3f(0.80, 02.0,0);

///mouth


    glVertex3f(-0.45, 0.95, 0.0);
    glVertex3f(-0.1, 0.8, 0.0);
    glVertex3f(-0.35,  0.85, 0.0);
    glVertex3f(-0.32, 0.90,0);


    glVertex3f(0.45, 01.85, 0.0);
    glVertex3f(0.1, 0.7, 0.0);
    glVertex3f(0.35,  0.7, 0.0);
    glVertex3f(0.32, 01.80,0);

    glColor3ub(105,105,105);

    glVertex3f(0.6, 01.58, 0.0);
    glVertex3f(0.6, 0.75, 0.0);
    glVertex3f(0.35,  0.6, 0.0);
    glVertex3f(0.35, 01.58,0);


    glVertex3f(0.7, 01.40, 0.0);
    glVertex3f(0.7, 0.85, 0.0);
    glVertex3f(0.5,  0.5, 0.0);
    glVertex3f(0.5, 01.58,0);







    glEnd();


    glPopMatrix();


    glPushMatrix(); //Save the current state of transformations
    //hand
    glTranslatef(-0.3, 1.85, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)
    glColor3ub(255,0,0);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();

    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
    //Head
    glTranslatef(0.0, 1.75, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)
    glColor3ub(0,255,0);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/10;
        float r=0.60;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();



    glPopMatrix(); //Undo the move to the center of the triangle


    glPushMatrix(); //Save the current state of transformations
    //hand
    glTranslatef(-0.1, 0.6, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)
    glColor3ub(0,0,205);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.15;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,255,255);

    glVertex3f(0.0,-0.1, 0.0);

    glColor3ub(75,0,130);
    glVertex3f(-0.7, -0.1, 0.0);
    glVertex3f(-0.7,0.1, 0.0);

    glColor3ub(0,255,255);
    glVertex3f(0.0,0.1,0);

    glColor3ub(188,143,143);

    glVertex3f(-0.7, -0.1, 0.0);
    glVertex3f(-0.7,0.1, 0.0);
    glVertex3f(-1.0, 0.3, 0.0);
    glVertex3f(-1.0,-0.3, 0.0);

    /// nick
    glColor3ub(165,42,42);
    glVertex3f(-0.2, 0.6, 0.0);
    glVertex3f(-0.2, 0.4, 0.0);
    glVertex3f(0.40,  0.4, 0.0);
    glVertex3f(0.40, 0.6,0);

    glEnd();


    glPopMatrix();


    glPushMatrix(); //Save the current state of transformations
    //body
    glTranslatef(0.0, 1.2, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)


    glBegin(GL_QUADS);
    glColor3ub(184,134,11);
    glVertex3f(-0.53, -0.2, 0.0);
    glColor3ub(255,215,0);
    glVertex3f(0.53, -0.2, 0.0);
    glVertex3f(0.53,-1.6, 0.0);
    glColor3ub(184,134,11);
    glVertex3f(-0.53,-1.6,0);


    glEnd();


    glPopMatrix(); //Undo the move to the center of the triangle


    glPushMatrix(); //Save the current state of transformations
    //leg
    glTranslatef(-0.40, -0.65, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)

    glColor3ub(65,105,225);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();


    glColor3ub(139,69,19);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.25;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();


    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
    //leg
    glTranslatef(0.4, -0.65, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)


    glColor3ub(65,105,225);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }

    glEnd();




    glColor3ub(139,69,19);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.25;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }

    glEnd();



    glPopMatrix();




    glPopMatrix();

    ///villain end
    ///background
    glPushMatrix();
    glBegin(GL_QUADS);

    glColor3ub(255,250,0);
    glVertex3f(6, 6, 0.0);

    glColor3ub(148,0,211);
    glVertex3f(6, -6, 0.0);
    glVertex3f(-6, -6, 0.0);


    glColor3ub(255,250,0);
    glVertex3f(-6, 6, 0.0);

    glEnd();


    glPopMatrix();



    glutSwapBuffers();
}

void drawScene1()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
    glLoadIdentity(); //Reset the drawing perspective
    glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
    glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units

    ///Healthbarenemy


    glPushMatrix();
    if (colCountL == 0 )
    {
        glTranslatef(1.0, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(0,128,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5 , -0.1);
        glVertex2f(1.5, 0.0);
        glEnd();


    }

    else if (colCountL == 1)
    {
        //yellow
        glTranslatef(1.0, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(255,255,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5-0.6 , -0.1);
        glVertex2f(1.5-0.6, 0.0);
        glEnd();
    }
    else if (colCountL == 2 )
    {
        glTranslatef(1.0, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(255,0,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5-1.2 , -0.1);
        glVertex2f(1.5-1.2, 0.0);
        glEnd();
    }
    else if (colCountL == 0 && xy==1000 )
    {
        glTranslatef(1.0, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(0,128,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5 , -0.1);
        glVertex2f(1.5, 0.0);
        glEnd();


    }

    else if (colCountL == 1&& xy==1000 )
    {
        //yellow
        glTranslatef(1.0, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(255,255,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5-0.6 , -0.1);
        glVertex2f(1.5-0.6, 0.0);
        glEnd();
    }
    else if (colCountL == 2 && xy==1000)
    {
        glTranslatef(1.0, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(255,0,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5-1.2 , -0.1);
        glVertex2f(1.5-1.2, 0.0);
        glEnd();
    }


    glPopMatrix();

///HealthbarHero
    glPushMatrix();

    glPushMatrix();
    glTranslatef(-2.5, 2.58, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(0,128,0);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.05 , 0.0);
    glVertex2f(0.05 , -0.25);
    glVertex2f(0.0, -0.25);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.34, 2.45, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(0,128,0);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.25 , 0.0);
    glVertex2f(-0.25,0.05 );
    glVertex2f(0.0, 0.05);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.7, 2.58, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(0,128,0);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.05 , 0.0);
    glVertex2f(0.05 , -0.25);
    glVertex2f(0.0, -0.25);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.85, 2.45, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(0,128,0);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.25 , 0.0);
    glVertex2f(-0.25,0.05 );
    glVertex2f(0.0, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    if (colCountR == 0 && xy1!=1000)
    {
        glTranslatef(-2.2, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(0,128,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5 , -0.1);
        glVertex2f(1.5, 0.0);
        glEnd();
    }

    else if (colCountR == 1 && xy1!=1000)
    {
        //yellow
        glTranslatef(-2.2, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(255,255,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5-0.6 , -0.1);
        glVertex2f(1.5-0.6, 0.0);
        glEnd();
    }
    else if (colCountR == 2 && xy1!=1000)
    {
        glTranslatef(-2.2, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(255,0,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5-1.2 , -0.1);
        glVertex2f(1.5-1.2, 0.0);
        glEnd();
    }
    else if (colCountR == 0 && xy1==1000)
    {
        glTranslatef(-2.2, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(0,128,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5 , -0.1);
        glVertex2f(1.5, 0.0);
        glEnd();
    }

    else if (colCountR == 1 && xy1==1000)
    {
        //yellow
        glTranslatef(-2.2, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(255,255,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5-0.6 , -0.1);
        glVertex2f(1.5-0.6, 0.0);
        glEnd();
    }
    else if (colCountR == 2 && xy1==1000)
    {
        glTranslatef(-2.2, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(255,0,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5-1.2 , -0.1);
        glVertex2f(1.5-1.2, 0.0);
        glEnd();
    }


    glPopMatrix();

    glPopMatrix();

///start pause
    glPushMatrix();
    glTranslatef(0, p, 0.0);
    glScalef(0.50, 0.50, 0.0);




    glPushMatrix();

    glColor3ub(255,240,245);


    glutSolidTorus(.2,1,100,100);


    glPopMatrix();


    glPushMatrix();
    glBegin(GL_QUADS);

    glColor3ub(220,220,220);


    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(0.35, -0.5, 0.0);
    glVertex3f(0.35, 0.5, 0.0);



    glVertex3f(0.10, 0.5, 0.0);
    glVertex3f(0.10, -0.5, 0.0);
    glVertex3f(0.25, -0.5, 0.0);
    glVertex3f(0.25, 0.5, 0.0);


    glEnd();


    glPopMatrix();


    glPushMatrix();

    glBegin(GL_TRIANGLES);



    glVertex3f(0.08, -0.0, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glVertex3f(-0.5, -0.5, 0.0);

    glEnd();

    glPopMatrix();
    glPopMatrix();
    ///end pause


    ///Chr2
    glPushMatrix();
    glScalef(-1,1,1);
    glScalef(0.25,0.25,0);
    glTranslatef(7.0+ch1,y, 0.0);


    glPushMatrix(); //Save the transformations performed thus far
    //glTranslatef(1.0, -1.0, 0.0);
    //glScalef(2.5,2.5,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
    //hand


    glColor3ub(85,107,47);
    glBegin(GL_QUADS);

    glVertex3f(-0.4, -0.2+yr, 0.0);
    glVertex3f(0.2, -0.2+yr, 0.0);
    glVertex3f(0.2,-0.4+yr, 0.0);
    glVertex3f(-0.4,-0.4+yr,0);


    glVertex3f(-0.4,-0.2+yr, 0.0);
    glVertex3f(-0.4,-0.4+yr,0);
    glVertex3f(-0.8, -0.6+yr, 0.0);
    glVertex3f(-0.8, 0.0+yr, 0.0);

    glVertex3f(-0.8,-0.6+yr, 0.0);
    glVertex3f(-1.0,-0.6+yr,0);
    glVertex3f(-1.0, -0.5+yr, 0.0);
    glVertex3f(-0.8, -0.5+yr, 0.0);

    glVertex3f(-0.8,-0.0+yr, 0.0);
    glVertex3f(-1.0,-0.0+yr,0);
    glVertex3f(-1.0, -0.1+yr, 0.0);
    glVertex3f(-0.8, -0.1+yr, 0.0);

    glEnd();

    glTranslatef(0.3, -0.3, 0.0);

    glColor3ub(72,61,139);
    //HAND

    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.15;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y+yr );
    }
    glEnd();

    glPopMatrix();


    ///Bullet

    glPushMatrix(); //Save the transformations performed thus far
    glTranslatef(x, xy, 0.0);
    glColor3ub(226,104,34);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y+yr);
    }
    glEnd();



    glPopMatrix();

    ///BulletEnd


    glPushMatrix(); //Save the transformations performed thus far
    //glTranslatef(1.0, -1.0, 0.0);
    //glScalef(2.5,2.5,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
    glBegin(GL_QUADS);


    glColor3ub(0,100,0);
    //spot

    glVertex3f(0.60, -0.10+yr, 0.0);
    glVertex3f(0.50, -0.2+yr, 0.0);
    glVertex3f(0.5, -0.4+yr, 0.0);
    glVertex3f(0.55,-0.10+yr,0);


    glVertex3f(0.60, -0.50+yr, 0.0);
    glVertex3f(0.50, -0.4+yr, 0.0);
    glVertex3f(0.5, -0.48+yr, 0.0);
    glVertex3f(0.55,-0.50+yr,0);


    glVertex3f(0.60, -0.80+yr, 0.0);
    glVertex3f(0.50, -0.7+yr, 0.0);
    glVertex3f(0.5, -0.68+yr, 0.0);
    glVertex3f(0.55,-0.80+yr,0);


    glVertex3f(0.40, -0.90+yr, 0.0);
    glVertex3f(0.30, -0.85+yr, 0.0);
    glVertex3f(0.3, -0.7+yr, 0.0);
    glVertex3f(0.35,-0.90+yr,0);

    glVertex3f(0.10, -0.95+yr, 0.0);
    glVertex3f(0.08, -0.75+yr, 0.0);
    glVertex3f(0.2, -0.60+yr, 0.0);
    glVertex3f(0.15,-0.85+yr,0);

    glVertex3f(0.10, -0.45+yr, 0.0);
    glVertex3f(0.08, -0.55+yr, 0.0);
    glVertex3f(0.2, -0.60+yr, 0.0);
    glVertex3f(0.15,-0.5+yr,0);

    glVertex3f(0.30, -0.45+yr, 0.0);
    glVertex3f(0.28, -0.65+yr, 0.0);
    glVertex3f(0.35, -0.60+yr, 0.0);
    glVertex3f(0.25,-0.55+yr,0);

    glVertex3f(0.30, -0.0+yr, 0.0);
    glVertex3f(0.28, -0.1+yr, 0.0);
    glVertex3f(0.35, -0.1+yr, 0.0);
    glVertex3f(0.25,-0.0+yr,0.0);

    glVertex3f(0.0, -0.0+yr, 0.0);
    glVertex3f(0.08, -0.1+yr, 0.0);
    glVertex3f(0.05, -0.1+yr, 0.0);
    glVertex3f(0.05,-0.0+yr,0.0);


    glColor3ub(160,82,45);



    glVertex3f(0.55, -0.10+yr, 0.0);
    glVertex3f(0.50, -0.2+yr, 0.0);
    glVertex3f(0.56, -0.4+yr, 0.0);
    glVertex3f(0.50,-0.10+yr,0);


    glVertex3f(0.4, -0.50+yr, 0.0);
    glVertex3f(0.40, -0.4+yr, 0.0);
    glVertex3f(0.50, -0.48+yr, 0.0);
    glVertex3f(0.45,-0.50+yr,0);


    glVertex3f(0.10, -0.80+yr, 0.0);
    glVertex3f(0.20, -0.7+yr, 0.0);
    glVertex3f(0.1, -0.5+yr, 0.0);
    glVertex3f(0.15,-0.80+yr,0);


    glVertex3f(0.50, -0.90+yr, 0.0);
    glVertex3f(0.20, -0.85+yr, 0.0);
    glVertex3f(0.44, -0.7+yr, 0.0);
    glVertex3f(0.53,-0.90+yr,0);

    glVertex3f(0.10, -0.85+yr, 0.0);
    glVertex3f(0.08, -0.55+yr, 0.0);
    glVertex3f(0.2, -0.40+yr, 0.0);
    glVertex3f(0.15,-0.75+yr,0);

    glVertex3f(0.20, -0.45+yr, 0.0);
    glVertex3f(0.08, -0.55+yr, 0.0);
    glVertex3f(0.22, -0.60+yr, 0.0);
    glVertex3f(0.09,-0.5+yr,0);

    glVertex3f(0.50, -0.45+yr, 0.0);
    glVertex3f(0.48, -0.65+yr, 0.0);
    glVertex3f(0.25, -0.60+yr, 0.0);
    glVertex3f(0.55,-0.55+yr,0);

    glVertex3f(0.30, -0.20+yr, 0.0);
    glVertex3f(0.28, -0.14+yr, 0.0);
    glVertex3f(0.35, -0.06+yr, 0.0);
    glVertex3f(0.25,-0.20+yr,0.0);

    glVertex3f(0.10, -0.0+yr, 0.0);
    glVertex3f(0.15, -0.1+yr, 0.0);
    glVertex3f(0.25, -0.1+yr, 0.0);
    glVertex3f(0.35,-0.0+yr,0.0);


    glColor3ub(240,230,140);
    //Body

    glVertex3f(0.0, 0.0+yr, 0.0);

    glColor3ub(245,222,179);

    glVertex3f(0.0, -1.0+yr, 0.0);
    glVertex3f(0.6, -1.0+yr, 0.0);

    glColor3ub(176,196,222);
    glVertex3f(0.6,0.0+yr,0);






    //Eye
    glColor3ub(25,25,112);

    glVertex3f(-0.2,0.7+yr,0);
    glVertex3f(-0.0,0.7+yr,0);
    glVertex3f(-0.0,0.9+yr,0);
    glVertex3f(-0.2,0.9+yr,0);


    glVertex3f(0.0,0.7+yr,0);
    glVertex3f(0.0,0.9+yr,0);
    glVertex3f(0.2,1.1+yr,0);
    glVertex3f(0.2,0.7+yr,0);
//mouth
    glColor3ub(192,192+yr,192);
    glVertex3f(-0.1,0.5+yr,0);
    glVertex3f(-0.0,0.5+yr,0);
    glVertex3f(-0.1,0.40+yr,0);
    glVertex3f(-0.2,0.40+yr,0);

    //Head
    glColor3ub(165,42,42);

    glVertex3f(-0.2,0.1+yr,0);
    glVertex3f(1.0,0.5+yr,0);
    glVertex3f(1.0,1.2+yr,0);
    glVertex3f(-0.2,1.4+yr,0);



    //neck
    glColor3ub(255,215,0);

    glVertex3f(0.2, 0.0+yr, 0.0);
    glVertex3f(0.4, 0.0+yr, 0.0);
    glVertex3f(0.4, 0.5+yr, 0.0);
    glVertex3f(0.2,0.5+yr,0);

    //Thai
    glVertex3f(0.2, -1.0+yr, 0.0);
    glVertex3f(0.4, -1.0+yr, 0.0);
    glVertex3f(0.4, -1.65+yr, 0.0);
    glVertex3f(0.2,-1.65+yr,0);
    glEnd();

    glPopMatrix(); //Undo the move to the center of the trapezoid

    glPushMatrix(); //Save the transformations performed thus far
    //glTranslatef(1.0, -1.0, 0.0);
    //glScalef(2.5,2.5,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
    //Leg



    glTranslatef(0.3, -1.7, 0.0);
    //glRotatef(_ang_tri ,0.0, 0.0, 1.0);

    glBegin(GL_POLYGON);

    glColor3ub(0,0,0);

    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y+yr);
    }
    glEnd();


    glBegin(GL_POLYGON);

    glColor3ub(105,112,142);

    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.3;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y+yr);
    }
    glEnd();




    glBegin(GL_POLYGON);

    glColor3ub(155,0,0);

    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.45;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y+yr);
    }
    glEnd();

    glPopMatrix(); //Undo the move to the center of the trapezoid
    glPopMatrix();


    ///Character
    glPushMatrix();
    glScalef(0.3,0.3,0);
    glTranslatef(6.0+ch, -7.0, 0.0);


    glPushMatrix(); //Save the current state of transformations

    glTranslatef(-0.1, 0.6, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)


    /// bru

    glColor3ub(105,105,105);
    glBegin(GL_QUADS);

    glVertex3f(-0.20, 01.40, 0.0);
    glVertex3f(-0.10, 01.45, 0.0);
    glVertex3f(0.03,  01.44, 0.0);
    glVertex3f(0.01, 01.42,0);


    glVertex3f(-0.20, 01.40, 0.0);
    glVertex3f(-0.10, 01.45, 0.0);
    glVertex3f(-0.3,  01.44, 0.0);
    glVertex3f(-0.35, 01.32,0);



    //horne
    glColor3ub(255,0,0);



    glVertex3f(-0.4, 02.10, 0.0);
    glVertex3f(-0.12, 01.55, 0.0);
    glVertex3f(-0.3,  01.55, 0.0);
    glVertex3f(-0.4, 02.10,0);


    glVertex3f(0.08, 02.0, 0.0);
    glVertex3f(-0.2, 01.55, 0.0);
    glVertex3f(0.0,  01.55, 0.0);
    glVertex3f(0.08, 02.0,0);


    glVertex3f(-0.2, 02.0, 0.0);
    glVertex3f(-0.2, 01.55, 0.0);
    glVertex3f(0.0,  01.55, 0.0);
    glVertex3f(-0.2, 02.0,0);

    glVertex3f(0.22, 02.0, 0.0);
    glVertex3f(-0.09, 01.55, 0.0);
    glVertex3f(0.1,  01.55, 0.0);
    glVertex3f(0.22, 02.0,0);



    glVertex3f(0.30, 02.0, 0.0);
    glVertex3f(0.25, 01.55, 0.0);
    glVertex3f(0.05,  01.55, 0.0);
    glVertex3f(0.30, 02.0,0);


    glVertex3f(0.50, 02.0, 0.0);
    glVertex3f(0.4, 01.55, 0.0);
    glVertex3f(0.1,  01.55, 0.0);
    glVertex3f(0.50, 02.0,0);


    glVertex3f(0.80, 02.0, 0.0);
    glVertex3f(0.5, 01.55, 0.0);
    glVertex3f(0.3,  01.55, 0.0);
    glVertex3f(0.80, 02.0,0);

///mouth


    glVertex3f(-0.45, 0.95, 0.0);
    glVertex3f(-0.1, 0.8, 0.0);
    glVertex3f(-0.35,  0.85, 0.0);
    glVertex3f(-0.32, 0.90,0);


    glVertex3f(0.45, 01.85, 0.0);
    glVertex3f(0.1, 0.7, 0.0);
    glVertex3f(0.35,  0.7, 0.0);
    glVertex3f(0.32, 01.80,0);

    glColor3ub(105,105,105);

    glVertex3f(0.6, 01.58, 0.0);
    glVertex3f(0.6, 0.75, 0.0);
    glVertex3f(0.35,  0.6, 0.0);
    glVertex3f(0.35, 01.58,0);


    glVertex3f(0.7, 01.40, 0.0);
    glVertex3f(0.7, 0.85, 0.0);
    glVertex3f(0.5,  0.5, 0.0);
    glVertex3f(0.5, 01.58,0);







    glEnd();


    glPopMatrix();


    glPushMatrix(); //Save the current state of transformations
    //hand
    glTranslatef(-0.3, 1.85, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)
    glColor3ub(255,0,0);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();

    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
    //Head
    glTranslatef(0.0, 1.75, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)
    glColor3ub(173,255,47);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/10;
        float r=0.60;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();



    glPopMatrix(); //Undo the move to the center of the triangle


    glPushMatrix(); //Save the current state of transformations
    //hand
    glTranslatef(-0.1, 0.6, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)
    glColor3ub(0,0,205);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.15;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,255,255);

    glVertex3f(0.0,-0.1, 0.0);

    glColor3ub(75,0,130);
    glVertex3f(-0.7, -0.1, 0.0);
    glVertex3f(-0.7,0.1, 0.0);

    glColor3ub(0,255,255);
    glVertex3f(0.0,0.1,0);

    glColor3ub(188,143,143);

    glVertex3f(-0.7, -0.1, 0.0);
    glVertex3f(-0.7,0.1, 0.0);
    glVertex3f(-1.0, 0.3, 0.0);
    glVertex3f(-1.0,-0.3, 0.0);

    /// nick
    glColor3ub(165,42,42);
    glVertex3f(-0.2, 0.6, 0.0);
    glVertex3f(-0.2, 0.4, 0.0);
    glVertex3f(0.40,  0.4, 0.0);
    glVertex3f(0.40, 0.6,0);

    glEnd();


    glPopMatrix();


    ///Bullet

    glPushMatrix(); //Save the transformations performed thus far
    glTranslatef(x1, xy1, 0.0);
    glColor3ub(226,104,34);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.17;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();


    glPopMatrix();

    ///BulletEnd


    glPushMatrix(); //Save the current state of transformations
    //body
    glTranslatef(0.0, 1.2, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)


    glBegin(GL_QUADS);
    glColor3ub(184,134,11);
    glVertex3f(-0.53, -0.2, 0.0);
    glColor3ub(255,215,0);
    glVertex3f(0.53, -0.2, 0.0);
    glVertex3f(0.53,-1.6, 0.0);
    glColor3ub(184,134,11);
    glVertex3f(-0.53,-1.6,0);


    glEnd();


    glPopMatrix(); //Undo the move to the center of the triangle


    glPushMatrix(); //Save the current state of transformations
    //leg
    glTranslatef(-0.40, -0.65, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)

    glColor3ub(30,144,255);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();


    glColor3ub(139,69,19);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.25;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();


    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
    //leg
    glTranslatef(0.4, -0.65, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)


    glColor3ub(30,144,255);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }

    glEnd();




    glColor3ub(139,69,19);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.25;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }

    glEnd();



    glPopMatrix();
    glPopMatrix();

///tree start
    glPushMatrix();


    glBegin(GL_TRIANGLES);
    glColor3ub(0,255,0);

    glVertex3f(-2.1, -01.2, 0.0);
    glVertex3f(-2.05, -0.8, 0.0);
    glVertex3f(-2.0, -01.2, 0.0);


    glVertex3f(-1.1, -01.2, 0.0);
    glVertex3f(-1.05, -0.8, 0.0);
    glVertex3f(-1.0, -01.2, 0.0);

    glVertex3f(-0.04, -01.2, 0.0);
    glVertex3f(0.03, -0.8, 0.0);
    glVertex3f(0.07, -01.2, 0.0);


    glVertex3f(1.3, -01.2, 0.0);
    glVertex3f(1.25, -0.8, 0.0);
    glVertex3f(1.2, -01.2, 0.0);


    glVertex3f(2.3, -01.2, 0.0);
    glVertex3f(2.25, -0.8, 0.0);
    glVertex3f(2.20, -01.2, 0.0);


    glEnd();


    glPopMatrix();


///end tree

    ///tree root start
    glPushMatrix(); //Save the current state of transformations
    glTranslatef(-0.15, -01.35, 0.0); //Move to the center of the pentagon

    glScalef(0.50, 0.50, 0.0); //Scale by 0.7 in the x, y, and z directions

    glBegin(GL_QUADS);
    glColor3ub(0,100,0);

    glVertex3f(0.3, 0.5, 0.0);
    glVertex3f(0.3, 0.15, 0.0);
    glVertex3f(0.35, 0.15, 0.0);
    glVertex3f(0.35, 0.5, 0.0);

    glVertex3f(-1.8, 0.5, 0.0);
    glVertex3f(-1.8, 0.15, 0.0);
    glVertex3f(-1.75, 0.15, 0.0);
    glVertex3f(-1.75, 0.5, 0.0);


    glVertex3f(-3.8, 0.5, 0.0);
    glVertex3f(-3.8, 0.15, 0.0);
    glVertex3f(-3.75, 0.15, 0.0);
    glVertex3f(-3.75, 0.5, 0.0);


    glVertex3f(2.8, 0.5, 0.0);
    glVertex3f(2.8, 0.15, 0.0);
    glVertex3f(2.75, 0.15, 0.0);
    glVertex3f(2.75, 0.5, 0.0);


    glVertex3f(4.8, 0.5, 0.0);
    glVertex3f(4.8, 0.15, 0.0);
    glVertex3f(4.75, 0.15, 0.0);
    glVertex3f(4.75, 0.5, 0.0);

    glEnd();
    glPopMatrix();

    ///tree root end




    ///road  cross
    glPushMatrix(); //Save the current state of transformations
    glTranslatef(0.0, -2.60, 0.0); //Move to the center of the pentagon
    glScalef(0.50, 0.50, 0.0); //Scale by 0.7 in the x, y, and z directions

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    //Trapezoid
    glVertex3f(5.8, 0.30, 0.0);
    glVertex3f(5.8, 0.10, 0.0);
    glVertex3f(5.7, 0.10, 0.0);
    glVertex3f(5.7, 0.30, 0.0);

    glVertex3f(4.8, 0.30, 0.0);
    glVertex3f(4.8, 0.1, 0.0);
    glVertex3f(4.7, 0.1, 0.0);
    glVertex3f(4.7, 0.3, 0.0);


    glVertex3f(3.8, 0.3, 0.0);
    glVertex3f(3.8, 0.1, 0.0);
    glVertex3f(3.7, 0.1, 0.0);
    glVertex3f(3.7, 0.3, 0.0);

    glVertex3f(2.8, 0.3, 0.0);
    glVertex3f(2.8, 0.1, 0.0);
    glVertex3f(2.7, 0.1, 0.0);
    glVertex3f(2.7, 0.3, 0.0);


    glVertex3f(1.8, 0.3, 0.0);
    glVertex3f(1.8, 0.1, 0.0);
    glVertex3f(1.7, 0.1, 0.0);
    glVertex3f(1.7, 0.3, 0.0);

    glVertex3f(0.8, 0.3, 0.0);
    glVertex3f(0.8, 0.1, 0.0);
    glVertex3f(0.7, 0.1, 0.0);
    glVertex3f(0.7, 0.3, 0.0);

    glVertex3f(0.0, 0.3, 0.0);
    glVertex3f(0.0, 0.1, 0.0);
    glVertex3f(0.1, 0.1, 0.0);
    glVertex3f(0.1, 0.3, 0.0);

///

    glVertex3f(-0.8, 0.3, 0.0);
    glVertex3f(-0.8, 0.1, 0.0);
    glVertex3f(-0.7, 0.1, 0.0);
    glVertex3f(-0.7, 0.3, 0.0);

    glVertex3f(-1.8, 0.3, 0.0);
    glVertex3f(-1.8, 0.1, 0.0);
    glVertex3f(-1.7, 0.1, 0.0);
    glVertex3f(-1.7, 0.3, 0.0);


    glVertex3f(-2.8, 0.3, 0.0);
    glVertex3f(-2.8, 0.1, 0.0);
    glVertex3f(-2.7, 0.1, 0.0);
    glVertex3f(-2.7, 0.3, 0.0);

    glVertex3f(-3.8, 0.3, 0.0);
    glVertex3f(-3.8, 0.1, 0.0);
    glVertex3f(-3.7, 0.1, 0.0);
    glVertex3f(-3.7, 0.3, 0.0);


    glVertex3f(-4.8, 0.3, 0.0);
    glVertex3f(-4.8, 0.1, 0.0);
    glVertex3f(-4.7, 0.1, 0.0);
    glVertex3f(-4.7, 0.3, 0.0);


    glVertex3f(-5.8, 0.3, 0.0);
    glVertex3f(-5.8, 0.1, 0.0);
    glVertex3f(-5.7, 0.1, 0.0);
    glVertex3f(-5.7, 0.3, 0.0);
///end

    glEnd();
    glPopMatrix();




    ///lemp post

    glPushMatrix();

    glBegin(GL_QUADS);

    glColor3ub(255,255,255);///light


    glVertex3f(2.60, -0.70, 0.0);
    glVertex3f(2.60, -0.75, 0.0);
    glVertex3f(2.68, -0.70, 0.0);
    glVertex3f(2.68, -0.60, 0.0);


    glVertex3f(1.6, -0.70, 0.0);
    glVertex3f(1.6, -0.75, 0.0);
    glVertex3f(1.68, -0.70, 0.0);
    glVertex3f(1.68, -0.60, 0.0);

    glVertex3f(0.60, -0.70, 0.0);
    glVertex3f(0.60, -0.75, 0.0);
    glVertex3f(0.68, -0.70, 0.0);
    glVertex3f(0.68, -0.60, 0.0);

    glVertex3f(-0.3, -0.60, 0.0);
    glVertex3f(-0.3, -0.70, 0.0);
    glVertex3f(-0.38, -0.75, 0.0);
    glVertex3f(-0.38, -0.70, 0.0);

    glVertex3f(-01.3, -0.60, 0.0);
    glVertex3f(-01.3, -0.70, 0.0);
    glVertex3f(-1.38, -0.75, 0.0);
    glVertex3f(-1.38, -0.70, 0.0);


    glVertex3f(-02.3, -0.60, 0.0);
    glVertex3f(-02.3, -0.70, 0.0);
    glVertex3f(-2.38, -0.75, 0.0);
    glVertex3f(-2.38, -0.70, 0.0);



    glColor3ub(160,82,45);

    glVertex3f(-02.47, -0.60, 0.0);
    glVertex3f(-02.47, -01.3, 0.0);
    glVertex3f(-2.5, -01.3, 0.0);
    glVertex3f(-2.5, -0.60, 0.0);


    glVertex3f(-01.47, -0.60, 0.0);
    glVertex3f(-01.47, -01.3, 0.0);
    glVertex3f(-1.5, -01.3, 0.0);
    glVertex3f(-1.5, -0.60, 0.0);


    glVertex3f(-0.47, -0.60, 0.0);
    glVertex3f(-0.47, -01.3, 0.0);
    glVertex3f(-0.5, -01.3, 0.0);
    glVertex3f(-0.5, -0.60, 0.0);


    glVertex3f(0.47, -0.60, 0.0);
    glVertex3f(0.47, -01.3, 0.0);
    glVertex3f(0.5, -01.3, 0.0);
    glVertex3f(0.5, -0.60, 0.0);


    glVertex3f(1.47, -0.60, 0.0);
    glVertex3f(1.47, -01.3, 0.0);
    glVertex3f(1.5, -01.3, 0.0);
    glVertex3f(1.5, -0.60, 0.0);



    glVertex3f(2.47, -0.60, 0.0);
    glVertex3f(2.47, -01.3, 0.0);
    glVertex3f(2.5, -01.3, 0.0);
    glVertex3f(2.5, -0.60, 0.0);


    ///

    glVertex3f(2.5, -0.70, 0.0);
    glVertex3f(2.5, -0.75, 0.0);
    glVertex3f(2.7, -0.70, 0.0);
    glVertex3f(2.7, -0.60, 0.0);

    glVertex3f(1.5, -0.70, 0.0);
    glVertex3f(1.5, -0.75, 0.0);
    glVertex3f(1.7, -0.70, 0.0);
    glVertex3f(1.7, -0.60, 0.0);

    glVertex3f(0.5, -0.70, 0.0);
    glVertex3f(0.5, -0.75, 0.0);
    glVertex3f(0.7, -0.70, 0.0);
    glVertex3f(0.7, -0.60, 0.0);

    glVertex3f(-0.5, -0.70, 0.0);
    glVertex3f(-0.5, -0.75, 0.0);
    glVertex3f(-0.3, -0.70, 0.0);
    glVertex3f(-0.3, -0.60, 0.0);

    glVertex3f(-01.5, -0.70, 0.0);
    glVertex3f(-01.5, -0.75, 0.0);
    glVertex3f(-1.3, -0.70, 0.0);
    glVertex3f(-1.3, -0.60, 0.0);


    glVertex3f(-02.5, -0.70, 0.0);
    glVertex3f(-02.5, -0.75, 0.0);
    glVertex3f(-2.3, -0.70, 0.0);
    glVertex3f(-2.3, -0.60, 0.0);


    glEnd();

    glPopMatrix();



///end lamp post




    ///picture
///stars
    glPushMatrix(); //Save the transformations performed thus far
    glScalef(0.50,0.50,0); //Move to the center of the trapezoid

    glBegin(GL_TRIANGLES);

    glColor3ub(135,205,250);
///star +1
    glVertex3f(-4.25, 4.50, 0.0);
    glVertex3f(-4.30, 4.60, 0.0);
    glVertex3f(-4.35, 4.50, 0.0);

    glVertex3f(-4.25, 4.55, 0.0);
    glVertex3f(-4.30, 4.45, 0.0);
    glVertex3f(-4.35, 4.55, 0.0);

///star -1

    glVertex3f(-5.25, 3.50, 0.0);
    glVertex3f(-5.30, 3.60, 0.0);
    glVertex3f(-5.35, 3.50, 0.0);

    glVertex3f(-5.25, 3.55, 0.0);
    glVertex3f(-5.30, 3.45, 0.0);
    glVertex3f(-5.35, 3.55, 0.0);


    glVertex3f(-5.25, 5.50, 0.0);
    glVertex3f(-5.30, 5.60, 0.0);
    glVertex3f(-5.35, 5.50, 0.0);

    glVertex3f(-5.25, 5.55, 0.0);
    glVertex3f(-5.30, 5.45, 0.0);
    glVertex3f(-5.35, 5.55, 0.0);


    glVertex3f(-0.25, 5.50, 0.0);
    glVertex3f(-0.30, 5.60, 0.0);
    glVertex3f(-0.35, 5.50, 0.0);

    glVertex3f(-0.25, 5.55, 0.0);
    glVertex3f(-0.30, 5.45, 0.0);
    glVertex3f(-0.35, 5.55, 0.0);

    glVertex3f(1.25, 5.0, 0.0);
    glVertex3f(1.30, 5.10, 0.0);
    glVertex3f(1.35, 5.0, 0.0);

    glVertex3f(1.25, 5.05, 0.0);
    glVertex3f(1.30, 4.95, 0.0);
    glVertex3f(1.35, 5.05, 0.0);

    glVertex3f(0.25, 4.50, 0.0);
    glVertex3f(0.30, 4.60, 0.0);
    glVertex3f(0.35, 4.50, 0.0);

    glVertex3f(0.25, 4.55, 0.0);
    glVertex3f(0.30, 4.45, 0.0);
    glVertex3f(0.35, 4.55, 0.0);



    glVertex3f(2.25, 4.50, 0.0);
    glVertex3f(2.30, 4.60, 0.0);
    glVertex3f(2.35, 4.50, 0.0);

    glVertex3f(2.25, 4.55, 0.0);
    glVertex3f(2.30, 4.45, 0.0);
    glVertex3f(2.35, 4.55, 0.0);

    glVertex3f(3.25, 4.60, 0.0);
    glVertex3f(3.30, 4.70, 0.0);
    glVertex3f(3.35, 4.60, 0.0);

    glVertex3f(3.25, 4.65, 0.0);
    glVertex3f(3.30, 4.55, 0.0);
    glVertex3f(3.35, 4.65, 0.0);


    glVertex3f(3.25, 5.50, 0.0);
    glVertex3f(3.30, 5.60, 0.0);
    glVertex3f(3.35, 5.50, 0.0);

    glVertex3f(3.25, 5.55, 0.0);
    glVertex3f(3.30, 5.45, 0.0);
    glVertex3f(3.35, 5.55, 0.0);


    ////////////////
    glVertex3f(-1.25, 5.50, 0.0);
    glVertex3f(-1.30, 5.60, 0.0);
    glVertex3f(-1.35, 5.50, 0.0);

    glVertex3f(-1.25, 5.55, 0.0);
    glVertex3f(-1.30, 5.45, 0.0);
    glVertex3f(-1.35, 5.55, 0.0);

    glVertex3f(-2.25, 4.50, 0.0);
    glVertex3f(-2.30, 4.60, 0.0);
    glVertex3f(-2.35, 4.50, 0.0);

    glVertex3f(-2.25, 4.55, 0.0);
    glVertex3f(-2.30, 4.45, 0.0);
    glVertex3f(-2.35, 4.55, 0.0);



    glVertex3f(-3.25, 4.70, 0.0);
    glVertex3f(-3.30, 4.80, 0.0);
    glVertex3f(-3.35, 4.70, 0.0);

    glVertex3f(-3.25, 4.75, 0.0);
    glVertex3f(-3.30, 4.65, 0.0);
    glVertex3f(-3.35, 4.75, 0.0);

    glVertex3f(-5.25, 3.50, 0.0);
    glVertex3f(-5.30, 3.60, 0.0);
    glVertex3f(-5.35, 3.50, 0.0);

    glVertex3f(-5.25, 3.55, 0.0);
    glVertex3f(-5.30, 3.45, 0.0);
    glVertex3f(-5.35, 3.55, 0.0);


    glEnd();

    glPopMatrix();
///star end

    glPushMatrix(); //Save the transformations performed thus far
    glTranslatef(-2.4, 0.4, 0.0);
    glScalef(1.0,0.90,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis

    glBegin(GL_TRIANGLES);



    ///1st building

    glColor3ub(139,69,19);
    glVertex3f(0.35, -0.5, 0.0);
    glVertex3f(-0.45, -0.5, 0.0);

    glColor3ub(255,250,250);
    glVertex3f(-0.09, 0.25, 0.0);


    glColor3ub(19,69,19);
    glVertex3f(0.4, -0.5, 0.0);
    glVertex3f(-0.5, -0.5, 0.0);

    glColor3ub(255,20,20);
    glVertex3f(-0.09, 0.3, 0.0);

    ///4th building
    glColor3ub(255,255,0);

    glVertex3f(1.62, 0.20, 0.0);
    glVertex3f(1.67, 0.60, 0.0);
    glVertex3f(1.72, 0.20, 0.0);

    glVertex3f(2.98, 0.20, 0.0);
    glVertex3f(2.93, 0.60, 0.0);
    glVertex3f(2.88, 0.20, 0.0);


    glVertex3f(2.25, 0.09, 0.0);
    glVertex3f(2.30, 0.50, 0.0);
    glVertex3f(2.35, 0.09, 0.0);





    glEnd();


    glPopMatrix(); //Undo the move to the center of the trapezoid

    glPopMatrix(); //Undo the move to the center of the trapezoid






///foot ware

    glPushMatrix(); //Save the current state of transformations
    glTranslatef(0.0, -1.35, 0.0); //Move to the center of the pentagon
    glScalef(0.50, 0.20, 0.0); //Scale by 0.7 in the x, y, and z directions

    glBegin(GL_QUADS);


    glColor3ub(205,133,63);///road hight line

    glVertex3f(5.75, 0.25, 0.0);
    glVertex3f(6.0, -0.12, 0.0);
    glVertex3f(-6.0, -0.12, 0.0);
    glVertex3f(-5.75, 0.25, 0.0);

    glColor3ub(188,143,143);
    ///up road
    glVertex3f(6.0, 01.25, 0.0);

    glColor3ub(200,200,200);
    glVertex3f(6.0, -0.12, 0.0);
    glVertex3f(-6.0, -0.12, 0.0);

    glColor3ub(188,143,143);
    glVertex3f(-6.0, 01.25, 0.0);

    glColor3ub(205,133,63);///road hight

    glVertex3f(6.0, -5.50, 0.0);
    glVertex3f(5.80, -6.10, 0.0);
    glVertex3f(-5.80, -6.10, 0.0);
    glVertex3f(-6.0, -5.50, 0.0);


///bottom

    glColor3ub(50,205,50);
    glVertex3f(6.0, -8.0, 0.0);

    glColor3ub(255,215,0);
    glVertex3f(6.0, -5.50, 0.0);

    glColor3ub(50,205,50);
    glVertex3f(-6.0, -5.50, 0.0);
    glVertex3f(-6.0, -8.0, 0.0);


    ///1st building

    glColor3ub(245,222,179);
    ///door

    glVertex3f(-4.70, 4.50, 0.0);
    glVertex3f(-4.70, 1.50, 0.0);
    glVertex3f(-5.10, 1.50, 0.0);
    glVertex3f(-5.10, 4.50, 0.0);

    glColor3ub(218,165,32);///base

    glVertex3f(-5.90, 1.50, 0.0);
    glVertex3f(-5.90, 1.20, 0.0);
    glVertex3f(-4.0, 1.20, 0.0);
    glVertex3f(-4.0, 1.50, 0.0);
///windows
    glColor3ub(250,235,215);

    glVertex3f(-5.60, 5.50, 0.0);
    glVertex3f(-5.60, 3.50, 0.0);
    glVertex3f(-5.20, 3.50, 0.0);
    glVertex3f(-5.20, 5.50, 0.0);

    glVertex3f(-4.60, 5.50, 0.0);
    glVertex3f(-4.60, 3.50, 0.0);
    glVertex3f(-4.20, 3.50, 0.0);
    glVertex3f(-4.20, 5.50, 0.0);

    glColor3ub(165,42,42);///body


    glVertex3f(-5.50, 9.50, 0.0);
    glVertex3f(-5.50, 7.50, 0.0);
    glVertex3f(-5.35, 7.50, 0.0);
    glVertex3f(-5.35, 9.50, 0.0);

    glColor3ub(139,69,19);

    glVertex3f(-5.55, 10.50, 0.0);
    glVertex3f(-5.55, 9.50, 0.0);
    glVertex3f(-5.30, 9.50, 0.0);
    glVertex3f(-5.30, 10.50, 0.0);


    glColor3ub(244,164,96);


    glVertex3f(-5.70, 6.50, 0.0);
    glVertex3f(-5.70, 1.25, 0.0);
    glVertex3f(-4.10, 1.25, 0.0);
    glVertex3f(-4.10, 6.50, 0.0);

///2nd building

    glColor3ub(255,255,224);

    glVertex3f(-3.80, 3.0, 0.0);
    glVertex3f(-3.80, 2.0, 0.0);
    glVertex3f(-3.60, 2.0, 0.0);
    glVertex3f(-3.60, 3.0, 0.0);

    glVertex3f(-3.80, 6.0, 0.0);
    glVertex3f(-3.80, 5.0, 0.0);
    glVertex3f(-3.60, 5.0, 0.0);
    glVertex3f(-3.60, 6.0, 0.0);

    glVertex3f(-3.20, 3.0, 0.0);
    glVertex3f(-3.20, 2.0, 0.0);
    glVertex3f(-3.0, 2.0, 0.0);
    glVertex3f(-3.0, 3.0, 0.0);

    glVertex3f(-3.20, 5.0, 0.0);
    glVertex3f(-3.20, 4.0, 0.0);
    glVertex3f(-3.0, 4.0, 0.0);
    glVertex3f(-3.0, 5.0, 0.0);

    glVertex3f(-3.20, 8.0, 0.0);
    glVertex3f(-3.20, 7.0, 0.0);
    glVertex3f(-3.0, 7.0, 0.0);
    glVertex3f(-3.0, 8.0, 0.0);

    glColor3ub(210,105,30);///base

    glVertex3f(-4.0, 1.50, 0.0);
    glVertex3f(-4.0, 1.20, 0.0);
    glVertex3f(-2.78, 1.20, 0.0);
    glVertex3f(-2.78, 1.50, 0.0);

    glColor3ub(240,128,128);

    glVertex3f(-4.0, 9.50, 0.0);
    glVertex3f(-4.0, 1.20, 0.0);
    glVertex3f(-2.80, 1.20, 0.0);
    glVertex3f(-2.80, 9.50, 0.0);



///3rd building

    glColor3ub(176,196,222);///base

    glVertex3f(-2.78, 1.50, 0.0);
    glVertex3f(-2.78, 1.20, 0.0);
    glVertex3f(-1.7, 1.20, 0.0);
    glVertex3f(-1.7, 1.50, 0.0);

    glColor3ub(255,255,255);


    glVertex3f(-2.50, 9.50, 0.0);
    glVertex3f(-2.50, 2.20, 0.0);
    glVertex3f(-2.40, 2.20, 0.0);
    glVertex3f(-2.40, 9.50, 0.0);

    glVertex3f(-2.0, 9.50, 0.0);
    glVertex3f(-2.0, 2.20, 0.0);
    glVertex3f(-2.10, 2.20, 0.0);
    glVertex3f(-2.10, 9.50, 0.0);

    glColor3ub(255,127,80);

    glVertex3f(-2.70, 11.50, 0.0);
    glVertex3f(-2.70, 1.20, 0.0);
    glVertex3f(-1.80, 1.20, 0.0);
    glVertex3f(-1.80, 11.50, 0.0);

    glVertex3f(-2.60, 12.50, 0.0);
    glVertex3f(-2.60, 11.50, 0.0);
    glVertex3f(-1.90, 11.50, 0.0);
    glVertex3f(-1.90, 12.50, 0.0);

    glVertex3f(-2.50, 13.0, 0.0);
    glVertex3f(-2.50, 12.50, 0.0);
    glVertex3f(-2.0, 12.50, 0.0);
    glVertex3f(-2.0, 13.0, 0.0);

    glVertex3f(-2.35, 14.0, 0.0);
    glVertex3f(-2.35, 13.0, 0.0);
    glVertex3f(-2.1, 13.0, 0.0);
    glVertex3f(-2.1, 14.50, 0.0);


    ///4th building
///basement
    glColor3ub(255,165,0);


    glVertex3f(-1.10, 6.9, 0.0);
    glVertex3f(-1.10, 6.50, 0.0);
    glVertex3f(0.70, 6.50, 0.0);
    glVertex3f(0.70, 6.90, 0.0);

    glVertex3f(-1.70, 1.50, 0.0);
    glVertex3f(-1.70, 1.20, 0.0);
    glVertex3f(1.25, 1.20, 0.0);
    glVertex3f(1.25, 1.50, 0.0);


    glColor3ub(47,79,79);

    ///upper window
    glVertex3f(-0.7, 6.0, 0.0);
    glVertex3f(-0.7, 4.50, 0.0);
    glVertex3f(-1.05, 4.50, 0.0);
    glVertex3f(-1.05, 6.0, 0.0);

    glVertex3f(0.25, 6.0, 0.0);
    glVertex3f(0.25, 4.50, 0.0);
    glVertex3f(0.6, 4.50, 0.0);
    glVertex3f(0.6, 6.0, 0.0);

    ///main gate
    glVertex3f(-0.37, 3.60, 0.0);
    glVertex3f(-0.37, 1.20, 0.0);
    glVertex3f(-0.08, 1.20, 0.0);
    glVertex3f(-0.08, 3.60, 0.0);



    glColor3ub(255,140,0);
    glVertex3f(-0.550, 5.40, 0.0);
    glVertex3f(-0.550, 1.20, 0.0);
    glVertex3f(0.10, 1.20, 0.0);
    glVertex3f(0.10, 5.40, 0.0);

    glColor3ub(255,255,255);///

    glVertex3f(-1.70, 4.50, 0.0);
    glVertex3f(-1.70, 4.20, 0.0);
    glVertex3f(1.25, 4.20, 0.0);
    glVertex3f(1.25, 4.50, 0.0);

    glColor3ub(255,215,0);

    glVertex3f(-0.62, 5.80, 0.0);
    glVertex3f(-0.62, 5.40, 0.0);
    glVertex3f(0.20, 5.40, 0.0);
    glVertex3f(0.20, 5.80, 0.0);

    glColor3ub(0,255,255);

    ///upper body
    glVertex3f(-1.20, 6.50, 0.0);
    glVertex3f(-1.20, 4.50, 0.0);
    glVertex3f(0.80, 4.50, 0.0);
    glVertex3f(0.80, 6.50, 0.0);

    glColor3ub(47,79,79);

///door
    glVertex3f(-1.50, 3.20, 0.0);
    glVertex3f(-1.50, 1.20, 0.0);
    glVertex3f(-1.25, 1.20, 0.0);
    glVertex3f(-1.25, 3.20, 0.0);

    glVertex3f(-1.1, 3.20, 0.0);
    glVertex3f(-1.1, 1.20, 0.0);
    glVertex3f(-0.85, 1.20, 0.0);
    glVertex3f(-0.85, 3.20, 0.0);

    glVertex3f(0.75, 3.20, 0.0);
    glVertex3f(0.75, 1.20, 0.0);
    glVertex3f(1.0, 1.20, 0.0);
    glVertex3f(1.0, 3.20, 0.0);

    glVertex3f(0.35, 3.20, 0.0);
    glVertex3f(0.35, 1.20, 0.0);
    glVertex3f(0.60, 1.20, 0.0);
    glVertex3f(0.60, 3.20, 0.0);


    glColor3ub(0,255,255);
///lower body
    glVertex3f(-1.60, 4.50, 0.0);
    glVertex3f(-1.60, 1.40, 0.0);
    glVertex3f(1.15, 1.40, 0.0);
    glVertex3f(1.15, 4.50, 0.0);


    glColor3ub(240,230,140);///piller

    glVertex3f(-1.60, 6.6, 0.0);
    glVertex3f(-1.60, 4.50, 0.0);
    glVertex3f(-1.30, 4.50, 0.0);
    glVertex3f(-1.30, 6.6, 0.0);

    glVertex3f(0.9, 6.6, 0.0);
    glVertex3f(0.9, 4.5, 0.0);
    glVertex3f(01.20, 4.5, 0.0);
    glVertex3f(01.20, 6.6, 0.0);


    glVertex3f(-1.55, 7.0, 0.0);
    glVertex3f(-1.55, 9.50, 0.0);
    glVertex3f(-1.35, 9.50, 0.0);
    glVertex3f(-1.35, 7.0, 0.0);

    glVertex3f(0.95, 7.0, 0.0);
    glVertex3f(0.95, 9.50, 0.0);
    glVertex3f(01.15, 9.50, 0.0);
    glVertex3f(01.15, 7.0, 0.0);

    glColor3ub(240,128,128);
///piller joint

    glVertex3f(-1.59, 9.30, 0.0);
    glVertex3f(-1.59, 9.70, 0.0);
    glVertex3f(-1.32, 9.70, 0.0);
    glVertex3f(-1.32, 9.30, 0.0);

    glVertex3f(0.92, 9.30, 0.0);
    glVertex3f(0.92, 9.70, 0.0);
    glVertex3f(01.17,9.70, 0.0);
    glVertex3f(01.17, 9.30, 0.0);

    glVertex3f(-1.65, 7.0, 0.0);
    glVertex3f(-1.65, 6.0, 0.0);
    glVertex3f(-1.25, 6.0, 0.0);
    glVertex3f(-1.25, 7.0, 0.0);

    glVertex3f(0.85, 7.0, 0.0);
    glVertex3f(0.85, 6.0, 0.0);
    glVertex3f(01.25,6.0, 0.0);
    glVertex3f(01.25,7.0, 0.0);


    ///5th building


    glColor3ub(255,255,255);///base

    glVertex3f(1.40, 1.50, 0.0);
    glVertex3f(1.40, 1.20, 0.0);
    glVertex3f(5.80, 1.20, 0.0);
    glVertex3f(5.80, 1.50, 0.0);

    glColor3ub(255,255,224);///mid window

    glVertex3f(2.70, 8.0, 0.0);
    glVertex3f(2.70, 7.20, 0.0);
    glVertex3f(3.0, 7.20, 0.0);
    glVertex3f(3.0, 8.0, 0.0);

    glVertex3f(2.7, 7.0, 0.0);
    glVertex3f(2.70, 6.20, 0.0);
    glVertex3f(3.0, 6.20, 0.0);
    glVertex3f(3.0, 7.0, 0.0);

    glVertex3f(2.70, 6.0, 0.0);
    glVertex3f(2.70, 5.20, 0.0);
    glVertex3f(3.0, 5.20, 0.0);
    glVertex3f(3.0, 6.0, 0.0);

    glVertex3f(2.70, 5.0, 0.0);
    glVertex3f(2.70, 4.20, 0.0);
    glVertex3f(3.0, 4.20, 0.0);
    glVertex3f(3.0, 5.0, 0.0);
    ///
    glVertex3f(3.10, 8.0, 0.0);
    glVertex3f(3.10, 7.20, 0.0);
    glVertex3f(3.40, 7.20, 0.0);
    glVertex3f(3.40, 8.0, 0.0);

    glVertex3f(3.1, 7.0, 0.0);
    glVertex3f(3.10, 6.20, 0.0);
    glVertex3f(3.40, 6.20, 0.0);
    glVertex3f(3.40, 7.0, 0.0);

    glVertex3f(3.10, 6.0, 0.0);
    glVertex3f(3.10, 5.20, 0.0);
    glVertex3f(3.40, 5.20, 0.0);
    glVertex3f(3.40, 6.0, 0.0);

    glVertex3f(3.10, 5.0, 0.0);
    glVertex3f(3.10, 4.20, 0.0);
    glVertex3f(3.40, 4.20, 0.0);
    glVertex3f(3.40, 5.0, 0.0);
    ///
    ///
    glVertex3f(3.50, 8.0, 0.0);
    glVertex3f(3.50, 7.20, 0.0);
    glVertex3f(3.80, 7.20, 0.0);
    glVertex3f(3.80, 8.0, 0.0);

    glVertex3f(3.5, 7.0, 0.0);
    glVertex3f(3.5, 6.20, 0.0);
    glVertex3f(3.80, 6.20, 0.0);
    glVertex3f(3.80, 7.0, 0.0);

    glVertex3f(3.50, 6.0, 0.0);
    glVertex3f(3.50, 5.20, 0.0);
    glVertex3f(3.80, 5.20, 0.0);
    glVertex3f(3.80, 6.0, 0.0);

    glVertex3f(3.50, 5.0, 0.0);
    glVertex3f(3.50, 4.20, 0.0);
    glVertex3f(3.80, 4.20, 0.0);
    glVertex3f(3.80, 5.0, 0.0);

    ///

    glVertex3f(3.90, 8.0, 0.0);
    glVertex3f(3.90, 7.20, 0.0);
    glVertex3f(4.20, 7.20, 0.0);
    glVertex3f(4.20, 8.0, 0.0);

    glVertex3f(3.9, 7.0, 0.0);
    glVertex3f(3.9, 6.20, 0.0);
    glVertex3f(4.20, 6.20, 0.0);
    glVertex3f(4.20, 7.0, 0.0);

    glVertex3f(3.90, 6.0, 0.0);
    glVertex3f(3.90, 5.20, 0.0);
    glVertex3f(4.20, 5.20, 0.0);
    glVertex3f(4.20, 6.0, 0.0);

    glVertex3f(3.90, 5.0, 0.0);
    glVertex3f(3.90, 4.20, 0.0);
    glVertex3f(4.20, 4.20, 0.0);
    glVertex3f(4.20, 5.0, 0.0);

    ///
    ///
    glVertex3f(4.30, 8.0, 0.0);
    glVertex3f(4.30, 7.20, 0.0);
    glVertex3f(4.60, 7.20, 0.0);
    glVertex3f(4.60, 8.0, 0.0);

    glVertex3f(4.3, 7.0, 0.0);
    glVertex3f(4.3, 6.20, 0.0);
    glVertex3f(4.60, 6.20, 0.0);
    glVertex3f(4.60, 7.0, 0.0);

    glVertex3f(4.30, 6.0, 0.0);
    glVertex3f(4.30, 5.20, 0.0);
    glVertex3f(4.60, 5.20, 0.0);
    glVertex3f(4.60, 6.0, 0.0);

    glVertex3f(4.30, 5.0, 0.0);
    glVertex3f(4.30, 4.20, 0.0);
    glVertex3f(4.60, 4.20, 0.0);
    glVertex3f(4.60, 5.0, 0.0);

    ///door

    glColor3ub(255,255,0);
    glVertex3f(3.26, 4.0, 0.0);
    glVertex3f(3.26, 3.80, 0.0);
    glVertex3f(4.04, 3.80, 0.0);
    glVertex3f(4.04, 4.0, 0.0);

    glColor3ub(30,144,255);

    glVertex3f(3.30, 3.80, 0.0);
    glVertex3f(3.30, 1.20, 0.0);
    glVertex3f(4.0, 1.20, 0.0);
    glVertex3f(4.0, 3.80, 0.0);





    glColor3ub(244,164,96);///body

    glVertex3f(2.50, 9.20, 0.0);
    glVertex3f(2.50, 1.20, 0.0);
    glVertex3f(4.70, 1.20, 0.0);
    glVertex3f(4.70, 9.20, 0.0);

    glVertex3f(2.80, 11.20, 0.0);
    glVertex3f(2.80, 9.20, 0.0);
    glVertex3f(4.40, 9.20, 0.0);
    glVertex3f(4.40, 11.20, 0.0);

    glColor3ub(255,105,180);///base upper

    glVertex3f(1.40, 6.50, 0.0);
    glVertex3f(1.40, 6.20, 0.0);
    glVertex3f(5.80, 6.20, 0.0);
    glVertex3f(5.80, 6.50, 0.0);


    glColor3ub(128,128,0);

    glVertex3f(1.80, 7.50, 0.0);
    glVertex3f(1.80, 6.50, 0.0);
    glVertex3f(5.40, 6.50, 0.0);
    glVertex3f(5.40, 7.50, 0.0);



    glColor3ub(65,105,225);///inside windows

    glVertex3f(1.60, 6.0, 0.0);
    glVertex3f(1.60, 5.20, 0.0);
    glVertex3f(1.90, 5.20, 0.0);
    glVertex3f(1.90, 6.0, 0.0);

    glVertex3f(1.60, 5.0, 0.0);
    glVertex3f(1.60, 4.20, 0.0);
    glVertex3f(1.90, 4.20, 0.0);
    glVertex3f(1.90, 5.0, 0.0);

    glVertex3f(1.60, 4.0, 0.0);
    glVertex3f(1.60, 3.20, 0.0);
    glVertex3f(1.90, 3.20, 0.0);
    glVertex3f(1.90, 4.0, 0.0);

    glVertex3f(2.10, 6.0, 0.0);
    glVertex3f(2.10, 5.20, 0.0);
    glVertex3f(2.4, 5.20, 0.0);
    glVertex3f(2.4, 6.0, 0.0);

    glVertex3f(2.1, 5.0, 0.0);
    glVertex3f(2.10, 4.20, 0.0);
    glVertex3f(2.40, 4.20, 0.0);
    glVertex3f(2.40, 5.0, 0.0);

    glVertex3f(2.10, 4.0, 0.0);
    glVertex3f(2.10, 3.20, 0.0);
    glVertex3f(2.40, 3.20, 0.0);
    glVertex3f(2.40, 4.0, 0.0);

    ///

    glVertex3f(5.30, 6.0, 0.0);
    glVertex3f(5.30, 5.20, 0.0);
    glVertex3f(5.60, 5.20, 0.0);
    glVertex3f(5.60, 6.0, 0.0);

    glVertex3f(5.3, 5.0, 0.0);
    glVertex3f(5.30, 4.20, 0.0);
    glVertex3f(5.60, 4.20, 0.0);
    glVertex3f(5.60, 5.0, 0.0);

    glVertex3f(5.30, 4.0, 0.0);
    glVertex3f(5.30, 3.20, 0.0);
    glVertex3f(5.60, 3.20, 0.0);
    glVertex3f(5.60, 4.0, 0.0);

    glVertex3f(4.80, 6.0, 0.0);
    glVertex3f(4.80, 5.20, 0.0);
    glVertex3f(5.1, 5.20, 0.0);
    glVertex3f(5.1, 6.0, 0.0);

    glVertex3f(4.8, 5.0, 0.0);
    glVertex3f(4.80, 4.20, 0.0);
    glVertex3f(5.10, 4.20, 0.0);
    glVertex3f(5.10, 5.0, 0.0);

    glVertex3f(4.80, 4.0, 0.0);
    glVertex3f(4.80, 3.20, 0.0);
    glVertex3f(5.10, 3.20, 0.0);
    glVertex3f(5.10, 4.0, 0.0);



    glColor3ub(255,205,255);///main

    glVertex3f(1.50, 6.20, 0.0);
    glVertex3f(1.50, 1.20, 0.0);
    glVertex3f(5.70, 1.20, 0.0);
    glVertex3f(5.70, 6.20, 0.0);






    glEnd();


    glPopMatrix();





///road
    glPushMatrix(); //Save the current state of transformations
    glTranslatef(0.0, -2.0, 0.0); //Move to the center of the pentagon
    //glRotatef(_angle, 1.0, 0.0, 0.0); //Rotate about the y-axis
    glScalef(0.50, 0.50, 0.0); //Scale by 0.7 in the x, y, and z directions

    glBegin(GL_QUADS);
    ///line

    glColor3ub(255,255,0);
    //Trapezoid
    glVertex3f(5.85, 0.20, 0.0);
    glVertex3f(5.9, 0.15, 0.0);
    glVertex3f(5.30, 0.15, 0.0);
    glVertex3f(5.25, 0.20, 0.0);

    glVertex3f(4.85, 0.20, 0.0);
    glVertex3f(4.9, 0.15, 0.0);
    glVertex3f(4.30, 0.15, 0.0);
    glVertex3f(4.25, 0.20, 0.0);


    glVertex3f(3.85, 0.20, 0.0);
    glVertex3f(3.9, 0.15, 0.0);
    glVertex3f(3.30, 0.15, 0.0);
    glVertex3f(3.25, 0.20, 0.0);

    glVertex3f(2.85, 0.20, 0.0);
    glVertex3f(2.9, 0.15, 0.0);
    glVertex3f(2.30, 0.15, 0.0);
    glVertex3f(2.25, 0.20, 0.0);


    glVertex3f(1.85, 0.20, 0.0);
    glVertex3f(1.9, 0.15, 0.0);
    glVertex3f(1.30, 0.15, 0.0);
    glVertex3f(1.25, 0.20, 0.0);

    glVertex3f(0.85, 0.20, 0.0);
    glVertex3f(0.9, 0.15, 0.0);
    glVertex3f(0.30, 0.15, 0.0);
    glVertex3f(0.25, 0.20, 0.0);

///

    glVertex3f(-0.9, 0.20, 0.0);
    glVertex3f(-0.85, 0.15, 0.0);
    glVertex3f(-0.25, 0.15, 0.0);
    glVertex3f(-0.30, 0.20, 0.0);

    glVertex3f(-1.9, 0.20, 0.0);
    glVertex3f(-1.85, 0.15, 0.0);
    glVertex3f(-1.25, 0.15, 0.0);
    glVertex3f(-1.30, 0.20, 0.0);


    glVertex3f(-2.9, 0.20, 0.0);
    glVertex3f(-2.85, 0.15, 0.0);
    glVertex3f(-2.25, 0.15, 0.0);
    glVertex3f(-2.30, 0.20, 0.0);

    glVertex3f(-3.9, 0.20, 0.0);
    glVertex3f(-3.85, 0.15, 0.0);
    glVertex3f(-3.25, 0.15, 0.0);
    glVertex3f(-3.30, 0.20, 0.0);


    glVertex3f(-4.9, 0.20, 0.0);
    glVertex3f(-4.85, 0.15, 0.0);
    glVertex3f(-4.25, 0.15, 0.0);
    glVertex3f(-4.30, 0.20, 0.0);


    glVertex3f(-5.9, 0.20, 0.0);
    glVertex3f(-5.85, 0.15, 0.0);
    glVertex3f(-5.25, 0.15, 0.0);
    glVertex3f(-5.30, 0.20, 0.0);

    ///road

    glColor3ub(105,105,105);
    glVertex3f(6.0, 01.25, 0.0);

    glColor3ub(40,40,40);
    glVertex3f(6.0, -1.0, 0.0);
    glVertex3f(-6.0, -1.0, 0.0);

    glColor3ub(105,105,105);
    glVertex3f(-6.0, 01.25, 0.0);




    glEnd();

    glPopMatrix(); //Undo the move to the center of the pentagon/*




    ///4th building

    glPushMatrix(); //Save the current state of transformations
    glTranslatef(-0.10, 0.10, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)

    glColor3ub(0,128,0);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.38;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();


    glPopMatrix(); //Undo the move to the center of the triangle



    glPushMatrix();
    glTranslatef(0.0, -4.0, 0.0);
    //glRotatef(0, 0.0, 1.0, 0.0);
    glScalef(0.30, 0.40, 0.0);


    glPushMatrix();

    glBegin(GL_QUADS);


    ///6th building backward


    glColor3ub(255,255,255);///building 5

///windows

    glVertex3f(1.0, 12.50, 0.0);
    glVertex3f(1.0, 12.25, 0.0);
    glVertex3f(0.90, 12.25, 0.0);
    glVertex3f(0.90, 12.50, 0.0);

    glVertex3f(1.10, 12.50, 0.0);
    glVertex3f(1.10, 12.25, 0.0);
    glVertex3f(1.20, 12.25, 0.0);
    glVertex3f(1.20, 12.50, 0.0);

    glVertex3f(1.30, 12.50, 0.0);
    glVertex3f(1.30, 12.25, 0.0);
    glVertex3f(1.40, 12.25, 0.0);
    glVertex3f(1.40, 12.50, 0.0);


    glVertex3f(1.50, 12.50, 0.0);
    glVertex3f(1.50, 12.25, 0.0);
    glVertex3f(1.60, 12.25, 0.0);
    glVertex3f(1.60, 12.50, 0.0);

////**********

    glVertex3f(1.0, 11.50, 0.0);
    glVertex3f(1.0, 11.25, 0.0);
    glVertex3f(0.90, 11.25, 0.0);
    glVertex3f(0.90, 11.50, 0.0);

    glVertex3f(1.10, 11.50, 0.0);
    glVertex3f(1.10, 11.25, 0.0);
    glVertex3f(1.20, 11.25, 0.0);
    glVertex3f(1.20, 11.50, 0.0);

    glVertex3f(1.30, 11.50, 0.0);
    glVertex3f(1.30, 11.25, 0.0);
    glVertex3f(1.40, 11.25, 0.0);
    glVertex3f(1.40, 11.50, 0.0);


    glVertex3f(1.50, 11.50, 0.0);
    glVertex3f(1.50, 11.25, 0.0);
    glVertex3f(1.60, 11.25, 0.0);
    glVertex3f(1.60, 11.50, 0.0);
//**********

    glVertex3f(1.0, 10.50, 0.0);
    glVertex3f(1.0, 10.25, 0.0);
    glVertex3f(0.90, 10.25, 0.0);
    glVertex3f(0.90, 10.50, 0.0);

    glVertex3f(1.10, 10.50, 0.0);
    glVertex3f(1.10, 10.25, 0.0);
    glVertex3f(1.20, 10.25, 0.0);
    glVertex3f(1.20, 10.50, 0.0);

    glVertex3f(1.30, 10.50, 0.0);
    glVertex3f(1.30,10.25, 0.0);
    glVertex3f(1.40, 10.25, 0.0);
    glVertex3f(1.40, 10.50, 0.0);


    glVertex3f(1.50, 10.50, 0.0);
    glVertex3f(1.50, 10.25, 0.0);
    glVertex3f(1.60, 10.25, 0.0);
    glVertex3f(1.60, 10.50, 0.0);

    ///main5

    glColor3ub(112,128,144);
    glVertex3f(0.80, 13.20, 0.0);
    glColor3ub(211,211,211);
    glVertex3f(0.80, 8.20, 0.0);
    glVertex3f(1.70, 8.20, 0.0);
    glVertex3f(1.70, 13.20, 0.0);


    glColor3ub(255,255,255);///building 6

///windows

    glVertex3f(2.70, 11.50, 0.0);
    glVertex3f(2.70, 11.25, 0.0);
    glVertex3f(2.80, 11.25, 0.0);
    glVertex3f(2.80, 11.50, 0.0);

    glVertex3f(2.70, 10.50, 0.0);
    glVertex3f(2.70, 10.25, 0.0);
    glVertex3f(2.80, 10.25, 0.0);
    glVertex3f(2.80, 10.50, 0.0);

    glVertex3f(2.5, 11.50, 0.0);
    glVertex3f(2.5, 10.25, 0.0);
    glVertex3f(2.30,  10.25, 0.0);
    glVertex3f(2.30, 11.50, 0.0);


    glColor3ub(139,69,19);///main6

    glVertex3f(01.70, 12.20, 0.0);

    glColor3ub(176,196,222);
    glVertex3f(01.70, 5.20, 0.0);
    glVertex3f(3.0, 5.20, 0.0);
    glVertex3f(3.0, 12.20, 0.0);

    glColor3ub(255,255,255);///building 7


    glVertex3f(04.70, 12.50, 0.0);
    glVertex3f(04.70, 11.50, 0.0);
    glVertex3f(5.0, 11.50, 0.0);
    glVertex3f(5.0, 12.50, 0.0);

    glVertex3f(05.10, 13.0, 0.0);
    glVertex3f(05.10, 12.50, 0.0);
    glVertex3f(5.40, 12.50, 0.0);
    glVertex3f(5.40, 13.0, 0.0);


    glColor3ub(255,255,255);///main7

    glVertex3f(04.40, 13.20, 0.0);

    glColor3ub(0,0,0);
    glVertex3f(04.40, 5.20, 0.0);
    glVertex3f(5.60, 5.20, 0.0);
    glVertex3f(5.60, 13.20, 0.0);

    glColor3ub(255,255,255);///building 8


    glVertex3f(08.0, 14.0, 0.0);
    glVertex3f(08.0,13.60, 0.0);
    glVertex3f(8.40, 13.60, 0.0);
    glVertex3f(8.40, 14.0, 0.0);


    glVertex3f(08.0, 13.0, 0.0);
    glVertex3f(08.0,12.60, 0.0);
    glVertex3f(8.40, 12.60, 0.0);
    glVertex3f(8.40, 13.0, 0.0);

    glVertex3f(07.80, 14.20, 0.0);
    glVertex3f(07.80, 8.60, 0.0);
    glVertex3f(7.90, 8.60, 0.0);
    glVertex3f(7.90, 14.20, 0.0);

    glVertex3f(08.60, 14.20, 0.0);
    glVertex3f(08.60, 8.60, 0.0);
    glVertex3f(8.50, 8.60, 0.0);
    glVertex3f(8.50, 14.20, 0.0);


    glColor3ub(128,128,128);///main8

    glVertex3f(07.50, 14.20, 0.0);

    glColor3ub(238,232,170);
    glVertex3f(07.50, 5.20, 0.0);
    glVertex3f(8.80, 5.20, 0.0);
    glVertex3f(8.80, 14.20, 0.0);


    glColor3ub(255,255,255);///building 1


    glVertex3f(-7.60, 12.20, 0.0);
    glVertex3f(-7.60, 11.50, 0.0);
    glVertex3f(-7.0, 11.50, 0.0);
    glVertex3f(-7.0, 12.20, 0.0);


    glVertex3f(-6.80, 13.20, 0.0);
    glVertex3f(-6.80, 12.50, 0.0);
    glVertex3f(-7.40, 12.50, 0.0);
    glVertex3f(-7.40, 13.20, 0.0);





    glVertex3f(-5.60, 12.20, 0.0);
    glVertex3f(-5.60, 11.50, 0.0);
    glVertex3f(-5.10, 11.50, 0.0);
    glVertex3f(-5.10, 12.20, 0.0);



    glColor3ub(0,0,0);///main1


    glVertex3f(-8.0, 13.50, 0.0);

    glColor3ub(173,216,230);
    glVertex3f(-8.0, 5.25, 0.0);
    glVertex3f(-5.0, 5.25, 0.0);
    glVertex3f(-5.0, 13.50, 0.0);

    glColor3ub(176,196,222);
    glVertex3f(-7.40, 14.20, 0.0);

    glColor3ub(173,216,230);
    glVertex3f(-7.40, 13.50, 0.0);
    glVertex3f(-5.30, 13.50, 0.0);
    glVertex3f(-5.30, 14.20, 0.0);


    glColor3ub(255,255,255);///building 3

    glVertex3f(-2.30, 14.20, 0.0);
    glVertex3f(-2.30, 13.80, 0.0);
    glVertex3f(-3.10, 13.80, 0.0);
    glVertex3f(-3.10, 14.20, 0.0);

    glVertex3f(-2.50, 13.20, 0.0);
    glVertex3f(-2.50, 12.80, 0.0);
    glVertex3f(-2.90, 12.80, 0.0);
    glVertex3f(-2.90, 13.20, 0.0);

    glVertex3f(-2.80, 12.20, 0.0);
    glVertex3f(-2.80, 11.80, 0.0);
    glVertex3f(-2.60, 11.80, 0.0);
    glVertex3f(-2.60, 12.20, 0.0);

    glVertex3f(-2.75, 11.20, 0.0);
    glVertex3f(-2.75, 10.80, 0.0);
    glVertex3f(-2.65, 10.80, 0.0);
    glVertex3f(-2.65, 11.20, 0.0);


    glColor3ub(255,192,203);///main3


    glVertex3f(-2.10, 14.50, 0.0);
    glColor3ub(255,250,250);

    glVertex3f(-2.10, 5.25, 0.0);
    glVertex3f(-3.30, 5.25, 0.0);
    glColor3ub(255,192,203);
    glVertex3f(-3.30, 14.50, 0.0);

    glColor3ub(255,255,255);///building 4

///windows

    glVertex3f(-0.80, 10.50, 0.0);
    glVertex3f(-0.80, 10.25, 0.0);
    glVertex3f(-1.0, 10.25, 0.0);
    glVertex3f(-1.0, 10.50, 0.0);

    glVertex3f(-1.20, 10.50, 0.0);
    glVertex3f(-1.20, 10.25, 0.0);
    glVertex3f(-1.10, 10.25, 0.0);
    glVertex3f(-1.10, 10.50, 0.0);

    glVertex3f(-1.40, 10.50, 0.0);
    glVertex3f(-1.40, 10.25, 0.0);
    glVertex3f(-1.30, 10.25, 0.0);
    glVertex3f(-1.30, 10.50, 0.0);

    glVertex3f(-1.50, 10.50, 0.0);
    glVertex3f(-1.50, 10.25, 0.0);
    glVertex3f(-1.60, 10.25, 0.0);
    glVertex3f(-1.60, 10.50, 0.0);


    glVertex3f(-1.80, 10.50, 0.0);
    glVertex3f(-1.80, 10.25, 0.0);
    glVertex3f(-1.70, 10.25, 0.0);
    glVertex3f(-1.70, 10.50, 0.0);



///**********

    glVertex3f(-1.20, 11.50, 0.0);
    glVertex3f(-1.20, 11.25, 0.0);
    glVertex3f(-1.10, 11.25, 0.0);
    glVertex3f(-1.10, .50, 0.0);

    glVertex3f(-1.40, 11.50, 0.0);
    glVertex3f(-1.40, 11.25, 0.0);
    glVertex3f(-1.30, 11.25, 0.0);
    glVertex3f(-1.30, 11.50, 0.0);

    glVertex3f(-1.50, 11.50, 0.0);
    glVertex3f(-1.50, 11.25, 0.0);
    glVertex3f(-1.60, 11.25, 0.0);
    glVertex3f(-1.60, 11.50, 0.0);


    glVertex3f(-1.80, 11.50, 0.0);
    glVertex3f(-1.80, 11.25, 0.0);
    glVertex3f(-1.70, 11.25, 0.0);
    glVertex3f(-1.70, 11.50, 0.0);

    ///////

    glVertex3f(-1.90, 10.50, 0.0);
    glVertex3f(-1.90, 10.25, 0.0);
    glVertex3f(-2.0, 10.25, 0.0);
    glVertex3f(-2.0, 10.50, 0.0);


    glVertex3f(-0.80, 9.50, 0.0);
    glVertex3f(-0.80, 9.25, 0.0);
    glVertex3f(-1.0, 9.25, 0.0);
    glVertex3f(-1.0, 9.50, 0.0);

    glColor3ub(105,105,105);///main4


    glVertex3f(-0.80, 11.90, 0.0);
    glVertex3f(-0.80, 5.25, 0.0);
    glVertex3f(-2.05, 5.25, 0.0);
    glVertex3f(-2.05, 11.90, 0.0);

    glEnd();


    glPopMatrix();


    glPopMatrix();




    glPushMatrix(); //Save the current state of transformations

    glScalef(0.50, 0.50, 0.0); //Scale by 0.7 in the x, y, and z directions

    glBegin(GL_QUADS);

    ///background

    glColor3ub(a,b,c);
    glVertex3f(6.0, 6.0, 0.0);

    //glColor3ub(205,205,200);
    glVertex3f(6.0, -04.0, 0.0);
    glVertex3f(-6.0, -04.0, 0.0);

    // glColor3ub(25,25,112);
    glVertex3f(-6.0, 6, 0.0);


    glEnd();


    glPopMatrix(); //Undo the move to the center of the pentagon/*




    glFlush();
    glutSwapBuffers();
}

void drawScene()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
    glLoadIdentity(); //Reset the drawing perspective
    glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
    glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units

    ///Healthbarenemy


    glPushMatrix();
    if (colCountL == 0 && xy!=1000)
    {
        glTranslatef(1.0, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(0,128,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5 , -0.1);
        glVertex2f(1.5, 0.0);
        glEnd();


    }

    else if (colCountL == 1 && xy!=1000)
    {
        //yellow
        glTranslatef(1.0, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(255,255,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5-0.6 , -0.1);
        glVertex2f(1.5-0.6, 0.0);
        glEnd();
    }
    else if (colCountL == 2 && xy!=1000)
    {
        glTranslatef(1.0, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(255,0,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5-1.2 , -0.1);
        glVertex2f(1.5-1.2, 0.0);
        glEnd();
    }
    else if (colCountL == 0 && xy==1000 )
    {
        glTranslatef(1.0, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(0,128,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5 , -0.1);
        glVertex2f(1.5, 0.0);
        glEnd();


    }

    else if (colCountL == 1&& xy==1000 )
    {
        //yellow
        glTranslatef(1.0, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(255,255,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5-0.6 , -0.1);
        glVertex2f(1.5-0.6, 0.0);
        glEnd();
    }
    else if (colCountL == 2 && xy==1000)
    {
        glTranslatef(1.0, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(255,0,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5-1.2 , -0.1);
        glVertex2f(1.5-1.2, 0.0);
        glEnd();
    }


    glPopMatrix();

///HealthbarHero
    glPushMatrix();

    glPushMatrix();
    glTranslatef(-2.5, 2.58, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(0,128,0);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.05 , 0.0);
    glVertex2f(0.05 , -0.25);
    glVertex2f(0.0, -0.25);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.34, 2.45, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(0,128,0);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.25 , 0.0);
    glVertex2f(-0.25,0.05 );
    glVertex2f(0.0, 0.05);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.7, 2.58, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(0,128,0);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.05 , 0.0);
    glVertex2f(0.05 , -0.25);
    glVertex2f(0.0, -0.25);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.85, 2.45, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(0,128,0);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.25 , 0.0);
    glVertex2f(-0.25,0.05 );
    glVertex2f(0.0, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    if (colCountR == 0 && xy1!=1000)
    {
        glTranslatef(-2.2, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(0,128,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5 , -0.1);
        glVertex2f(1.5, 0.0);
        glEnd();
    }

    else if (colCountR == 1 && xy1!=1000)
    {
        //yellow
        glTranslatef(-2.2, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(255,255,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5-0.6 , -0.1);
        glVertex2f(1.5-0.6, 0.0);
        glEnd();
    }
    else if (colCountR == 2 && xy1!=1000)
    {
        glTranslatef(-2.2, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(255,0,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5-1.2 , -0.1);
        glVertex2f(1.5-1.2, 0.0);
        glEnd();
    }
    else if (colCountR == 0 && xy1==1000)
    {
        glTranslatef(-2.2, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(0,128,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5 , -0.1);
        glVertex2f(1.5, 0.0);
        glEnd();
    }

    else if (colCountR == 1 && xy1==1000)
    {
        //yellow
        glTranslatef(-2.2, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(255,255,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5-0.6 , -0.1);
        glVertex2f(1.5-0.6, 0.0);
        glEnd();
    }
    else if (colCountR == 2 && xy1==1000)
    {
        glTranslatef(-2.2, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(255,0,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5-1.2 , -0.1);
        glVertex2f(1.5-1.2, 0.0);
        glEnd();
    }


    glPopMatrix();

    glPopMatrix();



///start pause
    glPushMatrix();
    glTranslatef(0, p, 0.0);
    glScalef(0.50, 0.50, 0.0);




    glPushMatrix();

    glColor3ub(255,240,245);


    glutSolidTorus(.2,1,100,100);


    glPopMatrix();


    glPushMatrix();
    glBegin(GL_QUADS);

    glColor3ub(220,220,220);


    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(0.35, -0.5, 0.0);
    glVertex3f(0.35, 0.5, 0.0);



    glVertex3f(0.10, 0.5, 0.0);
    glVertex3f(0.10, -0.5, 0.0);
    glVertex3f(0.25, -0.5, 0.0);
    glVertex3f(0.25, 0.5, 0.0);


    glEnd();


    glPopMatrix();


    glPushMatrix();

    glBegin(GL_TRIANGLES);



    glVertex3f(0.08, -0.0, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glVertex3f(-0.5, -0.5, 0.0);

    glEnd();

    glPopMatrix();
    glPopMatrix();
    ///end pause


    ///Chr2
    glPushMatrix();
    glScalef(-1,1,1);
    glScalef(0.25,0.25,0);
    glTranslatef(7.0+ch1,y, 0.0);


    glPushMatrix(); //Save the transformations performed thus far
    //glTranslatef(1.0, -1.0, 0.0);
    //glScalef(2.5,2.5,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
    //hand


    glColor3ub(85,107,47);
    glBegin(GL_QUADS);

    glVertex3f(-0.4, -0.2+yr, 0.0);
    glVertex3f(0.2, -0.2+yr, 0.0);
    glVertex3f(0.2,-0.4+yr, 0.0);
    glVertex3f(-0.4,-0.4+yr,0);


    glVertex3f(-0.4,-0.2+yr, 0.0);
    glVertex3f(-0.4,-0.4+yr,0);
    glVertex3f(-0.8, -0.6+yr, 0.0);
    glVertex3f(-0.8, 0.0+yr, 0.0);

    glVertex3f(-0.8,-0.6+yr, 0.0);
    glVertex3f(-1.0,-0.6+yr,0);
    glVertex3f(-1.0, -0.5+yr, 0.0);
    glVertex3f(-0.8, -0.5+yr, 0.0);

    glVertex3f(-0.8,-0.0+yr, 0.0);
    glVertex3f(-1.0,-0.0+yr,0);
    glVertex3f(-1.0, -0.1+yr, 0.0);
    glVertex3f(-0.8, -0.1+yr, 0.0);

    glEnd();

    glTranslatef(0.3, -0.3, 0.0);

    glColor3ub(72,61,139);
    //HAND

    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.15;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y+yr );
    }
    glEnd();

    glPopMatrix();


    ///Bullet

    glPushMatrix(); //Save the transformations performed thus far
    glTranslatef(x, xy, 0.0);
    glColor3ub(226,104,34);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y+yr);
    }
    glEnd();



    glPopMatrix();

    ///BulletEnd


    glPushMatrix(); //Save the transformations performed thus far
    //glTranslatef(1.0, -1.0, 0.0);
    //glScalef(2.5,2.5,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
    glBegin(GL_QUADS);


    glColor3ub(0,100,0);
    //spot

    glVertex3f(0.60, -0.10+yr, 0.0);
    glVertex3f(0.50, -0.2+yr, 0.0);
    glVertex3f(0.5, -0.4+yr, 0.0);
    glVertex3f(0.55,-0.10+yr,0);


    glVertex3f(0.60, -0.50+yr, 0.0);
    glVertex3f(0.50, -0.4+yr, 0.0);
    glVertex3f(0.5, -0.48+yr, 0.0);
    glVertex3f(0.55,-0.50+yr,0);


    glVertex3f(0.60, -0.80+yr, 0.0);
    glVertex3f(0.50, -0.7+yr, 0.0);
    glVertex3f(0.5, -0.68+yr, 0.0);
    glVertex3f(0.55,-0.80+yr,0);


    glVertex3f(0.40, -0.90+yr, 0.0);
    glVertex3f(0.30, -0.85+yr, 0.0);
    glVertex3f(0.3, -0.7+yr, 0.0);
    glVertex3f(0.35,-0.90+yr,0);

    glVertex3f(0.10, -0.95+yr, 0.0);
    glVertex3f(0.08, -0.75+yr, 0.0);
    glVertex3f(0.2, -0.60+yr, 0.0);
    glVertex3f(0.15,-0.85+yr,0);

    glVertex3f(0.10, -0.45+yr, 0.0);
    glVertex3f(0.08, -0.55+yr, 0.0);
    glVertex3f(0.2, -0.60+yr, 0.0);
    glVertex3f(0.15,-0.5+yr,0);

    glVertex3f(0.30, -0.45+yr, 0.0);
    glVertex3f(0.28, -0.65+yr, 0.0);
    glVertex3f(0.35, -0.60+yr, 0.0);
    glVertex3f(0.25,-0.55+yr,0);

    glVertex3f(0.30, -0.0+yr, 0.0);
    glVertex3f(0.28, -0.1+yr, 0.0);
    glVertex3f(0.35, -0.1+yr, 0.0);
    glVertex3f(0.25,-0.0+yr,0.0);

    glVertex3f(0.0, -0.0+yr, 0.0);
    glVertex3f(0.08, -0.1+yr, 0.0);
    glVertex3f(0.05, -0.1+yr, 0.0);
    glVertex3f(0.05,-0.0+yr,0.0);


    glColor3ub(160,82,45);



    glVertex3f(0.55, -0.10+yr, 0.0);
    glVertex3f(0.50, -0.2+yr, 0.0);
    glVertex3f(0.56, -0.4+yr, 0.0);
    glVertex3f(0.50,-0.10+yr,0);


    glVertex3f(0.4, -0.50+yr, 0.0);
    glVertex3f(0.40, -0.4+yr, 0.0);
    glVertex3f(0.50, -0.48+yr, 0.0);
    glVertex3f(0.45,-0.50+yr,0);


    glVertex3f(0.10, -0.80+yr, 0.0);
    glVertex3f(0.20, -0.7+yr, 0.0);
    glVertex3f(0.1, -0.5+yr, 0.0);
    glVertex3f(0.15,-0.80+yr,0);


    glVertex3f(0.50, -0.90+yr, 0.0);
    glVertex3f(0.20, -0.85+yr, 0.0);
    glVertex3f(0.44, -0.7+yr, 0.0);
    glVertex3f(0.53,-0.90+yr,0);

    glVertex3f(0.10, -0.85+yr, 0.0);
    glVertex3f(0.08, -0.55+yr, 0.0);
    glVertex3f(0.2, -0.40+yr, 0.0);
    glVertex3f(0.15,-0.75+yr,0);

    glVertex3f(0.20, -0.45+yr, 0.0);
    glVertex3f(0.08, -0.55+yr, 0.0);
    glVertex3f(0.22, -0.60+yr, 0.0);
    glVertex3f(0.09,-0.5+yr,0);

    glVertex3f(0.50, -0.45+yr, 0.0);
    glVertex3f(0.48, -0.65+yr, 0.0);
    glVertex3f(0.25, -0.60+yr, 0.0);
    glVertex3f(0.55,-0.55+yr,0);

    glVertex3f(0.30, -0.20+yr, 0.0);
    glVertex3f(0.28, -0.14+yr, 0.0);
    glVertex3f(0.35, -0.06+yr, 0.0);
    glVertex3f(0.25,-0.20+yr,0.0);

    glVertex3f(0.10, -0.0+yr, 0.0);
    glVertex3f(0.15, -0.1+yr, 0.0);
    glVertex3f(0.25, -0.1+yr, 0.0);
    glVertex3f(0.35,-0.0+yr,0.0);


    glColor3ub(240,230,140);
    //Body

    glVertex3f(0.0, 0.0+yr, 0.0);

    glColor3ub(245,222,179);

    glVertex3f(0.0, -1.0+yr, 0.0);
    glVertex3f(0.6, -1.0+yr, 0.0);

    glColor3ub(176,196,222);
    glVertex3f(0.6,0.0+yr,0);






    //Eye
    glColor3ub(25,25,112);

    glVertex3f(-0.2,0.7+yr,0);
    glVertex3f(-0.0,0.7+yr,0);
    glVertex3f(-0.0,0.9+yr,0);
    glVertex3f(-0.2,0.9+yr,0);


    glVertex3f(0.0,0.7+yr,0);
    glVertex3f(0.0,0.9+yr,0);
    glVertex3f(0.2,1.1+yr,0);
    glVertex3f(0.2,0.7+yr,0);
//mouth
    glColor3ub(192,192+yr,192);
    glVertex3f(-0.1,0.5+yr,0);
    glVertex3f(-0.0,0.5+yr,0);
    glVertex3f(-0.1,0.40+yr,0);
    glVertex3f(-0.2,0.40+yr,0);

    //Head
    glColor3ub(165,42,42);

    glVertex3f(-0.2,0.1+yr,0);
    glVertex3f(1.0,0.5+yr,0);
    glVertex3f(1.0,1.2+yr,0);
    glVertex3f(-0.2,1.4+yr,0);



    //neck
    glColor3ub(255,215,0);

    glVertex3f(0.2, 0.0+yr, 0.0);
    glVertex3f(0.4, 0.0+yr, 0.0);
    glVertex3f(0.4, 0.5+yr, 0.0);
    glVertex3f(0.2,0.5+yr,0);

    //Thai
    glVertex3f(0.2, -1.0+yr, 0.0);
    glVertex3f(0.4, -1.0+yr, 0.0);
    glVertex3f(0.4, -1.65+yr, 0.0);
    glVertex3f(0.2,-1.65+yr,0);
    glEnd();

    glPopMatrix(); //Undo the move to the center of the trapezoid

    glPushMatrix(); //Save the transformations performed thus far
    //glTranslatef(1.0, -1.0, 0.0);
    //glScalef(2.5,2.5,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
    //Leg



    glTranslatef(0.3, -1.7, 0.0);
    //glRotatef(_ang_tri ,0.0, 0.0, 1.0);

    glBegin(GL_POLYGON);

    glColor3ub(0,0,0);

    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y+yr);
    }
    glEnd();


    glBegin(GL_POLYGON);

    glColor3ub(105,112,142);

    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.3;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y+yr);
    }
    glEnd();




    glBegin(GL_POLYGON);

    glColor3ub(155,0,0);

    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.45;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y+yr);
    }
    glEnd();

    glPopMatrix(); //Undo the move to the center of the trapezoid
    glPopMatrix();


    ///Character
    glPushMatrix();
    glScalef(0.3,0.3,0);
    glTranslatef(6.0+ch, -7.0, 0.0);


    glPushMatrix(); //Save the current state of transformations

    glTranslatef(-0.1, 0.6, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)


    /// bru

    glColor3ub(105,105,105);
    glBegin(GL_QUADS);

    glVertex3f(-0.20, 01.40, 0.0);
    glVertex3f(-0.10, 01.45, 0.0);
    glVertex3f(0.03,  01.44, 0.0);
    glVertex3f(0.01, 01.42,0);


    glVertex3f(-0.20, 01.40, 0.0);
    glVertex3f(-0.10, 01.45, 0.0);
    glVertex3f(-0.3,  01.44, 0.0);
    glVertex3f(-0.35, 01.32,0);



    //horne
    glColor3ub(255,0,0);



    glVertex3f(-0.4, 02.10, 0.0);
    glVertex3f(-0.12, 01.55, 0.0);
    glVertex3f(-0.3,  01.55, 0.0);
    glVertex3f(-0.4, 02.10,0);


    glVertex3f(0.08, 02.0, 0.0);
    glVertex3f(-0.2, 01.55, 0.0);
    glVertex3f(0.0,  01.55, 0.0);
    glVertex3f(0.08, 02.0,0);


    glVertex3f(-0.2, 02.0, 0.0);
    glVertex3f(-0.2, 01.55, 0.0);
    glVertex3f(0.0,  01.55, 0.0);
    glVertex3f(-0.2, 02.0,0);

    glVertex3f(0.22, 02.0, 0.0);
    glVertex3f(-0.09, 01.55, 0.0);
    glVertex3f(0.1,  01.55, 0.0);
    glVertex3f(0.22, 02.0,0);



    glVertex3f(0.30, 02.0, 0.0);
    glVertex3f(0.25, 01.55, 0.0);
    glVertex3f(0.05,  01.55, 0.0);
    glVertex3f(0.30, 02.0,0);


    glVertex3f(0.50, 02.0, 0.0);
    glVertex3f(0.4, 01.55, 0.0);
    glVertex3f(0.1,  01.55, 0.0);
    glVertex3f(0.50, 02.0,0);


    glVertex3f(0.80, 02.0, 0.0);
    glVertex3f(0.5, 01.55, 0.0);
    glVertex3f(0.3,  01.55, 0.0);
    glVertex3f(0.80, 02.0,0);

///mouth


    glVertex3f(-0.45, 0.95, 0.0);
    glVertex3f(-0.1, 0.8, 0.0);
    glVertex3f(-0.35,  0.85, 0.0);
    glVertex3f(-0.32, 0.90,0);


    glVertex3f(0.45, 01.85, 0.0);
    glVertex3f(0.1, 0.7, 0.0);
    glVertex3f(0.35,  0.7, 0.0);
    glVertex3f(0.32, 01.80,0);

    glColor3ub(105,105,105);

    glVertex3f(0.6, 01.58, 0.0);
    glVertex3f(0.6, 0.75, 0.0);
    glVertex3f(0.35,  0.6, 0.0);
    glVertex3f(0.35, 01.58,0);


    glVertex3f(0.7, 01.40, 0.0);
    glVertex3f(0.7, 0.85, 0.0);
    glVertex3f(0.5,  0.5, 0.0);
    glVertex3f(0.5, 01.58,0);







    glEnd();


    glPopMatrix();


    glPushMatrix(); //Save the current state of transformations
    //hand
    glTranslatef(-0.3, 1.85, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)
    glColor3ub(255,0,0);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();

    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
    //Head
    glTranslatef(0.0, 1.75, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)
    glColor3ub(173,255,47);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/10;
        float r=0.60;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();



    glPopMatrix(); //Undo the move to the center of the triangle


    glPushMatrix(); //Save the current state of transformations
    //hand
    glTranslatef(-0.1, 0.6, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)
    glColor3ub(0,0,205);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.15;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,255,255);

    glVertex3f(0.0,-0.1, 0.0);

    glColor3ub(75,0,130);
    glVertex3f(-0.7, -0.1, 0.0);
    glVertex3f(-0.7,0.1, 0.0);

    glColor3ub(0,255,255);
    glVertex3f(0.0,0.1,0);

    glColor3ub(188,143,143);

    glVertex3f(-0.7, -0.1, 0.0);
    glVertex3f(-0.7,0.1, 0.0);
    glVertex3f(-1.0, 0.3, 0.0);
    glVertex3f(-1.0,-0.3, 0.0);

    /// nick
    glColor3ub(165,42,42);
    glVertex3f(-0.2, 0.6, 0.0);
    glVertex3f(-0.2, 0.4, 0.0);
    glVertex3f(0.40,  0.4, 0.0);
    glVertex3f(0.40, 0.6,0);

    glEnd();


    glPopMatrix();


    ///Bullet

    glPushMatrix(); //Save the transformations performed thus far
    glTranslatef(x1, xy1, 0.0);
    glColor3ub(226,104,34);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.17;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();


    glPopMatrix();

    ///BulletEnd


    glPushMatrix(); //Save the current state of transformations
    //body
    glTranslatef(0.0, 1.2, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)


    glBegin(GL_QUADS);
    glColor3ub(184,134,11);
    glVertex3f(-0.53, -0.2, 0.0);
    glColor3ub(255,215,0);
    glVertex3f(0.53, -0.2, 0.0);
    glVertex3f(0.53,-1.6, 0.0);
    glColor3ub(184,134,11);
    glVertex3f(-0.53,-1.6,0);


    glEnd();


    glPopMatrix(); //Undo the move to the center of the triangle


    glPushMatrix(); //Save the current state of transformations
    //leg
    glTranslatef(-0.40, -0.65, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)

    glColor3ub(30,144,255);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();


    glColor3ub(139,69,19);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.25;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();


    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
    //leg
    glTranslatef(0.4, -0.65, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)


    glColor3ub(30,144,255);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }

    glEnd();




    glColor3ub(139,69,19);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.25;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }

    glEnd();



    glPopMatrix();

    glPopMatrix();

///tree
    glPushMatrix();
    glBegin(GL_QUADS);

    glColor3ub(139,69,19);
    glVertex3f(-1.2-3*.06 ,-1.125+.075, 0.0);
    glVertex3f(-1.2-3*.06,-.75+2.5*.075, 0.0);
    glColor3ub(218,165,32);
    glVertex3f(-1.2-2*.06, -.75+2.5*.075, 0.0);
    glVertex3f(-1.2-2*.06, -1.125+.075, 0.0);


    glEnd();
    glBegin(GL_POLYGON);

    glColor3ub(0,100,0);
    glVertex3f(-1.2-2.5*.06 ,-.75+2.1*.075, 0.0);
    glVertex3f(-1.5-2.1*.06,-.375+1.5*.075, 0.0);
    glColor3ub(50,205,50);
    glVertex3f(-1.5-1.2*.06, 0-.5*.075, 0.0);
    glVertex3f(-1.2-2.5*.06, -.375+1.2*.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(-1.2+2.1*.06, 0-.5*.075, 0.0);
    glVertex3f(-.9-2.5*.06,-.375+1.5*.075, 0.0);

    glBegin(GL_POLYGON);

    glColor3ub(0,100,0);
    glVertex3f(-1.2-2.5*.06, -.375+1.2*.075, 0.0);
    glVertex3f(-1.5-.4*.06,-.0-1*.075, 0.0);
    glColor3ub(50,205,50);
    glVertex3f(-1.5+.6*.06, 0+2.5*.075, 0.0);
    glVertex3f(-1.2-2.3*.06, -.0+.2*.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(-1.2+.2*.06,0+2.5*.075, 0.0);
    glVertex3f(-1.2+1.2*.06,-.0-1*.075, 0.0);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(0,100,0);
    glVertex3f(-1.2-2.5*.06, -.0+.2*.075, 0.0);
    glVertex3f(-1.5+1.0*.06,-.0+1.5*.075, 0.0);
    glColor3ub(50,205,50);
    glVertex3f(-1.2-2.2*.06, 0.375+0*.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(-1.2-.3*.06, -.0+1.7*.075, 0.0);

    glEnd();
///2nd tree

    glBegin(GL_POLYGON);

    glColor3ub(0,100,0);
    glVertex3f(1.2-2.5*.06, -.375-2.7*.075, 0.0);
    glVertex3f(.9-3*.06,-.0-3*.075, 0.0);
    glColor3ub(50,205,50);
    glVertex3f(.9-1*.06, 0+0*.075, 0.0);
    glVertex3f(1.2-2.5*.06, -.0-3.3*.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(1.2+2.2*.06,0+0*.075, 0.0);
    glVertex3f(1.2+3.3*.06,-.0-3*.075, 0.0);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3ub(0,100,0);
    glVertex3f(1.2-2.5*.06, -.0+.3*.075, 0.0);
    glVertex3f(.9+1.5*.06,-.0+2.5*.075, 0.0);
    glColor3ub(50,205,50);
    glVertex3f(1.2-2.0*.06, 0.375+1.0*.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(1.2-.8*.06, -.0+2.5*.075, 0.0);


    glEnd();

    glBegin(GL_POLYGON);

    glColor3ub(0,100,0);
    glVertex3f(1.2-2.7*.06, -.0-3.3*.075, 0.0);
    glVertex3f(.9-.4*.06,-.0-.9*.075, 0.0);
    glColor3ub(50,205,50);
    glVertex3f(.9+1*.06, 0+3.2*.075, 0.0);
    glVertex3f(1.2-2.3*.06, -.0+1.3*.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(1.2-.2*.06,0+3.2*.075, 0.0);
    glVertex3f(1.2+1.20*.06,-.0-.9*.075, 0.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex3f(1.2-2*.06, -1.125+.075, 0.0);
    glVertex3f(1.2-3.0*.06,-1.125+.075, 0.0);
    glColor3ub(184,134,11);
    glVertex3f(1.2-3.0*.06, -.75+2.5*.075, 0.0);
    glColor3ub(218,165,32);
    glVertex3f(1.2-2*.06, -.75+2.5*.075, 0.0);


    glEnd();

    glPopMatrix();


///fence


    glPushMatrix(); //Save the transformations performed thus far
    glTranslatef(0.0, 0.0, 0.0);


    ///row fence

    ///-3 to 1st pillar
    glColor3ub(165,42,42);
    glBegin(GL_QUADS);


    glVertex3f(-3 ,0, 0.0);
    glVertex3f(-3,-.075*1, 0.0);
    glVertex3f(-2.4, -.075*1, 0.0);
    glVertex3f(-2.4, 0, 0.0);


    glEnd();
    glBegin(GL_QUADS);


    glVertex3f(-3 ,-.075*2, 0.0);
    glVertex3f(-3,-.075*3, 0.0);
    glVertex3f(-2.4, -.075*3, 0.0);
    glVertex3f(-2.4, -.075*2, 0.0);


    glEnd();


    glBegin(GL_QUADS);


    glVertex3f(-3 ,-.075*4, 0.0);
    glVertex3f(-3,-.075*5, 0.0);
    glVertex3f(-2.4, -.075*5, 0.0);
    glVertex3f(-2.4, -.075*4, 0.0);


    glEnd();

    glBegin(GL_QUADS);


    glVertex3f(-3 ,-.075*6, 0.0);
    glVertex3f(-3,-.075*7, 0.0);
    glVertex3f(-2.4, -.075*7, 0.0);
    glVertex3f(-2.4, -.075*6, 0.0);


    glEnd();

    glBegin(GL_QUADS);


    glVertex3f(-3 ,-.075*8, 0.0);
    glVertex3f(-3,-.075*9, 0.0);
    glVertex3f(-2.4, -.075*9, 0.0);
    glVertex3f(-2.4, -.075*8, 0.0);


    glEnd();

    ///row of 1st and middle pillar

    glBegin(GL_QUADS);


    glVertex3f(-1.2 ,0, 0.0);
    glVertex3f(-1.2,-.075*1, 0.0);
    glVertex3f(-0, -.075*1, 0.0);
    glVertex3f(-0, 0, 0.0);


    glEnd();
    glBegin(GL_QUADS);


    glVertex3f(-1.2 ,-.075*2, 0.0);
    glVertex3f(-1.2,-.075*3, 0.0);
    glVertex3f(-0, -.075*3, 0.0);
    glVertex3f(-0, -.075*2, 0.0);


    glEnd();
    glBegin(GL_QUADS);


    glVertex3f(-1.2 ,-.075*4, 0.0);
    glVertex3f(-1.2,-.075*5, 0.0);
    glVertex3f(-0, -.075*5, 0.0);
    glVertex3f(-0, -.075*4, 0.0);


    glEnd();
    glBegin(GL_QUADS);


    glVertex3f(-1.2 ,-.075*6, 0.0);
    glVertex3f(-1.2,-.075*7, 0.0);
    glVertex3f(-0, -.075*7, 0.0);
    glVertex3f(-0, -.075*6, 0.0);


    glEnd();
    glBegin(GL_QUADS);


    glVertex3f(-1.2 ,-.075*8, 0.0);
    glVertex3f(-1.2,-.075*9, 0.0);
    glVertex3f(-0, -.075*9, 0.0);
    glVertex3f(-0, -.075*8, 0.0);


    glEnd();


    ///row of 2nd & 3rd pillar

    glBegin(GL_QUADS);


    glVertex3f(1.2 ,0, 0.0);
    glVertex3f(1.2,-.075*1, 0.0);
    glVertex3f(1.8, -.075*1, 0.0);
    glVertex3f(1.8, -.075*0, 0.0);


    glEnd();
    glBegin(GL_QUADS);


    glVertex3f(1.2 ,-.075*2, 0.0);
    glVertex3f(1.2,-.075*3, 0.0);
    glVertex3f(1.8, -.075*3, 0.0);
    glVertex3f(1.8, -.075*2, 0.0);


    glEnd();

    glBegin(GL_QUADS);


    glVertex3f(1.2 ,-.075*4, 0.0);
    glVertex3f(1.2,-.075*5, 0.0);
    glVertex3f(1.8, -.075*5, 0.0);
    glVertex3f(1.8, -.075*4, 0.0);


    glEnd();
    glBegin(GL_QUADS);


    glVertex3f(1.2 ,-.075*6, 0.0);
    glVertex3f(1.2,-.075*7, 0.0);
    glVertex3f(1.8, -.075*7, 0.0);
    glVertex3f(1.8, -.075*6, 0.0);


    glEnd();
    glBegin(GL_QUADS);


    glVertex3f(1.2 ,-.075*8, 0.0);
    glVertex3f(1.2,-.075*9, 0.0);
    glVertex3f(1.8, -.075*9, 0.0);
    glVertex3f(1.8, -.075*8, 0.0);


    glEnd();
    glColor3ub(244,164,96);
    glBegin(GL_QUADS);


    ///column fence
    glVertex3f(-2.4-3*.06 ,-.075*10, 0.0);
    glVertex3f(-2.4-2*.06 ,-.075*10, 0.0);
    glVertex3f(-2.4-2*.06, .075*2, 0.0);
    glVertex3f(-2.4-3*.06, .075*2, 0.0);


    glEnd();
    glBegin(GL_QUADS);


    glVertex3f(-2.4-5*.06 ,-.075*10, 0.0);
    glVertex3f(-2.4-4*.06 ,-.075*10, 0.0);
    glVertex3f(-2.4-4*.06, .075*2, 0.0);
    glVertex3f(-2.4-5*.06, .075*2, 0.0);


    glEnd();

    glBegin(GL_QUADS);


    glVertex3f(-2.4-7*.06 ,-.075*10, 0.0);
    glVertex3f(-2.4-6*.06 ,-.075*10, 0.0);
    glVertex3f(-2.4-6*.06, .075*2, 0.0);
    glVertex3f(-2.4-7*.06, .075*2, 0.0);


    glEnd();


    glBegin(GL_QUADS);


    glVertex3f(-1.2+1*.06 ,-.075*10, 0.0);
    glVertex3f(-1.2+2*.06 ,-.075*10, 0.0);
    glVertex3f(-1.2+2*.06, .075*2, 0.0);
    glVertex3f(-1.2+1*.06, .075*2, 0.0);


    glEnd();
    glBegin(GL_QUADS);


    glVertex3f(-1.2+3*.06 ,-.075*10, 0.0);
    glVertex3f(-1.2+4*.06 ,-.075*10, 0.0);
    glVertex3f(-1.2+4*.06, .075*2, 0.0);
    glVertex3f(-1.2+3*.06, .075*2, 0.0);


    glEnd();
    glBegin(GL_QUADS);


    glVertex3f(-1.2+5*.06 ,-.075*10, 0.0);
    glVertex3f(-1.2+6*.06 ,-.075*10, 0.0);
    glVertex3f(-1.2+6*.06, .075*2, 0.0);
    glVertex3f(-1.2+5*.06, .075*2, 0.0);


    glEnd();
    glBegin(GL_QUADS);


    glVertex3f(-1.2+7*.06 ,-.075*10, 0.0);
    glVertex3f(-1.2+8*.06 ,-.075*10, 0.0);
    glVertex3f(-1.2+8*.06, .075*2, 0.0);
    glVertex3f(-1.2+7*.06, .075*2, 0.0);


    glEnd();
    glBegin(GL_QUADS);


    glVertex3f(-1.2+9*.06 ,-.075*10, 0.0);
    glVertex3f(-1.2+10*.06 ,-.075*10, 0.0);
    glVertex3f(-1.2+10*.06, .075*2, 0.0);
    glVertex3f(-1.2+9*.06, .075*2, 0.0);


    glEnd();

    glBegin(GL_QUADS);


    glVertex3f(-1.2+11*.06 ,-.075*10, 0.0);
    glVertex3f(-1.2+12*.06 ,-.075*10, 0.0);
    glVertex3f(-1.2+12*.06, .075*2, 0.0);
    glVertex3f(-1.2+11*.06, .075*2, 0.0);


    glEnd();
    glBegin(GL_QUADS);


    glVertex3f(-1.2+13*.06 ,-.075*10, 0.0);
    glVertex3f(-1.2+14*.06 ,-.075*10, 0.0);
    glVertex3f(-1.2+14*.06, .075*2, 0.0);
    glVertex3f(-1.2+13*.06, .075*2, 0.0);


    glEnd();
    glBegin(GL_QUADS);


    glVertex3f(-1.2+15*.06 ,-.075*10, 0.0);
    glVertex3f(-1.2+16*.06 ,-.075*10, 0.0);
    glVertex3f(-1.2+16*.06, .075*2, 0.0);
    glVertex3f(-1.2+15*.06, .075*2, 0.0);


    glEnd();
    glBegin(GL_QUADS);


    glVertex3f(-1.2+17*.06 ,-.075*10, 0.0);
    glVertex3f(-1.2+18*.06 ,-.075*10, 0.0);
    glVertex3f(-1.2+18*.06, .075*2, 0.0);
    glVertex3f(-1.2+17*.06, .075*2, 0.0);


    glEnd();

    ///column fence of 2nd and 3rd pillar

    glBegin(GL_QUADS);


    glVertex3f(1.2+1*.06 ,-.075*10, 0.0);
    glVertex3f(1.2+2*.06 ,-.075*10, 0.0);
    glVertex3f(1.2+2*.06, .075*2, 0.0);
    glVertex3f(1.2+1*.06, .075*2, 0.0);


    glEnd();
    glBegin(GL_QUADS);


    glVertex3f(1.2+3*.06 ,-.075*10, 0.0);
    glVertex3f(1.2+4*.06 ,-.075*10, 0.0);
    glVertex3f(1.2+4*.06, .075*2, 0.0);
    glVertex3f(1.2+3*.06, .075*2, 0.0);


    glEnd();
    glBegin(GL_QUADS);


    glVertex3f(1.2+5*.06 ,-.075*10, 0.0);
    glVertex3f(1.2+6*.06 ,-.075*10, 0.0);
    glVertex3f(1.2+6*.06, .075*2, 0.0);
    glVertex3f(1.2+5*.06, .075*2, 0.0);


    glEnd();
    glBegin(GL_QUADS);


    glVertex3f(1.2+7*.06 ,-.075*10, 0.0);
    glVertex3f(1.2+8*.06 ,-.075*10, 0.0);
    glVertex3f(1.2+8*.06, .075*2, 0.0);
    glVertex3f(1.2+7*.06, .075*2, 0.0);


    glEnd();
    glBegin(GL_QUADS);


    glVertex3f(1.2+9*.06 ,-.075*10, 0.0);
    glVertex3f(1.2+10*.06 ,-.075*10, 0.0);
    glVertex3f(1.2+10*.06, .075*2, 0.0);
    glVertex3f(1.2+9*.06, .075*2, 0.0);


    glEnd();

    glPopMatrix();

    glPushMatrix();
///1st lamp topping
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(-.9-0.5*.06 ,1.125+1*.075, 0.0);
    glVertex3f(-.9-2*.06 ,1.125+0.5*.075, 0.0);
    glVertex3f(-1.2+1.5*.06 ,1.125+0.5*.075, 0.0);
    glVertex3f(-1.2-.03,1.125+1*.075, 0.0);
    glVertex3f(-1.2+1.5*.06 ,1.125+1.5*.075, 0.0);

    glVertex3f(-1.2+3*.06 ,1.125+1.5*.075, 0.0);


    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(-1.2+1.5*.06 ,1.125+1.5*.075, 0.0);
    glVertex3f(-1.2+1.5*.06 ,1.125+2.5*.075, 0.0);
    glVertex3f(-1.2+3*.06 ,1.125+2.5*.075, 0.0);
    glVertex3f(-1.2+3*.06 ,1.125+1.5*.075, 0.0);

    glEnd();


///lamp stand
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);


    glVertex3f(-.9-3.6*.06 ,-.75, 0.0);
    glVertex3f(-.9-3.6*.06 ,.75+2*.075, 0.0);
    glVertex3f(-.9-2.8*.06 ,.75+2*.075, 0.0);
    glVertex3f(-.9-2.8*.06 ,-.75+0*.075, 0.0);

    glEnd();

///lamp light

    glBegin(GL_LINE_STRIP);
    glColor3ub(0,0,0);
    glVertex3f(-.9-3.2*.06 ,.75+1.5*.075, 0.0);
    glVertex3f(-1.2+.3*.06 ,1.125-1.5*.075, 0.0);
    glVertex3f(-1.2-.03,1.125+1*.075, 0.0);
    glVertex3f(-1.2+1.5*.06 ,1.125+0.5*.075, 0.0);
    //glColor3ub(255,255,0);
    glVertex3f(-.9-2*.06 ,1.125+0.5*.075, 0.0);
    glVertex3f(-.9-0.5*.06 ,1.125+1*.075, 0.0);
    glVertex3f(-.9-01.2*.06 ,1.125-1.*.075, 0.0);
    glVertex3f(-.9-3.2*.06 ,.75+1.5*.075, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,215,0);
    glVertex3f(-.9-3.2*.06 ,.75+1.5*.075, 0.0);
    glVertex3f(-1.2+.3*.06 ,1.125-1.5*.075, 0.0);
    glVertex3f(-1.2-.03,1.125+1*.075, 0.0);
    glVertex3f(-1.2+1.5*.06 ,1.125+0.5*.075, 0.0);
    glColor3ub(255,255,0);
    glVertex3f(-.9-2*.06 ,1.125+0.5*.075, 0.0);
    glVertex3f(-.9-0.5*.06 ,1.125+1*.075, 0.0);
    glVertex3f(-.9-01.2*.06 ,1.125-1.*.075, 0.0);
///***
    glEnd();
///2ND lamp stand


    glBegin(GL_QUADS);

    glColor3ub(0,0,0);
    glVertex3f(1.2+1.5*.06 ,-.75, 0.0);
    glVertex3f(1.2+1.5*.06 ,.75+2*.075, 0.0);
    glVertex3f(1.2+2*.06 ,.75+2*.075, 0.0);
    glVertex3f(1.2+2*.06  ,-.75+0*.075, 0.0);

    glEnd();


///light
    glBegin(GL_LINE_STRIP);
    glColor3ub(0,0,0);
    glVertex3f(1.2+1.75*.06 ,.75+1.5*.075, 0.0);
    glVertex3f(1.2+.1*.06 ,.75+3*.075, 0.0);
    glVertex3f(1.2-.03,1.125+1*.075, 0.0);
    glVertex3f(1.2+1.8*.06 ,1.125+0.5*.075, 0.0);
    //glColor3ub(255,255,0);
    glVertex3f(1.2+3.5*.06 ,1.125+0.5*.075, 0.0);
    glVertex3f(1.5-0.2*.06 ,1.125+1*.075, 0.0);
    glVertex3f(1.5-1.2*.06 ,.75+3.*.075, 0.0);

    glVertex3f(1.2+1.75*.06 ,.75+1.5*.075, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255,215,0);
    glVertex3f(1.2+1.75*.06 ,.75+1.5*.075, 0.0);
    glVertex3f(1.2+.1*.06 ,.75+3*.075, 0.0);
    glVertex3f(1.2-.03,1.125+1*.075, 0.0);
    glVertex3f(1.2+1.8*.06 ,1.125+0.5*.075, 0.0);
    glColor3ub(255,255,0);
    glVertex3f(1.2+3.5*.06 ,1.125+0.5*.075, 0.0);
    glVertex3f(1.5-0.2*.06 ,1.125+1*.075, 0.0);
    glVertex3f(1.5-1.2*.06 ,.75+3.*.075, 0.0);

    glEnd();

///2nd lamp topping
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(1.5-0.2*.06 ,1.125+1*.075, 0.0);
    glVertex3f(1.2+3.5*.06 ,1.125+0.5*.075, 0.0);
    glVertex3f(1.2+1.8*.06 ,1.125+0.5*.075, 0.0);
    glVertex3f(1.2-.03,1.125+1*.075, 0.0);
    glVertex3f(1.2+1.8*.06 ,1.125+1.8*.075, 0.0);
    glVertex3f(1.2+2.1*.06 ,1.125+1.8*.075, 0.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(1.2+1.5*.06 ,1.125+1.8*.075, 0.0);
    glVertex3f(1.2+1.5*.06 ,1.125+2.8*.075, 0.0);
    glVertex3f(1.2+2.9*.06 ,1.125+2.8*.075, 0.0);
    glVertex3f(1.2+2.9*.06 ,1.125+1.6*.075, 0.0);

    glEnd();

    glPopMatrix();


    ///Middle pillar
    glPushMatrix(); //Save the transformations performed thus far

    glScalef(1,0.7,0);
    glTranslatef(0.0, -.375, 0.0); //M //Move to the center of the trapezoid
///upper frame

    glBegin(GL_QUADS);
    glColor3ub(0,0,128);
    //glScalef(0.0,1.5,0.0);
    glVertex3f(-0.06, 1.875, 0.0);
    glVertex3f(1.26, 1.875, 0.0);
    glVertex3f(1.26, 2.25, 0.0);
    glVertex3f(-.06, 2.25, 0.0);


    glEnd();

    ///box
    glBegin(GL_QUADS);
    glColor3ub(75,0,130);

    glVertex3f(.3, 0, 0.0);
    glVertex3f(0.9, 0, 0.0);
    glVertex3f(.9, 1.5, 0.0);
    glVertex3f(.3, 1.5, 0.0);


    glEnd();

    ///lines
    glBegin(GL_LINES);
    glColor3ub(139,0,0);

    glVertex3f(0, 3*.075, 0.0);
    glVertex3f(1.2, 3*.075, 0.0);

    glVertex3f(0, 6*.075, 0.0);
    glVertex3f(1.2, 6*.075, 0.0);

    glVertex3f(0, -3*.075, 0.0);
    glVertex3f(1.2, -3*.075, 0.0);

    glVertex3f(0, -6*.075, 0.0);
    glVertex3f(1.2, -6*.075, 0.0);

    glVertex3f(0,0 , 0.0);
    glVertex3f(1.2, 0, 0.0);

    glVertex3f(0, 9*.075, 0.0);
    glVertex3f(1.2, 9*.075, 0.0);

    glVertex3f(0, 12*.075, 0.0);
    glVertex3f(1.2, 12*.075, 0.0);

    glVertex3f(0, 15*.075, 0.0);
    glVertex3f(1.2, 15*.075, 0.0);

    glVertex3f(0, 18*.075, 0.0);
    glVertex3f(1.2, 18*.075, 0.0);

    glVertex3f(0, 21*.075, 0.0);
    glVertex3f(1.2, 21*.075, 0.0);

    glVertex3f(0, 24*.075, 0.0);
    glVertex3f(1.2, 24*.075, 0.0);

    glVertex3f(0, 27*.075, 0.0);
    glVertex3f(1.2, 27*.075, 0.0);

    glVertex3f(0, -9*.075, 0.0);
    glVertex3f(1.2, -9*.075, 0.0);

    glVertex3f(0+.06*4, -9*.075, 0.0);
    glVertex3f(0+.06*4, -6*.075, 0.0);

    glVertex3f(0+.06*10, -9*.075, 0.0);
    glVertex3f(0+.06*10, -6*.075, 0.0);

    glVertex3f(0+.06*16, -9*.075, 0.0);
    glVertex3f(0+.06*16, -6*.075, 0.0);

    glVertex3f(0+.06*2, -9*.075, 0.0);
    glVertex3f(0+.06*2, -10*.075, 0.0);

    glVertex3f(0+.06*8, -9*.075, 0.0);
    glVertex3f(0+.06*8, -10*.075, 0.0);


    glVertex3f(0+.06*14, -9*.075, 0.0);
    glVertex3f(0+.06*14, -10*.075, 0.0);

    glVertex3f(0+.06*1, -6*.075, 0.0);
    glVertex3f(0+.06*1, -3*.075, 0.0);

    glVertex3f(0+.06*6, -6*.075, 0.0);
    glVertex3f(0+.06*6, -3*.075, 0.0);

    glVertex3f(0+.06*12, -6*.075, 0.0);
    glVertex3f(0+.06*12, -3*.075, 0.0);

    glVertex3f(0+.06*18, -6*.075, 0.0);
    glVertex3f(0+.06*18, -3*.075, 0.0);

    glVertex3f(0+.06*3, -3*.075, 0.0);
    glVertex3f(0+.06*3, 0, 0.0);

    glVertex3f(0+.06*9, -3*.075, 0.0);
    glVertex3f(0+.06*9, 0, 0.0);

    glVertex3f(0+.06*13, -3*.075, 0.0);
    glVertex3f(0+.06*13, 0, 0.0);

    glVertex3f(0+.06*17, -3*.075, 0.0);
    glVertex3f(0+.06*17, 0, 0.0);

    glVertex3f(0+.06*2, 3*.075, 0.0);
    glVertex3f(0+.06*2, 0, 0.0);

    glVertex3f(0+.06*18, 3*.075, 0.0);
    glVertex3f(0+.06*18, 0, 0.0);


    glVertex3f(0+.06*1, 3*.075, 0.0);
    glVertex3f(0+.06*1, 6*.075, 0.0);

    glVertex3f(0+.06*19, 3*.075, 0.0);
    glVertex3f(0+.06*19, 6*.075, 0.0);

    glVertex3f(0+.06*3, 6*.075, 0.0);
    glVertex3f(0+.06*3, 9*.075, 0.0);

    glVertex3f(0+.06*16, 6*.075, 0.0);
    glVertex3f(0+.06*16, 9*.075, 0.0);

    glVertex3f(0+.06*1.5, 12*.075, 0.0);
    glVertex3f(0+.06*1.5, 9*.075, 0.0);

    glVertex3f(0+.06*18.5, 12*.075, 0.0);
    glVertex3f(0+.06*18.5, 9*.075, 0.0);

    glVertex3f(0+.06*3.5, 12*.075, 0.0);
    glVertex3f(0+.06*3.5, 15*.075, 0.0);

    glVertex3f(0+.06*16.5, 12*.075, 0.0);
    glVertex3f(0+.06*16.5, 15*.075, 0.0);

    glVertex3f(0+.06*2.05, 18*.075, 0.0);
    glVertex3f(0+.06*2.05, 15*.075, 0.0);

    glVertex3f(0+.06*18.05, 18*.075, 0.0);
    glVertex3f(0+.06*18.05, 15*.075, 0.0);

    glVertex3f(0+.06*15.59, 18*.075, 0.0);
    glVertex3f(0+.06*15.59, 21*.075, 0.0);

    glVertex3f(0+.06*11, 18*.075, 0.0);
    glVertex3f(0+.06*11, 21*.075, 0.0);

    glVertex3f(0+.06*4, 18*.075, 0.0);
    glVertex3f(0+.06*4, 21*.075, 0.0);

    glVertex3f(0+.06*2, 24*.075, 0.0);
    glVertex3f(0+.06*2, 21*.075, 0.0);

    glVertex3f(0+.06*7, 24*.075, 0.0);
    glVertex3f(0+.06*7, 21*.075, 0.0);

    glVertex3f(0+.06*13, 24*.075, 0.0);
    glVertex3f(0+.06*13, 21*.075, 0.0);

    glVertex3f(0+.06*18, 24*.075, 0.0);
    glVertex3f(0+.06*18, 21*.075, 0.0);

    glVertex3f(0+.06*15, 24*.075, 0.0);
    glVertex3f(0+.06*15, 25*.075, 0.0);

    glVertex3f(0+.06*9, 24*.075, 0.0);
    glVertex3f(0+.06*9, 25*.075, 0.0);

    glVertex3f(0+.06*5, 24*.075, 0.0);
    glVertex3f(0+.06*5, 25*.075, 0.0);


    glEnd();

    ///body
    glBegin(GL_QUADS);
    glColor3ub(0,191,255);

    glVertex3f(0, -0.75, 0.0);
    glVertex3f(1.2, -0.75, 0.0);
    glVertex3f(1.2, 2.25, 0.0);
    glVertex3f(0.0, 2.25, 0.0);


    glEnd();




    glPopMatrix();


    ///3rd pillar

    glPushMatrix(); //Save the transformations performed thus far
    glTranslatef(0.0, 0.0, 0.0);

    ///upper box

    glBegin(GL_QUADS);
    glColor3ub(255,215,0);

    glVertex3f(2.1 ,.15, 0.0);
    glVertex3f(2.7, .15, 0.0);
    glVertex3f(2.7, .6, 0.0);
    glVertex3f(2.1, .6, 0.0);


    glEnd();


///lower box

    glBegin(GL_QUADS);
    glColor3ub(255,215,0);

    glVertex3f(2.1 ,-.075, 0.0);
    glVertex3f(2.1, -.525, 0.0);
    glVertex3f(2.7, -.525, 0.0);
    glVertex3f(2.7, -.075, 0.0);


    glEnd();

    ///lines

    glBegin(GL_LINES);
    glColor3ub(255,228,225);

    glVertex3f(1.8 ,0, 0.0);
    glVertex3f(3, 0, 0.0);


    glVertex3f(1.8, .075*3, 0.0);
    glVertex3f(3, .075*3, 0.0);

    glVertex3f(1.8, .075*6, 0.0);
    glVertex3f(3, .075*6, 0.0);

    glVertex3f(1.8, .075*9, 0.0);
    glVertex3f(3, .075*9, 0.0);


    glVertex3f(1.8, -.075*3, 0.0);
    glVertex3f(3, -.075*3, 0.0);

    glVertex3f(1.8, -.075*6, 0.0);
    glVertex3f(3, -.075*6, 0.0);

    glVertex3f(1.8, -.075*9, 0.0);
    glVertex3f(3, -.075*9, 0.0);

    glVertex3f(1.8+3*.06, 0, 0.0);
    glVertex3f(1.8+3*.06, .075*3, 0.0);

    glVertex3f(1.8+9*.06, 0, 0.0);
    glVertex3f(1.8+9*.06, .075*3, 0.0);

    glVertex3f(1.8+15*.06, 0, 0.0);
    glVertex3f(1.8+15*.06, .075*3, 0.0);

    glVertex3f(1.8+17*.06,.075*6 , 0.0);
    glVertex3f(1.8+17*.06, .075*3, 0.0);

    glVertex3f(1.8+1.5*.06,.075*6 , 0.0);
    glVertex3f(1.8+1.5*.06, .075*3, 0.0);

    glVertex3f(1.8+3.2*.06,.075*6 , 0.0);
    glVertex3f(1.8+3.2*.06, .075*9, 0.0);

    glVertex3f(1.8+10.2*.06,.075*6 , 0.0);
    glVertex3f(1.8+10.2*.06, .075*9, 0.0);

    glVertex3f(1.8+16.2*.06,.075*6, 0.0);
    glVertex3f(1.8+16.2*.06, .075*9, 0.0);

    glVertex3f(1.8+13.2*.06,.075*10, 0.0);
    glVertex3f(1.8+13.2*.06, .075*9, 0.0);

    glVertex3f(1.8+5.2*.06,.075*10, 0.0);
    glVertex3f(1.8+5.2*.06, .075*9, 0.0);

    glVertex3f(1.8+1.2*.06,0, 0.0);
    glVertex3f(1.8+1.2*.06, -.075*3, 0.0);

    glVertex3f(1.8+7.2*.06,0, 0.0);
    glVertex3f(1.8+7.2*.06, -.075*3, 0.0);

    glVertex3f(1.8+13.5*.06,0, 0.0);
    glVertex3f(1.8+13.5*.06, -.075*3, 0.0);

    glVertex3f(1.8+17.5*.06,0, 0.0);
    glVertex3f(1.8+17.5*.06, -.075*3, 0.0);

    glVertex3f(1.8+15.5*.06,-.075*6, 0.0);
    glVertex3f(1.8+15.5*.06, -.075*3, 0.0);

    glVertex3f(1.8+3.5*.06,-.075*6, 0.0);
    glVertex3f(1.8+3.5*.06, -.075*3, 0.0);

    glVertex3f(1.8+5.5*.06,-.075*6, 0.0);
    glVertex3f(1.8+5.5*.06, -.075*9, 0.0);

    glVertex3f(1.8+1.5*.06,-.075*6, 0.0);
    glVertex3f(1.8+1.5*.06, -.075*9, 0.0);

    glVertex3f(1.8+12.5*.06,-.075*6, 0.0);
    glVertex3f(1.8+12.5*.06, -.075*9, 0.0);

    glVertex3f(1.8+16.5*.06,-.075*6, 0.0);
    glVertex3f(1.8+16.5*.06, -.075*9, 0.0);

    glVertex3f(1.8+8.5*.06,-.075*10, 0.0);
    glVertex3f(1.8+8.5*.06, -.075*9, 0.0);

    glVertex3f(1.8+3.5*.06,-.075*10, 0.0);
    glVertex3f(1.8+3.5*.06, -.075*9, 0.0);

    glVertex3f(1.8+14.5*.06,-.075*10, 0.0);
    glVertex3f(1.8+14.5*.06, -.075*9, 0.0);

    glEnd();

    ///main body
    glBegin(GL_QUADS);
    glColor3ub(220,20,70);

    glVertex3f(1.8, -.75, 0.0);
    glVertex3f(3, -.75, 0.0);
    glVertex3f(3, .75, 0.0);
    glVertex3f(1.8, .75, 0.0);


    glEnd();


    ///upper frame

    glBegin(GL_QUADS);
    glColor3ub(148,0,0);

    glVertex3f(1.74 ,.75, 0.0);
    glVertex3f(3, .75, 0.0);
    glVertex3f(3, 1.125, 0.0);
    glVertex3f(1.74, 1.125, 0.0);


    glEnd();

    glPopMatrix();


    ///1st pillar

    glPushMatrix(); //Save the transformations performed thus far
    glTranslatef(0.0, 0.0, 0.0);
    //glScalef(0.5,0.5,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
    ///box
    glBegin(GL_QUADS);
    glColor3ub(218,165,32);

    glVertex3f(-2.1,-.375, 0.0);
    glVertex3f(-1.5, -.375, 0.0);
    glVertex3f(-1.5, .75, 0.0);
    glVertex3f(-2.1, .75, 0.0);


    glEnd();

    ///lines
    glBegin(GL_LINES);
    glColor3ub(255,255,0);

    glVertex3f(-2.4,0, 0.0);
    glVertex3f(-1.2, 0, 0.0);

    glVertex3f(-2.4+.06,0, 0.0);
    glVertex3f(-2.4+.06, 0-.075-.075-.075, 0.0);

    glVertex3f(-1.2-.06-.06,0, 0.0);
    glVertex3f(-1.2-.06-.06, 0-.075-.075-.075, 0.0);

    glVertex3f(-2.4+.06+.06+.06+.06, 0-.075-.075-.075, 0.0);
    glVertex3f(-2.4+.06+.06+.06+.06, 0-.075-.075-.075-.075-.075, 0.0);

    glVertex3f(-1.2-.06-.06-.06-.06,0-.075-.075-.075, 0.0);
    glVertex3f(-1.2-.06-.06-.06-.06, 0-.075-.075-.075-.075-.075, 0.0);

    glVertex3f(-2.4+.06+.06+.06+.06+.06+.06+.06, 0-.075-.075-.0750-.075-.075, 0.0);
    glVertex3f(-2.4+.06+.06+.06+.06+.06+.06+.06, 0-.075-.075-.0750-.075-.075-.075-.075, 0.0);


    glVertex3f(-2.4+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06, 0-.075-.075-.0750-.075-.075, 0.0);
    glVertex3f(-2.4+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06, 0-.075-.075-.0750-.075-.075-.075-.075, 0.0);


    glVertex3f(-2.4+.06+.06+.06+.06,0-.075-.075-.075-.075-.075-.075-.075, 0.0);
    glVertex3f(-2.4+.06+.06+.06+.06, 0-.075-.075-.075-.075-.075-.075-.075-.075-.075, 0.0);

    glVertex3f(-2.4+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06,0-.075-.075-.075-.075-.075-.075-.075, 0.0);
    glVertex3f(-2.4+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06, 0-.075-.075-.075-.075-.075-.075-.075-.075-.075, 0.0);


    glVertex3f(-2.4+.06+.06+.06+.06+.06+.06+.06+.06,0-.075-.075-.075-.075-.075-.075-.075-.075-.075, 0.0);
    glVertex3f(-2.4+.06+.06+.06+.06+.06+.06+.06+.06, -.75, 0.0);


    glVertex3f(-1.2-.06-.06-.06-.06,0-.075-.075-.075-.075-.075-.075-.075-.075-.075, 0.0);
    glVertex3f(-1.2-.06-.06-.06-.06,-.75, 0.0);

    glVertex3f(-2.4+.06+.06+.06+.06,0+.075+.075+.075, 0.0);
    glVertex3f(-2.4+.06+.06+.06+.06, 0, 0.0);


    glVertex3f(-2.4+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06,0+.075+.075+.075, 0.0);
    glVertex3f(-2.4+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06+.06, 0, 0.0);

    glVertex3f(-2.4+.07,0+.075+.075+.075, 0.0);
    glVertex3f(-2.4+.07, 0+.075+.075+.075+.075+.075, 0.0);

    glVertex3f(-1.2-.06-.06,.075+.075+.075+.075+.075, 0.0);
    glVertex3f(-1.2-.06-.06,.075+.075+.075, 0.0);


    glVertex3f(-2.4+.06+.06+.06+.03,0+.075+.075+.075+.075+.075+.075+.075, 0.0);
    glVertex3f(-2.4+.06+.06+.06+.03,0+.075+.075+.075+.075+.075, 0.0);


    glVertex3f(-1.2-.06-.06-.06-.06,.075+.075+.075+.075+.075+.075+.075, 0.0);
    glVertex3f(-1.2-.06-.06-.06-.06,.075+.075+.075+.075+.075, 0.0);

    glVertex3f(-2.4+.06+.06,0+.075+.075+.075+.075+.075+.075+.075, 0.0);
    glVertex3f(-2.4+.06+.06,0+.075+.075+.075+.075+.075+.075+.075+.075+.075, 0.0);

    glVertex3f(-1.2-.06-.06-.06,0+.075+.075+.075+.075+.075+.075+.075, 0.0);
    glVertex3f(-1.2-.06-.06-.06,0+.075+.075+.075+.075+.075+.075+.075+.075+.075, 0.0);

    glVertex3f(-2.4+.06+.06+.06,11*.075, 0.0);
    glVertex3f(-2.4+.06+.06+.06,9*.075, 0.0);

    glVertex3f(-1.2-.06,11*.075, 0.0);
    glVertex3f(-1.2-.06,9*.075, 0.0);

    glVertex3f(-1.2-.06*9,11*.075, 0.0);
    glVertex3f(-1.2-.06*9,9*.075, 0.0);

    glVertex3f(-1.2-.06*13,11*.075, 0.0);
    glVertex3f(-1.2-.06*13,13*.075, 0.0);

    glVertex3f(-1.2-.06*5,11*.075, 0.0);
    glVertex3f(-1.2-.06*5,13*.075, 0.0);

    glVertex3f(-1.2-.06*17,15*.075, 0.0);
    glVertex3f(-1.2-.06*17,13*.075, 0.0);

    glVertex3f(-1.2-.06*10,15*.075, 0.0);
    glVertex3f(-1.2-.06*10,13*.075, 0.0);

    glVertex3f(-1.2-.06*3,15*.075, 0.0);
    glVertex3f(-1.2-.06*3,13*.075, 0.0);


    glVertex3f(-2.4, -.225, 0.0);
    glVertex3f(-1.2, -.225, 0.0);

    glVertex3f(-2.4, -.225-.075-.075, 0.0);
    glVertex3f(-1.2, -.225-.075-.075, 0.0);

    glVertex3f(-2.4, -.225-.075-.075-.075-.075, 0.0);
    glVertex3f(-1.2, -.225-.075-.075-.075-.075, 0.0);

    glVertex3f(-2.4, -.225-.075-.075-.075-.075-.075-.075, 0.0);
    glVertex3f(-1.2, -.225-.075-.075-.075-.075-.075-.075, 0.0);

    glVertex3f(-2.4, -.225-.075-.075-.075-.075-.075-.075-.075, 0.0);
    glVertex3f(-1.2, -.225-.075-.075-.075-.075-.075-.075-.075, 0.0);



    //glVertex3f(-2.4,0+.075, 0.0);
    //glVertex3f(-1.2, 00+.075, 0.0);

    glVertex3f(-2.4,0+.075+.075+.075, 0.0);
    glVertex3f(-1.2, 00+.075+.075+.075, 0.0);

    glVertex3f(-2.4,0+.075+.075+.075+.075+.075, 0.0);
    glVertex3f(-1.2, 00+.075+.075+.075+.075+.075, 0.0);

    glVertex3f(-2.4,0+.075+.075+.075+.075+.075+.075+.075, 0.0);
    glVertex3f(-1.2, 00+.075+.075+.075+.075+.075+.075+.075, 0.0);

    glVertex3f(-2.4,0+.075+.075+.075+.075+.075+.075+.075+.075+.075, 0.0);
    glVertex3f(-1.2, 00+.075+.075+.075+.075+.075+.075+.075+.075+.075, 0.0);

    glVertex3f(-2.4,0+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075, 0.0);
    glVertex3f(-1.2, 00+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075, 0.0);

    glVertex3f(-2.4,0+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075, 0.0);
    glVertex3f(-1.2, 00+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075, 0.0);


    glVertex3f(-2.4,0+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075, 0.0);
    glVertex3f(-1.2, 00+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075+.075, 0.0);

    glEnd();


    ///body

    glBegin(GL_QUADS);
    glColor3ub(0,100,0);

    glVertex3f(-1.2 ,-.75, 0.0);
    glVertex3f(-2.4, -.75, 0.0);
    glVertex3f(-2.4, 1.125, 0.0);
    glVertex3f(-1.2, 1.125, 0.0);


    glEnd();


    ///upper frame
    glBegin(GL_QUADS);
    glColor3ub(255,140,0);

    glVertex3f(-2.46 ,1.125, 0.0);
    glVertex3f(-1.14, 1.125, 0.0);
    glVertex3f(-1.14, 1.5, 0.0);
    glVertex3f(-2.46, 1.5, 0.0);


    glEnd();


    glPopMatrix();


///building after 1st pillar

    glPushMatrix(); //Save the transformations performed thus far
    glTranslatef(0.0, 0.0, 0.0);
///triangle frame

    glColor3ub(139,69,19);
    glBegin(GL_QUADS);
    glVertex3f(-2.7-4*.06 ,1.5, 0.0);
    glVertex3f(-2.7-2*.06 ,1.5, 0.0);
    glVertex3f(-2.4+1*.06, 2.25-.075, 0.0);
    glVertex3f(-2.4+1*.06, 2.25+.075, 0.0);

    glEnd();
    glColor3ub(139,69,19);
    glBegin(GL_QUADS);
    glVertex3f(-1.8 ,1.5, 0.0);
    glVertex3f(-1.8-2*.06 ,1.5, 0.0);
    glVertex3f(-2.4+1*.06, 2.25-.075, 0.0);
    glVertex3f(-2.4+1*.06, 2.25+.075, 0.0);

    glEnd();

    glColor3ub(205,133,63);
    glBegin(GL_QUADS);
    glVertex3f(-2.7,1.5, 0.0);
    glVertex3f(-2.7-2*.06 ,1.5, 0.0);
    glVertex3f(-2.4+1*.06, 2.25-.075, 0.0);
    glVertex3f(-2.4+1*.06, 2.25-4*.075, 0.0);

    glEnd();

    glColor3ub(205,133,63);
    glBegin(GL_QUADS);
    glVertex3f(-2.1+3*.06,1.5, 0.0);
    glVertex3f(-2.1+1*.06 ,1.5, 0.0);
    glVertex3f(-2.4+1*.06, 2.25-4*.075, 0.0);
    glVertex3f(-2.4+1*.06, 2.25-.075, 0.0);

    glEnd();
    glColor3ub(255,222,173);
    glBegin(GL_TRIANGLES);
    glVertex3f(-2.1+1*.06,1.5, 0.0);
    glVertex3f(-2.7 ,1.5, 0.0);
    glColor3ub(210,105,30);
    glVertex3f(-2.4+1*.06, 2.25-4*.075, 0.0);
    //glVertex3f(-2.4+1*.06, 2.25-.075, 0.0);

    glEnd();

///lines in the shades

    glBegin(GL_LINES);
    glColor3ub(255,228,181);
    glVertex3f(-1.2-1*.06,1.5, 0.0);
    glVertex3f(-1.2-4*.06,1.5+4*.075, 0.0);

    glVertex3f(-1.2-2*.06,1.5, 0.0);
    glVertex3f(-1.2-5*.06,1.5+4*.075, 0.0);

    glVertex3f(-1.2-3*.06,1.5, 0.0);
    glVertex3f(-1.2-6*.06,1.5+4*.075, 0.0);

    glVertex3f(-1.2-4*.06,1.5, 0.0);
    glVertex3f(-1.2-7*.06,1.5+4*.075, 0.0);

    glVertex3f(-1.2-5*.06,1.5, 0.0);
    glVertex3f(-1.2-8*.06,1.5+4*.075, 0.0);

    glVertex3f(-1.2-6*.06,1.5, 0.0);
    glVertex3f(-1.2-9*.06,1.5+4*.075, 0.0);


    glVertex3f(-1.2-7*.06,1.5, 0.0);
    glVertex3f(-1.2-10*.06,1.5+4*.075, 0.0);

    glVertex3f(-1.2-8*.06,1.5, 0.0);
    glVertex3f(-1.2-11*.06,1.5+4*.075, 0.0);

    glVertex3f(-1.2-9*.06,1.5, 0.0);
    glVertex3f(-1.2-12*.06,1.5+4*.075, 0.0);

    glVertex3f(-1.2-10*.06,1.5, 0.0);
    glVertex3f(-1.2-13*.06,1.5+4*.075, 0.0);

    glVertex3f(-1.2-11*.06,1.5, 0.0);
    glVertex3f(-1.2-14*.06,1.5+4*.075, 0.0);

    glVertex3f(-1.2-12*.06,1.5, 0.0);
    glVertex3f(-1.2-15*.06,1.5+4*.075, 0.0);

    glVertex3f(-1.2-13*.06,1.5, 0.0);
    glVertex3f(-1.2-16*.06,1.5+4*.075, 0.0);

    glVertex3f(-2.4-1*.06,1.125+4*.075, 0.0);
    glVertex3f(-2.4-3*.06,1.5, 0.0);

    glVertex3f(-2.4-1*.06,1.125+3*.075, 0.0);
    glVertex3f(-2.4-4*.06,1.5, 0.0);

    glVertex3f(-2.4-1*.06,1.125+2*.075, 0.0);
    glVertex3f(-2.4-5*.06,1.5, 0.0);


    glVertex3f(-2.4-1*.06,1.125+.075, 0.0);
    glVertex3f(-2.4-6*.06,1.5, 0.0);

    glVertex3f(-2.4-2*.06,1.125+.075, 0.0);
    glVertex3f(-2.4-7*.06,1.5, 0.0);

    glVertex3f(-2.4-3*.06,1.125+.075, 0.0);
    glVertex3f(-2.4-8*.06,1.5, 0.0);

    glVertex3f(-2.4-4*.06,1.125+.075, 0.0);
    glVertex3f(-2.4-9*.06,1.5, 0.0);

    glVertex3f(-2.4-5*.06,1.125+.075, 0.0);
    glVertex3f(-2.4-10*.06,1.5, 0.0);

    glVertex3f(-2.4-6*.06,1.125+.075, 0.0);
    glVertex3f(-2.4-11*.06,1.5, 0.0);

    glVertex3f(-2.4-7*.06,1.125+.075, 0.0);
    glVertex3f(-2.4-12*.06,1.5, 0.0);

    glVertex3f(-2.7-2*.06,1.5+2*.075, 0.0);
    glVertex3f(-2.7-4*.06,1.5+4*.075, 0.0);

    glVertex3f(-2.7-1*.06,1.5+2*.075, 0.0);
    glVertex3f(-2.7-3*.06,1.5+4*.075, 0.0);

    glVertex3f(-2.7-2*.06,1.5+1*.075, 0.0);
    glVertex3f(-2.7-4.5*.06,1.5+3*.075, 0.0);

    glVertex3f(-2.7-3*.06,1.5+1*.075, 0.0);
    glVertex3f(-2.7-5.5*.06,1.5+3*.075, 0.0);

    glVertex3f(-2.7-3.5*.06,1.5+.075, 0.0);
    glVertex3f(-2.7-5*.06,1.5+2*.075, 0.0);

    glEnd();


///upper shading

    glBegin(GL_QUADS);

    glColor3ub(226,133,25);
    glVertex3f(-2.4-.06,1.125+.075, 0.0);
    glVertex3f(-2.7-2*.06 ,1.125+.075, 0.0);
    glColor3ub(182,123,70);
    glVertex3f(-2.7-2*.06, 1.5, 0.0);
    glVertex3f(-2.4-.06, 1.5, 0.0);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(226,133,25);
    glVertex3f(-2.7-2*.06,1.125+.075, 0.0);
    glVertex3f(-3,1.125+.075, 0.0);
    glColor3ub(182,123,70);
    glVertex3f(-3, 1.5, 0.0);
    glVertex3f(-2.7-2*.06, 1.5, 0.0);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(226,133,25);
    glVertex3f(-2.7,1.5, 0.0);
    glVertex3f(-2.7-4*.06,1.5, 0.0);
    glColor3ub(182,123,70);
    glVertex3f(-2.7-4*.06, 1.5+4*.075, 0.0);
    glVertex3f(-2.7, 1.5+4*.075, 0.0);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(226,133,25);
    glVertex3f(-2.7-4*.06,1.5, 0.0);
    glVertex3f(-3,1.5, 0.0);
    glColor3ub(182,123,70);
    glVertex3f(-3, 1.5+2*.075, 0.0);
    glVertex3f(-2.7-4*.06, 1.5+4*.075, 0.0);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(226,133,25);
    glVertex3f(-1.2,1.5, 0.0);
    glVertex3f(-1.8,1.5, 0.0);
    glColor3ub(182,123,70);
    glVertex3f(-1.8-4*.06, 1.5+4*.075, 0.0);
    glVertex3f(-1.2-3*.06, 1.5+4*.075, 0.0);

    glEnd();

    glBegin(GL_QUADS);
///golden frame
    glColor3ub(255,215,0);
    glVertex3f(-2.4-.06,1.125, 0.0);
    glVertex3f(-3,1.125, 0.0);
    glColor3ub(255,255,0);
    glVertex3f(-3, 1.125+1*.075, 0.0);
    glVertex3f(-2.4-.06, 1.125+1*.075, 0.0);

    glEnd();
///brown frame
    glBegin(GL_QUADS);

    glColor3ub(218,165,32);
    glVertex3f(-2.4,1.125-.06, 0.0);
    glVertex3f(-3,1.125-.06, 0.0);
    //glColor3ub(255,255,0);
    glVertex3f(-3, 1.125, 0.0);
    glVertex3f(-2.4, 1.125, 0.0);


    glEnd();



    glPopMatrix();


    glPushMatrix();

///door
    glBegin(GL_LINES);

    glColor3ub(240,248,255);
    glVertex3f(-2.7,-.75, 0.0);
    glVertex3f(-2.7,.375-.075, 0.0);

    glVertex3f(-2.7+1*.06, -.75, 0.0);
    glVertex3f(-2.7+1*.06, .375-.075, 0.0);

    glVertex3f(-2.7-1*.06, -.75, 0.0);
    glVertex3f(-2.7-1*.06, .375-.075, 0.0);

    glColor3ub(75,0,130);
    glVertex3f(-2.7-2*.06, -.75, 0.0);
    glVertex3f(-2.7-2*.06, .375-.075, 0.0);

    glVertex3f(-2.7+2*.06, -.75, 0.0);
    glVertex3f(-2.7+2*.06, .375-.075, 0.0);

    glVertex3f(-2.7-2*.06,.375-.075, 0.0);
    glVertex3f(-2.7+2*.06, .375-.075, 0.0);


    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(210,105,30);
    glVertex3f(-2.7-2*.06,-.75, 0.0);
    glVertex3f(-2.7-2*.06,.375-.075, 0.0);
    glColor3ub(210,105,30);
    glVertex3f(-2.7+2*.06, .375-.06, 0.0);
    glVertex3f(-2.7+2*.06, -.75, 0.0);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(128,0,0);
    glVertex3f(-2.7-4*.06,-.75, 0.0);
    glVertex3f(-2.7-4*.06,.375+.075, 0.0);
    glColor3ub(218,165,32);
    glVertex3f(-2.7+4*.06, .375+.075, 0.0);
    glVertex3f(-2.7+4*.06, -.75, 0.0);

    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(85,107,47);
    glVertex3f(-2.7-4*.06,.375, 0.0);
    glVertex3f(-2.7+4*.06,.375, 0.0);
    //glColor3ub(218,165,32);
    glVertex3f(-2.7, .375+5*.075, 0.0);
    //glVertex3f(-2.7+4*.06, -.75, 0.0);

    glEnd();
///window
    glBegin(GL_LINES);

    glColor3ub(178,34,34);
    glVertex3f(-2.7-1*.06,.75+1.5*.075, 0.0);
    glVertex3f(-2.7-4*.06,.75+1.5*.075, 0.0);

    glEnd();


    glBegin(GL_POLYGON);

    glColor3ub(255,215,0);
    glVertex3f(-2.7-1*.06,.75, 0.0);
    glVertex3f(-2.7-4*.06,.75, 0.0);

    glVertex3f(-2.7-4*.06, 1.125-2*.075, 0.0);
    glColor3ub(255,228,181);
    glVertex3f(-2.7-3*.06, 1.125-1.5*.075, 0.0);

    glVertex3f(-2.7-2*.06, 1.125-1.5*.075, 0.0);
    glVertex3f(-2.7-1*.06, 1.125-2*.075, 0.0);


    glEnd();


    glBegin(GL_LINES);

    glColor3ub(178,34,34);
    glVertex3f(-2.4-1*.06,.75+1.5*.075, 0.0);
    glVertex3f(-2.4-4*.06,.75+1.5*.075, 0.0);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3ub(255,215,0);
    glVertex3f(-2.4-1*.06,.75, 0.0);
    glVertex3f(-2.4-4*.06,.75, 0.0);

    glVertex3f(-2.4-4*.06, 1.125-2*.075, 0.0);
    glColor3ub(255,228,181);
    glVertex3f(-2.4-3*.06, 1.125-1.5*.075, 0.0);

    glVertex3f(-2.4-2*.06, 1.125-1.5*.075, 0.0);
    glVertex3f(-2.4-1*.06, 1.125-2*.075, 0.0);


    glEnd();


///body of the building behind 1st pillar

    glBegin(GL_QUADS);

    glColor3ub(255,20,147);
    glVertex3f(-3,-.75, 0.0);
    glVertex3f(-3,1.125-.06, 0.0);
    glColor3ub(199,21,133);
    glVertex3f(-2.4, 1.125-.06, 0.0);
    glVertex3f(-2.4, -.75, 0.0);

    glEnd();

    glPopMatrix();

    ///building after 3rd pillar
    glPushMatrix();

    ///upper  pillar
    glColor3ub(199,21,133);
    glBegin(GL_QUADS);


    glVertex3f(1.5 ,1.5+2*.075, 0.0);
    glVertex3f(1.8+2*.06,1.5+2*.075, 0.0);
    glColor3ub(147,112,219);
    glVertex3f(1.8+2*.06,1.5+4*.075, 0.0);
    glVertex3f(1.5, 1.5+4*.075, 0.0);


    glEnd();
    glColor3ub(199,21,133);
    glBegin(GL_QUADS);


    glVertex3f(1.8+2*.06 ,1.5+2*.075, 0.0);
    glVertex3f(2.1+3*.06,1.5+2*.075, 0.0);
    glColor3ub(147,112,219);
    glVertex3f(2.1+3*.06,1.5+7*.075, 0.0);
    glVertex3f(1.8+2*.06, 1.5+7*.075, 0.0);


    glEnd();
    glColor3ub(199,21,133);
    glBegin(GL_QUADS);


    glVertex3f(2.4-3*.06 ,1.5+2*.075, 0.0);
    glVertex3f(2.4+3*.06,1.5+2*.075, 0.0);
    glColor3ub(147,112,219);
    glVertex3f(2.4+3*.06,1.5+4*.075, 0.0);
    glVertex3f(2.4-3*.06, 1.5+4*.075, 0.0);

    glEnd();

    glColor3ub(199,21,133);
    glBegin(GL_QUADS);


    glVertex3f(2.4+3*.06 ,1.5+2*.075, 0.0);
    glVertex3f(3,1.5+2*.075, 0.0);
    glColor3ub(147,112,219);
    glVertex3f(3,1.5+9*.075, 0.0);
    glVertex3f(2.4+3*.06, 1.5+9*.075, 0.0);

    glEnd();
    ///frame box
    glColor3ub(255,127,80);
    glBegin(GL_QUADS);


    glVertex3f(1.5+1*.06 ,1.5-.5*.075, 0.0);
    glVertex3f(1.5+5*.06,1.5-.5*.075, 0.0);
    glColor3ub(255,255,0);
    glVertex3f(1.5+5*.06,1.5+.075, 0.0);
    glVertex3f(1.5+1*.06, 1.5+.075, 0.0);


    glEnd();
    glColor3ub(255,127,80);
    glBegin(GL_QUADS);


    glVertex3f(2.1-2*.06 ,1.5-.5*.075, 0.0);
    glVertex3f(2.1+3*.06,1.5-.5*.075, 0.0);
    glColor3ub(255,255,0);
    glVertex3f(2.1+3*.06,1.5+.075, 0.0);
    glVertex3f(2.1-2*.06, 1.5+.075, 0.0);


    glEnd();

    glColor3ub(255,127,80);
    glBegin(GL_QUADS);


    glVertex3f(2.4-0*.06 ,1.5-.5*.075, 0.0);
    glVertex3f(2.4+5*.06,1.5-.5*.075, 0.0);
    glColor3ub(255,255,0);
    glVertex3f(2.4+5*.06,1.5+.075, 0.0);
    glVertex3f(2.4-0*.06, 1.5+.075, 0.0);


    glEnd();
    glColor3ub(255,127,80);
    glBegin(GL_QUADS);


    glVertex3f(2.7+1*.06 ,1.5-.5*.075, 0.0);
    glVertex3f(3,1.5-.5*.075, 0.0);
    glColor3ub(255,255,0);
    glVertex3f(3,1.5+.075, 0.0);
    glVertex3f(2.7+1*.06, 1.5+.075, 0.0);


    glEnd();


    ///frame
    glColor3ub(139,0,139);

    glBegin(GL_QUADS);


    glVertex3f(1.5 ,1.5-.075, 0.0);
    glVertex3f(3,1.5-.075, 0.0);
    glVertex3f(3, 1.5+2*.075, 0.0);
    glVertex3f(1.5, 1.5+2*.075, 0.0);


    glEnd();
    ///window
    glColor3ub(255,215,0);
    glBegin(GL_QUADS);


    glVertex3f(1.5+2*.06 ,3*.075, 0.0);
    glVertex3f(1.8,3*.075, 0.0);
    glColor3ub(255,222,173);
    glVertex3f(1.8,8*.075, 0.0);
    glVertex3f(1.5+2*.06 , 8*.075, 0.0);


    glEnd();

    glColor3ub(255,215,0);
    glBegin(GL_QUADS);


    glVertex3f(1.5+2*.06 ,-5*.075, 0.0);
    glVertex3f(1.8,5*-.075, 0.0);
    glColor3ub(255,222,173);
    glVertex3f(1.8,1*.075, 0.0);
    glVertex3f(1.5+2*.06 , 1*.075, 0.0);


    glEnd();
    glColor3ub(255,215,0);
    glBegin(GL_QUADS);


    glVertex3f(1.5+2*.06 ,.75+.075, 0.0);
    glVertex3f(1.8+2*.06,.75+.075, 0.0);
    glColor3ub(255,222,173);
    glVertex3f(1.8+2*.06,1.125+2.5*.075, 0.0);
    glVertex3f(1.5+2*.06 , 1.125+2.5*.075, 0.0);


    glEnd();
    glColor3ub(255,215,0);
    glBegin(GL_QUADS);


    glVertex3f(2.1 ,1.125, 0.0);
    glVertex3f(2.4,1.125, 0.0);
    glColor3ub(255,222,173);
    glVertex3f(2.4,1.125+2.5*.075, 0.0);
    glVertex3f(2.1 , 1.125+2.5*.075, 0.0);


    glEnd();

    glColor3ub(255,215,0);
    glBegin(GL_QUADS);


    glVertex3f(2.7 ,1.125, 0.0);
    glVertex3f(3,1.125, 0.0);
    glColor3ub(255,222,173);
    glVertex3f(3,1.125+2.5*.075, 0.0);
    glVertex3f(2.7 , 1.125+2.5*.075, 0.0);


    glEnd();
    ///square of body building
    glColor3ub(25,25,112);
    glBegin(GL_QUADS);


    glVertex3f(1.5 ,0+.075, 0.0);
    glVertex3f(1.8,.075, 0.0);
    glColor3ub(240,255,255);
    glVertex3f(1.8,2*.075, 0.0);
    glVertex3f(1.5, 2*.075, 0.0);


    glEnd();

    glColor3ub(25,25,112);
    glBegin(GL_QUADS);


    glVertex3f(1.5 ,.75-.075, 0.0);
    glVertex3f(1.8,.75-.075, 0.0);
    glColor3ub(240,255,255);
    glVertex3f(1.8,.75, 0.0);
    glVertex3f(1.5, .75, 0.0);


    glEnd();
    glColor3ub(25,25,112);
    glBegin(GL_QUADS);


    glVertex3f(1.8+3*.06 ,1.125, 0.0);
    glVertex3f(1.8+4*.06,1.125, 0.0);
    glColor3ub(240,255,255);
    glVertex3f(1.8+4*.06,1.5-.075, 0.0);
    glVertex3f(1.8+3*.06, 1.5-.075, 0.0);


    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(25,25,112);


    glVertex3f(2.4+2*.06 ,1.125, 0.0);
    glVertex3f(2.4+3*.06,1.125, 0.0);
    glColor3ub(240,255,255);
    glVertex3f(2.4+3*.06,1.5-.075, 0.0);
    glVertex3f(2.4+2*.06, 1.5-.075, 0.0);


    glEnd();



    ///body
    glColor3ub(186,85,211);

    glBegin(GL_QUADS);


    glVertex3f(1.5 ,-.75, 0.0);
    glVertex3f(3,-.75, 0.0);
    glVertex3f(3, 1.5-.075, 0.0);
    glVertex3f(1.5, 1.5-.075, 0.0);


    glEnd();

    glPopMatrix();


    ///building after 2nd pillar


    glPushMatrix();
///window middle
    glBegin(GL_QUADS);


    glColor3ub(255,215,0);

    glVertex3f(-.6,1.125+.075, 0.0);
    glVertex3f(-.3, 1.125+.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(-.3,1.125+3*.075, 0.0);
    glVertex3f(-.6,1.125+3*.075, 0.0);
    glEnd();

    glBegin(GL_QUADS);


    glColor3ub(255,215,0);

    glVertex3f(-.6,.75+.075, 0.0);
    glVertex3f(-.3, .75+.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(-.3,.75+3*.075, 0.0);
    glVertex3f(-.6,.75+3*.075, 0.0);
    glEnd();

    glBegin(GL_QUADS);


    glColor3ub(255,215,0);

    glVertex3f(-.6,.375+.075, 0.0);
    glVertex3f(-.3, .375+.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(-.3,.375+3*.075, 0.0);
    glVertex3f(-.6,.375+3*.075, 0.0);
    glEnd();

    glBegin(GL_QUADS);


    glColor3ub(255,215,0);

    glVertex3f(-.6,.0+.075, 0.0);
    glVertex3f(-.3, .0+.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(-.3,.0+3*.075, 0.0);
    glVertex3f(-.6,.0+3*.075, 0.0);
    glEnd();


    glBegin(GL_QUADS);


    glColor3ub(255,215,0);

    glVertex3f(-.6,-.375+.075, 0.0);
    glVertex3f(-.3, -.375+.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(-.3,-.375+3*.075, 0.0);
    glVertex3f(-.6,-.375+3*.075, 0.0);
    glEnd();

    glBegin(GL_QUADS);


    glColor3ub(255,215,0);

    glVertex3f(-.6,-.75+.075, 0.0);
    glVertex3f(-.3, -.75+.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(-.3,-.75+3*.075, 0.0);
    glVertex3f(-.6,-.75+3*.075, 0.0);

    glEnd();

///	left side window

    glBegin(GL_QUADS);


    glColor3ub(255,215,0);

    glVertex3f(-.6-4*.06,1.125+1.5*.075, 0.0);
    glVertex3f(-.6-1*.06, 1.125+1.5*.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(-.6-1*.06,1.125+2.5*.075, 0.0);
    glVertex3f(-.6-4*.06,1.125+2.5*.075, 0.0);

    glEnd();

    glBegin(GL_QUADS);


    glColor3ub(255,215,0);

    glVertex3f(-.6-4*.06,.75+1.5*.075, 0.0);
    glVertex3f(-.6-1*.06, .75+1.5*.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(-.6-1*.06,.75+2.5*.075, 0.0);
    glVertex3f(-.6-4*.06,.75+2.5*.075, 0.0);

    glEnd();

    glBegin(GL_QUADS);


    glColor3ub(255,215,0);

    glVertex3f(-.6-4*.06,.375+1.5*.075, 0.0);
    glVertex3f(-.6-1*.06, .375+1.5*.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(-.6-1*.06,.375+2.5*.075, 0.0);
    glVertex3f(-.6-4*.06,.375+2.5*.075, 0.0);

    glEnd();

    glBegin(GL_QUADS);


    glColor3ub(255,215,0);

    glVertex3f(-.6-4*.06,.0+1.5*.075, 0.0);
    glVertex3f(-.6-1*.06, .0+1.5*.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(-.6-1*.06,.0+2.5*.075, 0.0);
    glVertex3f(-.6-4*.06,.0+2.5*.075, 0.0);

    glEnd();

    glBegin(GL_QUADS);


    glColor3ub(255,215,0);

    glVertex3f(-.6-4*.06,-.375+1.5*.075, 0.0);
    glVertex3f(-.6-1*.06, -.375+1.5*.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(-.6-1*.06,-.375+2.5*.075, 0.0);
    glVertex3f(-.6-4*.06,-.375+2.5*.075, 0.0);

    glEnd();

    glBegin(GL_QUADS);


    glColor3ub(255,215,0);

    glVertex3f(-.6-4*.06,-.75+1.5*.075, 0.0);
    glVertex3f(-.6-1*.06, -.75+1.5*.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(-.6-1*.06,-.75+2.5*.075, 0.0);
    glVertex3f(-.6-4*.06,-.75+2.5*.075, 0.0);


    glEnd();

///right side window

    glBegin(GL_QUADS);


    glColor3ub(255,215,0);

    glVertex3f(-.3+1*.06,1.125+1.5*.075, 0.0);
    glVertex3f(-0-.06, 1.125+1.5*.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(-0-.06,1.125+2.5*.075, 0.0);
    glVertex3f(-.3+1*.06,1.125+2.5*.075, 0.0);


    glEnd();
    glBegin(GL_QUADS);


    glColor3ub(255,215,0);

    glVertex3f(-.3+1*.06,.75+1.5*.075, 0.0);
    glVertex3f(-0-.06, .75+1.5*.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(-0-.06,.75+2.5*.075, 0.0);
    glVertex3f(-.3+1*.06,.75+2.5*.075, 0.0);


    glEnd();

    glBegin(GL_QUADS);


    glColor3ub(255,215,0);

    glVertex3f(-.3+1*.06,.375+1.5*.075, 0.0);
    glVertex3f(-0-.06, .375+1.5*.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(-0-.06,.375+2.5*.075, 0.0);
    glVertex3f(-.3+1*.06,.375+2.5*.075, 0.0);


    glEnd();

    glBegin(GL_QUADS);


    glColor3ub(255,215,0);

    glVertex3f(-.3+1*.06,.0+1.5*.075, 0.0);
    glVertex3f(-0-.06, .0+1.5*.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(-0-.06,.0+2.5*.075, 0.0);
    glVertex3f(-.3+1*.06,.0+2.5*.075, 0.0);


    glEnd();

    glBegin(GL_QUADS);


    glColor3ub(255,215,0);

    glVertex3f(-.3+1*.06,-.375+1.5*.075, 0.0);
    glVertex3f(-0-.06, -.375+1.5*.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(-0-.06,-.375+2.5*.075, 0.0);
    glVertex3f(-.3+1*.06,-.375+2.5*.075, 0.0);


    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0);

    glVertex3f(-.3+1*.06,-.75+1.5*.075, 0.0);
    glVertex3f(-0-.06, -.75+1.5*.075, 0.0);
    glColor3ub(173,255,47);
    glVertex3f(-0-.06,-.75+2.5*.075, 0.0);
    glVertex3f(-.3+1*.06,-.75+2.5*.075, 0.0);


    glEnd();


///row of building
    glBegin(GL_QUADS);


    glColor3ub(230,230,250);

    glVertex3f(-.9,1.125-.075, 0.0);
    glVertex3f(-0, 1.125-.075, 0.0);
    glColor3ub(218,165,32);
    glVertex3f(-0,1.125, 0.0);
    glVertex3f(-.9, 1.125, 0.0);
    glEnd();

    glBegin(GL_QUADS);


    glColor3ub(230,230,250);

    glVertex3f(-.9,.75-.075, 0.0);
    glVertex3f(-0, .75-.075, 0.0);
    glColor3ub(218,165,32);
    glVertex3f(-0,.75, 0.0);
    glVertex3f(-.9, .75, 0.0);
    glEnd();


    glBegin(GL_QUADS);


    glColor3ub(230,230,250);

    glVertex3f(-.9,.375-.075, 0.0);
    glVertex3f(-0, .375-.075, 0.0);
    glColor3ub(218,165,32);
    glVertex3f(-0,.375, 0.0);
    glVertex3f(-.9, .375, 0.0);
    glEnd();

    glBegin(GL_QUADS);


    glColor3ub(230,230,250);

    glVertex3f(-.9,.0-.075, 0.0);
    glVertex3f(-0, .0-.075, 0.0);
    glColor3ub(218,165,32);
    glVertex3f(-0,.0, 0.0);
    glVertex3f(-.9, .0, 0.0);
    glEnd();

    glBegin(GL_QUADS);


    glColor3ub(230,230,250);

    glVertex3f(-.9,-.375-.075, 0.0);
    glVertex3f(-0, -.375-.075, 0.0);
    glColor3ub(218,165,32);
    glVertex3f(-0,-.375, 0.0);
    glVertex3f(-.9, -.375, 0.0);
    glEnd();

    glBegin(GL_QUADS);


    glColor3ub(230,230,250);

    glVertex3f(-.9,1.5-.075, 0.0);
    glVertex3f(-0, 1.5-.075, 0.0);
    glColor3ub(218,165,32);
    glVertex3f(-0,1.5, 0.0);
    glVertex3f(-.9, 1.5, 0.0);
    glEnd();


///body
    glBegin(GL_QUADS);


    glColor3ub(178,37,29);

    glVertex3f(-.9,-.75, 0.0);
    glVertex3f(-.12, -.75, 0.0);
    glColor3ub(238,74,17);
    glVertex3f(-.12,1.5+.075*2, 0.0);
    glVertex3f(-.9, 1.5+.075*2, 0.0);
    glEnd();

    glBegin(GL_QUADS);


    glColor3ub(178,37,29);

    glVertex3f(-.12,-.75, 0.0);
    glVertex3f(-0, -.75, 0.0);
    glColor3ub(238,74,17);
    glVertex3f(-0,1.5, 0.0);
    glVertex3f(-.12, 1.5+.075*2, 0.0);
    glEnd();


    glBegin(GL_QUADS);


    glColor3ub(178,37,29);

    glVertex3f(-.6-2*.06,1.5+.075*2, 0.0);
    glVertex3f(-.3+.06, 1.5+.075*2, 0.0);
    glColor3ub(238,74,17);
    glVertex3f(-.3+.06,1.875+.075*3, 0.0);
    glVertex3f(-.6-2*.06, 1.875+.075*3, 0.0);
    glEnd();

    glBegin(GL_QUADS);


    glColor3ub(178,37,29);

    glVertex3f(-.6-3*.06,1.875+.075*1, 0.0);
    glVertex3f(-.6-2*.06, 1.875+.075*1, 0.0);
    glColor3ub(238,74,17);
    glVertex3f(-.6-2*.06,1.875+.075*3, 0.0);
    glVertex3f(-.6-3*.06, 1.875+.075*3, 0.0);
    glEnd();

    glBegin(GL_QUADS);


    glColor3ub(178,37,29);

    glVertex3f(-.3+.06,1.875+.075*1, 0.0);
    glVertex3f(-.3+.06*2, 1.875+.075*1, 0.0);
    glColor3ub(238,74,17);
    glVertex3f(-.3+.06*2,1.875+.075*3, 0.0);
    glVertex3f(-.3+.06, 1.875+.075*3, 0.0);
    glEnd();




    glPopMatrix();

///building behind 1st pillar and 2nd pillar building after building
    glPushMatrix();
///window
    glBegin(GL_POLYGON);
    glColor3ub(255,215,0);
    glVertex3f(-1.2-3*.06,1.875+2*.075, 0.0);
    glVertex3f(-1.2-3*.06,1.875+3*.075, 0.0);

    glVertex3f(-1.2-0*.06,1.875+4*.075, 0.0);
    glColor3ub(255,245,238);
    glVertex3f(-1.2+2.5*.06,1.875+3*.075, 0.0);
    glVertex3f(-1.2+2.5*.06,1.875+2*.075, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,140,0);
    glVertex3f(-1.5,1.875+.5*.075, 0.0);
    glVertex3f(-1.5,1.875+1.5*.075, 0.0);
    glColor3ub(255,245,238);
    glVertex3f(-1.5+1.5*.06,1.875+1.5*.075, 0.0);

    glVertex3f(-1.5+1.5*.06,1.875+.5*.075, 0.0);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,140,0);
    glVertex3f(-1.5+2.5*.06,1.875+.5*.075, 0.0);
    glVertex3f(-1.5+2.5*.06,1.875+1.5*.075, 0.0);
    glColor3ub(255,245,238);
    glVertex3f(-1.5+4*.06,1.875+1.5*.075, 0.0);

    glVertex3f(-1.5+4*.06,1.875+.5*.075, 0.0);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,140,0);
    glVertex3f(-1.5+5*.06,1.875+.5*.075, 0.0);
    glVertex3f(-1.5+5*.06,1.875+1.5*.075, 0.0);
    glColor3ub(255,245,238);
    glVertex3f(-1.5+6.5*.06,1.875+1.5*.075, 0.0);

    glVertex3f(-1.5+6.5*.06,1.875+.5*.075, 0.0);

    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,140,0);
    glVertex3f(-1.5+7.5*.06,1.875+.5*.075, 0.0);
    glVertex3f(-1.5+7.5*.06,1.875+1.5*.075, 0.0);
    glColor3ub(255,245,238);
    glVertex3f(-1.5+9*.06,1.875+1.5*.075, 0.0);

    glVertex3f(-1.5+9*.06,1.875+.5*.075, 0.0);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,192,203);
    glVertex3f(-1.5-1.5*.06,1.875-2*.075, 0.0);
    glVertex3f(-1.5-1.5*.06,1.875-.5*.075, 0.0);
    glColor3ub(255,245,238);
    glVertex3f(-1.2-1.5*.06,1.875-.5*.075, 0.0);

    glVertex3f(-1.2-1.5*.06,1.875-3*.075, 0.0);

    glEnd();
    glBegin(GL_LINES);
    glColor3ub(75,0,130);
    glVertex3f(-.9-2*.06,1.5+2*.075, 0.0);
    glVertex3f(-.9+2*.06,1.5+2*.075, 0.0);
    //glColor3ub(255,245,238);
    glVertex3f(-.9-2*.06,1.5+1*.075, 0.0);
    glVertex3f(-.9+2*.06,1.5+1*.075, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,192,203);
    glVertex3f(-.9-2*.06,1.5-0*.075, 0.0);
    glVertex3f(-.9-2*.06,1.875-.5*.075, 0.0);
    glColor3ub(255,245,238);
    glVertex3f(-.9+2*.06,1.875-.5*.075, 0.0);

    glVertex3f(-.9+2*.06,1.5-0*.075, 0.0);

    glEnd();
    glBegin(GL_LINES);
    glColor3ub(75,0,130);
    glVertex3f(-.9-2*.06,1.125-0*.075, 0.0);
    glVertex3f(-.9-0*.06,1.125+0*.075, 0.0);
    //glColor3ub(255,245,238);
    glVertex3f(-.9-2*.06,1.125+1*.075, 0.0);
    glVertex3f(-.9-0*.06,1.125+1*.075, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,192,203);
    glVertex3f(-.9-2*.06,1.125-1*.075, 0.0);
    glVertex3f(-.9-2*.06,1.125+3*.075, 0.0);
    glColor3ub(255,245,238);
    glVertex3f(-.9+0*.06,1.125+3*.075, 0.0);

    glVertex3f(-.9+0*.06,1.125-1*.075, 0.0);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(75,0,130);
    glVertex3f(-.9-2*.06,.75-0*.075, 0.0);
    glVertex3f(-.9-0*.06,.75+0*.075, 0.0);

    glVertex3f(-.9-2*.06,.75-1*.075, 0.0);
    glVertex3f(-.9-0*.06,.75-1*.075, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,192,203);
    glVertex3f(-.9-2*.06,.75-2*.075, 0.0);
    glVertex3f(-.9-2*.06,.75+2*.075, 0.0);
    glColor3ub(255,245,238);
    glVertex3f(-.9+0*.06,.75+2*.075, 0.0);

    glVertex3f(-.9+0*.06,.75-2*.075, 0.0);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(75,0,130);
    glVertex3f(-.9-2*.06,.375-2*.075, 0.0);
    glVertex3f(-.9-0*.06,.375-2*.075, 0.0);

    glVertex3f(-.9-2*.06,.375-3*.075, 0.0);
    glVertex3f(-.9-0*.06,.375-3*.075, 0.0);


    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,192,203);
    glVertex3f(-.9-2*.06,.375-4*.075, 0.0);
    glVertex3f(-.9-2*.06,.375+0*.075, 0.0);
    glColor3ub(255,245,238);
    glVertex3f(-.9+0*.06,.375+0*.075, 0.0);

    glVertex3f(-.9+0*.06,.375-4*.075, 0.0);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,192,203);
    glVertex3f(-.9-2*.06,.0-4*.075, 0.0);
    glVertex3f(-.9-2*.06,.0-1*.075, 0.0);
    glColor3ub(255,245,238);
    glVertex3f(-.9+0*.06,.0-1*.075, 0.0);

    glVertex3f(-.9+0*.06,.0-4*.075, 0.0);

    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(153,50,204);
    glVertex3f(-1.5-3*.06,-.75, 0.0);
    glVertex3f(-1.5-3*.06, 1.875, 0.0);
    glColor3ub(85,107,47);
    glVertex3f(-.9+3*.06, 1.875, 0.0);
    glVertex3f(-.9+3*.06, -.75, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153,50,204);
    glVertex3f(-1.5-1*.06,1.875, 0.0);
    glVertex3f(-1.5-1*.06, 1.875+2*.075, 0.0);
    glColor3ub(85,107,47);
    glVertex3f(-.9+.06, 1.875+2*.075, 0.0);
    glVertex3f(-.9+.06, 1.875, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(153,50,204);
    glVertex3f(-1.5,1.875+2*.075, 0.0);
    glVertex3f(-1.5, 1.875+4*.075, 0.0);

    glVertex3f(-1.2, 2.25+.5*.075, 0.0);
    glColor3ub(85,107,47);
    glVertex3f(-.9-.06, 1.875+4*.075, 0.0);
    glVertex3f(-.9-.06, 1.875+2*.075, 0.0);
    glEnd();



    glPopMatrix();
    ///lower staircase


    glPushMatrix(); //Save the transformations performed thus far
    glTranslatef(0.0, 0.0, 0.0);
    //glScalef(0.5,0.5,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
    ///pillar lines
    glBegin(GL_LINES);
    glColor3ub(139,69,19);

    glVertex3f(-3,-2.50, 0.0);
    glVertex3f(3, -2.50, 0.0);

    glVertex3f(-3, -2.7, 0.0);
    glVertex3f(3, -2.7, 0.0);




    glVertex3f(-2.4, -2.5, 0.0);
    glVertex3f(-2.4, -2.7, 0.0);

    glVertex3f(-1.8, -2.5, 0.0);
    glVertex3f(-1.8, -2.7, 0.0);

    glVertex3f(-1.2, -2.5, 0.0);
    glVertex3f(-1.2, -2.7, 0.0);

    glVertex3f(-.6, -2.5, 0.0);
    glVertex3f(-.6, -2.7, 0.0);

    glVertex3f(0, -2.5, 0.0);
    glVertex3f(0, -2.7, 0.0);

    glVertex3f(.6, -2.5, 0.0);
    glVertex3f(.6, -2.7, 0.0);

    glVertex3f(1.2, -2.5, 0.0);
    glVertex3f(1.2, -2.7, 0.0);

    glVertex3f(1.8, -2.5, 0.0);
    glVertex3f(1.8, -2.7, 0.0);

    glVertex3f(2.4, -2.5, 0.0);
    glVertex3f(2.4, -2.7, 0.0);

    glVertex3f(-2.7, -2.7, 0.0);
    glVertex3f(-2.7, -2.9, 0.0);

    glVertex3f(-2.1, -2.7, 0.0);
    glVertex3f(-2.1, -2.9, 0.0);

    glVertex3f(-1.5, -2.7, 0.0);
    glVertex3f(-1.5, -2.9, 0.0);

    glVertex3f(-.9, -2.7, 0.0);
    glVertex3f(-.9, -2.9, 0.0);

    glVertex3f(-.3, -2.7, 0.0);
    glVertex3f(-.3, -2.9, 0.0);

    glVertex3f(.3, -2.7, 0.0);
    glVertex3f(.3, -3.9, 0.0);


    glVertex3f(.9, -2.7, 0.0);
    glVertex3f(.9, -2.9, 0.0);



    glVertex3f(1.5, -2.7, 0.0);
    glVertex3f(1.5, -2.9, 0.0);



    glVertex3f(2.1, -2.7, 0.0);
    glVertex3f(2.1, -2.9, 0.0);



    glVertex3f(2.7, -2.7, 0.0);
    glVertex3f(2.7, -2.9, 0.0);



    glEnd();



    ///stone pillar

    glBegin(GL_QUADS);
    glColor3ub(218,165,32);

    glVertex3f(-3,-2.9, 0.0);
    glVertex3f(3, -2.9, 0.0);
    glVertex3f(3, -2.5, 0.0);
    glVertex3f(-3, -2.5, 0.0);


    glEnd();

    glPopMatrix();
///line white above two roads

    glPushMatrix();

    //glTranslatef(0.0, 0.0, 0.0);
    glScalef(01.0, 01.20, 1.0);

    glPushMatrix();
    glBegin(GL_QUADS);
///road foot path start

    glColor3ub(240,248,255);

    glVertex3f(-3+.06, -1.125-1*.035, 0.0);
    glVertex3f(-3, -1.2+1*.075, 0.0);
    glVertex3f(3+0*.06, -1.2+1*.075, 0.0);
    glVertex3f(3+0*.06, -1.125-1*.035, 0.0);



    glColor3ub(240,248,255);

    glVertex3f(-3+.06, -2.125-1*.035, 0.0);
    glVertex3f(-3, -2.09+1*.075, 0.0);
    glVertex3f(3+0*.06, -2.09+1*.075, 0.0);
    glVertex3f(3+0*.06, -2.125-1*.035, 0.0);

    glEnd();
    glPopMatrix();

///rood mid line
    glPushMatrix();
    glBegin(GL_QUADS);


    glColor3ub(255,255,0);

    glVertex3f(-2.8+.06, -1.6, 0.0);
    glVertex3f(-2.8, -1.58, 0.0);
    glVertex3f(-2.70+2*.06, -1.58, 0.0);
    glVertex3f(-2.70+4*.06, -1.6, 0.0);


    glVertex3f(-2.3+.06, -1.6, 0.0);
    glVertex3f(-2.3, -1.58, 0.0);
    glVertex3f(-2.20+2*.06, -1.58, 0.0);
    glVertex3f(-2.20+4*.06, -1.6, 0.0);


    glVertex3f(-1.8+.06, -1.6, 0.0);
    glVertex3f(-1.8, -1.58, 0.0);
    glVertex3f(-1.70+2*.06, -1.58, 0.0);
    glVertex3f(-1.70+4*.06, -1.6, 0.0);

    glVertex3f(-1.3+.06, -1.6, 0.0);
    glVertex3f(-1.3, -1.58, 0.0);
    glVertex3f(-1.20+2*.06, -1.58, 0.0);
    glVertex3f(-1.20+4*.06, -1.6, 0.0);


    glVertex3f(-0.8+.06, -1.6, 0.0);
    glVertex3f(-0.8, -1.58, 0.0);
    glVertex3f(-0.70+2*.06, -1.58, 0.0);
    glVertex3f(-0.70+4*.06, -1.6, 0.0);

    glVertex3f(-0.3+.06, -1.6, 0.0);
    glVertex3f(-0.3, -1.58, 0.0);
    glVertex3f(-0.20+2*.06, -1.58, 0.0);
    glVertex3f(-0.20+4*.06, -1.6, 0.0);


    glVertex3f(0.2+.06, -1.6, 0.0);
    glVertex3f(0.2, -1.58, 0.0);
    glVertex3f(0.30+2*.06, -1.58, 0.0);
    glVertex3f(0.30+4*.06, -1.6, 0.0);

    glVertex3f(0.7+.06, -1.6, 0.0);
    glVertex3f(0.7, -1.58, 0.0);
    glVertex3f(0.80+2*.06, -1.58, 0.0);
    glVertex3f(0.80+4*.06, -1.6, 0.0);


    glVertex3f(01.2+.06, -1.6, 0.0);
    glVertex3f(01.2, -1.58, 0.0);
    glVertex3f(01.3+2*.06, -1.58, 0.0);
    glVertex3f(01.3+4*.06, -1.6, 0.0);


    glVertex3f(01.7+.06, -1.6, 0.0);
    glVertex3f(01.7, -1.58, 0.0);
    glVertex3f(01.8+2*.06, -1.58, 0.0);
    glVertex3f(01.8+4*.06, -1.6, 0.0);


    glVertex3f(02.2+.06, -1.6, 0.0);
    glVertex3f(02.2, -1.58, 0.0);
    glVertex3f(02.3+2*.06, -1.58, 0.0);
    glVertex3f(02.3+4*.06, -1.6, 0.0);


    glVertex3f(02.7+.06, -1.6, 0.0);
    glVertex3f(02.7, -1.58, 0.0);
    glVertex3f(02.8+2*.06, -1.58, 0.0);
    glVertex3f(02.8+4*.06, -1.6, 0.0);



    glEnd();

    glPopMatrix();

    ///main road
    glPushMatrix();
    glBegin(GL_QUADS);

    glColor3ub(128,128,128);

    glVertex3f(-3, -2.25, 0.0);
    glVertex3f(3, -2.25, 0.0);
    glVertex3f(3, -1.125, 0.0);
    glVertex3f(-3, -1.125, 0.0);
    glEnd();

///footpath
    ///upper road
    glBegin(GL_QUADS);


    glColor3ub(119,136,153);

    glVertex3f(-3, -0.75,0.0);
    glVertex3f(3, -0.75, 0.0);
    glVertex3f(3, -.60, 0.0);
    glVertex3f(-3, -.60, 0.0);



    glColor3ub(160,82,45);
    glVertex3f(-3, -1.125,0.0);

    glColor3ub(160,82,45);
    glVertex3f(3, -1.125, 0.0);

    glColor3ub(192,192,192);
    glVertex3f(3, -.75, 0.0);
    glVertex3f(-3, -.75, 0.0);
    glEnd();


    glPopMatrix();
    glPopMatrix();
    ///road end

///building behind the 3rd pillar after building
    glPushMatrix();
    glBegin(GL_LINES);
    glColor3ub(139,0,0);
///lines
    glVertex3f(1.2+1*.06, 1.5+2*.075, 0.0);

    glVertex3f(1.2+4*.06, 1.5+2*.075, 0.0);
    // glColor3ub(240,230,140);
    glVertex3f(1.2+1*.06,1.5+3*.075, 0.0);
    // glColor3ub(255,228,181);
    glVertex3f(1.2+4*.06, 1.5+3*.075, 0.0);

    glVertex3f(1.2+1*.06, .375+2*.075, 0.0);
    //glColor3ub(240,255,255);
    glVertex3f(1.2+4*.06, .375+2*.075, 0.0);

    glVertex3f(1.2+1*.06, .375+3*.075, 0.0);

    glVertex3f(1.2+4*.06, .375+3*.075, 0.0);

    glVertex3f(1.2+1*.06, .0+2*.075, 0.0);
    glVertex3f(1.2+4*.06, .0+2*.075, 0.0);

    glVertex3f(1.2+1*.06, .0+3*.075, 0.0);
    glVertex3f(1.2+4*.06, .0+3*.075, 0.0);



    glEnd();

///lines above building
    glBegin(GL_QUADS);
    glColor3ub(255,228,225);

    glVertex3f(1.2-0.2*.06, 1.125-0*.075, 0.0);

    glVertex3f(1.2-0.2*.06, 2.25+ 1*.075, 0.0);

    glVertex3f(1.2+.3*.06, 2.25+1*.075, 0.0);
    glVertex3f(1.2+.3*.06, 1.125-0*.075, 0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,228,225);

    glVertex3f(1.5+0*.06, 1.5+3*.075, 0.0);

    glVertex3f(1.5+0*.06, 2.25+ 1*.075, 0.0);

    glVertex3f(1.5+.5*.06, 2.25+1*.075, 0.0);
    glVertex3f(1.5+.5*.06, 1.5+3*.075, 0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,228,225);

    glVertex3f(1.8+0*.06, 1.5+3*.075, 0.0);

    glVertex3f(1.8+0*.06, 2.25+ 2*.075, 0.0);

    glVertex3f(1.8+.5*.06, 2.25+2*.075, 0.0);
    glVertex3f(1.8+.5*.06, 1.5+3*.075, 0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,228,225);

    glVertex3f(2.1+3*.06, 1.5+3*.075, 0.0);

    glVertex3f(2.1+3.0*.06, 2.25+ 0*.075, 0.0);

    glVertex3f(2.1+3.5*.06, 2.25+0*.075, 0.0);
    glVertex3f(2.1+3.5*.06, 1.5+3*.075, 0.0);
    glEnd();

///window
    glBegin(GL_POLYGON);
    glColor3ub(255,215,0);

    glVertex3f(1.2+1*.06, 1.5+1*.075, 0.0);

    glVertex3f(1.2+1*.06, 1.875-1*.075, 0.0);
    // glColor3ub(240,230,140);
    glVertex3f(1.2+2*.06,1.875+0*.075, 0.0);
    glColor3ub(255,218,185);
    glVertex3f(1.2+3*.06, 1.875+0*.075, 0.0);
    glVertex3f(1.2+4*.06, 1.875-1*.075, 0.0);
    glVertex3f(1.2+4*.06, 1.5+1*.075, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,215,0);

    glVertex3f(1.2+1*.06, .75+2*.075, 0.0);

    glVertex3f(1.2+1*.06, .75+3*.075, 0.0);
    // glColor3ub(240,230,140);
    //glVertex3f(1.2+2*.06,1.875+0*.075, 0.0);
    glColor3ub(255,218,185);
    //glVertex3f(1.2+3*.06, 1.875+0*.075, 0.0);
    glVertex3f(1.2+4*.06, .75+3*.075, 0.0);
    glVertex3f(1.2+4*.06, .75+2*.075, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(128,128,128);

    glVertex3f(1.2+1*.06, .375+1*.075, 0.0);

    glVertex3f(1.2+1*.06, .375+4*.075, 0.0);
    // glColor3ub(240,230,140);
    glVertex3f(1.2+2*.06,.75-0.5*.075, 0.0);
    glColor3ub(112,128,144);
    glVertex3f(1.2+3*.06, .75-0.5*.075, 0.0);
    glVertex3f(1.2+4*.06, .75-1*.075, 0.0);
    glColor3ub(240,255,255);
    glVertex3f(1.2+4*.06, .375+1*.075, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255,215,0);

    glVertex3f(1.2+1*.06, .0+1*.075, 0.0);

    glVertex3f(1.2+1*.06, .0+4*.075, 0.0);
    // glColor3ub(240,230,140);
    glVertex3f(1.2+2*.06,.375-0.5*.075, 0.0);
    glColor3ub(255,228,181);
    glVertex3f(1.2+3*.06, .375-0.5*.075, 0.0);
    glVertex3f(1.2+4*.06, .375-1*.075, 0.0);
    //glColor3ub(240,255,255);
    glVertex3f(1.2+4*.06, .0+1*.075, 0.0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255,215,0);

    glVertex3f(1.2+1*.06, -.375-1.5*.075, 0.0);

    glVertex3f(1.2+1*.06, -.375+2*.075, 0.0);
    // glColor3ub(240,230,140);
    glVertex3f(1.2+2*.06,-.375+3*.075, 0.0);
    glColor3ub(255,228,181);
    glVertex3f(1.2+3*.06, -.375+3*.075, 0.0);
    glVertex3f(1.2+4*.06, -.375+2*.075, 0.0);
    //glColor3ub(240,255,255);
    glVertex3f(1.2+4*.06, -.375-1.5*.075, 0.0);
    glEnd();
///lines upper window
    glBegin(GL_LINES);
    glColor3ub(178,34,34);

    glVertex3f(1.5+1*.06, 1.875+2*.075, 0.0);

    glVertex3f(1.5+2.5*.06, 1.875+1*.075, 0.0);
    // glColor3ub(240,230,140);
    glVertex3f(1.5+2.5*.06,1.875+1*.075, 0.0);
    //glColor3ub(255,228,181);
    glVertex3f(1.5+4*.06, 1.875+2*.075, 0.0);
    glVertex3f(1.5+2.5*.06, 1.875+1*.075, 0.0);
    //glColor3ub(240,255,255);
    glVertex3f(1.5+2.5*.06, 1.875-2*.075, 0.0);
    glEnd();

///window
    glBegin(GL_POLYGON);
    glColor3ub(255,215,0);

    glVertex3f(1.5+1*.06, 1.5+3*.075, 0.0);

    glVertex3f(1.5+1*.06, 2.25-2.5*.075, 0.0);
    // glColor3ub(240,230,140);
    glVertex3f(1.5+1.5*.06,2.25-1.5*.075, 0.0);
    glColor3ub(255,228,181);
    glVertex3f(1.5+3.5*.06, 2.25-1.5*.075, 0.0);
    glVertex3f(1.5+4*.06, 2.25-2.5*.075, 0.0);
    //glColor3ub(240,255,255);
    glVertex3f(1.5+4*.06, 1.5+3*.075, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,99,71);

    glVertex3f(1.8+2*.06, 1.875+2.2*.075, 0.0);

    glVertex3f(1.8+2*.06, 1.875+3.7*.075, 0.0);
    glColor3ub(255,228,225);
    glVertex3f(2.1+1*.06, 1.875+3.7*.075, 0.0);

    glVertex3f(2.1+1*.06, 1.875+2.2*.075, 0.0);

    glEnd();


///lines

    glBegin(GL_LINES);
    glColor3ub(47,79,79);

    glVertex3f(2.1+3*.06, 1.875-0*.075, 0.0);

    glVertex3f(2.1+6*.06, 1.875+0.0*.075, 0.0);

    glVertex3f(2.1+3*.06, 1.875+1*.075, 0.0);
    //glColor3ub(255,140,0);
    glVertex3f(2.1+6.2*.06, 1.875+1*.075, 0.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,215,0);

    glVertex3f(2.1+3.5*.06, 1.875-2*.075, 0.0);

    glVertex3f(2.1+3.5*.06, 1.875+2.0*.075, 0.0);

    glVertex3f(2.1+4*.06, 1.875+2.6*.075, 0.0);
    glColor3ub(255,140,0);
    glVertex3f(2.1+5*.06, 1.875+2.6*.075, 0.0);
    glVertex3f(2.1+6*.06,1.875+2.0*.075, 0.0);
    //glColor3ub(240,255,255);
    glVertex3f(2.1+6*.06,1.875-2*.075, 0.0);
    glEnd();


///body

    glBegin(GL_QUADS);

    glColor3ub(139,0,0);

    glVertex3f(1.2-2*.06, -.75, 0.0);
    glVertex3f(1.2-2*.06, 2.25+.075, 0.0);

    glVertex3f(1.5, 2.25+.075, 0.0);
    glColor3ub(152,251,152);
    glVertex3f(1.5, -.75, 0.0);
    glEnd();
    glBegin(GL_QUADS);

    glColor3ub(139,0,0);

    glVertex3f(1.5-0*.06, 1.5+3*.075, 0.0);
    glVertex3f(1.5-0*.06, 2.25+.075, 0.0);

    glVertex3f(1.8+0*.06, 2.25+1*.075, 0.0);
    glColor3ub(255,160,122);
    glVertex3f(1.8+0*.06, 1.5+3*.075, 0.0);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(139,0,0);

    glVertex3f(1.5+2*.06, 2.25+.075, 0.0);

    glVertex3f(1.5+2*.06, 2.25+2*.075, 0.0);

    glVertex3f(1.8+0*.06, 2.25+2*.075, 0.0);
    //glColor3ub(240,230,140);
    glVertex3f(1.8+0*.06, 2.25+1*.075, 0.0);
    glEnd();
    glBegin(GL_QUADS);

    glColor3ub(139,0,0);

    glVertex3f(1.8+0*.06, 2.25+0*.075, 0.0);

    glVertex3f(1.8+0*.06, 2.25+2*.075, 0.0);

    glVertex3f(1.8+3*.06, 2.25+2*.075, 0.0);
    //glColor3ub(240,230,140);
    glVertex3f(1.8+3*.06, 2.25+0*.075, 0.0);
    glEnd();
    glBegin(GL_QUADS);

    glColor3ub(139,0,0);

    glVertex3f(1.8+0*.06, 1.875-2*.075, 0.0);

    glVertex3f(1.8+0*.06, 2.25+0*.075, 0.0);

    glVertex3f(2.1+3*.06, 2.25+0*.075, 0.0);
    glColor3ub(240,230,140);
    glVertex3f(2.1+3*.06, 1.875-2*.075, 0.0);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(139,0,0);

    glVertex3f(2.1+3*.06, 2.25-1*.075, 0.0);

    glVertex3f(2.7+0*.06, 2.25-1*.075, 0.0);
    glColor3ub(240,230,140);
    glVertex3f(2.7+0*.06, 1.875-2*.075, 0.0);

    glVertex3f(2.1+3*.06, 1.875-2*.075, 0.0);
    glEnd();
    glBegin(GL_QUADS);

    glColor3ub(139,0,0);

    glVertex3f(2.1+3*.06, 2.25-1*.075, 0.0);

    glVertex3f(2.1+3*.06, 2.25-0*.075, 0.0);
    // glColor3ub(240,230,140);
    glVertex3f(2.4+0*.06, 2.25-0*.075, 0.0);

    glVertex3f(2.4+0*.06, 2.25-1*.075, 0.0);
    glEnd();
    glBegin(GL_QUADS);

    glColor3ub(139,0,0);

    glVertex3f(2.4+2*.06, 1.875+2*.075, 0.0);

    glVertex3f(2.4+2*.06, 1.875+4*.075, 0.0);
    // glColor3ub(240,230,140);
    glVertex3f(2.7+0*.06,1.875+4*.075, 0.0);

    glVertex3f(2.7+0*.06, 1.875+2*.075, 0.0);
    glEnd();



    glPopMatrix();
///building after the 2nd pillar

    glPushMatrix();
    glBegin(GL_POLYGON);

    glColor3ub(25,25,112);

    glVertex3f(-04*.06, 1.125-0*.075, 0.0);
    glVertex3f(-0-4*.06, 1.875-2*.075, 0.0);
    glColor3ub(255,20,147);
    glVertex3f(1.2, 1.875-2*.075, 0.0);
    glVertex3f(1.2, 1.125-0*.075, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
///1st pillar
    glColor3ub(25,25,112);

    glVertex3f(-0-2.5*.06, 1.875-2*.075, 0.0);
    glVertex3f(-0-2.5*.06, 1.875+2*.075, 0.0);
    glColor3ub(255,20,147);
    glVertex3f(.3+0*.06, 1.875+2*.075, 0.0);
    glVertex3f(.3+0*.06, 1.875-2*.075, 0.0);
    glEnd();
///2nd pillar
    glBegin(GL_POLYGON);

    glColor3ub(25,25,112);

    glVertex3f(.60+0*.06, 1.875-2*.075, 0.0);
    glVertex3f(.60+0*.06, 1.875+2*.075, 0.0);
    glColor3ub(255,20,147);
    glVertex3f(.9+2*.06, 1.875+2*.075, 0.0);
    glVertex3f(.9+2*.06, 1.875-2*.075, 0.0);
    glEnd();
    glBegin(GL_POLYGON);

    glColor3ub(25,25,112);

    glVertex3f(.0-4*.06, 1.875-2*.075, 0.0);
    glVertex3f(.0-4*.06, 1.875-0*.075, 0.0);
    glColor3ub(255,20,147);
    glVertex3f(.0+1*.06, 1.875-0*.075, 0.0);
    glVertex3f(.0+1*.06, 1.875-2*.075, 0.0);
    glEnd();
    glBegin(GL_POLYGON);

    glColor3ub(25,25,112);

    glVertex3f(.9+2*.06, 1.875-2*.075, 0.0);
    glVertex3f(.9+2*.06, 1.875-0*.075, 0.0);
    glColor3ub(255,20,147);
    glVertex3f(.9+4*.06, 1.875-0*.075, 0.0);
    glVertex3f(.9+4*.06, 1.875-2*.075, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(128,0,0);

    glVertex3f(.3+1*.06, 1.875-2*.075, 0.0);
    glVertex3f(.3+1*.06, 1.875-.9*.075, 0.0);
    //glColor3ub(255,215,0);
    glVertex3f(.6-1*.06, 1.875-.9*.075, 0.0);
    glVertex3f(.6-1*.06, 1.875-2*.075, 0.0);


    glEnd();
///middle gumbuj
    glBegin(GL_POLYGON);
    glColor3ub(255,140,0);

    glVertex3f(.3+0*.06, 1.875-2*.075, 0.0);
    glVertex3f(.3+.3*.06, 1.875+0.2*.075, 0.0);
    glColor3ub(255,215,0);
    glVertex3f(.3+1.1*.06, 1.875+1.0*.075, 0.0);
    glVertex3f(.3+2.1*.06, 1.875+1.3*.075, 0.0);
    glColor3ub(218,165,32);
    glVertex3f(.3+3.3*.06, 1.875+1.0*.075, 0.0);
    glVertex3f(.3+4.3*.06, 1.875+.2*.075, 0.0);
    glColor3ub(244,164,96);
    glVertex3f(.6+0*.06, 1.875-2*.075, 0.0);


    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);

    glVertex3f(.3+3.2*.06, 1.875+1*.075, 0.0);
    glVertex3f(.3+1.2*.06, 1.875+1*.075, 0.0);
    //glColor3ub(255,215,0);
    glVertex3f(.3+2.2*.06, 1.875+3.2*.075, 0.0);


    glEnd();

///1st pillar over pillar
    glBegin(GL_POLYGON);
    glColor3ub(25,25,112);

    glVertex3f(.0-1.5*.06, 1.875+2*.075, 0.0);
    glVertex3f(.0-1.5*.06, 1.875+3*.075, 0.0);
    glColor3ub(255,20,147);
    glVertex3f(.0+4*.06, 1.875+3*.075, 0.0);
    glVertex3f(.0+4*.06, 1.875+2*.075, 0.0);


    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(25,25,112);

    glVertex3f(.0-.5*.06, 1.875+3*.075, 0.0);
    glVertex3f(.0-.5*.06, 1.875+4*.075, 0.0);
    glColor3ub(255,20,147);
    glVertex3f(.0+2.8*.06, 1.875+4*.075, 0.0);
    glVertex3f(.0+2.8*.06, 1.875+3*.075, 0.0);


    glEnd();
///2nd pillar over pillar

    glBegin(GL_POLYGON);
    glColor3ub(25,25,112);

    glVertex3f(.6+1*.06, 1.875+2*.075, 0.0);
    glVertex3f(.6+1*.06, 1.875+3*.075, 0.0);
    glColor3ub(255,20,147);
    glVertex3f(.9+1*.06, 1.875+3*.075, 0.0);
    glVertex3f(.9+1*.06, 1.875+2*.075, 0.0);


    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(25,25,112);

    glVertex3f(.6+2*.06, 1.875+3*.075, 0.0);
    glVertex3f(.6+2*.06, 1.875+4*.075, 0.0);
    glColor3ub(255,20,147);
    glVertex3f(.9+0*.06, 1.875+4*.075, 0.0);
    glVertex3f(.9+0*.06, 1.875+3*.075, 0.0);


    glEnd();











    glPopMatrix();

///sky

    glPushMatrix();
    glBegin(GL_QUADS);

    glColor3ub(135,206,235);

    glVertex3f(-3, -.75, 0.0);
    glVertex3f(3, -.75, 0.0);
    glVertex3f(3, 3, 0.0);
    glVertex3f(-3, 3, 0.0);
    glEnd();
    glPopMatrix();




    glFlush();
    glutSwapBuffers();

}
void drawscene2()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
    glLoadIdentity(); //Reset the drawing perspective
    glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
    glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units
    //RenderToDisplay();
    //glutSwapBuffers();
    glPushMatrix();
    if (colCountL == 0)
    {
        glTranslatef(1.0, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(0,128,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5 , -0.1);
        glVertex2f(1.5, 0.0);
        glEnd();


    }

    else if (colCountL == 1)
    {
        //yellow
        glTranslatef(1.0, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(255,255,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5-0.6 , -0.1);
        glVertex2f(1.5-0.6, 0.0);
        glEnd();
    }
    else if (colCountL == 2)
    {
        glTranslatef(1.0, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(255,0,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5-1.2 , -0.1);
        glVertex2f(1.5-1.2, 0.0);
        glEnd();
    }


    glPopMatrix();

///HealthbarHero
    glPushMatrix();

    glPushMatrix();
    glTranslatef(-2.5, 2.58, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(0,128,0);

    glVertex2f(0.0, 0.0);
    glVertex2f(0.05 , 0.0);
    glVertex2f(0.05 , -0.25);
    glVertex2f(0.0, -0.25);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.34, 2.45, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(0,128,0);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.25 , 0.0);
    glVertex2f(-0.25,0.05 );
    glVertex2f(0.0, 0.05);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.7, 2.58, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(0,128,0);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.05 , 0.0);
    glVertex2f(0.05 , -0.25);
    glVertex2f(0.0, -0.25);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.85, 2.45, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(0,128,0);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.25 , 0.0);
    glVertex2f(-0.25,0.05 );
    glVertex2f(0.0, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    if (colCountR == 0)
    {
        glTranslatef(-2.2, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(0,128,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5 , -0.1);
        glVertex2f(1.5, 0.0);
        glEnd();
    }

    else if (colCountR == 1)
    {
        //yellow
        glTranslatef(-2.2, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(255,255,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5-0.6 , -0.1);
        glVertex2f(1.5-0.6, 0.0);
        glEnd();
    }
    else if (colCountR == 2)
    {
        glTranslatef(-2.2, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(255,0,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5-1.2 , -0.1);
        glVertex2f(1.5-1.2, 0.0);
        glEnd();
    }
    else if (colCountR >= 3)
    {
        glTranslatef(-2.2, 2.5, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(0,128,0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0 , -0.1);
        glVertex2f(1.5 , -0.1);
        glVertex2f(1.5, 0.0);
        glEnd();
    }

    glPopMatrix();

    glPopMatrix();

///start pause
    glPushMatrix();
    glTranslatef(0, p, 0.0);
    glScalef(0.50, 0.50, 0.0);




    glPushMatrix();

    glColor3ub(255,240,245);


    glutSolidTorus(.2,1,100,100);


    glPopMatrix();


    glPushMatrix();
    glBegin(GL_QUADS);

    glColor3ub(220,220,220);


    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(0.35, -0.5, 0.0);
    glVertex3f(0.35, 0.5, 0.0);



    glVertex3f(0.10, 0.5, 0.0);
    glVertex3f(0.10, -0.5, 0.0);
    glVertex3f(0.25, -0.5, 0.0);
    glVertex3f(0.25, 0.5, 0.0);


    glEnd();


    glPopMatrix();


    glPushMatrix();

    glBegin(GL_TRIANGLES);



    glVertex3f(0.08, -0.0, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glVertex3f(-0.5, -0.5, 0.0);

    glEnd();

    glPopMatrix();
    glPopMatrix();
    ///end pause




    ///Chr2
    glPushMatrix();
    glScalef(-1,1,1);
    glScalef(0.25,0.25,0);
    glTranslatef(7.0+ch1,y, 0.0);


    glPushMatrix(); //Save the transformations performed thus far
    //glTranslatef(1.0, -1.0, 0.0);
    //glScalef(2.5,2.5,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
    //hand


    glColor3ub(85,107,47);
    glBegin(GL_QUADS);

    glVertex3f(-0.4, -0.2+yr, 0.0);
    glVertex3f(0.2, -0.2+yr, 0.0);
    glVertex3f(0.2,-0.4+yr, 0.0);
    glVertex3f(-0.4,-0.4+yr,0);


    glVertex3f(-0.4,-0.2+yr, 0.0);
    glVertex3f(-0.4,-0.4+yr,0);
    glVertex3f(-0.8, -0.6+yr, 0.0);
    glVertex3f(-0.8, 0.0+yr, 0.0);

    glVertex3f(-0.8,-0.6+yr, 0.0);
    glVertex3f(-1.0,-0.6+yr,0);
    glVertex3f(-1.0, -0.5+yr, 0.0);
    glVertex3f(-0.8, -0.5+yr, 0.0);

    glVertex3f(-0.8,-0.0+yr, 0.0);
    glVertex3f(-1.0,-0.0+yr,0);
    glVertex3f(-1.0, -0.1+yr, 0.0);
    glVertex3f(-0.8, -0.1+yr, 0.0);

    glEnd();

    glTranslatef(0.3, -0.3, 0.0);

    glColor3ub(72,61,139);
    //HAND

    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.15;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y+yr );
    }
    glEnd();

    glPopMatrix();


    ///Bullet

    glPushMatrix(); //Save the transformations performed thus far
    glTranslatef(x, xy, 0.0);
    glColor3ub(226,104,34);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y+yr);
    }
    glEnd();



    glPopMatrix();

    ///BulletEnd


    glPushMatrix(); //Save the transformations performed thus far
    //glTranslatef(1.0, -1.0, 0.0);
    //glScalef(2.5,2.5,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
    glBegin(GL_QUADS);


    glColor3ub(0,100,0);
    //spot

    glVertex3f(0.60, -0.10+yr, 0.0);
    glVertex3f(0.50, -0.2+yr, 0.0);
    glVertex3f(0.5, -0.4+yr, 0.0);
    glVertex3f(0.55,-0.10+yr,0);


    glVertex3f(0.60, -0.50+yr, 0.0);
    glVertex3f(0.50, -0.4+yr, 0.0);
    glVertex3f(0.5, -0.48+yr, 0.0);
    glVertex3f(0.55,-0.50+yr,0);


    glVertex3f(0.60, -0.80+yr, 0.0);
    glVertex3f(0.50, -0.7+yr, 0.0);
    glVertex3f(0.5, -0.68+yr, 0.0);
    glVertex3f(0.55,-0.80+yr,0);


    glVertex3f(0.40, -0.90+yr, 0.0);
    glVertex3f(0.30, -0.85+yr, 0.0);
    glVertex3f(0.3, -0.7+yr, 0.0);
    glVertex3f(0.35,-0.90+yr,0);

    glVertex3f(0.10, -0.95+yr, 0.0);
    glVertex3f(0.08, -0.75+yr, 0.0);
    glVertex3f(0.2, -0.60+yr, 0.0);
    glVertex3f(0.15,-0.85+yr,0);

    glVertex3f(0.10, -0.45+yr, 0.0);
    glVertex3f(0.08, -0.55+yr, 0.0);
    glVertex3f(0.2, -0.60+yr, 0.0);
    glVertex3f(0.15,-0.5+yr,0);

    glVertex3f(0.30, -0.45+yr, 0.0);
    glVertex3f(0.28, -0.65+yr, 0.0);
    glVertex3f(0.35, -0.60+yr, 0.0);
    glVertex3f(0.25,-0.55+yr,0);

    glVertex3f(0.30, -0.0+yr, 0.0);
    glVertex3f(0.28, -0.1+yr, 0.0);
    glVertex3f(0.35, -0.1+yr, 0.0);
    glVertex3f(0.25,-0.0+yr,0.0);

    glVertex3f(0.0, -0.0+yr, 0.0);
    glVertex3f(0.08, -0.1+yr, 0.0);
    glVertex3f(0.05, -0.1+yr, 0.0);
    glVertex3f(0.05,-0.0+yr,0.0);


    glColor3ub(160,82,45);



    glVertex3f(0.55, -0.10+yr, 0.0);
    glVertex3f(0.50, -0.2+yr, 0.0);
    glVertex3f(0.56, -0.4+yr, 0.0);
    glVertex3f(0.50,-0.10+yr,0);


    glVertex3f(0.4, -0.50+yr, 0.0);
    glVertex3f(0.40, -0.4+yr, 0.0);
    glVertex3f(0.50, -0.48+yr, 0.0);
    glVertex3f(0.45,-0.50+yr,0);


    glVertex3f(0.10, -0.80+yr, 0.0);
    glVertex3f(0.20, -0.7+yr, 0.0);
    glVertex3f(0.1, -0.5+yr, 0.0);
    glVertex3f(0.15,-0.80+yr,0);


    glVertex3f(0.50, -0.90+yr, 0.0);
    glVertex3f(0.20, -0.85+yr, 0.0);
    glVertex3f(0.44, -0.7+yr, 0.0);
    glVertex3f(0.53,-0.90+yr,0);

    glVertex3f(0.10, -0.85+yr, 0.0);
    glVertex3f(0.08, -0.55+yr, 0.0);
    glVertex3f(0.2, -0.40+yr, 0.0);
    glVertex3f(0.15,-0.75+yr,0);

    glVertex3f(0.20, -0.45+yr, 0.0);
    glVertex3f(0.08, -0.55+yr, 0.0);
    glVertex3f(0.22, -0.60+yr, 0.0);
    glVertex3f(0.09,-0.5+yr,0);

    glVertex3f(0.50, -0.45+yr, 0.0);
    glVertex3f(0.48, -0.65+yr, 0.0);
    glVertex3f(0.25, -0.60+yr, 0.0);
    glVertex3f(0.55,-0.55+yr,0);

    glVertex3f(0.30, -0.20+yr, 0.0);
    glVertex3f(0.28, -0.14+yr, 0.0);
    glVertex3f(0.35, -0.06+yr, 0.0);
    glVertex3f(0.25,-0.20+yr,0.0);

    glVertex3f(0.10, -0.0+yr, 0.0);
    glVertex3f(0.15, -0.1+yr, 0.0);
    glVertex3f(0.25, -0.1+yr, 0.0);
    glVertex3f(0.35,-0.0+yr,0.0);


    glColor3ub(240,230,140);
    //Body

    glVertex3f(0.0, 0.0+yr, 0.0);

    glColor3ub(245,222,179);

    glVertex3f(0.0, -1.0+yr, 0.0);
    glVertex3f(0.6, -1.0+yr, 0.0);

    glColor3ub(176,196,222);
    glVertex3f(0.6,0.0+yr,0);






    //Eye
    glColor3ub(25,25,112);

    glVertex3f(-0.2,0.7+yr,0);
    glVertex3f(-0.0,0.7+yr,0);
    glVertex3f(-0.0,0.9+yr,0);
    glVertex3f(-0.2,0.9+yr,0);


    glVertex3f(0.0,0.7+yr,0);
    glVertex3f(0.0,0.9+yr,0);
    glVertex3f(0.2,1.1+yr,0);
    glVertex3f(0.2,0.7+yr,0);
//mouth
    glColor3ub(192,192+yr,192);
    glVertex3f(-0.1,0.5+yr,0);
    glVertex3f(-0.0,0.5+yr,0);
    glVertex3f(-0.1,0.40+yr,0);
    glVertex3f(-0.2,0.40+yr,0);

    //Head
    glColor3ub(165,42,42);

    glVertex3f(-0.2,0.1+yr,0);
    glVertex3f(1.0,0.5+yr,0);
    glVertex3f(1.0,1.2+yr,0);
    glVertex3f(-0.2,1.4+yr,0);



    //neck
    glColor3ub(255,215,0);

    glVertex3f(0.2, 0.0+yr, 0.0);
    glVertex3f(0.4, 0.0+yr, 0.0);
    glVertex3f(0.4, 0.5+yr, 0.0);
    glVertex3f(0.2,0.5+yr,0);

    //Thai
    glVertex3f(0.2, -1.0+yr, 0.0);
    glVertex3f(0.4, -1.0+yr, 0.0);
    glVertex3f(0.4, -1.65+yr, 0.0);
    glVertex3f(0.2,-1.65+yr,0);
    glEnd();

    glPopMatrix(); //Undo the move to the center of the trapezoid

    glPushMatrix(); //Save the transformations performed thus far
    //glTranslatef(1.0, -1.0, 0.0);
    //glScalef(2.5,2.5,0); //Move to the center of the trapezoid
    //glRotatef(_ang_tri ,0.0, 1.0, 0.0); //Rotate about the z-axis
    //Leg



    glTranslatef(0.3, -1.7, 0.0);
    //glRotatef(_ang_tri ,0.0, 0.0, 1.0);

    glBegin(GL_POLYGON);

    glColor3ub(0,0,0);

    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y+yr);
    }
    glEnd();


    glBegin(GL_POLYGON);

    glColor3ub(105,112,142);

    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.3;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y+yr);
    }
    glEnd();




    glBegin(GL_POLYGON);

    glColor3ub(155,0,0);

    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.45;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y+yr);
    }
    glEnd();

    glPopMatrix(); //Undo the move to the center of the trapezoid
    glPopMatrix();


    ///Character
    glPushMatrix();
    glScalef(0.3,0.3,0);
    glTranslatef(6.0+ch, -7.0, 0.0);


    glPushMatrix(); //Save the current state of transformations

    glTranslatef(-0.1, 0.6, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)


    /// bru

    glColor3ub(105,105,105);
    glBegin(GL_QUADS);

    glVertex3f(-0.20, 01.40, 0.0);
    glVertex3f(-0.10, 01.45, 0.0);
    glVertex3f(0.03,  01.44, 0.0);
    glVertex3f(0.01, 01.42,0);


    glVertex3f(-0.20, 01.40, 0.0);
    glVertex3f(-0.10, 01.45, 0.0);
    glVertex3f(-0.3,  01.44, 0.0);
    glVertex3f(-0.35, 01.32,0);



    //horne
    glColor3ub(255,0,0);



    glVertex3f(-0.4, 02.10, 0.0);
    glVertex3f(-0.12, 01.55, 0.0);
    glVertex3f(-0.3,  01.55, 0.0);
    glVertex3f(-0.4, 02.10,0);


    glVertex3f(0.08, 02.0, 0.0);
    glVertex3f(-0.2, 01.55, 0.0);
    glVertex3f(0.0,  01.55, 0.0);
    glVertex3f(0.08, 02.0,0);


    glVertex3f(-0.2, 02.0, 0.0);
    glVertex3f(-0.2, 01.55, 0.0);
    glVertex3f(0.0,  01.55, 0.0);
    glVertex3f(-0.2, 02.0,0);

    glVertex3f(0.22, 02.0, 0.0);
    glVertex3f(-0.09, 01.55, 0.0);
    glVertex3f(0.1,  01.55, 0.0);
    glVertex3f(0.22, 02.0,0);



    glVertex3f(0.30, 02.0, 0.0);
    glVertex3f(0.25, 01.55, 0.0);
    glVertex3f(0.05,  01.55, 0.0);
    glVertex3f(0.30, 02.0,0);


    glVertex3f(0.50, 02.0, 0.0);
    glVertex3f(0.4, 01.55, 0.0);
    glVertex3f(0.1,  01.55, 0.0);
    glVertex3f(0.50, 02.0,0);


    glVertex3f(0.80, 02.0, 0.0);
    glVertex3f(0.5, 01.55, 0.0);
    glVertex3f(0.3,  01.55, 0.0);
    glVertex3f(0.80, 02.0,0);

///mouth


    glVertex3f(-0.45, 0.95, 0.0);
    glVertex3f(-0.1, 0.8, 0.0);
    glVertex3f(-0.35,  0.85, 0.0);
    glVertex3f(-0.32, 0.90,0);


    glVertex3f(0.45, 01.85, 0.0);
    glVertex3f(0.1, 0.7, 0.0);
    glVertex3f(0.35,  0.7, 0.0);
    glVertex3f(0.32, 01.80,0);

    glColor3ub(105,105,105);

    glVertex3f(0.6, 01.58, 0.0);
    glVertex3f(0.6, 0.75, 0.0);
    glVertex3f(0.35,  0.6, 0.0);
    glVertex3f(0.35, 01.58,0);


    glVertex3f(0.7, 01.40, 0.0);
    glVertex3f(0.7, 0.85, 0.0);
    glVertex3f(0.5,  0.5, 0.0);
    glVertex3f(0.5, 01.58,0);







    glEnd();


    glPopMatrix();


    glPushMatrix(); //Save the current state of transformations
    //hand
    glTranslatef(-0.3, 1.85, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)
    glColor3ub(255,0,0);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();

    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
    //Head
    glTranslatef(0.0, 1.75, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)
    glColor3ub(173,255,47);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/10;
        float r=0.60;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();



    glPopMatrix(); //Undo the move to the center of the triangle


    glPushMatrix(); //Save the current state of transformations
    //hand
    glTranslatef(-0.1, 0.6, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)
    glColor3ub(0,0,205);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.15;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,255,255);

    glVertex3f(0.0,-0.1, 0.0);

    glColor3ub(75,0,130);
    glVertex3f(-0.7, -0.1, 0.0);
    glVertex3f(-0.7,0.1, 0.0);

    glColor3ub(0,255,255);
    glVertex3f(0.0,0.1,0);

    glColor3ub(188,143,143);

    glVertex3f(-0.7, -0.1, 0.0);
    glVertex3f(-0.7,0.1, 0.0);
    glVertex3f(-1.0, 0.3, 0.0);
    glVertex3f(-1.0,-0.3, 0.0);

    /// nick
    glColor3ub(165,42,42);
    glVertex3f(-0.2, 0.6, 0.0);
    glVertex3f(-0.2, 0.4, 0.0);
    glVertex3f(0.40,  0.4, 0.0);
    glVertex3f(0.40, 0.6,0);

    glEnd();


    glPopMatrix();


    ///Bullet

    glPushMatrix(); //Save the transformations performed thus far
    glTranslatef(x1, xy1, 0.0);
    glColor3ub(226,104,34);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.17;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();


    glPopMatrix();

    ///BulletEnd


    glPushMatrix(); //Save the current state of transformations
    //body
    glTranslatef(0.0, 1.2, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)


    glBegin(GL_QUADS);
    glColor3ub(184,134,11);
    glVertex3f(-0.53, -0.2, 0.0);
    glColor3ub(255,215,0);
    glVertex3f(0.53, -0.2, 0.0);
    glVertex3f(0.53,-1.6, 0.0);
    glColor3ub(184,134,11);
    glVertex3f(-0.53,-1.6,0);


    glEnd();


    glPopMatrix(); //Undo the move to the center of the triangle


    glPushMatrix(); //Save the current state of transformations
    //leg
    glTranslatef(-0.40, -0.65, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)

    glColor3ub(30,144,255);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();


    glColor3ub(139,69,19);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.25;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();


    glPopMatrix();

    glPushMatrix(); //Save the current state of transformations
    //leg
    glTranslatef(0.4, -0.65, 0.0); //Move to the center of the triangle
    //glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)


    glColor3ub(30,144,255);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }

    glEnd();




    glColor3ub(139,69,19);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.25;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }

    glEnd();



    glPopMatrix();

    glPopMatrix();


    ///tree start
    glPushMatrix();


    glBegin(GL_TRIANGLES);
    glColor3ub(0,255,0);

    glVertex3f(-2.1, -01.2, 0.0);
    glVertex3f(-2.05, -0.8, 0.0);
    glVertex3f(-2.0, -01.2, 0.0);


    glVertex3f(-1.1, -01.2, 0.0);
    glVertex3f(-1.05, -0.8, 0.0);
    glVertex3f(-1.0, -01.2, 0.0);

    /*glVertex3f(-0.04, -01.2, 0.0);
    glVertex3f(0.03, -0.8, 0.0);
    glVertex3f(0.07, -01.2, 0.0);*/


    glVertex3f(1.3, -01.2, 0.0);
    glVertex3f(1.25, -0.8, 0.0);
    glVertex3f(1.2, -01.2, 0.0);


    glVertex3f(2.3, -01.2, 0.0);
    glVertex3f(2.25, -0.8, 0.0);
    glVertex3f(2.20, -01.2, 0.0);


    glEnd();


    glPopMatrix();


///end tree

///picture
///stars

    glPushMatrix(); //Save the current state of transformations
    glTranslatef(-0.15, -01.35, 0.0); //Move to the center of the pentagon

    glScalef(0.50, 0.50, 0.0); //Scale by 0.7 in the x, y, and z directions
///root
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    /*
        glVertex3f(0.8, 0.5, 0.0);
        glVertex3f(0.8, 0.15, 0.0);
        glVertex3f(0.75, 0.15, 0.0);
        glVertex3f(0.75, 0.5, 0.0);*/

    glVertex3f(-1.8, 0.5, 0.0);
    glVertex3f(-1.8, 0.15, 0.0);
    glVertex3f(-1.75, 0.15, 0.0);
    glVertex3f(-1.75, 0.5, 0.0);


    glVertex3f(-3.8, 0.5, 0.0);
    glVertex3f(-3.8, 0.15, 0.0);
    glVertex3f(-3.75, 0.15, 0.0);
    glVertex3f(-3.75, 0.5, 0.0);


    glVertex3f(2.8, 0.5, 0.0);
    glVertex3f(2.8, 0.15, 0.0);
    glVertex3f(2.75, 0.15, 0.0);
    glVertex3f(2.75, 0.5, 0.0);


    glVertex3f(4.8, 0.5, 0.0);
    glVertex3f(4.8, 0.15, 0.0);
    glVertex3f(4.75, 0.15, 0.0);
    glVertex3f(4.75, 0.5, 0.0);

    glEnd();
    glPopMatrix();

    ///road  cross
    glPushMatrix(); //Save the current state of transformations
    glTranslatef(0.0, -2.60, 0.0); //Move to the center of the pentagon
    glScalef(0.50, 0.50, 0.0); //Scale by 0.7 in the x, y, and z directions

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    //Trapezoid
    glVertex3f(5.8, 0.30, 0.0);
    glVertex3f(5.8, 0.10, 0.0);
    glVertex3f(5.7, 0.10, 0.0);
    glVertex3f(5.7, 0.30, 0.0);

    glVertex3f(4.8, 0.30, 0.0);
    glVertex3f(4.8, 0.1, 0.0);
    glVertex3f(4.7, 0.1, 0.0);
    glVertex3f(4.7, 0.3, 0.0);


    glVertex3f(3.8, 0.3, 0.0);
    glVertex3f(3.8, 0.1, 0.0);
    glVertex3f(3.7, 0.1, 0.0);
    glVertex3f(3.7, 0.3, 0.0);

    glVertex3f(2.8, 0.3, 0.0);
    glVertex3f(2.8, 0.1, 0.0);
    glVertex3f(2.7, 0.1, 0.0);
    glVertex3f(2.7, 0.3, 0.0);


    glVertex3f(1.8, 0.3, 0.0);
    glVertex3f(1.8, 0.1, 0.0);
    glVertex3f(1.7, 0.1, 0.0);
    glVertex3f(1.7, 0.3, 0.0);

    glVertex3f(0.8, 0.3, 0.0);
    glVertex3f(0.8, 0.1, 0.0);
    glVertex3f(0.7, 0.1, 0.0);
    glVertex3f(0.7, 0.3, 0.0);

    glVertex3f(0.0, 0.3, 0.0);
    glVertex3f(0.0, 0.1, 0.0);
    glVertex3f(0.1, 0.1, 0.0);
    glVertex3f(0.1, 0.3, 0.0);

///

    glVertex3f(-0.8, 0.3, 0.0);
    glVertex3f(-0.8, 0.1, 0.0);
    glVertex3f(-0.7, 0.1, 0.0);
    glVertex3f(-0.7, 0.3, 0.0);

    glVertex3f(-1.8, 0.3, 0.0);
    glVertex3f(-1.8, 0.1, 0.0);
    glVertex3f(-1.7, 0.1, 0.0);
    glVertex3f(-1.7, 0.3, 0.0);


    glVertex3f(-2.8, 0.3, 0.0);
    glVertex3f(-2.8, 0.1, 0.0);
    glVertex3f(-2.7, 0.1, 0.0);
    glVertex3f(-2.7, 0.3, 0.0);

    glVertex3f(-3.8, 0.3, 0.0);
    glVertex3f(-3.8, 0.1, 0.0);
    glVertex3f(-3.7, 0.1, 0.0);
    glVertex3f(-3.7, 0.3, 0.0);


    glVertex3f(-4.8, 0.3, 0.0);
    glVertex3f(-4.8, 0.1, 0.0);
    glVertex3f(-4.7, 0.1, 0.0);
    glVertex3f(-4.7, 0.3, 0.0);


    glVertex3f(-5.8, 0.3, 0.0);
    glVertex3f(-5.8, 0.1, 0.0);
    glVertex3f(-5.7, 0.1, 0.0);
    glVertex3f(-5.7, 0.3, 0.0);
///end

    glEnd();
    glPopMatrix();



    ///picture
///stars
    glPushMatrix(); //Save the transformations performed thus far
    glScalef(0.50,0.50,0); //Move to the center of the trapezoid

    glBegin(GL_TRIANGLES);

    glColor3ub(255,255,0);
///star +1
    glVertex3f(-4.25, 4.50, 0.0);
    glVertex3f(-4.30, 4.60, 0.0);
    glVertex3f(-4.35, 4.50, 0.0);

    glVertex3f(-4.25, 4.55, 0.0);
    glVertex3f(-4.30, 4.45, 0.0);
    glVertex3f(-4.35, 4.55, 0.0);

///star -1

    glVertex3f(-5.25, 3.50, 0.0);
    glVertex3f(-5.30, 3.60, 0.0);
    glVertex3f(-5.35, 3.50, 0.0);

    glVertex3f(-5.25, 3.55, 0.0);
    glVertex3f(-5.30, 3.45, 0.0);
    glVertex3f(-5.35, 3.55, 0.0);


    glVertex3f(-5.25, 5.50, 0.0);
    glVertex3f(-5.30, 5.60, 0.0);
    glVertex3f(-5.35, 5.50, 0.0);

    glVertex3f(-5.25, 5.55, 0.0);
    glVertex3f(-5.30, 5.45, 0.0);
    glVertex3f(-5.35, 5.55, 0.0);


    glVertex3f(-1.25, 04.0, 0.0);
    glVertex3f(-1.30, 04.10, 0.0);
    glVertex3f(-1.35, 04.0, 0.0);

    glVertex3f(-1.25, 04.05, 0.0);
    glVertex3f(-1.30, 03.95, 0.0);
    glVertex3f(-1.35, 04.05, 0.0);

    glVertex3f(-0.25, 3.50, 0.0);
    glVertex3f(-0.30, 3.60, 0.0);
    glVertex3f(-0.35, 3.50, 0.0);

    glVertex3f(-0.25, 3.55, 0.0);
    glVertex3f(-0.30, 3.45, 0.0);
    glVertex3f(-0.35, 3.55, 0.0);

    glVertex3f(-0.25, 5.50, 0.0);
    glVertex3f(-0.30, 5.60, 0.0);
    glVertex3f(-0.35, 5.50, 0.0);

    glVertex3f(-0.25, 5.55, 0.0);
    glVertex3f(-0.30, 5.45, 0.0);
    glVertex3f(-0.35, 5.55, 0.0);

    glVertex3f(1.25, 5.0, 0.0);
    glVertex3f(1.30, 5.10, 0.0);
    glVertex3f(1.35, 5.0, 0.0);

    glVertex3f(1.25, 5.05, 0.0);
    glVertex3f(1.30, 4.95, 0.0);
    glVertex3f(1.35, 5.05, 0.0);

    glVertex3f(0.25, 4.50, 0.0);
    glVertex3f(0.30, 4.60, 0.0);
    glVertex3f(0.35, 4.50, 0.0);

    glVertex3f(0.25, 4.55, 0.0);
    glVertex3f(0.30, 4.45, 0.0);
    glVertex3f(0.35, 4.55, 0.0);

    glVertex3f(0.25, 2.50, 0.0);
    glVertex3f(0.30, 2.60, 0.0);
    glVertex3f(0.35, 2.50, 0.0);

    glVertex3f(0.25, 2.55, 0.0);
    glVertex3f(0.30, 2.45, 0.0);
    glVertex3f(0.35, 2.55, 0.0);


    glVertex3f(2.25, 4.50, 0.0);
    glVertex3f(2.30, 4.60, 0.0);
    glVertex3f(2.35, 4.50, 0.0);

    glVertex3f(2.25, 4.55, 0.0);
    glVertex3f(2.30, 4.45, 0.0);
    glVertex3f(2.35, 4.55, 0.0);

    glVertex3f(3.25, 4.60, 0.0);
    glVertex3f(3.30, 4.70, 0.0);
    glVertex3f(3.35, 4.60, 0.0);

    glVertex3f(3.25, 4.65, 0.0);
    glVertex3f(3.30, 4.55, 0.0);
    glVertex3f(3.35, 4.65, 0.0);


    glVertex3f(3.25, 5.50, 0.0);
    glVertex3f(3.30, 5.60, 0.0);
    glVertex3f(3.35, 5.50, 0.0);

    glVertex3f(3.25, 5.55, 0.0);
    glVertex3f(3.30, 5.45, 0.0);
    glVertex3f(3.35, 5.55, 0.0);

    glVertex3f(4.25, 3.50, 0.0);
    glVertex3f(4.30, 3.60, 0.0);
    glVertex3f(4.35, 3.50, 0.0);

    glVertex3f(4.25, 3.55, 0.0);
    glVertex3f(4.30, 3.45, 0.0);
    glVertex3f(4.35, 3.55, 0.0);

    ////////////////
    glVertex3f(-1.25, 5.50, 0.0);
    glVertex3f(-1.30, 5.60, 0.0);
    glVertex3f(-1.35, 5.50, 0.0);

    glVertex3f(-1.25, 5.55, 0.0);
    glVertex3f(-1.30, 5.45, 0.0);
    glVertex3f(-1.35, 5.55, 0.0);

    glVertex3f(-0.25, 3.50, 0.0);
    glVertex3f(-0.30, 3.60, 0.0);
    glVertex3f(-0.35, 3.50, 0.0);

    glVertex3f(0.25, 3.55, 0.0);
    glVertex3f(0.30, 3.45, 0.0);
    glVertex3f(0.35, 3.55, 0.0);




    glVertex3f(-2.25, 4.50, 0.0);
    glVertex3f(-2.30, 4.60, 0.0);
    glVertex3f(-2.35, 4.50, 0.0);

    glVertex3f(-2.25, 4.55, 0.0);
    glVertex3f(-2.30, 4.45, 0.0);
    glVertex3f(-2.35, 4.55, 0.0);

    glVertex3f(-3.25, 3.50, 0.0);
    glVertex3f(-3.30, 3.60, 0.0);
    glVertex3f(-3.35, 3.50, 0.0);

    glVertex3f(-3.25, 3.55, 0.0);
    glVertex3f(-3.30, 3.45, 0.0);
    glVertex3f(-3.35, 3.55, 0.0);

    glVertex3f(-3.25, 4.70, 0.0);
    glVertex3f(-3.30, 4.80, 0.0);
    glVertex3f(-3.35, 4.70, 0.0);

    glVertex3f(-3.25, 4.75, 0.0);
    glVertex3f(-3.30, 4.65, 0.0);
    glVertex3f(-3.35, 4.75, 0.0);

    glVertex3f(-5.25, 3.50, 0.0);
    glVertex3f(-5.30, 3.60, 0.0);
    glVertex3f(-5.35, 3.50, 0.0);

    glVertex3f(-5.25, 3.55, 0.0);
    glVertex3f(-5.30, 3.45, 0.0);
    glVertex3f(-5.35, 3.55, 0.0);


    glEnd();

    glPopMatrix(); //Undo the move to the center of the trapezoid


    glPushMatrix(); //Save the transformations performed thus far
    glTranslatef(-2.4, 0.4, 0.0);
    glScalef(1.0,0.90,0); //Move to the center of the trapezoid

    glBegin(GL_TRIANGLES);


    ///6th building


    glColor3ub(139,69,19);
    glVertex3f(3.45, 0.09, 0.0);
    glVertex3f(5.0, 0.09, 0.0);

    glColor3ub(240,255,255);
    glVertex3f(4.22, 0.70, 0.0);


    ///4th building
    glColor3ub(255,160,122);
    glVertex3f(01.80, -0.20, 0.0);
    glVertex3f(2.80, -0.20, 0.0);

    glColor3ub(240,255,255);
    glVertex3f(02.3, 0.40, 0.0);


    glEnd();


    glPopMatrix(); //Undo the move to the center of the trapezoid

    glPopMatrix(); //Undo the move to the center of the trapezoid



///lemp post

    glPushMatrix();




    glBegin(GL_QUADS);

    //Trapezoid

    glColor3ub(255,255,255);///light


    glVertex3f(2.60, -0.70, 0.0);
    glVertex3f(2.60, -0.75, 0.0);
    glVertex3f(2.68, -0.70, 0.0);
    glVertex3f(2.68, -0.60, 0.0);


    glVertex3f(1.6, -0.70, 0.0);
    glVertex3f(1.6, -0.75, 0.0);
    glVertex3f(1.68, -0.70, 0.0);
    glVertex3f(1.68, -0.60, 0.0);

    glVertex3f(0.60, -0.70, 0.0);
    glVertex3f(0.60, -0.75, 0.0);
    glVertex3f(0.68, -0.70, 0.0);
    glVertex3f(0.68, -0.60, 0.0);

    glVertex3f(-0.3, -0.60, 0.0);
    glVertex3f(-0.3, -0.70, 0.0);
    glVertex3f(-0.38, -0.75, 0.0);
    glVertex3f(-0.38, -0.70, 0.0);

    glVertex3f(-01.3, -0.60, 0.0);
    glVertex3f(-01.3, -0.70, 0.0);
    glVertex3f(-1.38, -0.75, 0.0);
    glVertex3f(-1.38, -0.70, 0.0);


    glVertex3f(-02.3, -0.60, 0.0);
    glVertex3f(-02.3, -0.70, 0.0);
    glVertex3f(-2.38, -0.75, 0.0);
    glVertex3f(-2.38, -0.70, 0.0);



    glColor3ub(160,82,45);

    glVertex3f(-02.47, -0.60, 0.0);
    glVertex3f(-02.47, -01.3, 0.0);
    glVertex3f(-2.5, -01.3, 0.0);
    glVertex3f(-2.5, -0.60, 0.0);


    glVertex3f(-01.47, -0.60, 0.0);
    glVertex3f(-01.47, -01.3, 0.0);
    glVertex3f(-1.5, -01.3, 0.0);
    glVertex3f(-1.5, -0.60, 0.0);


    glVertex3f(-0.47, -0.60, 0.0);
    glVertex3f(-0.47, -01.3, 0.0);
    glVertex3f(-0.5, -01.3, 0.0);
    glVertex3f(-0.5, -0.60, 0.0);


    glVertex3f(0.47, -0.60, 0.0);
    glVertex3f(0.47, -01.3, 0.0);
    glVertex3f(0.5, -01.3, 0.0);
    glVertex3f(0.5, -0.60, 0.0);


    glVertex3f(1.47, -0.60, 0.0);
    glVertex3f(1.47, -01.3, 0.0);
    glVertex3f(1.5, -01.3, 0.0);
    glVertex3f(1.5, -0.60, 0.0);



    glVertex3f(2.47, -0.60, 0.0);
    glVertex3f(2.47, -01.3, 0.0);
    glVertex3f(2.5, -01.3, 0.0);
    glVertex3f(2.5, -0.60, 0.0);


    ///

    glVertex3f(2.5, -0.70, 0.0);
    glVertex3f(2.5, -0.75, 0.0);
    glVertex3f(2.7, -0.70, 0.0);
    glVertex3f(2.7, -0.60, 0.0);

    glVertex3f(1.5, -0.70, 0.0);
    glVertex3f(1.5, -0.75, 0.0);
    glVertex3f(1.7, -0.70, 0.0);
    glVertex3f(1.7, -0.60, 0.0);

    glVertex3f(0.5, -0.70, 0.0);
    glVertex3f(0.5, -0.75, 0.0);
    glVertex3f(0.7, -0.70, 0.0);
    glVertex3f(0.7, -0.60, 0.0);

    glVertex3f(-0.5, -0.70, 0.0);
    glVertex3f(-0.5, -0.75, 0.0);
    glVertex3f(-0.3, -0.70, 0.0);
    glVertex3f(-0.3, -0.60, 0.0);

    glVertex3f(-01.5, -0.70, 0.0);
    glVertex3f(-01.5, -0.75, 0.0);
    glVertex3f(-1.3, -0.70, 0.0);
    glVertex3f(-1.3, -0.60, 0.0);


    glVertex3f(-02.5, -0.70, 0.0);
    glVertex3f(-02.5, -0.75, 0.0);
    glVertex3f(-2.3, -0.70, 0.0);
    glVertex3f(-2.3, -0.60, 0.0);


    glEnd();

    glPopMatrix();



///end lamp post



///foot ware

    glPushMatrix(); //Save the current state of transformations
    glTranslatef(0.0, -1.35, 0.0); //Move to the center of the pentagon
    glScalef(0.50, 0.20, 0.0); //Scale by 0.7 in the x, y, and z directions

    glBegin(GL_QUADS);


    glColor3ub(205,133,63);///road hight line

    glVertex3f(5.75, 0.25, 0.0);
    glVertex3f(6.0, -0.12, 0.0);
    glVertex3f(-6.0, -0.12, 0.0);
    glVertex3f(-5.75, 0.25, 0.0);

    glColor3ub(188,143,143);
    ///up road
    glVertex3f(6.0, 01.25, 0.0);

    glColor3ub(0,0,0);
    glVertex3f(6.0, -0.12, 0.0);
    glVertex3f(-6.0, -0.12, 0.0);

    glColor3ub(188,143,143);
    glVertex3f(-6.0, 01.25, 0.0);

    glColor3ub(205,133,63);///road hight

    glVertex3f(6.0, -5.50, 0.0);
    glVertex3f(5.80, -6.10, 0.0);
    glVertex3f(-5.80, -6.10, 0.0);
    glVertex3f(-6.0, -5.50, 0.0);


///bottom

    glColor3ub(50,205,50);
    glVertex3f(6.0, -8.0, 0.0);

    glColor3ub(255,215,0);
    glVertex3f(6.0, -5.50, 0.0);

    glColor3ub(50,205,50);
    glVertex3f(-6.0, -5.50, 0.0);
    glVertex3f(-6.0, -8.0, 0.0);


    ///1st building

    glColor3ub(25,25,50);
    ///door

    glVertex3f(-4.60, 4.50, 0.0);
    glVertex3f(-4.60, 1.50, 0.0);
    glVertex3f(-5.20, 1.50, 0.0);
    glVertex3f(-5.20, 4.50, 0.0);

    glColor3ub(128,128,0);

    glVertex3f(-4.50, 4.50, 0.0);
    glVertex3f(-4.50, 5.0, 0.0);
    glVertex3f(-5.30, 5.0, 0.0);
    glVertex3f(-5.30, 4.50, 0.0);

    glColor3ub(218,165,32);///base

    glVertex3f(-5.90, 1.50, 0.0);
    glVertex3f(-5.90, 1.20, 0.0);
    glVertex3f(-4.0, 1.20, 0.0);
    glVertex3f(-4.0, 1.50, 0.0);
/// 2 line
    glColor3ub(210,115,105);

    glVertex3f(-5.60, 12.0, 0.0);
    glVertex3f(-5.60, 2.50, 0.0);
    glVertex3f(-5.50, 2.50, 0.0);
    glVertex3f(-5.50, 12.0, 0.0);

    glVertex3f(-4.30, 12.0, 0.0);
    glVertex3f(-4.30, 2.50, 0.0);
    glVertex3f(-4.20, 2.50, 0.0);
    glVertex3f(-4.20, 12.0, 0.0);

    glColor3ub(15,42,42);///windows

    glVertex3f(-5.40, 8.90, 0.0);
    glVertex3f(-5.40, 8.30, 0.0);
    glVertex3f(-5.10, 8.30, 0.0);
    glVertex3f(-5.10, 8.90, 0.0);

    glVertex3f(-5.0, 8.90, 0.0);
    glVertex3f(-5.0, 8.30, 0.0);
    glVertex3f(-4.8, 8.30, 0.0);
    glVertex3f(-4.8, 8.90, 0.0);


    glVertex3f(-4.70, 8.90, 0.0);
    glVertex3f(-4.70, 8.30, 0.0);
    glVertex3f(-4.40, 8.30, 0.0);
    glVertex3f(-4.40, 8.90, 0.0);



    ///

    glVertex3f(-5.40, 9.90, 0.0);
    glVertex3f(-5.40, 9.30, 0.0);
    glVertex3f(-5.10, 9.30, 0.0);
    glVertex3f(-5.10, 9.90, 0.0);

    glVertex3f(-5.0, 9.90, 0.0);
    glVertex3f(-5.0, 9.30, 0.0);
    glVertex3f(-4.8, 9.30, 0.0);
    glVertex3f(-4.8, 9.90, 0.0);


    glVertex3f(-4.70, 9.90, 0.0);
    glVertex3f(-4.70, 9.30, 0.0);
    glVertex3f(-4.40, 9.30, 0.0);
    glVertex3f(-4.40, 9.90, 0.0);

    ///

    glVertex3f(-5.40, 10.90, 0.0);
    glVertex3f(-5.40, 10.30, 0.0);
    glVertex3f(-5.10, 10.30, 0.0);
    glVertex3f(-5.10, 10.90, 0.0);

    glVertex3f(-5.0, 10.90, 0.0);
    glVertex3f(-5.0, 10.30, 0.0);
    glVertex3f(-4.8, 10.30, 0.0);
    glVertex3f(-4.8, 10.90, 0.0);


    glVertex3f(-4.70, 10.90, 0.0);
    glVertex3f(-4.70, 10.30, 0.0);
    glVertex3f(-4.40, 10.30, 0.0);
    glVertex3f(-4.40, 10.90, 0.0);

    ///

    glVertex3f(-5.10, 7.50, 0.0);
    glVertex3f(-5.10, 5.30, 0.0);
    glVertex3f(-4.73, 5.30, 0.0);
    glVertex3f(-4.73, 7.50, 0.0);

    glVertex3f(-5.10, 12.50, 0.0);
    glVertex3f(-5.10, 11.50, 0.0);
    glVertex3f(-4.73, 11.50, 0.0);
    glVertex3f(-4.73, 12.50, 0.0);

    glColor3ub(100,200,205);///body


    glVertex3f(-5.70, 12.50, 0.0);
    glVertex3f(-5.70, 1.25, 0.0);
    glVertex3f(-4.10, 1.25, 0.0);
    glVertex3f(-4.10, 12.50, 0.0);

///2nd building

    glColor3ub(255,255,224);///windows

    glVertex3f(-3.80, 3.0, 0.0);
    glVertex3f(-3.80, 2.0, 0.0);
    glVertex3f(-3.60, 2.0, 0.0);
    glVertex3f(-3.60, 3.0, 0.0);

    glVertex3f(-3.80, 5.0, 0.0);
    glVertex3f(-3.80, 4.0, 0.0);
    glVertex3f(-3.60, 4.0, 0.0);
    glVertex3f(-3.60, 5.0, 0.0);


    glVertex3f(-3.80, 7.0, 0.0);
    glVertex3f(-3.80, 6.0, 0.0);
    glVertex3f(-3.60, 6.0, 0.0);
    glVertex3f(-3.60, 7.0, 0.0);

    glVertex3f(-3.80, 9.0, 0.0);
    glVertex3f(-3.80, 8.0, 0.0);
    glVertex3f(-3.60, 8.0, 0.0);
    glVertex3f(-3.60, 9.0, 0.0);


    glVertex3f(-3.20, 3.0, 0.0);
    glVertex3f(-3.20, 2.0, 0.0);
    glVertex3f(-3.0, 2.0, 0.0);
    glVertex3f(-3.0, 3.0, 0.0);

    glVertex3f(-3.20, 5.0, 0.0);
    glVertex3f(-3.20, 4.0, 0.0);
    glVertex3f(-3.0, 4.0, 0.0);
    glVertex3f(-3.0, 5.0, 0.0);

    glVertex3f(-3.20, 7.0, 0.0);
    glVertex3f(-3.20, 6.0, 0.0);
    glVertex3f(-3.0, 6.0, 0.0);
    glVertex3f(-3.0, 7.0, 0.0);

    glVertex3f(-3.20, 9.0, 0.0);
    glVertex3f(-3.20, 8.0, 0.0);
    glVertex3f(-3.0, 8.0, 0.0);
    glVertex3f(-3.0, 9.0, 0.0);

    glColor3ub(210,105,30);///base

    glVertex3f(-4.0, 1.50, 0.0);
    glVertex3f(-4.0, 1.20, 0.0);
    glVertex3f(-2.78, 1.20, 0.0);
    glVertex3f(-2.78, 1.50, 0.0);

    glColor3ub(143,188,143);

    glVertex3f(-4.0, 10.50, 0.0);
    glVertex3f(-4.0, 1.20, 0.0);
    glVertex3f(-2.80, 1.20, 0.0);
    glVertex3f(-2.80, 10.50, 0.0);

    glVertex3f(-3.90, 11.50, 0.0);
    glVertex3f(-3.90, 10.50, 0.0);
    glVertex3f(-3.20, 10.50, 0.0);
    glVertex3f(-3.20, 11.50, 0.0);



///3rd building

    glColor3ub(176,196,222);///base

    glVertex3f(-2.78, 1.50, 0.0);
    glVertex3f(-2.78, 1.20, 0.0);
    glVertex3f(-1.7, 1.20, 0.0);
    glVertex3f(-1.7, 1.50, 0.0);

    glColor3ub(255,255,255);///line


    glVertex3f(-2.60, 2.50, 0.0);
    glVertex3f(-2.60, 2.30, 0.0);
    glVertex3f(-1.90, 2.30, 0.0);
    glVertex3f(-1.90, 2.50, 0.0);

    glVertex3f(-2.60, 2.60, 0.0);
    glVertex3f(-2.60, 2.80, 0.0);
    glVertex3f(-1.90, 2.80, 0.0);
    glVertex3f(-1.90, 2.60, 0.0);

    glVertex3f(-2.60, 4.50, 0.0);
    glVertex3f(-2.60, 4.30, 0.0);
    glVertex3f(-1.90, 4.30, 0.0);
    glVertex3f(-1.90, 4.50, 0.0);

    glVertex3f(-2.60, 4.60, 0.0);
    glVertex3f(-2.60, 4.80, 0.0);
    glVertex3f(-1.90, 4.80, 0.0);
    glVertex3f(-1.90, 4.60, 0.0);

    glVertex3f(-2.60, 6.50, 0.0);
    glVertex3f(-2.60, 6.30, 0.0);
    glVertex3f(-1.90, 6.30, 0.0);
    glVertex3f(-1.90, 6.50, 0.0);

    glVertex3f(-2.60, 6.60, 0.0);
    glVertex3f(-2.60, 6.80, 0.0);
    glVertex3f(-1.90, 6.80, 0.0);
    glVertex3f(-1.90, 6.60, 0.0);

    glVertex3f(-2.60, 8.50, 0.0);
    glVertex3f(-2.60, 8.30, 0.0);
    glVertex3f(-1.90, 8.30, 0.0);
    glVertex3f(-1.90, 8.50, 0.0);

    glVertex3f(-2.60, 8.60, 0.0);
    glVertex3f(-2.60, 8.80, 0.0);
    glVertex3f(-1.90, 8.80, 0.0);
    glVertex3f(-1.90, 8.60, 0.0);




    glVertex3f(-2.50, 9.50, 0.0);
    glVertex3f(-2.50, 2.20, 0.0);
    glVertex3f(-2.40, 2.20, 0.0);
    glVertex3f(-2.40, 9.50, 0.0);

    glVertex3f(-2.0, 9.50, 0.0);
    glVertex3f(-2.0, 2.20, 0.0);
    glVertex3f(-2.10, 2.20, 0.0);
    glVertex3f(-2.10, 9.50, 0.0);

    glColor3ub(255,127,80);///body

    glVertex3f(-2.70, 9.50, 0.0);
    glVertex3f(-2.70, 1.20, 0.0);
    glVertex3f(-1.80, 1.20, 0.0);
    glVertex3f(-1.80, 9.50, 0.0);




    ///4th building

///up base

    glVertex3f(-1.20, 6.70, 0.0);
    glVertex3f(-1.20, 6.50, 0.0);
    glVertex3f(0.80, 6.50, 0.0);
    glVertex3f(0.80, 6.70, 0.0);


    glColor3ub(139,69,19);///basement

    glVertex3f(-1.70, 1.50, 0.0);
    glVertex3f(-1.70, 1.20, 0.0);
    glVertex3f(1.25, 1.20, 0.0);
    glVertex3f(1.25, 1.50, 0.0);


    glColor3ub(127,255,212);

    ///upper pillar

    glVertex3f(-0.6, 8.0, 0.0);
    glVertex3f(-0.6, 6.50, 0.0);
    glVertex3f(-0.8, 6.50, 0.0);
    glVertex3f(-0.8, 8.0, 0.0);

    glColor3ub(238,232,170);

    glVertex3f(-0.5, 8.0, 0.0);
    glVertex3f(-0.5, 6.50, 0.0);
    glVertex3f(-0.4, 6.50, 0.0);
    glVertex3f(-0.4, 8.0, 0.0);

    glColor3ub(127,255,212);

    glVertex3f(0.20, 8.0, 0.0);
    glVertex3f(0.20, 6.50, 0.0);
    glVertex3f(0.4, 6.50, 0.0);
    glVertex3f(0.4, 8.0, 0.0);

    glColor3ub(238,232,170);

    glVertex3f(0.0, 8.0, 0.0);
    glVertex3f(0.0, 6.50, 0.0);
    glVertex3f(0.1, 6.50, 0.0);
    glVertex3f(0.1, 8.0, 0.0);

    ///main gate
    glVertex3f(-0.37, 3.60, 0.0);
    glVertex3f(-0.37, 1.20, 0.0);
    glVertex3f(-0.08, 1.20, 0.0);
    glVertex3f(-0.08, 3.60, 0.0);



    glColor3ub(255,140,0);

    glVertex3f(-0.550, 5.40, 0.0);
    glVertex3f(-0.550, 1.20, 0.0);
    glVertex3f(0.10, 1.20, 0.0);
    glVertex3f(0.10, 5.40, 0.0);

    glColor3ub(255,255,255);///mid base

    glVertex3f(-1.70, 4.50, 0.0);
    glVertex3f(-1.70, 4.20, 0.0);
    glVertex3f(1.25, 4.20, 0.0);
    glVertex3f(1.25, 4.50, 0.0);


    glVertex3f(-0.62, 5.80, 0.0);
    glVertex3f(-0.62, 5.40, 0.0);
    glVertex3f(0.20, 5.40, 0.0);
    glVertex3f(0.20, 5.80, 0.0);

    glColor3ub(180,215,25);

    ///upper body
    glVertex3f(-1.20, 6.50, 0.0);
    glVertex3f(-1.20, 4.50, 0.0);
    glVertex3f(0.80, 4.50, 0.0);
    glVertex3f(0.80, 6.50, 0.0);

    glColor3ub(47,79,79);

///door
    glVertex3f(-1.50, 3.20, 0.0);
    glVertex3f(-1.50, 1.20, 0.0);
    glVertex3f(-1.25, 1.20, 0.0);
    glVertex3f(-1.25, 3.20, 0.0);

    glVertex3f(-1.1, 3.20, 0.0);
    glVertex3f(-1.1, 1.20, 0.0);
    glVertex3f(-0.85, 1.20, 0.0);
    glVertex3f(-0.85, 3.20, 0.0);

    glVertex3f(0.75, 3.20, 0.0);
    glVertex3f(0.75, 1.20, 0.0);
    glVertex3f(1.0, 1.20, 0.0);
    glVertex3f(1.0, 3.20, 0.0);

    glVertex3f(0.35, 3.20, 0.0);
    glVertex3f(0.35, 1.20, 0.0);
    glVertex3f(0.60, 1.20, 0.0);
    glVertex3f(0.60, 3.20, 0.0);


    glColor3ub(180,215,25);
///lower body
    glVertex3f(-1.60, 4.50, 0.0);
    glVertex3f(-1.60, 1.40, 0.0);
    glVertex3f(1.15, 1.40, 0.0);
    glVertex3f(1.15, 4.50, 0.0);



    ///5th building


    glColor3ub(255,255,255);///base

    glVertex3f(1.40, 1.50, 0.0);
    glVertex3f(1.40, 1.20, 0.0);
    glVertex3f(5.80, 1.20, 0.0);
    glVertex3f(5.80, 1.50, 0.0);

    glColor3ub(255,255,224);///mid window

    glVertex3f(2.70, 8.0, 0.0);
    glVertex3f(2.70, 7.20, 0.0);
    glVertex3f(3.0, 7.20, 0.0);
    glVertex3f(3.0, 8.0, 0.0);

    glVertex3f(2.7, 7.0, 0.0);
    glVertex3f(2.70, 6.20, 0.0);
    glVertex3f(3.0, 6.20, 0.0);
    glVertex3f(3.0, 7.0, 0.0);

    glVertex3f(2.70, 6.0, 0.0);
    glVertex3f(2.70, 5.20, 0.0);
    glVertex3f(3.0, 5.20, 0.0);
    glVertex3f(3.0, 6.0, 0.0);

    glVertex3f(2.70, 5.0, 0.0);
    glVertex3f(2.70, 4.20, 0.0);
    glVertex3f(3.0, 4.20, 0.0);
    glVertex3f(3.0, 5.0, 0.0);
    ///
    glVertex3f(3.10, 8.0, 0.0);
    glVertex3f(3.10, 7.20, 0.0);
    glVertex3f(3.40, 7.20, 0.0);
    glVertex3f(3.40, 8.0, 0.0);

    glVertex3f(3.1, 7.0, 0.0);
    glVertex3f(3.10, 6.20, 0.0);
    glVertex3f(3.40, 6.20, 0.0);
    glVertex3f(3.40, 7.0, 0.0);

    glVertex3f(3.10, 6.0, 0.0);
    glVertex3f(3.10, 5.20, 0.0);
    glVertex3f(3.40, 5.20, 0.0);
    glVertex3f(3.40, 6.0, 0.0);

    glVertex3f(3.10, 5.0, 0.0);
    glVertex3f(3.10, 4.20, 0.0);
    glVertex3f(3.40, 4.20, 0.0);
    glVertex3f(3.40, 5.0, 0.0);
    ///
    ///
    glVertex3f(3.50, 8.0, 0.0);
    glVertex3f(3.50, 7.20, 0.0);
    glVertex3f(3.80, 7.20, 0.0);
    glVertex3f(3.80, 8.0, 0.0);

    glVertex3f(3.5, 7.0, 0.0);
    glVertex3f(3.5, 6.20, 0.0);
    glVertex3f(3.80, 6.20, 0.0);
    glVertex3f(3.80, 7.0, 0.0);

    glVertex3f(3.50, 6.0, 0.0);
    glVertex3f(3.50, 5.20, 0.0);
    glVertex3f(3.80, 5.20, 0.0);
    glVertex3f(3.80, 6.0, 0.0);

    glVertex3f(3.50, 5.0, 0.0);
    glVertex3f(3.50, 4.20, 0.0);
    glVertex3f(3.80, 4.20, 0.0);
    glVertex3f(3.80, 5.0, 0.0);

    ///

    glVertex3f(3.90, 8.0, 0.0);
    glVertex3f(3.90, 7.20, 0.0);
    glVertex3f(4.20, 7.20, 0.0);
    glVertex3f(4.20, 8.0, 0.0);

    glVertex3f(3.9, 7.0, 0.0);
    glVertex3f(3.9, 6.20, 0.0);
    glVertex3f(4.20, 6.20, 0.0);
    glVertex3f(4.20, 7.0, 0.0);

    glVertex3f(3.90, 6.0, 0.0);
    glVertex3f(3.90, 5.20, 0.0);
    glVertex3f(4.20, 5.20, 0.0);
    glVertex3f(4.20, 6.0, 0.0);

    glVertex3f(3.90, 5.0, 0.0);
    glVertex3f(3.90, 4.20, 0.0);
    glVertex3f(4.20, 4.20, 0.0);
    glVertex3f(4.20, 5.0, 0.0);

    ///
    ///
    glVertex3f(4.30, 8.0, 0.0);
    glVertex3f(4.30, 7.20, 0.0);
    glVertex3f(4.60, 7.20, 0.0);
    glVertex3f(4.60, 8.0, 0.0);

    glVertex3f(4.3, 7.0, 0.0);
    glVertex3f(4.3, 6.20, 0.0);
    glVertex3f(4.60, 6.20, 0.0);
    glVertex3f(4.60, 7.0, 0.0);

    glVertex3f(4.30, 6.0, 0.0);
    glVertex3f(4.30, 5.20, 0.0);
    glVertex3f(4.60, 5.20, 0.0);
    glVertex3f(4.60, 6.0, 0.0);

    glVertex3f(4.30, 5.0, 0.0);
    glVertex3f(4.30, 4.20, 0.0);
    glVertex3f(4.60, 4.20, 0.0);
    glVertex3f(4.60, 5.0, 0.0);

    ///door

    glColor3ub(255,255,0);
    glVertex3f(3.26, 4.0, 0.0);
    glVertex3f(3.26, 3.80, 0.0);
    glVertex3f(4.04, 3.80, 0.0);
    glVertex3f(4.04, 4.0, 0.0);

    glColor3ub(30,144,255);

    glVertex3f(3.30, 3.80, 0.0);
    glVertex3f(3.30, 1.20, 0.0);
    glVertex3f(4.0, 1.20, 0.0);
    glVertex3f(4.0, 3.80, 0.0);

    glColor3ub(255,255,0);///

    glVertex3f(2.15, 9.20, 0.0);
    glVertex3f(2.15, 9.0, 0.0);
    glVertex3f(5.20, 9.0, 0.0);
    glVertex3f(5.20, 9.20, 0.0);

    glColor3ub(244,164,96);///body

    glVertex3f(2.50, 9.20, 0.0);
    glVertex3f(2.50, 1.20, 0.0);
    glVertex3f(4.70, 1.20, 0.0);
    glVertex3f(4.70, 9.20, 0.0);

    glColor3ub(128,128,0);///

    glVertex3f(2.0, 7.80, 0.0);
    glVertex3f(2.0, 6.50, 0.0);
    glVertex3f(5.30, 6.50, 0.0);
    glVertex3f(5.30, 7.80, 0.0);

    glColor3ub(255,105,180);///base upper

    glVertex3f(1.40, 6.50, 0.0);
    glVertex3f(1.40, 6.20, 0.0);
    glVertex3f(5.80, 6.20, 0.0);
    glVertex3f(5.80, 6.50, 0.0);


    glColor3ub(65,105,225);///inside windows

    glVertex3f(1.60, 6.0, 0.0);
    glVertex3f(1.60, 5.20, 0.0);
    glVertex3f(1.90, 5.20, 0.0);
    glVertex3f(1.90, 6.0, 0.0);

    glVertex3f(1.60, 5.0, 0.0);
    glVertex3f(1.60, 4.20, 0.0);
    glVertex3f(1.90, 4.20, 0.0);
    glVertex3f(1.90, 5.0, 0.0);

    glVertex3f(1.60, 4.0, 0.0);
    glVertex3f(1.60, 3.20, 0.0);
    glVertex3f(1.90, 3.20, 0.0);
    glVertex3f(1.90, 4.0, 0.0);

    glVertex3f(2.10, 6.0, 0.0);
    glVertex3f(2.10, 5.20, 0.0);
    glVertex3f(2.4, 5.20, 0.0);
    glVertex3f(2.4, 6.0, 0.0);

    glVertex3f(2.1, 5.0, 0.0);
    glVertex3f(2.10, 4.20, 0.0);
    glVertex3f(2.40, 4.20, 0.0);
    glVertex3f(2.40, 5.0, 0.0);

    glVertex3f(2.10, 4.0, 0.0);
    glVertex3f(2.10, 3.20, 0.0);
    glVertex3f(2.40, 3.20, 0.0);
    glVertex3f(2.40, 4.0, 0.0);

    ///

    glVertex3f(5.30, 6.0, 0.0);
    glVertex3f(5.30, 5.20, 0.0);
    glVertex3f(5.60, 5.20, 0.0);
    glVertex3f(5.60, 6.0, 0.0);

    glVertex3f(5.3, 5.0, 0.0);
    glVertex3f(5.30, 4.20, 0.0);
    glVertex3f(5.60, 4.20, 0.0);
    glVertex3f(5.60, 5.0, 0.0);

    glVertex3f(5.30, 4.0, 0.0);
    glVertex3f(5.30, 3.20, 0.0);
    glVertex3f(5.60, 3.20, 0.0);
    glVertex3f(5.60, 4.0, 0.0);

    glVertex3f(4.80, 6.0, 0.0);
    glVertex3f(4.80, 5.20, 0.0);
    glVertex3f(5.1, 5.20, 0.0);
    glVertex3f(5.1, 6.0, 0.0);

    glVertex3f(4.8, 5.0, 0.0);
    glVertex3f(4.80, 4.20, 0.0);
    glVertex3f(5.10, 4.20, 0.0);
    glVertex3f(5.10, 5.0, 0.0);

    glVertex3f(4.80, 4.0, 0.0);
    glVertex3f(4.80, 3.20, 0.0);
    glVertex3f(5.10, 3.20, 0.0);
    glVertex3f(5.10, 4.0, 0.0);



    glColor3ub(255,205,255);///main

    glVertex3f(1.50, 6.20, 0.0);
    glVertex3f(1.50, 1.20, 0.0);
    glVertex3f(5.70, 1.20, 0.0);
    glVertex3f(5.70, 6.20, 0.0);


///6th building backward


    glColor3ub(255,255,255);///building 5

///windows

    glVertex3f(1.0, 9.50, 0.0);
    glVertex3f(1.0, 9.25, 0.0);
    glVertex3f(0.90, 9.25, 0.0);
    glVertex3f(0.90, 9.50, 0.0);

    glVertex3f(1.10, 9.50, 0.0);
    glVertex3f(1.10, 9.25, 0.0);
    glVertex3f(1.20, 9.25, 0.0);
    glVertex3f(1.20, 9.50, 0.0);

    glVertex3f(1.30, 9.50, 0.0);
    glVertex3f(1.30, 9.25, 0.0);
    glVertex3f(1.40, 9.25, 0.0);
    glVertex3f(1.40, 9.50, 0.0);


    glVertex3f(1.50, 9.50, 0.0);
    glVertex3f(1.50, 9.25, 0.0);
    glVertex3f(1.60, 9.25, 0.0);
    glVertex3f(1.60, 9.50, 0.0);

////**********

    glVertex3f(1.0, 8.50, 0.0);
    glVertex3f(1.0, 8.25, 0.0);
    glVertex3f(0.90, 8.25, 0.0);
    glVertex3f(0.90, 8.50, 0.0);

    glVertex3f(1.10, 8.50, 0.0);
    glVertex3f(1.10, 8.25, 0.0);
    glVertex3f(1.20, 8.25, 0.0);
    glVertex3f(1.20, 8.50, 0.0);

    glVertex3f(1.30, 8.50, 0.0);
    glVertex3f(1.30, 8.25, 0.0);
    glVertex3f(1.40, 8.25, 0.0);
    glVertex3f(1.40, 8.50, 0.0);


    glVertex3f(1.50, 8.50, 0.0);
    glVertex3f(1.50, 8.25, 0.0);
    glVertex3f(1.60, 8.25, 0.0);
    glVertex3f(1.60, 8.50, 0.0);
//**********

    glVertex3f(1.0, 7.50, 0.0);
    glVertex3f(1.0, 7.25, 0.0);
    glVertex3f(0.90, 7.25, 0.0);
    glVertex3f(0.90, 7.50, 0.0);

    glVertex3f(1.10, 7.50, 0.0);
    glVertex3f(1.10, 7.25, 0.0);
    glVertex3f(1.20, 7.25, 0.0);
    glVertex3f(1.20, 7.50, 0.0);

    glVertex3f(1.30, 7.50, 0.0);
    glVertex3f(1.30,7.25, 0.0);
    glVertex3f(1.40, 7.25, 0.0);
    glVertex3f(1.40, 7.50, 0.0);


    glVertex3f(1.50, 7.50, 0.0);
    glVertex3f(1.50, 7.25, 0.0);
    glVertex3f(1.60, 7.25, 0.0);
    glVertex3f(1.60, 7.50, 0.0);

    glColor3ub(218,165,32);///main5


    glVertex3f(0.80, 10.20, 0.0);

    glColor3ub(105,105,105);
    glVertex3f(0.80, 1.20, 0.0);
    glVertex3f(1.70, 1.20, 0.0);

    glColor3ub(218,165,32);
    glVertex3f(1.70, 10.20, 0.0);


    glColor3ub(255,255,255);///building 6

///windows

    glVertex3f(1.70, 11.50, 0.0);
    glVertex3f(1.70, 11.25, 0.0);
    glVertex3f(1.80, 11.25, 0.0);
    glVertex3f(1.80, 11.50, 0.0);

    glVertex3f(1.70, 10.50, 0.0);
    glVertex3f(1.70, 10.25, 0.0);
    glVertex3f(1.80, 10.25, 0.0);
    glVertex3f(1.80, 10.50, 0.0);

    glVertex3f(2.20, 10.50, 0.0);
    glVertex3f(2.20, 10.25, 0.0);
    glVertex3f(2.30,10.25, 0.0);
    glVertex3f(2.30, 10.50, 0.0);

    glVertex3f(2.20, 11.50, 0.0);
    glVertex3f(2.20, 11.25, 0.0);
    glVertex3f(2.30,11.25, 0.0);
    glVertex3f(2.30, 11.50, 0.0);


    glVertex3f(1.950, 11.50, 0.0);
    glVertex3f(1.950, 10.25, 0.0);
    glVertex3f(2.10,  10.25, 0.0);
    glVertex3f(2.10, 11.50, 0.0);


////**********
    glVertex3f(1.70, 8.50, 0.0);
    glVertex3f(1.70, 8.25, 0.0);
    glVertex3f(1.80, 8.25, 0.0);
    glVertex3f(1.80, 8.50, 0.0);

    glVertex3f(1.70, 7.50, 0.0);
    glVertex3f(1.70, 7.25, 0.0);
    glVertex3f(1.80, 7.25, 0.0);
    glVertex3f(1.80, 7.50, 0.0);

    glVertex3f(2.20, 7.50, 0.0);
    glVertex3f(2.20, 7.25, 0.0);
    glVertex3f(2.30, 7.25, 0.0);
    glVertex3f(2.30, 7.50, 0.0);

    glVertex3f(2.20, 8.50, 0.0);
    glVertex3f(2.20, 8.25, 0.0);
    glVertex3f(2.30, 8.25, 0.0);
    glVertex3f(2.30, 8.50, 0.0);


    glVertex3f(1.950, 8.50, 0.0);
    glVertex3f(1.950, 7.25, 0.0);
    glVertex3f(2.10,  7.25, 0.0);
    glVertex3f(2.10, 8.50, 0.0);

//**********


    glColor3ub(105,105,105);///main6

    glVertex3f(01.60, 12.20, 0.0);
    glVertex3f(01.60, 1.20, 0.0);
    glVertex3f(2.40, 1.20, 0.0);
    glVertex3f(2.40, 12.20, 0.0);

    glColor3ub(255,255,255);///building 7

    glVertex3f(04.80, 11.0, 0.0);
    glVertex3f(04.80, 10.50, 0.0);
    glVertex3f(4.70, 10.50, 0.0);
    glVertex3f(4.70, 11.0, 0.0);

    glVertex3f(04.80, 10.0, 0.0);
    glVertex3f(04.80, 9.50, 0.0);
    glVertex3f(4.70, 9.50, 0.0);
    glVertex3f(4.70, 10.0, 0.0);

    glVertex3f(04.80, 9.0, 0.0);
    glVertex3f(04.80, 8.50, 0.0);
    glVertex3f(4.70, 8.50, 0.0);
    glVertex3f(4.70, 9.0, 0.0);


    glVertex3f(04.80, 8.0, 0.0);
    glVertex3f(04.80, 7.50, 0.0);
    glVertex3f(4.70, 7.50, 0.0);
    glVertex3f(4.70, 8.0, 0.0);

    glVertex3f(04.90, 11.0, 0.0);
    glVertex3f(04.90, 10.50, 0.0);
    glVertex3f(5.0, 10.50, 0.0);
    glVertex3f(5.0, 11.0, 0.0);

    glVertex3f(04.90, 10.0, 0.0);
    glVertex3f(04.90, 9.50, 0.0);
    glVertex3f(5.0,   9.50, 0.0);
    glVertex3f(5.0,   10.0, 0.0);

    glVertex3f(04.90, 9.0, 0.0);
    glVertex3f(04.90, 8.50, 0.0);
    glVertex3f(5.0, 8.50, 0.0);
    glVertex3f(5.0, 9.0, 0.0);

    glVertex3f(04.90, 8.0, 0.0);
    glVertex3f(04.90, 7.50, 0.0);
    glVertex3f(5.0, 7.50, 0.0);
    glVertex3f(5.0, 8.0, 0.0);

    glVertex3f(05.10, 11.0, 0.0);
    glVertex3f(05.10, 10.50, 0.0);
    glVertex3f(5.20, 10.50, 0.0);
    glVertex3f(5.20, 11.0, 0.0);

    glVertex3f(05.10, 10.0, 0.0);
    glVertex3f(05.10, 9.50, 0.0);
    glVertex3f(5.20, 9.50, 0.0);
    glVertex3f(5.20, 10.0, 0.0);

    glVertex3f(05.10, 9.0, 0.0);
    glVertex3f(05.10, 8.50, 0.0);
    glVertex3f(5.20, 8.50, 0.0);
    glVertex3f(5.20, 9.0, 0.0);

    glVertex3f(05.10, 8.0, 0.0);
    glVertex3f(05.10, 7.50, 0.0);
    glVertex3f(5.20, 7.50, 0.0);
    glVertex3f(5.20, 8.0, 0.0);

    glVertex3f(05.30, 11.0, 0.0);
    glVertex3f(05.30, 10.50, 0.0);
    glVertex3f(5.40, 10.50, 0.0);
    glVertex3f(5.40, 11.0, 0.0);

    glVertex3f(05.30, 10.0, 0.0);
    glVertex3f(05.30, 9.50, 0.0);
    glVertex3f(5.40, 9.50, 0.0);
    glVertex3f(5.40, 10.0, 0.0);

    glVertex3f(05.30, 9.0, 0.0);
    glVertex3f(05.30, 8.50, 0.0);
    glVertex3f(5.40, 8.50, 0.0);
    glVertex3f(5.40, 9.0, 0.0);

    glVertex3f(05.30, 8.0, 0.0);
    glVertex3f(05.30, 7.50, 0.0);
    glVertex3f(5.40, 7.50, 0.0);
    glVertex3f(5.40, 8.0, 0.0);

    glVertex3f(05.30, 7.0, 0.0);
    glVertex3f(05.30, 6.50, 0.0);
    glVertex3f(5.40, 6.50, 0.0);
    glVertex3f(5.40, 7.0, 0.0);


    glColor3ub(127,255,212);///main7

    glVertex3f(04.60, 11.20, 0.0);

    glColor3ub(128,128,128);
    glVertex3f(04.60, 1.20, 0.0);
    glVertex3f(5.60, 1.20, 0.0);

    glColor3ub(127,255,212);
    glVertex3f(5.60, 11.20, 0.0);

    glColor3ub(255,255,255);///building 8

    glVertex3f(05.60, 9.0, 0.0);
    glVertex3f(05.60, 8.60, 0.0);
    glVertex3f(5.70, 8.60, 0.0);
    glVertex3f(5.70, 9.0, 0.0);

    glVertex3f(05.60, 8.0, 0.0);
    glVertex3f(05.60, 7.60, 0.0);
    glVertex3f(5.70, 7.60, 0.0);
    glVertex3f(5.70, 8.0, 0.0);

    glVertex3f(05.60, 7.0, 0.0);
    glVertex3f(05.60, 6.60, 0.0);
    glVertex3f(5.70, 6.60, 0.0);
    glVertex3f(5.70, 7.0, 0.0);

    glVertex3f(05.80, 9.0, 0.0);
    glVertex3f(05.80, 8.60, 0.0);
    glVertex3f(5.90, 8.60, 0.0);
    glVertex3f(5.90, 9.0, 0.0);
    ///
    glVertex3f(05.80, 8.0, 0.0);
    glVertex3f(05.80, 7.60, 0.0);
    glVertex3f(5.90, 7.60, 0.0);
    glVertex3f(5.90, 8.0, 0.0);

    glVertex3f(05.80, 7.0, 0.0);
    glVertex3f(05.80, 6.60, 0.0);
    glVertex3f(5.90, 6.60, 0.0);
    glVertex3f(5.90, 7.0, 0.0);

    glVertex3f(05.80, 6.0, 0.0);
    glVertex3f(05.80, 5.60, 0.0);
    glVertex3f(5.90, 5.60, 0.0);
    glVertex3f(5.90, 6.0, 0.0);

    glVertex3f(05.80, 5.0, 0.0);
    glVertex3f(05.80, 4.60, 0.0);
    glVertex3f(5.90, 4.60, 0.0);
    glVertex3f(5.90, 5.0, 0.0);

    glVertex3f(05.80, 4.0, 0.0);
    glVertex3f(05.80,3.60, 0.0);
    glVertex3f(5.90, 3.60, 0.0);
    glVertex3f(5.90, 4.0, 0.0);

    glVertex3f(05.80, 3.0, 0.0);
    glVertex3f(05.80, 2.60, 0.0);
    glVertex3f(5.90, 2.60, 0.0);
    glVertex3f(5.90, 3.0, 0.0);


    glColor3ub(105,105,105);///main8

    glVertex3f(05.50, 9.20, 0.0);
    glVertex3f(05.50, 1.20, 0.0);
    glVertex3f(6.0, 1.20, 0.0);
    glVertex3f(6.0, 9.20, 0.0);


    glColor3ub(255,255,255);///building 1


    glVertex3f(-5.80, 14.20, 0.0);
    glVertex3f(-5.80, 13.50, 0.0);
    glVertex3f(-5.70, 13.50, 0.0);
    glVertex3f(-5.70, 14.20, 0.0);


    glVertex3f(-5.80, 12.20, 0.0);
    glVertex3f(-5.80, 11.50, 0.0);
    glVertex3f(-5.70, 11.50, 0.0);
    glVertex3f(-5.70, 12.20, 0.0);



    glVertex3f(-5.80, 10.20, 0.0);
    glVertex3f(-5.80, 9.50, 0.0);
    glVertex3f(-5.70, 9.50, 0.0);
    glVertex3f(-5.70, 10.20, 0.0);


    glVertex3f(-5.80, 8.20, 0.0);
    glVertex3f(-5.80, 7.50, 0.0);
    glVertex3f(-5.70, 7.50, 0.0);
    glVertex3f(-5.70, 8.20, 0.0);


    glVertex3f(-5.80, 6.20, 0.0);
    glVertex3f(-5.80, 5.50, 0.0);
    glVertex3f(-5.70, 5.50, 0.0);
    glVertex3f(-5.70, 6.20, 0.0);

    glVertex3f(-5.60, 14.20, 0.0);
    glVertex3f(-5.60, 13.50, 0.0);
    glVertex3f(-5.50, 13.50, 0.0);
    glVertex3f(-5.50, 14.20, 0.0);

    glVertex3f(-5.40, 14.20, 0.0);
    glVertex3f(-5.40, 13.50, 0.0);
    glVertex3f(-5.30, 13.50, 0.0);
    glVertex3f(-5.30, 14.20, 0.0);

    glColor3ub(216,191,216);///main1


    glVertex3f(-6.0, 14.50, 0.0);
    glColor3ub(169,169,169);
    glVertex3f(-6.0, 1.25, 0.0);
    glVertex3f(-5.20, 1.25, 0.0);
    glColor3ub(216,191,216);
    glVertex3f(-5.20, 14.50, 0.0);

    glColor3ub(105,105,105);///main2


    glVertex3f(-5.0, 8.50, 0.0);
    glVertex3f(-5.0, 1.25, 0.0);
    glVertex3f(-3.40, 1.25, 0.0);
    glVertex3f(-3.40, 8.50, 0.0);

    glColor3ub(255,255,255);///building 3

    glVertex3f(-2.30, 14.20, 0.0);
    glVertex3f(-2.30, 13.80, 0.0);
    glVertex3f(-3.10, 13.80, 0.0);
    glVertex3f(-3.10, 14.20, 0.0);

    glVertex3f(-2.50, 13.20, 0.0);
    glVertex3f(-2.50, 12.80, 0.0);
    glVertex3f(-2.90, 12.80, 0.0);
    glVertex3f(-2.90, 13.20, 0.0);

    glVertex3f(-2.80, 12.20, 0.0);
    glVertex3f(-2.80, 11.80, 0.0);
    glVertex3f(-2.60, 11.80, 0.0);
    glVertex3f(-2.60, 12.20, 0.0);

    glVertex3f(-2.75, 11.20, 0.0);
    glVertex3f(-2.75, 10.80, 0.0);
    glVertex3f(-2.65, 10.80, 0.0);
    glVertex3f(-2.65, 11.20, 0.0);


    glColor3ub(245,222,179);///main3


    glVertex3f(-2.10, 14.50, 0.0);
    glColor3ub(211,211,211);
    glVertex3f(-2.10, 1.25, 0.0);
    glVertex3f(-3.30, 1.25, 0.0);
    glColor3ub(245,222,179);
    glVertex3f(-3.30, 14.50, 0.0);

    glColor3ub(255,255,255);///building 4

///windows

    glVertex3f(-0.80, 10.50, 0.0);
    glVertex3f(-0.80, 10.25, 0.0);
    glVertex3f(-1.0, 10.25, 0.0);
    glVertex3f(-1.0, 10.50, 0.0);

    glVertex3f(-1.20, 10.50, 0.0);
    glVertex3f(-1.20, 10.25, 0.0);
    glVertex3f(-1.10, 10.25, 0.0);
    glVertex3f(-1.10, 10.50, 0.0);

    glVertex3f(-1.40, 10.50, 0.0);
    glVertex3f(-1.40, 10.25, 0.0);
    glVertex3f(-1.30, 10.25, 0.0);
    glVertex3f(-1.30, 10.50, 0.0);

    glVertex3f(-1.50, 10.50, 0.0);
    glVertex3f(-1.50, 10.25, 0.0);
    glVertex3f(-1.60, 10.25, 0.0);
    glVertex3f(-1.60, 10.50, 0.0);


    glVertex3f(-1.80, 10.50, 0.0);
    glVertex3f(-1.80, 10.25, 0.0);
    glVertex3f(-1.70, 10.25, 0.0);
    glVertex3f(-1.70, 10.50, 0.0);

    ///


    glVertex3f(-1.20, 9.50, 0.0);
    glVertex3f(-1.20, 9.25, 0.0);
    glVertex3f(-1.10, 9.25, 0.0);
    glVertex3f(-1.10, 9.50, 0.0);

    glVertex3f(-1.40, 9.50, 0.0);
    glVertex3f(-1.40, 9.25, 0.0);
    glVertex3f(-1.30, 9.25, 0.0);
    glVertex3f(-1.30, 9.50, 0.0);

    glVertex3f(-1.50, 9.50, 0.0);
    glVertex3f(-1.50, 9.25, 0.0);
    glVertex3f(-1.60, 9.25, 0.0);
    glVertex3f(-1.60, 9.50, 0.0);


    glVertex3f(-1.80, 9.50, 0.0);
    glVertex3f(-1.80, 9.25, 0.0);
    glVertex3f(-1.70, 9.25, 0.0);
    glVertex3f(-1.70, 9.50, 0.0);

////**********


    glVertex3f(-1.20, 7.50, 0.0);
    glVertex3f(-1.20, 7.25, 0.0);
    glVertex3f(-1.10, 7.25, 0.0);
    glVertex3f(-1.10, 7.50, 0.0);

    glVertex3f(-1.40, 7.50, 0.0);
    glVertex3f(-1.40, 7.25, 0.0);
    glVertex3f(-1.30, 7.25, 0.0);
    glVertex3f(-1.30, 7.50, 0.0);

    glVertex3f(-1.50, 7.50, 0.0);
    glVertex3f(-1.50, 7.25, 0.0);
    glVertex3f(-1.60, 7.25, 0.0);
    glVertex3f(-1.60, 7.50, 0.0);


    glVertex3f(-1.80, 7.50, 0.0);
    glVertex3f(-1.80, 7.25, 0.0);
    glVertex3f(-1.70, 7.25, 0.0);
    glVertex3f(-1.70, 7.50, 0.0);


//**********


    glVertex3f(-1.40, 6.50, 0.0);
    glVertex3f(-1.40, 6.25, 0.0);
    glVertex3f(-1.30, 6.25, 0.0);
    glVertex3f(-1.30, 6.50, 0.0);

    glVertex3f(-1.50, 6.50, 0.0);
    glVertex3f(-1.50, 6.25, 0.0);
    glVertex3f(-1.60, 6.25, 0.0);
    glVertex3f(-1.60, 6.50, 0.0);

    glVertex3f(-1.40, 5.50, 0.0);
    glVertex3f(-1.40, 5.25, 0.0);
    glVertex3f(-1.30, 5.25, 0.0);
    glVertex3f(-1.30, 5.50, 0.0);

    glVertex3f(-1.50, 5.50, 0.0);
    glVertex3f(-1.50, 5.25, 0.0);
    glVertex3f(-1.60, 5.25, 0.0);
    glVertex3f(-1.60, 5.50, 0.0);

///****
    glVertex3f(-1.20, 8.50, 0.0);
    glVertex3f(-1.20, 8.25, 0.0);
    glVertex3f(-1.10, 8.25, 0.0);
    glVertex3f(-1.10, 8.50, 0.0);

    glVertex3f(-1.40, 8.50, 0.0);
    glVertex3f(-1.40, 8.25, 0.0);
    glVertex3f(-1.30, 8.25, 0.0);
    glVertex3f(-1.30, 8.50, 0.0);

    glVertex3f(-1.50, 8.50, 0.0);
    glVertex3f(-1.50, 8.25, 0.0);
    glVertex3f(-1.60, 8.25, 0.0);
    glVertex3f(-1.60, 8.50, 0.0);


    glVertex3f(-1.80, 8.50, 0.0);
    glVertex3f(-1.80, 8.25, 0.0);
    glVertex3f(-1.70, 8.25, 0.0);
    glVertex3f(-1.70, 8.50, 0.0);

    ///////

    glVertex3f(-1.90, 10.50, 0.0);
    glVertex3f(-1.90, 10.25, 0.0);
    glVertex3f(-2.0, 10.25, 0.0);
    glVertex3f(-2.0, 10.50, 0.0);


    glVertex3f(-0.80, 9.50, 0.0);
    glVertex3f(-0.80, 9.25, 0.0);
    glVertex3f(-1.0, 9.25, 0.0);
    glVertex3f(-1.0, 9.50, 0.0);

    glColor3ub(105,105,105);///main4


    glVertex3f(-0.80, 10.90, 0.0);
    glVertex3f(-0.80, 1.25, 0.0);
    glVertex3f(-2.05, 1.25, 0.0);
    glVertex3f(-2.05, 10.90, 0.0);

    glEnd();


    glPopMatrix(); //Undo the move to the center of the trapezoid


    ///road
    glPushMatrix(); //Save the current state of transformations
    glTranslatef(0.0, -2.0, 0.0); //Move to the center of the pentagon
    //glRotatef(_angle, 1.0, 0.0, 0.0); //Rotate about the y-axis
    glScalef(0.50, 0.50, 0.0); //Scale by 0.7 in the x, y, and z directions

    glBegin(GL_QUADS);
    ///line

    glColor3ub(255,255,0);
    //Trapezoid
    glVertex3f(5.85, 0.20, 0.0);
    glVertex3f(5.9, 0.15, 0.0);
    glVertex3f(5.30, 0.15, 0.0);
    glVertex3f(5.25, 0.20, 0.0);

    glVertex3f(4.85, 0.20, 0.0);
    glVertex3f(4.9, 0.15, 0.0);
    glVertex3f(4.30, 0.15, 0.0);
    glVertex3f(4.25, 0.20, 0.0);


    glVertex3f(3.85, 0.20, 0.0);
    glVertex3f(3.9, 0.15, 0.0);
    glVertex3f(3.30, 0.15, 0.0);
    glVertex3f(3.25, 0.20, 0.0);

    glVertex3f(2.85, 0.20, 0.0);
    glVertex3f(2.9, 0.15, 0.0);
    glVertex3f(2.30, 0.15, 0.0);
    glVertex3f(2.25, 0.20, 0.0);


    glVertex3f(1.85, 0.20, 0.0);
    glVertex3f(1.9, 0.15, 0.0);
    glVertex3f(1.30, 0.15, 0.0);
    glVertex3f(1.25, 0.20, 0.0);

    glVertex3f(0.85, 0.20, 0.0);
    glVertex3f(0.9, 0.15, 0.0);
    glVertex3f(0.30, 0.15, 0.0);
    glVertex3f(0.25, 0.20, 0.0);

///

    glVertex3f(-0.9, 0.20, 0.0);
    glVertex3f(-0.85, 0.15, 0.0);
    glVertex3f(-0.25, 0.15, 0.0);
    glVertex3f(-0.30, 0.20, 0.0);

    glVertex3f(-1.9, 0.20, 0.0);
    glVertex3f(-1.85, 0.15, 0.0);
    glVertex3f(-1.25, 0.15, 0.0);
    glVertex3f(-1.30, 0.20, 0.0);


    glVertex3f(-2.9, 0.20, 0.0);
    glVertex3f(-2.85, 0.15, 0.0);
    glVertex3f(-2.25, 0.15, 0.0);
    glVertex3f(-2.30, 0.20, 0.0);

    glVertex3f(-3.9, 0.20, 0.0);
    glVertex3f(-3.85, 0.15, 0.0);
    glVertex3f(-3.25, 0.15, 0.0);
    glVertex3f(-3.30, 0.20, 0.0);


    glVertex3f(-4.9, 0.20, 0.0);
    glVertex3f(-4.85, 0.15, 0.0);
    glVertex3f(-4.25, 0.15, 0.0);
    glVertex3f(-4.30, 0.20, 0.0);


    glVertex3f(-5.9, 0.20, 0.0);
    glVertex3f(-5.85, 0.15, 0.0);
    glVertex3f(-5.25, 0.15, 0.0);
    glVertex3f(-5.30, 0.20, 0.0);

    ///road

    glColor3ub(105,105,105);
    glVertex3f(6.0, 01.25, 0.0);

    glColor3ub(40,40,40);
    glVertex3f(6.0, -1.0, 0.0);
    glVertex3f(-6.0, -1.0, 0.0);

    glColor3ub(105,105,105);
    glVertex3f(-6.0, 01.25, 0.0);




    glEnd();

    glPopMatrix(); //Undo the move to the center of the pentagon/*




    glPushMatrix(); //Save the current state of transformations
    //glTranslatef(-1.0, 1.0, 0.0); //Move to the center of the pentagon
    //glRotatef(_angle, 1.0, 0.0, 0.0); //Rotate about the y-axis
    glScalef(0.50, 0.50, 0.0); //Scale by 0.7 in the x, y, and z directions

    glBegin(GL_QUADS);

    ///background

    glColor3ub(0,0,0);
    glVertex3f(6.0, 6.0, 0.0);
    glVertex3f(6.0, -04.0, 0.0);
    glVertex3f(-6.0, -04.0, 0.0);
    glVertex3f(-6.0, 6, 0.0);


    glEnd();


    glPopMatrix(); //Undo the move to the center of the pentagon/*


    glPopMatrix(); //Undo the move to the center of the pentagon/*

    glutPostRedisplay();
    glFlush();
}

void drawover()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
    glLoadIdentity(); //Reset the drawing perspective
    glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
    glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units


    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    //glRotatef(_angle, 1.0, 0.0, 0.0);
    //glScalef(0.50, 0.50, 0.0);


    glBegin(GL_QUADS);
///  G start
    glColor3ub(255,0,0);
///  |
    glVertex3f(-01.80, 0.5, 0.0);
    glVertex3f(-01.80, 0.0, 0.0);
    glVertex3f(-01.7, 0.0, 0.0);
    glVertex3f(-01.7, 0.5, 0.0);
/// |-
    glColor3ub(255,255,0);
    glVertex3f(-01.75, 0.65, 0.0);
    glVertex3f(-01.75, 0.50, 0.0);
    glVertex3f(-01.15, 0.50, 0.0);
    glVertex3f(-01.15, 0.65, 0.0);
/// |-
    glColor3ub(255,255,0);
    glVertex3f(-01.75, 0.0, 0.0);
    glVertex3f(-01.75, -0.15, 0.0);
    glVertex3f(-01.25, -0.15, 0.0);
    glVertex3f(-01.25, 0.0, 0.0);

///  -|
    glColor3ub(255,0,0);
    glVertex3f(-01.15, 0.2, 0.0);
    glVertex3f(-01.15, -0.10, 0.0);
    glVertex3f(-01.25, -0.10, 0.0);
    glVertex3f(-01.25, 0.2, 0.0);
/// -
//glColor3ub(255,255,0);
    glVertex3f(-01.5, 0.35, 0.0);
    glVertex3f(-01.5, 0.2, 0.0);
    glVertex3f(-01.15, 0.2, 0.0);
    glVertex3f(-01.15, 0.35, 0.0);

    /// G end

    ///A start

    glColor3ub(255,0,0);

    glVertex3f(-0.80, 0.5, 0.0);
    glVertex3f(-0.80, -0.150, 0.0);
    glVertex3f(-0.65, -0.150, 0.0);
    glVertex3f(-0.65, 0.5, 0.0);

//glColor3ub(255,255,0);
    glVertex3f(-0.05, 0.5, 0.0);
    glVertex3f(-0.05, -0.150, 0.0);
    glVertex3f(-0.2, -0.150, 0.0);
    glVertex3f(-0.2, 0.5, 0.0);

//glColor3ub(255,255,0);
    glVertex3f(-0.15, 0.65, 0.0);
    glVertex3f(-0.15, 0.50, 0.0);
    glVertex3f(-0.7, 0.50, 0.0);
    glVertex3f(-0.7, 0.65, 0.0);

    glColor3ub(255,255,0);
    glVertex3f(-0.15, 0.25, 0.0);
    glVertex3f(-0.15, 0.10, 0.0);
    glVertex3f(-0.75, 0.10, 0.0);
    glVertex3f(-0.75, 0.25, 0.0);

    ///A end

    ///M start
    glColor3ub(255,255,0);
    glVertex3f(0.20, 0.65, 0.0);
    glVertex3f(0.20, -0.150, 0.0);
    glVertex3f(0.35, -0.150, 0.0);
    glVertex3f(0.35, 0.65, 0.0);
    glColor3ub(255,0,0);
    glVertex3f(0.35, 0.55, 0.0);
    glVertex3f(0.35, 0.40, 0.0);
    glVertex3f(0.5, 0.40, 0.0);
    glVertex3f(0.5, 0.55, 0.0);
    glColor3ub(255,255,0);
    glVertex3f(0.80, 0.65, 0.0);
    glVertex3f(0.80, -0.150, 0.0);
    glVertex3f(0.95, -0.150, 0.0);
    glVertex3f(0.95, 0.65, 0.0);
    glColor3ub(255,0,0);
    glVertex3f(0.65, 0.55, 0.0);
    glVertex3f(0.65, 0.40, 0.0);
    glVertex3f(0.8, 0.40, 0.0);
    glVertex3f(0.8, 0.55, 0.0);
    glColor3ub(255,0,0);
    glVertex3f(0.45, 0.4, 0.0);
    glVertex3f(0.45, 0.250, 0.0);
    glVertex3f(0.7, 0.250, 0.0);
    glVertex3f(0.7, 0.40, 0.0);

///M end

/// E start
    glColor3ub(255,0,0);
    glVertex3f(01.20, 0.65, 0.0);
    glVertex3f(01.20, -0.150, 0.0);
    glVertex3f(01.35, -0.150, 0.0);
    glVertex3f(01.35, 0.65, 0.0);
    glColor3ub(255,255,0);
    glVertex3f(1.35, 0.65, 0.0);
    glVertex3f(1.35, 0.50, 0.0);
    glVertex3f(1.7, 0.50, 0.0);
    glVertex3f(1.7, 0.65, 0.0);
    glColor3ub(255,0,0);

    glVertex3f(1.35, 0.35, 0.0);
    glVertex3f(1.35, 0.20, 0.0);
    glVertex3f(1.6, 0.20, 0.0);
    glVertex3f(1.6, 0.35, 0.0);
    glColor3ub(255,255,0);

    glVertex3f(1.35, 0.0, 0.0);
    glVertex3f(1.35, -0.15, 0.0);
    glVertex3f(1.7, -0.15, 0.0);
    glVertex3f(1.7, 0.0, 0.0);

    ///E end


    ///O start
    glColor3ub(255,0,0);
    glVertex3f(-01.7, -0.40, 0.0);
    glVertex3f(-01.7, -0.55, 0.0);
    glVertex3f(-01.2, -0.55, 0.0);
    glVertex3f(-01.2, -0.4, 0.0);
    glColor3ub(255,0,0);
    glVertex3f(-01.7, -01.0, 0.0);
    glVertex3f(-01.7, -01.15, 0.0);
    glVertex3f(-01.2, -01.15, 0.0);
    glVertex3f(-01.2, -01.0, 0.0);

    glColor3ub(255,255,0);
    glVertex3f(-01.80, -0.50, 0.0);
    glVertex3f(-01.80, -01.10, 0.0);
    glVertex3f(-01.7, -01.10, 0.0);
    glVertex3f(-01.7, -0.50, 0.0);

    glColor3ub(255,255,0);
    glVertex3f(-01.10, -0.50, 0.0);
    glVertex3f(-01.10, -01.10, 0.0);
    glVertex3f(-01.2, -01.10, 0.0);
    glVertex3f(-01.2, -0.50, 0.0);


    ///O end

    /// V start
    glColor3ub(255,0,0);
    glVertex3f(-0.80, -0.50, 0.0);
    glVertex3f(-0.80, -0.9, 0.0);
    glVertex3f(-0.7, -0.9, 0.0);
    glVertex3f(-0.7, -0.50, 0.0);
//glColor3ub(255,255,0);

    glVertex3f(-0.10, -0.50, 0.0);
    glVertex3f(-0.10, -0.9, 0.0);
    glVertex3f(-0.2, -0.9, 0.0);
    glVertex3f(-0.2, -0.50, 0.0);
    glColor3ub(255,255,0);



    glVertex3f(-0.7, -0.9, 0.0);
    glVertex3f(-0.7, -01.1, 0.0);
    glVertex3f(-0.55, -01.1, 0.0);
    glVertex3f(-0.55, -0.9, 0.0);
    glColor3ub(255,0,0);

    glVertex3f(-0.55, -01.0, 0.0);
    glVertex3f(-0.55, -01.15, 0.0);
    glVertex3f(-0.35, -01.15, 0.0);
    glVertex3f(-0.35, -01.0, 0.0);
    glColor3ub(255,255,0);
    glVertex3f(-0.35, -0.9, 0.0);
    glVertex3f(-0.35, -01.1, 0.0);
    glVertex3f(-0.2, -01.1, 0.0);
    glVertex3f(-0.2, -0.9, 0.0);

    /// V end

    /// E start
    glColor3ub(255,0,0);
    glVertex3f(0.20, -01.15, 0.0);
    glVertex3f(0.20, -0.5, 0.0);
    glVertex3f(0.3, -0.5, 0.0);
    glVertex3f(0.3, -01.15, 0.0);
    glColor3ub(255,255,0);
    glVertex3f(0.3, -0.65, 0.0);
    glVertex3f(0.3, -0.50, 0.0);
    glVertex3f(0.7, -0.50, 0.0);
    glVertex3f(0.7, -0.65, 0.0);
    glColor3ub(255,0,0);

    glVertex3f(0.3, -0.9, 0.0);
    glVertex3f(0.3, -0.75, 0.0);
    glVertex3f(0.6, -0.75, 0.0);
    glVertex3f(0.6, -0.9, 0.0);

    glColor3ub(255,255,0);
    glVertex3f(0.3, -01.0, 0.0);
    glVertex3f(0.3, -01.15, 0.0);
    glVertex3f(0.7, -01.15, 0.0);
    glVertex3f(0.7, -01.0, 0.0);

    ///E end

    /// R start
    glColor3ub(255,0,0);
    glVertex3f(01.20, -01.15, 0.0);
    glVertex3f(01.20, -0.5, 0.0);
    glVertex3f(01.3, -0.5, 0.0);
    glVertex3f(01.3, -01.15, 0.0);
    glColor3ub(255,255,0);
    glVertex3f(01.3, -0.65, 0.0);
    glVertex3f(01.3, -0.50, 0.0);
    glVertex3f(01.6, -0.50, 0.0);
    glVertex3f(01.6, -0.65, 0.0);

    glColor3ub(255,255,0);
    glVertex3f(01.3, -0.95, 0.0);
    glVertex3f(01.3, -0.85, 0.0);
    glVertex3f(01.6, -0.85, 0.0);
    glVertex3f(01.6, -0.95, 0.0);

    glColor3ub(255,0,0);
    glVertex3f(01.6, -0.90, 0.0);
    glVertex3f(01.6, -01.15, 0.0);
    glVertex3f(01.7, -01.15, 0.0);
    glVertex3f(01.7, -0.90, 0.0);

//glColor3ub(255,0,0);
    glVertex3f(01.6, -0.60, 0.0);
    glVertex3f(01.6, -0.85, 0.0);
    glVertex3f(01.7, -0.85, 0.0);
    glVertex3f(01.7, -0.60, 0.0);

    ///R end


    glEnd();


    glPopMatrix();
    glutPostRedisplay();


    glutSwapBuffers();
}

void printtext(int x, int y, string String)
{
//(x,y) is from the bottom left of the window
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, 1000, 0, 1000, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glPushAttrib(GL_DEPTH_TEST);
    glDisable(GL_DEPTH_TEST);
    glRasterPos2i(x,y);
    for (int i=0; i<String.size(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, String[i]);
    }
    glPopAttrib();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);

    char str[64],str1[64],str2[64],str3[64],str4[64],str5[64],str6[64],str7[64],str8[64];
    sprintf(str, "F8 : Full Screen");
    sprintf(str1, "F9 : Pause");
    sprintf(str2, "F10 : Restart Level");
    sprintf(str3, "HOME : Enter/Back to Main Menu");
    sprintf(str4, "Instructions");
    sprintf(str5, "Game Controls");
    sprintf(str6, "Firing Mode : Auto");
    sprintf(str7, "Arrow Up : Move Up ");
    sprintf(str8, "Arrow Down : Move Down ");
    printtext(380,820,str4);
    printtext(380,750,str);
    printtext(380,700,str1);
    printtext(380,650,str2);
    printtext(380,600,str3);
    printtext(380,520,str5);
    printtext(380,450,str6);
    printtext(380,400,str7);
    printtext(380,350,str8);

    //glutSwapBuffers();

}


void update(int value)
{

    if (a <= 0 )
    {

        a=0;
    }
    else
    {
        (a=a-5);

    }
    if (b <= 0 )
    {
        b=0;
    }
    else
    {
        b=b-5;

    }

    if (c <= 0 )
    {
        c=0;
    }
    else
    {
        c=c-5;

    }




    glutPostRedisplay(); //Tell GLUT that the display has changed

    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(200, update, 0);
}
void update2(int value)
{
    _angle += 2.0f;
    if (_angle > 360)
    {
        _angle -= 360;
    }
    _ang_tri += 2.0f;
    if (_ang_tri > 360)
    {
        _ang_tri -= 360;
    }

    glutPostRedisplay(); //Tell GLUT that the display has changed

    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(25, update2, 0);
}

void heroBullet(int value)
{


    if (x==-18.9&&yr==2)
    {
        x=-0.9;
        PlaySound(TEXT("Shot2.wav"),NULL,SND_ASYNC);



    }
    else if (x==-18.9&&yr==1)
    {
        x=-0.9;
        PlaySound(TEXT("Shot2.wav"),NULL,SND_ASYNC);


    }
    else if (x==-18.9&&yr==0)
    {
        x=-0.9;
        PlaySound(TEXT("Shot2.wav"),NULL,SND_ASYNC);


    }
    else if (x==-13.9 && yr==1 && xy!=1000 && xy1!=1000)
    {
        x=-0.9;
        PlaySound(TEXT("Shot2.wav"),NULL,SND_ASYNC);

        if (colCountL<3)
        {
            PlaySound(TEXT("shot3col.wav"),NULL,SND_ASYNC);
            colCountL++;
        }


    }
    else if (x==-13.9 && yr==0 && xy!=1000 && xy1!=1000)
    {
        x=-0.9;
        PlaySound(TEXT("Shot2.wav"),NULL,SND_ASYNC);

        if(colCountL<3)
        {
            PlaySound(TEXT("shot3col.wav"),NULL,SND_ASYNC);
            colCountL++;
        }



    }

    else if (xy==1000 && xy1==1000)
    {
        x=-0.9;
    }
    else if (xy==1000 && xy1==1000)
    {
        x=-0.9;


    }


    else if(x>-13.9 && yr==1)
    {
        x=x-1;


    }
    else if(x>-13.9 && yr==0)
    {
        x=x-1;


    }

    else if(x<-13.9 && yr==1)
    {
        x=x-1;


    }
    else if(x<-13.9 && yr==0)
    {
        x=x-1;


    }
    else if(x<-13.9 && yr==2)
    {
        x=x-1;


    }
    else
    {

        x=x-1;


    }



    glutPostRedisplay(); //Tell GLUT that the display has changed

    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(p2, heroBullet, 0);
}

void villainBullet(int value)
{

    if (x1==-15.95 && yr==2)
    {
        x1=-0.95;
        PlaySound(TEXT("Shot2.wav"),NULL,SND_ASYNC);


    }
    else if (x1==-15.95 && yr==1)
    {
        x1=-0.95;
        PlaySound(TEXT("Shot2.wav"),NULL,SND_ASYNC);


    }
    else if (x1==-15.95 && yr==0)
    {
        x1=-0.95;
        PlaySound(TEXT("Shot2.wav"),NULL,SND_ASYNC);


    }
    else if (x1==-15.95 && yr==2 && xy!=1000 && xy1!=1000)
    {
        x1=-0.95;
        PlaySound(TEXT("Shot2.wav"),NULL,SND_ASYNC);


    }
    else if(x1==-11.95 && yr==1 && xy!=1000 && xy1!=1000)
    {
        x1=-0.95;
        PlaySound(TEXT("Shot2.wav"),NULL,SND_ASYNC);


        if(colCountR<3)
        {
            PlaySound(TEXT("shot3col.wav"),NULL,SND_ASYNC);

            colCountR++;
        }



    }
    else if(x1==-11.95 && yr==0&&xy!=1000 && xy1!=1000)
    {
        x1=-0.95;
        PlaySound(TEXT("Shot2.wav"),NULL,SND_ASYNC);


        if(colCountR<3)
        {
            PlaySound(TEXT("shot3col.wav"),NULL,SND_ASYNC);

            colCountR++;
        }

    }

    else if (xy==1000 && xy1==1000)
    {
        x1=-0.95;


    }
    else if(xy==1000 && xy1==1000)
    {
        x1=-0.95;

    }
    else if(xy==1000 && xy1==1000)
    {
        x1=-0.95;

    }


    else
    {

        x1=x1-1;


    }



    glutPostRedisplay(); //Tell GLUT that the display has changed

    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(p1, villainBullet, 0);


}


void villiangone(int value)
{


    if(colCountL>=3 && ch==22.5 && ch1==-22.5)
    {
        a=135,b=205,c=250;
        x=-0.9,x1=-0.95,y=-7.3,xy=-0.32,r2=1,xy1=0.6,ch=0,ch1=0,p=1000,p1=70,p2=150;
        full=false,pause=false;
        xr=0,yr=0;
        colCountL=0,colCountR=0;

        if(level==0)
        {
            menu1=1;
            glutDisplayFunc(drawScene1);
            level=1;
        }

        else if (level==1)
        {

            glutDisplayFunc(drawscene2);
            level=2;
            menu1=1;
        }
        else if(level==2)
        {
            xy=1000;
            xy1=1000;
            colCountL=0;
            colCountR=0;

            glutDisplayFunc(drawmenu);
            PlaySound(NULL, 0, 0);
            PlaySound(TEXT("Shot.wav"), NULL, SND_FILENAME | SND_ASYNC);
            level=0;
            menu1=0;
        }

    }
    else if (colCountL>=3 && colCountR<3)
    {
        if(xy==1000 && xy1==1000)
        {
            cout<<"pause";
        }

        else
        {
            ch=ch+0.5;
            ch1=ch1-0.5;
            cout<<ch<<","<<ch1<<endl;
        }


    }

    else if (colCountR==3)
    {
        glutDisplayFunc(drawover);
        PlaySound(NULL, 0, 0);
        PlaySound(TEXT("over.wav"), NULL, SND_FILENAME | SND_SYNC);
        glutPostRedisplay();
    }

    glutPostRedisplay(); //Tell GLUT that the display has changed
    glutSwapBuffers();

    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(100, villiangone, 0);

}

void keyboardown(int key, int x, int y)
{
    switch (key)
    {

    case GLUT_KEY_UP:
        if (pause==false)
        {
            if(yr==0||yr==1)
            {
                yr = yr+1;
            }
            glutPostRedisplay();
        }
        else {}
        break;



    case GLUT_KEY_DOWN:
        if (pause==false)
        {
            if(yr==1||yr==2)
            {
                yr--;
            }
            glutPostRedisplay();
        }
        else {}
        break;


//fullscreen F8
    case GLUT_KEY_F8:
        if(full==false)
        {
            glutFullScreen();
            full=true;
        }

        else
        {
            glutReshapeWindow(1000,1000);
            full=false;

        }
        break;
//Pause F9

    case GLUT_KEY_F9:
        if(pause==false)
        {
            pause=true;
            p=0;
            xy=1000;
            xy1=1000;
            glutPostRedisplay();

        }
        else if(pause==true)
        {
            pause=false;

            p=1000;
            xy=-0.32;
            xy1=0.6;
            glutPostRedisplay();

        }

    //arrow
    case GLUT_KEY_RIGHT:
        if(menu1==0 && level<3)
        {
            cout<<"Ins";
            t1=20;
            t2=144;
            t3=255;
            t4=240,t5=240,t6=240;
            menu=true;
        }
        else
        {
            cout<<"lock"<<"menu1 : "<<menu1<<endl;
        }


        glutPostRedisplay();

        break;

    case GLUT_KEY_LEFT:
        if(menu1==0 && level<3)
        {
            cout<<"Game";
            t1=240;
            t2=240;
            t3=240;
            t4=20;
            t5=144;
            t6=255;

            menu=false;
        }
        else
        {
            cout<<"lock"<<"menu1 : "<<menu1<<endl;
        }
        glutPostRedisplay();

        break;

        //Enter

    case GLUT_KEY_HOME:
        PlaySound(TEXT("Shot.wav"), NULL, SND_FILENAME | SND_ASYNC);
        if(menu==false)
        {
            if (xy==1000 && xy1==1000)
            {
                xy=-0.32;
                xy1=0.6,level=0;
                menu1=1;
                PlaySound(NULL, 0, 0);
                glutDisplayFunc(drawScene);
                cout<<"1";
                glutPostRedisplay();
            }

            else if (xy!=1000 && xy1!=1000)
            {
                xy=1000;
                xy1=1000;
                colCountL=0;
                colCountR=0,menu1=0;
                glutDisplayFunc(drawmenu);
                cout<<"2";
                glutPostRedisplay();
            }
        }
        else if (menu==true && ins == false )
        {
            menu1=0;
            level=3;
            glutDisplayFunc(display);
            glutPostRedisplay();
            ins=true;
            cout<<"3";

        }
        else if (menu==true && ins == true )
        {
            menu1=0;
            level=2;
            glutDisplayFunc(drawmenu);
            glutPostRedisplay();
            cout<<"4";
            ins=false;


        }
        glutPostRedisplay();

        break;

//Restart Level f10

    case GLUT_KEY_F10:
        a=135,b=205,c=250;
        x=-0.9,x1=-0.95,y=-7.3,xy=-0.32,r2=1,xy1=0.6,ch=0,ch1=0,p=1000,p1=70,p2=150;
        full=false,pause=false;
        xr=0,yr=0;
        colCountL=0,colCountR=0;
        if (level==0)
        {
            glutDisplayFunc(drawScene);
            glutPostRedisplay();

        }
        else if (level==1)
        {
            glutDisplayFunc(drawScene1);
            glutPostRedisplay();

        }
        else if (level==2)
        {

            glutDisplayFunc(drawscene2);
            glutPostRedisplay();
        }


        break;


    default:
        break;


    }

}



int main(int argc, char** argv)
{

    //Initialize GLUT

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(300,100);


    //Create the window
    glutCreateWindow("Transformations");
    initRendering();

    //Set handler function
    xy=1000;
    xy1=1000;

    PlaySound(TEXT("Shot.wav"), NULL, SND_FILENAME | SND_ASYNC);

    glutDisplayFunc(drawmenu);



    glutReshapeFunc(handleResize);





    glutTimerFunc(25, update2, 0);
    glutTimerFunc(1000, heroBullet, 0);
    glutTimerFunc(1000, villainBullet, 0);
    glutTimerFunc(3000, update, 0); //Add a timer
    glutTimerFunc(25, villiangone, 0);
    glutSpecialFunc(keyboardown);
    glutMainLoop();

    return 0;
}


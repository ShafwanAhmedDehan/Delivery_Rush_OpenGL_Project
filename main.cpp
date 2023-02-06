#include <windows.h>
#include <GL/glut.h>
#include<cstdio>
#include <GL/gl.h>
#include <iostream>
#include <math.h>
#include <mmsystem.h>
#include <time.h>
#include <MMSystem.h>
#include <stdlib.h>
#include <fstream>
#define PI 3.14159265358979323846 ///Draw Cricle
using namespace std;

///[Sets of global Variable]
double num=0;///For score board
double HighScore=0;
GLfloat position = 0.0f;
GLfloat position1 = 0.0f;
GLfloat position2 = 0.0f;
GLfloat position4 = 0.0f;
float speed = 0.02f;
float speed01=0.001f;
float speed02=0.003f;
float speed03=0.02f;
float speed04=0.02;
int control=1;
GLfloat position3=0.0f;
float xr = 0.0f, yr = 0.0f;///Key press variable adjust
///////////////////////////////////////////////////////////////////
/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void scoreBoard()///Generate score board
{

    renderBitmapString(-0.99f, 0.95f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Score : ");
    num = num+0.04;
    char buffer[10];
    sprintf(buffer, "%.0lf", num);
    if(num>50)
    {
        speed04=speed04+0.00000001;
    }
    glColor3ub(72,82,107);
    renderBitmapString(-0.85f, 0.95f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, buffer);
}

void update(int value)///For main display function animation
{
    if(position<-2.0)
    {
        position=0.0f;
    }
position-=speed02;
glutPostRedisplay();
glutTimerFunc(60, update, 0);
}

void update04(int value)///Jump control
{
    switch(control)
    {
    case 1:
        if(position4<0.3)
        {
            position4+=speed03;
            glutPostRedisplay();
            glutTimerFunc(60,update04,0);
        }
        else
        {
            control=-1;
            glutTimerFunc(60,update04,0);
        }
        break;
    case -1:
        if(position4>0.0)
        {
            position4-=speed03;
            glutPostRedisplay();
            glutTimerFunc(60,update04,0);
        }
        break;
    }
}
void keyboard(int key, int x, int y)///Keypress Control
{

    switch (key) {

        case GLUT_KEY_UP:
            if(yr<0.02)
            {
                control=1;
                glutTimerFunc(60,update04,0);
                break;
            }

        default:
                break;
        }
}
void circle(GLfloat x1,GLfloat y1, GLfloat R1)/// Draw Cicle
{
GLfloat x=x1; GLfloat y=y1; GLfloat radius =R1;
int triangleAmount = 100; //# of lines used to draw circle

//GLfloat radius = 0.8f; //radius
GLfloat twicePi = 2.0f * PI;
//glColor3f(0.35f,0.0f,0.0f);
glBegin(GL_TRIANGLE_FAN);
glVertex2f(x, y); // center of circle
for(int i = 0; i <= triangleAmount;i++)
    {
        glVertex2f( x + (radius * cos(i * twicePi / triangleAmount)),
        y + (radius * sin(i * twicePi / triangleAmount)) );
    }
glEnd();
}

void update01(int value)///Sun animation
{
    if(position1<-0.8)
    {
        position1=1.0f;
    }
position1-=speed01;
glutPostRedisplay();
glutTimerFunc(50, update01, 0);
}

void update02(int value)///Manu page animation
{
    if(position2<-2.0)
    {
        position2=0.0f;
    }
    position2-=speed;
glutPostRedisplay();
glutTimerFunc(60, update02, 0);
}

void afterGameOverPage()///Game over page
{
glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
///BackGround
glBegin(GL_POLYGON);
glColor3ub(179,186,202);
glVertex2f(1.0f,-1.0f);
glColor3ub(179,186,202);
glVertex2f(1.0f,1.0f);
glColor3ub(218,222,231);
glVertex2f(-1.0f,1.0f);
glColor3ub(230,230,250);
glVertex2f(-1.0f,-1.0f);
glEnd();
///////////////////////////////////
///Info Details
glColor3ub(39,45,59);
renderBitmapString(-0.17f, 0.3f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Your Score : ");
renderBitmapString(-0.3f, 0.2f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24,"-*-*-*-*-*-*-*-*-*-*-*-");
renderBitmapString(-0.15f, 0.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Game Over");
char buffer[10];
sprintf(buffer, "%.0lf", num);
glColor3ub(72,82,107);
renderBitmapString(0.08f, 0.3f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, buffer);
glutSwapBuffers();//Render
}

void update03(int value)///Obstacle animation
{
    if(position3<-27.5)
    {
        position3=1.1f;
    }
position3-=speed04;
scoreBoard();
glutPostRedisplay();
if((0.0<=position4) && ((0.01>position4) || (0.01>position4) || (0.08>position4) || (0.1>position4)) && ((-0.96>position3 && -1.0<position3) || (-2.16>position3 && -2.3<position3) || (-3.58>position3 && -3.66<position3)
                                          || (-4.3>position3 && -4.38<position3) || (-5.1>position3 && -5.28<position3) || (-5.98>position3 && -6.06<position3)
                                          || (-7.18>position3 && -7.36<position3) || (-7.98>position3 && -8.06<position3) || (-8.69>position3 && -8.86<position3)
                                          || (-9.45>position3 && -9.53<position3) || (-10.16>position3 && -10.3<position3) || (-10.86>position3 && -10.96<position3)
                                          || (-11.46>position3 && -11.66<position3) || (-12.34>position3 && -12.44<position3) || (-13.24>position3 && -13.37<position3)
                                          || (-14.1>position3 && -14.18<position3) || (-14.9>position3 && -15.08<position3) || (-15.65>position3 && -15.77<position3)
                                          || (-16.4>position3 && -16.48<position3) || (-17.18>position3 && -17.28<position3) || (-17.87>position3 && -17.95<position3)
                                          || (-18.7>position3 && -18.88<position3) || (-19.64>position3 && -19.74<position3) || (-20.48>position3 && -20.68<position3)
                                          || (-21.35>position3 && -21.49<position3) || (-22.12>position3 && -22.2<position3) || (-22.9>position3 && -23.1<position3)
                                          || (-23.64>position3 && -23.77<position3) || (-24.38>position3 && -24.56<position3) || (-25.45>position3 && -25.57<position3)
                                          || (-26.37>position3 && -26.45<position3)))
{
    glColor3f(1.0,0.0,0.0);
    glutDisplayFunc(afterGameOverPage);
    //glutPostRedisplay();
}
else
{
    glutTimerFunc(60, update03, 0);
}
}

void fakeBuildingback()///To maintain animation correctly fakebuilding
{
    ///start///
glBegin(GL_POLYGON);
glColor3ub(72,82,107);
glVertex2f(1.12f,0.04f);
glVertex2f(1.26f,0.04f);
glVertex2f(1.26f,-0.32f);
glVertex2f(1.0f,-0.32f);
glVertex2f(1.00f,0.24f);
glVertex2f(1.12f,0.24f);
glEnd();
////////////////////////
glBegin(GL_POLYGON);
glColor3ub(72,82,107);
glVertex2f(1.4f,0.1f);
glVertex2f(1.46f,0.1f);
glVertex2f(1.46f,-0.32f);
glVertex2f(1.26f,-0.32f);
glVertex2f(1.26f,0.18f);
glVertex2f(1.4f,0.18f);
glEnd();
////////////////////////
glBegin(GL_POLYGON);
glColor3ub(72,82,107);
glVertex2f(1.66f,0.1f);
glVertex2f(1.76f,0.1f);
glVertex2f(1.76f,-0.32f);
glVertex2f(1.46f,-0.32f);
glVertex2f(1.46f,0.3f);
glVertex2f(1.66f,0.3f);
glEnd();
////////////////////////
glBegin(GL_POLYGON);
glColor3ub(72,82,107);
glVertex2f(1.88f,0.14f);
glVertex2f(2.14f,0.14f);
glVertex2f(2.14f,-0.32f);
glVertex2f(1.76f,-0.32f);
glVertex2f(1.76f,0.24f);
glVertex2f(1.88f,0.24f);
glEnd();
////////////////////////
glBegin(GL_POLYGON);
glColor3ub(72,82,107);
glVertex2f(2.34f,0.14f);
glVertex2f(2.38f,0.14f);
glVertex2f(2.38f,-0.32f);
glVertex2f(2.14f,-0.32f);
glVertex2f(2.14f,0.3f);
glVertex2f(2.34f,0.3f);
glEnd();
////////////////////////
glBegin(GL_POLYGON);
glColor3ub(72,82,107);
glVertex2f(2.54f,0.2f);
glVertex2f(2.56f,0.2f);
glVertex2f(2.56f,-0.32f);
glVertex2f(2.38f,-0.32f);
glVertex2f(2.38f,0.24f);
glVertex2f(2.54f,0.24f);
glEnd();
////////////////////////
glBegin(GL_POLYGON);
glColor3ub(72,82,107);
glVertex2f(2.74f,0.04f);
glVertex2f(2.84f,0.04f);
glVertex2f(2.84f,-0.32f);
glVertex2f(2.56f,-0.32f);
glVertex2f(2.56f,0.28f);
glVertex2f(2.74f,0.28f);
glEnd();
////////////////////////
glBegin(GL_POLYGON);
glColor3ub(72,82,107);
glVertex2f(2.94f,0.14f);
glVertex2f(3.0f,0.14f);
glVertex2f(3.0f,-0.32f);
glVertex2f(2.84f,-0.32f);
glVertex2f(2.84f,0.24f);
glVertex2f(2.94f,0.24f);
glEnd();
/////////////////////////
glBegin(GL_POLYGON);
glColor3ub(72,82,107);
glVertex2f(3.0f,0.14f);
glVertex2f(3.0f,0.14f);
glVertex2f(3.0f,-0.32f);
glVertex2f(2.84f,-0.32f);
glVertex2f(2.84f,0.17f);
glVertex2f(3.0f,0.17f);
glEnd();
        ///end///
}


void fakebuildingfornt()///To maintain animation correctly fakebuilding
{
    ///Start///
glBegin(GL_POLYGON);
glColor3ub(39,45,59);
glVertex2f(1.2f,0.0f);
glVertex2f(1.3f,0.0f);
glVertex2f(1.3f,-0.32f);
glVertex2f(1.0f,-0.32f);
glVertex2f(1.0f,0.1f);
glVertex2f(1.2f,0.1f);
glEnd();
//////////////////////////
glBegin(GL_POLYGON);
glColor3ub(39,45,59);
glVertex2f(1.5f,0.04f);
glVertex2f(1.6f,0.04f);
glVertex2f(1.6f,-0.32f);
glVertex2f(1.3f,-0.32f);
glVertex2f(1.3f,0.1f);
glVertex2f(1.5f,0.1f);
glEnd();
////////////////////////
glBegin(GL_POLYGON);
glColor3ub(39,45,59);
glVertex2f(1.7f,0.0f);
glVertex2f(1.8f,0.0f);
glVertex2f(1.8f,-0.32f);
glVertex2f(1.6f,-0.32f);
glVertex2f(1.6f,0.14f);
glVertex2f(1.7f,0.14f);
glEnd();
/////////////////////////
glBegin(GL_POLYGON);
glColor3ub(39,45,59);
glVertex2f(1.94f,-0.06f);
glVertex2f(2.0f,-0.06f);
glVertex2f(2.0f,-0.32f);
glVertex2f(1.8f,-0.32f);
glVertex2f(1.8f,0.08f);
glVertex2f(1.94f,0.08f);
glEnd();
///////////////////////////
glBegin(GL_POLYGON);
glColor3ub(39,45,59);
glVertex2f(2.2f,-0.06f);
glVertex2f(2.26f,-0.06f);
glVertex2f(2.26f,-0.32f);
glVertex2f(2.0f,-0.32f);
glVertex2f(2.0f,0.2f);
glVertex2f(2.2f,0.2f);
glEnd();
////////////////////////////
glBegin(GL_POLYGON);
glColor3ub(39,45,59);
glVertex2f(2.4f,0.04f);
glVertex2f(2.5f,0.04f);
glVertex2f(2.5f,-0.32f);
glVertex2f(2.26f,-0.32f);
glVertex2f(2.26f,0.14f);
glVertex2f(2.4f,0.14f);
glEnd();
////////////////////////////
glBegin(GL_POLYGON);
glColor3ub(39,45,59);
glVertex2f(2.8f,-0.06f);
glVertex2f(2.9f,-0.06f);
glVertex2f(2.9f,-0.32f);
glVertex2f(2.5f,-0.32f);
glVertex2f(2.5f,0.2f);
glVertex2f(2.8f,0.2f);
glEnd();
//////////////////////////////
glBegin(GL_POLYGON);
glColor3ub(39,45,59);
glVertex2f(2.9f,0.14f);
glVertex2f(3.0f,0.14f);
glVertex2f(3.0f,-0.32f);
glVertex2f(2.9f,-0.32f);
glEnd();
        ///End///
}


void display()///Main gameplay page
{
glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
glLoadIdentity();
glMatrixMode(GL_MODELVIEW);
//glLineWidth(5);
//glBegin(GL_LINES);

///Box for Character
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(-0.94f+xr,-0.20f+yr);
glVertex2f(-0.775f+xr,-0.20f+yr);
glVertex2f(-0.775f+xr,-0.36f+yr);
glVertex2f(-0.94f+xr,-0.36f+yr);
glEnd();
glPopMatrix();
glLoadIdentity();
glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(position3,0.0f,0.0f);
///Obstacles Boxes
///Box for Hole-1
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(0.18f,-0.34f);
glVertex2f(0.36f,-0.34f);
glVertex2f(0.36f,-0.38f);
glVertex2f(0.18f,-0.38f);
glEnd();
////////////////////////////////
///Box for Water-1
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(1.38f,-0.34f);
glVertex2f(1.52f,-0.34f);
glVertex2f(1.52f,-0.38f);
glVertex2f(1.38f,-0.38f);
glEnd();
////////////////////////////////
///Box for Dustbin-1
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(2.80f,-0.28f);
glVertex2f(2.88f,-0.28f);
glVertex2f(2.88f,-0.38f);
glVertex2f(2.80f,-0.38f);
glEnd();
////////////////////////////////
///Box for Lomba kichu ekta-1
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(3.52f,-0.28f);
glVertex2f(3.60f,-0.28f);
glVertex2f(3.60f,-0.38f);
glVertex2f(3.52f,-0.38f);
glEnd();
////////////////////////////////
///Box for Car-1
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(4.32f,-0.26f);
glVertex2f(4.50f,-0.26f);
glVertex2f(4.50f,-0.36f);
glVertex2f(4.32f,-0.36f);
glEnd();
////////////////////////////////
///Box for Upordik kichu ekta-1
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(5.20f,-0.28f);
glVertex2f(5.28f,-0.28f);
glVertex2f(5.28f,-0.38f);
glVertex2f(5.20f,-0.38f);
glEnd();
////////////////////////////////
///Box for Car-2
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(6.40f,-0.26f);
glVertex2f(6.58f,-0.26f);
glVertex2f(6.58f,-0.36f);
glVertex2f(6.40f,-0.36f);
glEnd();
////////////////////////////////
///Box for Dustbin-2
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(7.20f,-0.28f);
glVertex2f(7.28f,-0.28f);
glVertex2f(7.28f,-0.38f);
glVertex2f(7.20f,-0.38f);
glEnd();
////////////////////////////////
///Box for Car-3
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(7.90f,-0.26f);
glVertex2f(8.08f,-0.26f);
glVertex2f(8.08f,-0.36f);
glVertex2f(7.90f,-0.36f);
glEnd();
////////////////////////////////
///Box for Lomba kichu ekta-2
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(8.67f,-0.28f);
glVertex2f(8.75f,-0.28f);
glVertex2f(8.75f,-0.38f);
glVertex2f(8.67f,-0.38f);
glEnd();
////////////////////////////////
///Box for Water-2
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(9.38f,-0.34f);
glVertex2f(9.52f,-0.34f);
glVertex2f(9.52f,-0.38f);
glVertex2f(9.38f,-0.38f);
glEnd();
////////////////////////////////
///Box for Box-1
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(10.08f,-0.28f);
glVertex2f(10.18f,-0.28f);
glVertex2f(10.18f,-0.38f);
glVertex2f(10.08f,-0.38f);
glEnd();
////////////////////////////////
///Box for Hole-2
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(10.68f,-0.34f);
glVertex2f(10.86f,-0.34f);
glVertex2f(10.86f,-0.38f);
glVertex2f(10.68f,-0.38f);
glEnd();
////////////////////////////////
///Box for Katakata kichu-1
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(11.54f,-0.28f);
glVertex2f(11.64f,-0.28f);
glVertex2f(11.64f,-0.38f);
glVertex2f(11.54f,-0.38f);
glEnd();
////////////////////////////////
///Box for Ball-1
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(12.47f,-0.28f);
glVertex2f(12.57f,-0.28f);
glVertex2f(12.57f,-0.38f);
glVertex2f(12.47f,-0.38f);
glEnd();
////////////////////////////////
///Box for Upordik kichu ekta-2
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(13.30f,-0.28f);
glVertex2f(13.38f,-0.28f);
glVertex2f(13.38f,-0.38f);
glVertex2f(13.30f,-0.38f);
glEnd();
////////////////////////////////
///Box for Car-4
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(14.10f,-0.26f);
glVertex2f(14.28f,-0.26f);
glVertex2f(14.28f,-0.36f);
glVertex2f(14.10f,-0.36f);
glEnd();
////////////////////////////////
///Box for Triangle-1
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(14.87f,-0.28f);
glVertex2f(14.97f,-0.28f);
glVertex2f(14.97f,-0.38f);
glVertex2f(14.87f,-0.38f);
glEnd();
////////////////////////////////
///Box for Dustbin-3
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(15.60f,-0.28f);
glVertex2f(15.68f,-0.28f);
glVertex2f(15.68f,-0.38f);
glVertex2f(15.60f,-0.38f);
glEnd();
////////////////////////////////
///Box for Box-2
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(16.38f,-0.28f);
glVertex2f(16.48f,-0.28f);
glVertex2f(16.48f,-0.38f);
glVertex2f(16.38f,-0.38f);
glEnd();
////////////////////////////////
///Box for Lomba kichu ekta-3
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(17.07f,-0.28f);
glVertex2f(17.15f,-0.28f);
glVertex2f(17.15f,-0.38f);
glVertex2f(17.07f,-0.38f);
glEnd();
////////////////////////////////
///Box for Car-5
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(17.90f,-0.26f);
glVertex2f(18.08f,-0.26f);
glVertex2f(18.08f,-0.36f);
glVertex2f(17.90f,-0.36f);
glEnd();
////////////////////////////////
///Box for Katakata kichu-2
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(18.84f,-0.28f);
glVertex2f(18.94f,-0.28f);
glVertex2f(18.94f,-0.38f);
glVertex2f(18.84f,-0.38f);
glEnd();
////////////////////////////////
///Box for Hole-3
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(19.68f,-0.34f);
glVertex2f(19.86f,-0.34f);
glVertex2f(19.86f,-0.38f);
glVertex2f(19.68f,-0.38f);
glEnd();
////////////////////////////////
///Box for Triangle-2
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(20.57f,-0.28f);
glVertex2f(20.67f,-0.28f);
glVertex2f(20.67f,-0.38f);
glVertex2f(20.57f,-0.38f);
glEnd();
////////////////////////////////
///Box for Upordik kichu ekta-3
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(21.30f,-0.28f);
glVertex2f(21.38f,-0.28f);
glVertex2f(21.38f,-0.38f);
glVertex2f(21.30f,-0.38f);
glEnd();
////////////////////////////////
///Box for Car-6
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(22.10f,-0.26f);
glVertex2f(22.28f,-0.26f);
glVertex2f(22.28f,-0.36f);
glVertex2f(22.10f,-0.36f);
glEnd();
////////////////////////////////
///Box for Ball-2
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(22.85f,-0.28f);
glVertex2f(22.95f,-0.28f);
glVertex2f(22.95f,-0.38f);
glVertex2f(22.85f,-0.38f);
glEnd();
////////////////////////////////
///Box for Water-3
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(23.56f,-0.34f);
glVertex2f(23.74f,-0.34f);
glVertex2f(23.74f,-0.38f);
glVertex2f(23.56f,-0.38f);
glEnd();
////////////////////////////////
///Box for Lomba kichu ekta-4
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(24.67f,-0.28f);
glVertex2f(24.75f,-0.28f);
glVertex2f(24.75f,-0.38f);
glVertex2f(24.67f,-0.38f);
glEnd();
////////////////////////////////
///Box for Box-3
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(25.48f,-0.28f);
glVertex2f(25.58f,-0.28f);
glVertex2f(25.58f,-0.38f);
glVertex2f(25.48f,-0.38f);
glEnd();
////////////////////////////////
///Box for Dustbin-4
glBegin(GL_LINE_LOOP);
glColor3f(255,228,196);
glVertex2f(26.30f,-0.28f);
glVertex2f(26.38f,-0.28f);
glVertex2f(26.38f,-0.38f);
glVertex2f(26.30f,-0.38f);
glEnd();
////////////////////////////////
glPopMatrix();
///BackGround
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(1.0f,-1.0f);
glVertex2f(1.0f,1.0f);
glVertex2f(-1.0f,1.0f);
glVertex2f(-1.0f,-1.0f);
glEnd();
////////////////////////////
///Sky
glBegin(GL_POLYGON);
glColor3ub(223,226,233);
glVertex2f(-1.0f,1.0f);
//glColor3f(0.419608f,0.137255f,0.556863f);
glVertex2f(-1.0f,-0.32f);
//glColor3f(0.419608f,0.137255f,0.556863f);
glVertex2f(1.5f,-0.32f);
//glColor3f(0.25f,0.55f,1.0f);
glVertex2f(1.5f,1.0f);
glEnd();
///////////////////////////////////////////
///Sun
glLoadIdentity();
glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(position1,position1,0.0f);
GLfloat x15=0.75f; GLfloat y15=0.7f; GLfloat radius15 =0.13f;
GLfloat twicePi15 = 2.0f * PI;
int triangleAmount=100;
glColor3ub(255,248,210);
glBegin(GL_TRIANGLE_FAN);
glVertex2f(x15, y15); // center of circle
for(int i = 0; i <= triangleAmount;i++)
    {
        glVertex2f( x15 + (radius15 * cos(i * twicePi15 / triangleAmount)),
        y15 + (radius15 * sin(i * twicePi15 / triangleAmount)) );
    }
glEnd();
glPopMatrix();
///////////////////////////////////////
///Cloud
/////////////////////////////////////
        ///start///
glLoadIdentity();
glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(position,0.0f,0.0f);
////////////////////////////////////////////
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.6f,0.54f);
glVertex2f(-0.64f,0.54f);
glVertex2f(-0.62f,0.56f);
glVertex2f(-0.6f,0.56f);
glVertex2f(-0.56f,0.52f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.66f,0.56f);
glVertex2f(-0.68f,0.54f);
glVertex2f(-0.72f,0.56f);
glVertex2f(-0.74f,0.58f);
glVertex2f(-0.70f,0.6f);
glVertex2f(-0.66f,0.58f);
glVertex2f(-0.62f,0.56f);
glVertex2f(-0.64f,0.54f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.76f,0.56f);
glVertex2f(-0.8f,0.54f);
glVertex2f(-0.8f,0.56f);
glVertex2f(-0.74f,0.58f);
glVertex2f(-0.72f,0.56f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.84f,0.56f);
glVertex2f(-0.88f,0.54f);
glVertex2f(-0.92f,0.56f);
glVertex2f(-0.88f,0.56f);
glVertex2f(-0.86f,0.58f);
glVertex2f(-0.8f,0.56f);
glVertex2f(-0.8f,0.54f);
glEnd();
////////////////////////////////////////////
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(1.4f,0.54f);
glVertex2f(1.36f,0.54f);
glVertex2f(1.38f,0.56f);
glVertex2f(1.4f,0.56f);
glVertex2f(1.44f,0.52f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(1.34f,0.56f);
glVertex2f(1.32f,0.54f);
glVertex2f(1.28f,0.56f);
glVertex2f(1.26f,0.58f);
glVertex2f(1.3f,0.6f);
glVertex2f(1.34f,0.58f);
glVertex2f(1.38f,0.56f);
glVertex2f(1.36f,0.54f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(1.24f,0.56f);
glVertex2f(1.2f,0.54f);
glVertex2f(1.2f,0.56f);
glVertex2f(1.26f,0.58f);
glVertex2f(1.28f,0.56f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(1.16f,0.56f);
glVertex2f(1.12f,0.54f);
glVertex2f(1.08f,0.56f);
glVertex2f(1.12f,0.56f);
glVertex2f(1.14f,0.58f);
glVertex2f(1.2f,0.56f);
glVertex2f(1.2f,0.54f);
glEnd();
/////////////////////////////////////////
/////////////////////////////////////////
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(2.12f,0.86f);
glVertex2f(2.1f,0.82f);
glVertex2f(2.08f,0.8f);
glVertex2f(2.04f,0.8f);
glVertex2f(2.04f,0.82f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(1.96f,0.82f);
glVertex2f(1.92f,0.82f);
glVertex2f(1.92f,0.86f);
glVertex2f(1.98f,0.84f);
glVertex2f(2.04f,0.82f);
glVertex2f(2.04f,0.8f);
glVertex2f(2.0f,0.78f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(1.88f,0.84f);
glVertex2f(1.8f,0.84f);
glVertex2f(1.88f,0.8f);
glVertex2f(1.96f,0.82f);
glVertex2f(1.92f,0.86f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(1.82f,0.84f);
glVertex2f(1.78f,0.84f);
glVertex2f(1.76f,0.88f);
glVertex2f(1.78f,0.86f);
glVertex2f(1.8f,0.86f);
glEnd();
////////////////////////////////////////////
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(0.12f,0.86f);
glVertex2f(0.1f,0.82f);
glVertex2f(0.08f,0.8f);
glVertex2f(0.04f,0.8f);
glVertex2f(0.04f,0.82f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.04f,0.82f);
glVertex2f(-0.08f,0.82f);
glVertex2f(-0.08f,0.86f);
glVertex2f(-0.02f,0.84f);
glVertex2f(0.04f,0.82f);
glVertex2f(0.04f,0.8f);
glVertex2f(0.0f,0.78f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.12f,0.84f);
glVertex2f(-0.2f,0.84f);
glVertex2f(-0.12f,0.8f);
glVertex2f(-0.08f,0.82f);
glVertex2f(-0.08f,0.86f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.18f,0.84f);
glVertex2f(-0.22f,0.84f);
glVertex2f(-0.24f,0.88f);
glVertex2f(-0.22f,0.86f);
glVertex2f(-0.2f,0.86f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(0.12f,0.86f);
glVertex2f(0.1f,0.82f);
glVertex2f(0.08f,0.8f);
glVertex2f(0.04f,0.8f);
glVertex2f(0.04f,0.82f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.04f,0.82f);
glVertex2f(-0.08f,0.82f);
glVertex2f(-0.08f,0.86f);
glVertex2f(-0.02f,0.84f);
glVertex2f(0.04f,0.82f);
glVertex2f(0.04f,0.8f);
glVertex2f(0.0f,0.78f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.12f,0.84f);
glVertex2f(-0.2f,0.84f);
glVertex2f(-0.12f,0.8f);
glVertex2f(-0.04f,0.82f);
glVertex2f(-0.08f,0.86f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.18f,0.84f);
glVertex2f(-0.22f,0.84f);
glVertex2f(-0.24f,0.88f);
glVertex2f(-0.22f,0.86f);
glVertex2f(-0.2f,0.86f);
glEnd();
////////////////////////////////////////////
///cloud
////////////////////////////////////////
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(0.58f,0.58f);
glVertex2f(0.56f,0.56f);
glVertex2f(0.54f,0.58f);
glVertex2f(0.54f,0.6f);
glVertex2f(0.58f,0.6f);
glVertex2f(0.64f,0.58f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(0.5f,0.6f);
glVertex2f(0.46f,0.58f);
glVertex2f(0.46f,0.6f);
glVertex2f(0.5f,0.62f);
glVertex2f(0.54f,0.6f);
glVertex2f(0.54f,0.58f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(0.4f,0.57f);
glVertex2f(0.34f,0.58f);
glVertex2f(0.32f,0.6f);
glVertex2f(0.4f,0.62f);
glVertex2f(0.46f,0.6f);
glVertex2f(0.46f,0.58f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(0.3f,0.58f);
glVertex2f(0.28f,0.58f);
glVertex2f(0.32f,0.56f);
glVertex2f(0.34f,0.58f);
glVertex2f(0.32f,0.6f);
glEnd();
////////////////////////////////////
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(2.58f,0.58f);
glVertex2f(2.56f,0.56f);
glVertex2f(2.54f,0.58f);
glVertex2f(2.54f,0.6f);
glVertex2f(2.58f,0.6f);
glVertex2f(2.64f,0.58f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(2.5f,0.6f);
glVertex2f(2.46f,0.58f);
glVertex2f(2.46f,0.6f);
glVertex2f(2.5f,0.62f);
glVertex2f(2.54f,0.6f);
glVertex2f(2.54f,0.58f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(2.4f,0.57f);
glVertex2f(2.34f,0.58f);
glVertex2f(2.32f,0.6f);
glVertex2f(2.4f,0.62f);
glVertex2f(2.46f,0.6f);
glVertex2f(2.46f,0.58f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(2.3f,0.58f);
glVertex2f(2.28f,0.58f);
glVertex2f(2.32f,0.56f);
glVertex2f(2.34f,0.58f);
glVertex2f(2.32f,0.6f);
glEnd();
glPopMatrix();
        ///End///

///Road
///Line01
glBegin(GL_POLYGON);
glColor3ub(106,110,119);
glVertex2f(-1.0f,-0.26f);
glVertex2f(-1.0f,-0.4f);
glVertex2f(3.0f,-0.4f);
glVertex2f(3.0f,-0.26f);
glEnd();
///////////////////////////////
///Line02
glBegin(GL_POLYGON);
glColor3ub(138,143,153);
glVertex2f(-1.0f,-0.4f);
glVertex2f(-1.0f,-0.44f);
glVertex2f(3.0f,-0.44f);
glVertex2f(3.0f,-0.4f);
glEnd();
//////////////////////////////
///Line03
glBegin(GL_POLYGON);
glColor3ub(138,143,153);
glVertex2f(-1.0f,-0.44f);
glVertex2f(-1.0f,-0.5f);
glVertex2f(3.0f,-0.5f);
glVertex2f(3.0f,-0.44f);
glEnd();
//////////////////////////////
glLoadIdentity();
glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(position2,0.0f,0.0f);
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(120,120,120);
///Curved Line
glVertex2f(-0.78f,-0.4f);
glVertex2f(-0.76f,-0.44f);

glVertex2f(-0.54f,-0.4f);
glVertex2f(-0.52f,-0.44f);

glVertex2f(-0.3f,-0.4f);
glVertex2f(-0.28f,-0.44f);

glVertex2f(-0.06f,-0.4f);
glVertex2f(-0.04f,-0.44f);

glVertex2f(0.18f,-0.4f);
glVertex2f(0.2f,-0.44f);

glVertex2f(0.42f,-0.4f);
glVertex2f(0.44f,-0.44f);

glVertex2f(0.66f,-0.4f);
glVertex2f(0.68f,-0.44f);

glVertex2f(0.90f,-0.4f);
glVertex2f(0.92f,-0.44f);

glVertex2f(1.14f,-0.4f);
glVertex2f(1.16f,-0.44f);

glVertex2f(1.38f,-0.4f);
glVertex2f(1.4f,-0.44f);

glVertex2f(1.62f,-0.4f);
glVertex2f(1.64f,-0.44f);

glVertex2f(1.86f,-0.4f);
glVertex2f(1.88f,-0.44f);

glVertex2f(2.1f,-0.4f);
glVertex2f(2.12f,-0.44f);

glVertex2f(2.34f,-0.4f);
glVertex2f(2.36f,-0.44f);

glVertex2f(2.58f,-0.4f);
glVertex2f(2.6f,-0.44f);

glVertex2f(2.82f,-0.4f);
glVertex2f(2.84f,-0.44f);

glVertex2f(3.06f,-0.4f);
glVertex2f(3.08f,-0.44f);

///Straight Line
glVertex2f(-0.76f,-0.44f);
glVertex2f(-0.76f,-0.5f);

glVertex2f(-0.52f,-0.44f);
glVertex2f(-0.52f,-0.5f);

glVertex2f(-0.28f,-0.44f);
glVertex2f(-0.28f,-0.5f);

glVertex2f(-0.04f,-0.44f);
glVertex2f(-0.04f,-0.5f);

glVertex2f(0.2f,-0.44f);
glVertex2f(0.2f,-0.5f);

glVertex2f(0.44f,-0.44f);
glVertex2f(0.44f,-0.5f);

glVertex2f(0.68f,-0.44f);
glVertex2f(0.68f,-0.5f);

glVertex2f(0.92f,-0.44f);
glVertex2f(0.92f,-0.5f);

glVertex2f(1.16f,-0.44f);
glVertex2f(1.16f,-0.5f);

glVertex2f(1.4f,-0.44f);
glVertex2f(1.4f,-0.5f);

glVertex2f(1.64f,-0.44f);
glVertex2f(1.64f,-0.5f);

glVertex2f(1.88f,-0.44f);
glVertex2f(1.88f,-0.5f);

glVertex2f(2.12f,-0.44f);
glVertex2f(2.12f,-0.5f);

glVertex2f(2.36f,-0.44f);
glVertex2f(2.36f,-0.5f);

glVertex2f(2.60f,-0.44f);
glVertex2f(2.60f,-0.5f);

glVertex2f(2.84f,-0.44f);
glVertex2f(2.84f,-0.5f);

glVertex2f(3.08f,-0.44f);
glVertex2f(3.08f,-0.5f);
////////////////////////////////
///Division mid line
glVertex2f(-1.0f,-0.44f);
glVertex2f(3.0f,-0.44f);
////////////////////////////////

glColor3f(1.0f,1.0f,1.0f);
///Road Lane
glVertex2f(-0.90f,-0.36f);
glVertex2f(-0.8f,-0.36f);

glVertex2f(-0.7f,-0.36f);
glVertex2f(-0.6f,-0.36f);

glVertex2f(-0.5f,-0.36f);
glVertex2f(-0.4f,-0.36f);

glVertex2f(-0.3f,-0.36f);
glVertex2f(-0.2f,-0.36f);

glVertex2f(-0.1f,-0.36f);
glVertex2f(0.0f,-0.36f);

glVertex2f(0.1f,-0.36f);
glVertex2f(0.2f,-0.36f);

glVertex2f(0.3f,-0.36f);
glVertex2f(0.4f,-0.36f);

glVertex2f(0.5f,-0.36f);
glVertex2f(0.6f,-0.36f);

glVertex2f(0.7f,-0.36f);
glVertex2f(0.8f,-0.36f);

glVertex2f(0.9f,-0.36f);
glVertex2f(1.0f,-0.36f);

glVertex2f(1.1f,-0.36f);
glVertex2f(1.2f,-0.36f);

glVertex2f(1.3f,-0.36f);
glVertex2f(1.4f,-0.36f);

glVertex2f(1.5f,-0.36f);
glVertex2f(1.6f,-0.36f);

glVertex2f(1.7f,-0.36f);
glVertex2f(1.8f,-0.36f);

glVertex2f(1.9f,-0.36f);
glVertex2f(2.0f,-0.36f);

glVertex2f(2.1f,-0.36f);
glVertex2f(2.2f,-0.36f);

glVertex2f(2.3f,-0.36f);
glVertex2f(2.4f,-0.36f);

glVertex2f(2.5f,-0.36f);
glVertex2f(2.6f,-0.36f);

glVertex2f(2.7f,-0.36f);
glVertex2f(2.8f,-0.36f);

glVertex2f(2.9f,-0.36f);
glVertex2f(3.0f,-0.36f);

glEnd();
glPopMatrix();
        ///Lines End--

///GROUND
glBegin(GL_POLYGON);
glColor3ub(39,45,59);
glVertex2f(-1.0f,-0.5f);
glVertex2f(-1.0f,-1.0f);
glVertex2f(1.5f,-1.0f);
glVertex2f(1.5f,-0.5f);
glEnd();
//////////////////////////////////
///UnderGround
glLoadIdentity();
glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(position2,0.0f,0.0f);
////////////////////////////
glColor3ub(57,55,79);
circle(-0.86,-0.6,0.04);
circle(1.14,-0.6,0.04);
///////////////////////////////////
circle(-0.64,-0.58,0.02);
circle(1.36,-0.58,0.02);
///////////////////////////////////
circle(-0.68,-0.72,0.02);
circle(1.32,-0.72,0.02);
///////////////////////////////////
circle(-0.3,-0.66,0.04);
circle(1.7,-0.66,0.04);
///////////////////////////////////
circle(-0.22,-0.76,0.02);
circle(1.18,-0.76,0.02);
///////////////////////////////////
circle(-0.5,-0.92,0.03);
circle(1.5,-0.92,0.03);
///////////////////////////////////
circle(-0.04,-0.58,0.03);
circle(1.94,-0.58,0.03);
///////////////////////////////////
circle(0.1,-0.56,0.02);
circle(2.1,-0.56,0.02);
///////////////////////////////////
circle(0.32,-0.68,0.02);
circle(2.32,-0.68,0.02);
///////////////////////////////////
circle(0.38,-0.76,0.045);
circle(2.38,-0.76,0.045);
///////////////////////////////////
circle(0.52,-0.56,0.02);
circle(2.52,-0.56,0.02);
///////////////////////////////////
circle(0.76,-0.66,0.02);
circle(2.76,-0.66,0.02);
///////////////////////////////////
circle(0.94,-0.7,0.04);
circle(2.94,-0.7,0.04);
///////////////////////////////////
circle(0.6,-0.92,0.03);
circle(2.6,-0.92,0.03);
///////////////////////////////////
circle(0.06,-0.92,0.04);
circle(2.06,-0.92,0.04);
///////////////////////////////////
glPopMatrix();

///Building
//////////////////////////////////
glLoadIdentity();
glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(position2,0.0f,0.0f);
////////////////////////////////////
///Back Building
glBegin(GL_POLYGON);
glColor3ub(72,82,107);
glVertex2f(-0.88f,0.04f);
glVertex2f(-0.74f,0.04f);
glVertex2f(-0.74f,-0.32f);
glVertex2f(-1.0f,-0.32f);
glVertex2f(-1.00f,0.24f);
glVertex2f(-0.88f,0.24f);
glEnd();
////////////////////////
glBegin(GL_POLYGON);
glColor3ub(72,82,107);
glVertex2f(-0.60f,0.1f);
glVertex2f(-0.54f,0.1f);
glVertex2f(-0.54f,-0.32f);
glVertex2f(-0.74f,-0.32f);
glVertex2f(-0.74f,0.18f);
glVertex2f(-0.6f,0.18f);
glEnd();
////////////////////////
glBegin(GL_POLYGON);
glColor3ub(72,82,107);
glVertex2f(-0.34f,0.1f);
glVertex2f(-0.24f,0.1f);
glVertex2f(-0.24f,-0.32f);
glVertex2f(-0.54f,-0.32f);
glVertex2f(-0.54f,0.3f);
glVertex2f(-0.34f,0.3f);
glEnd();
////////////////////////
glBegin(GL_POLYGON);
glColor3ub(72,82,107);
glVertex2f(-0.12f,0.14f);
glVertex2f(0.14f,0.14f);
glVertex2f(0.14f,-0.32f);
glVertex2f(-0.24f,-0.32f);
glVertex2f(-0.24f,0.24f);
glVertex2f(-0.12f,0.24f);
glEnd();
////////////////////////
glBegin(GL_POLYGON);
glColor3ub(72,82,107);
glVertex2f(0.34f,0.14f);
glVertex2f(0.38f,0.14f);
glVertex2f(0.38f,-0.32f);
glVertex2f(0.14f,-0.32f);
glVertex2f(0.14f,0.3f);
glVertex2f(0.34f,0.3f);
glEnd();
////////////////////////
glBegin(GL_POLYGON);
glColor3ub(72,82,107);
glVertex2f(0.54f,0.2f);
glVertex2f(0.56f,0.2f);
glVertex2f(0.56f,-0.32f);
glVertex2f(0.38f,-0.32f);
glVertex2f(0.38f,0.24f);
glVertex2f(0.54f,0.24f);
glEnd();
////////////////////////
glBegin(GL_POLYGON);
glColor3ub(72,82,107);
glVertex2f(0.74f,0.04f);
glVertex2f(0.84f,0.04f);
glVertex2f(0.84f,-0.32f);
glVertex2f(0.56f,-0.32f);
glVertex2f(0.56f,0.28f);
glVertex2f(0.74f,0.28f);
glEnd();
////////////////////////
glBegin(GL_POLYGON);
glColor3ub(72,82,107);
glVertex2f(0.94f,0.14f);
glVertex2f(1.0f,0.14f);
glVertex2f(1.0f,-0.32f);
glVertex2f(0.84f,-0.32f);
glVertex2f(0.84f,0.24f);
glVertex2f(0.94f,0.24f);
glEnd();
/////////////////////////
glBegin(GL_POLYGON);
glColor3ub(72,82,107);
glVertex2f(1.0f,0.14f);
glVertex2f(1.0f,0.14f);
glVertex2f(1.0f,-0.32f);
glVertex2f(0.84f,-0.32f);
glVertex2f(0.84f,0.17f);
glVertex2f(1.0f,0.17f);
glEnd();
fakeBuildingback();
        ///End---
////////////////////////
///front building
glBegin(GL_POLYGON);
glColor3ub(39,45,59);
glVertex2f(-0.8f,0.0f);
glVertex2f(-0.7f,0.0f);
glVertex2f(-0.7f,-0.32f);
glVertex2f(-1.0f,-0.32f);
glVertex2f(-1.0f,0.1f);
glVertex2f(-0.8f,0.1f);
glEnd();
//////////////////////////
glBegin(GL_POLYGON);
glColor3ub(39,45,59);
glVertex2f(-0.5f,0.04f);
glVertex2f(-0.4f,0.04f);
glVertex2f(-0.4f,-0.32f);
glVertex2f(-0.7f,-0.32f);
glVertex2f(-0.7f,0.1f);
glVertex2f(-0.5f,0.1f);
glEnd();
////////////////////////
glBegin(GL_POLYGON);
glColor3ub(39,45,59);
glVertex2f(-0.3f,0.0f);
glVertex2f(-0.2f,0.0f);
glVertex2f(-0.2f,-0.32f);
glVertex2f(-0.4f,-0.32f);
glVertex2f(-0.4f,0.14f);
glVertex2f(-0.3f,0.14f);
glEnd();
/////////////////////////
glBegin(GL_POLYGON);
glColor3ub(39,45,59);
glVertex2f(-0.06f,-0.06f);
glVertex2f(0.0f,-0.06f);
glVertex2f(0.0f,-0.32f);
glVertex2f(-0.2f,-0.32f);
glVertex2f(-0.2f,0.08f);
glVertex2f(-0.06f,0.08f);
glEnd();
///////////////////////////
glBegin(GL_POLYGON);
glColor3ub(39,45,59);
glVertex2f(0.2f,-0.06f);
glVertex2f(0.26f,-0.06f);
glVertex2f(0.26f,-0.32f);
glVertex2f(0.0f,-0.32f);
glVertex2f(0.0f,0.2f);
glVertex2f(0.2f,0.2f);
glEnd();
////////////////////////////
glBegin(GL_POLYGON);
glColor3ub(39,45,59);
glVertex2f(0.4f,0.04f);
glVertex2f(0.5f,0.04f);
glVertex2f(0.5f,-0.32f);
glVertex2f(0.26f,-0.32f);
glVertex2f(0.26f,0.14f);
glVertex2f(0.4f,0.14f);
glEnd();
////////////////////////////
glBegin(GL_POLYGON);
glColor3ub(39,45,59);
glVertex2f(0.8f,-0.06f);
glVertex2f(0.9f,-0.06f);
glVertex2f(0.9f,-0.32f);
glVertex2f(0.5f,-0.32f);
glVertex2f(0.5f,0.2f);
glVertex2f(0.8f,0.2f);
glEnd();
//////////////////////////////
glBegin(GL_POLYGON);
glColor3ub(39,45,59);
glVertex2f(0.9f,0.14f);
glVertex2f(1.0f,0.14f);
glVertex2f(1.0f,-0.32f);
glVertex2f(0.9f,-0.32f);
glEnd();
fakebuildingfornt();
glPopMatrix();
        ///End---
/////////////////////////////////

/////////////////////////////////

///Obejct_Character
glLoadIdentity();
glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(0.0,position4,0.0f);
///Front tier
glColor3f(0.0f,0.0f,0.0f);
circle(-0.80+xr,-0.34+yr,0.03);
glColor3ub(175,175,175);
circle(-0.80+xr,-0.34+yr,0.022);
///------------------------------------///
///Back Tier
glColor3f(0.0f,0.0f,0.0f);
circle(-0.90+xr,-0.34+yr,0.03);
glColor3ub(175,175,175);
circle(-0.90+xr,-0.34+yr,0.022);
///--------------------------------------///
///bike handle
glColor3ub(86,193,255);
circle(-0.825+xr,-0.26+yr,0.01);
///-------------------------------------///
///Human Head
glColor3ub(255,123,111);
circle(-0.87+xr,-0.22+yr,0.015);
///-----------------------------------///
glBegin(GL_POLYGON);
glColor3ub(86,193,255);
glVertex2f(-0.89f+xr,-0.32f+yr);
glVertex2f(-0.92f+xr,-0.32f+yr);
glVertex2f(-0.94f+xr,-0.28f+yr);
glVertex2f(-0.89f+xr,-0.28f+yr);
glVertex2f(-0.85f+xr,-0.31f+yr);
glVertex2f(-0.85f+xr,-0.34f+yr);
glVertex2f(-0.88f+xr,-0.34f+yr);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(86,193,255);
glVertex2f(-0.82f+xr,-0.32f+yr);
glVertex2f(-0.84f+xr,-0.32f+yr);
glVertex2f(-0.84f+xr,-0.34f+yr);
glVertex2f(-0.80f+xr,-0.34f+yr);
glVertex2f(-0.82f+xr,-0.27f+yr);
glVertex2f(-0.83f+xr,-0.27f+yr);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(250,0,140);
glVertex2f(-0.87f+xr,-0.23f+yr);
glVertex2f(-0.87f+xr,-0.28f+yr);
glVertex2f(-0.89f+xr,-0.28f+yr);
glVertex2f(-0.89f+xr,-0.24f+yr);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(250,0,140);
glVertex2f(-0.85f+xr,-0.255f+yr);
glVertex2f(-0.87f+xr,-0.23f+yr);
glVertex2f(-0.87f+xr,-0.25f+yr);
glVertex2f(-0.85f+xr,-0.27f+yr);
glVertex2f(-0.83f+xr,-0.265f+yr);
glVertex2f(-0.83f+xr,-0.255f+yr);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(175,175,175);
glVertex2f(-0.85f+xr,-0.31f+yr);
glVertex2f(-0.85f+xr,-0.34f+yr);
glVertex2f(-0.84f+xr,-0.34f+yr);
glVertex2f(-0.84f+xr,-0.31f+yr);
glVertex2f(-0.87f+xr,-0.28f+yr);
glVertex2f(-0.89f+xr,-0.28f+yr);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(-0.86f+xr,-0.2f+yr);
glVertex2f(-0.89f+xr,-0.2f+yr);
glVertex2f(-0.89f+xr,-0.23f+yr);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(85,107,47);
glVertex2f(-0.94f+xr,-0.28f+yr);
glVertex2f(-0.90f+xr,-0.28f+yr);
glVertex2f(-0.90f+xr,-0.25f+yr);
glVertex2f(-0.94f+xr,-0.25f+yr);
glEnd();


//////////////////////////////////
///Obstacles
glLoadIdentity();
glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(position3,0.0f,0.0f);
///Object
///////////////////////////////
///Hole-1
glBegin(GL_POLYGON);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.18f,-0.36f);
glVertex2f(0.28f,-0.34f);
glVertex2f(0.36f,-0.36f);
glVertex2f(0.32f,-0.38f);
glVertex2f(0.22f,-0.38f);
glEnd();
////////////////////////////////
///Water-1
glBegin(GL_POLYGON);
glColor3ub(86,193,255);
glVertex2f(1.38f,-0.36f);
glVertex2f(1.44f,-0.34f);
glVertex2f(1.48f,-0.34f);
glVertex2f(1.52f,-0.36f);
glVertex2f(1.48f,-0.38f);
glVertex2f(1.44f,-0.38f);
glEnd();
////////////////////////////////
///Dustbin-1
glBegin(GL_POLYGON);
glColor3ub(242,197,14);
glVertex2f(2.88f,-0.3f);
glVertex2f(2.86f,-0.28f);
glVertex2f(2.82f,-0.28f);
glVertex2f(2.80f,-0.3f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(255,127,80);
glVertex2f(2.88f,-0.30f);
glVertex2f(2.88f,-0.32f);
glVertex2f(2.8f,-0.32f);
glVertex2f(2.8f,-0.30f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(242,197,14);
glVertex2f(2.87f,-0.32f);
glVertex2f(2.86f,-0.38f);
glVertex2f(2.82f,-0.38f);
glVertex2f(2.81f,-0.32f);
glEnd();
////////////////////////////////
///Lomba kichu Ekta-1
glBegin(GL_POLYGON);
glColor3ub(199,21,133);
glVertex2f(3.54f,-0.36f);
glVertex2f(3.52f,-0.36f);
glVertex2f(3.52f,-0.38f);
glVertex2f(3.60f,-0.38f);
glVertex2f(3.60f,-0.36f);
glVertex2f(3.58f,-0.36f);
glVertex2f(3.58f,-0.28f);
glVertex2f(3.54f,-0.28f);
glEnd();
////////////////////////////////
///Car-1
glBegin(GL_POLYGON);
glColor3ub(153,0,18);
glVertex2f(4.32f,-0.30f);
glVertex2f(4.28f,-0.32f);
glVertex2f(4.28f,-0.36f);
glVertex2f(4.54f,-0.36f);
glVertex2f(4.54f,-0.32f);
glVertex2f(4.50f,-0.3f);
glVertex2f(4.50f,-0.24f);
glVertex2f(4.32f,-0.24f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(48,125,126);
glVertex2f(4.34f,-0.26f);
glVertex2f(4.40f,-0.26f);
glVertex2f(4.40f,-0.3f);
glVertex2f(4.34f,-0.3f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(48,125,126);
glVertex2f(4.42f,-0.26f);
glVertex2f(4.48f,-0.26f);
glVertex2f(4.48f,-0.3f);
glVertex2f(4.42f,-0.3f);
glEnd();
glColor3b(255,239,0);
circle(4.34,-0.36,0.02);
circle(4.48,-0.36,0.02);
///////////////////////////////////
///Upordik kichu ekta-1
glBegin(GL_POLYGON);
glColor3ub(250,0,0);
glVertex2f(5.22f,-0.30f);
glVertex2f(5.22f,-0.38f);
glVertex2f(5.26f,-0.38f);
glVertex2f(5.26f,-0.30f);
glVertex2f(5.28f,-0.30f);
glVertex2f(5.24f,-0.27f);
glVertex2f(5.20f,-0.30f);
glEnd();
/////////////////////////////////
///Car-2
glBegin(GL_POLYGON);
glColor3ub(167,98,219);
glVertex2f(6.40f,-0.30f);
glVertex2f(6.36f,-0.32f);
glVertex2f(6.36f,-0.36f);
glVertex2f(6.62f,-0.36f);
glVertex2f(6.62f,-0.32f);
glVertex2f(6.58f,-0.30f);
glVertex2f(6.58f,-0.24f);
glVertex2f(6.40f,-0.24f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(48,125,126);
glVertex2f(6.42f,-0.26f);
glVertex2f(6.48f,-0.26f);
glVertex2f(6.48f,-0.3f);
glVertex2f(6.42f,-0.3f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(48,125,126);
glVertex2f(6.50f,-0.26f);
glVertex2f(6.56f,-0.26f);
glVertex2f(6.56f,-0.3f);
glVertex2f(6.50f,-0.3f);
glEnd();
glColor3b(255,239,0);
circle(6.42,-0.36,0.02);
circle(6.56,-0.36,0.02);
////////////////////////////////
///Dustbin-2
glBegin(GL_POLYGON);
glColor3ub(242,197,14);
glVertex2f(7.28f,-0.30f);
glVertex2f(7.26f,-0.28f);
glVertex2f(7.22f,-0.28f);
glVertex2f(7.20f,-0.30f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(255,127,80);
glVertex2f(7.28f,-0.30f);
glVertex2f(7.28f,-0.32f);
glVertex2f(7.20f,-0.32f);
glVertex2f(7.20f,-0.30f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(242,197,14);
glVertex2f(7.27f,-0.32f);
glVertex2f(7.26f,-0.38f);
glVertex2f(7.22f,-0.38f);
glVertex2f(7.21f,-0.32f);
glEnd();
/////////////////////////////////
///Car-3
glBegin(GL_POLYGON);
glColor3ub(167,98,29);
glVertex2f(7.9f,-0.32f);
glVertex2f(7.86f,-0.32f);
glVertex2f(7.86f,-0.36f);
glVertex2f(8.12f,-0.36f);
glVertex2f(8.12f,-0.32f);
glVertex2f(8.08f,-0.32f);
glVertex2f(8.08f,-0.26f);
glVertex2f(7.90f,-0.26f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(48,125,126);
glVertex2f(7.92f,-0.28f);
glVertex2f(7.98f,-0.28f);
glVertex2f(7.98f,-0.32f);
glVertex2f(7.92f,-0.32f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(48,125,126);
glVertex2f(8.0f,-0.28f);
glVertex2f(8.06f,-0.28f);
glVertex2f(8.06f,-0.32f);
glVertex2f(8.0f,-0.32f);
glEnd();
glColor3b(255,239,0);
circle(7.92,-0.36,0.02);
circle(8.06,-0.36,0.02);
//////////////////////////////////
///Lomba kichu ekta-2
glBegin(GL_POLYGON);
glColor3ub(228,155,150);
glVertex2f(8.69f,-0.36f);
glVertex2f(8.67f,-0.36f);
glVertex2f(8.67f,-0.38f);
glVertex2f(8.75f,-0.38f);
glVertex2f(8.75f,-0.36f);
glVertex2f(8.73f,-0.36f);
glVertex2f(8.73f,-0.28f);
glVertex2f(8.69f,-0.28f);
glEnd();
//////////////////////////////////
///Water-2
glBegin(GL_POLYGON);
glColor3ub(86,193,255);
glVertex2f(9.38f,-0.36f);
glVertex2f(9.44f,-0.34f);
glVertex2f(9.48f,-0.34f);
glVertex2f(9.52f,-0.36f);
glVertex2f(9.48f,-0.38f);
glVertex2f(9.44f,-0.38f);
glEnd();
///////////////////////////////
///Box-1
glBegin(GL_POLYGON);
glColor3ub(218,165,32);
glVertex2f(10.08f,-0.28f);
glVertex2f(10.18f,-0.28f);
glVertex2f(10.18f,-0.38f);
glVertex2f(10.08f,-0.38f);
glEnd();
glBegin(GL_LINES);
glColor3ub(0.0,0.0,0.0);
glVertex2f(10.08f,-0.28f);
glVertex2f(10.18f,-0.28f);
glVertex2f(10.18f,-0.28f);
glVertex2f(10.18f,-0.38f);
glVertex2f(10.18f,-0.38f);
glVertex2f(10.08f,-0.38f);
glVertex2f(10.08f,-0.38f);
glVertex2f(10.08f,-0.28f);
glVertex2f(10.08f,-0.31f);
glVertex2f(10.18f,-0.31f);
glVertex2f(10.08f,-0.34f);
glVertex2f(10.18f,-0.34f);
glEnd();
/////////////////////////////////
///Hole-2
glBegin(GL_POLYGON);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(10.68f,-0.36f);
glVertex2f(10.78f,-0.34f);
glVertex2f(10.86f,-0.36f);
glVertex2f(10.82f,-0.38f);
glVertex2f(10.72f,-0.38f);
glEnd();
/////////////////////////////////
///Katakata kichu-1
glBegin(GL_LINES);
glColor3ub(0.0,0.0,0.0);
glVertex2f(11.54f,-0.38f);
glVertex2f(11.54f,-0.28f);
glVertex2f(11.55f,-0.38f);
glVertex2f(11.55f,-0.28f);
glVertex2f(11.56f,-0.38f);
glVertex2f(11.56f,-0.28f);
glVertex2f(11.57f,-0.38f);
glVertex2f(11.57f,-0.28f);
glVertex2f(11.58f,-0.38f);
glVertex2f(11.58f,-0.28f);
glVertex2f(11.59f,-0.38f);
glVertex2f(11.59f,-0.28f);
glVertex2f(11.60f,-0.38f);
glVertex2f(11.60f,-0.28f);
glVertex2f(11.61f,-0.38f);
glVertex2f(11.61f,-0.28f);
glVertex2f(11.62f,-0.38f);
glVertex2f(11.62f,-0.28f);
glVertex2f(11.63f,-0.38f);
glVertex2f(11.63f,-0.28f);
glVertex2f(11.64f,-0.38f);
glVertex2f(11.64f,-0.28f);
glVertex2f(11.54f,-0.38f);
glVertex2f(11.64f,-0.38f);
glEnd();
//////////////////////////////
///Ball-1
glColor3b(0,0,0);
circle(12.52,-0.32,0.06);
glColor3ub(255,0,0);
circle(12.52,-0.32,0.05);
glColor3ub(255,255,255);
circle(12.52,-0.32,0.04);
///////////////////////////////
///Upordik Kichu ekta-2
glBegin(GL_POLYGON);
glColor3ub(124,252,0);
glVertex2f(13.32f,-0.30f);
glVertex2f(13.32f,-0.38f);
glVertex2f(13.36f,-0.38f);
glVertex2f(13.36f,-0.30f);
glVertex2f(13.38f,-0.30f);
glVertex2f(13.34f,-0.28f);
glVertex2f(13.30f,-0.30f);
glEnd();
/////////////////////////////////
///Car-4
glBegin(GL_POLYGON);
glColor3ub(0,0,128);
glVertex2f(14.10f,-0.30f);
glVertex2f(14.06f,-0.32f);
glVertex2f(14.06f,-0.36f);
glVertex2f(14.32f,-0.36f);
glVertex2f(14.32f,-0.32f);
glVertex2f(14.28f,-0.30f);
glVertex2f(14.28f,-0.24f);
glVertex2f(14.10f,-0.24f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(48,125,126);
glVertex2f(14.12f,-0.26f);
glVertex2f(14.18f,-0.26f);
glVertex2f(14.18f,-0.30f);
glVertex2f(14.12f,-0.30f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(48,125,126);
glVertex2f(14.20f,-0.26f);
glVertex2f(14.26f,-0.26f);
glVertex2f(14.26f,-0.30f);
glVertex2f(14.20f,-0.30f);
glEnd();
glColor3b(255,239,0);
circle(14.12,-0.36,0.02);
circle(14.26,-0.36,0.02);
////////////////////////////////
///Triangle-1
glBegin(GL_POLYGON);
glColor3ub(244,164,96);
glVertex2f(14.87f,-0.38f);
glVertex2f(14.97f,-0.38f);
glVertex2f(14.92f,-0.28f);
glEnd();
///////////////////////////////
///Dustbin-3
glBegin(GL_POLYGON);
glColor3ub(242,197,14);
glVertex2f(15.68f,-0.30f);
glVertex2f(15.66f,-0.28f);
glVertex2f(15.62f,-0.28f);
glVertex2f(15.60f,-0.30f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(255,127,80);
glVertex2f(15.68f,-0.30f);
glVertex2f(15.68f,-0.32f);
glVertex2f(15.60f,-0.32f);
glVertex2f(15.60f,-0.30f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(242,197,14);
glVertex2f(15.67f,-0.32f);
glVertex2f(15.66f,-0.38f);
glVertex2f(15.62f,-0.38f);
glVertex2f(15.61f,-0.32f);
glEnd();
///////////////////////////////
///Box-2
glBegin(GL_POLYGON);
glColor3ub(218,165,32);
glVertex2f(16.38f,-0.28f);
glVertex2f(16.48f,-0.28f);
glVertex2f(16.48f,-0.38f);
glVertex2f(16.38f,-0.38f);
glEnd();
glBegin(GL_LINES);
glColor3ub(0.0,0.0,0.0);
glVertex2f(16.38f,-0.28f);
glVertex2f(16.48f,-0.28f);
glVertex2f(16.48f,-0.28f);
glVertex2f(16.48f,-0.38f);
glVertex2f(16.48f,-0.38f);
glVertex2f(16.38f,-0.38f);
glVertex2f(16.38f,-0.38f);
glVertex2f(16.38f,-0.28f);
glVertex2f(16.38f,-0.31f);
glVertex2f(16.48f,-0.31f);
glVertex2f(16.38f,-0.34f);
glVertex2f(16.48f,-0.34f);
glEnd();
////////////////////////////////
///Lomba kicuAkta-3
glBegin(GL_POLYGON);
glColor3ub(255,0,255);
glVertex2f(17.09f,-0.36f);
glVertex2f(17.07f,-0.36f);
glVertex2f(17.07f,-0.38f);
glVertex2f(17.15f,-0.38f);
glVertex2f(17.15f,-0.36f);
glVertex2f(17.13f,-0.36f);
glVertex2f(17.13f,-0.28f);
glVertex2f(17.09f,-0.28f);
glEnd();
////////////////////////////////
///Car-5
glBegin(GL_POLYGON);
glColor3ub(167,98,29);
glVertex2f(17.9f,-0.32f);
glVertex2f(17.86f,-0.32f);
glVertex2f(17.86f,-0.36f);
glVertex2f(18.12f,-0.36f);
glVertex2f(18.12f,-0.32f);
glVertex2f(18.08f,-0.32f);
glVertex2f(18.08f,-0.26f);
glVertex2f(17.90f,-0.26f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(48,125,126);
glVertex2f(17.92f,-0.28f);
glVertex2f(17.98f,-0.28f);
glVertex2f(17.98f,-0.32f);
glVertex2f(17.92f,-0.32f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(48,125,126);
glVertex2f(18.0f,-0.28f);
glVertex2f(18.06f,-0.28f);
glVertex2f(18.06f,-0.32f);
glVertex2f(18.0f,-0.32f);
glEnd();
glColor3b(255,239,0);
circle(17.92,-0.36,0.02);
circle(18.06,-0.36,0.02);
//////////////////////////////////
///Katakata kichu ekta-2
glBegin(GL_LINES);
glColor3ub(0.0,0.0,0.0);
glVertex2f(18.84f,-0.38f);
glVertex2f(18.84f,-0.28f);
glVertex2f(18.85f,-0.38f);
glVertex2f(18.85f,-0.28f);
glVertex2f(18.86f,-0.38f);
glVertex2f(18.86f,-0.28f);
glVertex2f(18.87f,-0.38f);
glVertex2f(18.87f,-0.28f);
glVertex2f(18.88f,-0.38f);
glVertex2f(18.88f,-0.28f);
glVertex2f(18.89f,-0.38f);
glVertex2f(18.89f,-0.28f);
glVertex2f(18.90f,-0.38f);
glVertex2f(18.90f,-0.28f);
glVertex2f(18.91f,-0.38f);
glVertex2f(18.91f,-0.28f);
glVertex2f(18.92f,-0.38f);
glVertex2f(18.92f,-0.28f);
glVertex2f(18.93f,-0.38f);
glVertex2f(18.93f,-0.28f);
glVertex2f(18.94f,-0.38f);
glVertex2f(18.94f,-0.28f);
glVertex2f(18.84f,-0.38f);
glVertex2f(18.94f,-0.38f);
glEnd();
/////////////////////////////////
///hole-3
glBegin(GL_POLYGON);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(19.68f,-0.36f);
glVertex2f(19.78f,-0.34f);
glVertex2f(19.86f,-0.36f);
glVertex2f(19.82f,-0.38f);
glVertex2f(19.72f,-0.38f);
glEnd();
/////////////////////////////////
///Triangle-2
glBegin(GL_POLYGON);
glColor3ub(128,0,128);
glVertex2f(20.57f,-0.38f);
glVertex2f(20.67f,-0.38f);
glVertex2f(20.62f,-0.28f);
glEnd();
/////////////////////////////////
///Upordik kichu ekta-3
glBegin(GL_POLYGON);
glColor3ub(0,0,128);
glVertex2f(21.32f,-0.30f);
glVertex2f(21.32f,-0.38f);
glVertex2f(21.36f,-0.38f);
glVertex2f(21.36f,-0.30f);
glVertex2f(21.38f,-0.30f);
glVertex2f(21.34f,-0.26f);
glVertex2f(21.30f,-0.30f);
glEnd();
/////////////////////////////////
///Car-6
glBegin(GL_POLYGON);
glColor3ub(205,92,92);
glVertex2f(22.10f,-0.32f);
glVertex2f(22.06f,-0.32f);
glVertex2f(22.06f,-0.36f);
glVertex2f(22.32f,-0.36f);
glVertex2f(22.32f,-0.32f);
glVertex2f(22.28f,-0.32f);
glVertex2f(22.28f,-0.26f);
glVertex2f(22.10f,-0.26f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(48,125,126);
glVertex2f(22.12f,-0.28f);
glVertex2f(22.18f,-0.28f);
glVertex2f(22.18f,-0.32f);
glVertex2f(22.12f,-0.32f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(48,125,126);
glVertex2f(22.20f,-0.28f);
glVertex2f(22.26f,-0.28f);
glVertex2f(22.26f,-0.32f);
glVertex2f(22.20f,-0.32f);
glEnd();
glColor3b(255,239,0);
circle(22.12,-0.36,0.02);
circle(22.26,-0.36,0.02);
/////////////////////////////////
///Ball-2
glColor3b(0,0,0);
circle(22.90,-0.32,0.06);
glColor3ub(255,140,0);
circle(22.90,-0.32,0.05);
glColor3ub(128,128,0);
circle(22.90,-0.32,0.04);
/////////////////////////////////
///Water-3
glBegin(GL_POLYGON);
glColor3ub(86,193,255);
glVertex2f(23.58f,-0.36f);
glVertex2f(23.64f,-0.34f);
glVertex2f(23.68f,-0.34f);
glVertex2f(23.72f,-0.36f);
glVertex2f(23.68f,-0.38f);
glVertex2f(23.64f,-0.38f);
glEnd();
/////////////////////////////////
///Lomba kichu ekta-4
glBegin(GL_POLYGON);
glColor3ub(255,69,0);
glVertex2f(24.69f,-0.36f);
glVertex2f(24.67f,-0.36f);
glVertex2f(24.67f,-0.38f);
glVertex2f(24.75f,-0.38f);
glVertex2f(24.75f,-0.36f);
glVertex2f(24.73f,-0.36f);
glVertex2f(24.73f,-0.28f);
glVertex2f(24.69f,-0.28f);
glEnd();
/////////////////////////////////
///Box-3
glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(25.48f,-0.28f);
glVertex2f(25.58f,-0.28f);
glVertex2f(25.58f,-0.38f);
glVertex2f(25.48f,-0.38f);
glEnd();
glBegin(GL_LINES);
glColor3ub(255,255,255);
glVertex2f(25.48f,-0.28f);
glVertex2f(25.58f,-0.28f);
glVertex2f(25.58f,-0.28f);
glVertex2f(25.58f,-0.38f);
glVertex2f(25.58f,-0.38f);
glVertex2f(25.48f,-0.38f);
glVertex2f(25.48f,-0.38f);
glVertex2f(25.48f,-0.28f);
glVertex2f(25.48f,-0.31f);
glVertex2f(25.58f,-0.31f);
glVertex2f(25.48f,-0.34f);
glVertex2f(25.58f,-0.34f);
glEnd();
/////////////////////////////////
///Dustbin-4
glBegin(GL_POLYGON);
glColor3ub(242,197,14);
glVertex2f(26.38f,-0.30f);
glVertex2f(26.36f,-0.28f);
glVertex2f(26.32f,-0.28f);
glVertex2f(26.30f,-0.30f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(255,127,80);
glVertex2f(26.38f,-0.30f);
glVertex2f(26.38f,-0.32f);
glVertex2f(26.30f,-0.32f);
glVertex2f(26.30f,-0.30f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(242,197,14);
glVertex2f(26.37f,-0.32f);
glVertex2f(26.36f,-0.38f);
glVertex2f(26.32f,-0.38f);
glVertex2f(26.31f,-0.32f);
glEnd();
/////////////////////////////////

/////////////////////////////////

/////////////////////////////////

/////////////////////////////////
glPopMatrix();
///////////////////////////////////
glColor3f(0.0f,0.0f,0.0f);
scoreBoard();
glutSwapBuffers();/// Render now
}

void key(unsigned char key,int x, int y)///Game start and quit control
{
  switch ( key )
  {
    case 27:///'ESC' button
      glutDestroyWindow ( glutGetWindow() );
      exit (0);
      break;
    case 's':
    case 'S':
        glutDisplayFunc(display);
        glutTimerFunc(60, update03, 0);
        break;
    case 'F':
    case 'f':
        glutFullScreen();
        break;

  }
glutPostRedisplay();
}

void welcomeDisplay()///welcome game menu
{
glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
///BackGround
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(1.0f,-1.0f);
glVertex2f(1.0f,1.0f);
glVertex2f(-1.0f,1.0f);
glVertex2f(-1.0f,-1.0f);
glEnd();
/////////////////////////////
///Sky
glBegin(GL_POLYGON);
glColor3ub(223,226,233);
glVertex2f(-1.0f,1.0f);
//glColor3f(0.419608f,0.137255f,0.556863f);
glVertex2f(-1.0f,-0.42f);
//glColor3f(0.419608f,0.137255f,0.556863f);
glVertex2f(1.0f,-0.42f);
//glColor3f(0.25f,0.55f,1.0f);
glVertex2f(1.0f,1.0f);
glEnd();
//////////////////////////////
///Cloud
            ///Start
/////////////////////////////////////
glLoadIdentity();
glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(position,0.0f,0.0f);
////////////////////////////////////////////
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.6f,0.54f);
glVertex2f(-0.64f,0.54f);
glVertex2f(-0.62f,0.56f);
glVertex2f(-0.6f,0.56f);
glVertex2f(-0.56f,0.52f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.66f,0.56f);
glVertex2f(-0.68f,0.54f);
glVertex2f(-0.72f,0.56f);
glVertex2f(-0.74f,0.58f);
glVertex2f(-0.70f,0.6f);
glVertex2f(-0.66f,0.58f);
glVertex2f(-0.62f,0.56f);
glVertex2f(-0.64f,0.54f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.76f,0.56f);
glVertex2f(-0.8f,0.54f);
glVertex2f(-0.8f,0.56f);
glVertex2f(-0.74f,0.58f);
glVertex2f(-0.72f,0.56f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.84f,0.56f);
glVertex2f(-0.88f,0.54f);
glVertex2f(-0.92f,0.56f);
glVertex2f(-0.88f,0.56f);
glVertex2f(-0.86f,0.58f);
glVertex2f(-0.8f,0.56f);
glVertex2f(-0.8f,0.54f);
glEnd();
////////////////////////////////////////////
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(1.4f,0.54f);
glVertex2f(1.36f,0.54f);
glVertex2f(1.38f,0.56f);
glVertex2f(1.4f,0.56f);
glVertex2f(1.44f,0.52f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(1.34f,0.56f);
glVertex2f(1.32f,0.54f);
glVertex2f(1.28f,0.56f);
glVertex2f(1.26f,0.58f);
glVertex2f(1.3f,0.6f);
glVertex2f(1.34f,0.58f);
glVertex2f(1.38f,0.56f);
glVertex2f(1.36f,0.54f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(1.24f,0.56f);
glVertex2f(1.2f,0.54f);
glVertex2f(1.2f,0.56f);
glVertex2f(1.26f,0.58f);
glVertex2f(1.28f,0.56f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(1.16f,0.56f);
glVertex2f(1.12f,0.54f);
glVertex2f(1.08f,0.56f);
glVertex2f(1.12f,0.56f);
glVertex2f(1.14f,0.58f);
glVertex2f(1.2f,0.56f);
glVertex2f(1.2f,0.54f);
glEnd();
/////////////////////////////////////////
/////////////////////////////////////////
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(2.12f,0.86f);
glVertex2f(2.1f,0.82f);
glVertex2f(2.08f,0.8f);
glVertex2f(2.04f,0.8f);
glVertex2f(2.04f,0.82f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(1.96f,0.82f);
glVertex2f(1.92f,0.82f);
glVertex2f(1.92f,0.86f);
glVertex2f(1.98f,0.84f);
glVertex2f(2.04f,0.82f);
glVertex2f(2.04f,0.8f);
glVertex2f(2.0f,0.78f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(1.88f,0.84f);
glVertex2f(1.8f,0.84f);
glVertex2f(1.88f,0.8f);
glVertex2f(1.96f,0.82f);
glVertex2f(1.92f,0.86f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(1.82f,0.84f);
glVertex2f(1.78f,0.84f);
glVertex2f(1.76f,0.88f);
glVertex2f(1.78f,0.86f);
glVertex2f(1.8f,0.86f);
glEnd();
////////////////////////////////////////////
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(0.12f,0.86f);
glVertex2f(0.1f,0.82f);
glVertex2f(0.08f,0.8f);
glVertex2f(0.04f,0.8f);
glVertex2f(0.04f,0.82f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.04f,0.82f);
glVertex2f(-0.08f,0.82f);
glVertex2f(-0.08f,0.86f);
glVertex2f(-0.02f,0.84f);
glVertex2f(0.04f,0.82f);
glVertex2f(0.04f,0.8f);
glVertex2f(0.0f,0.78f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.12f,0.84f);
glVertex2f(-0.2f,0.84f);
glVertex2f(-0.12f,0.8f);
glVertex2f(-0.08f,0.82f);
glVertex2f(-0.08f,0.86f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.18f,0.84f);
glVertex2f(-0.22f,0.84f);
glVertex2f(-0.24f,0.88f);
glVertex2f(-0.22f,0.86f);
glVertex2f(-0.2f,0.86f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(0.12f,0.86f);
glVertex2f(0.1f,0.82f);
glVertex2f(0.08f,0.8f);
glVertex2f(0.04f,0.8f);
glVertex2f(0.04f,0.82f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.04f,0.82f);
glVertex2f(-0.08f,0.82f);
glVertex2f(-0.08f,0.86f);
glVertex2f(-0.02f,0.84f);
glVertex2f(0.04f,0.82f);
glVertex2f(0.04f,0.8f);
glVertex2f(0.0f,0.78f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.12f,0.84f);
glVertex2f(-0.2f,0.84f);
glVertex2f(-0.12f,0.8f);
glVertex2f(-0.04f,0.82f);
glVertex2f(-0.08f,0.86f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-0.18f,0.84f);
glVertex2f(-0.22f,0.84f);
glVertex2f(-0.24f,0.88f);
glVertex2f(-0.22f,0.86f);
glVertex2f(-0.2f,0.86f);
glEnd();
////////////////////////////////////////////
///cloud
////////////////////////////////////////
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(0.58f,0.58f);
glVertex2f(0.56f,0.56f);
glVertex2f(0.54f,0.58f);
glVertex2f(0.54f,0.6f);
glVertex2f(0.58f,0.6f);
glVertex2f(0.64f,0.58f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(0.5f,0.6f);
glVertex2f(0.46f,0.58f);
glVertex2f(0.46f,0.6f);
glVertex2f(0.5f,0.62f);
glVertex2f(0.54f,0.6f);
glVertex2f(0.54f,0.58f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(0.4f,0.57f);
glVertex2f(0.34f,0.58f);
glVertex2f(0.32f,0.6f);
glVertex2f(0.4f,0.62f);
glVertex2f(0.46f,0.6f);
glVertex2f(0.46f,0.58f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(0.3f,0.58f);
glVertex2f(0.28f,0.58f);
glVertex2f(0.32f,0.56f);
glVertex2f(0.34f,0.58f);
glVertex2f(0.32f,0.6f);
glEnd();
////////////////////////////////////
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(2.58f,0.58f);
glVertex2f(2.56f,0.56f);
glVertex2f(2.54f,0.58f);
glVertex2f(2.54f,0.6f);
glVertex2f(2.58f,0.6f);
glVertex2f(2.64f,0.58f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(2.5f,0.6f);
glVertex2f(2.46f,0.58f);
glVertex2f(2.46f,0.6f);
glVertex2f(2.5f,0.62f);
glVertex2f(2.54f,0.6f);
glVertex2f(2.54f,0.58f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(2.4f,0.57f);
glVertex2f(2.34f,0.58f);
glVertex2f(2.32f,0.6f);
glVertex2f(2.4f,0.62f);
glVertex2f(2.46f,0.6f);
glVertex2f(2.46f,0.58f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(2.3f,0.58f);
glVertex2f(2.28f,0.58f);
glVertex2f(2.32f,0.56f);
glVertex2f(2.34f,0.58f);
glVertex2f(2.32f,0.6f);
glEnd();
glPopMatrix();
        ///End----
///////////////////////////////////
///Road
glBegin(GL_POLYGON);
glColor3ub(106,110,119);
glVertex2f(-1.0f,-0.42f);
glVertex2f(-1.0f,-0.5f);
glVertex2f(3.0f,-0.5f);
glVertex2f(3.0f,-0.42f);
glEnd();

///Line02
glBegin(GL_POLYGON);
glColor3ub(138,143,153);
glVertex2f(-1.0f,-0.5f);
glVertex2f(-1.0f,-0.54f);
glVertex2f(3.0f,-0.54f);
glVertex2f(3.0f,-0.5f);
glEnd();

///Line03
glBegin(GL_POLYGON);
glColor3ub(138,143,153);
glVertex2f(-1.0f,-0.54f);
glVertex2f(-1.0f,-0.6f);
glVertex2f(3.0f,-0.6f);
glVertex2f(3.0f,-0.54f);
glEnd();

glLoadIdentity();
glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(position2,0.0f,0.0f);
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(120,120,120);
///Curved Line
glVertex2f(-0.78f,-0.5f);
glVertex2f(-0.76f,-0.54f);

glVertex2f(-0.54f,-0.5f);
glVertex2f(-0.52f,-0.54f);

glVertex2f(-0.3f,-0.5f);
glVertex2f(-0.28f,-0.54f);

glVertex2f(-0.06f,-0.5f);
glVertex2f(-0.04f,-0.54f);

glVertex2f(0.18f,-0.5f);
glVertex2f(0.2f,-0.54f);

glVertex2f(0.42f,-0.5f);
glVertex2f(0.44f,-0.54f);

glVertex2f(0.66f,-0.5f);
glVertex2f(0.68f,-0.54f);

glVertex2f(0.90f,-0.5f);
glVertex2f(0.92f,-0.54f);

glVertex2f(1.14f,-0.5f);
glVertex2f(1.16f,-0.54f);

glVertex2f(1.38f,-0.5f);
glVertex2f(1.4f,-0.54f);

glVertex2f(1.62f,-0.5f);
glVertex2f(1.64f,-0.54f);

glVertex2f(1.86f,-0.5f);
glVertex2f(1.88f,-0.54f);

glVertex2f(2.1f,-0.5f);
glVertex2f(2.12f,-0.54f);

glVertex2f(2.34f,-0.5f);
glVertex2f(2.36f,-0.54f);

glVertex2f(2.58f,-0.5f);
glVertex2f(2.6f,-0.54f);

glVertex2f(2.82f,-0.5f);
glVertex2f(2.84f,-0.54f);

glVertex2f(3.06f,-0.5f);
glVertex2f(3.08f,-0.54f);

///Straight Line
glVertex2f(-0.76f,-0.54f);
glVertex2f(-0.76f,-0.6f);

glVertex2f(-0.52f,-0.54f);
glVertex2f(-0.52f,-0.6f);

glVertex2f(-0.28f,-0.54f);
glVertex2f(-0.28f,-0.6f);

glVertex2f(-0.04f,-0.54f);
glVertex2f(-0.04f,-0.6f);

glVertex2f(0.2f,-0.54f);
glVertex2f(0.2f,-0.6f);

glVertex2f(0.44f,-0.54f);
glVertex2f(0.44f,-0.6f);

glVertex2f(0.68f,-0.54f);
glVertex2f(0.68f,-0.6f);

glVertex2f(0.92f,-0.54f);
glVertex2f(0.92f,-0.6f);

glVertex2f(1.16f,-0.54f);
glVertex2f(1.16f,-0.6f);

glVertex2f(1.4f,-0.54f);
glVertex2f(1.4f,-0.6f);

glVertex2f(1.64f,-0.54f);
glVertex2f(1.64f,-0.6f);

glVertex2f(1.88f,-0.54f);
glVertex2f(1.88f,-0.6f);

glVertex2f(2.12f,-0.54f);
glVertex2f(2.12f,-0.6f);

glVertex2f(2.36f,-0.54f);
glVertex2f(2.36f,-0.6f);

glVertex2f(2.60f,-0.54f);
glVertex2f(2.60f,-0.6f);

glVertex2f(2.84f,-0.54f);
glVertex2f(2.84f,-0.6f);

glVertex2f(3.08f,-0.54f);
glVertex2f(3.08f,-0.6f);
////////////////////////////////
///Division mid line
glVertex2f(-1.0f,-0.54f);
glVertex2f(3.0f,-0.54f);
///////////////////////////
glColor3f(1.0f,1.0f,1.0f);
///Road Lane
glVertex2f(-0.90f,-0.46f);
glVertex2f(-0.8f,-0.46f);

glVertex2f(-0.7f,-0.46f);
glVertex2f(-0.6f,-0.46f);

glVertex2f(-0.5f,-0.46f);
glVertex2f(-0.4f,-0.46f);

glVertex2f(-0.3f,-0.46f);
glVertex2f(-0.2f,-0.46f);

glVertex2f(-0.1f,-0.46f);
glVertex2f(0.0f,-0.46f);

glVertex2f(0.1f,-0.46f);
glVertex2f(0.2f,-0.46f);

glVertex2f(0.3f,-0.46f);
glVertex2f(0.4f,-0.46f);

glVertex2f(0.5f,-0.46f);
glVertex2f(0.6f,-0.46f);

glVertex2f(0.7f,-0.46f);
glVertex2f(0.8f,-0.46f);

glVertex2f(0.9f,-0.46f);
glVertex2f(1.0f,-0.46f);

glVertex2f(1.1f,-0.46f);
glVertex2f(1.2f,-0.46f);

glVertex2f(1.3f,-0.46f);
glVertex2f(1.4f,-0.46f);

glVertex2f(1.5f,-0.46f);
glVertex2f(1.6f,-0.46f);

glVertex2f(1.7f,-0.46f);
glVertex2f(1.8f,-0.46f);

glVertex2f(1.9f,-0.46f);
glVertex2f(2.0f,-0.46f);

glVertex2f(2.1f,-0.46f);
glVertex2f(2.2f,-0.46f);

glVertex2f(2.3f,-0.46f);
glVertex2f(2.4f,-0.46f);

glVertex2f(2.5f,-0.46f);
glVertex2f(2.6f,-0.46f);

glVertex2f(2.7f,-0.46f);
glVertex2f(2.8f,-0.46f);

glVertex2f(2.9f,-0.46f);
glVertex2f(3.0f,-0.46f);

glEnd();
glPopMatrix();
/////////////////////////////
///GROUND
glBegin(GL_POLYGON);
glColor3ub(39,45,59);
glVertex2f(-1.0f,-0.6f);
glVertex2f(-1.0f,-1.0f);
glVertex2f(1.0f,-1.0f);
glVertex2f(1.0f,-0.6f);
glEnd();
/////////////////////////////////
///UnderGround
glLoadIdentity();
glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(position2,0.0f,0.0f);
////////////////////////////
glColor3ub(57,55,79);
circle(-0.86,-0.65,0.04);
circle(1.14,-0.65,0.04);
///////////////////////////////////
circle(-0.68,-0.72,0.02);
circle(1.32,-0.72,0.02);
///////////////////////////////////
circle(-0.3,-0.66,0.04);
circle(1.7,-0.66,0.04);
///////////////////////////////////
circle(-0.22,-0.76,0.02);
circle(1.18,-0.76,0.02);
///////////////////////////////////
circle(-0.5,-0.92,0.03);
circle(1.5,-0.92,0.03);
///////////////////////////////////
circle(0.32,-0.68,0.02);
circle(2.32,-0.68,0.02);
///////////////////////////////////
circle(0.38,-0.76,0.045);
circle(2.38,-0.76,0.045);
///////////////////////////////////
circle(0.76,-0.66,0.02);
circle(2.76,-0.66,0.02);
///////////////////////////////////
circle(0.94,-0.7,0.04);
circle(2.94,-0.7,0.04);
///////////////////////////////////
circle(0.6,-0.92,0.03);
circle(2.6,-0.92,0.03);
///////////////////////////////////
circle(0.06,-0.92,0.04);
circle(2.06,-0.92,0.04);
///////////////////////////////////
glPopMatrix();
///////////////////////////////////
///Obejct_Character
glColor3f(0.0f,0.0f,0.0f);
circle(-0.00,-0.44,0.03);
glColor3ub(175,175,175);
circle(-0.00,-0.44,0.022);
glColor3f(0.0f,0.0f,0.0f);
circle(-0.10,-0.44,0.03);
glColor3ub(175,175,175);
circle(-0.10,-0.44,0.022);
glColor3ub(86,193,255);
circle(-0.025,-0.36,0.01);
glColor3ub(255,123,111);
circle(-0.07,-0.32,0.015);
glBegin(GL_POLYGON);
glColor3ub(86,193,255);
glVertex2f(-0.09f,-0.42f);
glVertex2f(-0.12f,-0.42f);
glVertex2f(-0.10f,-0.38f);
glVertex2f(-0.09f,-0.38f);
glVertex2f(-0.05f,-0.41f);
glVertex2f(-0.05f,-0.44f);
glVertex2f(-0.08f,-0.44f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(86,193,255);
glVertex2f(-0.02f,-0.42f);
glVertex2f(-0.04f,-0.42f);
glVertex2f(-0.04f,-0.44f);
glVertex2f(-0.00f,-0.44f);
glVertex2f(-0.02f,-0.37f);
glVertex2f(-0.03f,-0.37f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(250,0,140);
glVertex2f(-0.07f,-0.33f);
glVertex2f(-0.07f,-0.38f);
glVertex2f(-0.09f,-0.38f);
glVertex2f(-0.09f,-0.34f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(250,0,140);
glVertex2f(-0.05f,-0.355f);
glVertex2f(-0.07f,-0.33f);
glVertex2f(-0.07f,-0.35f);
glVertex2f(-0.05f,-0.37f);
glVertex2f(-0.03f,-0.365f);
glVertex2f(-0.03f,-0.355f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(175,175,175);
glVertex2f(-0.05f,-0.41f);
glVertex2f(-0.05f,-0.44f);
glVertex2f(-0.04f,-0.44f);
glVertex2f(-0.04f,-0.41f);
glVertex2f(-0.07f,-0.38f);
glVertex2f(-0.09f,-0.38f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(-0.06f,-0.3f);
glVertex2f(-0.09f,-0.3f);
glVertex2f(-0.09f,-0.33f);
glEnd();
////////////////////////////////////
///TItle
glBegin(GL_POLYGON);
glColor3ub(39,45,59);
glVertex2f(-0.28f,0.8f);
glVertex2f(-0.3f,0.65f);
glVertex2f(0.28f,0.65f);
glVertex2f(0.3f,0.8f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(223,226,233);
glVertex2f(-0.265f,0.78f);
glVertex2f(-0.28f,0.67f);
glVertex2f(0.265f,0.67f);
glVertex2f(0.28f,0.78f);
glEnd();
///////////////////////////////
///Key Instruction
glColor3ub(255,255,255);
renderBitmapString(-0.2f, -0.7f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Press 's' to Play");
renderBitmapString(-0.2f, -0.75f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Press 'ESC' to Exit");
renderBitmapString(-0.3f, -0.8f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Press 'Up Butoon' to Jump");
glColor3ub(39,45,59);
renderBitmapString(-0.2f, 0.9f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Press 'F' to Full Screen");

renderBitmapString(-0.12f, 0.712f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Delivery Rush");
circle(-0.15f,0.726f,0.02);
circle(0.17f,0.726f,0.02);
renderBitmapString(-0.05f, 0.4f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Play");
renderBitmapString(-0.1f, 0.35f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Highscore");
renderBitmapString(-0.08f, 0.3f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Settings");
renderBitmapString(-0.065f, 0.25f, 0.0f, GLUT_BITMAP_HELVETICA_18, "About");
renderBitmapString(-0.055f, 0.2f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Quit");
glutSwapBuffers();///render
}

void AutoShiftControl(int val)///intro page to game menu
{
    glutDisplayFunc(welcomeDisplay);
    glutPostRedisplay();
}

void introPage()///Introduction page
{
glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
///BackGround
glBegin(GL_POLYGON);
glColor3ub(179,186,202);
glVertex2f(1.0f,-1.0f);
glColor3ub(179,186,202);
glVertex2f(1.0f,1.0f);
glColor3ub(218,222,231);
glVertex2f(-1.0f,1.0f);
glColor3ub(230,230,250);
glVertex2f(-1.0f,-1.0f);
glEnd();
///////////////////////////////////
///Info Details
glColor3ub(39,45,59);
renderBitmapString(-0.2f, 0.9f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "W-E-L-C-O-M-E");
renderBitmapString(-0.28f, 0.85f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24,"-*-*-*-*-*-*-*-*-*-*-*-");
renderBitmapString(-0.3f, 0.7f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Course : Computer Graphics [A]");
renderBitmapString(-0.34f, 0.6f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Course Teacher : Mahfujur Rahman");
renderBitmapString(-0.28f, 0.5f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Project Title : Delivery Rush");
renderBitmapString(-0.18f, 0.45f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Team Members");
renderBitmapString(-0.59f, 0.4f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "*****************************************************");
renderBitmapString(-0.4f, 0.35f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "1. Md Shafwan Ahmed Dehan (19-39302-1)");
renderBitmapString(-0.4f, 0.25f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "2. Sadia Islam Zerin (20-43741-2)");
renderBitmapString(-0.4f, 0.15f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "3. Md Saeedullah Azim (19-41351-3)");
renderBitmapString(-0.4f, 0.05f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "4. Sudarshan Saha Bishal (20-42915-1)");
renderBitmapString(-0.4f, -0.05f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "5. Tauhid Abiad (18-39115-3)");
renderBitmapString(-0.3f, -0.7f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Game Will Start Soon......");

glutSwapBuffers();//Render
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) ///Main function
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(1080, 1920);
glutInitWindowPosition(50, 50); // Set the window's initial width & height
glutCreateWindow("Computer Graphic Project"); // Create a window with the given title
glutDisplayFunc(introPage);
glutTimerFunc(5000,AutoShiftControl,0);
glutKeyboardFunc(key);
glutSpecialFunc(keyboard);
glutTimerFunc(50, update, 0);
glutTimerFunc(60, update02, 0);
glutTimerFunc(50, update01, 0);
PlaySound("D:\\Picture\\Computer Graphic\\ComputerGraphicProject\\Sound\\2.wav",NULL,SND_ASYNC | SND_LOOP);///For sound
glutMainLoop(); // Enter the event-processing loop
return 0;
}

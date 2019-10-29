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

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include "RGBpixmap.cpp"

using namespace std;
RGBpixmap pix[10];

static int slices = 16;
static int stacks = 16;
static int xx = 0;
static int yy = 0;
static float zzz = -15;
static float zz = -15;
static float z = -15;
static float t1z = 0;
static float t2z = -5;
static float t3z = 5;
int abc;
int coun =0;

vector<float>cv;
vector<float>b1v;
vector<float>bv;


/* GLUT callback Handlers */

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}


void grass()
{
   glColor3f(1.0,1.0,1.0);

    glBegin(GL_POLYGON);
        glVertex3f(5, 0, 15);
        glVertex3f(25, 0, 15);
        glVertex3f(25, 0, -15);
        glVertex3f(5, 0, -15);

    glEnd();


    //glColor3f(0.0,0.9,0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex3f(-25, 0, 15);
        glVertex3f(-5, 0, 15);
        glVertex3f(-5, 0, -15);
        glVertex3f(-25, 0, -15);
    glEnd();

}


void road()
{
    glColor3f(.2,.2,.2);

    glBegin(GL_POLYGON);
        glVertex3f(-5, 0, 15);
        glVertex3f(5, 0, 15);
        glVertex3f(5, 0, -15);
        glVertex3f(-5, -0, -15);

    glEnd();
}

void divider()
{
    //divider
    glColor3d(1,1,1);

    glBegin(GL_POLYGON);
        glVertex3f(-.2, .1, 5);
        glVertex3f(-.2, .1, 10);
        glVertex3f(.2, .1, 10);
        glVertex3f(.2, .1, 5);

    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-.2, .1, -5);
        glVertex3f(-.2, .1, 0);
        glVertex3f(.2, .1, 0);
        glVertex3f(.2, .1, -5);

    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-.2, .1, -15);
        glVertex3f(-.2, .1, -10);
        glVertex3f(.2, .1, -10);
        glVertex3f(.2, .1, -15);

    glEnd();
}


void tree()
{
    //tree1
    glColor3d(1,0,0);
    glBegin(GL_POLYGON);
        glVertex3f(-8,0,t1z);
        glVertex3f(-7.3,0,t1z);
        glVertex3f(-6.5,3,t1z);
        glVertex3f(-7.5,3,t1z);
    glEnd();

    glColor3d(1,1,0);
    glBegin(GL_TRIANGLES);
        glVertex3f(-8.5,2.7,t1z);
        glVertex3f(-5.5,2.7,t1z);
        glVertex3f(-6,5,t1z);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex3f(-8,3.7,t1z);
        glVertex3f(-5,3.7,t1z);
        glVertex3f(-6,5,t1z);
    glEnd();

    t1z += .02;
    if(t1z>14)
        t1z = 0;

    //tree2

    glColor3d(1,0,0);
    glBegin(GL_POLYGON);
        glVertex3f(-8,0,t2z);
        glVertex3f(-7.3,0,t2z);
        glVertex3f(-6.5,2.7,t2z);
        glVertex3f(-7.5,2.7,t2z);
    glEnd();

    glColor3d(1,1,0);
    glBegin(GL_TRIANGLES);
        glVertex3f(-8.5,2.7,t2z);
        glVertex3f(-5.5,2.7,t2z);
        glVertex3f(-6,5,t2z);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex3f(-8,3.7,t2z);
        glVertex3f(-5,3.7,t2z);
        glVertex3f(-6,5,t2z);
    glEnd();

    t2z += .02;
    if(t2z>14)
        t2z = -5;

    //tree3

    glColor3d(1,0,0);
    glBegin(GL_POLYGON);
        glVertex3f(-8,0,t3z);
        glVertex3f(-7.3,0,t3z);
        glVertex3f(-6.5,2.7,t3z);
        glVertex3f(-7.5,2.7,t3z);
    glEnd();

    glColor3d(1,1,0);
    glBegin(GL_TRIANGLES);
        glVertex3f(-8.5,2.7,t3z);
        glVertex3f(-5.5,2.7,t3z);
        glVertex3f(-6,5,t3z);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex3f(-8,3.7,t3z);
        glVertex3f(-5,3.7,t3z);
        glVertex3f(-6,5,t3z);
    glEnd();

    t3z += .02;
    if(t3z>14)
        t3z = 5;
}










void car()
{
    glColor3d(1,0,0);
    glBegin(GL_POLYGON);
        glVertex3f(-1,1,0);
        glVertex3f(1,1,0);
        glVertex3f(.7,1,-1.2);
        glVertex3f(-.7,1,-1.2);
    glEnd();

    glColor3d(0,0,1);
    glBegin(GL_POLYGON);
        glVertex3f(-1,1,0);
        glVertex3f(-1,1,2);
        glVertex3f(1,1,2);
        glVertex3f(1,1,0);
    glEnd();

    glColor3d(1,0,0);
    glBegin(GL_POLYGON);
        glVertex3f(-1,1,2);
        glVertex3f(-1,1,2.3);
        glVertex3f(1,1,2.3);
        glVertex3f(1,1,2);
    glEnd();


    coun++;
}

int box()
{

        glColor3d(1,1,0);

        glBegin(GL_POLYGON);

            glVertex3f(-3.2,2,z);
            glVertex3f(-3.2,2,z+3);
            glVertex3f(-1.2,2,z+3);
            glVertex3f(-1.2,2,z);

        glEnd();


        glBegin(GL_POLYGON);

            glVertex3f(-3.2,1,z);
            glVertex3f(-3.2,1,z+3);
            glVertex3f(-1.2,1,z+3);
            glVertex3f(-1.2,1,z);

        glEnd();

        glColor3d(1,1,1);

        glBegin(GL_POLYGON);

            glVertex3f(-3.2,2,z+3);
            glVertex3f(-3.2,1,z+3);
            glVertex3f(-1.2,1,z+3);
            glVertex3f(-1.2,2,z+3);


        glEnd();
        z+= .025;

        //cout<<z<<endl;


        if (z>15)
            z=-15;
        bv.push_back(z+3);

}


int box2()
{

        glColor3d(1,1,0);

        glBegin(GL_POLYGON);

            glVertex3f(-1,2,zzz);
            glVertex3f(-1,2,zzz+3);
            glVertex3f(1,2,zzz+3);
            glVertex3f(1,2,zzz);

        glEnd();


        glBegin(GL_POLYGON);

            glVertex3f(-1,1,zzz);
            glVertex3f(-1,1,zzz+3);
            glVertex3f(1,1,zzz+3);
            glVertex3f(1,1,zzz);

        glEnd();

        glColor3d(1,1,1);

        glBegin(GL_POLYGON);

            glVertex3f(-1,2,zzz+3);
            glVertex3f(-1,1,zzz+3);
            glVertex3f(1,1,zzz+3);
            glVertex3f(1,2,zzz+3);


        glEnd();
        zzz+= .009;

        //cout<<z<<endl;


        if (zzz>15)
            zzz=-15;
        bv.push_back(zzz+3);

}



void box1()
{

        glColor3d(1,1,0);

        glBegin(GL_POLYGON);

            glVertex3f(1.2,2,zz);
            glVertex3f(1.2,2,zz+3);
            glVertex3f(3.2,2,zz+3);
            glVertex3f(3.2,2,zz);

        glEnd();


        glBegin(GL_POLYGON);

            glVertex3f(1.2,1,zz);
            glVertex3f(1.2,1,zz+3);
            glVertex3f(3.2,1,zz+3);
            glVertex3f(3.2,1,zz);

        glEnd();

        glColor3d(1,1,1);

        glBegin(GL_POLYGON);

            glVertex3f(1.2,2,zz+3);
            glVertex3f(1.2,1,zz+3);
            glVertex3f(3.2,1,zz+3);
            glVertex3f(3.2,2,zz+3);


        glEnd();
        zz+= .02;

        if (zz>15)
            zz=-15;

        b1v.push_back(zz+3);

}

void collition()
{
    if ((z < 1 && z > -.5) && xx >= 1)
    {
        cout<<endl<<endl<<"            GAME FINISHED"<<endl<<endl;
        cout<<"            YOUR POINT :"<<coun<<endl<<endl<<endl<<endl;
        exit(0);
    }


    if ((zz < 1 && zz > -.5) && xx <= -1)
        {
            cout<<endl<<endl<<"            GAME FINISHED"<<endl<<endl;
            exit(0);
        }
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glPushMatrix();
    collition();
        glTranslated(0,0,-16);
        glRotated(60,1,0,0);
        glRotated(0,0,0,1);
        glBindTexture(GL_TEXTURE_2D,3);
        glEnable(GL_TEXTURE_2D);
        grass();
        glDisable(GL_TEXTURE_2D);
        road();
        divider();
        tree();

        box();
        box1();
        //box2();

    glPopMatrix();

    glPushMatrix();

    if(xx<-5 || xx>5)
            exit(0);

    glTranslated(-1*xx,yy,-16);
    cv.push_back(xx);

//    cout<<yy;
//    cout<<endl;

    glRotated(60,1,0,0);
    glRotated(0,0,0,1);
    car();
    glPopMatrix();


    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :

        case 'q':
            exit(0);
            break;

//        case ' ':
//            z++;
//            break;

        case 'a':
            xx++;
            break;

        case 'd':
            xx--;
            break;

        case 'w':
            yy++;
            break;

        case 's':
            yy--;
            break;





    }


    glutPostRedisplay();
}

static void idle(void)
{

    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */
void Init()
{
	glEnable(GL_TEXTURE_2D);

    pix[0].makeCheckImage();
	pix[0].setTexture(1);

//	pix[1].readBMPFile("C:\\Users\\Tusher\\Desktop\\project_cg\\teapot.bmp");
//	pix[1].setTexture(2);

	pix[2].readBMPFile("C:\\Users\\Tusher\\Desktop\\project_cg\\table.bmp");
	pix[2].setTexture(3);

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
   // glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    Init();

    glutMainLoop();

    return EXIT_SUCCESS;
}

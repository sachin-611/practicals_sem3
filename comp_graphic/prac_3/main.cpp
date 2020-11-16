#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.5,0.5,0.9,0.6);
    glLoadIdentity();

    glBegin(GL_POLYGON);
    glColor3f(0,1,0);
        glVertex2f(5,-2);
        glVertex2f(2,-7);
        glVertex2f(8,-7);
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glColor3f(1,0.5,0);
        glVertex2f(-2,2);
        glVertex2f(-2,7);
        glVertex2f(-8,7);
        glVertex2f(-8,2);
    glEnd();
    glFlush();


    glBegin(GL_POLYGON);
    glColor3f(0.5,1,0.5);
        glVertex2f(-2,-2);
        glVertex2f(-2,-7);
        glVertex2f(-8,-7);
        glVertex2f(-8,-2);
    glEnd();
    glFlush();





    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
        glVertex2f(6,5);
        glVertex2f(7,3.5);
        glVertex2f(6,2);
        glVertex2f(4,2);
        glVertex2f(3,3.5);
        glVertex2f(4,5);
    glEnd();
    glFlush();

}
void keyboard_event(unsigned char key, int x, int y)
{
    if(key == 13)
        exit(0);
    else if(key == 32)
    {
        cout<<"\n You have changed colour using SPACE BAR \n";
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glutPostRedisplay();
    }

    else
        cout<<"\n You have pressed: \n"<<key;
}

void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-15,15,-15,15);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char**argv)
{
    cout<<"Press ENTER to exit"<<endl;
    cout<<"Press SPACE BAR to change background color"<<endl;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(500,330);
    glutInitWindowSize(800,800);
    glutCreateWindow("Assignment3");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard_event);
    glutMainLoop();
}

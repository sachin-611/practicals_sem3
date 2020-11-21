#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;

float x_2,y_1,y_2,x_1;
void init_GL()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500,500,-500,500);
}

void input()
{
    cout<<"Enter the value of x1: ";
    cin>>x_1;
    cout<<"Enter the value of y1: ";
    cin>>y_1;
    cout<<"Enter the value of x2: ";
    cin>>x_2;
    cout<<"Enter the value of y2: ";
    cin>>y_2;
}

void DDA_Line()
{
    int steps;
    GLfloat dx, dy, incx, incy, x, y;
    dx = x_2 - x_1;
    dy = y_2 - y_1;
    steps = max(abs(dx), abs(dy));
    incx = dx/steps;
    incy = dy/steps;
    x = x_1;
    y = y_1;
    glPointSize(5);
    glBegin(GL_POINT);
        glColor3f(1.0, 0.0, 1.0);
        glVertex2f(x, y);
    glEnd();
    for(int i =0; i<=steps; i++)
    {
        x += incx;
        y += incy;
        glPointSize(5);
        glBegin(GL_POINTS);
            glColor3f(1.0, 0.0, 1.0);
            glVertex2f(x, y);
        glEnd();
    }
    glFlush();
}

void keyboard_event(unsigned char key, int x, int y)
{
    if(key == 13)
        exit(0);
}

int main(int argc, char ** argv)
{
    input();
    glutInit(&argc, argv);
    glutCreateWindow("DDA Line Generation");
    glutInitWindowPosition(160, 160);
    glutInitWindowSize(200, 200);
    init_GL();
    glutDisplayFunc(DDA_Line);
    glutKeyboardFunc(keyboard_event);
    glutMainLoop();
    return 0;
}

#include<iostream>
#include<GL/glut.h>
#include<math.h>

using namespace std;

float ax1,ax2,ay1,ay2;
void InitGL()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500,500,-500,500);
}

void input_data()
{
    cout<<"Enter the value of x1: ";
    cin>>ax1;
    cout<<"Enter the value of y1: ";
    cin>>ay1;
    cout<<"Enter the value of x2: ";
    cin>>ax2;
    cout<<"Enter the value of y2: ";
    cin>>ay2;
}


void display()
{
    glClearColor(1.0, 0.5, 0.7, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    int dx, dy, p, x, y;
    dx = ax2 - ax1;
    dy = ay2 - ay1;
    x = ax1;
    y = ay1;
    p = 2*dy - dx;
    glPointSize(2);
    while(x < ax2)
    {
        if(p >= 0)
        {
            glBegin(GL_POINTS);
                glColor3f(1.0, 1.0, 1.0);
                glVertex2f(x, y);
            glEnd();
            y=y+1;
            p=p+2*dy-2*dx;
        }
        else
        {
            glBegin(GL_POINTS);
                glColor3f(1.0, 1.0, 1.0);
                glVertex2f(x, y);
            glEnd();
            p=p+2*dy;
        }
        x=x+1;
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
    input_data();
    glutInit(&argc, argv);
    glutCreateWindow("Bresenham Line Generation");
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(600, 600);
    InitGL();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard_event);
    glutMainLoop();
    return 0;
}

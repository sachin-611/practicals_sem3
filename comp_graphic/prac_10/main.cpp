#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;

class vertex
{
    int x;
    int y;
public:
    void xy(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    int gety()
    {
        return this->y;
    }
    int getx()
    {
        return this->x;
    }
};
vector<vertex>arr(50);
bool flag = false;
bool colored = false;
int edges = 0;

void initGL()
{
     glClearColor(1.0f, 0.70f, 0.0f, 1.0f);
     glClear(GL_COLOR_BUFFER_BIT);
     glMatrixMode( GL_PROJECTION );
     glLoadIdentity();
     gluOrtho2D( 0, 800, 0, 800);
}

void mouse(int click, int pos, int x, int y)
{
    if(click == GLUT_LEFT_BUTTON && pos == GLUT_DOWN && !flag)
    {

        arr[edges].xy(x, 800 - y);
        edges++;
    }
    if(click == GLUT_RIGHT_BUTTON && pos == GLUT_DOWN && !flag)
    {
        flag = true;
    }
    if(click == GLUT_LEFT_BUTTON && pos == GLUT_DOWN && !colored && flag)
    {
        colored = true;
    }
    glutPostRedisplay();
 }


void display()
{
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2);
    if(!flag)
    {
        glPointSize(10);
        glBegin(GL_POINTS);
            for(int i=0;i<edges;i++)
            glVertex2i(arr[i].getx(), arr[i].gety());
        glEnd();
        glPointSize(5);
        glBegin(GL_LINE_STRIP);
        for(int i=0;i<edges;i++)
            glVertex2i(arr[i].getx(), arr[i].gety());
        glEnd();
    }
    else
    {
        glBegin(GL_LINE_LOOP);
        for(int i=0;i<edges;i++)
            glVertex2i(arr[i].getx(), arr[i].gety());
        glEnd();
    }
    glFlush();
}


int main(int argc, char ** argv) {
     glutInit(&argc, argv);
     glutInitWindowPosition(0, 0);
     glutInitWindowSize(800, 800);
     glutCreateWindow("Polygon using mouse");
     initGL();
     glutMouseFunc(mouse);
     glutDisplayFunc(display);
     glutMainLoop();
     return(0);
 }

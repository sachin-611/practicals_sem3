#include <iostream>
#include <GL/glut.h>
using namespace std;

class vertex
{
public:
    int x, y;
    void init_xy(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
}v[20];
bool complete = false;
int edges = 0;
float boundary_color[] = {1, 0, 0};
float fill_color[] = {0, 1, 0};
void initGL()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}
void boundary_fill(int x, int y)
{
    float color[3];
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, color);
    if((color[0] != boundary_color[0] || color[1] != boundary_color[1] || color[2] != boundary_color[2])&&(
     color[0] != fill_color[0] || color[1] != fill_color[1] || color[2] != fill_color[2]))
     {
        glColor3f(fill_color[0], fill_color[1], fill_color[2]);
        glBegin(GL_POINTS);
            glVertex2i(x,y);
        glEnd();
        glFlush();
        boundary_fill(x+2,y);
        boundary_fill(x-2,y);
        boundary_fill(x,y+2);
        boundary_fill(x,y-2);
    }
    else
        return;
}
void mouse(int button, int state, int x, int y)
{
    y = 480-y;
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !complete)
    {
        v[edges].init_xy(x, y);
        edges++;
        glutPostRedisplay();
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && !complete)
    {
        v[edges].init_xy(v[0].x, v[0].y);
        complete = true;
        glutPostRedisplay();
    }
    if(button==GLUT_LEFT_BUTTON && state == GLUT_DOWN && complete)
    {
        boundary_fill(x,y);
    }
}
void display()
{
    glLineWidth(3);
    glPointSize(2);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(boundary_color[0], boundary_color[1], boundary_color[2]);
    if(!complete)
    {
        glPointSize(2);
        glBegin(GL_LINE_STRIP);
        for(int i=0;i<edges;i++)
            glVertex2i(v[i].x, v[i].y);
        glEnd();
    }
    else
    {
        glPointSize(2);
        glBegin(GL_LINE_LOOP);
        for(int i=0;i<edges;i++)
            glVertex2i(v[i].x, v[i].y);
        glEnd();
    }
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Boundary-Fill Algorithm ");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    initGL();
    glutMainLoop();
    return 0;
}

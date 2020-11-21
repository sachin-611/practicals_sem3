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
GLfloat bg_color[] = {0.0f, 0.0f, 0.0f};
GLfloat fill_color[] = {0.0f, 1.0f, 0.0f};
GLfloat bndry_color[] = {1.0f, 0.0f, 0.0f};
void initGL()
{
    glClearColor(bg_color[0], bg_color[1], bg_color[2], 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,1350,0,690);
}
void flood_fill(int x, int y)
{
    float color[3];
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, color);
    if(color[0] == bg_color[0] && color[1] == bg_color[1] && color[2] == bg_color[2])
     {
        glColor3f(fill_color[0], fill_color[1], fill_color[2]);
        glBegin(GL_POINTS);
            glVertex2i(x,y);
        glEnd();
        glFlush();
        flood_fill(x+1, y);
        flood_fill(x-1, y);
        flood_fill(x, y+1);
        flood_fill(x, y-1);
    }
    else
        return;
}
void mouse(int button, int state, int x, int y)
{
    y = 690-y;
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
        flood_fill(x,y);
    }
}
void display()
{
    glLineWidth(2);
    glPointSize(1);
    glClear(GL_COLOR_BUFFER_BIT);
    int count = 0;
    if(!complete)
    {
        glPointSize(2);
        glBegin(GL_LINE_STRIP);
        for(int i=0;i<edges;i++)
        {
            glColor3f(bndry_color[0], bndry_color[1], bndry_color[2]);
            glVertex2i(v[i].x, v[i].y);
            count += 1;
        }
        glEnd();
    }
    else
    {
        glPointSize(2);
        glBegin(GL_LINE_LOOP);
        for(int i=0;i<edges;i++)
        {
            glColor3f(bndry_color[0], bndry_color[1], bndry_color[2]);
            glVertex2i(v[i].x, v[i].y);
            count += 1;
        }
        glEnd();
    }
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1350,690);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Flood-Fill Algorithm ");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    initGL();
    glutMainLoop();
    return 0;
}

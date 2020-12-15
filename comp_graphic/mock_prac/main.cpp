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
    int get_y()
    {
        return y;
    }
    int get_x()
    {
        return x;
    }
};
vector<vertex>arr(50);
bool complete = false;
bool colored = false;
int edges = 0;

void scanline(vector<vertex>p,int n)
{
    vector<float>m(100);
    vector<int>interx(100);
    int ymax=0,ymin=500,dx,dy;

    for(int i=0;i<n;i++){
        if(p[i].get_y()>ymax)
            ymax=p[i].get_y();
        if(p[i].get_y()<ymin)
            ymin=p[i].get_y();
        dx=p[i+1].get_x()-p[i].get_x();
        dy=p[i+1].get_y()-p[i].get_y();

        if(dx==0)
            m[i]=0;
        if(dy==0)
            m[i]=1;

        if(dx!=0 && dy!=0){
            m[i]=(float)dx/dy;
        }
    }
    int k;
    for(int y=ymax;y>=ymin;y--){
        k=0;
        for(int i=0;i<n;i++){
            if(p[i].get_y()>y && p[i+1].get_y()<=y || p[i].get_y()<=y && p[i+1].get_y()>y){
                interx[k++]=(p[i].get_x()+(m[i]*(y-p[i].get_y())));
            }
        }

        for(int i=0;i<k-1;i+=2){
            glBegin(GL_LINES);
            glVertex2i(interx[i],y);
            glVertex2i(interx[i+1],y);
            glEnd();
            glFlush();
        }
    }
}

void initGL()
{
     glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
     glClear(GL_COLOR_BUFFER_BIT);
     glMatrixMode( GL_PROJECTION );
     glLoadIdentity();
     gluOrtho2D( 0, 500, 0, 500);
}

void mouse(int click, int pos, int x, int y)
{
    if(click == GLUT_LEFT_BUTTON && pos == GLUT_DOWN && !complete)
    {
        arr[edges].xy(x, 500 - y);
        edges++;
    }
    if(click == GLUT_RIGHT_BUTTON && pos == GLUT_DOWN && !complete)
    {
        complete = true;
        arr[edges].xy(arr[0].get_x(),arr[0].get_y());
        edges++;
    }
    if(click == GLUT_LEFT_BUTTON && pos == GLUT_DOWN && !colored && complete)
    {
        colored = true;
        scanline(arr,edges);
    }
    glutPostRedisplay();
 }


void display()
{
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(2);
    if(!complete)
    {
        glPointSize(10);
        glBegin(GL_POINTS);
            for(int i=0;i<edges;i++)
            glVertex2i(arr[i].get_x(), arr[i].get_y());
        glEnd();
        glPointSize(2);
        glBegin(GL_LINE_STRIP);
        for(int i=0;i<edges;i++)
            glVertex2i(arr[i].get_x(), arr[i].get_y());
        glEnd();
    }
    else
    {
        glBegin(GL_LINE_LOOP);
        for(int i=0;i<edges;i++)
            glVertex2i(arr[i].get_x(), arr[i].get_y());
        glEnd();
    }
    glFlush();
}


int main(int argc, char ** argv) {
     glutInit(&argc, argv);
     glutInitWindowPosition(0, 0);
     glutInitWindowSize(500, 500);
     glutCreateWindow("Polygon filling");
     initGL();
     glutMouseFunc(mouse);
     glutDisplayFunc(display);
     glutMainLoop();
     return(0);
 }

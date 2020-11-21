#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;


void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    glFlush();
}
void init(void)
{
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glOrtho(-454.0, 454.0, -250.0, 250.0, -250.0, 250.0);
}



void keys(unsigned char key,int x,int y)
{
    if(key=='q' || key=='Q')
        exit(0);
}

int main (int argc, char *argv)
{
    glutInit(&argc, &argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (600, 60);
    glutCreateWindow ("");
    init();
    glutKeyboardFunc(keys);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

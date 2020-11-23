#include <GL/glut.h>
#include <bits/stdc++.h>
#include <GL/freeglut.h>

using namespace std;
int window_width = 1350, window_height = 690;
int insert_x1 = 550, insert_x2 = 650, insert_y1 = 100, insert_y2 = 150;
int delete_x1 = 700, delete_x2 = 800, delete_y1 = 100, delete_y2 = 150;

int cnt = 0, beg = 0;
string input = "", value[12];
bool inserting = false, deleting = false, insert_in_queue = false;

void initGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, window_width, 0, window_height);
}

void drawText(float x, float y, float z, char * str, float r, float g, float b)
{
    glColor3f(r, g, b);
    glRasterPos3f(x, y, z);
    for (char* c = str; *c != '\0'; c++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
}

void writeText(float x, float y, float z, char* str, float r, float g, float b, float scalex, float scaley, float scalez)
{
    glColor3f(r, g, b);
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(scalex, scaley, scaley);
    for (char *c= str; *c != '\0'; c++)
    {
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *c);
    }
    glPopMatrix();
}

void keyboard(unsigned char key, int x, int y)
{
    if(key == 'i' || key=='I')
    {
        if(cnt != 12)
        {
            cout<<"Enter value to be inserted : ";
            input = "";
            cin>>input;
            value[cnt] = input;
            insert_in_queue=true;
            cnt++;
            glutPostRedisplay();
        }
        else
        {
            cout<<"\nQueue is Full!!";
        }
    }
    if(key == 'd' || key=='D')
    {
        if(cnt != beg)
        {
            deleting = true;
            if(beg != 12)
                beg++;
            glutPostRedisplay();
        }
        else
        {
            cout<<"\nQueue is empty!!";
        }
    }
    else
    {
        deleting = false;
        glutPostRedisplay();
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    writeText(200, 500, 0, "     QUEUE VISUALIZATION", 1.0f, 1.0f, 1.0f, 0.3f, 0.3f, 1.0f);
    // Queue
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2i(75, 350);
    glVertex2i(1275, 350);
    glVertex2i(1275, 350);
    glVertex2i(1275, 250);
    glVertex2i(1275, 250);
    glVertex2i(75, 250);
    glVertex2i(75, 250);
    glVertex2i(75, 350);
    glEnd();

    if(insert_in_queue)
    {
        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
        for(int i = beg + 1; i <= cnt ; i++)
        {
            glVertex2i(75 + (i-1)*100, 350);
            glVertex2i(75 + (i-1)*100, 250);
            glVertex2i(75 + (i*100), 250);
            glVertex2i(75 + (i*100), 350);
        }
        glEnd();
        glColor3f(1.0f, 1.0f, 1.0f);
        glLineWidth(2);
        glBegin(GL_LINES);
        for(int x = 75 + 100*beg; x <= 75 + cnt * 100 ; x += 100)
        {
            glVertex2i(x, 350);
            glVertex2i(x, 250 );
        }
        glEnd();

    }
    for(int j = beg; j < cnt; j++)
    {
        char temp[10];
        strcpy(temp, value[j].c_str());
        drawText(110 + j*100, 293, 0, temp, 1.0f, 1.0f, 1.0f);
    }
    glFlush();

}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(0, 5);
    glutInitWindowSize(window_width, window_height);
    glutCreateWindow("Queue Visualization using OpenGL");
    initGL();
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

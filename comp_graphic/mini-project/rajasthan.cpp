#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

const double PI = 3.141592654;
int frameNumber=0;
bool isDay=1,light_off=0,isOpen=1,runBus=1;
float p=0.75,q=0.47,r=0.14;
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
class disk
{
public:
    disk(float radius)
    {
        glBegin(GL_POLYGON);
        for (int d = 0; d < 32; d++)
        {
            double angle = 2*PI/32 * d;
            glVertex2d( radius*cos(angle), radius*sin(angle));
        }
        glEnd();
    }
};
class star
{
public:
    star(float x=0,float y=0)
    {
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(5-x,3.43-y);
        glVertex2f(4.95-x,3.35-y);
        glVertex2f(5.05-x,3.35-y);
        glVertex2f(5-x,3.32-y);
        glVertex2f(4.95-x,3.40-y);
        glVertex2f(5.05-x,3.40-y);
        glEnd();
    }
};
class tyre
{
public:
    tyre()
    {
        glColor3f(0,0,0);
        disk d1(1.15);
        glColor3f(0, 1, 0);
        disk d2Disk(1);
        glColor3f(0,0,1);
        disk d3(0.5);
        glRotatef(frameNumber,0,0,1);
        glBegin(GL_LINES);
        for (int i = 0; i < 20; i++)
        {
            glVertex2f(0,0);
            glVertex2d(cos(i*2*PI/20), sin(i*2*PI/20));
        }
        glEnd();
    }
};

class bus
{
public:
    bus()
    {
        assemble();
    }
    void bus_services()
    {
        writeText(-4.0, 1.4, 0, "bhanupratap", 1.0f, 1.0f, 0.0f, 0.007f, 0.01f, 0.1f);
        writeText(-4.0, 0.1, 0, "bus service", 1.0f, 1.0f, 0.0f, 0.007f, 0.01f, 0.1f);
    }
    void assemble()
    {
        glPushMatrix();
        set_size();
        drawTyre();
        lugagge_push();
        body();
        name_board();
        bus_services();
        window();
        glPopMatrix();
    }
    void window()
    {
        glColor3f(0,0,9);
        glBegin(GL_POLYGON);
        glVertex2f(-4-0.15,2.5);
        glVertex2f(-3-0.15,2.5);
        glVertex2f(-3-0.15,3.5);
        glVertex2f(-4-0.15,3.5);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(-4+1.2,2.5);
        glVertex2f(-3+1.2,2.5);
        glVertex2f(-3+1.2,3.5);
        glVertex2f(-4+1.2,3.5);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(-4+2.5,2.5);
        glVertex2f(-3+2.5,2.5);
        glVertex2f(-3+2.5,3.5);
        glVertex2f(-4+2.5,3.5);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(-4+3.8,2.5);
        glVertex2f(-3+3.8,2.5);
        glVertex2f(-3+3.8,3.5);
        glVertex2f(-4+3.8,3.5);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(-4+5.1,2.5);
        glVertex2f(-3+5.1,2.5);
        glVertex2f(-3+5.1,3.5);
        glVertex2f(-4+5.1,3.5);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(-4+7,2.5);
        glVertex2f(-3+7,2.5);
        glVertex2f(-3+7,3.5);
        glVertex2f(-4+7,3.5);
        glEnd();
    }
    void set_size()
    {
        glTranslated(-3 + 14*(frameNumber % 300) / 300.0, 0, 0);
        glScaled(0.3,0.3,1);
    }
    void name_board()
    {
        glColor3f(1,0,1);
        glBegin(GL_POLYGON);
        glVertex2f(4.5,0);
        glVertex2f(4.5,5);
        glVertex2f(-2.5,0);
        glEnd();
    }
    void body()
    {
        glColor3f(1,0,1);
        glBegin(GL_POLYGON);
        glVertex2f(-4.5f,0);
        glVertex2f(4.5f,0);
        glVertex2f(4.5f,4);
        glVertex2f(-4.5f,4);
        glEnd();
    }
    void drawTyre()
    {
        glPushMatrix();
        glTranslatef(-2.5f, -0.1f, 0);
        glScalef(0.8f,0.8f,1);
        tyre t1;
        glPopMatrix();
        glPushMatrix();
        glTranslatef(2.5f, -0.1f, 0);
        glScalef(0.8f,0.8f,1);
        tyre t2;
        glPopMatrix();
    }
    void lugagge_push()
    {
        glColor3f(0.5,0.5,0.5);
        glBegin(GL_LINES);
        glVertex2f(-4.5f,4);
        glVertex2f(4.5,4);
        glVertex2f(-4.5f,4.5f);
        glVertex2f(4.5,4.5f);
        glVertex2f(-4.5f,5);
        glVertex2f(4.5f,5);
        for(float i=-4.5; i<4.5; i+=0.5)
        {
            glVertex2f(i,4);
            glVertex2f(i,5);
        }
        glEnd();
    }
};

class windmill
{
public:
    windmill()
    {
        glColor3f(0.8f, 0.8f, 0.9f);
        glBegin(GL_POLYGON);
        glVertex2f(-0.05f, 0);
        glVertex2f(0.05f, 0);
        glVertex2f(0.05f, 3);
        glVertex2f(-0.05f, 3);
        glEnd();
        glTranslatef(0, 3, 0);
        glRotated(frameNumber * (180.0/46), 0, 0, 1);
        glColor3f(0.0f, 3.1f, 0.0f);
        for (int i = 0; i < 3; i++)
        {
            glRotated(120, 0, 0, 1);
            glBegin(GL_POLYGON);
            glVertex2f(0,0);
            glVertex2f(0.5f, 0.1f);
            glVertex2f(1.5f,0);
            glVertex2f(0.5f, -0.1f);
            glEnd();
        }
    }
};

class draw
{
public:
    draw()
    {
        sandHills();
        drawHouse();
        road();
        allWindmills();
        if(runBus)
            startBus();
    }
    void sandHills()
    {
        glColor3f(1.9f, 0.8f, 0.5f);
        glBegin(GL_POLYGON);//first hill
        glVertex2f(-3,-1);
        glVertex2f(1.0f,1.65f);
        glVertex2f(5,-1);
        glEnd();
        glBegin(GL_POLYGON); // second hill overlapping first
        glVertex2f(-3,-1);
        glVertex2f(3,2.1f);
        glVertex2f(7,-1);
        glEnd();
        glBegin(GL_POLYGON); // third hill
        glVertex2f(0,-1);
        glVertex2f(6,1.2f);
        glVertex2f(20,-1);
        glEnd();
    }
    void drawHouse()
    {
        //body
        glColor3f(p,q,r);
        glBegin(GL_POLYGON);
        glVertex2f(0.5-0.3,0.5);
        glVertex2f(0.5-0.3,1.8);
        glVertex2f(2.5-0.1,1.8);
        glVertex2f(2.5-0.1,0.5);
        glVertex2f(1.5-0.1,0.5);
        glVertex2f(1.5-0.1,1);
        glVertex2f(0.5-0.3,1);
        glVertex2f(0.5-0.3,0.5);
        glEnd();
        //top of house
        glColor3f(0.35,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(0.25-0.1,1.8);
        glVertex2f(0.25-0.1,1.8+0.65);
        glVertex2f(2.345+0.1,1.8+0.65);
        glVertex2f(2.345+0.1,1.8);
        glEnd();
        window(0.1);
        window(-1.3);
        door();
    }
    void door()
    {
        if(isOpen)
        {
            glColor3f(1-light_off,1-light_off,1-light_off);
            glBegin(GL_POLYGON);
            glVertex2f(1.0,0.5);
            glVertex2f(1.0,1.2);
            glVertex2f(1.6,1.2);
            glVertex2f(1.6,0.5);
            glEnd();
            glColor3f(0.35f,0,0);
            glLineWidth(6);
            glBegin(GL_LINES);
            glVertex2f(1.0,0.5);
            glVertex2f(1.0,1.2);
            glVertex2f(1.0,1.2);
            glVertex2f(1.6,1.2);
            glVertex2f(1.6,1.2);
            glVertex2f(1.6,0.5);
            glEnd();
            glLineWidth(2);
            glBegin(GL_POLYGON);
            glVertex2f(1.0,0.5);
            glVertex2f(1.0,1.2);
            glVertex2f(1.4,1.1);
            glVertex2f(1.4,0.6);
            glVertex2f(1.0,0.5);
            glEnd();
        }
        else
        {
            glColor3f(0.35f,0,0);
            glBegin(GL_POLYGON);
            glVertex2f(1.0,0.5);
            glVertex2f(1.0,1.2);
            glVertex2f(1.6,1.2);
            glVertex2f(1.6,0.5);
            glEnd();
        }
    }
    void window(float x=0,float y=0)
    {
        glColor3f(1-light_off,1-light_off,1-light_off);
        glBegin(GL_POLYGON);
        glVertex2f(0.45-x,1.1-y);
        glVertex2f(0.45-x,1.6-y);
        glVertex2f(0.95-x,1.6-y);
        glVertex2f(0.95-x,1.1-y);
        glEnd();
        glLineWidth(8);
        glColor3f(0.35,0.0,0.0);
        glBegin(GL_LINES);
        glVertex2f(0.45-x,1.1-y);
        glVertex2f(0.45-x,1.6-y);
        glVertex2f(0.95-x,1.6-y);
        glVertex2f(0.95-x,1.1-y);
        glVertex2f(0.95-x,1.6-y);
        glVertex2f(0.45-x,1.6-y);
        glVertex2f(0.95-x,1.1-y);
        glVertex2f(0.45-x,1.1-y);
        glVertex2f(0.7-x,1.6-y);
        glVertex2f(0.7-x,1.1-y);
        glEnd();
        glLineWidth(2);
    }
    void startBus()
    {
        bus b1;
    }
    void allWindmills()
    {
        glPushMatrix();
        glTranslated(4.5,0.909,0);
        glScaled(0.4,0.2,1);
        windmill mill1;
        glPopMatrix();

        glPushMatrix();
        glTranslated(3.2,0.6,0);
        glScaled(0.4,0.4,1);
        windmill mill2;
        glPopMatrix();

        glPushMatrix();
        glTranslated(6.5,0.5,0);
        glScaled(0.3,0.3,1);
        windmill mill3;
        glPopMatrix();
    }
    void road()
    {
        glColor3f(0.4f, 0.4f, 0.5f);
        glBegin(GL_POLYGON);//road
        glVertex2f(0,-0.4f);
        glVertex2f(7,-0.4f);
        glVertex2f(7,0.4f);
        glVertex2f(0,0.4f);
        glEnd();
        glLineWidth(6);//yellow strip
        glColor3f(1,1,0.5f);
        glBegin(GL_LINES);
        glVertex2f(0,0);
        glVertex2f(7,0);
        glEnd();
        glLineWidth(2.5);
    }
};

class day
{
public:
    day()
    {
        draw_scene();
        draw d1;
    }
    void draw_scene()
    {
        glColor4f(0.4f,0.5f,1,1);
        glBegin(GL_POLYGON);
        glVertex2f(0,-1);
        glVertex2f(0,4);
        glVertex2f(7,4);
        glVertex2f(7,-1);
        glEnd();
        drawSun();
    }
    void drawSun()
    {
        glLineWidth(2);
        glColor3f(1,1,0.5);
        glPushMatrix();
        glTranslated(3.8,3.2,0);//translating to sun's location
        disk d2(0.5);
        glPopMatrix();
    }
};

class night
{
public:
    night()
    {
        draw_scene();
        draw d1;
    }
    void draw_scene()
    {
        glColor4f(0,0,0,0);
        glBegin(GL_POLYGON);
        glVertex2f(0,-1);
        glVertex2f(0,4);
        glVertex2f(7,4);
        glVertex2f(7,-1);
        glEnd();
        drawMoon();
        drawStars();
    }
    void drawStars()
    {
        star s1;
        star s2(-1.9,1);
        star s3(-1.5,0);
        star s4(-1,2);
        star s5(-0.9,0.8);
        star s6(0.4,1.7);
        star s7(1,1.1);
        star s8(2,-0.5);
        star s9 (2.5,1);
        star s10(3,-0.1);
        star s11(3.7,1.4);
        star s12(4.5,0.3);
        star s13(4.9,1.3);
    }
    void drawMoon()
    {
        glLineWidth(2);
        glColor3f(1,1,1);
        glPushMatrix();
        glTranslated(3.8,3.2,0);//translating to moon's location
        disk d2(0.5);
        glPopMatrix();
    }
};

void nextFrame(int v)
{
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(20,nextFrame,0);
}

void menus()
{
    cout<<"Press n for night";
    cout<<"\nPress d for day";
    cout<<"\nPress b for enable/disable bus";
    cout<<"\nPress l for turning on light of house";
    cout<<"\nPress f for turing off light of house";
    cout<<"\nPress o for opening door of house";
    cout<<"\nPress c for close door of house"<<endl<<endl;
}



void keyboardFunc( unsigned char key, int x, int y )
{
    if(key=='n')
    {
        isDay=false;
        cout<<"Pressed 'n' key"<<endl;
    }
    if(key=='d')
    {
        isDay=true;
        cout<<"Pressed 'd' key"<<endl;
    }
    if(key=='l')
    {
        light_off=false;
        cout<<"Pressed 'l' key"<<endl;
    }
    if(key=='f')
    {
        light_off=true;
        cout<<"Pressed 'f' key"<<endl;
    }
    if(key=='o')
    {
        isOpen=true;
        cout<<"Pressed 'o' key"<<endl;
    }
    if(key=='c')
    {
        isOpen=false;
        cout<<"Pressed 'c' key"<<endl;
    }
    if(key=='b')
    {
        runBus=!runBus;
        cout<<"Pressed 'b' key"<<endl;
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    if(isDay)
        day d3;
    else
        night n2;
    glPopMatrix();
    glutSwapBuffers();
}

void init(void)
{
    glClearColor(0.4f,0.5f,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    menus();
    glOrtho(0, 7, -1, 4, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(200,200);
    glutInitWindowSize(700,500);
    glutCreateWindow("Mini-project");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardFunc);
    glutTimerFunc(20,nextFrame,0);
    glutMainLoop();
    return 0;
}

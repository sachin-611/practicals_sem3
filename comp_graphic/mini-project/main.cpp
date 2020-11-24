#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

const double PI = 3.141592654;
int frameNumber=0;
bool day=true;
void init(void)
{
    glClearColor(0.4f,0.5f,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 7, -1, 4, -1, 1);
    glMatrixMode(GL_MODELVIEW);
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
void drawhill(void)
{
//    glOrtho()
    glColor3f(1.9f, 0.8f, 0.5f);
    glBegin(GL_POLYGON);//first hill
	glVertex2f(-3,-1);
	glVertex2f(1.0f,1.65f);
	glVertex2f(5,-1);
	glEnd();
    glBegin(GL_POLYGON); // second hill ovelapping first
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

void drawRoad(void)
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
}

void drawDisk(double radius) {
	glBegin(GL_POLYGON);
	for (int d = 0; d < 32; d++) {
		double angle = 2*PI/32 * d;
		glVertex2d( radius*cos(angle), radius*sin(angle));
	}
	glEnd();
}

void drawSun(void) {
    glLineWidth(2);
    glPushMatrix();
	glTranslated(3.8,3.2,0);//translating to sun's location
	drawDisk(0.5);
	glPopMatrix();
}

void drawWindmill()
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

void drawAllWindmill(void)
{
    glPushMatrix();
	glTranslated(4.5,0.909,0);
	glScaled(0.4,0.2,1);
    drawWindmill();
    glPopMatrix();

    glPushMatrix();
	glTranslated(3.2,0.6,0);
	glScaled(0.4,0.4,1);
	drawWindmill();
	glPopMatrix();

	glPushMatrix();
	glTranslated(6.5,0.5,0);
	glScaled(0.3,0.3,1);
	drawWindmill();
	glPopMatrix();
    //board
    glColor3f(1,1,1);
	glPushMatrix();
    glBegin(GL_POLYGON);
        glVertex2f(4+2,2-1.3);
        glVertex2f(5,2-1.3);
        glVertex2f(5,3-0.5-1.3);
        glVertex2f(4+2,3-0.5-1.3);
    glEnd();
	glPopMatrix();

}

void drawTyre() {
	glColor3f(0,0,0);
	drawDisk(1.15);
	glColor3f(0, 1, 0);
	drawDisk(1);
	glColor3f(0,0,1);
	drawDisk(0.5);
	glRotatef(frameNumber,0,0,1);
	glBegin(GL_LINES);
	for (int i = 0; i < 20; i++) {
		glVertex2f(0,0);
		glVertex2d(cos(i*2*PI/20), sin(i*2*PI/20));
	}
	glEnd();
}

void drawBus() {
	glPushMatrix();
	glTranslatef(-2.5f, -0.1f, 0);
	glScalef(0.8f,0.8f,1);
	drawTyre();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.5f, -0.1f, 0);
	glScalef(0.8f,0.8f,1);
	drawTyre();
	glPopMatrix();
	//luggage begin
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_LINES);
	glVertex2f(-4.5f,4);
	glVertex2f(4.5,4);
	glVertex2f(-4.5f,4.5f);
	glVertex2f(4.5,4.5f);
	glVertex2f(-4.5f,5);
	glVertex2f(4.5f,5);
	for(float i=-4.5;i<4.5;i+=0.5)
    {
        glVertex2f(i,4);
        glVertex2f(i,5);
    }
	glEnd();
	//luggage ends
	//bus body begin
	glColor3f(50,0,100);
	glBegin(GL_POLYGON);
	glVertex2f(-4.5f,0);
	glVertex2f(4.5f,0);
	glVertex2f(4.5f,4);
	glVertex2f(-4.5f,4);
	glEnd();
	//bus body end
	glColor3f(1,0,1);
	//name display board start
	glBegin(GL_POLYGON);
	glVertex2f(4.5,0);
	glVertex2f(4.5,5);
	glVertex2f(-2.5,0);
	glEnd();
	//name display board end
}

void drawnight()
{
   // glClearColor(0,0,0,0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    drawhill();//drawing hill
    drawRoad();//drawing road
    if(day)
        drawSun(); //drawing sun
    else
        drawnight();
    drawAllWindmill();//drawing 3 windmills

        drawnight();
	glTranslated(-3 + 14*(frameNumber % 300) / 300.0, 0, 0);
	glScaled(0.3,0.3,1);
	drawBus();
    writeText(-4.0, 1.2, 0, "bhanupratap", 1.0f, 1.0f, 0.0f, 0.007f, 0.01f, 0.1f);
    writeText(-4.0, 0.1, 0, "bus service", 1.0f, 1.0f, 0.0f, 0.007f, 0.01f, 0.1f);
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
	glPopMatrix();
	glutSwapBuffers();
}

void doFrame(int v)
{
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(20,doFrame,0);
}

int main(int argc ,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowPosition(200,200);
    glutInitWindowSize(700,500);
    glutCreateWindow("Mini-project");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(20,doFrame,0);
    glutMainLoop();
    return 0;
}

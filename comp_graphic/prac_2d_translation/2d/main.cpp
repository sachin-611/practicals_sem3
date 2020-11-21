#include<windows.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200,200,-200,200);
}

void setpixel(GLint x, GLint y)
{
	glColor3f(0.0,0.0,1.0);
	glPointSize(2.0);
	glBegin (GL_POINTS);
		glVertex2f(x,y);
	glEnd();
	glFlush();
}

vector<vector<float>> mati(30,vector<float>(2));
vector<vector<float>> mato(30,vector<float>(2));
int transl[2][2];
int count_,n=0;
void plot(vector<vector<float>>&m)
{
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
	for(int i=0;i<count_;i++)
		glVertex2f(m[i][0],m[i][1]);
	glEnd();
	glFlush();
}
void translation()
{
    float t_x,t_y;
    cout<<endl<<"Enter tx factor::"<<endl;
	cin>>t_x;
	cout<<endl<<"Enter ty factor::"<<endl;
	cin>>t_y;
	for(int i=0;i<count_;i++)
	{
		mato[i][0]=mati[i][0] + t_x;
		mato[i][1]=mati[i][1] + t_y;
	}
}

void keyboard(unsigned char key,int x,int y)
{
	if(key=='l')
	{   glColor3f(1.0,0.0,1.0);
		glBegin(GL_LINE_LOOP);
        for(int i=0;i<n;i++)
        glVertex2f(mati[i][0],mati[i][1]);
        glEnd();
        count_=n;
        n=0;
		translation();
		plot(mato);
        glFlush();
	}
}

void mouse(int button,int state,int x,int y)
{
	int x1,y1,p;
	if(button==GLUT_LEFT_BUTTON && state== GLUT_DOWN) {
			mati[n][0]=(float)(x-200);
			mati[n][1]=(float)(200-y);
			glColor3f(1.0,0.0,0.0);
			glPointSize(3.0);
			glBegin(GL_POINTS);
			glVertex2f(mati[n][0],mati[n][1]);
			glEnd();
			n++;
			glFlush();
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(400,400);
	glutCreateWindow("2D");
	glutDisplayFunc(init);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}

#include<bits/stdc++.h>
#include<GL/glut.h>
using namespace std;

int top = -1;
int width = 200;
int height = 25;
string a[5];
bool previous=true;

void init()
{
	glClearColor(1, 0, 1,1);
	glViewport(0, 0, 500, 500);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-250, 250, -250, 250, -100, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void drawBitmap(string str, int x, int y)
{
	glRasterPos2f(x, y);

	for (int i = 0; i < str.length(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	}
}

void show()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(0, -200, 0);
	int k = 0;
	for (int i = 0; i <= top; i++) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glBegin(GL_POLYGON);
		glVertex2f(-100, k);
		glVertex2f(100, k);
		glVertex2f(100, k + 50);
		glVertex2f(-100, k + 50);
		glEnd();
		glRasterPos2f(-2, (k + 10));
		for (int j = 0; j < a[i].length(); j++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, a[i][j]);
		}
		k += 50;
	}
	glutSwapBuffers();
	glPopMatrix();
}

void push()
{
	if (top >= 4)
	{
		drawBitmap("STACK IS FULL", -70, 200);
		glutSwapBuffers();
	}
	else{
		top++;
		cout<<"\nEnter the Element: ";
		cin >> a[top];
		cout << endl;
		show();
	}
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	if (top == -1)
	{
		string c = "3. Enter q or Q to Exit";
		glRasterPos2i(-70, 120);
		for (int i = 0; i < c.length(); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c[i]);
		}
		c = "2. Enter r or R to Pop";
		glRasterPos2i(-70,140);
		for (int i = 0; i < c.length(); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c[i]);
		}
		c = "1. Enter i or I to Push";
		glRasterPos2i(-70, 160);
		for (int i = 0; i < c.length() ; i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c[i]);
		}
		glFlush();
		glutSwapBuffers();
	}
	else{
		string c = "3. Enter q or Q to Exit";
		glRasterPos2i(-70, 120);
		for (int i = 0; i < c.length(); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c[i]);
		}
		c = "2. Enter r or R to Pop";
		glRasterPos2i(-70,140);
		for (int i = 0; i < c.length(); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c[i]);
		}
		c = "1. Enter i or I to Push";
		glRasterPos2i(-70, 160);
		for (int i = 0; i < c.length() ; i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c[i]);
		}
		glFlush();
		show();
		}
}

void pop()
{
	if (top ==-1)
	{
	    display();
		drawBitmap("STACK IS EMPTY", -70, 200);
		glutSwapBuffers();
	}
	else
	{
		cout << "\nElement " << a[top] << " is removed from stack\n";
		top--;
		show();
	}
}


void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'i' | 'I':
	    if(top==-1)
            display();
	    push();
		break;

	case 'r' | 'R': pop();
		display();
		if(top==-1)
            pop();
		break;
	case 'q' | 'Q': exit(0);
	}
}

int main(int argc, char*argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Stack Display");
    init();
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}

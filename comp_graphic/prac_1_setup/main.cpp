// This is a sample OpenGL program to display a Triangle

#ifdef __APPLE__

#include <GLUT/glut.h> // Header file required for OpenGL

#else

#include <GL/glut.h> // Header file required for OpenGL

#endif

#include <stdlib.h> // Header file standard library

#include<iostream> // Header file input/output stream

using namespace std; // Standard name space

void display() {

glClear(GL_COLOR_BUFFER_BIT); // Clears the buffer

glBegin(GL_POLYGON); // Graphics Primitive used- GL_POLYGON

glColor3f(1.0, 0.0, 0.0); // Used for coloring object

glVertex2f(-0.6, -0.75); // Used to draw vertex

glColor3f(0.0, 1.0, 0.0);

glVertex2f(0.6, -0.75);

glColor3f(0.0, 0.0, 1.0);

glVertex2f(0, 0.75);

glEnd();

// Flush drawing command buffer to make drawing happen as soon as possible.

glFlush();

}

int main(int argc, char** argv)

{

glutInit(&argc, argv); // Initializes GLUT

glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Initializes the display mode

glutCreateWindow(" A Simple Triangle"); // Crates Output Window

glutInitWindowPosition(200,200); //Initializes Windows initial position

glutInitWindowSize(400,300); // Defines dimensions of Output Window

glutReshapeWindow(1000,800);

glutDisplayFunc(display); // Registers callback function

glutMainLoop(); //Enters the main event loop

return 0;

}

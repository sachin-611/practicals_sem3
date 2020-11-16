// This is a sample OpenGL program to display a square
// #include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void displaySquare() {

   glClearColor(0.25, 1.0, 0.75 ,0.0); // Set background color to white and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
   // Draw a Red 1x1 Square centered at origin
   glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      glColor3f(0.70, 0.05, 0.75); // Blue
      glVertex2f(-0.5f, -0.5f);    // x, y
      glVertex2f( 0.5f, -0.5f);
      glVertex2f( 0.5f,  0.5f);
      glVertex2f(-0.5f,  0.5f);
   glEnd();
   glFlush();  // Render now

}

void displayPoints(){

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 1.0, 0.75 ,0.0);
    glLoadIdentity();
    gluOrtho2D(0,100,0,100);
    glPointSize(10.0);
    glBegin(GL_POINTS);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(20,50);
        glVertex2f(30,50);
        glVertex2f(10,20);
        glVertex2f(20,70);
        glVertex2f(10,40);
    glEnd();
    glFlush();

}

void displayLines(){

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,0.0,1.0);
    glLoadIdentity();
    gluOrtho2D(0,100,0,100);
    glBegin(GL_LINES);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(10,20);
        glVertex2f(30,50);
        glVertex2f(10,20);
        glVertex2f(20,70);
        glVertex2f(10,40);
        glVertex2f(20,10);
    glEnd();
    glFlush();

}

void displayLineStrip(){

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,1.0,1.0,1.0);
    glLoadIdentity();
    gluOrtho2D(0,100,0,100);
    glBegin(GL_LINE_STRIP);
        glColor3f(0.0,0.0,1.0);
        glVertex2f(10,20);
        glVertex2f(30,50);
        glVertex2f(10,20);
        glVertex2f(20,70);
        glVertex2f(10,40);
        glVertex2f(20,10);
    glEnd();
    glFlush();

}

void displayLineLoops(){

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,1.0,0.0,1.0);
    glLoadIdentity();
    gluOrtho2D(0,100,0,100);
    glBegin(GL_LINE_LOOP);
        glColor3f(1.25,0,1.0);
        glVertex2f(10,20);
        glVertex2f(30,50);
        glVertex2f(10,20);
        glVertex2f(20,70);
        glVertex2f(10,40);
        glVertex2f(30,50);
    glEnd();
    glFlush();

}

void displayTriangles(){

    glClearColor(0.8,0.2,0.6,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5,-0.5);
    glVertex2f(0.0,0.5);
    glVertex2f(0.5,-0.5);
    glEnd();
    glFlush();

}

void displayTriangleFan(){

    glClearColor(0.8,0.2,0.6,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0,1.0,0);
    glVertex2f(-0.5,-0.5);
    glVertex2f(0.0,0.5);
    glVertex2f(0.5,-0.5);
    glVertex2f(0.75,0.75);
    glVertex2f(0.75,-0.75);
    glVertex2f(-0.75,-0.75);
    glEnd();
    glFlush();

}

void displayTriangleStrip(){

    glClearColor(0.0,1.25,0.5,0.75);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0,0,0);
        glVertex2f(0.5,-0.5);
        glVertex2f(0.0,1.0);
        glVertex2f(0.5,-0.5);
        glVertex2f(0,0);
        glVertex2f(-0.5,0.5);
        glVertex2f(0.5,0.5);
    glEnd();
    glFlush();
}

void displayPolygon(){


    glClearColor(0.50,1.5,0.7,0.75);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
        glVertex2f(-0.5,-0.5);
        glVertex2f(0.5,-0.5);
        glVertex2f(-0.5,0.5);
        glVertex2f(0.5,0.5);
    glEnd();
    glFlush();

}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
   glutInit(&argc, argv);                 // Initialize GLUT
   glutCreateWindow(" A Simple Square"); // Create a window with the given title
   glutInitWindowSize(320, 320);   // Set the window's initial width & height
   glutReshapeWindow(1000,800);
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutDisplayFunc(displaySquare); // Register display callback handler for window re-paint
   //glutDisplayFunc(displayPoints);
   //glutDisplayFunc(displayLines);
   //glutDisplayFunc(displayLineStrip);
   //glutDisplayFunc(displayLineLoops);
   //glutDisplayFunc(displayTriangles);
   //glutDisplayFunc(displayTriangleFan);
   //glutDisplayFunc(displayTriangleStrip);
  // glutDisplayFunc(displayPolygon);
   glutMainLoop();           // Enter the event-processing loop
   return 0;
}

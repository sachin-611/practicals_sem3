#include<iostream>
#include<GL/glut.h>
#include<math.h>

using namespace std;

static int choice = 0;
int window;

class line
{
    float ax1,ax2,ay1,ay2;

public:
    static float line_red, line_green, line_blue;
    static float bg_red, bg_green, bg_blue;

    void input_data()
    {
        cout<<"Enter the value of x1: ";
        cin>>ax1;
        cout<<"Enter the value of y1: ";
        cin>>ay1;
        cout<<"Enter the value of x2: ";
        cin>>ax2;
        cout<<"Enter the value of y2: ";
        cin>>ay2;
    }

    void draw_pixel(int x, int y)
    {
        glPointSize(2);
        glBegin(GL_POINTS);
            glColor3f(line_red, line_green, line_blue);
            glVertex2f(x, y);
        glEnd();
    }

    void dda_line_generation()
    {
        GLfloat dx, dy, incx, incy, x, y;
        int steps;
        dx = ax2 - ax1;
        dy = ay2 - ay1;
        steps = max(abs(dx), abs(dy));
        incx = dx/steps;
        incy = dy/steps;
        x = ax1;
        y = ay1;
        draw_pixel(x, y);
        for(int i =0; i<=steps; i++)
        {
            x += incx;
            y += incy;
            draw_pixel(x, y);
        }
    }
    void bresenham_line_generation()
    {
        int dx, dy, p, x, y;
        dx = ax2 - ax1;
        dy = ay2 - ay1;
        x = ax1;
        y = ay1;
        p = 2*dy - dx;
        while(x < ax2)
        {
            if(p >= 0)
            {
                draw_pixel(x, y);
                y=y+1;
                p=p+2*dy-2*dx;
            }
            else
            {
                draw_pixel(x, y);
                p=p+2*dy;
            }
            x=x+1;
        }
    }

    void modified_bresenham_line_generation()
    {
        int dx, dy, p, x, y;
        int incx, incy, inc1, inc2;

        dx = ax2 - ax1;
        dy = ay2 - ay1;

        if(dx < 0)
            dx = -dx;
        if(dy < 0)
            dy = -dy;

        incx = 1;
        if(ax2 < ax1)
        incx = -1;
        incy = 1;
        if(ay2 < ay1)
            incy = -1;

        x = ax1;
        y = ay1;

        if(dx > dy)
        {
            draw_pixel(x, y);
            p = 2 * dy -dx;
            inc1 = 2 * (dy - dx);
            inc2 = 2 * dy;
            for(int i=0; i<dx; i++)
            {
                if(p >= 0)
                {
                    y += incy;
                    p += inc1;
                }
                else
                    p += inc2;
                x += incx;
                draw_pixel(x, y);
            }
        }
        else
        {
            draw_pixel(x, y);
            p = 2 * dx - dy;
            inc1 = 2 * (dx - dy);
            inc2 = 2 * dx;
            for(int i=0; i < dy; i++)
            {
                if(p >= 0)
                {
                    x += incx;
                    p += inc1;
                }
                else
                    p += inc2;
                y += incy;
                draw_pixel(x, y);
            }
        }
    }

}obj;

float line::line_red = 1.0, line::line_green = 1.0, line::line_blue = 0.0;
float line::bg_red = 0.5, line::bg_green = 0.2, line::bg_blue = 0.0;

void InitGL()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500,500,-500,500);
}


void display()
{
    glClearColor( 1.0, 0.3 ,0.7 , 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    if (choice == 1)
        obj.dda_line_generation();
    else if(choice == 2)
        obj.bresenham_line_generation();
    else if(choice == 3)
        obj.modified_bresenham_line_generation();
    else
        glClear(GL_COLOR_BUFFER_BIT);

    glFlush();

}


void keyboard_event(unsigned char key, int x, int y)
    {
        if(key == 13)
        {
            glutDestroyWindow(window);
            exit(0);
        }
        else if(key == 'd' || key=='D')
        {
            cout<<"\n You pressed "<<key<<" So, DDA Algorithm";
            choice = 1;
        }
        else if(key == 'b' || key == 'B')
        {
            cout<<"\n You pressed "<<key<<" so, Bresenham Algorithm";
            choice = 2;
        }
        else if(key == 'm' || key == 'M')
        {
            cout<<"\n You pressed "<<key<<" so, Modified Bresenham Algorithm";
            choice = 3;
        }
        glutPostRedisplay();
    }


void menu_right(int n)
{
    choice = n;
    glutPostRedisplay();
}

void create_Right_Menu()
{
    glutCreateMenu(menu_right);
        glutAddMenuEntry("DDA", 1);
        glutAddMenuEntry("Bresenham", 2);
        glutAddMenuEntry("Modified Bresenham", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void menu_left(int n)
{
    switch(n)
    {
        case -1:glutDestroyWindow(window);
                exit(0);
                break;
        case 0: line::line_red = line::bg_red;
                line::line_green = line::bg_green;
                line::line_blue = line::bg_blue;
                break;

        case 11: line::line_red = 1.0; line::line_green = 0.0; line::line_blue = 0.0;
                 break;
        case 12: line::line_red = 0.0; line::line_green = 1.0; line::line_blue = 0.0;
                 break;
        case 13: line::line_red = 0.0; line::line_green = 0.0; line::line_blue = 1.0;
                 break;
        case 14: line::line_red = 1.0; line::line_green = 1.0; line::line_blue = 0.0;
                 break;

        case 21: line::bg_red = 0.0; line::bg_green = 0.0; line::bg_blue = 0.0;
                 break;
        case 22: line::bg_red = 1.0; line::bg_green = 1.0; line::bg_blue = 1.0;
                 break;
        case 23: line::bg_red = 0.5; line::bg_green = 0.5; line::bg_blue = 0.5;
                 break;
        case 24: line::bg_red = 1.0; line::bg_green = 0.3; line::bg_blue = 0.7;
                 break;
    }
    glutPostRedisplay();
}

void create_Left_Menu()
{
    int submenu_line_color = glutCreateMenu(menu_left);
        glutAddMenuEntry("Red", 11);
        glutAddMenuEntry("Green", 12);
        glutAddMenuEntry("Blue", 13);
        glutAddMenuEntry("Original: Yellow", 14);

    int submenu_bg_color = glutCreateMenu(menu_left);
        glutAddMenuEntry("Black", 21);
        glutAddMenuEntry("White", 22);
        glutAddMenuEntry("Gray", 23);
        glutAddMenuEntry("Original", 24);

    glutCreateMenu(menu_left);
        glutAddSubMenu("Line Color", submenu_line_color);
        glutAddSubMenu("Background Color", submenu_bg_color);
        glutAddMenuEntry("Clear", 0);
        glutAddMenuEntry("Exit", -1);
    glutAttachMenu(GLUT_LEFT_BUTTON);
}


int main(int argc, char ** argv)
{
    obj.input_data();
    glutInit(&argc, argv);
    window = glutCreateWindow("Line Generation");
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    glutDisplayFunc(display);
    create_Right_Menu();
    create_Left_Menu();
    glutKeyboardFunc(keyboard_event);
    InitGL();
    glutMainLoop();
    return 0;
}

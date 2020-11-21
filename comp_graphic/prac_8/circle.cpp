#include <bits/stdc++.h>
#include<windows.h>
#include <GL/glut.h>
using namespace std;

static int choice;

class circle
{
    float x_cor, y_cor, radius;

public:
    static float circle_red, circle_green, circle_blue ;
    static float bg_red, bg_green, bg_blue ;

    void input()
    {
        cout<<"\nEnter the x coordinates of center of the circle: ";
        cin>>x_cor;
        cout<<"\nEnter the y coordinates of center of the circle: ";
        cin>>y_cor;
        cout<<"\nEnter the radius of the circle: ";
        cin>>radius;
    }
    void put_symmetric_pixel(int x, int y)
    {
        glColor3f(circle_red, circle_green, circle_blue);
        glBegin(GL_POINTS);
            glVertex2i(x_cor+x, y_cor+y);
            glVertex2i(x_cor+x, y_cor-y);
            glVertex2i(x_cor+y, y_cor+x);
            glVertex2i(x_cor+y, y_cor-x);
            glVertex2i(x_cor-x, y_cor-y);
            glVertex2i(x_cor-y, y_cor-x);
            glVertex2i(x_cor-x, y_cor+y);
            glVertex2i(x_cor-y, y_cor+x);
        glEnd();
    }
    void bresenham_circle_generation()
    {
        float x = 0, y = radius;
        float p = 3 - 2*radius;
        put_symmetric_pixel(x, y);
        while(x < y)
        {
            x = x + 1;
            if(p < 0)
                p = p + 4*x+6;
            else
            {
                y = y - 1;
                p = p + 4*(x - y) + 10;
            }
        put_symmetric_pixel(x, y);
        }
    }
    void dda_circle_generation()
    {
        float x1, y1, startx, starty, x2, y2, xini = x_cor, yini = y_cor;
        x1 = 0;
        y1 = radius;
        startx = x1;
        starty = y1;
        int temp, i=0;
        do
        {
            temp = pow(2,i);
            i++;
        }while(temp < radius);
        float E = pow(2,-(i-1));
        glColor3f(circle::circle_red,circle::circle_green,circle::circle_blue);
        glBegin(GL_POINTS);
        do
        {
            x2 = x1 + y1*E;
            y2 = y1 - x2*E;
            glVertex2f(xini+x2,yini+y2);
            x1 = x2;
            y1 = y2;
        }while((y1 - starty) < E||(startx - x1) > E);
        glEnd();
    }
    void mid_point_circle_generation()
    {
        float x = 0, y = radius;
        float d = (5/4) - radius;
        put_symmetric_pixel(x, y);
        while(x < y)
        {
            x = x + 1;
            if(d < 0)
                d = d + (2 * x) + 3;
            else
            {
                y = y - 1;
                d = d + 2*(x - y) + 5;
            }
            put_symmetric_pixel(x, y);
        }
    }
}circle_1;

float circle::circle_red = 1.0, circle::circle_green = 1.0, circle::circle_blue = 0.0;
float circle::bg_red = 0.0, circle::bg_green = 0.0, circle::bg_blue = 0.0;

void display()
{
    glClearColor(circle::bg_red, circle::bg_green, circle::bg_blue, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    if (choice ==2)
        circle_1.dda_circle_generation();
    else if(choice == 3)
        circle_1.mid_point_circle_generation();
    else if(choice == 1)
        circle_1.bresenham_circle_generation();
    glFlush();
}

void keyboard_event(unsigned char key, int x, int y)
{
    if(key == 13)
        exit(0);
    else if(key == 'w')
        {circle::bg_red = 1.0; circle::bg_green = 1.0 ; circle::bg_blue = 1.0;}
    else if(key == 'g')
        {circle::bg_red = 0.5; circle::bg_green = 0.5; circle::bg_blue = 0.5;}
    else if(key == 'M' || key=='m')
        choice = 3;
    else if(key == 'D' || key=='d')
        choice = 2;
    else if(key == 'B' || key=='b')
        choice = 1;

    glutPostRedisplay();
}

void InitGL()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500,500,-500,500);
}
void menu_right(int n)
{
    choice = n;
    glutPostRedisplay();
}

void create_Right_Menu()
{
    glutCreateMenu(menu_right);
        glutAddMenuEntry("dda circle", 1);
        glutAddMenuEntry("bresenham circle", 2);
        glutAddMenuEntry("mid point circle", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void menu_left(int n)
{
    switch(n)
    {
        case -1:
                exit(0);
                break;
        case 0: circle::circle_red = circle::bg_red;
                circle::circle_green = circle::bg_green;
                circle::circle_blue = circle::bg_blue;
                break;

        case 11: circle::circle_red = 1.0; circle::circle_green = 0.0; circle::circle_blue = 0.0;
                 break;
        case 12: circle::circle_red = 0.0; circle::circle_green = 1.0; circle::circle_blue = 0.0;
                 break;
        case 13: circle::circle_red = 0.0; circle::circle_green = 0.0; circle::circle_blue = 1.0;
                 break;
        case 14: circle::circle_red = 1.0; circle::circle_green = 1.0; circle::circle_blue = 0.0;
                 break;

        case 21: circle::bg_red = 0.0; circle::bg_green = 0.0; circle::bg_blue = 0.0;
                 break;
        case 22: circle::bg_red = 1.0; circle::bg_green = 1.0; circle::bg_blue = 1.0;
                 break;
        case 23: circle::bg_red = 0.5; circle::bg_green = 0.5; circle::bg_blue = 0.5;
                 break;
        case 24: circle::bg_red = 1.0; circle::bg_green = 0.3; circle::bg_blue = 0.7;
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
        glutAddSubMenu("Circle Color", submenu_line_color);
        glutAddSubMenu("Background Color", submenu_bg_color);
        glutAddMenuEntry("Clear", 0);
        glutAddMenuEntry("Exit", -1);
    glutAttachMenu(GLUT_LEFT_BUTTON);
}

void create_menu(){
    create_Right_Menu();
    create_Left_Menu();
}

int main(int argc,char **argv)
{
        circle_1.input();
        glutInit(&argc,argv);
        glutCreateWindow("-- Circle Generation --");
        glutInitWindowPosition(100,100);
        glutInitWindowSize(1000,1000);
        glutDisplayFunc(display);
        glutKeyboardFunc(keyboard_event);
        create_menu();
        InitGL();
        glutMainLoop();
        return 0;
}

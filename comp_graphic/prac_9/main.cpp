#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

static const float root_3=pow(3,0.5);

class pattern1
{
    int radius,x_cor=0,y_cor=0;
public:
    static float circle_red, circle_green, circle_blue ;
    static float line_red, line_green, line_blue;
    static float bg_red, bg_green, bg_blue ;
    void input()
    {
        cout<<"Enter radius of inner circle : ";
        cin>>radius;
        cout<<"Enter x co-ordinate of center : ";
        cin>>x_cor;
        cout<<"Enter y co-ordinate of center : ";
        cin>>y_cor;
    }

    void draw_pixel(int x, int y)
    {
        glPointSize(2);
        glBegin(GL_POINTS);
            glColor3f(line_red, line_green, line_blue);
            glVertex2f(x, y);
        glEnd();
    }

    void modified_bresenham_line_generation(int ax1,int ay1,int ax2,int ay2)
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

    void bresenham_circle(float radius)
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
        put_symmetric_pixel(x,y);
        }
    }

    void pattern_generate()
    {
        bresenham_circle(radius);
        bresenham_circle(radius*2);
        modified_bresenham_line_generation(x_cor,y_cor+(2*radius),x_cor+(root_3*radius),y_cor-radius);
        modified_bresenham_line_generation(x_cor-(root_3*radius),y_cor-radius,x_cor,y_cor+(2*radius));
        modified_bresenham_line_generation(x_cor-(root_3*radius),y_cor-radius,x_cor+(root_3*radius),y_cor-radius);
    }
}pattern1;
float pattern1::line_red = 1.0, pattern1::line_green = 1.0, pattern1::line_blue = 0.0;
float pattern1::circle_red = 1.0, pattern1::circle_green = 1.0, pattern1::circle_blue = 0.0;
float pattern1::bg_red = 0.0, pattern1::bg_green = 0.0, pattern1::bg_blue = 0.0;

class pattern2
{

    float x_cor, y_cor, h, w, radius;
    int ax1, ax2, ax3, ax4, ay1, ay2, ay3, ay4, bx1, bx2, bx3, bx4, by1, by2, by3, by4, width_sq, height_sq ;
public:
    static float line_red_, line_green_ , line_blue_ ;
    static float circle_red_, circle_green_ , circle_blue_ ;
    static float bg_red_ , bg_green_ , bg_blue_ ;

    void input(){
        cout<<"Enter x co-ordinates of center : ";
        cin>>x_cor;
        cout<<"Enter y co-ordinates of center : ";
        cin>>y_cor;
        cout<<"Enter height of pattern : ";
        cin>>h;
        cout<<"Enter width of pattern : ";
        cin>>w;
        ax1 = -w/2; ax2 = w/2; ax3 = w/2; ax4 = -w/2;
        ay1 = h/2; ay2 = h/2; ay3 = -h/2; ay4 = -h/2;
        bx1 = 0; bx2 = w/2; bx3 = 0; bx4 = -w/2;
        by1 = h/2; by2 = 0; by3 = -h/2; by4 = 0;
        width_sq = pow(w, 2);height_sq = pow(h, 2);
        radius = pow((width_sq + height_sq)/16, 0.5);
    }
    void draw_pixel(int x, int y)
    {
        glPointSize(2);
        glBegin(GL_POINTS);
            glColor3f(line_red_, line_green_, line_blue_);
            glVertex2f(x, y);
        glEnd();
    }

    void modified_bresenham_line_generation(int ax1,int ay1,int ax2,int ay2)
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

    void put_symmetric_pixel(int x, int y)
    {
        glColor3f(circle_red_, circle_green_, circle_blue_);
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

    void bresenham_circle(float radius)
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
        put_symmetric_pixel(x,y);
        }
    }

    void pattern_generate()
    {

    modified_bresenham_line_generation(ax1, ay1, ax2, ay2);
    modified_bresenham_line_generation(ax2, ay2, ax3, ay3);
    modified_bresenham_line_generation(ax3, ay3, ax4, ay4);
    modified_bresenham_line_generation(ax4, ay4, ax1, ay1);
    modified_bresenham_line_generation(bx1, by1, bx2, by2);
    modified_bresenham_line_generation(bx2, by2, bx3, by3);
    modified_bresenham_line_generation(bx3, by3, bx4, by4);
    modified_bresenham_line_generation(bx4, by4, bx1, by1);
    bresenham_circle(radius);

    }

}pattern2;

float pattern2::line_red_ = 1.0, pattern2::line_green_ = 1.0, pattern2::line_blue_ = 0.0;
float pattern2::circle_red_ = 1.0, pattern2::circle_green_ = 1.0, pattern2::circle_blue_ = 0.0;
float pattern2::bg_red_ = 0.0, pattern2::bg_green_ = 0.0, pattern2::bg_blue_ = 0.0;

class pattern3
{
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;
    int ax1,ax2,ax3,ax4,ay1,ay2,ay3,ay4,bx1,bx2,bx3,bx4,by1,by2,by3,by4;
    int x_cor,y_cor;
public:
    pattern3()
    {
        x1 = -300; x2 = 300; x3 = 300; x4 = -300;
        y1 = 300; y2 = 300; y3 = -300; y4 = -300;
    }

    void input(){
        cout<<"Enter x co-ordinate of center of pattern : ";
        cin>>x_cor;
        cout<<"Enter y co-ordinate of center of pattern : ";
        cin>>y_cor;
        ax1 = x1+x_cor, ax2 = x2+x_cor, ax3 = x3+x_cor, ax4 = x4+x_cor;
        ay1 = y1+y_cor, ay2 = y2+y_cor, ay3 = y3+y_cor, ay4 = y4+y_cor;
        bx1 = x1+x_cor, bx2 = x2+x_cor, bx3 = x3+x_cor, bx4 = x4+x_cor;
        by1 = y1+y_cor, by2 = y2+y_cor, by3 = y3+y_cor, by4 = y4+y_cor;
    }

    void draw_pixel(int x, int y)
    {
        glPointSize(2);
        glBegin(GL_POINTS);
            glColor3f(1.0, 1.0, 0.0);
            glVertex2f(x, y);
        glEnd();
    }

    void modified_bresenham_line_generation(int ax1,int ay1,int ax2,int ay2)
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

    void pattern_generate(){
        for(int i=0;i<3;i++)
        {
            modified_bresenham_line_generation(ax1, ay1, ax2, ay2);
            modified_bresenham_line_generation(ax2, ay2, ax3, ay3);
            modified_bresenham_line_generation(ax3, ay3, ax4, ay4);
            modified_bresenham_line_generation(ax4, ay4, ax1, ay1);
            ax1 = (bx1+bx2)/2; ax2 = (bx2+bx3)/2; ax3 = (bx3+bx4)/2; ax4 = (bx4+bx1)/2;
            ay1 = (by1+by2)/2; ay2 = (by2+by3)/2; ay3 = (by3+by4)/2; ay4 = (by4+by1)/2;
            bx1 = ax1; bx2 = ax2; bx3 = ax3; bx4 = ax4;
            by1 = ay1; by2 = ay2; by3 = ay3; by4 = ay4;
        }
    }
}pattern3;


void display()
{
    glClearColor(pattern1::bg_red, pattern1::bg_green, pattern1::bg_blue, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    pattern1.pattern_generate();
    pattern2.pattern_generate();
    pattern3.pattern_generate();
    glFlush();
}

void InitGL()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500,500,-500,500);
}

int main(int argc,char **argv)
{
        //pattern1.input();
        //pattern2.input();
        pattern3.input();
        glutInit(&argc,argv);
        glutCreateWindow("-x-x-x- Pattern Generation -x-x-x-");
        glutInitWindowPosition(100,100);
        glutInitWindowSize(1000,1000);
        glutDisplayFunc(display);
        InitGL();
        glutMainLoop();
}

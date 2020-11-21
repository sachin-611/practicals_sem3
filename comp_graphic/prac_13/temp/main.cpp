#include <windows.h>
#include <gl/glut.h>
#include <bits/stdc++.h>

using namespace std;

int screen_height = 690;
int screen_width = 1350;
bool complete = false, want_transformations = false;
bool doing_translation = false, doing_scaling = false;
bool doing_reflection = false, doing_shearing = false;
bool doing_rotation = false;

vector<vector<float>> ip_coordinates;
vector<vector<float>> op_coordinates;

int translate_coord_x, translate_coord_y;
int scaling_factor[2] = {0, 0}, scaling_count = 0;
char reflection_axis;
char shearing_axis;
int shearing_factor;
char rotation_type;
int options;

void multiply(float temp[2][2])
{
    op_coordinates.clear();
    int i, j, k;
    vector<float> sum;
    for (i = 0; i < ip_coordinates.size(); i++)
    {
        for (j = 0; j < 2; j++)
        {
            sum.push_back(0);
            for (k = 0; k < 2; k++)
                sum[j] = sum[j] + ip_coordinates[i][k] * temp[k][j];
        }
        op_coordinates.push_back(sum);
        sum.clear();
    }
    for (int l = 0; i < op_coordinates.size(); l++)
        for (int m = 0; m < 2; m++)
            cout << op_coordinates[l][m] << endl;
}

void translation()
{
    op_coordinates.clear();
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();
    int tx, ty;
    tx = translate_coord_x - ip_coordinates[0][0];
    ty = translate_coord_y - ip_coordinates[0][1];

    for (int i = 0; i < ip_coordinates.size(); i++)
        op_coordinates.push_back({ip_coordinates[i][0] + tx, ip_coordinates[i][1] + ty});

    if (want_transformations && op_coordinates.size() != 0)
    {
        glColor3f(0.0f, 1.0f, 0.0f);
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < op_coordinates.size(); i++)
            glVertex2i(op_coordinates[i][0], op_coordinates[i][1]);
        glEnd();
    }
    glFlush();
}
void scaling()
{
    if (scaling_count % 2 == 0)
    {
        op_coordinates.clear();
        glClear(GL_COLOR_BUFFER_BIT);
        glutPostRedisplay();
        float scaling_matrix[2][2];
        scaling_matrix[0][0] = scaling_factor[0];
        scaling_matrix[0][1] = 0;
        scaling_matrix[1][0] = 0;
        scaling_matrix[1][1] = scaling_factor[1];
        multiply(scaling_matrix);

        glColor3f(0.0f, 0.0f, 1.0f);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < op_coordinates.size(); i++)
            glVertex2i(op_coordinates[i][0], op_coordinates[i][1]);
        glEnd();
    }
    glFlush();
}

void reflection()
{
    op_coordinates.clear();
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();

    if (reflection_axis == 'x' || reflection_axis == 'X')
    {
        for (int i = 0; i < ip_coordinates.size(); i++)
            op_coordinates.push_back({ip_coordinates[i][0], ip_coordinates[i][1] * -1});
        glColor3f(1.0f, 1.0f, 0.0f);
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < op_coordinates.size(); i++)
            glVertex2i(op_coordinates[i][0], op_coordinates[i][1]);
        glEnd();
    }

    else if (reflection_axis == 'y' || reflection_axis == 'Y')
    {
        for (int i = 0; i < ip_coordinates.size(); i++)
            op_coordinates.push_back({ip_coordinates[i][0] * -1, ip_coordinates[i][1]});
        glColor3f(0.0f, 1.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < op_coordinates.size(); i++)
            glVertex2i(op_coordinates[i][0], op_coordinates[i][1]);
        glEnd();
    }
    glFlush();
}

void shearing()
{
    op_coordinates.clear();
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();

    if (shearing_axis == 'x')
    {
        float shearing_matrix[2][2];
        shearing_matrix[0][0] = 1;
        shearing_matrix[0][1] = 0;
        shearing_matrix[1][0] = shearing_factor;
        shearing_matrix[1][1] = 1;
        multiply(shearing_matrix);

        glColor3f(1.0f, 0.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < op_coordinates.size(); i++)
            glVertex2i(op_coordinates[i][0], op_coordinates[i][1]);
        glEnd();
        glFlush();
    }
    else if (shearing_axis == 'y')
    {
        float shearing_matrix[2][2];
        shearing_matrix[0][0] = 1;
        shearing_matrix[0][1] = shearing_factor;
        shearing_matrix[1][0] = 0;
        shearing_matrix[1][1] = 1;
        multiply(shearing_matrix);

        glColor3f(1.0f, 0.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < op_coordinates.size(); i++)
            glVertex2i(op_coordinates[i][0], op_coordinates[i][1]);
        glEnd();
        glFlush();
    }
}

void rotation()
{
    op_coordinates.clear();
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();
    glFlush();

    float angle, rotation_matrix[2][2];
    cout << "\n Enter angle for Rotation(in degrees) --> ";
    cin >> angle;
    glClear(GL_COLOR_BUFFER_BIT);
    angle = (3.14 * angle) / 180;
    if (rotation_type == 'c')
    {
        rotation_matrix[0][0] = cos(angle);
        rotation_matrix[0][1] = -sin(angle);
        rotation_matrix[1][0] = sin(angle);
        rotation_matrix[1][1] = cos(angle);
    }
    else if (rotation_type == 'a')
    {
        rotation_matrix[0][0] = cos(angle);
        rotation_matrix[0][1] = sin(angle);
        rotation_matrix[1][0] = -sin(angle);
        rotation_matrix[1][1] = cos(angle);
    }

    multiply(rotation_matrix);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < op_coordinates.size(); i++)
        glVertex2i(op_coordinates[i][0], op_coordinates[i][1]);
    glEnd();
    glFlush();
}

void initGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-screen_width / 2, screen_width / 2, -screen_height / 2, screen_height / 2);
}
void menu(int n)
{
    switch (n)
    {
    case 1:
        doing_translation = true;
        glClear(GL_COLOR_BUFFER_BIT);
        break;
    case 2:
        doing_scaling = true;
        glClear(GL_COLOR_BUFFER_BIT);
        break;
    case 3:
        doing_rotation = true;
        glClear(GL_COLOR_BUFFER_BIT);
        break;
    case 4:
        doing_reflection = true;
        glClear(GL_COLOR_BUFFER_BIT);
        break;
    case 5:
        doing_shearing = true;
        glClear(GL_COLOR_BUFFER_BIT);
        break;
    case 6:
        op_coordinates.clear();
        ip_coordinates.clear();
        want_transformations = false;
        complete = false;
        glutDestroyMenu(options);
        glClear(GL_COLOR_BUFFER_BIT);
        glutPostRedisplay();
        break;
    case 7:
        exit(0);
    }
}

void mouse_event(int button, int state, int x, int y)
{
    y = screen_height / 2 - y;
    x = x - screen_width / 2;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !complete)
    {

        ip_coordinates.push_back({x, y});
        glutPostRedisplay();
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && !complete)
    {
        complete = true;
        want_transformations = true;
        glutPostRedisplay();
    }

    if (want_transformations)
    {
        options = glutCreateMenu(menu);
        glutAddMenuEntry("TRANSLATION", 1);
        glutAddMenuEntry("SCALING", 2);
        glutAddMenuEntry("ROTATION", 3);
        glutAddMenuEntry("REFLECTION", 4);
        glutAddMenuEntry("SHEARING", 5);
        glutAddMenuEntry("CLEAR", 6);
        glutAddMenuEntry("EXIT", 7);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
    }

    if (doing_translation && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        translate_coord_x = x;
        translate_coord_y = y;
        translation();
        doing_translation = false;
    }
}

void keyboard(unsigned char key, int x, int y)
{
    if (doing_scaling)
    {
        switch (key)
        {
        case 48:
            scaling_factor[scaling_count % 2] = 0;
            break;
        case 49:
            scaling_factor[scaling_count % 2] = 1;
            break;
        case 50:
            scaling_factor[scaling_count % 2] = 2;
            break;
        case 51:
            scaling_factor[scaling_count % 2] = 3;
            break;
        case 52:
            scaling_factor[scaling_count % 2] = 4;
            break;
        case 53:
            scaling_factor[scaling_count % 2] = 5;
            break;
        case 54:
            scaling_factor[scaling_count % 2] = 6;
            break;
        case 55:
            scaling_factor[scaling_count % 2] = 7;
            break;
        case 56:
            scaling_factor[scaling_count % 2] = 8;
            break;
        case 57:
            scaling_factor[scaling_count % 2] = 9;
            break;
        default:
            break;
        }
        if (key >= 48 && key <= 57)
        {
            if (scaling_count % 2 == 1)
                doing_scaling = false;
            scaling_count += 1;
            scaling();
        }
    }
    if (doing_reflection == true)
    {
        if (key == 'x' || key == 'X')
        {
            reflection_axis = 'x';
            reflection();
            doing_reflection = false;
        }
        else if (key == 'y' || key == 'Y')
        {
            reflection_axis = 'y';
            reflection();
            doing_reflection = false;
        }
    }
    if (doing_shearing == true)
    {
        if (key == 'x' || key == 'X')
        {
            shearing_axis = 'x';
        }
        else if (key == 'y' || key == 'Y')
        {
            shearing_axis = 'y';
        }
        switch (key)
        {
        case 48:
            shearing_factor = 0;
            break;
        case 49:
            shearing_factor = 1;
            break;
        case 50:
            shearing_factor = 2;
            break;
        case 51:
            shearing_factor = 3;
            break;
        case 52:
            shearing_factor = 4;
            break;
        case 53:
            shearing_factor = 5;
            break;
        case 54:
            shearing_factor = 6;
            break;
        case 55:
            shearing_factor = 7;
            break;
        case 56:
            shearing_factor = 8;
            break;
        case 57:
            shearing_factor = 9;
            break;
        default:
            break;
        }
        if (key >= 48 && key <= 57)
        {
            doing_shearing = false;
            shearing();
        }
    }

    if (doing_rotation)
    {
        if (key == 'A' || key == 'a')
            rotation_type = 'a';
        else if (key == 'C' || key == 'c')
            rotation_type = 'c';
        rotation();
        doing_rotation = false;
    }
}

void display()
{
    glColor3f(1.0f, 0.0f, 0.0f);
    if (!complete)
    {
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < ip_coordinates.size(); i++)
            glVertex2i(ip_coordinates[i][0], ip_coordinates[i][1]);
        glEnd();
    }
    else if (complete && !doing_scaling)
    {
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < ip_coordinates.size(); i++)
            glVertex2i(ip_coordinates[i][0], ip_coordinates[i][1]);
        glEnd();
    }
    else if (complete && doing_scaling)
    {
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < ip_coordinates.size(); i++)
            glVertex2i(ip_coordinates[i][0], ip_coordinates[i][1]);
        glEnd();
    }
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(screen_width, screen_height);
    glutCreateWindow("2D Transformations");
    initGL();
    glutDisplayFunc(display);
    glutMouseFunc(mouse_event);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return (0);
}

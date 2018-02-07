#include "windmill.h"

#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

const double PI = 3.141592654;
int direction = 1;
int degree = 0;
const float colors[4][3] =
    {
        {0.0f,1.0f,0.0f},
        {1.0f,0.0f,0.0f},
        {0.0f,0.0f,1.0f},
        {1.0f,1.0f,0.0f}
    };

void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_LEFT:
            ++direction;
        break;
        case GLUT_KEY_RIGHT:
            --direction;
        break;
    }
}

float get_rad(float mod, float mult) {
    return (mod + degree + 90 * mult) * PI/180;
}

 
void windmill(float x) {
    int i;
    float center_x = 0.0f;
    float center_y = 0.2f;
    float adjust_radius = 0.2f;
    float adjust_spade = 25;

    glColor3f(1.0f, 1.0f, 1.0f);
    
    glBegin(GL_TRIANGLES);
    
    glVertex2f(x, -0.8f);
    glVertex2f(x+0.005f, 0.2f);
    glVertex2f(x-0.005f, 0.2f);
    
    glEnd();
    
    for (i = 0; i < 4; i++) {
        glColor3f(colors[i][0],colors[i][1],colors[i][2]);

        glBegin(GL_TRIANGLES);
        
        glVertex2f(x+center_x, center_y);
        glVertex2f((sin(get_rad(0,i))*adjust_radius) + x+center_x,
            (cos(get_rad(0,i))*adjust_radius) + center_y);
        glVertex2f((sin(get_rad(adjust_spade,i))*adjust_radius) + x+center_x,
            (cos(get_rad(adjust_spade,i))*adjust_radius) + center_y);
        
        glEnd();
    }
}

void windmill_display() {
 
    glClear(GL_COLOR_BUFFER_BIT);

    glutSpecialFunc(SpecialInput);
    // 01
    windmill(0.0f);
    // 02
    windmill(0.5f);
 
    glutSwapBuffers();
 
}

void windmill_doFrame(int v) {
    degree += direction;
    glutPostRedisplay();
    glutTimerFunc(20,windmill_doFrame,0);
}
 
void windmill_init() {
    glClearColor(1.0f, 0.6f, 0, 1);
}
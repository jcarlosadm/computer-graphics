#include "windmill.h"

#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

const double PI = 3.141592654;
int direction = 1;
int degree = 0;

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

 
void windmill() {
    int i;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    
    glVertex2f(0, 0);
    glVertex2f(0.05f, 3);
    glVertex2f(-0.05f, 3);
    
    glEnd();
    
    for (i = 0; i < 4; i++) {
        glColor3f(0.1f * i, 0.05f + i * 0.2f, 0.3f * i);

        glBegin(GL_TRIANGLES);
        
        glVertex2f(0.0f,3.0f);
        glVertex2f(sin(get_rad(0,i)), cos(get_rad(0,i))+3.0f);
        glVertex2f(sin(get_rad(25,i)), cos(get_rad(25,i))+3.0f);
        
        glEnd();
    }
}

void windmill_display() {
 
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
 
    glPushMatrix();
    glTranslated(3.5,-0.7,1);
    glScaled(1.0,1.0,1);
    glutSpecialFunc(SpecialInput);
    windmill();
    glPopMatrix();
 
    glutSwapBuffers();
 
}

void windmill_doFrame(int v) {
    degree += direction;
    glutPostRedisplay();
    glutTimerFunc(20,windmill_doFrame,0);
}
 
void windmill_init() {
    glClearColor(1.0f, 0.6f, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 7, -1, 4, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}
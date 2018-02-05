#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

#include "blocks.h"

int direction = 1;
const int n_elem = 6;
int active_blocks[n_elem];
int flag = 0;
int max_flag = 15;
int down = 0;
float height = 1.0f;
float width = 1.0f;
float x[n_elem];
float y[n_elem];

void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_LEFT:
            ++direction;
            if(direction > 1)
                direction = 1;
        break;
        case GLUT_KEY_RIGHT:
            --direction;
            if(direction < -1)
                direction = -1;
        break;
    }
}

void init_blocks() {
    int i = 0;
    for(i = 0; i < n_elem; ++i) {
        active_blocks[i] = 0;
        x[i] = (i-3)*width;
        y[i] = 0;
    }
}

 
void blocks() {
    int i = 0;
    for(i=0;i<n_elem;++i){
        glColor3f(0.05f*i, 0.1f*i, 0.2f);

        glBegin(GL_POLYGON);
    
        glVertex2f(x[i], y[i]+height);
        glVertex2f(x[i]+width, y[i]+height);
        glVertex2f(x[i]+width, y[i]);
        glVertex2f(x[i], y[i]);
        
        glEnd();
    }
}

void blocks_display() {
 
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
 
    glPushMatrix();
    glTranslated(3.5,-0.7,1);
    glScaled(1.0,1.0,1);
    glutSpecialFunc(SpecialInput);
    blocks();
    glPopMatrix();
 
    glutSwapBuffers();
 
}

void blocks_doFrame(int v) {
    int i;
    if(direction == 0)
        init_blocks();
    else if(direction == 1){
        for(i=0;i<n_elem;++i){
            if(active_blocks[i] == 0){
                if(flag == max_flag){
                    active_blocks[i] = 1;
                    flag = 0;
                }
                else
                    ++flag;
                break;
            }
        }
    }
    else {
        for(i=n_elem-1;i>=0;--i){
            if(active_blocks[i] == 0){
                if(flag==max_flag){
                    active_blocks[i] = 1;
                    flag=0;
                }
                else
                    ++flag;
                break;
            }
        }
    }

    int num_finished = 0;

    if (down == 0) {
        for(i=0;i<n_elem;++i){
            if(active_blocks[i] == 1 && y[i] < height){
                y[i] += 0.03f;
            } else if (active_blocks[i] == 1 && y[i] >= height) {
                ++num_finished;
            }
        }
    } else {
        for(i=0;i<n_elem;++i){
            if(y[i] > 0) {
                y[i] -= 0.03f;
            } else {
                active_blocks[i] = 0;
                down = 0;
            }
        }
    }

    if (down == 0)
        down = (num_finished == n_elem);

    glutPostRedisplay();
    glutTimerFunc(20,blocks_doFrame,0);
}
 
void blocks_init() {
    glClearColor(1.0f, 0.6f, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 7, -1, 4, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    init_blocks();
}
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

#include "blocks.h"

#define n_elem 6

int direction = 1;

int active_blocks[n_elem];

// delay for movement
int flag = 0;
int max_flag = 15;

// all blocks going down?
int down = 0;

// blocks stats
float height = 0.3f;
float width = 0.3f;
float x[n_elem];
float y[n_elem];
float speed = 0.01f;

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
    
    glutSpecialFunc(SpecialInput);
    blocks();
 
    glutSwapBuffers();
 
}

int switch_block(int position) {
	if(active_blocks[position] == 0){
        if(flag==max_flag){
            active_blocks[position] = 1;
            flag=0;
        }
        else
            ++flag;
        return 1;
    }

    return 0;
}

void blocks_doFrame(int v) {
    int i;
    int num_finished = 0;

    // directions

    if(direction == 0)
        blocks_init();
    else if(direction == 1){
        for(i=0;i<n_elem;++i){
            if (switch_block(i)) break;
        }
    }
    else {
        for(i=n_elem-1;i>=0;--i){
            if (switch_block(i)) break;
        }
    }

    // up!
    if (down == 0) {
        for(i=0;i<n_elem;++i){
            if(active_blocks[i] == 1 && y[i] < height){
                y[i] += speed;
            } else if (active_blocks[i] == 1 && y[i] >= height) {
                ++num_finished;
            }
        }
    // down!
    } else {
        for(i=0;i<n_elem;++i){
            if(y[i] > 0) {
                y[i] -= speed;
            } else {
                active_blocks[i] = 0;
                down = 0;
            }
        }
    }

    // change to up?
    if (down == 0)
        down = (num_finished == n_elem);

    glutPostRedisplay();
    glutTimerFunc(20,blocks_doFrame,0);
}
 
void blocks_init() {
    glClearColor(1.0f, 0.6f, 0, 1);
    int i = 0;
    for(i = 0; i < n_elem; ++i) {
        active_blocks[i] = 0;
        x[i] = (i-3)*width;
        y[i] = 0;
    }
}
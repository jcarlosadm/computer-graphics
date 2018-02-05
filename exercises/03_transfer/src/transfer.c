#include "transfer.h"

#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

#define MAX_DOWNLOAD 10
#define MAX_UPLOAD 10
#define MAX_DELAY 15

float blocks_width = 0.06f;
float blocks_space = 0.01f;

float first_block_x = 0.0f;
float first_block_y = 0.0f;

int num_blocks_download = 0;
int num_blocks_upload = 0;

int delay = 0;

void onMouseButton(int button, int state, int x, int y)
{
	if (state != GLUT_DOWN)
		return;

    switch(button) {
    case GLUT_LEFT_BUTTON:
    	num_blocks_upload = (num_blocks_upload < MAX_UPLOAD ? num_blocks_upload + 1 : 0);
    	break;
    case GLUT_RIGHT_BUTTON:
    	num_blocks_download = (num_blocks_download < MAX_DOWNLOAD ? num_blocks_download + 1 : 0);
    	break;
    }
}

void draw_block(float init_x, float init_y) {
	glBegin(GL_POLYGON);

	glVertex2f(init_x, init_y + blocks_width);
    glVertex2f(init_x + blocks_width, init_y + blocks_width);
    glVertex2f(init_x + blocks_width, init_y);
    glVertex2f(init_x, init_y);

	glEnd();
}

void transfer() {
	int i;
	
	// first block
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);

	draw_block(first_block_x, first_block_y);

	glEnd();

	// download
	glColor3f(1.0f, 0, 0);
	for(i = 0; i < num_blocks_download; ++i) {
		draw_block(first_block_x + ((i + 1) * (blocks_width + blocks_space)),
			first_block_y);
	}

	// upload
	glColor3f(0, 1.0f, 0);
	for(i = 0; i < num_blocks_upload; ++i) {
		draw_block(first_block_x - ((i + 1) * (blocks_width + blocks_space)),
			first_block_y);
	}
}

void transfer_display() {
 
    glClear(GL_COLOR_BUFFER_BIT);

    glutMouseFunc(onMouseButton);
    transfer();
 
    glutSwapBuffers();
 
}

void transfer_doFrame(int v) {
    glutPostRedisplay();
    glutTimerFunc(20,transfer_doFrame,0);
}
 
void transfer_init() {
    glClearColor(1.0f, 0.6f, 0, 1);
}
#include <GL/glut.h>

#include "windmill.hpp"

const char* title = "Windmill";

Windmill windmill(-0.5, -0.8, 0.2, 25.0, 1.0, 1);
Windmill windmill2(0.5, -0.4, 0.3, 45, 0.7, 2);

void draw();

void update(int v);

void init();

void special_input(int key, int x, int y);

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(title);
 
    init();
 
    glutDisplayFunc(draw);
    glutTimerFunc(200, update, 0);
 
    glutMainLoop();

	return 0;
}

void draw() {
	glClear(GL_COLOR_BUFFER_BIT);

	windmill.draw();
	windmill2.draw();
	
	glutSwapBuffers();
}

void update(int v) {
	glutPostRedisplay();

	windmill.update();
	windmill2.update();

    glutTimerFunc(20, update, 0);
}

void init() {
	// TODO: objs
	glutSpecialFunc(special_input);

	float colors[][3] = 
		{{0.0f,0.5f,0.5f},
        {1.0f,0.0f,0.5f},
        {0.0f,0.5f,1.0f},
        {1.0f,0.5f,0.2f}};
	windmill2.change_spade_colors(colors);
}

void special_input(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_LEFT:
        	windmill.rotate_left();
        	windmill2.rotate_left();
        break;
        case GLUT_KEY_RIGHT:
            windmill.rotate_right();
            windmill2.rotate_right();
        break;
    }
}
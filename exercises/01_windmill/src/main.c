#include <GL/glut.h>

#include "windmill.h"

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("windmill");
 
    windmill_init();
 
    glutDisplayFunc(windmill_display);
    glutTimerFunc(200, windmill_doFrame, 0);
 
    glutMainLoop();
	return 0;
}
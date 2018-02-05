#include <GL/glut.h>

#include "transfer.h"

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("transfer");
 
    transfer_init();
 
    glutDisplayFunc(transfer_display);
    glutTimerFunc(200, transfer_doFrame, 0);
 
    glutMainLoop();
    return 0;
}
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
    
    glTranslatef(0, 3, 0);
    
    for (i = 0; i < 4; i++) {
        glColor3f(0.1f * i, 0.05f + i * 0.2f, 0.3f * i);

        glBegin(GL_TRIANGLES);
        
        glVertex2f(0,0);
        glVertex2f(sin(get_rad(0,i)), cos(get_rad(0,i)));
        glVertex2f(sin(get_rad(25,i)), cos(get_rad(25,i)));
        
        glEnd();
    }
}

void display() {
 
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

void doFrame(int v) {
    degree += direction;
    glutPostRedisplay();
    glutTimerFunc(20,doFrame,0);
}
 
void init() {
    glClearColor(1.0f, 0.6f, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 7, -1, 4, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}
 
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700,500);
    glutInitWindowPosition(100,100);  
    glutCreateWindow("windmill");
 
    init();
 
    glutDisplayFunc(display);  
    glutTimerFunc(200,doFrame,0);
   
 
    glutMainLoop();
    return 0;
}
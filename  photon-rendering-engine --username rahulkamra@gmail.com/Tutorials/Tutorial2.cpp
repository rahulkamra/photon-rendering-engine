

#include <GL/freeglut.h>
#include <iostream>

static void render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();

}


static void InitializeGlutCallbacks()
{
	glutDisplayFunc(render);
}

int main(int argc, char** argv)
{

	return 0; 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Tutorial 01");

	InitializeGlutCallbacks();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glutMainLoop();


}


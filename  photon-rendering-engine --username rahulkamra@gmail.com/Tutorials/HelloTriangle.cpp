
#include "Header.h"

using namespace std;

GLuint VBO;
const char* pVSFileName = "shader.vs";
const char* pFSFileName = "shader.fs";

static void render()
{
	Vector3f Vertices[3];
	Vertices[0] = Vector3f(0, 1, 0);
	Vertices[1] = Vector3f(-1, -1, 0);
	Vertices[2] = Vector3f(1, -1, 0);

	glClear(GL_COLOR_BUFFER_BIT);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glutSwapBuffers();
	glDisableVertexAttribArray(0);


}


static void InitializeGlutCallbacks()
{
	glutDisplayFunc(render);
}

int main(int argc, char** argv)
{


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Tutorial 01");

	InitializeGlutCallbacks();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}

	glutMainLoop();



}
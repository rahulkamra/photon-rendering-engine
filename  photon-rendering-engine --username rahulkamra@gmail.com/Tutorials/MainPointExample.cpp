
#include "Header.h"

using namespace std;

GLuint VBO;


static void render()
{
	Vector3f Vertices[1];
	Vertices[0] = Vector3f(0, 0, 0);

	glClear(GL_COLOR_BUFFER_BIT);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_POINTS, 0, 1);
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




/*



*/

void test(MyClass *newPonter, MyClass newObj)
{
	cout << newPonter << endl;
	cout << &newObj << endl;

	cout << newObj.a << endl;
	cout << newPonter->a << endl;

	//new MyClass().
}



void pointerTest()
{
	MyClass newObj = MyClass();
	MyClass *newPonter = new MyClass();

	cout << &newObj << endl;
	cout << newPonter << endl;

	newObj.a = 100;
	newPonter->a = 500;
	
	cout << newObj.a << endl;
	cout << newPonter->a << endl;


	test(newPonter, newObj);
	//test(&my);
	
}

#define WIN32 1

#include "Header.h"
using namespace std;

GLuint VBO;
const char* pVSFileName = "Shaders/Hello Triangle/shader.vs";
const char* pFSFileName = "Shaders/Hello Triangle/shader.fs";

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

static void AddShader(GLuint shaderProgram, const char *shaderText, GLenum shaderType)
{
	GLuint shaderObj = glCreateShader(shaderType);
	if (shaderObj == 0)
	{
		fprintf(stderr, "Error Creating Shader type %d", shaderType);
		exit(1);
	}

	const GLchar *p[1];
	p[0] = shaderText;

	GLint lenghts[1];
	lenghts[0] = strlen(shaderText);
	glShaderSource(shaderObj, 1, p, lenghts);

	glCompileShader(shaderObj);

	GLint success;
	glGetShaderiv(shaderObj, GL_COMPILE_STATUS, &success);

	if (!success) {
		GLchar InfoLog[1024];
		glGetShaderInfoLog(shaderObj, 1024, NULL, InfoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", shaderType, InfoLog);
		while (1);
	}

	glAttachShader(shaderProgram, shaderObj);
}

void compileShader()
{
	GLuint shaderProgram = glCreateProgram();
	if (shaderProgram == 0) {
		fprintf(stderr, "Error creating shader program\n");
		exit(1);
	}

	string vs, fs; 

	if (!ReadFile(pVSFileName, vs))
	{
		while (1);
		exit(1); 
	}

	if (!ReadFile(pFSFileName, fs))
	{
		while (1);
		exit(1);
	}

	AddShader(shaderProgram,vs.c_str(),GL_VERTEX_SHADER);
	AddShader(shaderProgram, fs.c_str(), GL_FRAGMENT_SHADER);

	GLint Success = 0;
	GLchar ErrorLog[1024] = { 0 };

	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &Success);

	if (Success == 0)
	{
		glGetProgramInfoLog(shaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		fprintf(stderr, "Error linking shader program: '%s'\n", ErrorLog);
		while (1);
		exit(1);
	}

	glValidateProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &Success);

	if (Success == 0)
	{
		glGetProgramInfoLog(shaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		fprintf(stderr, "Error linking shader program: '%s'\n", ErrorLog);
		while (1);
		exit(1);
	}

	glUseProgram(shaderProgram);
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
		while (1);
		return 1;
	}
	compileShader();
	glutMainLoop();



}

#define WIN32 1

#include "../Header.h"
using namespace std;
using glm::vec3;
using glm::mat4;

GLuint IBO;
GLuint VBO;
const char* pVSFileName = "Cube/shader.vs";
const char* pFSFileName = "Cube/shader.fs";
GLuint shaderProgram;

int width = 1024;
int height = 768;
static void enterFrame()
{
	glutPostRedisplay();
	
}

static void addUniforData()
{
	vec3 redColor(1.0f, 0.0f, 0.0f);
	GLint redColorLocation = glGetUniformLocation(shaderProgram, "redColor");
	glUniform3fv(redColorLocation, 1, &redColor[0]);
}

static void createIndexBuffer(ShapeData shapeData)
{
	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, shapeData.getIndicesSize(), shapeData.getIndices(), GL_STATIC_DRAW);
	
}

static void createVertexBuffer(ShapeData shapeData)
{
	
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

	glBufferData(GL_ARRAY_BUFFER, shapeData.getVeticesSize(), shapeData.getVertices(), GL_STATIC_DRAW);
	
}

static void addMatrices()
{
	mat4 projectionMatrix = glm::perspective(60.0f, (float)width / (float)height, 0.1f, 10.0f);
	mat4 translationProjectionMatrix = glm::translate(projectionMatrix, vec3(0, 0, -3));
	mat4 transformMatrix = glm::rotate(translationProjectionMatrix, 54.0f, vec3(1.0f, 0, 0));

	GLint transformMatrixLocation = glGetUniformLocation(shaderProgram, "transformMatrix");
	glUniformMatrix4fv(transformMatrixLocation, 1, GL_FALSE, &transformMatrix[0][0]);

}
static void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	ShapeData shapeData = ShapeGenerator::makeCube();

	createIndexBuffer(shapeData);
	createVertexBuffer(shapeData);
	

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), 0);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),  (char *)(sizeof(float) * 3));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

	addUniforData();
	addMatrices();
	glDrawElements(GL_TRIANGLES, shapeData.getNumIndices(), GL_UNSIGNED_SHORT, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glutSwapBuffers();

	shapeData.dispose();
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
	glDeleteShader(shaderObj);
}

void compileShader()
{
	 shaderProgram = glCreateProgram();
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

	AddShader(shaderProgram, vs.c_str(), GL_VERTEX_SHADER);
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
	glutIdleFunc(enterFrame);
	glutDisplayFunc(draw);
}


int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(width, height);
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
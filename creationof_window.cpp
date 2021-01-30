//ebo just makes it easier on our memory if we don't want to copy paste a huge amount of rectangle coordinates
//vao gets the vertex points
//then binds it to the buffer


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;
const char* vertex_shader =
"#version 430 core\n"
"layout(location = 0) in vec2 position;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(position, 0, 1.0);\n"
"}\n";
const char* fragment_shader =
"#version 430\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"color = vec4(0.0, 1.0, 1.0, 1.0);\n"
"}\n";
int main() {
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(800, 600, "spencer's square", NULL, NULL);
	if (window == NULL)
	{
		glfwTerminate();
	};
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glViewport(0, 0, 800, 600);
	

	float points[] {
	 0.5f,  0.5f, 
	 0.5f, -0.5f, 
	-0.5f,  0.5f, 
	// second triangle
	 0.5f, 0.5f, 
	-0.5f, -0.5f, 
	-0.5f,  0.5f
	};

	int vertex = glCreateShader(GL_VERTEX_SHADER);
	int fragment = glCreateShader(GL_FRAGMENT_SHADER);
	const char* character_strings[1];
	character_strings[0] = vertex_shader;
	glShaderSource(vertex, 1, character_strings, 0);
	character_strings[0] = fragment_shader;
	glShaderSource(fragment, 1, character_strings, 0);
	glCompileShader(vertex);
	glCompileShader(fragment);
	int program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);
	glUseProgram(program);
	

	unsigned int space;
	glGenBuffers(1, &space);
	glGenVertexArrays(1, &space);
	glBindBuffer(GL_ARRAY_BUFFER, space);
	glBindVertexArray(space);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);




	while (!glfwWindowShouldClose(window)) {

		glUseProgram(program);
		glBindVertexArray(space);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

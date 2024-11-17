#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"models/shaderClass.h"
#include"models/VAO.h"
#include"models/VBO.h"
#include"models/EBO.h"

int height = 800;
int width = 800;


VAO drowTask1() {
	float vertices[] = {
	   -0.9f, 0.9f, 0.0f,0.0f,0.0f,1.0f,1.0f,
	  -0.9f, -0.9f, 0.0f,1.0f,0.0f,0.0f,1.0f,
	   0.9f,  0.0f, 0.0f,0.0f,1.0f,0.0f,1.0f
	};
	unsigned int indices[] = {
		0, 1, 2,
	};

	VAO VAO1;
	VAO1.Bind();
	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 7 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 4, GL_FLOAT, 7 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();
	VBO1.Delete(); EBO1.Delete();
	return VAO1;
}

int main()
{
	// Init GLFW & Create Windows
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL NGP", NULL, NULL);
	
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, width, height);
	//=======================================
	Shader shaderProgram("shaders/default.vert", "shaders/default.frag");
	VAO VAO1=drowTask1();
	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		shaderProgram.Activate();
		glUniform1f(uniID, 0);
		VAO1.Bind();
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	VAO1.Delete();
	shaderProgram.Delete();
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
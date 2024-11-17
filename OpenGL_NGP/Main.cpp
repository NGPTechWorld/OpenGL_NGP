#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include"models/shaderClass.h"
#include"models/VAO.h"
#include"models/VBO.h"
#include"models/EBO.h"
#include"models/Texture.h"
#include "models/Renderer.h"

int height = 800;
int width = 800;

//hellp
//hellp
VAO drowTask1() {
	float vertices[] = {
	//     COORDINATES     /        COLORS      /
	   -0.9f, 0.9f, 0.0f   ,0.0f,0.0f,1.0f,1.0f,
	  -0.9f, -0.9f, 0.0f   ,1.0f,0.0f,0.0f,1.0f,
	   0.9f,  0.0f, 0.0f   ,0.0f,1.0f,0.0f,1.0f
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
VAO drowTextureExample() {
	GLfloat vertices[] =
	{  //     COORDINATES     /        COLORS      /   TexCoord  //
		-0.9f, -0.9f, 0.0f,     1.0f, 0.0f, 0.0f,1.0f,	0.0f, 0.0f,
		-0.9f,  0.9f, 0.0f,     0.0f, 1.0f, 0.0f,1.0f,	0.0f, 1.0f,
		 0.9f,  0.9f, 0.0f,     0.0f, 0.0f, 1.0f,1.0f,	1.0f, 1.0f,
		 0.9f, -0.9f, 0.0f,     1.0f, 1.0f, 1.0f,1.0f,	1.0f, 0.0f
	};
	unsigned int indices[] = {
		0, 2, 1,
		0,3,2
	};

	VAO VAO1;
	VAO1.Bind();
	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 9 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 4, GL_FLOAT, 9 * sizeof(float), (void*)(3 * sizeof(float)));VAO1.LinkAttrib(VBO1, 1, 4, GL_FLOAT, 7 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 9 * sizeof(float), (void*)(7 * sizeof(float))); VAO1.LinkAttrib(VBO1, 1, 4, GL_FLOAT, 7 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();
	VBO1.Delete(); EBO1.Delete();
	return VAO1;
}
VAO drow3DExample() {
	GLfloat vertices[] =
	{ //     COORDINATES        /        COLORS          /   TexCoord  //
		-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,1.0f,	0.0f, 0.0f,
		-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,1.0f,	5.0f, 0.0f,
		 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,1.0f,	0.0f, 0.0f,
		 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,1.0f,	5.0f, 0.0f,
		 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,1.0f,	2.5f, 5.0f
	};
	GLuint indices[] =
	{
		0, 1, 2,
		0, 2, 3,
		0, 1, 4,
		1, 2, 4,
		2, 3, 4,
		3, 0, 4
	};
	VAO VAO1;
	VAO1.Bind();
	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 9 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 4, GL_FLOAT, 9 * sizeof(float), (void*)(3 * sizeof(float))); VAO1.LinkAttrib(VBO1, 1, 4, GL_FLOAT, 7 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 9 * sizeof(float), (void*)(7 * sizeof(float))); VAO1.LinkAttrib(VBO1, 1, 4, GL_FLOAT, 7 * sizeof(float), (void*)(3 * sizeof(float)));
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

	std::string texPath = "resources/planks.png";
	Shader shaderProgram("shaders/default.vert", "shaders/default.frag");
	Shader shaderTextureProgram("shaders/textureShader.vert", "shaders/textureShader.frag");
	Shader shader3DProgram("shaders/shader3D.vert", "shaders/textureShader.frag");

	// Texture
	Texture popTex((texPath).c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	popTex.textureUnit(shader3DProgram, "tex0", 0);
	VAO VAO1=drow3DExample();
	GLuint uniID = glGetUniformLocation(shader3DProgram.ID, "scale");
	float rotation = 0.0f;
	double prevTime = glfwGetTime();
	glEnable(GL_DEPTH_TEST);

	//Drow Part
	while (!glfwWindowShouldClose(window))
	{
		//glClear(GL_COLOR_BUFFER_BIT);
		GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
		shader3DProgram.Activate();
		// Simple timer
		double crntTime = glfwGetTime();
		if (crntTime - prevTime >= 1 / 60)
		{
			rotation += 0.005f;
			prevTime = crntTime;
		}

		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 proj = glm::mat4(1.0f);

		model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.5f, 1.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, -0.5f, -2.0f));
		proj = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);
	
		int modelLoc = glGetUniformLocation(shader3DProgram.ID, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		int viewLoc = glGetUniformLocation(shader3DProgram.ID, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		int projLoc = glGetUniformLocation(shader3DProgram.ID, "proj");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

	/*	glUniform1f(uniID, 0);*/
		popTex.Bind();
		VAO1.Bind();
		GLCall(glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0));
		GLCall(glfwSwapBuffers(window));
		glfwPollEvents();
	}
	VAO1.Delete();
	popTex.Delete();
	shader3DProgram.Delete();
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
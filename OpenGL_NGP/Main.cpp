#include<iostream>
#include<glad/glad.h>
#include <vector>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include"models/shaderClass.h"
#include"models/VAO.h"
#include"models/VBO.h"
#include"models/EBO.h"
#include"shapes/Shape.h"
#include"shapes/Wall.h"
#include"models/Texture.h"
#include "models/Renderer.h"
#include "models/Camera.h"
int height = 720;
int width = 1280;

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

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

int main()
{
	// Init GLFW & Create Windows
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(width, height, "OpenGL NGP", NULL, NULL);
	
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, width, height);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	//=======================================

	std::string texPath = "resources/pop_cat.png";
	Shader shaderProgram("shaders/default.vert", "shaders/default.frag");
	Shader shaderTextureProgram("shaders/textureShader.vert", "shaders/textureShader.frag");
	Shader shader3DProgram("shaders/shader3D.vert", "shaders/textureShader.frag");
	Shader shaderCameraProgram("shaders/shaderCamera.vert", "shaders/textureShader.frag");
	// Texture
	//Texture popTex((texPath).c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	////popTex.textureUnit(shaderCameraProgram, "tex0", 0);
	//VAO VAO1=drow3DExample();
	//GLuint uniID = glGetUniformLocation(shaderCameraProgram.ID, "scale");
	//float rotation = 0.0f;
	//double prevTime = glfwGetTime();
	//glEnable(GL_DEPTH_TEST);
	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	std::vector<Wall> walls = {
	   Wall(glm::vec3(0.0f, 0.0f, -2.0f), glm::vec3(1.0f, 0.0f, 0.0f)), // حائط أمامي
	   Wall(glm::vec3(-2.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)), // حائط يساري
	   Wall(glm::vec3(2.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f))  // حائط يميني
	};
	//Drow Part
	while (!glfwWindowShouldClose(window))
	{
		//glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.83f, 0.95f, 1.0f, 1.0f);
		GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
		shaderCameraProgram.Activate();

	//	// Simple timer
		camera.Inputs(window);
		camera.Matrix(45.0f, 0.1f, 100.0f, shaderCameraProgram, "camMatrix");
	/*	glUniform1f(uniID, 0);*/
	//	popTex.Bind();
	//	VAO1.Bind();
	//	GLCall(glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0));
		/*wall.draw(shaderCameraProgram);*/
		for (Wall& wall : walls) {
			wall.draw(shaderCameraProgram);
		}

		GLCall(glfwSwapBuffers(window));
		glfwPollEvents();
	}
	//VAO1.Delete();
	//popTex.Delete();
	shaderCameraProgram.Delete();
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
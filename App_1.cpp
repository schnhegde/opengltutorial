/*
*	Opengl tutorial 1
	Initalizes GLFW, creates window, sets opengl properties inits glew and does a simple clearcolor in a loop on the window context
*/


#include <stdio.h>


#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Window Resolution
const GLint WIDTH = 800, HEIGHT = 600;


int main() {
	
	// init glfw
	if (glfwInit() == GLFW_FALSE) {
		printf("GLFW Error: init failed!");
		glfwTerminate();
		return 1;
	}


	// create glfw window properties
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// set profile to core // wont be compatible with older opengl // depricated features not allowed 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// allow forward compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// create window
	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
	if (mainWindow == nullptr) {
		printf("GLFW error: window creation failed!");
		glfwTerminate();
		return 1;
	}

	// get buffer width and height
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	// set the context for glew
	glfwMakeContextCurrent(mainWindow);

	// allow modern opengl extensions
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		printf("GLEW error: init failed!");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	// setup viewport to use (buffer width and buffer height)
	glViewport(0, 0, bufferWidth, bufferHeight);

	while (!glfwWindowShouldClose(mainWindow)) {
		glfwPollEvents();

		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(mainWindow);
	}

	return 0;
}
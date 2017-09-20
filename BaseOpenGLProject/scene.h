#ifndef DEF_SCENEOPENGL
#define DEF_SCENEOPENGL

// Includes 

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

class scene
{
private:
	GLFWwindow* window;
	bool update;

	const int SCENE_GL_MAJOR = 3;
	const int SCENE_GL_MINOR = 1;

	void handleInput();
	void render(float vertices[]);

public:
	scene();
	~scene();

	bool initialize(const int width, const int height, const char* title);
	void updateScene();
};

#endif
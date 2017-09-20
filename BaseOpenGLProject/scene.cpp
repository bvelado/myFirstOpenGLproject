#include "scene.h"


void scene::handleInput()
{
	glfwPollEvents();

	int state = glfwGetKey(window, GLFW_KEY_ESCAPE);
	if (state == GLFW_PRESS)
		update = false;

	if (glfwWindowShouldClose(window))
	{
		update = false;;
	}
}

void scene::render(float vertices[])
{
	glClear(GL_COLOR_BUFFER_BIT);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, vertices);
	glEnableVertexAttribArray(0);

	glDrawArrays(GL_TRIANGLES, 0, 9);

	glDisableVertexAttribArray(0);

	glfwSwapBuffers(window);
}

scene::scene()
{
	update = false;
}


scene::~scene()
{
	glfwTerminate();
}

bool scene::initialize(const int width, const int height, const char * title)
{
	if (!glfwInit())
		return false;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, SCENE_GL_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, SCENE_GL_MINOR);

	window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!window)
		return false;

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	GLenum err = glewInit();
	if (GLEW_OK != err)
		return false;

	return true;
}

void scene::updateScene()
{
	update = true;

	float vertices[] = {
		0, -0.5,   -0.5, 0.3,   0.5, 0.3,
		-0.5, 0.3,  -0.25, 0.6,  0.2, 0.3,
		-0.2, 0.3,    0.25, 0.6,    0.5, 0.3
	};

	while (update) {
		handleInput();
		render(vertices);
	}
}

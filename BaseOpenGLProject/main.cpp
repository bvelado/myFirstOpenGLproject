#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "scene.h"

int main(void)
{
	scene scene = scene::scene();
	if (!scene.initialize(800, 600, "Caca de cul"))
		return -1;
	
	scene.updateScene();

	return 0;
}
#include "../include/eng.hpp"
using namespace eng;

void Camera::BeginDraw(Color c)
{
	glfwPollEvents();
	glClearColor(c.x, c.y, c.z, c.w);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Camera::Present(GLFWwindow* e)
{
	if (e == nullptr) std::cout << "window null\n";
	glfwSwapBuffers(e);
}
#include "../include/eng.hpp"
using namespace eng;

void Camera::BeginDraw()
{
	glfwPollEvents();
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Camera::Present(GLFWwindow* e)
{
	if (e == nullptr) std::cout << "window null\n";
	glfwSwapBuffers(e);
}
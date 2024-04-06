#include "../include/Camera.hpp"
#define GLEW_STATIC
#include "../include/lib/glew.h"
#include "../include/lib/glfw3.h"
using namespace eng;

void Camera::BeginDraw()
{
	glfwPollEvents();
	glClearColor(backgroundColor.x, backgroundColor.y, backgroundColor.z, backgroundColor.w);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Camera::Present()
{
	glfwSwapBuffers(glfwGetCurrentContext());
}

void Camera::Update()
{
	viewMatrix = glm::mat4(1);
	viewMatrix = glm::translate(viewMatrix, glm::vec3(position.x, position.y, position.z));
}
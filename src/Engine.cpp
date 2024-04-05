#include "../include/eng.hpp"

using namespace eng;

void error_callback(int code, const char* description)
{
	std::cout << code << " :: " << description << "\n";
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

Engine eng::CreateEngine(AppData data, bool* success)
{
	Engine e;
	bool s;
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
	{
		std::cout << "glfw failed\n";
		s = false;
		success = &s;
		return e;
	}
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	e.window = glfwCreateWindow(data.width, data.height, data.title, NULL, NULL);
	glfwMakeContextCurrent(e.window);


	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "glew failed\n";
		glfwTerminate();
		s = false;
		success = &s;
		return e;
	}
	glEnable(GL_DEPTH_TEST);
	glfwSetFramebufferSizeCallback(e.window, framebuffer_size_callback);
	s = true;
	success = &s;

	return e;
}

void Engine::Terminate()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

bool Engine::Running(GLFWwindow* window)
{
	return !glfwWindowShouldClose(window);
}

Camera Engine::CreateCamera(CameraData data)
{
	return Camera(data);
}

Object Engine::CreateObject(char name[], Transform transform)
{
	Object o;
	o.name = name;
	o.transform = &transform;
	return o;
}

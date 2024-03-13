#include "../include/eng.hpp"

using namespace eng;

Engine eng::CreateEngine(AppData data)
{
	Engine e;
	if (glfwInit() != 0)
		return e;
	
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();

	const GLFWvidmode* mode = glfwGetVideoMode(monitor);

	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

	e.window = glfwCreateWindow(data.width == fullscreen ? mode->width : data.width, data.height == fullscreen ? mode->height : data.height, data.title, monitor, NULL);
	glfwMakeContextCurrent(e.window);

	glewExperimental = true;
	if (glewInit() != 0)
	{
		glfwTerminate();
		return Engine();
	}
	

	return e;
}

void Engine::Terminate()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

bool Engine::Running()
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

#include "../include/eng.hpp"

using namespace eng;

void error_callback(int code, const char* description)
{
	std::cout << code << " :: " << description << "\n";
}

void window_content_scale_callback(GLFWwindow* window, float xscale, float yscale)
{
	glViewport(xscale/2, yscale / 2, xscale, yscale);
}

Engine eng::CreateEngine(AppData data, bool* success)
{
	Engine e;
	bool s;
	if (!glfwInit())
	{
		std::cout << "glfw failed\n";
		s = false;
		success = &s;
		return e;
	}
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	if (data.width == eng::fullscreen)
	{
		glfwWindowHint(GLFW_RED_BITS, mode->redBits);
		glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
		glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
		glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
	}

	e.window = glfwCreateWindow(data.width == eng::fullscreen ? mode->width : data.width,
		data.height == eng::fullscreen ? mode->height : data.height, data.title, data.width == eng::fullscreen ? glfwGetPrimaryMonitor() : NULL, NULL);
	glfwMakeContextCurrent(e.window);

	glfwSetWindowContentScaleCallback(e.window, window_content_scale_callback);

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

void Engine::InitFPS()
{
	lastTime = glfwGetTime();
}

float Engine::FPS(bool mills)
{
	double currentTime = glfwGetTime();
	nbFrames++;
	float ms = 0;
	if (currentTime - lastTime >= 1.0) { // If last prinf() was more than 1 sec ago
		// printf and reset timer
		ms = 1000.0 / double(nbFrames);
		std::cout << 1 / ms * 1000 << "\n";
		nbFrames = 0;
		lastTime += 1.0;
	}
	if (mills)
		return ms;
	return 1 / ms * 1000;
		
}

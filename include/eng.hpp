#pragma once
#include "../include/Modules.hpp"

#include <iostream>

namespace eng {
	class Engine;
	const int perspective = 1;
	const int orthographic = 0;
	const int fullscreen = 52354;

	struct AppData {
		char* title;
		int width, height;
	};

	

	class Engine {
	public:
		char* name;
		int width, height;
		GLFWwindow* window;
		Camera CreateCamera(CameraData* data);
		void Terminate();
		bool Running();
		float FPS(bool mills);
		void InitFPS();
	private:
		// for fps counter
		double lastTime;
		int nbFrames;
	};

	Engine CreateEngine(AppData data, bool* success);

	
}
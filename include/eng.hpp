//#include <glfw3.h>
#include <iostream>
#include <vector>

namespace eng {

	const int perspective = 1;
	const int orthographic = 0;
	const int fullscreen = 52354;

	struct AppData {
		char* title;
		int width, height;
	};

	struct Transform {
		Vec3 position, rotation, scale;
	};

	struct CameraData {
		int priority, depth;
		float min, max;
		Vec3 position, rotation;
		Color backgroundColor;
	};

	class Engine {
		char* name;
		int width, height;
		//GLFWwindow* window;

		void CreateObject(char name[]);
		void CreateCamera(CameraData data);
	};

	Engine CreateEngine(AppData data);

	class Module {
		bool enabled;
	};

	class Object {
		Transform* transform;
		char* name;

		std::vector<Module> modules;

		template<typename T>
		T AddModule();
	};
}

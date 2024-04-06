#include "../include/eng.hpp"
#include "../include/Meshes.hpp" // Provides basic mesh templates
#include "../include/Materials.hpp" // Provides shaders

eng::AppData appdata = {
	(char*)"Test App", // title
	1000, // width
	1000 // height
};

eng::Transform transform = {
	Vec3(0, 0, 0), // position
	Vec3(0, 0, 0), // rotation
	Vec3(1, 1, 1) // scale
};

eng::CameraData cameradata = {
		1,
		eng::orthographic,
		60,
		Vec2(0.1f, 100),
		Vec3(1, 0, -5),
		Vec3(0, 0, 0),
		Color(0.2f, 0.3f, 0.6f, 1)
};

ObjectRendererData renderdata = {
	eng::meshes::cube,
	eng::materials::unlit_3d
};

int main()
{
	bool yay;
	eng::Engine engine = eng::CreateEngine(appdata, &yay);
	engine.InitFPS();
	if (!yay)
	{
		return -1;
	}

	eng::Camera camera = engine.CreateCamera(&cameradata);

	ObjectRenderer renderobject;

	renderobject.CreateTexture("C:/Eng/bin/win_debug/Assets/Textures/test.png");

	renderobject.Create(renderdata, 8, 12, 8, &transform);

	while (engine.Running())
	{
		engine.FPS(false);
		camera.BeginDraw();

		camera.position.x = sin(glfwGetTime()) * 2;
		camera.position.y = cos(glfwGetTime()) * 2;

		camera.Update();

		renderobject.Translate(&camera);
		renderobject.Perspective(engine.window, &camera);

		renderobject.BindTexture();
		renderobject.Render(12);

		camera.Present();
	}
	
	engine.Terminate();

	return 0;
}
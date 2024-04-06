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
		Vec2(0.03f, 1000),
		Vec3(0, 0, -10),
		Vec3(0, 0, 0),
		Color(0.2f, 0.3f, 0.6f, 1)
};

ObjectRendererData renderdata = {
	eng::meshes::cube,
	eng::materials::unlit_2d
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

	eng::Camera camera = engine.CreateCamera(cameradata);

	ObjectRenderer renderobject;

	renderobject.Create(renderdata, 8, 12);

	while (engine.Running())
	{
		engine.FPS(false);
		camera.BeginDraw();

		renderobject.Render(12);

		camera.Present(engine.window);
	}
	
	engine.Terminate();

	return 0;
}
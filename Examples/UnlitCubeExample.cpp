#include "../include/eng.hpp"

using namespace eng::rendering;

eng::AppData appdata = {
	(char*)"Test App", // title
	eng::fullscreen, // width
	eng::fullscreen // height
};

eng::Transform transform = {
	eng::Vec3(0, 0, 0), // position
	eng::Vec3(0, 0, 0), // rotation
	eng::Vec3(1, 1, 1) // scale
};

eng::CameraData cameradata = {
		1,
		eng::perspective,
		eng::Vec2(0.03f, 1000),
		eng::Vec3(0, 0, -10),
		eng::Vec3(0, 0, 0),
		eng::Color(0,0,0,0)
};

ObjectRendererData renderdata = {
	eng::meshes::cube,
	eng::materials::unlit
};

int main()
{
	eng::Engine engine = eng::CreateEngine(appdata);

	eng::Camera camera = engine.CreateCamera(cameradata);

	eng::Object obj = engine.CreateObject((char*)"test object", transform);



	ObjectRenderer renderobject;

	renderobject.Create(renderdata);

	obj.AddModule(renderobject);

	while (engine.Running())
	{
		camera.BeginDraw();

		camera.Render(renderobject);

		camera.Present();
	}

	engine.Terminate();

	return 0;
}